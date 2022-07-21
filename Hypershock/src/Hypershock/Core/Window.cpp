/**
 *  Copyright (c) 2022 Frostwave.gg
 *
 *  This software is provided 'as-is', without any express or implied warranty.
 *  In no event will the authors be held liable for any damages arising from the use of this software.
 *
 *  Permission is granted, free of charge, to anyone to use this software for non-commercial non-military purposes, and to alter it and redistribute it freely,
 *  subject to the following restrictions:
 *      1. The origin of the software must not be misrepresented; you must not claim that you wrote the original software.
 *      2. The acknowledgement of the use of this software must be present and clearly visible in the product documentation and the product itself.
 *      3. This notice must not be removed from any source distribution.
 *
 *  Permission is denied for any military purpose without explicit cooperation agreement between the third party and Frostwave.gg.
 *  For military use, contact Frostwave.gg.
 *  (Heads up, Frostwave.gg does not support military use of its software, therefore rates may be astronomical)
 *
 *  Permission is denied to anyone to use this software, alter it or redistribute it for commercial, or commercial-related purposes,
 *  without permission of Frostwave.gg or its subsidiaries. This includes any and all products and activity with potential monetary gain,
 *  including but not limited to commercial or advertisement products, products containing advertisement, training software and in-house simulation software.
 *  Requirements for commercial use are following:
 *      1. The origin of the software must not be misrepresented; you must not claim that you wrote the original software.
 *      2. Frostwave.gg is eligible for 7.5% of the first 100,000 USD of the products profit, and 15% of all profit after.
 *      3. This notice must not be removed from any source distribution.
 *      4. A formal business agreement from Frostwave.gg or its subsidiaries must be acquired for any commercial use.
 *      5. The acknowledgement of the use of this software must be present and clearly visible in the product documentation.
 *
 *  Open-source commercial products may be eligible to a reduced owed profit percentage - contact Frostwave.gg for further information.
 *
 */

#include "Window.hpp"

namespace Hypershock {

    Size Window::s_WindowCount = 0;

    Window::Window(Uint32 width, Uint32 height, const std::string &title) {
        if(s_WindowCount++ == 0) {
            glfwInit();
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_pNativeWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        m_Settings.width = width;
        m_Settings.height = height;
        m_Settings.title = title;
        m_Settings.eventCallback = [](Event& event){};
        m_Settings.mode = WindowMode::Windowed;
        // Generate UUID
    }

    Window::Window(const WindowSettings& settings) {
        if(s_WindowCount++ == 0) {
            glfwInit();
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_pNativeWindow = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);

        m_Settings = settings;
    }

    Window::~Window() {
        glfwSetWindowShouldClose(m_pNativeWindow, GLFW_TRUE);

        glfwDestroyWindow(m_pNativeWindow);

        if(--s_WindowCount == 0) {
            glfwTerminate();
        }
    }

    bool Window::Resize(Uint32 width, Uint32 height) {
        if(width == 0 || height == 0) {
            return false;
        }

        glfwSetWindowSize(m_pNativeWindow, width, height);

        return true;
    }

    bool Window::ChangeTitle(const std::string &title) {
        glfwSetWindowTitle(m_pNativeWindow, title.c_str());

        return true;
    }

    bool Window::ChangeMode(WindowMode mode) {
        return false;
    }

    bool Window::Hide() {
        return false;
    }

    bool Window::Show() {
        return false;
    }

    bool Window::SetWindowed() {
        return false;
    }

    bool Window::SetWindowedFullScreen() {
        return false;
    }

    bool Window::SetFullScreen() {
        return false;
    }

    bool Window::Minimize() {
        return false;
    }

    bool Window::Unminimize() {
        return false;
    }

    bool Window::Focus() {
        return false;
    }

    bool Window::RequestAttention() {
        return false;
    }

    bool Window::SetOpacity(float opacity) {
        return false;
    }

    bool Window::ShouldClose() {
        return glfwWindowShouldClose(m_pNativeWindow);
    }

    void Window::OnUpdate() {
        glfwPollEvents();
    }

    void Window::SetupCallbacks() {
        glfwSetWindowUserPointer(m_pNativeWindow, &m_Settings);

        // TODO: setup callbacks for all types of events and implement more event types
        glfwSetWindowCloseCallback(m_pNativeWindow, nullptr);
        glfwSetWindowContentScaleCallback(m_pNativeWindow, nullptr);
        glfwSetWindowFocusCallback(m_pNativeWindow, nullptr);
        glfwSetWindowIconifyCallback(m_pNativeWindow, nullptr);
        glfwSetWindowMaximizeCallback(m_pNativeWindow, nullptr);
        glfwSetWindowSizeCallback(m_pNativeWindow, nullptr);
        glfwSetWindowPosCallback(m_pNativeWindow, nullptr);
        glfwSetWindowRefreshCallback(m_pNativeWindow, nullptr);
        glfwSetMouseButtonCallback(m_pNativeWindow, nullptr);
        glfwSetJoystickCallback(nullptr);
        glfwSetKeyCallback(m_pNativeWindow, nullptr);
        glfwSetScrollCallback(m_pNativeWindow, nullptr);
        glfwSetCursorPosCallback(m_pNativeWindow, nullptr);
        glfwSetCursorEnterCallback(m_pNativeWindow, nullptr);
        glfwSetFramebufferSizeCallback(m_pNativeWindow, nullptr);
    }
}
