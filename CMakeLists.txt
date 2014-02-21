CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT ("SfBall")

#
# CMake Configuration
#

SET (CMAKE_CXX_FLAGS "-std=c++0x -Wall -D_USE_MATH_DEFINES")

#
# Custom CMake modules
#

SET (
    CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/CMakeModules ${CMAKE_MODULE_PATH}
)

#
# Variables
#

SET (SFBALL_BUNDLE_PATH ${CMAKE_SOURCE_DIR}/bin)

#
# Dependencies
#

# Find SFML
FIND_PACKAGE (SFML 2 REQUIRED system window graphics)

#
# Include Directories
#

INCLUDE_DIRECTORIES (
    ${SFML_INCLUDE_DIR}
	"include/"
)

#
# Sources
#

# DxBall
FILE (
    GLOB_RECURSE
    SFBALL_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*
)

#
# Exec
#

# DxBall
ADD_EXECUTABLE (
    SfBall
    ${SFBALL_SOURCES}
)

#
# Library linking
#

# DxBall
TARGET_LINK_LIBRARIES (
    SfBall
    ${SFML_LIBRARIES}
    ${CMAKE_SOURCE_DIR}/lib/libBox2D.a
)

#
# Setup bundles
#

# DxBall bundle

SET_PROPERTY (
    TARGET SfBall
    PROPERTY RUNTIME_OUTPUT_DIRECTORY ${SFBALL_BUNDLE_PATH}
)

SET_PROPERTY (
    TARGET SfBall
    PROPERTY RUNTIME_OUTPUT_DIRECTORY_DEBUG ${SFBALL_BUNDLE_PATH}
)

SET_PROPERTY (
    TARGET SfBall
    PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELEASE ${SFBALL_BUNDLE_PATH}
)
