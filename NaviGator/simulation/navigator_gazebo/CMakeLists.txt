cmake_minimum_required(VERSION 2.8.3)
project(navigator_gazebo)

find_package(catkin
    REQUIRED COMPONENTS
    std_msgs
    nav_msgs
    rospy
    gazebo_ros
    roscpp
    message_generation
    roboteq_msgs
    xacro
)


find_package(gazebo REQUIRED)
link_directories(${GAZEBO_LIBRARY_DIRS})
include_directories(
    ${Boost_INCLUDE_DIR}
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
    include
)

add_library(
    navigator_thrusters
        src/navigator_thrusters.cpp
)
set_target_properties(navigator_thrusters PROPERTIES COMPILE_FLAGS "-std=c++11 -Wall")
target_link_libraries(navigator_thrusters
  ${catkin_LIBRARIES}
  ${GAZEBO_LIBRARIES}
)
add_dependencies(navigator_thrusters
  ${catkin_EXPORTED_TARGETS}
)

add_library(
    pinger_plugin
        src/pinger_plugin.cpp
)
set_target_properties(pinger_plugin PROPERTIES COMPILE_FLAGS "-std=c++11 -Wall")
target_link_libraries(pinger_plugin
  ${catkin_LIBRARIES}
  ${GAZEBO_LIBRARIES}
)
add_dependencies(pinger_plugin
  ${catkin_EXPORTED_TARGETS}
)

add_library(sylphase_gazebo
  src/sylphase_gazebo.cpp
)
set_target_properties(sylphase_gazebo PROPERTIES COMPILE_FLAGS "-std=c++11 -Wall")
target_link_libraries(sylphase_gazebo
  ${catkin_LIBRARIES}
  ${GAZEBO_LIBRARIES}
)
add_dependencies(sylphase_gazebo
    ${catkin_EXPORTED_TARGETS}
)

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS gazebo_ros roscpp rospy std_msgs nav_msgs message_runtime tf gazebo_plugins sensor_msgs
)

# Generate NaviGator's URDF
xacro_add_files(
  urdf/navigator.urdf.xacro
  INORDER INSTALL DESTINATION urdf
  TARGET xacro_urdf
)

# Generate Navigator urdf for vrx via yaml files
add_custom_target(navigator_vrx_urdf ALL
  DEPENDS ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}/urdf/navigator_vrx.urdf
)
add_custom_command(
  OUTPUT ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}/urdf/navigator_vrx.urdf
  COMMAND . ${CATKIN_DEVEL_PREFIX}/setup.sh && roslaunch vrx_gazebo generate_wamv.launch thruster_yaml:=${CMAKE_CURRENT_SOURCE_DIR}/urdf/navigator_vrx/thruster_config.yaml sensor_yaml:=${CMAKE_CURRENT_SOURCE_DIR}/urdf/navigator_vrx/sensor_config.yaml wamv_target:=${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}/urdf/navigator_vrx.urdf
  DEPENDS urdf/navigator_vrx/thruster_config.yaml urdf/navigator_vrx/sensor_config.yaml
  DEPENDS ${CATKIN_DEVEL_PREFIX}/setup.sh
  BYPRODUCTS urdf/navigator_vrx/thruster_config.xacro urdf/navigator_vrx/thruster_config.xacro
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "xacro: generating ${output} from yamls"
)

# Generate world files from xacro and install
xacro_add_files(
  worlds/course.world.xacro
  INORDER INSTALL DESTINATION worlds
  TARGET xacro_worlds
)

# if(CATKIN_ENABLE_TESTING)
#     find_package(rostest)
#     add_subdirectory(test)
# endif()
