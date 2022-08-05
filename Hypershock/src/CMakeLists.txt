add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/Core")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/Event")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/DataStructures")

set(HYPERSHOCK_HEADERS
        ${HYPERSHOCK_CORE_HEADERS}
        ${EVENT_HEADERS}
        ${DATA_STRUCTURE_HEADERS}
        "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock.hpp"
        CACHE INTERNAL "" FORCE)

set(HYPERSHOCK_SOURCES
        ${HYPERSHOCK_CORE_SOURCES}
        ${EVENT_SOURCES}
        ${DATA_STRUCTURE_SOURCES}
        CACHE INTERNAL "" FORCE)