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
#include "Hypershock/Core/Time/DateTime.hpp"
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Platform.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    /*static*/
    const DateTime DateTime::Null = DateTime();
    //====================================================================================================
    /*static*/
    DateTime DateTime::Now() noexcept
    {
    #ifdef HYPERSHOCK_WINDOWS
        SYSTEMTIME time;
        GetLocalTime(&time);
        const DateTime inaccurateLocalTime(0, 0, time.wMilliseconds, time.wSecond, time.wMinute, time.wHour, time.wDay, time.wMonth, time.wYear);

        GetSystemTime(&time);
        const DateTime inaccurateUtcTime(0, 0, time.wMilliseconds, time.wSecond, time.wMinute, time.wHour, time.wDay, time.wMonth, time.wYear);

        const DateTime accurateUtcTime = UtcNow();
        const Timespan delta = inaccurateLocalTime - inaccurateUtcTime;

        return accurateUtcTime + delta; // Accurate local time
    #else
        NOT_IMPLEMENTED();
        return DateTime();
    #endif
    }
    //====================================================================================================
    /*static*/
    DateTime DateTime::UtcNow() noexcept
    {
    #ifdef HYPERSHOCK_WINDOWS
        FILETIME time = {};
        GetSystemTimePreciseAsFileTime(&time);

        constexpr uint8 interval = 100; // GetSystemTimePreciseAsFileTime accuracy is expressed as a count of 100 nanosecond intervals
        uint64 totalNanosecondsIntervals = time.dwHighDateTime;
        totalNanosecondsIntervals <<= 32;
        totalNanosecondsIntervals += time.dwLowDateTime;

        // Convert the total nanosecond intervals count into ticks measured in partial seconds
        const double ticks = (1.0 * totalNanosecondsIntervals / 1000000000.0) * interval;

        return DateTime(ticks);
    #else
        NOT_IMPLEMENTED();
        return DateTime();
    #endif
    }
    //====================================================================================================
    DateTime::DateTime(double ticks/* = 0.0f*/) noexcept : m_Ticks(ticks)
    {
    }
    //====================================================================================================
    DateTime::DateTime(int32 nanoseconds, int32 microseconds, int32 milliseconds, int32 seconds, int32 minutes, int32 hours, int32 days, int32 months, int32 years) noexcept
    {
        m_Ticks = nanoseconds * TICKS_PER_NANOSECOND +
                  microseconds * MICROSECONDS_PER_TICK +
                  milliseconds * TICKS_PER_MILLISECOND +
                  seconds * TICKS_PER_SECOND +
                  minutes * TICKS_PER_MINUTE +
                  hours * TICKS_PER_HOUR +
                  days * TICKS_PER_DAY +
                  years * 365.25 * TICKS_PER_DAY;

        const int32 daysPerMonth[] = {
                31,
                28,
                31,
                30,
                31,
                30,
                31,
                31,
                30,
                31,
                30,
                31
        };

        for (int32 i = 1; i <= months; i++)
        {
            m_Ticks += daysPerMonth[i] * TICKS_PER_DAY;
        }
    }
    //====================================================================================================
    DateTime& DateTime::operator=(const DateTime other) noexcept
    {
        m_Ticks = other.GetTicks();
        return *this;
    }
    //====================================================================================================
    bool DateTime::operator==(const DateTime other) const noexcept
    {
        return GetTicks() == other.GetTicks();
    }
    //====================================================================================================
    bool DateTime::operator<(const DateTime other) const noexcept
    {
        return GetTicks() < other.GetTicks();
    }
    //====================================================================================================
    bool DateTime::operator>(const DateTime other) const noexcept
    {
        return GetTicks() > other.GetTicks();
    }
    //====================================================================================================
    bool DateTime::operator<=(const DateTime other) const noexcept
    {
        return GetTicks() <= other.GetTicks();
    }
    //====================================================================================================
    bool DateTime::operator>=(const DateTime other) const noexcept
    {
        return GetTicks() >= other.GetTicks();
    }
    //====================================================================================================
    Timespan DateTime::operator-(const DateTime other) const noexcept
    {
        return Timespan(GetTicks() - other.GetTicks());
    }
    //====================================================================================================
    DateTime DateTime::operator+(const Timespan timespan) const noexcept
    {
        return DateTime(GetTicks() + timespan.GetTicks());
    }
    //====================================================================================================
    DateTime DateTime::operator-(const Timespan timespan) const noexcept
    {
        return DateTime(GetTicks() - timespan.GetTicks());
    }
    //====================================================================================================
    DateTime& DateTime::operator+=(const Timespan timespan) noexcept
    {
        m_Ticks += timespan.GetTicks();
        return *this;
    }
    //====================================================================================================
    DateTime& DateTime::operator-=(const Timespan timespan) noexcept
    {
        m_Ticks -= timespan.GetTicks();
        return *this;
    }
    //====================================================================================================
    double DateTime::GetTicks() const noexcept
    {
        return m_Ticks;
    }
    //====================================================================================================
    double DateTime::GetTotalYears() const noexcept
    {
        return m_Ticks * DAYS_PER_TICK / 365.25;
    }
    //====================================================================================================
    double DateTime::GetTotalMonths() const noexcept
    {
        return GetTotalYears() / 12.0;
    }
    //====================================================================================================
    double DateTime::GetTotalDays() const noexcept
    {
        return m_Ticks * DAYS_PER_TICK;
    };
    //====================================================================================================
    double DateTime::GetTotalHours() const noexcept
    {
        return m_Ticks * HOURS_PER_TICK;
    }
    //====================================================================================================
    double DateTime::GetTotalMinutes() const noexcept
    {
        return m_Ticks * MINUTES_PER_TICK;
    }
    //====================================================================================================
    double DateTime::GetTotalSeconds() const noexcept
    {
        return m_Ticks * SECONDS_PER_TICK;
    }
    //====================================================================================================
    double DateTime::GetTotalMilliseconds() const noexcept
    {
        return m_Ticks * MILLISECONDS_PER_TICK;
    }
    //====================================================================================================
    double DateTime::GetTotalMicroseconds() const noexcept
    {
        return m_Ticks * MICROSECONDS_PER_TICK;
    }
    //====================================================================================================
    double DateTime::GetTotalNanoseconds() const noexcept
    {
        return m_Ticks * NANOSECONDS_PER_TICK;
    }
    //====================================================================================================
    int32 DateTime::GetYear() const noexcept
    {
        return static_cast<int32>(GetTotalYears());
    }
    //====================================================================================================
    int32 DateTime::GetMonth() const noexcept
    {
        int32 dayInTheYear = SIGN(m_Ticks) * static_cast<int32>(GetTotalDays() - 0.25 * (GetYear() % 4));

        const int32 daysPerMonth[] = {
                31,
                28,
                31,
                30,
                31,
                30,
                31,
                31,
                30,
                31,
                30,
                31
        };

        for (int32 i = 0; i < 12; i++)
        {
            if (dayInTheYear <= daysPerMonth[i])
            {
                return i + 1;
            }

            dayInTheYear -= daysPerMonth[i];
        }

        return 0;
    }
    //====================================================================================================
    int32 DateTime::GetDay() const noexcept
    {
        int32 dayInTheYear = SIGN(m_Ticks) * static_cast<int32>(GetTotalDays() - 0.25 * (GetYear() % 4));

        const int32 daysPerMonth[] = {
                31,
                28,
                31,
                30,
                31,
                30,
                31,
                31,
                30,
                31,
                30,
                31
        };

        for (int days : daysPerMonth)
        {
            if (dayInTheYear <= days)
            {
                return dayInTheYear;
            }

            dayInTheYear -= days;
        }

        return dayInTheYear;
    }
    //====================================================================================================
    int32 DateTime::GetHours() const noexcept
    {
        const double totalDays = GetTotalDays();
        return SIGN(m_Ticks) * static_cast<int32>(DECIMAL(totalDays) * 24);
    }
    //====================================================================================================
    int32 DateTime::GetHours12() const noexcept
    {
        return GetHours() / 2;
    }
    //====================================================================================================
    int32 DateTime::GetMinutes() const noexcept
    {
        return SIGN(m_Ticks) * static_cast<int32>(DECIMAL(GetTotalHours()) * 60);
    }
    //====================================================================================================
    int32 DateTime::GetSeconds() const noexcept
    {
        return SIGN(m_Ticks) * static_cast<int32>(DECIMAL(GetTotalMinutes()) * 60);
    }
    //====================================================================================================
    int32 DateTime::GetMilliseconds() const noexcept
    {
        return SIGN(m_Ticks) * static_cast<int32>(DECIMAL(GetTotalSeconds()) * 100);
    }
    //====================================================================================================
    int32 DateTime::GetMicroseconds() const noexcept
    {
        return SIGN(m_Ticks) * static_cast<int32>(DECIMAL(GetTotalMilliseconds()) * 100);
    }
    //====================================================================================================
    int32 DateTime::GetNanoseconds() const noexcept
    {
        return SIGN(m_Ticks) * static_cast<int32>(DECIMAL(GetTotalMicroseconds()) * 100);
    }
    //====================================================================================================
}
//====================================================================================================