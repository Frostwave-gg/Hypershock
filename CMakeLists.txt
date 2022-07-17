cmake_minimum_required(VERSION 3.20.0)

set(HYPERSHOCK_VERSION 0.1)

project(Hypershock VERSION ${HYPERSHOCK_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add subdirectories
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/HYPERSHOCK/src")

# set sources
set(HYPERSHOCK_FILES
		${HYPERSHOCK_SOURCES}
		${HYPERSHOCK_HEADERS}
		CACHE INTERNAL "" FORCE)


if(DEFINED HYPERSHOCK_BUILD_TYPE)
	set(HYPERSHOCK_BUILD_TYPE
			${HYPERSHOCK_BUILD_TYPE}
			CACHE INTERNAL "" FORCE)
else()
	set(HYPERSHOCK_BUILD_TYPE
			"SHARED"
			CACHE INTERNAL "" FORCE)
endif()

if(HYPERSHOCK_BUILD_TYPE STREQUAL "STATIC")
	message(STATUS "HYPERSHOCK: Build type detected: ${GGEZ_BUILD_TYPE}")
elseif(HYPERSHOCK_BUILD_TYPE STREQUAL "SHARED")
	message(STATUS "HYPERSHOCK: Build type detected: ${GGEZ_BUILD_TYPE}")
else()
	message(FATAL_ERROR "HYPERSHOCK: Build type detected: ${GGEZ_BUILD_TYPE}")
endif()


add_library(Hypershock ${HYPERSHOCK_BUILD_TYPE} ${HYPERSHOCK_FILES})

target_include_directories(Hypershock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/src")
target_include_directories(Hypershock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/stb")
target_include_directories(Hypershock PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/src/Hypershock")

message(STATUS "HYPERSHOCK: Building glfw")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/glfw")

message(STATUS "HYPERSHOCK: Building glm")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/glm")

message(STATUS "HYPERSHOCK: Building spdlog")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/spdlog")

target_link_libraries(Hypershock glfw glm spdlog)

if(HYPERSHOCK_BUILD_TYPE STREQUAL "STATIC")
	target_compile_definitions(Hypershock PUBLIC HYPERSHOCK_BUILD_STATIC)
elseif(HYPERSHOCK_BUILD_TYPE STREQUAL "SHARED")
	target_compile_definitions(Hypershock PUBLIC HYPERSHOCK_BUILD_SHARED)
	target_compile_definitions(Hypershock PRIVATE HYPERSHOCK_EXPORT)
endif()