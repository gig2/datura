set (core_sources
  autotrans.cpp
  distance.cpp
  ellipsoid.cpp
  manualtrans.cpp
  nuage.cpp
  pca.cpp
  pcaauto.cpp
  pcafactory.cpp
  pcamanual.cpp
  quaternion.cpp
  transformation.cpp
  transformationfactory.cpp
  transformationimpl.cpp)

set (core_headers
  autotrans.h
  barycenter.h
  constants.h
  distance.h
  ellipsoid.h
  manualtrans.h
  mode.h
  nuage.h
  pca.h
  pcaauto.h
  pcafactory.h
  pcaimpl.h
  pcamanual.h
  quaternion.h
  recenter.h
  transformation.h
  transformationfactory.h
  transformationimpl.h)

add_library(datura_core ${core_sources} ${core_headers})

target_include_directories(datura_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Datura/core>)

target_link_libraries(datura_core PUBLIC
  glm
  Eigen3::Eigen)
