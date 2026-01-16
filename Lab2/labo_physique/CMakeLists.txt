cmake_minimum_required(VERSION 3.21)

project(labo_physique)

# Setup language requirements
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#--------------------------------------------------
# Gestion de OpenMP sur macOS (Homebrew)
#--------------------------------------------------
if(APPLE)
    set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp")
    set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp")
    set(OpenMP_C_LIB_NAMES "omp")
    set(OpenMP_CXX_LIB_NAMES "omp")

    execute_process(
            COMMAND brew --prefix libomp
            OUTPUT_VARIABLE HOMEBREW_LIBOMP_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    set(OpenMP_omp_LIBRARY "${HOMEBREW_LIBOMP_PATH}/lib/libomp.dylib")
    include_directories("${HOMEBREW_LIBOMP_PATH}/include")
endif()

# Recherche OpenMP
find_package(OpenMP)

#--------------------------------------------------
# Sous MAC, OpenGL est Deprecated, mais toujours
# fonctionnel, on veut éviter tous les warnings
# durant la compilation.
#--------------------------------------------------
if (APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
endif()

add_definitions(${NANOGUI_EXTRA_DEFS})
include_directories(${nanogui_SRC_DIR}/include)
include_directories(${NANOGUI_EXTRA_INCS})
include_directories(${PROJECT_SOURCE_DIR}/../labo01/src ${COMMON_INCLUDES})

find_package(OpenGL REQUIRED)

# Add .cpp and .h files
set(HEADERS
        ParticleSimGLCanvas.h
        ParticleSimApplication.h
        ParticleSystem.h
        ParticleSystemFactory.h
        Vector2d.h
        Solvers.h
        GraphColoring.h
)

set(SOURCE
        main.cpp
        ParticleSimApplication.cpp
        ParticleSimGLCanvas.cpp
        ParticleSystem.cpp
        ParticleSystemFactory.cpp
        GraphColoring.cpp
)

add_executable(labo_physique ${SOURCE} ${HEADERS})

target_link_libraries(labo_physique nanogui ${NANOGUI_EXTRA_LIBS} OpenGL::GL)

if(MSVC)
    set_property(TARGET labo_physique PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/labo_physique)
endif()