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
#ifndef HYPERSHOCK_DATETIME_HPP
#define HYPERSHOCK_DATETIME_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
#include "Hypershock/Core/Time/Timespan.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    class HYPERSHOCK_PUBLIC_API DateTime
    {
    public:
        //====================================================================================================
        static const DateTime Null;

        static constexpr double TICKS_PER_DAY = 86400.0;
        static constexpr double TICKS_PER_HOUR = 3600.0;
        static constexpr double TICKS_PER_MINUTE = 60.0;
        static constexpr double TICKS_PER_SECOND = 1.0;
        static constexpr double TICKS_PER_MILLISECOND = 1.0 / 1000.0;
        static constexpr double TICKS_PER_MICROSECOND = 1.0 / 1000000.0;
        static constexpr double TICKS_PER_NANOSECOND = 1.0 / 1000000000.0;

        static constexpr double DAYS_PER_TICK = 1.0 / TICKS_PER_DAY;
        static constexpr double HOURS_PER_TICK = 1.0 / TICKS_PER_HOUR;
        static constexpr double MINUTES_PER_TICK = 1.0 / TICKS_PER_MINUTE;
        static constexpr double SECONDS_PER_TICK = 1.0 / TICKS_PER_SECOND;
        static constexpr double MILLISECONDS_PER_TICK = 1.0 / TICKS_PER_MILLISECOND;
        static constexpr double MICROSECONDS_PER_TICK = 1.0 / TICKS_PER_MICROSECOND;
        static constexpr double NANOSECONDS_PER_TICK = 1.0 / TICKS_PER_NANOSECOND;
        //====================================================================================================
    public:
        //====================================================================================================
        static DateTime Now() noexcept;
        static DateTime UtcNow() noexcept;
        //====================================================================================================
    public:
        //====================================================================================================
        /**
         *
         * @param ticks
         */
        explicit DateTime(double ticks = 0.0f) noexcept;
        /**
         *
         * @param seconds
         * @param minutes
         * @param hours
         * @param days
         * @param months
         * @param years
         */
        explicit DateTime(int32 nanoseconds, int32 microseconds, int32 milliseconds, int32 seconds, int32 minutes, int32 hours, int32 days, int32 months, int32 years) noexcept;
        /**
         *
         */
        virtual ~DateTime() noexcept = default;
        //====================================================================================================
        /**
         *
         * @param other
         */
        DateTime& operator=(const DateTime other) noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator==(const DateTime other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator<(const DateTime other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator>(const DateTime other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator<=(const DateTime other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator>=(const DateTime other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        Timespan operator-(const DateTime other) const noexcept;
        /**
         *
         * @param timespan
         * @return
         */
        DateTime operator+(const Timespan timespan) const noexcept;
        /**
         *
         * @param timespan
         * @return
         */
        DateTime operator-(const Timespan timespan) const noexcept;
        /**
         *
         * @param timespan
         * @return
         */
        DateTime& operator+=(const Timespan timespan) noexcept;
        /**
         *
         * @param timespan
         * @return
         */
        DateTime& operator-=(const Timespan timespan) noexcept;
        //====================================================================================================
        /**
         *
         * @return
         */
        double GetTicks() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalYears() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalMonths() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalDays() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalHours() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalMinutes() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalSeconds() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalMilliseconds() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalMicroseconds() const noexcept;
        /**
         *
         * @return
         */
        double GetTotalNanoseconds() const noexcept;
        /**
         *
         * @return
         */
        int32 GetYear() const noexcept;
        /**
         *
         * @return
         */
        int32 GetMonth() const noexcept;
        /**
         *
         * @return
         */
        int32 GetDay() const noexcept;
        /**
         *
         * @return
         */
        int32 GetHours() const noexcept;
        /**
         *
         * @return
         */
        int32 GetHours12() const noexcept;
        /**
         *
         * @return
         */
        int32 GetMinutes() const noexcept;
        /**
         *
         * @return
         */
        int32 GetSeconds() const noexcept;
        /**
         *
         * @return
         */
        int32 GetMilliseconds() const noexcept;
        /**
         *
         * @return
         */
        int32 GetMicroseconds() const noexcept;
        /**
         *
         * @return
         */
        int32 GetNanoseconds() const noexcept;

    private:
        double m_Ticks = 0.0f; // = seconds (delta from 0/0/0000)
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_DATETIME_HPP
//====================================================================================================