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
#include "basics/ClassPub.hpp"

namespace basics
{

MyCustomPub::MyCustomPub(const std::string & name, const std::chrono::nanoseconds & rate)
: Node(name)
{
  // PUBLICADOR

  // Se crea un puntero inteligente a un publisher que pertenece a node
  //    node -> método de node.
  //    <std_msgs::msg::String> --> interfaz del mensaje, debe estar en el include.
  //    nombre del topic donde se va a publicar
  //    tamaño de la cola
  //    QoS (nada = por defecto) --> rclcpp::QoS(10).transient_local().<lo_que_sea> (por defecto):
  //        volatil
  //        reliable (fiable, con reenvíos)

  pub_ = create_publisher<std_msgs::msg::String>("topic_del_publicador", 10);

  // Asignas callback ( ... , _1, _2) dos argumentos para el callback previo
  timer_ = create_wall_timer(
    rate, std::bind(&MyCustomPub::say_hello_callback, this));
}

void
MyCustomPub::say_hello_callback(void)
{
  std_msgs::msg::String msg;
  std::string node_name = get_name();
  msg.data = "Hello from " + node_name;

  // MACRO como un printf--> Cada nodo tiene un logger que debe especificarse de forma explícita.
  //    DEBUG
  //    WARN
  //    ERROR
  //    INFO_STREAM (te lo asemeja a un cout)

  RCLCPP_INFO(get_logger(), "Publishing [%s]", msg.data.c_str());
  pub_->publish(msg);
}

}  // namespace basics
