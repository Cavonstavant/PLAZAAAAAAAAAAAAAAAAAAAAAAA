set (INCLUDE_ROOT ${PROJECT_NAME}/tests/unit_tests/Parser)
set (SRC_ROOT ${PROJECT_NAME}/tests/unit_tests/Parser)

set (SRC
)

create_test(
    TEST_NAME Parser_tests
    SRC ${SRC}
    DEPS ${PROJECT_NAME}_parser
)