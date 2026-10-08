cmake_minimum_required(VERSION 3.10)
project(2D-ARPG-TEST)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(game PRIVATE lib)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(2D-ARPG-TEST ${SOURCES})

target_link_libraries(2D-ARPG-TEST raylib opengl32 gdi32 winmm)

#target_link_options(BeeBusy PRIVATE -Wl,--subsystem,windows)

add_custom_command(TARGET 2D-ARPG-TEST POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:2D-ARPG-TEST>/assets
)