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
#ifndef HYPERSHOCK_UNIQUEPTR_HPP
#define HYPERSHOCK_UNIQUEPTR_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/Memory/SharedPtr.hpp"
#include "Hypershock/Core/Memory/WeakPtr.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    template<typename T> class SharedPtr;
    //====================================================================================================
    /**
     * TODO: do the version of the pointers but for arrays (https://en.cppreference.com/w/cpp/memory/unique_ptr for reference)
     * @tparam T
     */
    template<typename T>
    class HYPERSHOCK_PUBLIC_API UniquePtr
    {
        friend class SharedPtr<T>;

    public:
        //====================================================================================================
        /**
         *
         * @tparam Args
         * @param args
         */
        template<typename ...Args>
        explicit FORCE_INLINE UniquePtr(Args... args) noexcept
        {
            m_ObjPtr = new T(args...);
        }
        /**
         *
         * @param other
         */
        explicit FORCE_INLINE UniquePtr(const T& other) noexcept
        {
            m_ObjPtr = new T(other);
        }
        /**
         *
         * @param other
         */
        explicit FORCE_INLINE UniquePtr(T&& other) noexcept
        {
            m_ObjPtr = new T(other);
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE UniquePtr(T* other) noexcept
        {
            m_ObjPtr = other;
        }
        /**
         *
         */
        FORCE_INLINE UniquePtr(TYPE_OF_NULLPTR) noexcept
        {
            m_ObjPtr = nullptr;
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE UniquePtr(const UniquePtr& other) noexcept = delete;
        /**
         *
         * @param other
         */
        FORCE_INLINE UniquePtr(UniquePtr&& other) noexcept
        {
            m_ObjPtr = other.m_ObjPtr;
            other.m_ObjPtr = nullptr;
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE UniquePtr(const SharedPtr<T>& other) noexcept = delete;
        /**
         *
         * @param other
         */
        FORCE_INLINE UniquePtr(SharedPtr<T>&& other) noexcept
        {
            m_ObjPtr = other.m_ObjPtr;
            other.m_ObjPtr = nullptr;
            other.Invalidate();
        }
        /**
         *
         */
        virtual FORCE_INLINE ~UniquePtr() noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }
        }
        //====================================================================================================
    public:
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE UniquePtr& operator=(T* other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = other;

            return *this;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE UniquePtr& operator=(TYPE_OF_NULLPTR) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
                m_ObjPtr = nullptr;
            }

            return *this;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE UniquePtr& operator=(const UniquePtr& other) noexcept = delete;
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE UniquePtr& operator=(UniquePtr&& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = other.m_ObjPtr;
            other.m_ObjPtr = nullptr;

            return *this;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE UniquePtr& operator=(const SharedPtr<T>& other) noexcept = delete;
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE UniquePtr& operator=(SharedPtr<T>&& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = other.m_ObjPtr;
            other.m_ObjPtr = nullptr;
            other.Invalidate();
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
         *
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
        FORCE_INLINE bool operator==(const UniquePtr& other) const noexcept
        {
            return m_ObjPtr == other.m_ObjPtr;
        }
        /**
         *
         * @return
         */
        explicit FORCE_INLINE operator bool() const noexcept
        {
            return IsValid();
        }
        /**
         *
         * @return
         */
        FORCE_INLINE T* operator->() const noexcept
        {
            return m_ObjPtr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE T& operator*() const noexcept
        {
            return *m_ObjPtr;
        }

    public:
        /**
         *
         * @return
         */
        FORCE_INLINE T* Release() noexcept
        {
            T* ret = m_ObjPtr;
            m_ObjPtr = nullptr;
            return m_ObjPtr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE T* Get() const noexcept
        {
            return m_ObjPtr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE bool IsValid() const noexcept
        {
            return m_ObjPtr != nullptr;
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE void Swap(UniquePtr&& other) noexcept
        {
            T* temp = m_ObjPtr;
            m_ObjPtr = other.m_ObjPtr;
            other.m_ObjPtr = temp;
        }
        /**
         *
         * @tparam Args
         * @param args
         */
        template<typename ...Args>
        FORCE_INLINE void Reset(Args ...args) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = new T(args...);
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE void Reset(const T& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = new T(other);
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE void Reset(T&& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = new T(other);
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE void Reset(T* other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = other;
        }
        /**
         *
         */
        FORCE_INLINE void Reset(TYPE_OF_NULLPTR) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
                m_ObjPtr = nullptr;
            }
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE void Reset(UniquePtr&& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = other.m_ObjPtr;
            other.m_ObjPtr = nullptr;
        }

    private:
        T* m_ObjPtr;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_UNIQUEPTR_HPP
//====================================================================================================