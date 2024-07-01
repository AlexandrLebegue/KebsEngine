# CMakeList.txt : CMake project for SDL_cmake_template, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.7.2)


project(physics)
set(CMAKE_CXX_STANDARD 17)

# Imprimer la valeur de CMAKE_BUILD_TYPE pour vérifier qu'elle est correctement récupérée
message(STATUS "Compiling ${Project_Name}")

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME} 
PRIVATE src/object.cpp
PRIVATE src/physic-world.cpp
)

target_include_directories(${PROJECT_NAME} 
PUBLIC include/object.hpp
PUBLIC include/physic-world.hpp
)

