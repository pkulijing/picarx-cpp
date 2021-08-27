cmake_minimum_required(VERSION 3.10)

project(picar)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-psabi")

add_executable(servo_test
  component/servo_test.cpp
  common/flags.cpp
  i2c/smbus.c
)

target_include_directories(servo_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(servo_test PUBLIC cxx_std_11)
target_link_libraries(servo_test
  glog
  gflags
)

add_executable(motor_test
  component/motor_test.cpp
  common/flags.cpp
  i2c/smbus.c
)

target_include_directories(motor_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(motor_test PUBLIC cxx_std_11)
target_link_libraries(motor_test
  glog
  gflags
  wiringPi
)

add_executable(picar_test
  car/picar_test.cpp
  common/flags.cpp
  i2c/smbus.c
)

target_include_directories(picar_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(picar_test PUBLIC cxx_std_11)
target_link_libraries(picar_test
  glog
  gflags
  wiringPi
)


add_executable(joystick_test
  joystick/joystick_test.cpp
)

target_include_directories(joystick_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(joystick_test PUBLIC cxx_std_11)
target_link_libraries(joystick_test
  glog
)

add_executable(remote_control_car
  remote_control_car_test.cpp
  common/flags.cpp
  i2c/smbus.c
)

target_include_directories(remote_control_car PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(remote_control_car PUBLIC cxx_std_11)
target_link_libraries(remote_control_car
  glog
  gflags
  wiringPi
)
