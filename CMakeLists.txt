cmake_minimum_required(VERSION 2.8.3)
project(soem)

catkin_package(
	INCLUDE_DIRS src/soem src/osal src/oshw/${OROCOS_TARGET})

include_directories(include ${catkin_INCLUDE_DIRS} ${BOOST_INCLUDE_DIRS} src/oshw/${OROCOS_TARGET} src/osal/${OROCOS_TARGET} src/soem src/osal)

add_library(${PROJECT_NAME} SHARED src/osal/${OROCOS_TARGET}/osal.c src/oshw/${OROCOS_TARGET}/nicdrv.c src/oshw/${OROCOS_TARGET}/oshw.c src/soem/ethercatbase.c src/soem/ethercatcoe.c src/soem/ethercatconfig.c src/soem/ethercatdc.c src/soem/ethercatfoe.c src/soem/ethercatmain.c src/soem/ethercatprint.c src/soem/ethercatsoe.c)

#Start of user code user_build
if(${OROCOS_TARGET} STREQUAL "xenomai" )
# message("Found RTNET: ${RTNET_INCLUDE_DIR}")
# message("XENOMAI_INCLUDE_DIRS: ${XENOMAI_INCLUDE_DIRS}")
# include_directories(${RTNET_INCLUDE_DIR})
  add_definitions(-DHAVE_RTNET)
  # try Xenomai
  execute_process(COMMAND xeno-config --skin=posix --cflags OUTPUT_VARIABLE XENO_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
  execute_process(COMMAND xeno-config --skin=posix --ldflags OUTPUT_VARIABLE XENO_LDFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${XENO_CFLAGS} -DXENOMAI -I/usr/local/rtnet/include")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${XENO_LDFLAGS}")
  orocos_add_compile_flags(${PROJECT_NAME} ${XENO_CFLAGS})
  orocos_add_link_flags(${PROJECT_NAME} ${XENO_LDFLAGS})
  TARGET_LINK_LIBRARIES(${PROJECT_NAME} "-lrtdm")

endif()
#End of user code

