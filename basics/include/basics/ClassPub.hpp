// Copyright 2022 csanrod
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BASICS__CLASSPUB_HPP_
#define BASICS__CLASSPUB_HPP_

#include <string>
#include <chrono>

// Mensajes de ROS2 para publicar/subscribirse en los topics
#include "rclcpp/rclcpp.hpp"
// Minúscula y con barra baja, LaserScan => laser_scan
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

namespace basics
{

class MyCustomPub : public rclcpp::Node
{
public:
  // Constructor (nombre_del_nodo, rate_del_timer)
  MyCustomPub(const std::string & name, const std::chrono::nanoseconds & rate);

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  // Método del timer para publicar
  void say_hello_callback(void);
};

}  // namespace basics

#endif  // BASICS__CLASSPUB_HPP_
