cmake_minimum_required(VERSION 2.6.4)

project(soem)

SET( PROJ_SOURCE_DIR ${soem_SOURCE_DIR} )
SET( PROJ_BINARY_DIR ${soem_BINARY_DIR} )

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(DOC_STRING "The Operating System target. One of [linux rtw win32 xenomai]")
set(SOEM_TARGET_ENV $ENV{SOEM_TARGET}) # MUST use helper variable, otherwise not picked up !!!
if( SOEM_TARGET_ENV )
  set(SOEM_TARGET ${SOEM_TARGET_ENV} CACHE STRING "${DOC_STRING}" FORCE)
  message( "Detected SOEM_TARGET environment variable. Using: ${SOEM_TARGET}")
else()
  if(NOT DEFINED SOEM_TARGET )
    if(MSVC)
      set(SOEM_TARGET win32 CACHE STRING "${DOC_STRING}")
    else()
      set(SOEM_TARGET linux CACHE STRING "${DOC_STRING}")
    endif()
  endif()
  message( "No SOEM_TARGET environment variable set. Using: ${SOEM_TARGET}")
endif()

# Setup flags for Xenomai
if(SOEM_TARGET STREQUAL "xenomai")

  find_package(Xenomai REQUIRED)

  add_definitions( -Wall )
  
  if(XENOMAI_FOUND)
  
    execute_process(COMMAND xeno-config --skin=native --cflags OUTPUT_VARIABLE XENO_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(COMMAND xeno-config --skin=native --ldflags OUTPUT_VARIABLE XENO_LDFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
    # Input for .pc and .cmake generated files:
    list(APPEND SOEM_INCLUDE_DIRS ${XENOMAI_INCLUDE_DIRS} ${PTHREAD_INCLUDE_DIRS})
    list(APPEND SOEM_LIBRARIES ${XENO_LDFLAGS})
    list(APPEND SOEM_DEFINITIONS "SOEM_TARGET=${SOEM_TARGET}")
    # Direct input only for .pc file:
    list(APPEND SOEM_USER_LDFLAGS ${XENO_LDFLAGS} )
    list(APPEND SOEM_USER_CFLAGS ${XENOMAI_CFLAGS} )
  endif()
endif()

INCLUDE_DIRECTORIES( ${SOEM_INCLUDE_DIRS} )

add_subdirectory(src)
add_subdirectory(test)
