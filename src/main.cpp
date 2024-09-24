#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "dockspace.h"

enum class Tool {
    None,
    Brush,
    Eraser,
    ColorPicker
};

// Entry point
int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Kokoro Pixel - Pixel Art App");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);
    sf::Clock deltaClock;
    Tool currentTool = Tool::None;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // Begin custom dock space
        DockSpace::BeginDockSpace();

        // Toolbox
        ImGui::Begin("Toolbox");
        if (ImGui::Button("Brush")) {
            currentTool = Tool::Brush;
        }
        if (ImGui::Button("Eraser")) {
            currentTool = Tool::Eraser;
        }
        if (ImGui::Button("Color Picker")) {
            currentTool = Tool::ColorPicker;
        }
        ImGui::End();

        // Canvas
        ImGui::Begin("Canvas");
        ImVec2 canvasSize = ImGui::GetContentRegionAvail();
        ImGui::Text("Canvas Size: %.1f, %.1f", canvasSize.x, canvasSize.y);
        ImGui::End();

        // End custom dock space
        DockSpace::EndDockSpace();

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
