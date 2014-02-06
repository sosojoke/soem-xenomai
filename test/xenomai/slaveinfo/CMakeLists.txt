
add_executable(slaveinfo slaveinfo.c)
target_link_libraries(slaveinfo soem ${SOEM_LIBRARIES} rtdm)
