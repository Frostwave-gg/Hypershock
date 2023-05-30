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
#ifndef HYPERSHOCK_WEAKPTR_HPP
#define HYPERSHOCK_WEAKPTR_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/Memory/SharedPtr.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    template<typename T> class SharedPtr;
    //====================================================================================================
    template<typename T>
    class HYPERSHOCK_PUBLIC_API WeakPtr
    {
        friend class SharedPtr<T>;

    public:
        //====================================================================================================
        /**
         *
         */
        FORCE_INLINE WeakPtr() noexcept : m_ObjPtr(nullptr), m_Owner(nullptr)
        {
        }
        /**
         *
         * @param obj
         */
        FORCE_INLINE WeakPtr(T* obj) noexcept : m_ObjPtr(obj), m_Owner(nullptr)
        {
        }
        /**
         *
         */
        FORCE_INLINE WeakPtr(TYPE_OF_NULLPTR) noexcept : m_ObjPtr(nullptr), m_Owner(nullptr)
        {
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE WeakPtr(const WeakPtr& other) noexcept : m_ObjPtr(other.m_ObjPtr), m_Owner(other.m_Owner)
        {
            if (m_Owner != nullptr)
            {
                m_Owner->RegisterWeakPtr(this);
            }
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE WeakPtr(WeakPtr&& other) noexcept : m_ObjPtr(other.m_ObjPtr), m_Owner(other.m_Owner)
        {
            if (other.m_Owner != nullptr)
            {
                other.m_Owner.UnregisterWeakPtr(other);
            }

            other.Invalidate();

            m_Owner->RegisterWeakPtr(this);
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE WeakPtr(const SharedPtr<T>& other) noexcept : m_ObjPtr(nullptr), m_Owner(nullptr)
        {
            Set(other.m_ObjPtr, &other);
        }
        /**
         *
         */
        virtual ~WeakPtr() noexcept
        {
            if (m_Owner != nullptr)
            {
                m_Owner->UnregisterWeakPtr(this);
            }
        }
        //====================================================================================================
    public:
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE WeakPtr& operator=(const WeakPtr& other) noexcept
        {
            if (&other == this)
            {
                return *this;
            }

            if (other.m_ObjPtr == m_ObjPtr || other.m_Owner == m_Owner)
            {
                return *this;
            }

            m_ObjPtr = other.m_ObjPtr;

            if (m_Owner != nullptr)
            {
                m_Owner->UnregisterWeakPtr(this);
            }

            m_Owner = other.m_Owner;

            if (m_Owner != nullptr)
            {
                m_Owner->RegisterWeakPtr(this);
            }

            return *this;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE WeakPtr& operator=(WeakPtr&& other) noexcept
        {
            if (&other == this)
            {
                return *this;
            }

            m_ObjPtr = other.m_ObjPtr;
            m_Owner = other.m_Owner;

            if (other.m_Owner != nullptr)
            {
                other.m_Owner.UnregisterWeakPtr(other);
            }

            other.Invalidate();

            m_Owner->RegisterWeakPtr(this);

            return *this;
        }
        /**
         *
         * @param obj
         * @return
         */
        FORCE_INLINE WeakPtr& operator=(const T* obj) noexcept
        {
            if (m_ObjPtr == obj)
            {
                return *this;
            }

            if (m_Owner != nullptr)
            {
                m_Owner->UnregisterWeakPtr(this);
            }

            m_ObjPtr = obj;
            m_Owner = nullptr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE WeakPtr& operator=(TYPE_OF_NULLPTR) noexcept
        {
            if (m_Owner != nullptr)
            {
                m_Owner->UnregisterWeakPtr(this);
            }

            Invalidate();

            return *this;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE WeakPtr& operator=(const SharedPtr<T>& other) noexcept
        {
            Set(other.m_ObjPtr, &other);
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE bool operator==(const WeakPtr& other) const noexcept
        {
            return m_ObjPtr == other.m_ObjPtr;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE bool operator==(const T* other) const noexcept
        {
            return m_ObjPtr == other;
        }
        /**
         * TODO: non-member operators for all smart pointers
         * @return
         */
        FORCE_INLINE bool operator==(TYPE_OF_NULLPTR) const noexcept
        {
            return m_ObjPtr == nullptr;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE bool operator==(const SharedPtr<T>& other) const noexcept
        {
            return m_Owner == &other;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE T* operator->() const noexcept
        {
            return Get();
        }
        /**
         *
         * @return
         */
        FORCE_INLINE T& operator*() const noexcept
        {
            return *Get();
        }
        /**
         *
         * @return
         */
        explicit FORCE_INLINE operator bool() const noexcept
        {
            return IsValid();
        }

    public:
        /**
         *
         * @return
         */
        FORCE_INLINE bool IsValid() const noexcept
        {
            if (m_Owner == nullptr)
            {
                return m_ObjPtr != nullptr;
            }

            return m_Owner->IsValid();
        }
        /**
         *
         * @return
         */
        FORCE_INLINE T* Get() const noexcept
        {
            if (m_Owner != nullptr && m_Owner->IsValid())
            {
                return m_Owner->Get();
            }

            return m_ObjPtr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE SharedPtr<T>& GetOwner() const noexcept
        {
            static const SharedPtr<T> null = SharedPtr<T>(nullptr);

            if (m_Owner == nullptr)
            {
                return null;
            }

            return *m_Owner;
        }

    protected:
        //====================================================================================================
        FORCE_INLINE WeakPtr(T* obj, SharedPtr<T>* owner) noexcept : m_ObjPtr(obj), m_Owner(owner)
        {
            if (m_Owner != nullptr)
            {
                m_Owner->RegisterWeakPtr(this);
            }
        }
        //====================================================================================================

    protected:
        /**
         *
         */
        FORCE_INLINE void Invalidate() noexcept
        {
            m_ObjPtr = nullptr;
            m_Owner = nullptr;
        }
        /**
         *
         * @param obj
         * @param owner
         */
        FORCE_INLINE void Set(const T* obj, const SharedPtr<T>* owner) noexcept
        {
            if (m_ObjPtr == obj && m_Owner == owner)
            {
                return;
            }

            m_ObjPtr = obj;

            if (m_Owner != nullptr)
            {
                m_Owner->UnregisterWeakPtr(this);
            }

            m_Owner = owner;

            if (m_Owner != nullptr)
            {
                m_Owner->RegisterWeakPtr(this);
            }
        }

    private:
        T* m_ObjPtr;
        SharedPtr<T>* m_Owner;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_WEAKPTR_HPP
//====================================================================================================