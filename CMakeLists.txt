cmake_minimum_required(VERSION 3.5.1)

# set project name
project(fenko)

# list source files
set(SOURCES 
    src/main.cpp 
    src/graphics/render.cpp 
    src/canvas.cpp 
    src/input/input.cpp 
    src/input/input_api.cpp 
    src/data.cpp 
    src/graphics/drawing_api.cpp
    src/graphics/sprite.cpp
    src/sound/sound.cpp
    src/api/wally_fenko.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_CXX_STANDARD 14)

message(STATUS "Configuration: ${CMAKE_BUILD_TYPE}")

add_executable(fenko ${SOURCES})

# set include dirs
include_directories(fenko PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/
                    # backwards compatibility
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/data_structs
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/debug
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/emitter
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/memory
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/misc
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/parser
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/preprocessor
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/scanner
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/std
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/wally/vm)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    target_compile_options(fenko PRIVATE -Wall -Wextra -Wpedantic)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
else()
    target_compile_options(fenko PRIVATE -O3 -Wall -Wextra -Wpedantic)
endif()

# find and include sdl2 files
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# find and include SDL2 Mixer
include(FindPkgConfig)
pkg_check_modules(SDL2_Mixer REQUIRED IMPORTED_TARGET SDL2_mixer)
pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# link sdl2
target_link_libraries(fenko ${SDL2_LIBRARIES} -lSDL2_image PkgConfig::SDL2_Mixer )

# link Wally
target_link_libraries(fenko ${CMAKE_CURRENT_SOURCE_DIR}/lib/libWally.a)
