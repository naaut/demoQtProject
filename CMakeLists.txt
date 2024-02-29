cmake_minimum_required(VERSION 3.16)

project(QmlInjectorCore VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/qmlinjector)
add_subdirectory(src/data)
add_subdirectory(src/interfaces)
add_subdirectory(src/qmlapp)

