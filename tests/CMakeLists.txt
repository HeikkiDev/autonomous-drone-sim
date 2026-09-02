include(FetchContent)

find_package(GTest QUIET)
if(NOT TARGET GTest::gtest_main)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
        GIT_SHALLOW TRUE
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

include(GoogleTest)

set(TEST_SOURCES
    test_vector2d.cpp
    test_sensor.cpp
    test_kalman.cpp
    test_control.cpp
    test_integration.cpp
)

foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})
    target_link_libraries(${test_name} PRIVATE drone_sim GTest::gtest_main)
    gtest_discover_tests(${test_name})
endforeach()
