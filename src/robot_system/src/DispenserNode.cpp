#include "robot_system/DispenserNode.hpp"
#include <thread>
#include <chrono>

DispenserNode::DispenserNode()
    : Node(Constants::DISPENSER_NODE)
{
    xyz_dispenser_service = create_service<message::srv::DispenseService>(
        Service::SERVICE_DISPENSER,
        std::bind(&DispenserNode::xyz_callback_service, this, std::placeholders::_1, std::placeholders::_2)
    );

    dispenser = std::make_unique<DIODispenser>();

    RCLCPP_INFO(this->get_logger(), "Dispenser Node Init!!");
}

void DispenserNode::xyz_callback_service(
    const std::shared_ptr<message::srv::DispenseService::Request> request,
    std::shared_ptr<message::srv::DispenseService::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Request Cmd : %s", request->command.c_str());

    if (request->command == DispenseCommand::toString(DispenseCommand::Type::COFFEE_ON)) {
        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::COFFEE_ON));
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::COFFEE_PIN_RESET));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::COFFEE_OFF));
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::COFFEE_PIN_RESET));
    }
    else if (request->command == DispenseCommand::toString(DispenseCommand::Type::WATER_TOGGLE)) {
        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::WATER_TOGGLE));
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::WATER_PIN_RESET));
        std::this_thread::sleep_for(std::chrono::seconds(9));

        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::WATER_TOGGLE));
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        *response = dispenser->dispense(DispenseCommand::toString(DispenseCommand::Type::WATER_PIN_RESET));
    }
    else {
        response->seq_no = "";
        response->response_cd = 9999;
    }
}