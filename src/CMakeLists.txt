
include_directories(oshw/linux osal/linux soem osal)
add_library(soem SHARED soem/ethercatbase.c soem/ethercatcoe.c soem/ethercatconfig.c soem/ethercatfoe.c soem/ethercatsoe.c soem/ethercatmain.c soem/ethercatprint.c oshw/${SOEM_TARGET}/nicdrv.c oshw/${SOEM_TARGET}/oshw.c osal/${SOEM_TARGET}/osal.c soem/ethercatdc.c)

