find_package(Qt6 REQUIRED COMPONENTS
    Core
)

add_library(interfaces STATIC)

target_include_directories(interfaces
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(interfaces
    PUBLIC
        Qt6::Core
)

target_sources(interfaces
    PRIVATE
        include/interfaces/IExampleInterface.h
)
