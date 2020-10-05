cmake_minimum_required(VERSION 3.1...3.16)

project (decs VERSION 0.1 LANGUAGES C)

# Add Data Desk git submodule to cmake project
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ext/data_desk")

# Add decs_ds custom library
data_desk_add_custom_library(
	LIBNAME decs_ds
	SRC "ds/model.c"
)

# run code generation on data desk files
data_desk_invoke(
	LIBNAME decs_ds
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/generated/"
	DATASPECS "${CMAKE_CURRENT_SOURCE_DIR}/ds/data.ds"
	OUTPUTS
		"${CMAKE_CURRENT_SOURCE_DIR}/src/generated/generated_print.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/generated/generated_print.c"
)

## add decs library
add_library(decs STATIC
    "src/object.c"
    "src/generated/generated_print.c"
    )

# add include directory
target_include_directories(decs PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# create test executable
add_executable(test
	"${CMAKE_CURRENT_SOURCE_DIR}/test/main.c")

#link decs library
target_link_libraries(test decs)
