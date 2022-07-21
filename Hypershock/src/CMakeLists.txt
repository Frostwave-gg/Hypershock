add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/Core")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/Event")

set(HYPERSHOCK_HEADERS
        ${HYPERSHOCK_CORE_HEADERS}
        ${EVENT_HEADERS}
        "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock.hpp"
        CACHE INTERNAL "" FORCE)

set(HYPERSHOCK_SOURCES
        ${HYPERSHOCK_CORE_SOURCES}
        ${EVENT_SOURCES}
        CACHE INTERNAL "" FORCE)