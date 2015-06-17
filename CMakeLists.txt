cmake_minimum_required( VERSION 2.8.4 )

project( LISP )

#find_package( Combine )

set( CMAKE_CXX_FLAGS "-std=c++1y -Wall -Werror -Wno-unused-variable" )


option( BUILD_TESTS "Build the tests?" ON )
option( USE_SYSTEM_COMBINE "Use the system's Combine library?" ON )
option( MAKE_COMBINE_SUBSIDIARY "Install Combine as a subsidiary library?" OFF )

set( COMBINE_INCLUDE_DIR "/usr/local/include" )
set( CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${COMBINE_INCLUDE_DIR}/combine/cmake
  ${CMAKE_MODULE_PATH} )

configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/lisp/import.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/lisp/import.hpp )
configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/lisp/config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/lisp/config.hpp )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} )

if( BUILD_TESTS )
  
  enable_testing()
  
  include( simple_test )
  
  add_simplest_test( easy )
  add_simplest_test( cons )
  add_simplest_test( list )
  add_simplest_test( expr )
  add_simplest_test( quote )
  add_simplest_test( symbol )

  
endif()