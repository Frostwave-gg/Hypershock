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
#include "Vector.hpp"
//====================================================================================================
#include <cmath>
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    namespace Vector
    {
        //====================================================================================================
        template<>
        float Dot<Vector2>(const Vector2& vec1, const Vector2& vec2) noexcept
        {
            return vec1.X * vec2.X + vec1.Y * vec2.Y;
        }
        //====================================================================================================
        template<>
        float Dot<Vector3>(const Vector3& vec1, const Vector3& vec2) noexcept
        {
            return vec1.X * vec2.X + vec1.Y * vec2.Y + vec1.Z * vec2.Z;
        }
        //====================================================================================================
        template<>
        float Dot<Vector4>(const Vector4& vec1, const Vector4& vec2) noexcept
        {
            return vec1.X * vec2.X + vec1.Y * vec2.Y + vec1.Z * vec2.Z + vec1.W * vec2.W;
        }
        //====================================================================================================
        Vector2 CrossProduct(const Vector2& vec) noexcept
        {
            return Vector2{vec.Y, -vec.X};
        }
        //====================================================================================================
        Vector3 CrossProduct(const Vector3& vec1, const Vector3& vec2) noexcept
        {
            return Vector3{vec1.Y * vec2.Z - vec1.Z * vec2.Y, -(vec1.X * vec2.Z - vec1.Z * vec2.X), vec1.X * vec2.Y - vec1.Y * vec2.X};
        }
        //====================================================================================================
        Vector4 CrossProduct(const Vector4& vec1, const Vector4& vec2, const Vector4& vec3) noexcept
        {
            return Vector4{vec1.Y * (vec2.Z * vec3.W - vec2.W * vec3.Z) - vec1.Z * (vec2.Y * vec3.W - vec2.W * vec3.Y) + vec1.W * (vec2.Y * vec3.Z - vec2.Z * vec3.Y),
                           -(vec1.X * (vec2.Z * vec3.W - vec2.W * vec3.Z) - vec1.Z * (vec2.X * vec3.W - vec2.X * vec3.W) + vec1.W * (vec2.X * vec3.Z - vec2.Z * vec3.X)),
                           vec1.X * (vec2.Y * vec3.W - vec2.W * vec3.Y) - vec1.Y * (vec2.X * vec3.W - vec2.W * vec3.X) + vec1.W * (vec2.X * vec3.Y - vec2.Y * vec3.X),
                           -(vec1.X * (vec2.Y * vec3.Z - vec2.Z * vec3.Y) - vec1.Y * (vec2.X * vec3.Z - vec2.X * vec3.Z) + vec1.Z * (vec2.X * vec3.Y - vec2.Y * vec3.X))};
        }
        //====================================================================================================
        template<>
        float Length<Vector2>(const Vector2& vec) noexcept
        {
            return sqrt(vec.X * vec.X + vec.Y * vec.Y);
        }
        //====================================================================================================
        template<>
        float Length<Vector3>(const Vector3& vec) noexcept
        {
            return sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z);
        }
        //====================================================================================================
        template<>
        float Length<Vector4>(const Vector4& vec) noexcept
        {
            return sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z + vec.W * vec.W);
        }
        //====================================================================================================
        template<>
        float Distance<Vector2>(const Vector2& vec1, const Vector2& vec2) noexcept
        {
            return Length(Vector2{vec2.X - vec1.X, vec2.Y - vec1.Y});
        }
        //====================================================================================================
        template<>
        float Distance<Vector3>(const Vector3& vec1, const Vector3& vec2) noexcept
        {
            return Length(Vector3{vec2.X - vec1.X, vec2.Y - vec1.Y, vec2.Z - vec1.Z});
        }
        //====================================================================================================
        template<>
        float Distance<Vector4>(const Vector4& vec1, const Vector4& vec2) noexcept
        {
            return Length(Vector4{vec2.X - vec1.X, vec2.Y - vec1.Y, vec2.Z - vec1.Z, vec2.W - vec1.W});
        }
        //====================================================================================================
        template<>
        Vector2 Unit<Vector2>(const Vector2& vec) noexcept
        {
            float length = Length(vec);
            return Vector2{vec.X / length, vec.Y / length};
        }
        //====================================================================================================
        template<>
        Vector3 Unit<Vector3>(const Vector3& vec) noexcept
        {
            float length = Length(vec);
            return Vector3{vec.X / length, vec.Y / length, vec.Z / length};
        }
        //====================================================================================================
        template<>
        Vector4 Unit<Vector4>(const Vector4& vec) noexcept
        {
            float length = Length(vec);
            return Vector4{vec.X / length, vec.Y / length, vec.Z / length, vec.W / length};
        }
        //====================================================================================================
    }
    //====================================================================================================
    template<>
    Vector2 operator+<Vector2>(const Vector2& vec1, const Vector2& vec2) noexcept
    {
        return Vector2{vec1.X + vec2.X, vec1.Y + vec2.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator+<Vector3>(const Vector3& vec1, const Vector3& vec2) noexcept
    {
        return Vector3{vec1.X + vec2.X, vec1.Y + vec2.Y, vec1.Z + vec2.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator+<Vector4>(const Vector4& vec1, const Vector4& vec2) noexcept
    {
        return Vector4{vec1.X + vec2.X, vec1.Y + vec2.Y, vec1.Z + vec2.Z, vec1.W + vec2.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator-<Vector2>(const Vector2& vec1, const Vector2& vec2) noexcept
    {
        return Vector2{vec1.X - vec2.X, vec1.Y - vec2.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator-<Vector3>(const Vector3& vec1, const Vector3& vec2) noexcept
    {
        return Vector3{vec1.X - vec2.X, vec1.Y - vec2.Y, vec1.Z - vec2.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator-<Vector4>(const Vector4& vec1, const Vector4& vec2) noexcept
    {
        return Vector4{vec1.X - vec2.X, vec1.Y - vec2.Y, vec1.Z - vec2.Z, vec1.W - vec2.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator*<Vector2>(const Vector2& vec1, const Vector2& vec2) noexcept
    {
        return Vector2{vec1.X * vec2.X, vec1.Y * vec2.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator*<Vector3>(const Vector3& vec1, const Vector3& vec2) noexcept
    {
        return Vector3{vec1.X * vec2.X, vec1.Y * vec2.Y, vec1.Z * vec2.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator*<Vector4>(const Vector4& vec1, const Vector4& vec2) noexcept
    {
        return Vector4{vec1.X * vec2.X, vec1.Y * vec2.Y, vec1.Z * vec2.Z, vec1.W * vec2.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator/<Vector2>(const Vector2& vec1, const Vector2& vec2) noexcept
    {
        return Vector2{vec1.X / vec2.X, vec1.Y / vec2.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator/<Vector3>(const Vector3& vec1, const Vector3& vec2) noexcept
    {
        return Vector3{vec1.X / vec2.X, vec1.Y / vec2.Y, vec1.Z / vec2.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator/<Vector4>(const Vector4& vec1, const Vector4& vec2) noexcept
    {
        return Vector4{vec1.X / vec2.X, vec1.Y / vec2.Y, vec1.Z / vec2.Z, vec1.W / vec2.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator+<Vector2>(const Vector2& vec, int32 scalar) noexcept
    {
        return Vector2{vec.X + scalar, vec.Y + scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator+<Vector3>(const Vector3& vec, int32 scalar) noexcept
    {
        return Vector3{vec.X + scalar, vec.Y + scalar, vec.Z + scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator+<Vector4>(const Vector4& vec, int32 scalar) noexcept
    {
        return Vector4{vec.X + scalar, vec.Y + scalar, vec.Z + scalar, vec.W + scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator+<Vector2>(int32 scalar, const Vector2& vec) noexcept
    {
        return Vector2{vec.X + scalar, vec.Y + scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator+<Vector3>(int32 scalar, const Vector3& vec) noexcept
    {
        return Vector3{vec.X + scalar, vec.Y + scalar, vec.Z + scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator+<Vector4>(int32 scalar, const Vector4& vec) noexcept
    {
        return Vector4{vec.X + scalar, vec.Y + scalar, vec.Z + scalar, vec.W + scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator+<Vector2>(const Vector2& vec, float scalar) noexcept
    {
        return Vector2{vec.X + scalar, vec.Y + scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator+<Vector3>(const Vector3& vec, float scalar) noexcept
    {
        return Vector3{vec.X + scalar, vec.Y + scalar, vec.Z + scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator+<Vector4>(const Vector4& vec, float scalar) noexcept
    {
        return Vector4{vec.X + scalar, vec.Y + scalar, vec.Z + scalar, vec.W + scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator+<Vector2>(float scalar, const Vector2& vec) noexcept
    {
        return Vector2{vec.X + scalar, vec.Y + scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator+<Vector3>(float scalar, const Vector3& vec) noexcept
    {
        return Vector3{vec.X + scalar, vec.Y + scalar, vec.Z + scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator+<Vector4>(float scalar, const Vector4& vec) noexcept
    {
        return Vector4{vec.X + scalar, vec.Y + scalar, vec.Z + scalar, vec.W + scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator-<Vector2>(const Vector2& vec, int32 scalar) noexcept
    {
        return Vector2{vec.X - scalar, vec.Y - scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator-<Vector3>(const Vector3& vec, int32 scalar) noexcept
    {
        return Vector3{vec.X - scalar, vec.Y - scalar, vec.Z - scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator-<Vector4>(const Vector4& vec, int32 scalar) noexcept
    {
        return Vector4{vec.X - scalar, vec.Y - scalar, vec.Z - scalar, vec.W - scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator-<Vector2>(int32 scalar, const Vector2& vec) noexcept
    {
        return Vector2{scalar - vec.X, scalar - vec.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator-<Vector3>(int32 scalar, const Vector3& vec) noexcept
    {
        return Vector3{scalar - vec.X, scalar - vec.Y, scalar - vec.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator-<Vector4>(int32 scalar, const Vector4& vec) noexcept
    {
        return Vector4{scalar - vec.X, scalar - vec.Y, scalar - vec.Z, scalar - vec.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator-<Vector2>(const Vector2& vec, float scalar) noexcept
    {
        return Vector2{vec.X - scalar, vec.Y - scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator-<Vector3>(const Vector3& vec, float scalar) noexcept
    {
        return Vector3{vec.X - scalar, vec.Y - scalar, vec.Z - scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator-<Vector4>(const Vector4& vec, float scalar) noexcept
    {
        return Vector4{vec.X - scalar, vec.Y - scalar, vec.Z - scalar, vec.W - scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator-<Vector2>(float scalar, const Vector2& vec) noexcept
    {
        return Vector2{scalar - vec.X, scalar - vec.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator-<Vector3>(float scalar, const Vector3& vec) noexcept
    {
        return Vector3{scalar - vec.X, scalar - vec.Y, scalar - vec.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator-<Vector4>(float scalar, const Vector4& vec) noexcept
    {
        return Vector4{scalar - vec.X, scalar - vec.Y, scalar - vec.Z, scalar - vec.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator*<Vector2>(const Vector2& vec, float scalar) noexcept
    {
        return Vector2{vec.X * scalar, vec.Y * scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator*<Vector3>(const Vector3& vec, float scalar) noexcept
    {
        return Vector3{vec.X * scalar, vec.Y * scalar, vec.Z * scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator*<Vector4>(const Vector4& vec, float scalar) noexcept
    {
        return Vector4{vec.X * scalar, vec.Y * scalar, vec.Z * scalar, vec.W * scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator*<Vector2>(float scalar, const Vector2& vec) noexcept
    {
        return Vector2{scalar * vec.X, scalar * vec.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator*<Vector3>(float scalar, const Vector3& vec) noexcept
    {
        return Vector3{scalar * vec.X, scalar * vec.Y, scalar * vec.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator*<Vector4>(float scalar, const Vector4& vec) noexcept
    {
        return Vector4{scalar * vec.X, scalar * vec.Y, scalar * vec.Z, scalar * vec.W};
    }
    //====================================================================================================
    template<>
    Vector2 operator/<Vector2>(const Vector2& vec, float scalar) noexcept
    {
        return Vector2{vec.X / scalar, vec.Y / scalar};
    }
    //====================================================================================================
    template<>
    Vector3 operator/<Vector3>(const Vector3& vec, float scalar) noexcept
    {
        return Vector3{vec.X / scalar, vec.Y / scalar, vec.Z / scalar};
    }
    //====================================================================================================
    template<>
    Vector4 operator/<Vector4>(const Vector4& vec, float scalar) noexcept
    {
        return Vector4{vec.X / scalar, vec.Y / scalar, vec.Z / scalar, vec.W / scalar};
    }
    //====================================================================================================
    template<>
    Vector2 operator/<Vector2>(float scalar, const Vector2& vec) noexcept
    {
        return Vector2{scalar / vec.X, scalar / vec.Y};
    }
    //====================================================================================================
    template<>
    Vector3 operator/<Vector3>(float scalar, const Vector3& vec) noexcept
    {
        return Vector3{scalar / vec.X, scalar / vec.Y, scalar / vec.Z};
    }
    //====================================================================================================
    template<>
    Vector4 operator/<Vector4>(float scalar, const Vector4& vec) noexcept
    {
        return Vector4{scalar / vec.X, scalar / vec.Y, scalar / vec.Z, scalar / vec.W};
    }
    //====================================================================================================
    template<>
    float operator*<Vector2>(const Vector2& vec) noexcept
    {
        return sqrt(vec.X * vec.X + vec.Y * vec.Y);
    }
    //====================================================================================================
    template<>
    float operator*<Vector3>(const Vector3& vec) noexcept
    {
        return sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z);
    }
    //====================================================================================================
    template<>
    float operator*<Vector4>(const Vector4& vec) noexcept
    {
        return sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z + vec.W * vec.W);
    }
    //====================================================================================================
}
//====================================================================================================