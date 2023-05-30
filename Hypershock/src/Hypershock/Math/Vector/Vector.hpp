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
#ifndef HYPERSHOCK_VECTOR_HPP
#define HYPERSHOCK_VECTOR_HPP
//====================================================================================================
#include "Hypershock/Math/Vector/Vector2.hpp"
#include "Hypershock/Math/Vector/Vector3.hpp"
#include "Hypershock/Math/Vector/Vector4.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    namespace Vector
    {
        //====================================================================================================
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Null = Vector4{0.0f, 0.0f, 0.0f, 0.0f};
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Up = Vector4{0.0f, 0.0f, 1.0f, 0.0f};
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Down = Vector4{0.0f, 0.0f, -1.0f, 0.0f};
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Front = Vector4{1.0f, 0.0f, 0.0f, 0.0f};
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Back = Vector4{-1.0f, 0.0f, 0.0f, 0.0f};
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Left = Vector4{0.0f, 1.0f, 0.0f, 0.0f};
        static constexpr HYPERSHOCK_PUBLIC_API Vector4 Right = Vector4{0.0f, -1.0f, 0.0f, 0.0f};
        //====================================================================================================
        /**
         *
         * @tparam T
         * @param vec1
         * @param vec2
         * @return
         */
        template<typename T>
        float HYPERSHOCK_PUBLIC_API Dot(const T& vec1, const T& vec2) noexcept;
        /**
         *
         * @param vec
         * @return
         */
        Vector2 HYPERSHOCK_PUBLIC_API CrossProduct(const Vector2& vec) noexcept;
        /**
         *
         * @param vec1
         * @param vec2
         * @return
         */
        Vector3 HYPERSHOCK_PUBLIC_API CrossProduct(const Vector3& vec1, const Vector3& vec2) noexcept;
        /**
         *
         * @param vec1
         * @param vec2
         * @param vec3
         * @return
         */
        Vector4 HYPERSHOCK_PUBLIC_API CrossProduct(const Vector4& vec1, const Vector4& vec2, const Vector4& vec3) noexcept;
        /**
         *
         * @tparam T
         * @param vec
         * @return
         */
        template<typename T>
        float HYPERSHOCK_PUBLIC_API Length(const T& vec) noexcept;
        /**
         *
         * @tparam T
         * @param vec1
         * @param vec2
         * @return
         */
        template<typename T>
        float HYPERSHOCK_PUBLIC_API Distance(const T& vec1, const T& vec2) noexcept;
        /**
         *
         * @tparam T
         * @param vec
         * @return
         */
        template<typename T>
        T HYPERSHOCK_PUBLIC_API Unit(const T& vec) noexcept;
        //====================================================================================================
    }
    //====================================================================================================
    /**
     *
     * @tparam T
     * @param vec1
     * @param vec2
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator+(const T& vec1, const T& vec2) noexcept;
    /**
     *
     * @tparam T
     * @param vec1
     * @param vec2
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator-(const T& vec1, const T& vec2) noexcept;
    /**
     *
     * @tparam T
     * @param vec1
     * @param vec2
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator*(const T& vec1, const T& vec2) noexcept;
    /**
     *
     * @tparam T
     * @param vec1
     * @param vec2
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator/(const T& vec1, const T& vec2) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator+(const T& vec, int32 scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator+(int32 scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator+(const T& vec, float scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator+(float scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator-(const T& vec, int32 scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator-(int32 scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator-(const T& vec, float scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator-(float scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator*(const T& vec, int32 scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator*(int32 scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator*(const T& vec, float scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator*(float scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator/(const T& vec, int32 scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator/(int32 scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @param scalar
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator/(const T& vec, float scalar) noexcept;
    /**
     *
     * @tparam T
     * @param scalar
     * @param vec
     * @return
     */
    template<typename T>
    T HYPERSHOCK_PUBLIC_API operator/(float scalar, const T& vec) noexcept;
    /**
     *
     * @tparam T
     * @param vec
     * @return
     */
    template<typename T>
    float HYPERSHOCK_PUBLIC_API operator*(const T& vec) noexcept;
    //====================================================================================================
}
//====================================================================================================
#endif //HYPERSHOCK_VECTOR_HPP
//====================================================================================================