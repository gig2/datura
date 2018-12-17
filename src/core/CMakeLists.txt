set (core_sources
  autotrans.cpp
  distance.cpp
  ellipsoid.cpp
  nuage.cpp
  quaternion.cpp
  transformation.cpp
  transformationfactory.cpp
  transformationimpl.cpp
  manualtrans.cpp)

set (core_headers
  autotrans.h
  constants.h
  distance.h
  ellipsoid.h
  mode.h
  nuage.h
  quaternion.h
  transformation.h
  transformationfactory.h
  transformationimpl.h
  manualtrans.h)

add_library(datura_core ${core_sources} ${core_headers})

target_include_directories(datura_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Datura/core>)

target_link_libraries(datura_core PUBLIC
  glm)
