//
// Created by jankr on 05-Aug-22.
//

#ifndef HYPERSHOCK_GAME_IDTREE_HPP
#define HYPERSHOCK_GAME_IDTREE_HPP

#include "Core/Core.hpp"
#include "Core/Types.hpp"

#include <vector>
#include <string>

#define MAX_ID_LEN ('9' - '0' + 1 + 'z' - 'a' + 1 + 'Z' - 'A' + 1)
#define CHAR_TO_INDEX(c) ((c >= '0' && c <= '9') ? c - '0' : (c >= 'a' && c <= 'z' ? c - 'a' : c - 'A'))
#define CHAR_IN_ID_RANGE(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

namespace Hypershock {
    template<typename T> class HYPERSHOCK_PUBLIC_API IDTree {
    public:
        IDTree();
        ~IDTree();


    private:
        struct TreeElement {
            char elemChar = '\0';
            TreeElement* array[MAX_ID_LEN] = {nullptr};
            T* element = nullptr;
        };

        std::vector<std::string> m_IDKeys;
        std::vector<T*> m_Elements;

    };
}


#endif //HYPERSHOCK_GAME_IDTREE_HPP
