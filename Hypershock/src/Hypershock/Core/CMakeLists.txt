set(HYPERSHOCK_CORE_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/Core.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Types.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/EntryPoint.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Error.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Utilities.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Monitor.hpp"
        CACHE INTERNAL "" FORCE)

set(HYPERSHOCK_CORE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Monitor.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Types.cpp"
        CACHE INTERNAL "" FORCE)