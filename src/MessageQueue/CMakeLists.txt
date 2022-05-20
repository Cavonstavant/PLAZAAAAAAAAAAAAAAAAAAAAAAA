set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src/MessageQueue)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/MessageQueue)

set (SRC
    ${SRC_ROOT}/MessageQueue.cpp
    ${SRC_ROOT}/MessageQueue.hpp
)

add_library(${PROJECT_NAME}_messageQueue ${SRC})

target_link_libraries(${PROJECT_NAME}_messageQueue
    PRIVATE ${PROJECT_NAME}_logger
    PRIVATE rt
)

target_include_directories(${PROJECT_NAME}_messageQueue
    PRIVATE ${SRC_ROOT}
    PUBLIC ${INCLUDE_ROOT}
)
