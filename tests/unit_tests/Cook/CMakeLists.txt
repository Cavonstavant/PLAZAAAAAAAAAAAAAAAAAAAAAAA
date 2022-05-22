set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Cook)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Cook)

set(SRC
    ${SRC_ROOT}/Cook_test.cpp
)

create_test(
    TEST_NAME Cook_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_cook
)
