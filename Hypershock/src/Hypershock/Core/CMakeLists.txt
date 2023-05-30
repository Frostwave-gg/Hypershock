#====================================================================================================
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Time")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/String")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Memory")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Object")
#====================================================================================================
set(HYPERSHOCK_CORE_HEADERS
        ${HYPERSHOCK_TIME_HEADERS}
        ${HYPERSHOCK_STRING_HEADERS}
        ${HYPERSHOCK_MEMORY_HEADERS}
        ${HYPERSHOCK_OBJECT_HEADERS}
        "${CMAKE_CURRENT_SOURCE_DIR}/Core.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Types.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/EntryPoint.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Error.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Utilities.hpp"
        CACHE INTERNAL "" FORCE)
#====================================================================================================
set(HYPERSHOCK_CORE_SOURCES
        ${HYPERSHOCK_TIME_SOURCES}
        ${HYPERSHOCK_STRING_SOURCES}
        ${HYPERSHOCK_MEMORY_SOURCES}
        ${HYPERSHOCK_OBJECT_SOURCES}
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
        CACHE INTERNAL "" FORCE)
#====================================================================================================