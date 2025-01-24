cmake_minimum_required(VERSION 3.2)

project(
  Vex-Engine
  VERSION 3.2
  DESCRIPTION "My Voxel Game Engine"
  LANGUAGES CXX
)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(LIB_DIR, "${PROJECT_SOURCE_DIR}/libs")
set(SRC_DIR, "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR, "${PROJECT_SOURCE_DIR}/include")

# Define your source files
file(GLOB_RECURSE VEX_FILES
    ${SRC_DIR}/*.cpp
    ${INCLUDE_DIR}/*.hpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${VEX_FILES})

# Add ${LIB_DIR} libraries
# Adjust these paths if you use submodules or custom paths for the libraries

# GLFW
add_subdirectory(${LIB_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

# GLAD
add_library(glad ${LIB_DIR}/glad/src/glad.c)
target_include_directories(glad PUBLIC ${LIB_DIR}/glad/include)
target_link_libraries(${PROJECT_NAME} glad)

# GLM
target_include_directories(${PROJECT_NAME} PRIVATE ${LIB_DIR}/glm)

# ImGui
add_library(imgui
    ${LIB_DIR}/imgui/imgui.cpp
    ${LIB_DIR}/imgui/imgui_draw.cpp
    ${LIB_DIR}/imgui/imgui_widgets.cpp
    ${LIB_DIR}/imgui/backends/imgui_impl_glfw.cpp
    ${LIB_DIR}/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC ${LIB_DIR}/imgui ${LIB_DIR}/imgui/backends)
target_link_libraries(${PROJECT_NAME} imgui)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${LIB_DIR}/glfw/include
    ${LIB_DIR}/glad/include
    ${LIB_DIR}/imgui
)

# Link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Set output directories for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Alternatively, for libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Optional: Enable warnings for better development
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()


