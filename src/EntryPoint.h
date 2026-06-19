#pragma once
#include "Application.h"
#include <imgui.h>

extern VeneriX::Application* VeneriX::CreateApplication();

int main(int argc, char** argv) {
    auto app = VeneriX::CreateApplication();

    ImGui::SetCurrentContext(app->GetImGuiContext());

    app->Run();

    delete app;
    return 0;
}