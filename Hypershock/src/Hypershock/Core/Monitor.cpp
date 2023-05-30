//
// Created by jankr on 26-Jul-22.
//

#include "Monitor.hpp"

namespace Hypershock {

    std::vector<Monitor> Monitor::GetMonitors() {
        Int32 count;
        GLFWmonitor** ppMonitors = glfwGetMonitors(&count);

        std::vector<Monitor> monitors;
        monitors.reserve(count);

        for(Int32 i = 0; i < count; i++) {
            monitors.emplace_back(Monitor(ppMonitors[i]));
        }

        return monitors;
    }

    Monitor Monitor::GetMain() {
        return Monitor(glfwGetPrimaryMonitor());
    }

    Monitor Monitor::GetByIndex(Size index) {
        auto monitors = GetMonitors();

        if(index >= monitors.size()) {
            return Monitor(nullptr);
        }

        return GetMonitors()[index];
    }

    glm::vec2 Monitor::GetContentScale() {
        glm::vec2 contentScale;

        glfwGetMonitorContentScale(m_pNativeMonitor, &contentScale.x, &contentScale.y);

        return contentScale;
    }

    glm::ivec2 Monitor::GetPosition() {
        glm::ivec2 position;

        glfwGetMonitorPos(m_pNativeMonitor, &position.x, &position.y);

        return position;
    }

    glm::ivec2 Monitor::GetPhysicalSize() {
        glm::ivec2 size;

        glfwGetMonitorPhysicalSize(m_pNativeMonitor, &size.x, &size.y);

        return size;
    }

    std::string Monitor::GetName() {
        return {glfwGetMonitorName(m_pNativeMonitor)};
    }

    glm::ivec2 Monitor::GetWorkArea() {
        // TODO: change function to implement good return value etc...

        return glm::ivec2();
    }

    Monitor::Monitor(GLFWmonitor *pMonitor) : m_pNativeMonitor(pMonitor) {}
}
