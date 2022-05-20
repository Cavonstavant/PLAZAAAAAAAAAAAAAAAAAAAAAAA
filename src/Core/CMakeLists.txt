set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)
set (INC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)

add_subdirectory(Cook)
add_subdirectory(Kitchen)
add_subdirectory(Parser)
add_subdirectory(Pizza)

set(SRC
    ${SRC_ROOT}/Plazza.cpp
    ${SRC_ROOT}/Plazza.hpp
)

add_library(${PROJECT_NAME}_core SHARED ${SRC})

target_include_directories(${PROJECT_NAME}_core
    PUBLIC ${INC_ROOT}
    PRIVATE ${SRC_ROOT}
)

target_link_libraries(${PROJECT_NAME}_core
    PUBLIC ${PROJECT_NAME}_parser
    PUBLIC ${PROJECT_NAME}_kitchen
    # PUBLIC ${PROJECT_NAME}_cook
    PRIVATE pthread
)
