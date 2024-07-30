#ifndef DISPENSER_NODE_H
#define DISPENSER_NODE_H

#include "rclcpp/rclcpp.hpp"
#include "message/srv/dispense_service.hpp"
#include "robot_system/DIODispenser.hpp"
#include "library/Constants.hpp"

class DispenserNode : public rclcpp::Node
{
public:
    DispenserNode();
    
private:
    static constexpr double CHECK_INTERVAL_SEC = 0.1;

    void xyz_callback_service(
        const std::shared_ptr<message::srv::DispenseService::Request> request,
        std::shared_ptr<message::srv::DispenseService::Response> response);

    rclpp::Service<message::srv::DispenseService>::SharedPtr xyz_dispenser_service;
    std::unique_ptr<DIODispenser> dispenser;
}

#endif