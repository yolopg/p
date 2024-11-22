# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Music-cmake_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Music-cmake_autogen.dir\\ParseCache.txt"
  "Music-cmake_autogen"
  )
endif()
