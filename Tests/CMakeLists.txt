link_directories (${CMAKE_SOURCE_DIR}/JKit)
add_executable (test-file File.cpp)
target_link_libraries (test-file jkit)
