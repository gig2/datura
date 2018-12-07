set (sourcesFiles
    main.cpp)

add_subdirectory(core)
add_subdirectory(gui)


add_executable(datura ${sourcesFiles} )

target_include_directories(datura PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

target_link_libraries(datura PUBLIC
   datura_gui
    )
