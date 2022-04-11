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
#include "basics/ClassPub.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  // INIT --> del programa (con las precondiciones o parámetros)
  rclcpp::init(argc, argv);

  // DECLARACIÓN DE NODOS
  /*
  *  auto pone el tipo automáticamente al igualarlo a algo
  *  Espacio de nombres :: Clase :: Método (en este caso static)
  *  Puntero inteligente (puntero que libera la memoria automáticamente cuando no se usa)
  *
  *  std::shared_ptr<rclcpp::Node> node_a (new rclcpp::Node("my_node"));
  *  std::shared_ptr<rclcpp::Node> node_a = std::make_shared<rclcpp::Node>("my_node");
  *  rclcpp::Node::SharedPtr node_a = std::make_shared<rclcpp::Node>("my_node");
  *  auto node_a = std::make_shared<rclcpp::Node>("my_node");
  */

  auto node_a = std::make_shared<basics::MyCustomPub>("nodo_A", 1s);
  auto node_b = std::make_shared<basics::MyCustomPub>("nodo_B", 500ms);

  // EXECUTORS
  // Objetos encargados de ejecutar nodos (single/multi thread)

  rclcpp::executors::MultiThreadedExecutor executor;

  // Se añaden los nodos para hacerles spin.
  // Para lifecycle nodes:
  //      executor.add_node(node_a->get_node_base_interface());
  executor.add_node(node_a);
  executor.add_node(node_b);

  // Se queda bloqueado esperando los eventos.
  executor.spin();

  rclcpp::shutdown();
  return 0;
}
