add_executable(shell-app main.cpp pid.cpp ackerman_sim.cpp ackerman_controller.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
