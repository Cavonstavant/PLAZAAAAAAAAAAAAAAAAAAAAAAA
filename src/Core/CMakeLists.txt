find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)
set (INC_ROOT ${PROJECT_SOURCE_DIR}/src/Core)


add_subdirectory(Cook)
add_subdirectory(Kitchen)
add_subdirectory(Parser)
add_subdirectory(Pizza)

set(SRC
    ${SRC_ROOT}/Plazza.cpp
    ${SRC_ROOT}/Plazza.hpp
    ${SRC_ROOT}/Bonus.cpp
    ${SRC_ROOT}/Bonus.hpp
)

add_library(${PROJECT_NAME}_core SHARED ${SRC})

target_include_directories(${PROJECT_NAME}_core
    PUBLIC ${INC_ROOT}
    PRIVATE ${SRC_ROOT}
)

target_link_libraries(${PROJECT_NAME}_core
    PUBLIC ${PROJECT_NAME}_parser
    PUBLIC ${PROJECT_NAME}_kitchen
    ${SFML_LIBRARIES}
    PRIVATE pthread
)
