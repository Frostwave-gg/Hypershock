//
// Created by jankr on 02-Aug-22.
//

#ifndef HYPERSHOCK_GAME_APPLICATION_HPP
#define HYPERSHOCK_GAME_APPLICATION_HPP

#include "Types.hpp"
#include "Core.hpp"
#include "Event/Event.hpp"
#include "Window.hpp"
#include "Monitor.hpp"

#include <string>
#include <vector>
#include <map>
#include <functional>

namespace Hypershock {

    struct HYPERSHOCK_PUBLIC_API ApplicationSettings {
        WindowSettings defaultWindowSettings;
        std::string appName = "";
        std::function<bool(Event&)> eventCallback = [](Event& event){ return false; };
    };

    class HYPERSHOCK_PUBLIC_API Application {
    public:
        Application(const std::string& appName, const std::string& windowName);
        virtual ~Application();

        std::string NewWindow(Uint32 width = 1920, Uint32 height = 1080, const std::string& title = "Window");
        std::string NewWindow(WindowSettings settings = WindowSettings());
        Window& GetWindow(const std::string& id);

        bool OnEvent(Event& event);

        inline ApplicationSettings& GetSettings() { return m_ApplicationSettings; }

        inline virtual void OnStart() {}
        inline virtual void Update() {}
        inline virtual void FixedUpdate() {}
        inline virtual void OnEnd() {}

        inline Window& GetMainWindow() { return *m_MainWindow; }

    private:
        ApplicationSettings m_ApplicationSettings;
        std::map<std::string, Window*> m_Windows;
        std::vector<Monitor> m_Monitors;
        Window* m_MainWindow;
    };

}

#endif //HYPERSHOCK_GAME_APPLICATION_HPP
