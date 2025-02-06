cmake_minimum_required(VERSION 3.30)
project(Task_Management C)

set(CMAKE_C_STANDARD 23)

add_executable(Task_Management
    main.c
    UserData/createFile.c
    Task/task.c
    Date/date.c
)

include_directories(
    Date
    Task
    UserData
)

# --- Custom clean rule ---
# This will search recursively in the build directory for any .o or .out files
file(GLOB_RECURSE EXTRA_FILES
        "${CMAKE_BINARY_DIR}/*.o"
        "${CMAKE_BINARY_DIR}/*.out"
)

# Define a custom target "clean_extra" to remove these files
add_custom_target(clean_extra
        COMMAND ${CMAKE_COMMAND} -E echo "Removing extra files (.o and .out)..."
        COMMAND ${CMAKE_COMMAND} -E remove ${EXTRA_FILES}
        COMMENT "Cleaning extra .o and .out files from the build tree"
)