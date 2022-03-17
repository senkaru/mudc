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

include (cmake/CCompileOptions.cmake)

add_library (${PROJECT_NAME} INTERFACE)
CCompileOptions(${PROJECT_NAME} INTERFACE ON)
target_include_directories (${PROJECT_NAME}
  INTERFACE
    "./include"
)

set (PROJECT_NAME_STATIC "${PROJECT_NAME}_static")
add_library (${PROJECT_NAME_STATIC} STATIC "src/mudc.c")
CCompileOptions(${PROJECT_NAME_STATIC} PRIVATE ON)
target_include_directories (${PROJECT_NAME_STATIC}
  PUBLIC
    "./include"
)

install (TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
install (TARGETS ${PROJECT_NAME_STATIC} EXPORT ${PROJECT_NAME_STATIC}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

if (BUILD_TESTING)
  add_subdirectory ("./test")
endif (BUILD_TESTING)
