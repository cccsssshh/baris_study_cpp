#include <rclcpp/rclcpp.hpp>
#include "robot_system/DispenserNode.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DispenserNode>());
    rclcpp::shutdown();
    return 0;
}