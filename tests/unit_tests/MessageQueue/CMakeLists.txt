set(INCLUDE_ROOT ${PROJECT_NAME}/tests/unit_tests/MessageQueue)
set(SRC_ROOT ${PROJECT_NAME}/tests/unit_tests/MessageQueue)

set(SRC
    ${SRC_ROOT}/MessageQueue_test.cpp
)

create_test(
        TEST_NAME MessageQueue_tests
        TEST_SRC ${SRC}
        DEPS ${PROJECT_NAME}_core
)