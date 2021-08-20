cmake_minimum_required(VERSION 3.14)

project(rediscppTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/windows-set-path.cmake)

if(PROJECT_IS_TOP_LEVEL)
  find_package(rediscpp REQUIRED)
  enable_testing()
endif()

add_executable(rediscpp_test source/rediscpp_test.cpp)
target_link_libraries(rediscpp_test PRIVATE rediscpp::rediscpp)
target_compile_features(rediscpp_test PRIVATE cxx_std_20)

add_test(NAME rediscpp_test COMMAND rediscpp_test)
