set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Core)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/Core)

set(SRC
    ${SRC_ROOT}/Core_test.cpp
)

create_test(
    TEST_NAME Core_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_Core
)
