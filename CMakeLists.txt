# CMakeList.txt : CMake project for KebsEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.7.2)

project(KebsEngine)
set(CMAKE_CXX_STANDARD 17)

# Imprimer la valeur de CMAKE_BUILD_TYPE pour vérifier qu'elle est correctement récupérée
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# TODO: Add tests and install targets if needed.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)


find_package(SDL2 REQUIRED)
find_package(SDL2_image)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_subdirectory(src/graphics)
add_subdirectory(src/physics)
add_subdirectory(src/components)



set(SOURCE_FILES "src/main.cpp")

add_executable(KebsEngine 
	${SOURCE_FILES}
)

target_link_libraries(KebsEngine 
	${SDL2_LIBRARY}
	${SDL2_IMAGE_LIBRARY}
	components
	graphics
	physics
)

install(TARGETS KebsEngine RUNTIME DESTINATION ${BIN_DIR}/)
set_target_properties(KebsEngine PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}" )

if(CMAKE_SIZEOF_VOID_P EQUAL 8) 
	add_custom_command( TARGET KebsEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different 
		${SDL2_IMAGE_PATH}/lib/x64/SDL2_image.dll 
		${BIN_DIR}/$<CONFIG>/SDL2_image.dll  )
	add_custom_command( TARGET KebsEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${SDL2_PATH}/lib/x64/SDL2.dll
		${BIN_DIR}/$<CONFIG>/SDL2.dll  )
elseif()
	add_custom_command( TARGET KebsEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different 
		${SDL2_IMAGE_PATH}/lib/x86/SDL2_image.dll 
		${BIN_DIR}/$<CONFIG>/SDL2_image.dll  )
	add_custom_command( TARGET KebsEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${SDL2_PATH}/lib/x86/SDL2.dll
		${BIN_DIR}/$<CONFIG>/SDL2.dll  )
endif()

add_custom_command( TARGET KebsEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory 
		${CMAKE_SOURCE_DIR}/src/graphics/ressources/ 
		${BIN_DIR}/$<CONFIG>/ressources/ )