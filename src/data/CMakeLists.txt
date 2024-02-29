find_package(Qt6 REQUIRED COMPONENTS
    Core
    Test
)

add_library(data STATIC)

target_include_directories(data
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(data
    PUBLIC
        Qt6::Core
        interfaces
)

target_sources(data
    PRIVATE
        include/data/ExampleInterfaceImpl.h
        src/ExampleInterfaceImpl.cpp
)

enable_testing()

add_executable(test_ExampleInterfaceImpl
    test/test_ExampleInterfaceImpl.cpp
)

add_test(NAME test_ExampleInterfaceImpl COMMAND test_ExampleInterfaceImpl)

target_link_libraries(test_ExampleInterfaceImpl
    PRIVATE
        Qt6::Test
        data
        interfaces
)
