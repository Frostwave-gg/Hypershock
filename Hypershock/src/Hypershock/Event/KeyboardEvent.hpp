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

#ifndef HYPERSHOCK_KEYBOARDEVENT_HPP
#define HYPERSHOCK_KEYBOARDEVENT_HPP

#include "Core/Core.hpp"
#include "Core/Types.hpp"
#include "EventCore.hpp"

namespace Hypershock {

    class HYPERSHOCK_PUBLIC_API KeyboardEvent : public Event {
    public:
        KeyboardEvent() : Event() {}
        ~KeyboardEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)
    };

    class HYPERSHOCK_PUBLIC_API KeyboardButtonDownEvent : public KeyboardEvent {
    public:
        explicit KeyboardButtonDownEvent(Int32 key) : KeyboardEvent(), m_Keycode(key) {}
        ~KeyboardButtonDownEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)

        EVENT_TYPE_FUNCTIONS(KeyboardButtonDown)

        [[nodiscard]] inline Int32 GetKeycode() const { return m_Keycode; }

    private:
        Int32 m_Keycode;
    };

    class HYPERSHOCK_PUBLIC_API KeyboardButtonUpEvent : public KeyboardEvent {
    public:
        explicit KeyboardButtonUpEvent(Int32 key) : KeyboardEvent(), m_Keycode(key) {}
        ~KeyboardButtonUpEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)

        EVENT_TYPE_FUNCTIONS(KeyboardButtonUp)

        [[nodiscard]] inline Int32 GetKeycode() const { return m_Keycode; }

    private:
        Int32 m_Keycode;
    };

    class HYPERSHOCK_PUBLIC_API KeyboardButtonHoldEvent : public KeyboardEvent {
    public:
        explicit KeyboardButtonHoldEvent(Int32 key) : KeyboardEvent(), m_Keycode(key) {}
        ~KeyboardButtonHoldEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)

        EVENT_TYPE_FUNCTIONS(KeyboardButtonHold)

        [[nodiscard]] inline Int32 GetKeycode() const { return m_Keycode; }

    private:
        Int32 m_Keycode;
    };
}

#endif //HYPERSHOCK_KEYBOARDEVENT_HPP
