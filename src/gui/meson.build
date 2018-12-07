gui_sources = files(['mainwindow.cpp',
                     'modelvisu.cpp'])


gui_moc_headers = files(['mainwindow.h',
                         'modelvisu.h'])

gui_ui = files(['ui/mainwindow.ui'])


gui_processed = qt5_mod.preprocess(
  moc_headers : [gui_moc_headers],
  ui_files : [gui_ui]
)


gui_include = include_directories('.')

datura_gui_lib = library('datura_gui',
                        sources: [gui_sources,
                               gui_moc_headers,
                               gui_processed],

        dependencies: [ qt5_widgets_dep,
                        qt5_gui_dep,
                        qt5_opengl_dep,
                        gl_dep,
                        datura_core_dep,
                        openglshader_dep,
                        openglmeshrender_dep]
        , include_directories: gui_include
                       )


datura_gui_dep = declare_dependency(link_with: datura_gui_lib,
                                    dependencies:
                                             [qt5_widgets_dep,
                                              qt5_gui_dep,
                                              qt5_opengl_dep,
                                              gl_dep,
                                              datura_core_dep,
                                              openglshader_dep,
                                              openglmeshrender_dep],
                                   include_directories: [gui_include])
