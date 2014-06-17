set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package(OpenCL REQUIRED)
include_directories(${OPENCL_INCLUDE_DIRS})
if(NOT OPENCL_FOUND) 
    message(ERROR " OPENCL not found!")
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR})