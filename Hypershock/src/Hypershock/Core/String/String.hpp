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
#ifndef HYPERSHOCK_STRING_HPP
#define HYPERSHOCK_STRING_HPP
//====================================================================================================
#include <vector>
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    // Macros for handling unicode strings and characters
    #ifdef TEXT
        #undef TEXT
    #endif
    #define TEXT(x) (char16*)(u##x)

    #ifdef CHAR
        #undef CHAR
    #endif
    #define CHAR(x) (char16)(u##x)
    //====================================================================================================
    namespace ASCII
    {
        constexpr char HYPERSHOCK_PUBLIC_API Null = '\0';
        constexpr char HYPERSHOCK_PUBLIC_API Newline = '\n';
        constexpr char HYPERSHOCK_PUBLIC_API Tab = '\t';
    }
    //====================================================================================================
    namespace Unicode
    {
        static constexpr HYPERSHOCK_PUBLIC_API char16 Null = CHAR('\0');
        static constexpr HYPERSHOCK_PUBLIC_API char16 Newline = CHAR('\n');
        static constexpr HYPERSHOCK_PUBLIC_API char16 Tab = CHAR('\t');
    }
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API String
    {
    public:
        String() noexcept;
        String(const String& other) noexcept;
        String(String&& other) noexcept;
        String(const char16* const str) noexcept;
        String(const char* const str) noexcept;
        String(TYPE_OF_NULLPTR) noexcept;
        String(int64 num) noexcept;
        String(uint64 num) noexcept;
        String(float num) noexcept;
        String(double num) noexcept;
        virtual ~String() noexcept = default;

    public:
        String& operator=(const String& other) noexcept;
        String& operator=(String&& other) noexcept;
        String& operator=(const char16* const str) noexcept;
        String& operator=(const char* const str) noexcept;
        String& operator=(TYPE_OF_NULLPTR) noexcept;
        String& operator=(int64 num) noexcept;
        String& operator=(uint64 num) noexcept;
        String& operator=(float num) noexcept;
        String& operator=(double num) noexcept;
        String& operator+=(const String& other) noexcept;
        String& operator+=(const char16* const str) noexcept;
        String& operator+=(const char* const str) noexcept;
        String& operator+=(TYPE_OF_NULLPTR) noexcept;
        String& operator+=(int64 num) noexcept;
        String& operator+=(uint64 num) noexcept;
        String& operator+=(float num) noexcept;
        String& operator+=(double num) noexcept;
        String operator+(const String& other) const noexcept;
        String operator+(const char16* const str) const noexcept;
        String operator+(const char* const str) const noexcept;
        String operator+(TYPE_OF_NULLPTR) const noexcept;
        String operator+(int64 num) const noexcept;
        String operator+(uint64 num) const noexcept;
        String operator+(float num) const noexcept;
        String operator+(double num) const noexcept;
        bool operator==(const String& other) const noexcept;
        bool operator==(const char16* const str) const noexcept;
        bool operator==(const char* const str) const noexcept;
        bool operator==(TYPE_OF_NULLPTR) const noexcept;
        char16* operator*() noexcept;
        const char16* const operator*() const noexcept;
        char16& operator[](size index) noexcept;
        const char16& operator[](size index) const noexcept;

    public:
        char16* Get() noexcept;
        const char16* const Get() const noexcept;
        char16& Get(size index) noexcept;
        const char16& Get(size index) const noexcept;
        bool Equals(const String& other) const noexcept;
        bool Equals(const char16* const str) const noexcept;
        bool Equals(const char* const str) const noexcept;
        bool Equals(TYPE_OF_NULLPTR) const noexcept;
        size Size() const noexcept;
        size Length() const noexcept;
        size Capacity() const noexcept;
        bool IsEmpty() const noexcept;
        void Empty() noexcept;
        char16& Front() noexcept;
        const char16& Front() const noexcept;
        char16& Back() noexcept;
        const char16& Back() const noexcept;

    private:
        std::vector<char16> m_Characters;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_STRING_HPP
//====================================================================================================