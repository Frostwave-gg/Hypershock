//
// Created by jankr on 21-Jul-22.
//

#ifndef HYPERSHOCK_UTILITIES_HPP
#define HYPERSHOCK_UTILITIES_HPP

#include "Core.hpp"
#include "Types.hpp"

#include <string>
#include <sstream>
#include <random>

namespace Hypershock {
    class HYPERSHOCK_PRIVATE_API Utilities {
    public:
        // TODO: Replace std random usage with internal random generator
        inline static std::string GenerateUUID() {
            std::stringstream uuid("");

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(Limits::Byte_MIN, Limits::Byte_MAX);

            for(Uint32 i = 0; i < DEFAULT_UUID_SIZE; i++) {
                uuid << dis(gen);
            }

            return uuid.str();
        }

    public:
        static const Uint32 DEFAULT_UUID_SIZE = 128;
    };
}

#endif //HYPERSHOCK_UTILITIES_HPP
