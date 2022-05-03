set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)

set(SRC
    ${SRC_ROOT}/Plazza.cpp
    ${SRC_ROOT}/Plazza.hpp
)

add_library(${PROJECT_NAME}_Core ${SRC})
target_link_directories(${PROJECT_NAME}_Core
    PUBLIC ${SRC_ROOT}
    PRIVATE ${SRC_ROOT}
)