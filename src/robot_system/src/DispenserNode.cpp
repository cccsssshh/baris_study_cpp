#include "DispenserNode.hpp"
#include <thread>
#include <chrono>

DispenserNode::DispenserNode()
    : Node(Constants::DISPENSER_NODE)
{
    xyz_dispenser_service = create_service<message::srv::DispenseService>(
        Service::SERVICE_DISPENSER,
        std::bind(&DispenserNode::xyz_callback_service, this, std::placeholders::_1, std::placeholders::_2)
    );

    dispenser = std:make_unique<DIODispenser>();
}