#include <chrono>
#include <gflags/gflags.h>
#include <iostream>
#include <thread>
#include <vector>

#include "common/flags.hpp"
#include "common/log.hpp"
#include "component/servo.hpp"

int main(int argc, char **argv) {
  FLAGS_alsologtostderr = true;
  google::InitGoogleLogging(argv[0]);

  std::vector<Servo> servos;
  servos.emplace_back(FLAGS_channel_servo_cam_yaw, FLAGS_cam_yaw_max_angle,
                      "cam_yaw");
  servos.emplace_back(FLAGS_channel_servo_cam_pitch, FLAGS_cam_pitch_max_angle,
                      "cam_pitch");
  servos.emplace_back(FLAGS_channel_servo_dir, FLAGS_dir_max_angle, "dir");

  for (int i = 0; i < servos.size(); i++) {
    int ret = servos[i].Init();
    if (ret != 0) {
      LOG_ERROR << "servo " << i << " init err: " << ret;
      return ret;
    }
  }

  int id, angle;
  while (std::cin >> id >> angle) {
    if (id > 1000) {
      break;
    }
    LOG_INFO << "set servo " << id << " angle to " << angle;
    servos[id].SetAngle(angle);
  }

  return 0;
}