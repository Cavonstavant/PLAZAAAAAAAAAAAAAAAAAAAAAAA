set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/Parser)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Parser)
set (ARG_ROOT ${SRC_ROOT}/ArgumentsParser)
set (INP_ROOT ${SRC_ROOT}/InputParser)

set (SRC
    ${SRC_ROOT}/IParser.hpp
    ${SRC_ROOT}/AParser.hpp
    ${SRC_ROOT}/AParser.cpp
    ${INP_ROOT}/InputParser.hpp
    ${INP_ROOT}/InputParser.cpp
    ${ARG_ROOT}/ArgumentsParser.hpp
    ${ARG_ROOT}/ArgumentsParser.cpp
)

add_library(${PROJECT_NAME}_parser ${SRC})

target_include_directories(${PROJECT_NAME}_parser
    PRIVATE ${SRC_ROOT}
    PUBLIC ${SRC_ROOT}
    PUBLIC ${ARG_ROOT}
    PUBLIC ${INP_ROOT}
)
target_link_libraries(${PROJECT_NAME}_parser
    PRIVATE ${PROJECT_NAME}_logger
)