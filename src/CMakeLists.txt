set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(MessageQueue)

set (TARGET_ARCHIVE_SRC
     ${MESSAGE_QUEUE_SRC}
)

add_library(${PROJECT_NAME}_core SHARED ${TARGET_ARCHIVE_SRC})

target_link_libraries(${PROJECT_NAME}_core
    PUBLIC ${PROJECT_NAME}_logger
    PUBLIC ${PROJECT_NAME}_parser
    PUBLIC ${PROJECT_NAME}_Core
    PRIVATE rt
)

target_include_directories(${PROJECT_NAME}_core
   PUBLIC ${INCLUDE_ROOT}
)

set (TARGET_SRC
    ${SRC_ROOT}/main.cpp
)

add_executable(${PROJECT_NAME} ${TARGET_SRC})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_core)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_subdirectory(Logger)
add_subdirectory(Parser)
add_subdirectory(cook)
add_subdirectory(Core)
