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

#include "Utilities.hpp"

#include <iostream>

namespace Hypershock {

    Size Window::s_WindowCount = 0;

    Window::Window(Uint32 width, Uint32 height, const std::string &title) {
        if(s_WindowCount++ == 0) {
            glfwInit();
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
        glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
        glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
        glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_FALSE);
        glfwWindowHint(GLFW_FLOATING, GLFW_FALSE);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
        glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_FALSE);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_FALSE);
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);

        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API); // Change to no_api for non opengl renderers

        m_pNativeWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        m_Settings.width = width;
        m_Settings.height = height;
        m_Settings.title = title;
        m_Settings.eventCallback = [](Event& event){
            std::cout << event.GetName() << std::endl;
        };
        m_Settings.mode = WindowMode::Windowed;
        m_Settings.id = Utilities::GenerateUUID();

        SetupCallbacks();
    }

    Window::Window(const WindowSettings& settings) {
        if(s_WindowCount++ == 0) {
            glfwInit();
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_pNativeWindow = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);

        m_Settings = settings;

        SetupCallbacks();
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
        if(mode == WindowMode::Windowed) {
            if(m_Settings.mode != WindowMode::Windowed) {
                SetWindowed();
            }
        }
        else if(mode == WindowMode::Borderless) {
            if(m_Settings.mode != WindowMode::Borderless) {
                SetBorderless();
            }
        }
        else if(mode == WindowMode::Hidden) {
            if(m_Settings.mode != WindowMode::Hidden) {
                Hide();
            }
        }
        else if(mode == WindowMode::Minimized) {
            if(m_Settings.mode != WindowMode::Minimized) {
                Minimize();
            }
        }
        else if(mode == WindowMode::FullScreen) {
            if(m_Settings.mode != WindowMode::FullScreen) {
                Maximize();
            }
        }
        else {
            return false;
        }

        return true;
    }

    bool Window::Hide() {
        glfwHideWindow(m_pNativeWindow);

        return false;
    }

    bool Window::Show() {
        glfwShowWindow(m_pNativeWindow);

        return false;
    }

    bool Window::SetWindowed() {
        glfwRestoreWindow(m_pNativeWindow);

        // Deal with this crap

        return false;
    }

    bool Window::SetBorderless() {
        glfwRestoreWindow(m_pNativeWindow);

        // Set borderleses

        return false;
    }

    bool Window::Maximize() {
        glfwRestoreWindow(m_pNativeWindow);

        glfwMaximizeWindow(m_pNativeWindow);

        return false;
    }

    bool Window::Minimize() {
        glfwIconifyWindow(m_pNativeWindow);

        return false;
    }

    bool Window::Unminimize() {
        glfwRestoreWindow(m_pNativeWindow);

        return false;
    }

    bool Window::Focus() {
        glfwFocusWindow(m_pNativeWindow);

        return false;
    }

    bool Window::RequestAttention() {
        glfwRequestWindowAttention(m_pNativeWindow);

        return false;
    }

    bool Window::SetOpacity(float opacity) {
        glfwSetWindowOpacity(m_pNativeWindow, opacity);

        return false;
    }

    bool Window::ShouldClose() {
        return glfwWindowShouldClose(m_pNativeWindow);
    }

    void Window::PollEvents() {
        glfwPollEvents();
    }

    void Window::SetupCallbacks() {
        glfwSetWindowUserPointer(m_pNativeWindow, &m_Settings);

        // TODO: setup callbacks for all types of events and implement more event types
        glfwSetWindowCloseCallback(m_pNativeWindow, [](GLFWwindow* window) {
            std::cout << "Window Close Event" << std::endl;
        });
        glfwSetWindowContentScaleCallback(m_pNativeWindow, [](GLFWwindow* pWindow, float xScale, float yScale) {
            std::cout << "Window Content Scale Event" << std::endl;
        });
        glfwSetWindowFocusCallback(m_pNativeWindow, [](GLFWwindow* pWindow, int focused) {
            std::cout << "Window Focus Event" << std::endl;
        });
        glfwSetWindowIconifyCallback(m_pNativeWindow, [](GLFWwindow* pWindow, int iconified) {
            std::cout << "Window Iconify Event" << std::endl;
        });
        glfwSetWindowMaximizeCallback(m_pNativeWindow, [](GLFWwindow* pWindow, int maximized) {
            std::cout << "Window Maximize Event" << std::endl;
        });
        glfwSetWindowSizeCallback(m_pNativeWindow, [](GLFWwindow* pWindow, Int32 width, Int32 height) {
            std::cout << "Window Resize Event" << std::endl;
        });
        glfwSetWindowPosCallback(m_pNativeWindow, [](GLFWwindow* pWindow, Int32 xPos, Int32 yPos) {
            std::cout << "Window Position Event" << std::endl;
        });
        glfwSetWindowRefreshCallback(m_pNativeWindow, [](GLFWwindow* pWindow) {
            std::cout << "Window Refresh Event" << std::endl;
        });
        glfwSetMouseButtonCallback(m_pNativeWindow, [](GLFWwindow* pWindow, Int32 button, Int32 action, Int32 mods) {
            std::cout << "Mouse Button Event" << std::endl;
        });
        glfwSetJoystickCallback([](Int32 JID, Int32 event) {
            std::cout << "Joystick Event" << std::endl;
        });
        glfwSetKeyCallback(m_pNativeWindow, [](GLFWwindow* pWindow, Int32 key, Int32 scancode, Int32 action, Int32 mods) {
            std::cout << "Keyboard Key Event" << std::endl;
        });
        glfwSetScrollCallback(m_pNativeWindow, [](GLFWwindow* pWindow, double xOffset, double yOffset) {
            std::cout << "Mouse Scroll Event" << std::endl;
        });
        glfwSetCursorPosCallback(m_pNativeWindow, [](GLFWwindow* pWindow, double xPos, double yPos) {
            std::cout << "Mouse Position Event" << std::endl;
        });
        glfwSetCursorEnterCallback(m_pNativeWindow, [](GLFWwindow* pWindow, Int32 entered) {
            std::cout << "Cursor Enter Event" << std::endl;
        });
        glfwSetFramebufferSizeCallback(m_pNativeWindow, [](GLFWwindow* pWindow, Int32 width, Int32 height) {
            std::cout << "Framebuffer Resize Event" << std::endl;
        });
    }
}
