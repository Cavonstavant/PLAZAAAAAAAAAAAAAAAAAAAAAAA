set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/logger)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/logger)

set (SRC
    ${SRC_ROOT}/Exception.cpp
    ${SRC_ROOT}/Exception.hpp
    ${SRC_ROOT}/Logger.cpp
    ${SRC_ROOT}/Logger.hpp
)

add_library(${PROJECT_NAME}_logger ${SRC})
target_include_directories(${PROJECT_NAME}_logger
    PUBLIC ${INCLUDE_ROOT}
    PRIVATE ${SRC_ROOT}
)
