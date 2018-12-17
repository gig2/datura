core_sources = files(['autotrans.cpp',
                      'distance.cpp',
                      'ellipsoid.cpp',
                      'nuage.cpp',
                      'manualtrans.cpp',
                      'quaternion.cpp',
                      'transformation.cpp',
                      'transformationfactory.cpp',
                      'transformationimpl.cpp'])


core_headers = files(['autotrans.h',
                      'constants.h',
                      'distance.h',
                      'ellipsoid.h',
                      'mode.h',
                      'nuage.h',
                      'manualtrans.h',
                      'pca.h',
                      'pcaimpl.h',
                      'quaternion.h',
                      'recenter.h',
                      'transformation.h',
                      'transformationfactory.h',
                      'transformationimpl.h'])

core_include = include_directories('.')

datura_core_lib = library('datura_core',
                        sources: [core_sources,
                                  core_headers],

        dependencies: [ glm_dep, eigen_dep]
        , include_directories: [core_include]
                       )


datura_core_dep = declare_dependency(link_with: datura_core_lib,
                                    dependencies: [glm_dep, eigen_dep],
                                   include_directories: [core_include])
