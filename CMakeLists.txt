cmake_minimum_required(VERSION 3.10)
project(mc-shell)

if(NOT DEFINED MC_PATH)
set(MC_PATH /usr/bin/mc CACHE STRING "Midnight Commander binary path" FORCE)
endif()

find_program(MC ${MC_PATH} REQUIRED)
message(STATUS "Using Midnight Commander binary: ${MC}")

configure_file(
    ${CMAKE_SOURCE_DIR}/src/constants-impl.hpp.in
    ${CMAKE_BINARY_DIR}/src/constants-impl.hpp
    @ONLY)
    
file(GLOB SOURCES src/*.cpp)
add_executable(mc-shell ${SOURCES})

set_target_properties(mc-shell PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED True
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
pkg_check_modules(VTE vte-2.91 REQUIRED)

target_include_directories(mc-shell PUBLIC ${CMAKE_BINARY_DIR}/src ${GTKMM_INCLUDE_DIRS} ${VTE_INCLUDE_DIRS})
target_link_libraries(mc-shell ${GTKMM_LIBRARIES} ${VTE_LIBRARIES})

set(CMAKE_INSTALL_PREFIX /usr)
configure_file(
    ${CMAKE_SOURCE_DIR}/install/mc-shell.desktop.in
    ${CMAKE_BINARY_DIR}/install/mc-shell.desktop
    @ONLY)

install(TARGETS mc-shell DESTINATION bin)
install(FILES ${CMAKE_BINARY_DIR}/install/mc-shell.desktop DESTINATION share/applications)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "mc-shell")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Simon Wendel")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "A simple shell for Midnight Commander")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libgtkmm-3.0-1v5, libvte-2.91-0")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
include(CPack)
