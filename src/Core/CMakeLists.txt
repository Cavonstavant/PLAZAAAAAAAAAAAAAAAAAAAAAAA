set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)
set (INC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)

add_subdirectory(Kitchen)

set(SRC
    ${SRC_ROOT}/Plazza.cpp
    ${SRC_ROOT}/Plazza.hpp
    ${SRC_ROOT}/Pizza.hpp
    ${KITCHEN_SRC}
)

add_library(${PROJECT_NAME}_Core ${SRC})
target_include_directories(${PROJECT_NAME}_Core
    PUBLIC ${INC_ROOT}
    PRIVATE ${SRC_ROOT}
    PUBLIC ${INC_ROOT}/Kitchen
)
target_link_libraries(${PROJECT_NAME}_Core
    PRIVATE ${PROJECT_NAME}_parser
    PRIVATE pthread
)
