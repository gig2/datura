set (core_sources)

set (core_headers)

add_library(datura_core ${core_sources} ${core_headers})

target_include_directories(datura_core PUBLIC
  $<BUILD_INTERFACE:${OPENMESH_INCLUDE_DIRS}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Datura/core>)

target_link_libraries(datura_core PUBLIC
  glm)
