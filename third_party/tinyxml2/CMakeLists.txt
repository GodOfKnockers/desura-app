add_definitions(-D_LIB)
add_library(tinyxml2 STATIC tinyxml2.cpp)

set(TINYXML_INCLUDEDIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(TINYXML_LIBRARIES tinyxml2 PARENT_SCOPE)

SET_PROPERTY(TARGET tinyxml2                PROPERTY FOLDER "ThirdParty")

if (WIN32)
	add_library(tinyxml2_s STATIC tinyxml2.cpp)
	set(TINYXML_LIBRARIES_S tinyxml2_s PARENT_SCOPE)
	SET_PROPERTY(TARGET tinyxml2_s PROPERTY FOLDER "ThirdParty")

	SetStaticRuntime(tinyxml2_s)
endif()
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Weffc++")
endif()
