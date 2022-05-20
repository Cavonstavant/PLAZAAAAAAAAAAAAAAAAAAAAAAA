set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core/Pizza)
set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/Core/Pizza)

set (SRC
    ${SRC_ROOT}/Pizza.hpp
    ${SRC_ROOT}/Pizza.cpp
)

add_library(${PROJECT_NAME}_pizza ${SRC})

target_link_libraries(${PROJECT_NAME}_pizza
    PUBLIC ${PROJECT_NAME}_logger
)

target_include_directories(${PROJECT_NAME}_pizza
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)
