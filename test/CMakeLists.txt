cmake_minimum_required(VERSION 3.14)

project(rediscppTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(rediscpp REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(rediscpp_test source/rediscpp_test.cpp)
target_link_libraries(
    rediscpp_test PRIVATE
    rediscpp::rediscpp
    Catch2::Catch2WithMain
)
target_compile_features(rediscpp_test PRIVATE cxx_std_17)

catch_discover_tests(rediscpp_test)

# ---- End-of-file commands ----

add_folders(Test)
