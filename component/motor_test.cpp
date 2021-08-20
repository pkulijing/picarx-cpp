#include <chrono>
#include <gflags/gflags.h>
#include <iostream>
#include <thread>
#include <vector>
#include <wiringPi.h>

#include "common/flags.hpp"
#include "common/log.hpp"
#include "component/motor.hpp"

int main(int argc, char **argv) {
  FLAGS_alsologtostderr = true;
  google::InitGoogleLogging(argv[0]);
  wiringPiSetup();

  std::vector<Motor> motors;
  motors.emplace_back(FLAGS_channel_left_rear_speed,
                      FLAGS_channel_left_rear_dir, "left_rear");
  motors.emplace_back(FLAGS_channel_right_rear_speed,
                      FLAGS_channel_right_rear_dir, "right_rear");

  for (int i = 0; i < motors.size(); i++) {
    int ret = motors[i].Init();
    if (ret != 0) {
      LOG_ERROR << "motor " << i << " init err: " << ret;
      return ret;
    }
  }

  int id, speed;
  while (std::cin >> id >> speed) {
    if (id > 1000) {
      break;
    }
    LOG_INFO << "set motor " << id << " speed to " << speed;
    motors[id].SetSpeed(speed);
  }

  return 0;
}