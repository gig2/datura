sourcesFiles = files(['main.cpp'])

subdir('core')
subdir('gui')

executable('datura', sourcesFiles,
           dependencies: [datura_gui_dep
                          ],
           include_directories: includeDir)

