cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    rediscpp
    VERSION 0.1.0
    DESCRIPTION "Redis CPP client"
    HOMEPAGE_URL "https://github.com/fpicchi/rediscpp"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(rediscpp_rediscpp INTERFACE)
add_library(rediscpp::rediscpp ALIAS rediscpp_rediscpp)

set_property(
    TARGET rediscpp_rediscpp PROPERTY
    EXPORT_NAME rediscpp
)

target_include_directories(
    rediscpp_rediscpp ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(rediscpp_rediscpp INTERFACE cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(rediscpp_rediscpp INTERFACE fmt::fmt)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${rediscpp_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT rediscpp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of rediscpp"
  )
endif()

include(cmake/dev-mode.cmake)
