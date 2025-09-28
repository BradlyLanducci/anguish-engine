cmake_minimum_required(VERSION 3.5)

project(AnguishEngine)

# add_compile_options("-O0")

find_package(glog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

file(GLOB_RECURSE AssetsSourceFiles ${CMAKE_SOURCE_DIR}/assets/*.cpp)
file(GLOB DependencySourceFiles 
	${CMAKE_SOURCE_DIR}/dependencies/*.c
	${CMAKE_SOURCE_DIR}/dependencies/*.cpp
)
file(GLOB_RECURSE CoreSourceFiles ${CMAKE_SOURCE_DIR}/core/*.cpp)

set(SourceFiles
	${AssetsSourceFiles}
	${DependencySourceFiles}
	${CoreSourceFiles}
)
	
add_executable(${PROJECT_NAME} ${SourceFiles})

add_library(glfw3 STATIC IMPORTED)
set_target_properties(glfw3 PROPERTIES
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/Dependencies/lib/glfw3.lib
)

add_library(assimp SHARED IMPORTED)
set_target_properties(assimp PROPERTIES
   	IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/builds/Debug/assimp-vc143-mt.dll
	IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/Dependencies/lib/assimp-vc143-mt.lib
)

file(GLOB IMGUI_SOURCES Dependencies/include/imgui/*.cpp)
add_library(ImGui STATIC ${IMGUI_SOURCES})
target_include_directories(ImGui PUBLIC 
	imgui
	${CMAKE_INCLUDE_PATH}
	${CMAKE_SOURCE_DIR}/Dependencies/include
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/assets
	${CMAKE_SOURCE_DIR}/Dependencies/
	${CMAKE_SOURCE_DIR}/Dependencies/include
	${CMAKE_SOURCE_DIR}/core
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
PUBLIC
	glog::glog
	glfw3
	glm::glm
	assimp
	ImGui
)
