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
#ifndef HYPERSHOCK_TYPES_H
#define HYPERSHOCK_TYPES_H
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
//====================================================================================================
namespace Hypershock {
    //====================================================================================================
    typedef unsigned char uint8;
    typedef unsigned short int uint16;
    typedef unsigned int uint32;
    typedef unsigned long long int uint64;
    typedef signed char int8;
    typedef signed short int int16;
    typedef signed int int32;
    typedef signed long long int int64;
    typedef uint8 byte;
    typedef uint64 size;
    typedef uint8 char8;
    typedef uint16 char16;
    typedef uint32 char32;
    //====================================================================================================
    typedef int32 TYPE_OF_NULL;
    typedef decltype(nullptr) TYPE_OF_NULLPTR;
    //====================================================================================================
    namespace Limits {
        //====================================================================================================
        constexpr uint8 uint8_MIN = 0;
        constexpr uint8 uint8_MAX = 0xFFU;
        constexpr uint16 uint16_MIN = 0;
        constexpr uint16 uint16_MAX = 0xFFFFU;
        constexpr uint32 uint32_MIN = 0;
        constexpr uint32 uint32_MAX = 0xFFFFFFFFU;
        constexpr uint64 uint64_MIN = 0;
        constexpr uint64 uint64_MAX = 0xFFFFFFFFFFFFFFFFULL;
        //====================================================================================================
        constexpr int8 int8_MIN = -128;
        constexpr int8 int8_MAX = 127;
        constexpr int16 int16_MIN = -32768;
        constexpr int16 int16_MAX = 32767;
        constexpr int32 int32_MIN = -2147483648;
        constexpr int32 int32_MAX = 2147483647;
        constexpr int64 int64_MIN = 0x8000000000000000LL;
        constexpr int64 int64_MAX = 0x7FFFFFFFFFFFFFFFLL;
        //====================================================================================================
        constexpr byte byte_MIN = 0;
        constexpr byte byte_MAX = 0xFFU;
        //====================================================================================================
        constexpr size size_MIN = 0x8000000000000000ULL;
        constexpr size size_MAX = 0x7FFFFFFFFFFFFFFFULL;
        //====================================================================================================
        /**
         *
         * @tparam T
         * @return
         */
        template<typename T> constexpr T Minimum();
        /**
         *
         * @tparam T
         * @return
         */
        template<typename T> constexpr T Maximum();
        //====================================================================================================
        /**
         *
         * @return
         */
        template<> constexpr uint8 Minimum<uint8>() { return uint8_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr uint8 Maximum<uint8>() { return uint8_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr uint16 Minimum<uint16>() { return uint16_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr uint16 Maximum<uint16>() { return uint16_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr uint32 Minimum<uint32>() { return uint32_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr uint32 Maximum<uint32>() { return uint32_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr uint64 Minimum<uint64>() { return uint64_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr uint64 Maximum<uint64>() { return uint64_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr int8 Minimum<int8>() { return int8_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr int8 Maximum<int8>() { return int8_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr int16 Minimum<int16>() { return int16_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr int16 Maximum<int16>() { return int16_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr int32 Minimum<int32>() { return int32_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr int32 Maximum<int32>() { return int32_MAX; }
        /**
         *
         * @return
         */
        template<> constexpr int64 Minimum<int64>() { return int64_MIN; }
        /**
         *
         * @return
         */
        template<> constexpr int64 Maximum<int64>() { return int64_MAX; }
        //====================================================================================================
    }
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_TYPES_H
//====================================================================================================