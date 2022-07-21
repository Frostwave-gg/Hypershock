//
// Created by jankr on 21-Jul-22.
//

#ifndef HYPERSHOCK_MOUSEEVENT_HPP
#define HYPERSHOCK_MOUSEEVENT_HPP

#include "Event.hpp"
#include "Core/Core.hpp"
#include "Core/Types.hpp"

#include <glm/glm.hpp>

namespace Hypershock {

    class HYPERSHOCK_PUBLIC_API MouseEvent : public Event {
    public:
        MouseEvent();
        virtual ~MouseEvent();

        EVENT_CLASS_FUNCTIONS(Mouse)
    };


    class HYPERSHOCK_PUBLIC_API MouseMoveEvent : public MouseEvent {
    public:
        MouseMoveEvent(double x, double y) : MouseEvent(), m_X(x), m_Y(y) {}
        virtual ~MouseMoveEvent() = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseMove)

        inline glm::vec2 GetPosition() const { return {m_X, m_Y}; }

        inline double GetX() const { return m_X; }
        inline double GetY() const { return m_Y; }

    private:
        double m_X, m_Y;
    };

    class HYPERSHOCK_PUBLIC_API MouseScrollEvent : public MouseEvent {
    public:
        MouseScrollEvent(double xOffset, double yOffset) : MouseEvent(), m_XOffset(xOffset), m_YOffset(yOffset) {}
        virtual ~MouseScrollEvent() = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseScroll)

        inline glm::vec2 GetOffsets() const { return {m_XOffset, m_YOffset}; }

        inline double GetXOffset() const { return m_XOffset; }
        inline double GetYOffset() const { return m_YOffset; }

    private:
        double m_XOffset, m_YOffset;
    };

    class HYPERSHOCK_PUBLIC_API MouseButtonDownEvent : public MouseEvent {
    public:
        MouseButtonDownEvent(Int32 button) : MouseEvent(), m_ButtonCode(button) {}
        virtual ~MouseButtonDownEvent() = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseButtonDown)

        inline Int32 GetButtonCode() const { return m_ButtonCode; }

    private:
        Int32 m_ButtonCode;
    };

    class HYPERSHOCK_PUBLIC_API MouseButtonUpEvent : public MouseEvent {
    public:
        MouseButtonUpEvent(Int32 button) : MouseEvent(), m_ButtonCode(button) {}
        virtual ~MouseButtonUpEvent() = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseButtonUp)

        inline Int32 GetButtonCode() const { return m_ButtonCode; }

    private:
        Int32 m_ButtonCode;
    };

    class HYPERSHOCK_PUBLIC_API MouseButtonHoldEvent : public MouseEvent {
    public:
        MouseButtonHoldEvent(Int32 button) : MouseEvent(), m_ButtonCode(button) {}
        virtual ~MouseButtonHoldEvent() = default;

        EVENT_CLASS_FUNCTIONS(Mouse)

        EVENT_TYPE_FUNCTIONS(MouseButtonHold)

        inline Int32 GetButtonCode() const { return m_ButtonCode; }

    private:
        Int32 m_ButtonCode;
    };

}

#endif //HYPERSHOCK_MOUSEEVENT_HPP
