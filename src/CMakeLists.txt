set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(MessageQueue)

set (TARGET_ARCHIVE_SRC
     ${MESSAGE_QUEUE_SRC}
)

add_library(${PROJECT_NAME}_core SHARED ${TARGET_ARCHIVE_SRC})

target_link_libraries(${PROJECT_NAME}_core
    ${PROJECT_NAME}_logger
    ${PROJECT_NAME}_parser
)

target_include_directories(${PROJECT_NAME}_core
   PRIVATE ${INCLUDE_ROOT}
)

set (TARGET_SRC
    ${SRC_ROOT}/main.cpp
)

add_executable(${PROJECT_NAME} ${TARGET_SRC})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_core)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_subdirectory(logger)
add_subdirectory(Parser)