add_executable(test-nuage
  main.cpp
  test_nuage.cpp
  )

target_include_directories(test-nuage PRIVATE
  $<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${gmock_SOURCE_DIR}/include>)

target_link_libraries(test-nuage PRIVATE
  datura_core
  gtest
  gmock)

add_test(NAME test-nuage COMMAND test-nuage
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
