cmake_minimum_required(VERSION 3.10)

project(mc-shell)

file(GLOB SOURCES "*.cpp" "*.h")
add_executable(mc-shell ${SOURCES})

set_target_properties(mc-shell PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED True
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
pkg_check_modules(VTE vte-2.91 REQUIRED)

target_include_directories(mc-shell PUBLIC ${GTKMM_INCLUDE_DIRS} ${VTE_INCLUDE_DIRS})
target_link_libraries(mc-shell ${GTKMM_LIBRARIES} ${VTE_LIBRARIES})
