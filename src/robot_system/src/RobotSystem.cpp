#include "RobotSystem.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <stdexcept>

RobotSystem::RobotSystem()
    : before_pos("cmd"), request_pos(nullptr),
    request_cnt(Constants::ZERO)
{
}

std::string RobotSystem::get_cur_cmd() {
    return before_pos;
}

message::srv::RobotService::Response RobotSystem::execute(const message::srv::RobotService::Request& request) {
    message::srv::RobotService::Response response;
    response.component_cd = DeviceCode::ROBOT;
    response.seq_no = request.seq_no;