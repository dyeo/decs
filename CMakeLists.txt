cmake_minimum_required(VERSION 3.1...3.16)

project (decs VERSION 0.1 LANGUAGES C)

# add data desk git submodule to cmake project
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ext/data_desk")

# add decs_ds custom library
data_desk_add_custom_library(
	LIBNAME decs_ds 
	SRC "${CMAKE_CURRENT_SOURCE_DIR}/ds/model.c"
)

# recurse all data desk files
file(GLOB_RECURSE DATA_SRC 
	"${CMAKE_CURRENT_SOURCE_DIR}/ds/*.ds"
)

# run code generation on data desk files
data_desk_invoke(
	LIBNAME decs_ds
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	DATASPECS "${DATA_SRC}"
	OUTPUTS "${CMAKE_CURRENT_SOURCE_DIR}/src/generated/"
)

# recurse all source code files
file(GLOB_RECURSE LIB_SRC 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# add decs library
add_library(decs STATIC ${LIB_SRC})

# add include directory
target_include_directories(decs PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# recurse all source code files
file(GLOB_RECURSE TEST_SRC 
	"${CMAKE_CURRENT_SOURCE_DIR}/test/*.h" 
	"${CMAKE_CURRENT_SOURCE_DIR}/test/*.c"
)

# create test executable
add_executable(test ${TEST_SRC})

#link decs library
target_link_libraries(test decs)