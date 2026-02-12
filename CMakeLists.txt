cmake_minimum_required(VERSION 3.20)
set(TARGET utils)
project(${TARGET} LANGUAGES CXX)

# =========================
# Compilateur & Standard
# =========================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER clang++)

# =========================
# Warnings
# =========================
add_compile_options(
    -W
    -Wall
    -Wextra
    -Wpedantic
    -Wunused-parameter
    -Wshadow
    -Wuninitialized
)

# =========================
# Sources
# =========================
set(SRC
    ## Exception
    src/utils/exception/AException.cpp
)
add_library(${TARGET} STATIC ${SRC})

# =========================
# Includes
# =========================
target_include_directories(${TARGET} PUBLIC include)
#target_link_libraries(${TARGET} PRIVATE ...)

# =========================
# Modes
# =========================
target_compile_options(${TARGET} PRIVATE
    $<$<CONFIG:Debug>:-g -ggdb3>
    $<$<CONFIG:Release>:-O1>
)

# =========================
# Utils
# =========================
add_custom_target(get_unregistered_files
    COMMAND bash ${CMAKE_SOURCE_DIR}/cmake/check_files.sh unregistered ${SRC}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(get_unknow_files
    COMMAND bash ${CMAKE_SOURCE_DIR}/cmake/check_files.sh unknow ${SRC}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
