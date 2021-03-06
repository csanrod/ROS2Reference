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

#ifndef BASICS__CLASSSUB_HPP_
#define BASICS__CLASSSUB_HPP_

#include <string>

// Mensajes de ROS2 para publicar/subscribirse en los topics
#include "rclcpp/rclcpp.hpp"
// Minúscula y con barra baja, LaserScan => laser_scan
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

namespace basics
{

class MyCustomSub : public rclcpp::Node
{
public:
  // Constructor (nombre_del_nodo)
  explicit MyCustomSub(const std::string & name);

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  // No cambia el estado del objeto, por eso es const
  void subscriber_callback(const std_msgs::msg::String::SharedPtr msg) const;
};

}  // namespace basics

#endif  // BASICS__CLASSSUB_HPP_
