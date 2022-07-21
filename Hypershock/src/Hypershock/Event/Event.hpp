//
// Created by jankr on 21-Jul-22.
//

#ifndef HYPERSHOCK_EVENT_HPP
#define HYPERSHOCK_EVENT_HPP

#include "Core/Core.hpp"

#include <string>

namespace Hypershock {

    enum class EventType {
        None,
        MouseButtonDown, MouseButtonUp, MouseButtonHold, MouseScroll, MouseMove,
        KeyboardButtonDown, KeyboardButtonUp, KeyboardButtonHold,
        WindowClose, WindowResize, WindowFocus, WindowUnfocus, WindowModeChange
    };

    enum class EventClass {
        None,
        Input,
        Keyboard,
        Mouse,
        Window,
        Application
    };

#define EVENT_TYPE_FUNCTIONS(type) inline static EventType GetStaticType() { return EventType::type; } \
                                    virtual EventType GetType() const override { return GetStaticType(); } \
                                    inline virtual std::string GetName() const override { return #type; }

#define EVENT_CLASS_FUNCTIONS(class) inline static EventClass GetClass() { return EventClass::class; }


    class HYPERSHOCK_PUBLIC_API Event {
    public:
        Event() = default;
        virtual ~Event() = default;

        inline static EventType GetStaticType() { return EventType::None; }
        virtual EventType GetType() const = 0;
        inline virtual std::string GetName() const { return "None"; }
        inline static EventClass GetClass() { return EventClass::None; }

        inline void Handle() { m_Handled = true; }
        inline bool IsHandled() const { return m_Handled; }

    protected:
        bool m_Handled = false;
    };

}



#endif //HYPERSHOCK_EVENT_HPP
