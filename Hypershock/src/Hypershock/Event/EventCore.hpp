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
#ifndef HYPERSHOCK_EVENTCORE_HPP
#define HYPERSHOCK_EVENTCORE_HPP
//====================================================================================================
#include <string>
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    enum class SystemEventType : uint8
    {
        None,
        MouseButtonDown, MouseButtonUp, MouseButtonHold, MouseScroll, MouseMove,
        KeyboardButtonDown, KeyboardButtonUp, KeyboardButtonHold,
        WindowClose, WindowResize, WindowFocus, WindowUnfocus, WindowModeChange,
        PreTick, Tick, PostTick, PreRender, Render, PostRender, Startup, Shutdown, Crash, Interrupt,
    };
    //====================================================================================================
    enum class SystemEventClass : uint8
    {
        None,
        Keyboard,
        Mouse,
        Window,
        Application
    };
    //====================================================================================================
    #define EVENT_TYPE_FUNCTIONS(type) FORCE_INLINE static SystemEventType GetStaticType() noexcept { return SystemEventType::type; } \
                                    FORCE_INLINE virtual SystemEventType GetType() const noexcept override { return GetStaticType(); } \
                                    FORCE_INLINE virtual std::string GetName() const noexcept override { return #type; }
    //====================================================================================================
    #define EVENT_CLASS_FUNCTIONS(class) FORCE_INLINE static SystemEventClass GetClass() { return SystemEventClass::class; }
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API SystemEvent
    {
    public:
        /**
         *
         */
        SystemEvent() noexcept = default;
        /**
         *
         */
        virtual ~SystemEvent() noexcept = default;
        /**
         *
         * @return
         */
        FORCE_INLINE static SystemEventType GetStaticType() noexcept { return SystemEventType::None; }
        /**
         *
         * @return
        */
        virtual SystemEventType GetType() const noexcept = 0;
        /**
         *
         * @return
         */
        FORCE_INLINE virtual std::string GetName() const noexcept { return "None"; }
        /**
         *
         * @return
         */
        FORCE_INLINE static SystemEventClass GetClass() noexcept { return SystemEventClass::None; }
        /**
         *
         */
        FORCE_INLINE void Handle() noexcept { m_Handled = true; }
        /**
         *
         * @return
         */
        FORCE_INLINE bool IsHandled() const noexcept { return m_Handled; }

    private:
        bool m_Handled = false;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_EVENTCORE_HPP
//====================================================================================================