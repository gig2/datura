core_sources = files(['distance.cpp',
                      'ellipsoid.cpp',
                      'nuage.cpp',
                      'quaternion.cpp',
                      'manualtrans.cpp',
                      'transformation.cpp',
                      'transformationfactory.cpp',
                      'transformationimpl.cpp'])


core_headers = files(['constants.h',
                      'distance.h',
                      'ellipsoid.h',
                      'mode.h',
                      'nuage.h',
                      'quaternion.h',
                      'manualtrans.h',
                      'transformation.h',
                      'transformationfactory.h',
                      'transformationimpl.h'])

core_include = include_directories('.')

datura_core_lib = library('datura_core',
                        sources: [core_sources,
                                  core_headers],

        dependencies: [ glm_dep]
        , include_directories: [core_include]
                       )


datura_core_dep = declare_dependency(link_with: datura_core_lib,
                                    dependencies: glm_dep,
                                   include_directories: [core_include])
