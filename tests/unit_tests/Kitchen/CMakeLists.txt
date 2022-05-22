set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Kitchen)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Kitchen)

set(SRC
    ${SRC_ROOT}/Kitchen_test.cpp
)

create_test(
    TEST_NAME Kitchen_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_kitchen
)
