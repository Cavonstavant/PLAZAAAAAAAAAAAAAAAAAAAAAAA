set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Parser)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Parser)

set (SRC
    ${SRC_ROOT}/Parser_test.cpp
)

create_test(
    TEST_NAME Parser_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_parser
)
