set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test_ackerman_controller.cpp
    test_ackerman_sim.cpp
    test_pid.cpp
    ../app/ackerman_controller.cpp
    ../app/ackerman_sim.cpp
    ../app/pid.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest)
