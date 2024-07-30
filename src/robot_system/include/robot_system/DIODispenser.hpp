#ifndef DIO_DISPENSER_H
#define DIO_DISPENSER_H

#include <string>
#include "Constants.hpp"
#include "message/srv/dispense_service.hpp"

class DIODispenser {
private:
    void* dio_component;
    std::string status;
    std::string before_cmd;

public:
    DIODispenser();
    std::string get_before_cmd() const;
    message::srv::DispenseService::Response dispense(const std::string& command);
};

#endif
