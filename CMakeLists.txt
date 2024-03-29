#====================================================================================================
cmake_minimum_required(VERSION 3.20.0)
#====================================================================================================
set(HYPERSHOCK_VERSION 0.0.1)
message(STATUS "\n-- HYPERSHOCK: Version ${HYPERSHOCK_VERSION}\n--")
project(Hypershock VERSION ${HYPERSHOCK_VERSION})
#====================================================================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#====================================================================================================
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/HYPERSHOCK/src")
#====================================================================================================
set(HYPERSHOCK_FILES
		${HYPERSHOCK_SOURCES}
		${HYPERSHOCK_HEADERS}
		CACHE INTERNAL "" FORCE)
#====================================================================================================
if(DEFINED HYPERSHOCK_BUILD_TYPE)
	set(HYPERSHOCK_BUILD_TYPE
			${HYPERSHOCK_BUILD_TYPE}
			CACHE INTERNAL "" FORCE)
else()
	set(HYPERSHOCK_BUILD_TYPE
			"SHARED"
			CACHE INTERNAL "" FORCE)
endif()
#====================================================================================================
if(HYPERSHOCK_BUILD_TYPE STREQUAL "STATIC")
	message(STATUS "HYPERSHOCK: Build type: ${HYPERSHOCK_BUILD_TYPE}")
elseif(HYPERSHOCK_BUILD_TYPE STREQUAL "SHARED")
	message(STATUS "HYPERSHOCK: Build type: ${HYPERSHOCK_BUILD_TYPE}")
else()
	message(FATAL_ERROR "HYPERSHOCK: Build type: ${HYPERSHOCK_BUILD_TYPE}")
endif()
#====================================================================================================
include(GNUInstallDirs)
#====================================================================================================
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#====================================================================================================
add_library(Hypershock ${HYPERSHOCK_BUILD_TYPE} ${HYPERSHOCK_FILES})
#====================================================================================================
target_include_directories(Hypershock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/src")
target_include_directories(Hypershock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/stb")
target_include_directories(Hypershock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/src/Hypershock")
#====================================================================================================
message(STATUS "\n-- HYPERSHOCK: Adding glfw\n--")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/glfw")

message(STATUS "\n-- HYPERSHOCK: Adding glm\n--")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/glm")

message(STATUS "\n-- HYPERSHOCK: Adding spdlog\n--")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/spdlog")

message(STATUS "\n-- HYPERSHOCK: Adding glad\n--")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Hypershock/vendor/src/glad")
#====================================================================================================
target_link_libraries(Hypershock glfw glm spdlog glad)
#====================================================================================================
if(HYPERSHOCK_BUILD_TYPE STREQUAL "STATIC")
	target_compile_definitions(Hypershock PUBLIC HYPERSHOCK_BUILD_STATIC)
elseif(HYPERSHOCK_BUILD_TYPE STREQUAL "SHARED")
	target_compile_definitions(Hypershock PRIVATE HYPERSHOCK_BUILD_SHARED)
	target_compile_definitions(Hypershock PRIVATE HYPERSHOCK_EXPORT)
endif()
#====================================================================================================
set_target_properties(Hypershock PROPERTIES VERSION ${HYPERSHOCK_VERSION})
#====================================================================================================