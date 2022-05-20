set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/Core/Cook)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core/Cook)

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
    PRIVATE ${PROJECT_NAME}_pizza
)
