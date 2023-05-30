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
#ifndef HYPERSHOCK_SHAREDPTR_HPP
#define HYPERSHOCK_SHAREDPTR_HPP
//====================================================================================================
#include <vector>
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/Memory/WeakPtr.hpp"
#include "Hypershock/Core/Memory/UniquePtr.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    template<typename T> class WeakPtr;
    template<typename T> class UniquePtr;
    //====================================================================================================
    /**
     *
     * @tparam T
     */
    template<typename T>
    class HYPERSHOCK_PUBLIC_API SharedPtr
    {
        friend class WeakPtr<T>;
        friend class UniquePtr<T>;

    public:
        //====================================================================================================
        /**
         *
         * @tparam Args
         * @param args
         */
        template<typename ...Args>
        explicit FORCE_INLINE SharedPtr(Args... args) noexcept : m_RelatedWeakPointers()
        {
            m_ObjPtr = new T(args...);
        }
        /**
         *
         * @param other
         */
        explicit FORCE_INLINE SharedPtr(const T& other) noexcept : m_RelatedWeakPointers()
        {
            m_ObjPtr = new T(other);
        }
        /**
         *
         * @param other
         */
        explicit FORCE_INLINE SharedPtr(T&& other) noexcept : m_RelatedWeakPointers()
        {
            m_ObjPtr = new T(other);
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE SharedPtr(T* other) noexcept : m_RelatedWeakPointers()
        {
            m_ObjPtr = other;
        }
        /**
         *
         */
        FORCE_INLINE SharedPtr(TYPE_OF_NULLPTR) noexcept : m_ObjPtr(nullptr), m_RelatedWeakPointers()
        {
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE SharedPtr(const SharedPtr& other) noexcept
        {
            m_ObjPtr = new T(*other.Get());
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE SharedPtr(SharedPtr&& other) noexcept
        {
            m_ObjPtr = other.m_ObjPtr;

            for (WeakPtr<T>*& ptr : other.m_RelatedWeakPointers)
            {
                if (ptr == nullptr)
                {
                    continue;
                }

                ptr->Set(m_ObjPtr, this);
            }

            other.m_ObjPtr = nullptr;
            other.m_RelatedWeakPointers = std::vector<WeakPtr<T>*>();
        }
        /**
         *
         * @param other
         */
        FORCE_INLINE SharedPtr(const UniquePtr<T>& other) noexcept = delete;
        /**
         *
         * @param other
         */
        FORCE_INLINE SharedPtr(UniquePtr<T>&& other) noexcept
        {
            m_ObjPtr = other.m_ObjPtr;

            if (other.m_ObjPtr != nullptr)
            {
                delete other.m_ObjPtr;
                other.m_ObjPtr = nullptr;
            }
        }
        /**
         *
         */
        virtual FORCE_INLINE ~SharedPtr() noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            for (WeakPtr<T>*& ptr : m_RelatedWeakPointers)
            {
                if (ptr == nullptr)
                {
                    continue;
                }

                ptr->Invalidate();
            }
        }
        //====================================================================================================
    public:
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE SharedPtr& operator=(T* other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;

                for (WeakPtr<T>*& ptr : m_RelatedWeakPointers)
                {
                    if (ptr == nullptr)
                    {
                        continue;
                    }

                    ptr->Invalidate();
                }
            }

            m_ObjPtr = new T(*other);
            other = nullptr;
        }
        /**
         *
         * @return
         */
        FORCE_INLINE SharedPtr& operator=(TYPE_OF_NULLPTR) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;

                for (WeakPtr<T>*& ptr : m_RelatedWeakPointers)
                {
                    if (ptr == nullptr)
                    {
                        continue;
                    }

                    ptr->Invalidate();
                }
            }

            m_ObjPtr = nullptr;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE SharedPtr& operator=(const SharedPtr& other) noexcept
        {
            if (&other == this)
            {
                return *this;
            }

            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;

                for (WeakPtr<T>*& ptr : m_RelatedWeakPointers)
                {
                    if (ptr == nullptr)
                    {
                        continue;
                    }

                    ptr->Invalidate();
                }
            }

            m_ObjPtr = new T(*other.m_ObjPtr);
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE SharedPtr& operator=(SharedPtr&& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;

                for (WeakPtr<T>*& ptr : m_RelatedWeakPointers)
                {
                    if (ptr == nullptr)
                    {
                        continue;
                    }

                    ptr->Invalidate();
                }
            }

            m_ObjPtr = other.m_ObjPtr;

            for (WeakPtr<T>*& ptr : other.m_RelatedWeakPointers)
            {
                if (ptr == nullptr)
                {
                    continue;
                }

                ptr->Set(m_ObjPtr, this);
            }

            other.m_ObjPtr = nullptr;
            other.m_RelatedWeakPointers = std::vector<WeakPtr<T>*>();
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE SharedPtr& operator=(const UniquePtr<T>& other) noexcept = delete;
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE SharedPtr& operator=(UniquePtr<T>&& other) noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            m_ObjPtr = other.m_ObjPtr;

            if (other.m_ObjPtr != nullptr)
            {
                delete other.m_ObjPtr;
            }

            for (WeakPtr<T>& ptr : m_RelatedWeakPointers)
            {
                ptr.m_ObjPtr = m_ObjPtr;
            }
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
        FORCE_INLINE bool operator==(const SharedPtr& other) const noexcept
        {
            return m_ObjPtr == other.m_ObjPtr;
        }
        /**
         *
         * @param other
         * @return
         */
        FORCE_INLINE bool operator==(const WeakPtr<T>& other) const noexcept
        {
            return m_ObjPtr == other.Get();
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
         * @return
         */
        FORCE_INLINE WeakPtr<T> GetWeakPtr() noexcept
        {
            return WeakPtr<T>(m_ObjPtr, this);
        }
        /**
         *
         * @return
         */
        FORCE_INLINE size Count() const noexcept
        {
            return m_RelatedWeakPointers.size();
        }
        /**
         *
         */
        FORCE_INLINE void Invalidate() const noexcept
        {
            if (m_ObjPtr != nullptr)
            {
                delete m_ObjPtr;
            }

            for (WeakPtr<T>& ptr : m_RelatedWeakPointers)
            {
                ptr.Invalidate();
            }
        }

    protected:
        /**
         *
         * @param ptr
         */
        FORCE_INLINE void RegisterWeakPtr(WeakPtr<T>* ptr) noexcept
        {
            if (ptr == nullptr)
            {
                return;
            }

            m_RelatedWeakPointers.emplace_back(ptr);
        }
        /**
         *
         * @param ptr
         */
        FORCE_INLINE void UnregisterWeakPtr(WeakPtr<T>* ptr) noexcept
        {
            if (ptr == nullptr)
            {
                return;
            }

            std::remove(m_RelatedWeakPointers.begin(), m_RelatedWeakPointers.end(), ptr);
        }

    private:
        T* m_ObjPtr;
        std::vector<WeakPtr<T>*> m_RelatedWeakPointers;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_SHAREDPTR_HPP
//====================================================================================================