project(flexpars) # project name

cmake_minimum_required(VERSION 2.4.0)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")

# dependencies
#FIND_PACKAGE(X11 REQUIRED) # find and setup X11

add_subdirectory(src) # tells cmake to process this directory

set_target_properties(flexpars PROPERTIES VERSION 0.03)

IF(UNIX)
	MESSAGE( STATUS "This is UNIX" )
ENDIF(UNIX)


# adding uninstall target
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_modules/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_modules/cmake_uninstall.cmake")
