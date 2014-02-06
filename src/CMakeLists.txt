
include_directories(oshw/linux osal/linux soem osal)
add_library(soem SHARED soem/ethercatbase.c soem/ethercatcoe.c soem/ethercatconfig.c soem/ethercatfoe.c soem/ethercatsoe.c soem/ethercatmain.c soem/ethercatprint.c oshw/${SOEM_TARGET}/nicdrv.c oshw/${SOEM_TARGET}/oshw.c osal/${SOEM_TARGET}/osal.c soem/ethercatdc.c)

install(TARGETS soem
  LIBRARY DESTINATION lib)

install(FILES soem/ethercatbase.h soem/ethercatcoe.h soem/ethercatconfig.h
  soem/ethercatconfiglist.h soem/ethercatdc.h soem/ethercatfoe.h
  soem/ethercatmain.h soem/ethercatprint.h soem/ethercatsoe.h
  soem/ethercattype.h oshw/${SOEM_TARGET}/nicdrv.h
  DESTINATION include/soem )
