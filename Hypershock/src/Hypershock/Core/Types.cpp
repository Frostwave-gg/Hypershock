//
// Created by jankr on 02-Aug-22.
//

#include "Types.hpp"

namespace Hypershock {
    namespace Limits {
        template<> HYPERSHOCK_CONSTEXPR Uint8 Minimum<Uint8>() {
            return Uint8_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint8 Maximum<Uint8>() {
            return Uint8_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint16 Minimum<Uint16>() {
            return Uint16_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint16 Maximum<Uint16>() {
            return Uint16_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint32 Minimum<Uint32>() {
            return Uint32_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint32 Maximum<Uint32>() {
            return Uint32_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint64 Minimum<Uint64>() {
            return Uint64_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Uint64 Maximum<Uint64>() {
            return Uint64_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Int8 Minimum<Int8>() {
            return Int8_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Int8 Maximum<Int8>() {
            return Int8_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Int16 Minimum<Int16>() {
            return Int16_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Int16 Maximum<Int16>() {
            return Int16_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Int32 Minimum<Int32>() {
            return Int32_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Int32 Maximum<Int32>() {
            return Int32_MAX;
        }

        template<> HYPERSHOCK_CONSTEXPR Int64 Minimum<Int64>() {
            return Int64_MIN;
        }

        template<> HYPERSHOCK_CONSTEXPR Int64 Maximum<Int64>() {
            return Int64_MAX;
        }
    }
}