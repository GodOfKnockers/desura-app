include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB_RECURSE Sources ../*.h)

add_library(include_headers STATIC ${Sources})
SET_PROPERTY(TARGET include_headers PROPERTY FOLDER "Common")
set_target_properties(include_headers PROPERTIES LINKER_LANGUAGE CXX)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Weffc++")
endif()
