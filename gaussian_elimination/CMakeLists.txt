include_directories(../headers)
add_executable(gaussian_elimination main.c)
target_link_libraries(gaussian_elimination la)