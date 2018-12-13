set (core_sources
  distance.cpp
  ellipsoid.cpp
  nuage.cpp
  quaternion.cpp)

set (core_headers
  distance.h
  ellipsoid.h
  mode.h
  nuage.h
  quaternion.h)

add_library(datura_core ${core_sources} ${core_headers})

target_include_directories(datura_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Datura/core>)

target_link_libraries(datura_core PUBLIC
  glm)
