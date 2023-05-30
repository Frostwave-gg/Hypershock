#====================================================================================================
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Vector")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Matrix")
#====================================================================================================
set(HYPERSHOCK_MATH_HEADERS
        ${HYPERSHOCK_VECTOR_HEADERS}
        ${HYPERSHOCK_MATRIX_HEADERS}
        ${HYPERSHOCK_QUATERNION_HEADERS}
        "${CMAKE_CURRENT_SOURCE_DIR}/Math.hpp"
        CACHE INTERNAL "" FORCE)
#====================================================================================================
set(HYPERSHOCK_MATH_SOURCES
        ${HYPERSHOCK_VECTOR_SOURCES}
        ${HYPERSHOCK_MATRIX_SOURCES}
        ${HYPERSHOCK_QUATERNION_SOURCES}
        "${CMAKE_CURRENT_SOURCE_DIR}/Math.cpp"
        CACHE INTERNAL "" FORCE)
#====================================================================================================