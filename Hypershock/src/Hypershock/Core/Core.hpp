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
#ifndef HYPERSHOCK_CORE_HPP
#define HYPERSHOCK_CORE_HPP
//====================================================================================================
#include "Hypershock/Core/Compiler.hpp"
#include "Hypershock/Core/Platform.hpp"
//====================================================================================================
// Variety
//====================================================================================================
#define EMPTY
#define NODISCARD [[nodiscard]]
#define SIGN(x) (x >= 0 ? 1 : -1)
#define DECIMAL(x) (x - static_cast<int32>(x))

#ifdef HYPERSHOCK_WINDOWS
    #define DEBUG_BREAK() __debugbreak()
#else
    #define DEBUG_BREAK()
#endif

#define CHECK(x) { if (!(x)) DEBUG_BREAK(); }

#define NOT_IMPLEMENTED() DEBUG_BREAK()

#ifdef HYPERSHOCK_MSVC
    #define INLINE __inline
    #define FORCE_INLINE __forceinline
#else
    #define INLINE inline

    #if defined(HYPERSHOCK_GCC) || defined(HYPERSHOCK_CLANG)
        #define FORCE_INLINE __attribute__((always_inline))
    #else
        #define FORCE_INLINE inline
    #endif
#endif
//====================================================================================================
// Import / Export
//====================================================================================================
#ifdef HYPERSHOCK_MSVC
    #define DLL_EXPORT __declspec(dllexport)
    #define DLL_IMPORT __declspec(dllimport)
#else
    #define DLIB_EXPORT_PUBLIC __attribute__((visibility("default")))
    #define DLIB_EXPORT_PRIVATE __attribute__((visibility("hidden")))
    #define DLIB_IMPORT
#endif

#ifdef HYPERSHOCK_BUILD_SHARED
    #ifdef HYPERSHOCK_WINDOWS
        #ifdef HYPERSHOCK_MSVC
            #ifdef HYPERSHOCK_EXPORT
                #define HYPERSHOCK_PUBLIC_API DLL_EXPORT
            #else
                #define HYPERSHOCK_PUBLIC_API DLL_IMPORT
            #endif

            #define HYPERSHOCK_PRIVATE_API EMPTY
        #else
            #ifdef HYPERSHOCK_EXPORT
                #define HYPERSHOCK_PUBLIC_API DLIB_EXPORT_PUBLIC
                #define HYPERSHOCK_PRIVATE_API DLIB_EXPORT_PRIVATE
            #else
                #define HYPERSHOCK_PUBLIC_API EMPTY
                #define HYPERSHOCK_PRIVATE_API EMPTY
            #endif
        #endif
    #else
            #ifdef HYPERSHOCK_EXPORT
                #define HYPERSHOCK_PUBLIC_API DLIB_EXPORT_PUBLIC
                #define HYPERSHOCK_PRIVATE_API DLIB_EXPORT_PRIVATE
            #else
                #define HYPERSHOCK_PUBLIC_API EMPTY
                #define HYPERSHOCK_PRIVATE_API EMPTY
            #endif
    #endif
#else
    #define HYPERSHOCK_PUBLIC_API EMPTY
    #define HYPERSHOCK_PRIVATE_API EMPTY
#endif
//====================================================================================================
#endif //HYPERSHOCK_CORE_HPP
//====================================================================================================