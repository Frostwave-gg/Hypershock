//
// Created by jankr on 16-Jul-22.
//

#ifndef HYPERSHOCK_TYPES_H
#define HYPERSHOCK_TYPES_H

#include "Core.hpp"

namespace Hypershock {

    typedef unsigned char Uint8;
    typedef unsigned short int Uint16;
    typedef unsigned int Uint32;
    typedef unsigned long long int Uint64;
    typedef signed char Int8;
    typedef signed short int Int16;
    typedef signed int Int32;
    typedef signed long long int Int64;
    typedef Uint8 Byte;
    typedef Uint64 Size;

    namespace Limits {

        const Uint8 Uint8_MIN = 0;
        const Uint8 Uint8_MAX = 0xFFU;
        const Uint16 Uint16_MIN = 0;
        const Uint16 Uint16_MAX = 0xFFFFU;
        const Uint32 Uint32_MIN = 0;
        const Uint32 Uint32_MAX = 0xFFFFFFFFU;
        const Uint64 Uint64_MIN = 0;
        const Uint64 Uint64_MAX = 0xFFFFFFFFFFFFFFFFULL;

        const Int8 Int8_MIN = -128;
        const Int8 Int8_MAX = 127;
        const Int16 Int16_MIN = -32768;
        const Int16 Int16_MAX = 32767;
        const Int32 Int32_MIN = -2147483648;
        const Int32 Int32_MAX = 2147483647;
        const Int64 Int64_MIN = (Int64)0x8000000000000000ULL;
        const Int64 Int64_MAX = (Int64)0x7FFFFFFFFFFFFFFFULL;

        const Byte Byte_MIN = 0;
        const Byte Byte_MAX = 0xFFU;

        const Size Size_MIN = (Size)0x8000000000000000ULL;
        const Size Size_MAX = (Size)0x7FFFFFFFFFFFFFFFULL;

        template<typename T> T Minimum();

        template<typename T> T Maximum();

        template<> Uint8 Minimum<Uint8>() {
            return Uint8_MIN;
        }

        template<> Uint8 Maximum<Uint8>() {
            return Uint8_MAX;
        }

        template<> Uint16 Minimum<Uint16>() {
            return Uint16_MIN;
        }

        template<> Uint16 Maximum<Uint16>() {
            return Uint16_MAX;
        }

        template<> Uint32 Minimum<Uint32>() {
            return Uint32_MIN;
        }

        template<> Uint32 Maximum<Uint32>() {
            return Uint32_MAX;
        }

        template<> Uint64 Minimum<Uint64>() {
            return Uint64_MIN;
        }

        template<> Uint64 Maximum<Uint64>() {
            return Uint64_MAX;
        }

        template<> Int8 Minimum<Int8>() {
            return Int8_MIN;
        }

        template<> Int8 Maximum<Int8>() {
            return Int8_MAX;
        }

        template<> Int16 Minimum<Int16>() {
            return Int16_MIN;
        }

        template<> Int16 Maximum<Int16>() {
            return Int16_MAX;
        }

        template<> Int32 Minimum<Int32>() {
            return Int32_MIN;
        }

        template<> Int32 Maximum<Int32>() {
            return Int32_MAX;
        }

        template<> Int64 Minimum<Int64>() {
            return Int64_MIN;
        }

        template<> Int64 Maximum<Int64>() {
            return Int64_MAX;
        }
    }

}


#endif //HYPERSHOCK_TYPES_H
