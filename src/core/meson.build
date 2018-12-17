core_sources = files(['autotrans.cpp',
                      'distance.cpp',
                      'ellipsoid.cpp',
                      'manualtrans.cpp',
                      'nuage.cpp',
                      'pca.cpp',
                      'pcaauto.cpp',
                      'pcafactory.cpp',
                      'pcamanual.cpp',
                      'quaternion.cpp',
                      'transformation.cpp',
                      'transformationfactory.cpp',
                      'transformationimpl.cpp'])


core_headers = files(['autotrans.h',
                      'barycenter.h',
                      'constants.h',
                      'distance.h',
                      'ellipsoid.h',
                      'manualtrans.h',
                      'mode.h',
                      'nuage.h',
                      'pca.h',
                      'pcaauto.h',
                      'pcafactory.h',
                      'pcaimpl.h',
                      'pcamanual.h',
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
