cmake_minimum_required(VERSION 3.5)

project(sportcarplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sportcarplus main.cpp)

include(GNUInstallDirs)
install(TARGETS sportcarplus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
