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

#ifndef HYPERSHOCK_CORE_HPP
#define HYPERSHOCK_CORE_HPP

#define HYPERSHOCK_PLATFORM_WINDOWS 0
#define HYPERSHOCK_PLATFORM_MACOS 1
#define HYPERSHOCK_PLATFORM_IOS 2
#define HYPERSHOCK_PLATFORM_LINUX 3
#define HYPERSHOCK_PLATFORM_ANDROID 4
#define HYPERSHOCK_PLATFORM_WEB 5


#if (defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__))

#ifdef HYPERSHOCK_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define HYPERSHOCK_PLATFORM HYPERSHOCK_PLATFORM_WINDOWS
#define HYPERSHOCK_WINDOWS

#if (defined(_WIN64))
#define HYPERSHOCK_WINDOWS_64
#else
#define HYPERSHOCK_WINDOWS_32
#endif

#endif


#if ((defined(macintosh) || defined(Macintosh) || defined(__APPLE__) || defined(__MACH__)) && !defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__))

#ifdef HYPERSHOCK_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define HYPERSHOCK_PLATFORM HYPERSHOCK_PLATFORM_MACOS
#define HYPERSHOCK_MACOS

#endif


#if ((defined(__APPLE__) || defined(__MACH__)) && defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__))

#ifdef HYPERSHOCK_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define HYPERSHOCK_PLATFORM HYPERSHOCK_PLATFORM_IOS
#define HYPERSHOCK_IOS

#endif


#if (defined(__linux__) || defined(linux) || defined(__linux))

#ifdef HYPERSHOCK_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define HYPERSHOCK_PLATFORM HYPERSHOCK_PLATFORM_LINUX
#define HYPERSHOCK_LINUX

#endif


#if (defined(__ANDROID__))

#ifdef HYPERSHOCK_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define HYPERSHOCK_PLATFORM HYPERSHOCK_PLATFORM_ANDROID
#define HYPERSHOCK_ANDROID

#endif


#if (defined(__EMSCRIPTEN__))

#ifdef HYPERSHOCK_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define HYPERSHOCK_PLATFORM HYPERSHOCK_PLATFORM_WEB
#define HYPERSHOCK_WEB

#endif

#define HYPERSHOCK_COMPILER_CLANG 0
#define HYPERSHOCK_COMPILER_GCC 1
#define HYPERSHOCK_COMPILER_MSVC 2

#if defined(__clang__)
/** Clang/LLVM. ---------------------------------------------- */
#define HYPERSHOCK_CLANG
#define HYPERSHOCK_COMPILER HYPERSHOCK_COMPILER_CLANG

#elif defined(__GNUC__) || defined(__GNUG__)
/** GNU GCC/G++. --------------------------------------------- */
#define HYPERSHOCK_GCC
#define HYPERSHOCK_COMPILER HYPERSHOCK_COMPILER_GCC

#elif defined(_MSC_VER)
/** Microsoft Visual Studio. --------------------------------- */
#define HYPERSHOCK_MSVC
#define HYPERSHOCK_COMPILER HYPERSHOCK_COMPILER_MSVC

#endif // GGEZ_COMPILER

#ifdef HYPERSHOCK_BUILD_SHARED

    #ifdef HYPERSHOCK_WINDOWS

        #ifdef HYPERSHOCK_MSVC

            #ifdef HYPERSHOCK_EXPORT
                #define HYPERSHOCK_PUBLIC_API __declspec(dllexport)
            #else
                #define HYPERSHOCK_PUBLIC_API __declspec(dllimport)
            #endif

            #define HYPERSHOCK_PRIVATE_API

        #else

            #define HYPERSHOCK_PUBLIC_API __attribute__((visibility("default")))
            #define HYPERSHOCK_PRIVATE_API __attribute__((visibility("hidden")))

        #endif

    #else

        #define HYPERSHOCK_PUBLIC_API __attribute__((visibility("default")))
        #define HYPERSHOCK_PRIVATE_API __attribute__((visibility("hidden")))

    #endif

#else

    #define HYPERSHOCK_PUBLIC_API
    #define HYPERSHOCK_PRIVATE_API

#endif

#define HYPERSHOCK_CONSTEXPR constexpr

#endif //HYPERSHOCK_CORE_HPP
