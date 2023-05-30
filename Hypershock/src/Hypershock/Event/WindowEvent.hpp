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
#ifndef HYPERSHOCK_WINDOWEVENT_HPP
#define HYPERSHOCK_WINDOWEVENT_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Event/EventCore.hpp"
//====================================================================================================
#include <string>
//====================================================================================================
namespace Hypershock {
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API WindowEvent : public SystemEvent {
    public:
        /**
         *
         * @param id
         */
        explicit WindowEvent(const std::string& id) : SystemEvent() {}
        /**
         *
         */
        ~WindowEvent() override = default;
        /**
         *
         * @return
         */
        FORCE_INLINE std::string GetId() const noexcept { return m_WindowId; }
        //====================================================================================================
        EVENT_CLASS_FUNCTIONS(Window)
        //====================================================================================================
    protected:
        std::string m_WindowId;
    };
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API WindowResizeEvent : public WindowEvent {
    public:
        /**
         *
         * @param id
         */
        explicit WindowResizeEvent(const std::string& id) : WindowEvent(id) {}
        /**
         *
         */
        ~WindowResizeEvent() override = default;
        //====================================================================================================
        EVENT_CLASS_FUNCTIONS(Window)
        EVENT_TYPE_FUNCTIONS(WindowResize)
        //====================================================================================================
    };
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API WindowFocusEvent : public WindowEvent {
    public:
        /**
         *
         * @param id
         */
        explicit WindowFocusEvent(const std::string& id) : WindowEvent(id) {}
        /**
         *
         */
        ~WindowFocusEvent() override = default;
        //====================================================================================================
        EVENT_CLASS_FUNCTIONS(Window)
        EVENT_TYPE_FUNCTIONS(WindowFocus)
        //====================================================================================================
    };
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API WindowUnfocusEvent : public WindowEvent {
    public:
        /**
         *
         * @param id
         */
        explicit WindowUnfocusEvent(const std::string& id) : WindowEvent(id) {}
        /**
         *
         */
        ~WindowUnfocusEvent() override = default;
        //====================================================================================================
        EVENT_CLASS_FUNCTIONS(Window)
        EVENT_TYPE_FUNCTIONS(WindowUnfocus)
        //====================================================================================================
    };
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API WindowCloseEvent : public WindowEvent {
    public:
        /**
         *
         * @param id
         */
        explicit WindowCloseEvent(const std::string& id) : WindowEvent(id) {}
        /**
         *
         */
        ~WindowCloseEvent() override = default;
        //====================================================================================================
        EVENT_CLASS_FUNCTIONS(Window)
        EVENT_TYPE_FUNCTIONS(WindowClose)
        //====================================================================================================
    };
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API WindowModeChangeEvent : public WindowEvent {
    public:
        /**
         *
         * @param id
         */
        explicit WindowModeChangeEvent(const std::string& id) : WindowEvent(id) {}
        /**
         *
         */
        ~WindowModeChangeEvent() override = default;
        //====================================================================================================
        EVENT_CLASS_FUNCTIONS(Window)
        EVENT_TYPE_FUNCTIONS(WindowModeChange)
        //====================================================================================================
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_WINDOWEVENT_HPP
//====================================================================================================