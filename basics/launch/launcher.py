# Copyright 2022 csanrod
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # LAUNCH DESCRIPTION
    # Objeto que se va a retornar, contiene todo lo que se va a lanzar
    ld = LaunchDescription()

    # Declaramos el nodo, aquí se hacen los remappings, el paso de parámetros, etc.
    mynode = Node(
        package='basics',                 		# PKG al que pertenece el nodo que vamos a ejecutar
        executable='main_class_node',		    # Nombre del ejecutable
        output='screen'
        )

    # Para añadir cada nodo en cuestion
    ld.add_action(mynode)

    # Se retorna el LD entero
    return ld
