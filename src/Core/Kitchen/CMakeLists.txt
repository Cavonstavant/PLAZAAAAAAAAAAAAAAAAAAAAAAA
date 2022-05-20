set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core/Kitchen)
set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/Core/Kitchen)

set (SRC
    ${SRC_ROOT}/Kitchen.cpp
    ${SRC_ROOT}/Kitchen.hpp
)

add_library(${PROJECT_NAME}_kitchen ${SRC})

target_link_libraries(${PROJECT_NAME}_kitchen
    # PUBLIC ${PROJECT_NAME}_logger
    PUBLIC ${PROJECT_NAME}_messageQueue
    # PRIVATE ${PROJECT_NAME}_pizza
    PUBLIC ${PROJECT_NAME}_cook
)

target_include_directories(${PROJECT_NAME}_kitchen
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)
