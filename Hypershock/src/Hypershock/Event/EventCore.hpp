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

#ifndef HYPERSHOCK_EVENTCORE_HPP
#define HYPERSHOCK_EVENTCORE_HPP

#include "Core/Core.hpp"

#include <string>

namespace Hypershock {

    enum class EventType {
        None,
        MouseButtonDown, MouseButtonUp, MouseButtonHold, MouseScroll, MouseMove,
        KeyboardButtonDown, KeyboardButtonUp, KeyboardButtonHold,
        WindowClose, WindowResize, WindowFocus, WindowUnfocus, WindowModeChange,

    };

    enum class EventClass {
        None,
        Keyboard,
        Mouse,
        Window,
        Application
    };

#define EVENT_TYPE_FUNCTIONS(type) inline static EventType GetStaticType() { return EventType::type; } \
                                    [[nodiscard]] virtual EventType GetType() const override { return GetStaticType(); } \
                                    [[nodiscard]] inline virtual std::string GetName() const override { return #type; }

#define EVENT_CLASS_FUNCTIONS(class) inline static EventClass GetClass() { return EventClass::class; }


    class HYPERSHOCK_PUBLIC_API Event {
    public:
        Event() = default;
        virtual ~Event() = default;

        inline static EventType GetStaticType() { return EventType::None; }
        [[nodiscard]] virtual EventType GetType() const = 0;
        [[nodiscard]] inline virtual std::string GetName() const { return "None"; }
        inline static EventClass GetClass() { return EventClass::None; }

        inline void Handle() { m_Handled = true; }
        [[nodiscard]] inline bool IsHandled() const { return m_Handled; }

    protected:
        bool m_Handled = false;
    };

}



#endif //HYPERSHOCK_EVENT_HPP
