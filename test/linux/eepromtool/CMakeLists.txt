
add_executable(eepromtool eepromtool.c)
target_link_libraries(eepromtool soem m rt c pq pthread)
