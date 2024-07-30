#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include <ctime>
#include <stdexcept>

#include <library/Constants.hpp>
#include <message/srv/robot_service.hpp>

class RobotSystem {
public:
    RobotSystem();
    std::string::get_cur_cmd();
    message::srv::RobotService::Response execute(const message::srv::RobotService::Request& request);

private:
    static const std::array<int, ANSWER_SIZE> ANSWER_CMD;
    static const std::array<int, ANSWER_SIZE> ANSWER_CMD_PAR;

    void* robot;
    std::string before_pos;
    std::string* request_pos;
    int request_cnt;

    std::string make_str(const std::array<std::string, 7>& result_list);
    std::string get_current_time();
};

#endif