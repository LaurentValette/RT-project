get_filename_component(DIR ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${DIR})
add_executable(${DIR} 

main.cpp
primitives.hpp
primitives.cpp
)

target_link_libraries(${DIR} ${OPENCL_LIBRARIES})
