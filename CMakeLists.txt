cmake_minimum_required(VERSION 3.5)

project(AnguishEngine)

# add_compile_options("-O0")

find_package(glog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(AssetsSourceFiles
	assets/sprites/character.cpp
	assets/sprites/grass.cpp
)

set(DependencySourceFiles
	dependencies/glad.c
	dependencies/stb_image.h
)

set(IdleSourceFiles
	source/idle/idle_manager.cpp
)

set(ObjectSourceFiles
	source/objects/object.cpp
	source/objects/collision_object.cpp
	source/objects/static_object.cpp
	source/objects/sprite_object.cpp
)

set(OpenGlSourceFiles
	source/ogl/gl_object.h
	source/ogl/vao.cpp
	source/ogl/vbo.cpp
	source/ogl/ebo.cpp
)

set(PhysicsSourceFiles
	source/physics/aabb.cpp
	source/physics/physics_manager.cpp
)

set(RendererSourceFiles
	source/renderer/rendering_manager.cpp
)

set(ShaderSourceFiles
	source/shaders/shader.cpp
	source/shaders/shader_program.cpp	
)

set(TextureSourceFiles
	source/texture/texture.cpp
)

set(UtilitiesSourceFiles
	source/utilities/file_io.h	
	source/utilities/keyboard.cpp	
	source/utilities/window.cpp	
	source/utilities/data_structures.cpp	
)

set(SourceFiles
	Source/main.cpp

	${AssetsSourceFiles}
	${DependencySourceFiles}
	${IdleSourceFiles}
	${ObjectSourceFiles}
	${OpenGlSourceFiles}
	${PhysicsSourceFiles}
	${RendererSourceFiles}
	${ShaderSourceFiles}
	${TextureSourceFiles}
	${UtilitiesSourceFiles}
)
	
add_executable(${PROJECT_NAME} ${SourceFiles})

target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/assets
	${CMAKE_SOURCE_DIR}/Dependencies/
	${CMAKE_SOURCE_DIR}/Dependencies/include
	${CMAKE_SOURCE_DIR}/source
)

target_link_libraries("${PROJECT_NAME}"
PRIVATE
PUBLIC
	glog::glog
	glfw3
	glm::glm
	assimp
	ImGui
)

add_library(glfw3 STATIC IMPORTED)
set_target_properties(glfw3 PROPERTIES
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/Dependencies/lib/glfw3.lib"
)

add_library(assimp SHARED IMPORTED)
set_target_properties(assimp PROPERTIES
   	IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/builds/Debug/assimp-vc143-mt.dll"
	IMPORTED_IMPLIB "${PROJECT_SOURCE_DIR}/Dependencies/lib/assimp-vc143-mt.lib"	
)

file(GLOB IMGUI_SOURCES Dependencies/include/imgui/*.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories(ImGui PUBLIC 
	imgui
	${CMAKE_INCLUDE_PATH}
	${CMAKE_SOURCE_DIR}/Dependencies/include
)
