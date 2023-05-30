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
#ifndef HYPERSHOCK_TIMESPAN_HPP
#define HYPERSHOCK_TIMESPAN_HPP
//====================================================================================================
#include "Hypershock/Core/Core.hpp"
#include "Hypershock/Core/Types.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    class Timespan
    {
    public:
        //====================================================================================================
        /**
         *
         * @param ticks
         */
        explicit Timespan(double ticks = 0.0f) noexcept;
        /**
         *
         * @param nanoseconds
         * @param milliseconds
         * @param seconds
         * @param minutes
         * @param hours
         * @param days
         * @param months
         * @param years
         */
        explicit Timespan(int32 nanoseconds, int32 microseconds, int32 milliseconds, int32 seconds, int32 minutes, int32 hours, int32 days, int32 months, int32 years) noexcept;
        /**
         *
         */
        virtual ~Timespan() noexcept = default;
        //====================================================================================================
        // TODO: move all possible operators outside of the class
        /**
         *
         * @param other
         * @return
         */
        Timespan& operator=(const Timespan other) noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator==(const Timespan other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator<(const Timespan other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator>(const Timespan other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator<=(const Timespan other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        bool operator>=(const Timespan other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        Timespan operator+(const Timespan other) const noexcept;
        /**
         *
         * @param other
         * @return
         */
        Timespan operator-(const Timespan other) const noexcept;
        /**
         *
         * @param other
         */
        Timespan operator+=(const Timespan other) noexcept;
        /**
         *
         * @param other
         */
        Timespan operator-=(const Timespan other) noexcept;
        /**
         *
         * @param factor
         * @return
         */
        Timespan operator*(const double factor) const noexcept;
        /**
         *
         * @param factor
         * @return
         */
        Timespan operator/(const double factor) const noexcept;
        /**
         *
         * @return
         */
        Timespan operator-(int) const noexcept;
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
        double GetYears() const noexcept;
        /**
         *
         * @return
         */
        double GetMonths() const noexcept;
        /**
         *
         * @return
         */
        double GetDays() const noexcept;
        /**
         *
         * @return
         */
        double GetHours() const noexcept;
        /**
         *
         * @return
         */
        double GetMinutes() const noexcept;
        /**
         *
         * @return
         */
        double GetSeconds() const noexcept;
        /**
         *
         * @return
         */
        double GetMilliseconds() const noexcept;
        /**
         *
         * @return
         */
        double GetMicroseconds() const noexcept;
        /**
         *
         * @return
         */
        double GetNanoseconds() const noexcept;

    private:
        double m_Ticks;
    };
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_TIMESPAN_HPP
//====================================================================================================