file(GLOB ExampleSourceFiles 
	${CMAKE_SOURCE_DIR}/example/*.cpp
)

set(EXAMPLE_PROJECT ${PROJECT_NAME}_example)
	
add_executable(${EXAMPLE_PROJECT}
    ${ExampleSourceFiles}
)

target_compile_features(${EXAMPLE_PROJECT} 
    PRIVATE 
        cxx_std_20
)

target_include_directories(${EXAMPLE_PROJECT} 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/Dependencies/
        ${CMAKE_SOURCE_DIR}/Dependencies/include
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/example
)

target_link_libraries(${EXAMPLE_PROJECT}
    AnguishEngine
)
