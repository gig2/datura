core_sources = files([])

core_headers = files([])

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
