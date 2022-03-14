cmake_minimum_required (VERSION 3.13)

project (mudc
  VERSION 0.0.1
  DESCRIPTION "Modern utilities and datatypes for C."
  HOMEPAGE_URL "https://github.com/senkaru/mudc"
  LANGUAGES C
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set (PROJECT_NAME "mudc")
set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)

add_library (${PROJECT_NAME} INTERFACE)

include (cmake/CompileOptions.cmake)

target_include_directories (${PROJECT_NAME}
  INTERFACE
    "./include"
)

install (TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

if (BUILD_TESTING)
  add_subdirectory ("./test")
endif (BUILD_TESTING)
