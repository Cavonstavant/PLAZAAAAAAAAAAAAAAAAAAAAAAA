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
