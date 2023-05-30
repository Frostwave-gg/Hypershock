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
#include "Hypershock/Core/Time/Timespan.hpp"
#include "Hypershock/Core/Time/DateTime.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    Timespan::Timespan(double ticks/* = 0.0f*/) noexcept : m_Ticks(ticks)
    {

    }
    //====================================================================================================
    Timespan::Timespan(int32 nanoseconds, int32 microseconds, int32 milliseconds, int32 seconds, int32 minutes,
                       int32 hours, int32 days, int32 months, int32 years) noexcept
    {
        m_Ticks = nanoseconds * DateTime::TICKS_PER_NANOSECOND +
                  microseconds * DateTime::MICROSECONDS_PER_TICK +
                  milliseconds * DateTime::TICKS_PER_MILLISECOND +
                  seconds * DateTime::TICKS_PER_SECOND +
                  minutes * DateTime::TICKS_PER_MINUTE +
                  hours * DateTime::TICKS_PER_HOUR +
                  days * DateTime::TICKS_PER_DAY +
                  years * 365.25 * DateTime::TICKS_PER_DAY;

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
            m_Ticks += daysPerMonth[i] * DateTime::TICKS_PER_DAY;
        }
    }
    //====================================================================================================
    Timespan& Timespan::operator=(const Timespan other) noexcept
    {
        m_Ticks = other.GetTicks();
        return *this;
    }
    //====================================================================================================
    bool Timespan::operator==(const Timespan other) const noexcept
    {
        return GetTicks() == other.GetTicks();
    }
    //====================================================================================================
    bool Timespan::operator<(const Timespan other) const noexcept
    {
        return GetTicks() < other.GetTicks(); // TODO: compare absolute values
    }
    //====================================================================================================
    bool Timespan::operator>(const Timespan other) const noexcept
    {
        return GetTicks() > other.GetTicks(); // TODO: compare absolute values
    }
    //====================================================================================================
    bool Timespan::operator<=(const Timespan other) const noexcept
    {
        return GetTicks() <= other.GetTicks(); // TODO: compare absolute values
    }
    //====================================================================================================
    bool Timespan::operator>=(const Timespan other) const noexcept
    {
        return GetTicks() >= other.GetTicks(); // TODO: compare absolute values
    }
    //====================================================================================================
    Timespan Timespan::operator+(const Timespan other) const noexcept
    {
        return Timespan(GetTicks() + other.GetTicks());
    }
    //====================================================================================================
    Timespan Timespan::operator-(const Timespan other) const noexcept
    {
        return Timespan(GetTicks() - other.GetTicks());
    }
    //====================================================================================================
    Timespan Timespan::operator+=(const Timespan other) noexcept
    {
        m_Ticks += other.GetTicks();
        return *this;
    }
    //====================================================================================================
    Timespan Timespan::operator-=(const Timespan other) noexcept
    {
        m_Ticks -= other.GetTicks();
        return *this;
    }
    //====================================================================================================
    Timespan Timespan::operator*(const double factor) const noexcept
    {
        return Timespan(factor * GetTicks());
    }
    //====================================================================================================
    Timespan Timespan::operator/(const double factor) const noexcept
    {
        return Timespan(GetTicks() / factor);
    }
    //====================================================================================================
    Timespan Timespan::operator-(int) const noexcept
    {
        return (*this) * -1.0;
    }
    //====================================================================================================
    double Timespan::GetTicks() const noexcept
    {
        return m_Ticks;
    }
    //====================================================================================================
    double Timespan::GetYears() const noexcept
    {
        return m_Ticks * DateTime::DAYS_PER_TICK / 365.25;
    }
    //====================================================================================================
    double Timespan::GetMonths() const noexcept
    {
        return GetYears() / 12.0;
    }
    //====================================================================================================
    double Timespan::GetDays() const noexcept
    {
        return m_Ticks * DateTime::DAYS_PER_TICK;
    }
    //====================================================================================================
    double Timespan::GetHours() const noexcept
    {
        return m_Ticks * DateTime::HOURS_PER_TICK;
    }
    //====================================================================================================
    double Timespan::GetMinutes() const noexcept
    {
        return m_Ticks * DateTime::MINUTES_PER_TICK;
    }
    //====================================================================================================
    double Timespan::GetSeconds() const noexcept
    {
        return m_Ticks * DateTime::SECONDS_PER_TICK;
    }
    //====================================================================================================
    double Timespan::GetMilliseconds() const noexcept
    {
        return m_Ticks * DateTime::MILLISECONDS_PER_TICK;
    }
    //====================================================================================================
    double Timespan::GetMicroseconds() const noexcept
    {
        return m_Ticks * DateTime::MICROSECONDS_PER_TICK;
    }
    //====================================================================================================
    double Timespan::GetNanoseconds() const noexcept
    {
        return m_Ticks * DateTime::NANOSECONDS_PER_TICK;
    }
    //====================================================================================================
}
//====================================================================================================