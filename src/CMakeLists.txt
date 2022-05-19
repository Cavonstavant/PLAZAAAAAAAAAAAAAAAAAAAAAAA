set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src)
# set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(MessageQueue)
add_subdirectory(Logger)
add_subdirectory(Core)

set (TARGET_SRC
    ${SRC_ROOT}/main.cpp
)

add_executable(${PROJECT_NAME} ${TARGET_SRC})

target_link_libraries(${PROJECT_NAME}
    PUBLIC ${PROJECT_NAME}_core
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

# target_link_libraries(${PROJECT_NAME}_mainLib
#     PUBLIC ${PROJECT_NAME}_logger
#     PUBLIC ${PROJECT_NAME}_parser
#     PUBLIC ${PROJECT_NAME}_core
#     PUBLIC ${PROJECT_NAME}_messageQueue
# )

# add_library(${PROJECT_NAME}_mainLib SHARED ${TARGET_SRC})

# target_include_directories(${PROJECT_NAME}_mainLib
#    PUBLIC ${INCLUDE_ROOT}
# )

#


# set (TARGET_ARCHIVE_SRC
#      ${MESSAGE_QUEUE_SRC}
# )

# set(INC_QUEUE_ROOT ${INCLUDE_ROOT}/MessageQueue)

# add_library(${PROJECT_NAME}_messageQueue SHARED ${TARGET_ARCHIVE_SRC})

# target_link_libraries(${PROJECT_NAME}_messageQueue
#     PUBLIC ${PROJECT_NAME}_logger
# )

# target_include_directories(${PROJECT_NAME}_messageQueue
#    PUBLIC ${INCLUDE_ROOT}/MessageQueue
# )




# target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_mainLib)

