//
// Created by jankr on 26-Jul-22.
//

#pragma once

#ifndef HYPERSHOCK_GAME_MONITOR_HPP
#define HYPERSHOCK_GAME_MONITOR_HPP

#include "Core.hpp"
#include "Types.hpp"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

namespace Hypershock {
    class HYPERSHOCK_PUBLIC_API Monitor {
    public:
        virtual ~Monitor() = default;

        static std::vector<Monitor> GetMonitors();
        static Monitor GetMain();
        static Monitor GetByIndex(Size index);

        glm::vec2 GetContentScale();
        glm::ivec2 GetPosition();
        glm::ivec2 GetPhysicalSize();
        std::string GetName();
        glm::ivec2 GetWorkArea();

        inline GLFWmonitor* GetNativeMonitor() { return m_pNativeMonitor; }

    private:
        explicit Monitor(GLFWmonitor* pMonitor);

    private:
        GLFWmonitor* m_pNativeMonitor;

    };
}


#endif //HYPERSHOCK_GAME_MONITOR_HPP
