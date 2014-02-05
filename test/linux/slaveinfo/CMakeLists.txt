
add_executable(slaveinfo slaveinfo.c)
target_link_libraries(slaveinfo soem m rt c pq pthread)
