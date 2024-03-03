cmake_minimum_required(VERSION 3.10)
project(mc-shell)

if(NOT DEFINED MC_PATH)
    set(MC_PATH "/usr/bin/mc" CACHE STRING "Midnight Commander binary path" FORCE)
endif()

find_program(MC "${MC_PATH}" REQUIRED)
message(STATUS "Using Midnight Commander binary: ${MC}")

configure_file(
    "${CMAKE_SOURCE_DIR}/src/constants-impl.hpp.in" 
    "${CMAKE_BINARY_DIR}/src/constants-impl.hpp" 
    @ONLY)


file(GLOB SOURCES "src/*.cpp" "src/*.hpp" "${CMAKE_BINARY_DIR}/src/*.hpp")
add_executable(mc-shell ${SOURCES})

set_target_properties(mc-shell PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED True
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
pkg_check_modules(VTE vte-2.91 REQUIRED)

target_include_directories(mc-shell PUBLIC ${GTKMM_INCLUDE_DIRS} ${VTE_INCLUDE_DIRS})
target_link_libraries(mc-shell ${GTKMM_LIBRARIES} ${VTE_LIBRARIES})
