set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Logger)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Logger)

set(SRC
    ${SRC_ROOT}/Logger_test.cpp
)

create_test(
    TEST_NAME Logger_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_logger
)
