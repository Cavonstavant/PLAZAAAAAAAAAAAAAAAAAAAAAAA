set (INCLUDE_ROOT ${PROJECT_NAME}/tests/unit_tests/Parser)
set (SRC_ROOT ${PROJECT_NAME}/tests/unit_tests/Parser)

set (SRC
)

create_test(
    TEST_NAME Parser_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_parser
)
