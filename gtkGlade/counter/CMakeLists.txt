cmake_minimum_required(VERSION 3.10.0)

project(window)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MAJOR 0)

set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

find_package (PkgConfig)
if (PKG_CONFIG_FOUND)
    pkg_check_modules (GTK "gtk+-3.0")
    if (GTK_FOUND)
        add_executable(window "")
        target_sources(window
            PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/src/main.c
            ${CMAKE_CURRENT_LIST_DIR}/glade
        )
        target_link_libraries(window PUBLIC ${GTK_LIBRARIES})
        # add_definitions(-DGLADE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/glade/window.glade")
        add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
    endif()
endif()

add_custom_command(TARGET window POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/glade ${CMAKE_BINARY_DIR}/bin/glade)


