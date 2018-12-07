set( gui_sources
  mainwindow.cpp
  modelvisu.cpp)


qt5_wrap_cpp( gui_moc_headers
   mainwindow.h
   modelvisu.h)


qt5_wrap_ui( gui_ui
    ui/mainwindow.ui)


add_library(datura_gui ${gui_sources}  ${gui_ui}
                      ${gui_moc_headers})

target_include_directories(datura_gui PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

target_include_directories(datura_gui PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/Datura/gui)

target_link_libraries(datura_gui PUBLIC
  Qt5::Widgets
  Qt5::Gui
  Qt5::OpenGL
  GLEW::GLEW
  ${OPENGL_LIBRARIES}
  datura_core
  OpenGLShader
  OpenGLMeshRender)
