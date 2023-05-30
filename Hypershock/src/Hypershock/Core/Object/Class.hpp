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
#ifndef HYPERSHOCK_CLASS_HPP
#define HYPERSHOCK_CLASS_HPP
//====================================================================================================
#include <set>
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/Memory/WeakPtr.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    class Object;
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API Class
    {
    public:
        /**
         *
         * @tparam T
         * @tparam Types
         * @return
         */
        template<typename T, typename ...Types>
        FORCE_INLINE static Class* New() noexcept
        {
            Class* newClass = new Class();

            newClass->SetCastFlags<T, Types...>();
            newClass->SetId(++s_LastAssignedId);

            return newClass;
        }
        /**
         *
         * @return
         */
        static Class* New() noexcept;

    private:
        static uint32 s_LastAssignedId;

    public:
        /**
         *
         */
        virtual ~Class() noexcept = default;

    public:
        /**
         *
         * @return
         */
        FORCE_INLINE uint32 GetId() const noexcept { return m_Id; }
        /**
         *
         * @param other
         * @return
         */
        bool IsA(const WeakPtr<Class>& other) const noexcept;
        /**
         *
         * @param object
         * @return
         */
        bool IsA(const WeakPtr<Object>& object) const noexcept;
        /**
         *
         * @tparam T
         * @return
         */
        template<typename T>
        FORCE_INLINE bool IsA() const noexcept { return IsA(T::StaticClass()); }
        /**
         *
         * @param other
         * @return
         */
        bool HasCastFlags(const WeakPtr<Class>& other) const noexcept;
        /**
         *
         * @param object
         * @return
         */
        bool HasCastFlags(const WeakPtr<Object>& object) const noexcept;
        /**
         *
         * @tparam T
         * @return
         */
        template<typename T>
        FORCE_INLINE bool HasCastFlags() const noexcept { return HasCastFlags(T::StaticClass()); }

    protected:
        /**
         *
         */
        explicit Class() noexcept = default;
        /**
         *
         * @tparam T
         * @tparam Types
         */
        template<typename T, typename ...Types>
        FORCE_INLINE void SetCastFlags() noexcept
        {
            Class* otherClass = T::StaticClass();

            if (otherClass == nullptr)
            {
                return;
            }

            m_CastFlags.insert(otherClass->GetId());

            for (uint32 id : otherClass->m_CastFlags)
            {
                m_CastFlags.insert(id);
            }

            SetCastFlags<Types...>();
        }
        /**
         *
         * @tparam ...
         */
        template<typename...>
        FORCE_INLINE void SetCastFlags() const noexcept
        {
        }
        /**
         *
         * @param id
         */
        FORCE_INLINE void SetId(uint32 id) noexcept { m_Id = id; }

    private:
        uint32 m_Id = 0; // TODO: add class id struct to be more specific. Add macro to quickly define different id structs.
        std::set<uint32> m_CastFlags;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_CLASS_HPP
//====================================================================================================