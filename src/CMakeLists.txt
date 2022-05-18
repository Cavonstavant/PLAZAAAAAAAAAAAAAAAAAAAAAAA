set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(MessageQueue)

set (TARGET_ARCHIVE_SRC
     ${MESSAGE_QUEUE_SRC}
)

set(INC_QUEUE_ROOT ${INCLUDE_ROOT}/MessageQueue)

add_library(${PROJECT_NAME}_messageQueue SHARED ${TARGET_ARCHIVE_SRC})
target_link_libraries(${PROJECT_NAME}_messageQueue
    PUBLIC ${PROJECT_NAME}_logger
)

target_include_directories(${PROJECT_NAME}_messageQueue
   PUBLIC ${INCLUDE_ROOT}/MessageQueue
)

set (TARGET_SRC
    ${SRC_ROOT}/main.cpp
)

add_library(${PROJECT_NAME}_mainLib SHARED ${TARGET_SRC})

target_link_libraries(${PROJECT_NAME}_mainLib
    PUBLIC ${PROJECT_NAME}_logger
    PUBLIC ${PROJECT_NAME}_parser
    PUBLIC ${PROJECT_NAME}_Core
    PRIVATE rt
)

target_include_directories(${PROJECT_NAME}_mainLib
   PUBLIC ${INCLUDE_ROOT}
)

add_executable(${PROJECT_NAME} ${TARGET_SRC})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_mainLib)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_subdirectory(Logger)
add_subdirectory(Parser)
add_subdirectory(Core)
