cmake_minimum_required(VERSION 3.21)
project(GTI320-labos)

#--------------------------------------------------
# Add google test and setup build
#--------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# No need for GMock
set( BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set( INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set( GTEST_FORCE_SHARED_CRT ON CACHE BOOL "" FORCE)
set( GTEST_DISABLE_PTHREADS ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --------------------------------------------------
# Configuration FORCÉE de NanoGUI AVANT FetchContent
# --------------------------------------------------
set(NANOGUI_BUILD_EXAMPLES OFF CACHE BOOL "Disable examples" FORCE)
set(NANOGUI_BUILD_SHARED OFF CACHE BOOL "Disable shared lib" FORCE)
set(NANOGUI_BUILD_PYTHON OFF CACHE BOOL "Disable Python" FORCE)
set(NANOGUI_BUILD_GLFW ON CACHE BOOL "Enable GLFW" FORCE)
set(NANOGUI_INSTALL ON CACHE BOOL "Enable install" FORCE)

# 🔥 Forcer OpenGL et désactiver Metal
set(NANOGUI_USE_METAL OFF CACHE BOOL "Disable Metal backend" FORCE)
set(NANOGUI_USE_OPENGL ON CACHE BOOL "Enable OpenGL backend" FORCE)
set(NANOGUI_BACKEND "OpenGL" CACHE STRING "Select backend for NanoGUI" FORCE)
set(NANOGUI_SKIP_METAL_SHADER_PRECOMPILATION ON CACHE BOOL "Skip Metal shader precompilation" FORCE)

# --------------------------------------------------
# Déclaration et chargement du dépôt nanogui
# --------------------------------------------------
FetchContent_Declare(
        nanogui
        GIT_REPOSITORY https://github.com/mitsuba-renderer/nanogui.git
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(nanogui)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include_directories(${CMAKE_SOURCE_DIR}/labo01/src ${COMMON_INCLUDES})
add_subdirectory(labo01)
add_subdirectory(labo_ik)

if( MSVC )
  set_property(DIRECTORY . PROPERTY VS_STARTUP_PROJECT labo_ik)
endif()
  
