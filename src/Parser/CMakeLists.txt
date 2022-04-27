set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/Parser)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Parser)

set (SRC
    ${SRC_ROOT}/IParser.hpp
    ${SRC_ROOT}/AParser.hpp
    ${SRC_ROOT}/AParser.cpp
    ${SRC_ROOT}/Parser.hpp
    ${SRC_ROOT}/Parser.cpp
)

add_library(${PORJECT_NAME}_parser ${SRC})
target_link_directories(${PROJECT_NAME}_parser
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)