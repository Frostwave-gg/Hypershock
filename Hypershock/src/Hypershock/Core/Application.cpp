//
// Created by jankr on 02-Aug-22.
//

#include "Application.hpp"

namespace Hypershock {

    Application::Application(const std::string &appName, const std::string &windowName) {

    }

    Application::~Application() {
        for(auto val : m_Windows) {
            delete val.second;
        }
    }

    std::string Application::NewWindow(Uint32 width, Uint32 height, const std::string& title) {
        Window* window = new Window(width, height, title);
        m_Windows.insert(std::pair<std::string, Window*>(window->GetID(), window));
        return window->GetID();
    }

    std::string Application::NewWindow(WindowSettings settings) {
        Window* window = new Window(settings);
        m_Windows.insert(std::pair<std::string, Window*>(window->GetID(), window));
        return window->GetID();
    }

    Window &Application::GetWindow(const std::string &id) {
        return *m_Windows.at(id);
    }

    bool Application::OnEvent(Event &event) {
        return false;
    }
}