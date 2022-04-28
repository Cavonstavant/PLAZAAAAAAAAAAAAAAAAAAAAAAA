set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/src)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src)

set (SRC
    ${SRC_ROOT}/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_logger)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${INCLUDE_ROOT}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_subdirectory(logger)