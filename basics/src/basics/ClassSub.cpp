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
#include "basics/ClassSub.hpp"

namespace basics
{

MyCustomSub::MyCustomSub(const std::string & name)
: Node(name)
{
  // SUSCRIPTOR

  // hay que bindearlo (retorna la dirección de memoria)
  // + placeholders (previamente definidos)
  sub_ = create_subscription<std_msgs::msg::String>(
    "topic_del_publicador", 10, std::bind(&MyCustomSub::subscriber_callback, this, _1));
}

void
MyCustomSub::subscriber_callback(const std_msgs::msg::String::SharedPtr msg) const
{
  RCLCPP_INFO(
    this->get_logger(), "Receiving: [%s]", msg->data.c_str());
}

}  // namespace basics
