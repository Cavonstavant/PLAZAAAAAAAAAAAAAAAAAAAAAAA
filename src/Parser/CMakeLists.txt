set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/Parser)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Parser)

set (SRC
    ${SRC_ROOT}/IParser.hpp
    ${SRC_ROOT}/AParser.hpp
    ${SRC_ROOT}/AParser.cpp
    ${SRC_ROOT}/InputParser.cpp
    ${SRC_ROOT}/InputParser.hpp
)

add_library(${PROJECT_NAME}_parser ${SRC})
target_link_directories(${PROJECT_NAME}_parser
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)
