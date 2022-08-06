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

namespace Hypershock {

    class Application {
    public:
        Application();
        virtual ~Application();

        std::string NewWindow();
        Window& GetWindow(const std::string& id);

    private:
        std::map<std::string, Window*> m_Windows;
        std::vector<Monitor> m_Monitors;
        Window* m_MainWindow;
    };

}

#endif //HYPERSHOCK_GAME_APPLICATION_HPP
