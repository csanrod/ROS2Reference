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

#include <string>
#include "basics/ClassNode.hpp"

namespace basics
{

using std::placeholders::_1;

MyCustomNode::MyCustomNode(const std::string & name, const std::chrono::nanoseconds & rate)
: Node(name)
{
  pub_ = create_publisher<std_msgs::msg::String>("topic_del_publicador", 10);

  timer_ = create_wall_timer(
    rate, std::bind(&MyCustomNode::say_hello_callback, this));
}

void
MyCustomNode::say_hello_callback(void)
{
  std_msgs::msg::String msg;
  std::string node_name = get_name();
  msg.data = "Hello from " + node_name;
  RCLCPP_INFO(get_logger(), "Publishing [%s]", msg.data.c_str());
  pub_->publish(msg);
}

}  // namespace basics
