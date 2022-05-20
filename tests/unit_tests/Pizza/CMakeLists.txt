set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Pizza)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Pizza)

set (SRC
    ${SRC_ROOT}/Pizza_test.cpp
)

create_test(
    TEST_NAME Pizza_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_pizza
)
