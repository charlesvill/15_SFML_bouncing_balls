cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(barkeshli_s22)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# . . . . . . . . . . . . . . . . . . . .
include(GNUInstallDirs)

if(MSVC)
    add_compile_options(/W4)
    add_link_options(/W4)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

# place binaries and libraries according to GNU standards
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# . . . . . . . . . . . . . . . . . . . .

# ------------------------------------
include(FetchContent)

# ---- googletest ----
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ---- SFML (downloaded and built from source) ----
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE) # static: no .dylib/.dll to copy around
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE) # not used; avoids extra dependencies
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE) # not used
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    SFML
    URL https://github.com/SFML/SFML/archive/refs/tags/2.6.2.zip
)
FetchContent_MakeAvailable(SFML)

enable_testing()

# ------------------------------------

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Grab all cpp files from includes folder
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${INCLUDES_FOLDER}/*.cpp")

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ADD_EXECUTABLE(main
    main.cpp
    ${SOURCE_FILES}
)

ADD_EXECUTABLE(basic_test
    _tests/_test_files/basic_test.cpp
    ${SOURCE_FILES}
)

ADD_EXECUTABLE(testB
    _tests/_test_files/testB.cpp
    ${SOURCE_FILES}
)

TARGET_LINK_LIBRARIES(main gtest sfml-graphics sfml-window sfml-system)
TARGET_LINK_LIBRARIES(basic_test gtest sfml-graphics sfml-window sfml-system)
TARGET_LINK_LIBRARIES(testB gtest sfml-graphics sfml-window sfml-system)


