cmake_minimum_required(VERSION 3.5)

project(AnguishEngine)

# add_compile_options("-O0")

find_package(glog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_library(glfw3 
    STATIC 
    IMPORTED
)

set_target_properties(glfw3 
    PROPERTIES
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/Dependencies/lib/glfw3.lib
)

add_library(assimp 
    SHARED 
    IMPORTED
)

set_target_properties(assimp 
    PROPERTIES
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/builds/Debug/assimp-vc143-mt.dll
        IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/Dependencies/lib/assimp-vc143-mt.lib
)

file(GLOB IMGUI_SOURCES 
    ${CMAKE_SOURCE_DIR}/Dependencies/include/imgui/*.cpp
)

add_library(ImGui 
    STATIC 
    ${IMGUI_SOURCES}
)

target_include_directories(ImGui 
    PUBLIC 
        imgui
        ${CMAKE_INCLUDE_PATH}
        ${CMAKE_SOURCE_DIR}/Dependencies/include
)

add_subdirectory(core)
add_subdirectory(example)
