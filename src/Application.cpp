#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "Renderer.h"
#include "Audio.h"

namespace VeneriX {

    Application* Application::s_Instance = nullptr;
    Application::Application(const ApplicationSpecification& spec) {
        s_Instance = this;
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(spec.Width, spec.Height, spec.Name.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glEnable(GL_DEPTH_TEST);

        Renderer::Init();
        Audio::Init();

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
        ImGui_ImplOpenGL3_Init("#version 330 core");
    }

    Application::~Application() {
        Audio::Shutdown();
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwTerminate();
    }

    void Application::Run() {
        while (!glfwWindowShouldClose(m_Window)) {
            float currentFrame = static_cast<float>(glfwGetTime());
            float rawDelta = currentFrame - m_LastFrame;
            m_LastFrame = currentFrame;

            m_TimeStep.Unscaled = rawDelta;
            m_TimeStep.Delta = rawDelta * m_TimeStep.TimeScale;

            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            if (m_CurrentScene) {
                m_CurrentScene->UpdateEntities(m_TimeStep);
                m_CurrentScene->Update(m_TimeStep);
                m_CurrentScene->Render();
            }

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            if (m_CurrentScene)
                m_CurrentScene->RenderUI();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }
    }
    ImGuiContext* Application::GetImGuiContext() {
        return ImGui::GetCurrentContext();
    }
}