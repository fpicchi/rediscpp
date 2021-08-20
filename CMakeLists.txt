cmake_minimum_required(VERSION 3.14)

include(cmake/in-source-guard.cmake)

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
    rediscpp_rediscpp ${rediscpp_warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(rediscpp_rediscpp INTERFACE cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
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
