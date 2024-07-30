#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string_view>
#include <array>
#include <string>
#include <vector>

class Command {
public:
    // 커맨드 관련 상수
    enum class Type {
        INIT,
        RUN,
        STOP,
        OFF,
        SHUTDOWN,
        RESTART,
        GET_STATUS,
        CLEAN,
        CLEAN_ALL,
        CLEAN_CHANNEL,
        DISPENSE,
        TEST,
        EXTRACT,
        HOT_WATER,
        SET_STOCK_MIN,
        SET_STOCK_MAX,
        GET_MENU,
        WATER,
        ICE,
        GET_STATUS_MODULE,
        GET_INFO,
        RAIL_BASE,
        REBOOT,
        PRESET,
        CLOSE,
        UNLOCK_PROTECT,
        GRIPPER_INIT,
        HOME,
        PLACE_SYRUP,
        PICKUP_SYRUP,
        TEACH,
        ENDTEACH,
        RESET
    };

    [[nodiscard]] static constexpr std::string_view toString(Type type) {
        switch (type) {
            case Type::INIT: return "INIT";
            case Type::RUN: return "RUN";
            case Type::STOP: return "STOP";
            case Type::OFF: return "OFF";
            case Type::SHUTDOWN: return "SHUTDOWN";
            case Type::RESTART: return "RESTART";
            case Type::GET_STATUS: return "get_status";
            case Type::CLEAN: return "clean";
            case Type::CLEAN_ALL: return "clean_all";
            case Type::CLEAN_CHANNEL: return "clean_channel";
            case Type::DISPENSE: return "dispense";
            case Type::TEST: return "test";
            case Type::EXTRACT: return "extract";
            case Type::HOT_WATER: return "hot_water";
            case Type::SET_STOCK_MIN: return "set_stock_min";
            case Type::SET_STOCK_MAX: return "set_stock_max";
            case Type::GET_MENU: return "get_menu";
            case Type::WATER: return "water";
            case Type::ICE: return "ice";
            case Type::GET_STATUS_MODULE: return "get_status_module";
            case Type::GET_INFO: return "get_info";
            case Type::RAIL_BASE: return "rail_base";
            case Type::REBOOT: return "reboot";
            case Type::PRESET: return "preset";
            case Type::CLOSE: return "close";
            case Type::UNLOCK_PROTECT: return "unlock_protect";
            case Type::GRIPPER_INIT: return "gripper_init";
            case Type::HOME: return "home";
            case Type::PLACE_SYRUP: return "place_syrup";
            case Type::PICKUP_SYRUP: return "pickup_syrup";
            case Type::TEACH: return "TEACH";
            case Type::ENDTEACH: return "ENDTEACH";
            case Type::RESET: return "reset";
        }
        return "UNKNOWN";
    }
};

class RobotParameter {
public:
    enum class Type {
        ZERO, ONE, TWO, DSP, ZON, KET, DPO, PIC, ETC, HOT, SOL, BIN, COF
    };

    [[nodiscard]] static constexpr std::string_view toString(Type type) {
        switch (type) {
            case Type::ZERO: return "0";
            case Type::ONE: return "1";
            case Type::TWO: return "2";
            case Type::DSP: return "DSP";
            case Type::ZON: return "ZON";
            case Type::KET: return "KET";
            case Type::DPO: return "DPO";
            case Type::PIC: return "PIC";
            case Type::ETC: return "ETC";
            case Type::HOT: return "HOT";
            case Type::SOL: return "SOL";
            case Type::BIN: return "BIN";
            case Type::COF: return "COF";
        }
        return "UNKNOWN";
    }
};

class RobotCommand {
public:
    enum class Type {
        DRAIN_ALL, DRAIN_FIT, DRIP, FLATTENING, GESTURE, HOLD, HOME_KETTLE,
        PLACE, PLACE_CUP, PLACE_DRIP, UNHOLD, GRIPPER_INIT, HOME_NORMAL,
        PICKUP, PICKUP_CUP, PICKUP_DRIP, SHUTDOWN, STOP, RUN, RESTART, HOME, RESET
    };

    [[nodiscard]] static constexpr std::string_view toString(Type type) {
        switch (type) {
            case Type::DRAIN_ALL: return "DRAIN_ALL";
            case Type::DRAIN_FIT: return "DRAIN_FIT";
            case Type::DRIP: return "DRIP";
            case Type::FLATTENING: return "FLATTENING";
            case Type::GESTURE: return "GESTURE";
            case Type::HOLD: return "HOLD";
            case Type::HOME_KETTLE: return "HOME_KETTLE";
            case Type::PLACE: return "PLACE";
            case Type::PLACE_CUP: return "PLACE_CUP";
            case Type::PLACE_DRIP: return "PLACE_DRIP";
            case Type::UNHOLD: return "UNHOLD";
            case Type::GRIPPER_INIT: return "GRIPPER_INIT";
            case Type::HOME_NORMAL: return "HOME_NORMAL";
            case Type::PICKUP: return "PICKUP";
            case Type::PICKUP_CUP: return "PICKUP_CUP";
            case Type::PICKUP_DRIP: return "PICKUP_DRIP";
            case Type::SHUTDOWN: return "SHUTDOWN";
            case Type::STOP: return "STOP";
            case Type::RUN: return "RUN";
            case Type::RESTART: return "RESTART";
            case Type::HOME: return "HOME";
            case Type::RESET: return "RESET";
        }
        return "UNKNOWN";
    }
};

class DispenseCommand {
public:
    enum class Type {
        WATER_TOGGLE, WATER_PIN_RESET, COFFEE_PIN_RESET, COFFEE_TOGGLE,
        COFFEE_ON, COFFEE_OFF, WATER, COFFEE
    };

    [[nodiscard]] static constexpr std::string_view toString(Type type) {
        switch (type) {
            case Type::WATER_TOGGLE: return "WATER_TOGGLE";
            case Type::WATER_PIN_RESET: return "WATER_PIN_RESET";
            case Type::COFFEE_PIN_RESET: return "COFFEE_PIN_RESET";
            case Type::COFFEE_TOGGLE: return "COFFEE_TOGGLE";
            case Type::COFFEE_ON: return "COFFEE_ON";
            case Type::COFFEE_OFF: return "COFFEE_OFF";
            case Type::WATER: return "WATER";
            case Type::COFFEE: return "COFFEE";
        }
        return "UNKNOWN";
    }
};

struct ResponseDataList {
    int response_cd = 999;
    std::string status_cd;
    std::string component_cd;
    std::vector<std::string> data_list;
    std::string cmd;
};

enum class ResponseCode {
    SUCCESS = 0,  // 정상
    OFF = 1,      // OFF 상태
    ON = 2,       // ON 상태
    STANDBY = 3,  // STANDBY 상태
    WORKING = 4,  // WORKING 상태
    ERROR = 9
};

namespace Constants {
    constexpr int ZERO = 0;
    constexpr int ONE = 1;
    constexpr int TWO = 2;
    constexpr int THREE = 3;
    constexpr int FOUR = 4;
    constexpr double TIMER_PERIOD = 0.1;
    inline const std::string ROBOTS_SYSTEM = "RobotSystemNode";
    constexpr int QOS_DEFAULT = 20;
    inline const std::string DISPENSER_NODE = "DispenserNode";
}

namespace Service {
    inline const std::string SERVICE_ROBOT = "XYZ_robot/service";
    inline const std::string SERVICE_DISPENSER = "XYZ_dispenser/service";
}

namespace Topic {
    inline const std::string ROBOT_STATUS = "XYZ_robot/status";
}

namespace DeviceCode {
    inline const std::string ROBOT = "ROBOT";
    inline const std::string WATER = "WATER";
    inline const std::string COFFEE = "COFFEE";
}

namespace DeviceStatus {
    inline const std::string STANDBY = "STANDBY";
    inline const std::string WORKING = "WORKING";
    inline const std::string ERROR = "ERROR";
    inline const std::string RESET = "RESET";
}

#endif // CONSTANTS_HPP