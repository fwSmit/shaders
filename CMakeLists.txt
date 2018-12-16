cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set (CMAKE_CXX_STANDARD 14)

project (shaders_project CXX)

#file globing
file(GLOB_RECURSE sources src/*.cpp src/*.h)
file(GLOB_RECURSE data resources/*)
file(GLOB_RECURSE shader_files src/*.frag src/*.vert)

add_executable(shaders ${sources})

#copy resources to build/resources
file(COPY ${data} DESTINATION resources)
#copy shader files to build directory
#foreach(shaderFile ${shader_files})
	#add_custom_command(
		#TARGET shaders PRE_BUILD
		#COMMAND ${CMAKE_COMMAND} -E create_symlink
		#${shaderFile}
		#${CMAKE_CURRENT_BINARY_DIR})
#endforeach()
#armadillo library
add_custom_command(
	TARGET shaders PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E create_symlink
	${CMAKE_SOURCE_DIR}/src/fragment_shader.frag
	${CMAKE_CURRENT_BINARY_DIR}/fragment_shader.frag)
find_package(Armadillo REQUIRED)

#include the necessary libraries
find_package(SFML 2 REQUIRED system window graphics)
find_package(TGUI REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()

if(NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif()

if(NOT ARMADILLO_FOUND)
	message(FATAL_ERROR "Could not find armadillo")
endif()

include_directories(${SFML_INCLUDE_DIR})
include_directories(${TGUI_INCLUDE_DIR})
include_directories(${ARMADILLO_INCLUDE_DIRS})

target_link_libraries(shaders ${SFML_LIBRARIES} ${TGUI_LIBRARY} ${ARMADILLO_LIBRARIES})
