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
#include "String.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    String::String() noexcept
    {
    }
    //====================================================================================================
    String::String(const String& other) noexcept : m_Characters(other.m_Characters)
    {
    }
    //====================================================================================================
    String::String(String&& other) noexcept : m_Characters(static_cast<std::vector<char16>&&>(other.m_Characters))
    {
        // TODO: make move a bit more std like and less always casting etc...
    }
    //====================================================================================================
    String::String(const char16* const str) noexcept
    {
        if (str == nullptr)
        {
            return;
        }

        for (size i = 0; str[i] != Unicode::Null; i++)
        {
            m_Characters.emplace_back(str[i]);
        }
    }
    //====================================================================================================
    String::String(const char* const str) noexcept
    {
        if (str == nullptr)
        {
            return;
        }

        for (size i = 0; str[i] != ASCII::Null; i++)
        {
            m_Characters.emplace_back(Unicode::Null);
            m_Characters[i] &= str[i];
        }
    }
    //====================================================================================================
    String::String(TYPE_OF_NULLPTR) noexcept
    {
    }
    //====================================================================================================
    String::String(int64 num) noexcept
    {
        if (num == 0)
        {
            m_Characters.emplace_back(CHAR('0'));
            return;
        }

        const int32 sign = SIGN(num);
        num *= sign;

        while (num != 0)
        {
            const uint8 part = static_cast<uint8>(num % 10);
            num /= 10;

            char16 c = CHAR('0') + part;
            m_Characters.emplace(m_Characters.cbegin(), c);
        }

        while(!m_Characters.empty() && m_Characters.front() == CHAR('0'))
        {
            std::remove(m_Characters.begin(), m_Characters.begin() + 1, CHAR('0'));
        }

        if (sign < 0)
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('-'));
        }
    }
    //====================================================================================================
    String::String(uint64 num) noexcept
    {
        if (num == 0)
        {
            m_Characters.emplace_back(CHAR('0'));
            return;
        }

        while (num != 0)
        {
            const uint8 part = static_cast<uint8>(num % 10);
            num /= 10;

            const char16 c = CHAR('0') + part;
            m_Characters.emplace(m_Characters.cbegin(), c);
        }

        while(!m_Characters.empty() && m_Characters.front() == CHAR('0'))
        {
            std::remove(m_Characters.begin(), m_Characters.begin() + 1, CHAR('0'));
        }
    }
    //====================================================================================================
    String::String(float num) noexcept
    {
        if (num == 0.0f)
        {
            m_Characters.emplace_back(CHAR('0'));
            m_Characters.emplace_back(CHAR('.'));
            m_Characters.emplace_back(CHAR('0'));
            return;
        }

        const int32 sign = SIGN(num);
        num *= sign;

        uint64 whole = static_cast<uint64>(num);
        uint64 decimal = static_cast<uint64>(DECIMAL(num) * 1000000);

        if (decimal != 0)
        {
            while (decimal != 0)
            {
                const uint8 part = static_cast<uint8>(decimal % 10);
                decimal /= 10;

                const char16 c = CHAR('0') + part;
                m_Characters.emplace(m_Characters.cbegin(), c);
            }

            while (!m_Characters.empty() && m_Characters.back() == CHAR('0'))
            {
                std::remove(m_Characters.end() - 1, m_Characters.end(), CHAR('0'));
            }
        }
        else
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('0'));
        }

        m_Characters.emplace(m_Characters.cbegin(), CHAR('.'));

        if (whole != 0)
        {
            while (whole != 0)
            {
                const uint8 part = static_cast<uint8>(whole % 10);
                whole /= 10;

                const char16 c = CHAR('0') + part;
                m_Characters.emplace(m_Characters.cbegin(), c);
            }

            while (!m_Characters.empty() && m_Characters.back() == CHAR('0'))
            {
                std::remove(m_Characters.end() - 1, m_Characters.end(), CHAR('0'));
            }
        }
        else
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('0'));
        }

        if (sign < 0)
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('-'));
        }
    }
    //====================================================================================================
    String::String(double num) noexcept
    {
        if (num == 0.0)
        {
            m_Characters.emplace_back(CHAR('0'));
            m_Characters.emplace_back(CHAR('.'));
            m_Characters.emplace_back(CHAR('0'));
            return;
        }

        const int32 sign = SIGN(num);
        num *= sign;

        uint64 whole = static_cast<uint64>(num);
        uint64 decimal = static_cast<uint64>(DECIMAL(num) * 1000000000000);

        if (decimal != 0)
        {
            while (decimal != 0)
            {
                const uint8 part = static_cast<uint8>(decimal % 10);
                decimal /= 10;

                const char16 c = CHAR('0') + part;
                m_Characters.emplace(m_Characters.cbegin(), c);
            }

            while (!m_Characters.empty() && m_Characters.back() == CHAR('0'))
            {
                std::remove(m_Characters.end() - 1, m_Characters.end(), CHAR('0'));
            }
        }
        else
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('0'));
        }

        m_Characters.emplace(m_Characters.cbegin(), CHAR('.'));

        if (whole != 0)
        {
            while (whole != 0)
            {
                const uint8 part = static_cast<uint8>(whole % 10);
                whole /= 10;

                const char16 c = CHAR('0') + part;
                m_Characters.emplace(m_Characters.cbegin(), c);
            }

            while (!m_Characters.empty() && m_Characters.back() == CHAR('0'))
            {
                std::remove(m_Characters.end() - 1, m_Characters.end(), CHAR('0'));
            }
        }
        else
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('0'));
        }

        if (sign < 0)
        {
            m_Characters.emplace(m_Characters.cbegin(), CHAR('-'));
        }
    }
    //====================================================================================================
    String& String::operator=(const String& other) noexcept
    {
        m_Characters = other.m_Characters;
        return *this;
    }
    //====================================================================================================
    String& String::operator=(String&& other) noexcept
    {
        m_Characters = static_cast<std::vector<char16>&&>(other.m_Characters);
        return *this;
    }
    //====================================================================================================
    String& String::operator=(const char16* const str) noexcept
    {
        m_Characters.resize(0);

        if (str == nullptr)
        {
            return *this;
        }

        for (size i = 0; str[i] != Unicode::Null; i++)
        {
            m_Characters.emplace_back(str[i]);
        }

        return *this;
    }
    //====================================================================================================
    String& String::operator=(const char* const str) noexcept
    {
        m_Characters.resize(0);

        if (str == nullptr)
        {
            return *this;
        }

        for (size i = 0; str[i] != ASCII::Null; i++)
        {
            m_Characters.emplace_back(Unicode::Null);
            m_Characters[i] &= str[i];
        }

        return *this;
    }
    //====================================================================================================
    String& String::operator=(TYPE_OF_NULLPTR) noexcept
    {
        m_Characters.resize(0);
        return *this;
    }
    //====================================================================================================
    String& String::operator=(int64 num) noexcept
    {
        *this = String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator=(uint64 num) noexcept
    {
        *this = String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator=(float num) noexcept
    {
        *this = String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator=(double num) noexcept
    {
        *this = String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator+=(const String& other) noexcept
    {
        for (const char16& c : other.m_Characters)
        {
            if (c == Unicode::Null)
            {
                break;
            }

            m_Characters.emplace_back(c);
        }

        return *this;
    }
    //====================================================================================================
    String& String::operator+=(const char16* const str) noexcept
    {
        if (str == nullptr)
        {
            return *this;
        }

        for (size i = 0; str[i] != Unicode::Null; i++)
        {
            m_Characters.emplace_back(str[i]);
        }

        return *this;
    }
    //====================================================================================================
    String& String::operator+=(const char* const str) noexcept
    {
        if (str == nullptr)
        {
            return *this;
        }

        for (size i = 0; str[i] != ASCII::Null; i++)
        {
            m_Characters.emplace_back(Unicode::Null);
            m_Characters[i] &= str[i];
        }

        return *this;
    }
    //====================================================================================================
    String& String::operator+=(TYPE_OF_NULLPTR) noexcept
    {
        return *this;
    }
    //====================================================================================================
    String& String::operator+=(int64 num) noexcept
    {
        *this += String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator+=(uint64 num) noexcept
    {
        *this += String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator+=(float num) noexcept
    {
        *this += String(num);
        return *this;
    }
    //====================================================================================================
    String& String::operator+=(double num) noexcept
    {
        *this += String(num);
        return *this;
    }
    //====================================================================================================
    String String::operator+(const String& other) const noexcept
    {
        String ret = *this;
        ret += other;
        return ret;
    }
    //====================================================================================================
    String String::operator+(const char16* const str) const noexcept
    {
        if (str == nullptr)
        {
            return *this;
        }

        String ret = *this;
        ret += str;
        return ret;
    }
    //====================================================================================================
    String String::operator+(const char* const str) const noexcept
    {
        if (str == nullptr)
        {
            return *this;
        }

        String ret = *this;
        ret += str;
        return ret;
    }
    //====================================================================================================
    String String::operator+(TYPE_OF_NULLPTR) const noexcept
    {
        return *this;
    }
    //====================================================================================================
    String String::operator+(int64 num) const noexcept
    {
        return *this + String(num);
    }
    //====================================================================================================
    String String::operator+(uint64 num) const noexcept
    {
        return *this + String(num);
    }
    //====================================================================================================
    String String::operator+(float num) const noexcept
    {
        return *this + String(num);
    }
    //====================================================================================================
    String String::operator+(double num) const noexcept
    {
        return *this + String(num);
    }
    //====================================================================================================
    bool String::operator==(const String& other) const noexcept
    {
        return Equals(other);
    }
    //====================================================================================================
    bool String::operator==(const char16* const str) const noexcept
    {
        return Equals(str);
    }
    //====================================================================================================
    bool String::operator==(const char* const str) const noexcept
    {
        return Equals(str);
    }
    //====================================================================================================
    bool String::operator==(TYPE_OF_NULLPTR) const noexcept
    {
        return Equals(nullptr);
    }
    //====================================================================================================
    char16* String::operator*() noexcept
    {
        CHECK(!m_Characters.empty())
        return m_Characters.data();
    }
    //====================================================================================================
    const char16* const String::operator*() const noexcept
    {
        CHECK(!m_Characters.empty())
        return m_Characters.data();
    }
    //====================================================================================================
    char16& String::operator[](size index) noexcept
    {
        CHECK(index >= 0 && index < m_Characters.size());
        return m_Characters[index];
    }
    //====================================================================================================
    const char16& String::operator[](size index) const noexcept
    {
        CHECK(index >= 0 && index < m_Characters.size());
        return m_Characters[index];
    }
    //====================================================================================================
    char16* String::Get() noexcept
    {
        if (m_Characters.empty())
        {
            return nullptr;
        }

        return m_Characters.data();
    }
    //====================================================================================================
    const char16* const String::Get() const noexcept
    {
        if (m_Characters.empty())
        {
            return nullptr;
        }

        return m_Characters.data();
    }
    //====================================================================================================
    char16& String::Get(size index) noexcept
    {
        CHECK(index >= 0 && index < m_Characters.size());
        return m_Characters[index];;
    }
    //====================================================================================================
    const char16& String::Get(size index) const noexcept
    {
        CHECK(index >= 0 && index < m_Characters.size());
        return m_Characters[index];
    }
    //====================================================================================================
    bool String::Equals(const String& other) const noexcept
    {
        if (Length() != other.Length())
        {
            return false;
        }

        for (size i = 0; i < Length(); i++)
        {
            if (m_Characters[i] != other[i])
            {
                return false;
            }
        }

        return true;
    }
    //====================================================================================================
    bool String::Equals(const char16* const str) const noexcept
    {
        String temp(str);
        return Equals(temp);
    }
    //====================================================================================================
    bool String::Equals(const char* const str) const noexcept
    {
        String temp(str);
        return Equals(temp);
    }
    //====================================================================================================
    bool String::Equals(TYPE_OF_NULLPTR) const noexcept
    {
        return m_Characters.empty();
    }
    //====================================================================================================
    size String::Size() const noexcept
    {
        return m_Characters.size();
    }
    //====================================================================================================
    size String::Length() const noexcept
    {
        return m_Characters.size();
    }
    //====================================================================================================
    size String::Capacity() const noexcept
    {
        return m_Characters.capacity();
    }
    //====================================================================================================
    bool String::IsEmpty() const noexcept
    {
        return m_Characters.empty();
    }
    //====================================================================================================
    void String::Empty() noexcept
    {
        m_Characters.resize(0);
    }
    //====================================================================================================
    char16& String::Front() noexcept
    {
        CHECK(!m_Characters.empty());
        return m_Characters.front();
    }
    //====================================================================================================
    const char16& String::Front() const noexcept
    {
        CHECK(!m_Characters.empty());
        return m_Characters.front();
    }
    //====================================================================================================
    char16& String::Back() noexcept
    {
        CHECK(!m_Characters.empty());
        return m_Characters.back();
    }
    //====================================================================================================
    const char16& String::Back() const noexcept
    {
        CHECK(!m_Characters.empty());
        return m_Characters.back();
    }
    //====================================================================================================
}
//====================================================================================================