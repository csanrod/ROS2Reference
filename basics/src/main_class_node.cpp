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

#include <memory>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "basics/ClassNode.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node_a = std::make_shared<basics::MyCustomNode>("nodo_A", 1s);
  auto node_b = std::make_shared<basics::MyCustomNode>("nodo_B", 500ms);
  rclcpp::executors::MultiThreadedExecutor executor;

  // Para lifecycle nodes:
  //      executor.add_node(node_a->get_node_base_interface());
  executor.add_node(node_a);
  executor.add_node(node_b);

  executor.spin();

  rclcpp::shutdown();
  return 0;
}
