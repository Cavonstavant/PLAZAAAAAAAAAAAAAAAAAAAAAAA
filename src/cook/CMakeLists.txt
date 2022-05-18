set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/cook)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src/cook)

set(SRC
    ${SRC_ROOT}/Cook.cpp
    ${SRC_ROOT}/Cook.hpp
)

add_library(${PROJECT_NAME}_cook ${SRC})

target_include_directories(${PROJECT_NAME}_cook
    PRIVATE ${SRC_ROOT}
    PUBLIC ${INCLUDE_ROOT}
)

target_link_libraries(${PROJECT_NAME}_cook
    PUBLIC ${PROJECT_NAME}_logger
    PRIVATE ${PROJECT_NAME}_Core
)
