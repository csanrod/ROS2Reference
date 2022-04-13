cmake_minimum_required(VERSION 3.5)
project(basics)

# Para compilar en C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

# Se incluyen los paquetes usados
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Variable que recoge todas las dependencias de cada paquete
set(dependencies
    rclcpp
    std_msgs
)

# Incluimos los directorios
include_directories(include)

# Agregamos los modulos
add_library(${PROJECT_NAME} SHARED
    src/basics/ClassPub.cpp
    src/basics/ClassSub.cpp
)
ament_target_dependencies(${PROJECT_NAME} ${dependencies})

# Creación de ejecutable para el main
add_executable(main_class_node src/main_class_node.cpp)
# Se enlazan los modulos con el main
target_link_libraries(main_class_node ${PROJECT_NAME})

# Se deben instalar los directorios
install(DIRECTORY include launch
    DESTINATION share/${PROJECT_NAME}
)

# Instalación de cada paquete
install(TARGETS
    main_class_node
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib/${PROJECT_NAME}
)

# Para los test
if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${dependencies})

ament_package()
