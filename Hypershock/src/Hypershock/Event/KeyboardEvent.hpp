//
// Created by jankr on 21-Jul-22.
//

#ifndef HYPERSHOCK_KEYBOARDEVENT_HPP
#define HYPERSHOCK_KEYBOARDEVENT_HPP

#include "Core/Core.hpp"
#include "Core/Types.hpp"
#include "Event.hpp"

namespace Hypershock {

    class HYPERSHOCK_PUBLIC_API KeyboardEvent : public Event {
    public:
        KeyboardEvent();
        virtual ~KeyboardEvent() = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)
    };

    class HYPERSHOCK_PUBLIC_API KeyboardButtonDownEvent : public KeyboardEvent {
    public:
        KeyboardButtonDownEvent(Int32 key) : KeyboardEvent(), m_Keycode(key) {}
        virtual ~KeyboardButtonDownEvent() = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)

        EVENT_TYPE_FUNCTIONS(KeyboardButtonDown)

        inline Int32 GetKeycode() const { return m_Keycode; }

    private:
        Int32 m_Keycode;
    };

    class HYPERSHOCK_PUBLIC_API KeyboardButtonUpEvent : public KeyboardEvent {
    public:
        KeyboardButtonUpEvent(Int32 key) : KeyboardEvent(), m_Keycode(key) {}
        virtual ~KeyboardButtonUpEvent() = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)

        EVENT_TYPE_FUNCTIONS(KeyboardButtonUp)

        inline Int32 GetKeycode() const { return m_Keycode; }

    private:
        Int32 m_Keycode;
    };

    class HYPERSHOCK_PUBLIC_API KeyboardButtonHoldEvent : public KeyboardEvent {
    public:
        KeyboardButtonHoldEvent(Int32 key) : KeyboardEvent(), m_Keycode(key) {}
        virtual ~KeyboardButtonHoldEvent() = default;

        EVENT_CLASS_FUNCTIONS(Keyboard)

        EVENT_TYPE_FUNCTIONS(KeyboardButtonHold)

        inline Int32 GetKeycode() const { return m_Keycode; }

    private:
        Int32 m_Keycode;
    };
}

#endif //HYPERSHOCK_KEYBOARDEVENT_HPP
