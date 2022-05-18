set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/MessageQueue)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/MessageQueue)

set(SRC
    ${SRC_ROOT}/MessageQueue_test.cpp
)

create_test(
    TEST_NAME MessageQueue_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_messageQueue
)
