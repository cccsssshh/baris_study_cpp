#include "robot_system/DIODispenser.hpp"
#include <chrono>
#include <ctime>

DIODispenser::DIODispenser() : dio_component(nullptr), status(DeviceStatus::STANDBY), before_cmd("") {}

std::string DIODispenser::get_before_cmd() const {
    return before_cmd;
}

message::srv::DispenseService::Response DIODispenser::dispense(std::string_view command) {
    message::srv::DispenseService::Response response;
    before_cmd = command;

    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now_c));

    response.seq_no = std::string(buf);
    response.response_cd = static_cast<uint16_t>(ResponseCode::SUCCESS);

    return response;
}


