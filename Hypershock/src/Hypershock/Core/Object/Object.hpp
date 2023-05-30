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
#ifndef HYPERSHOCK_OBJECT_HPP
#define HYPERSHOCK_OBJECT_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/Memory/WeakPtr.hpp"
#include "Hypershock/Core/String/String.hpp"
#include "Hypershock/Core/Time/Timespan.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    class Class;
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API Object
    {
    public:
        /**
         *
         * @return
         */
        static WeakPtr<Class> StaticClass() noexcept;
        /**
         *
         * @return
         */
        FORCE_INLINE virtual WeakPtr<Class> GetStaticClass() const noexcept { return StaticClass(); }
        /**
         *
         * @return
         */
        FORCE_INLINE virtual String GetName() const noexcept { return TEXT("Object_(TODO: guid)"); }

    public:
        // TODO: add a macro that will define the class of the object by defining a static function that will contain the static variable of the class for the object
        // TODO: add other shit to the macro as well.
        Object() noexcept;
        virtual ~Object() noexcept;

    public:
        virtual void BeginPlay() noexcept;
        virtual void Tick(Timespan deltaTime) noexcept;
        virtual void EndPlay() noexcept;
        virtual void OnDestroy() noexcept;

    public:
        /**
         *
         * @tparam T
         * @return
         */
        template<typename T>
        FORCE_INLINE bool IsA() const noexcept
        {
            const WeakPtr<Class> otherStaticClass = T::StaticClass();
            if (!otherStaticClass.IsValid())
            {
                return false;
            }

            return IsA(otherStaticClass);
        }
        /**
         *
         * @param other
         * @return
         */
        bool IsA(const WeakPtr<Class> other) const noexcept;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_OBJECT_HPP
//====================================================================================================