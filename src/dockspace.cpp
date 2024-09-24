#include "dockspace.h"

void DockSpace::BeginDockSpace() {
    ImGui::Begin("DockSpace", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
}

void DockSpace::EndDockSpace() {
    ImGui::End();
}
