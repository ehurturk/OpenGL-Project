cmake_minimum_required(VERSION 3.12)
project(OpenGL-Project)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE proj_sources ${CMAKE_SOURCE_DIR}/src/Core/*.cpp)
file(GLOB_RECURSE proj_include ${CMAKE_SOURCE_DIR}/src/*.h)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(GLFW_LIB /usr/local/lib/libglfw.3.3.dylib)
set(TO_BE_LINKED ${OPENGL_LIBRARIES} ${GLFW_LIB})


include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/thirdparty/glad.c ${proj_sources} ${proj_include})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/vendor ${proj_include} )
target_link_libraries(${CMAKE_PROJECT_NAME} ${TO_BE_LINKED})
