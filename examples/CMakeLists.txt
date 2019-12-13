cmake_minimum_required(VERSION 3.2)

project(ProjestWithGTest)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)

# Test target
add_executable(
    test_assertions
    test/test_assertions.cpp
)
add_executable(
    test_fixtures
    test/test_fixtures.cpp
)
add_executable(
    test_mocks
    test/test_mocks.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    test_assertions PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_include_directories(
    test_fixtures PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_include_directories(
    test_mocks PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    test_assertions PRIVATE
    gtest gtest_main
)
target_link_libraries(
    test_fixtures PRIVATE
    gtest gtest_main
)
target_link_libraries(
    test_mocks PRIVATE
    gtest gtest_main gmock
)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        test_assertions PRIVATE
        /W4
    )
    target_compile_options(
        test_fixtures PRIVATE
        /W4
    )
    target_compile_options(
        test_mocks PRIVATE
        /W4
    )
else ()
    target_compile_options(
        test_assertions PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_fixtures PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_mocks PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()