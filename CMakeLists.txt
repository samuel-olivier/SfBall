CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT ("SfBall")

#
# CMake Configuration
#

SET (GCC46_PATH
  "/usr/bin/g++-4.6"
)
IF (EXISTS ${GCC46_PATH})
   SET (CMAKE_CXX_COMPILER ${GCC46_PATH})
ENDIF ()

SET (CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Wno-ignored-qualifiers")

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
    DxBall
    ${SFBALL_SOURCES}
)

#
# Library linking
#

# DxBall
TARGET_LINK_LIBRARIES (
    DxBall
    ${SFML_LIBRARIES}
)

#
# Setup bundles
#

# DxBall bundle

SET_PROPERTY (
    TARGET DxBall
    PROPERTY RUNTIME_OUTPUT_DIRECTORY ${SFBALL_BUNDLE_PATH}
)

SET_PROPERTY (
    TARGET DxBall
    PROPERTY RUNTIME_OUTPUT_DIRECTORY_DEBUG ${SFBALL_BUNDLE_PATH}
)

SET_PROPERTY (
    TARGET DxBall
    PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELEASE ${SFBALL_BUNDLE_PATH}
)