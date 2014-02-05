cmake_minimum_required(VERSION 2.6.4)

project(soem)

SET( PROJ_SOURCE_DIR ${soem_SOURCE_DIR} )
SET( PROJ_BINARY_DIR ${soem_BINARY_DIR} )

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

add_subdirectory(src)
add_subdirectory(test)
