#pragma once
#include "Core.h"
#include "Scene.h"
#include <string>
#include "TimeStep.h"

struct GLFWwindow;
struct ImGuiContext;

namespace VeneriX {
    struct ApplicationSpecification {
        std::string Name = "VeneriX Application";
        uint32_t Width = 1280;
        uint32_t Height = 720;
    };

    class VENERIX_API Application {
    public:
        Application(const ApplicationSpecification& spec = ApplicationSpecification());
        virtual ~Application();

        void Run();
        void SetScene(Scene* scene) { m_CurrentScene = scene; }

        void SetTimeScale(float scale) { m_TimeStep.TimeScale = scale; }
        float GetTimeScale() const { return m_TimeStep.TimeScale; }
        const TimeStep& GetTimeStep() const { return m_TimeStep; }

        static Application* Get() { return s_Instance; }

        ImGuiContext* GetImGuiContext();

    protected:
        GLFWwindow* m_Window;
        Scene* m_CurrentScene = nullptr;
        TimeStep m_TimeStep;
        float m_LastFrame = 0.0f;

    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}