cmake_minimum_required(VERSION 3.16)
project(autonomous_drone_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(DRONE_SIM_BUILD_TESTS "Build unit tests" ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

include(FetchContent)

# --- Eigen (header-only linear algebra, used by the Kalman filter) ---
find_package(Eigen3 3.3 QUIET NO_MODULE)
if(NOT TARGET Eigen3::Eigen)
    message(STATUS "Eigen3 not found locally; fetching it")
    FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.4.0
        GIT_SHALLOW TRUE
    )
    set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
    set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(eigen)
endif()

# --- Core simulation library shared by every phase executable ---
add_library(drone_sim
    src/core/Vector2D.cpp
    src/core/State.cpp
    src/simulation/World.cpp
    src/simulation/Target.cpp
    src/simulation/Drone.cpp
    src/sensors/NoiseModel.cpp
    src/sensors/VirtualSensor.cpp
    src/estimation/KalmanFilter.cpp
    src/control/Controller.cpp
    src/control/Trajectory.cpp
    visualization/DataLogger.cpp
    visualization/Plotter.cpp
)

target_include_directories(drone_sim PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/visualization
)

target_link_libraries(drone_sim PUBLIC Eigen3::Eigen)

if(MSVC)
    target_compile_options(drone_sim PRIVATE /W4)
else()
    target_compile_options(drone_sim PRIVATE -Wall -Wextra -Wpedantic)
endif()

# --- One executable per phase ---
set(PHASE_TARGETS
    phase1_world
    phase2_sensor
    phase3_kalman
    phase4_visualization
    phase5_loss
    phase6_drone
    phase7_control
    phase8_prediction
)

foreach(phase ${PHASE_TARGETS})
    add_executable(${phase} phases/${phase}.cpp)
    target_link_libraries(${phase} PRIVATE drone_sim)
endforeach()

# Results directory expected by the loggers/plotters.
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data/results)

if(DRONE_SIM_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
