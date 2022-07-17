//
// Created by jankr on 15-Jul-22.
//

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

#endif //HYPERSHOCK_CORE_HPP
