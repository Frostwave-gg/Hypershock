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

#ifndef HYPERSHOCK_MOUSEEVENT_HPP
#define HYPERSHOCK_MOUSEEVENT_HPP

#include "EventCore.hpp"
#include "Core/Core.hpp"
#include "Core/Types.hpp"

#include <glm/glm.hpp>

namespace Hypershock {

    class HYPERSHOCK_PUBLIC_API MouseEvent : public Event {
    public:
        MouseEvent() : Event() {}
        ~MouseEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Mouse)
    };


    class HYPERSHOCK_PUBLIC_API MouseMoveEvent : public MouseEvent {
    public:
        MouseMoveEvent(double x, double y) : MouseEvent(), m_X(x), m_Y(y) {}
        ~MouseMoveEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseMove)

        [[nodiscard]] inline glm::vec2 GetPosition() const { return {m_X, m_Y}; }

        [[nodiscard]] inline double GetX() const { return m_X; }
        [[nodiscard]] inline double GetY() const { return m_Y; }

    private:
        double m_X, m_Y;
    };

    class HYPERSHOCK_PUBLIC_API MouseScrollEvent : public MouseEvent {
    public:
        MouseScrollEvent(double xOffset, double yOffset) : MouseEvent(), m_XOffset(xOffset), m_YOffset(yOffset) {}
        ~MouseScrollEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseScroll)

        [[nodiscard]] inline glm::vec2 GetOffsets() const { return {m_XOffset, m_YOffset}; }

        [[nodiscard]] inline double GetXOffset() const { return m_XOffset; }
        [[nodiscard]] inline double GetYOffset() const { return m_YOffset; }

    private:
        double m_XOffset, m_YOffset;
    };

    class HYPERSHOCK_PUBLIC_API MouseButtonDownEvent : public MouseEvent {
    public:
        explicit MouseButtonDownEvent(Int32 button) : MouseEvent(), m_ButtonCode(button) {}
        ~MouseButtonDownEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseButtonDown)

        [[nodiscard]] inline Int32 GetButtonCode() const { return m_ButtonCode; }

    private:
        Int32 m_ButtonCode;
    };

    class HYPERSHOCK_PUBLIC_API MouseButtonUpEvent : public MouseEvent {
    public:
        explicit MouseButtonUpEvent(Int32 button) : MouseEvent(), m_ButtonCode(button) {}
        ~MouseButtonUpEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseButtonUp)

        [[nodiscard]] inline Int32 GetButtonCode() const { return m_ButtonCode; }

    private:
        Int32 m_ButtonCode;
    };

    class HYPERSHOCK_PUBLIC_API MouseButtonHoldEvent : public MouseEvent {
    public:
        explicit MouseButtonHoldEvent(Int32 button) : MouseEvent(), m_ButtonCode(button) {}
        ~MouseButtonHoldEvent() override = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseButtonHold)

        [[nodiscard]] inline Int32 GetButtonCode() const { return m_ButtonCode; }

    private:
        Int32 m_ButtonCode;
    };

}

#endif //HYPERSHOCK_MOUSEEVENT_HPP
