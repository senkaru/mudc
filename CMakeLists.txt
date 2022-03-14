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

add_library (${PROJECT_NAME}_STATIC STATIC "src/mudc.c")
CCompileOptions(${PROJECT_NAME}_STATIC PRIVATE ON)
target_include_directories (${PROJECT_NAME}_STATIC
  PUBLIC
    "./include"
)

# add_executable (${PROJECT_NAME}_TEST "./src/mudc.c")
# target_link_libraries (${PROJECT_NAME}_TEST PRIVATE ${PROJECT_NAME})

install (TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
install (TARGETS ${PROJECT_NAME}_STATIC EXPORT ${PROJECT_NAME}_STATICTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

if (BUILD_TESTING)
  add_subdirectory ("./test")
endif (BUILD_TESTING)
