//====================================================================================================
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
//====================================================================================================
#pragma once
#ifndef HYPERSHOCK_WINDOW_HPP
#define HYPERSHOCK_WINDOW_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/String/String.hpp"
#include "Hypershock/Event/Event.hpp"
//====================================================================================================
#include <GLFW/glfw3.h>
//====================================================================================================
#include <string>
#include <functional>
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    enum class WindowMode : uint8
    {
        Hidden = 0,
        Windowed = 1,
        WindowedFullScreen = 2,
        FullScreen = 3,
        Minimized = 4
    };
    //====================================================================================================
    struct WindowSettings
    {
        uint32 width;
        uint32 height;
        uint32 pixelWidth;
        uint32 pixelHeight;
        glm::vec2 contentScale;
        String title;
        String id;
        WindowMode mode;
        uint32 refreshRate;
        std::function<void(SystemEvent&)> eventCallback;
    };
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API Window
    {
    public:
        //====================================================================================================
        /**
         *
         * @param width
         * @param height
         * @param title
         */
        explicit Window(uint32 width = 1920, uint32 height = 1080, const String& title = TEXT(""));
        /**
         *
         * @param settings
         */
        explicit Window(const WindowSettings& settings);
        /**
         *
         */
        ~Window();
        //====================================================================================================
        /**
         *
         * @param width
         * @param height
         * @return
         */
        bool Resize(uint32 width, uint32 height);
        /**
         *
         * @param title
         * @return
         */
        bool ChangeTitle(const String& title);
        /**
         *
         * @param mode
         * @return
         */
        bool ChangeMode(WindowMode mode);
        /**
         *
         * @return
         */
        bool Hide();
        /**
         *
         * @return
         */
        bool Show();
        /**
         *
         * @return
         */
        bool SetWindowed();
        /**
         *
         * @return
         */
        bool SetWindowedFullScreen();
        /**
         *
         * @return
         */
        bool SetFullScreen();
        /**
         *
         * @return
         */
        bool Minimize();
        /**
         *
         * @return
         */
        bool Unminimize();
        /**
         *
         * @return
         */
        bool Focus();
        /**
         *
         * @return
         */
        bool RequestAttention();
        /**
         *
         * @param opacity
         * @return
         */
        bool SetOpacity(float opacity);
        /**
         *
         * @return
         */
        bool ShouldClose();
        /**
         *
         */
        void OnUpdate();
        /**
         *
         * @return
         */
        inline GLFWwindow* GetNativeWindow() { return m_pNativeWindow; }

    private:
        /**
         *
         */
        void SetupCallbacks();

    private:
        GLFWwindow* m_pNativeWindow;
        static size s_WindowCount;
        WindowSettings m_Settings;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_WINDOW_HPP
//====================================================================================================