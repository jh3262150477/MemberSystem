/**
 * @file Utils.cpp
 * @brief 工具类实现文件
 * @details 实现各种验证和工具函数，包括输入验证、数据验证和用户交互功能
 * @author 系统开发者
 * @date 2024
 * @version 1.0
 */

#include "Utils.h"
#include <iostream>
#include <regex>
#include <limits>
#include <ctime>
#include <sstream>
#include <iomanip>

/**
 * @brief 验证中文姓名
 * @param name 待验证的姓名
 * @return true 如果是有效的中文姓名，false 否则
 * @details 支持Windows GBK编码和Linux/macOS UTF-8编码的中文姓名验证
 */
bool Utils::isValidChineseName(const std::string& name) {
    #ifdef _WIN32
    // Windows GBK编码中文字符范围验证
    for (size_t i = 0; i < name.length(); i++) {
        unsigned char c = name[i];
        if (c >= 0x81 && c <= 0xFE) {
            if (++i >= name.length()) return false;
        }
        else {
            return false;
        }
    }
    #else
    // Linux/macOS UTF-8编码中文验证
    std::regex re("^[\u4e00-\u9fa5]+$");
    if (!std::regex_match(name, re)) {
        return false;
    }
    #endif
    return true;
}

/**
 * @brief 验证电话号码
 * @param phone 待验证的电话号码
 * @return true 如果是有效的电话号码，false 否则
 * @details 支持手机号（11位，1开头）和固定电话（7-8位）格式验证
 */
bool Utils::isValidPhoneNumber(const std::string& phone) {
    if (phone.empty()) {
        return false;
    }

    // 验证是否只包含数字
    for (char c : phone) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    // 验证长度：手机号11位，固定电话7-8位
    if (phone.length() != 11 && phone.length() != 7 && phone.length() != 8) {
        return false;
    }

    // 手机号以1开头
    if (phone.length() == 11 && phone[0] != '1') {
        return false;
    }

    return true;
}

/**
 * @brief 验证生日格式
 * @param birthday 待验证的生日字符串（YYYY-MM-DD格式）
 * @return true 如果是有效的生日格式，false 否则
 * @details 验证日期格式、日期有效性和不能是未来日期
 */
bool Utils::isValidBirthday(const std::string& birthday) {
    if (birthday.empty()) {
        return false;
    }

    // 验证格式：YYYY-MM-DD
    std::regex datePattern(R"(^\d{4}-\d{2}-\d{2}$)");
    if (!std::regex_match(birthday, datePattern)) {
        return false;
    }

    // 解析日期
    std::istringstream iss(birthday);
    int year, month, day;
    char dash1, dash2;

    if (!(iss >> year >> dash1 >> month >> dash2 >> day) ||
        dash1 != '-' || dash2 != '-') {
        return false;
    }

    // 验证年份范围
    if (year < 1900 || year > 2100) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    // 验证日期
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // 处理闰年
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    // 验证不能是未来日期
    std::time_t now = std::time(nullptr);
    std::tm currentTime;

    // 平台兼容：使用线程安全函数
#if defined(_WIN32)
    localtime_s(&currentTime, &now);  // Windows
#else
    localtime_r(&now, &currentTime);  // Linux/macOS
#endif

    // 日期比较逻辑
    if (year > currentTime.tm_year + 1900) {
        return false;
    }
    if (year == currentTime.tm_year + 1900 && month > currentTime.tm_mon + 1) {
        return false;
    }
    if (year == currentTime.tm_year + 1900 && month == currentTime.tm_mon + 1 && day > currentTime.tm_mday) {
        return false;
    }

    return true;
}

/**
 * @brief 验证整数值范围
 * @param value 待验证的整数值
 * @param min 最小值
 * @param max 最大值
 * @return true 如果在范围内，false 否则
 */
bool Utils::isInRange(int value, int min, int max) {
    return value >= min && value <= max;
}

/**
 * @brief 验证双精度浮点数值范围
 * @param value 待验证的双精度浮点数值
 * @param min 最小值
 * @param max 最大值
 * @return true 如果在范围内，false 否则
 */
bool Utils::isInRange(double value, double min, double max) {
    return value >= min && value <= max;
}

/**
 * @brief 清除输入缓冲区
 * @details 清除cin的错误状态和缓冲区中的剩余字符
 */
void Utils::clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief 显示错误信息
 * @param message 错误信息
 * @details 在控制台输出错误信息
 */
void Utils::showError(const std::string& message) {
    std::cout << message << std::endl;
}

/**
 * @brief 显示成功信息
 * @param message 成功信息
 * @details 在控制台输出成功信息
 */
void Utils::showSuccess(const std::string& message) {
    std::cout << message << std::endl;
}

/**
 * @brief 安全获取字符串输入
 * @param prompt 提示信息
 * @param maxLength 最大长度限制
 * @return 用户输入的字符串
 * @details 获取用户输入并验证长度，自动去除首尾空格
 */
std::string Utils::getStringInput(const std::string& prompt, size_t maxLength) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // 去除首尾空格
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (input.empty()) {
            showError("输入不能为空，请重新输入！");
            continue;
        }

        if (input.length() > maxLength) {
            showError("输入长度超出限制，最多" + std::to_string(maxLength) + "个字符，请重新输入！");
            continue;
        }

        break;
    }
    return input;
}

/**
 * @brief 安全获取整数输入
 * @param prompt 提示信息
 * @param minValue 最小值
 * @param maxValue 最大值
 * @return 验证通过的整数值
 * @details 获取用户输入并验证格式和范围
 */
int Utils::getIntInput(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            if (isInRange(value, minValue, maxValue)) {
                clearInputBuffer();
                break;
            }
            else {
                showError("输入超出范围，请输入" + std::to_string(minValue) + "到" + std::to_string(maxValue) + "之间的整数！");
            }
        }
        else {
            showError("输入格式错误，请输入有效的整数！");
            clearInputBuffer();
        }
    }
    return value;
}

/**
 * @brief 安全获取双精度浮点数输入
 * @param prompt 提示信息
 * @param minValue 最小值
 * @param maxValue 最大值
 * @return 验证通过的双精度浮点数值
 * @details 获取用户输入并验证格式和范围
 */
double Utils::getDoubleInput(const std::string& prompt, double minValue, double maxValue) {
    double value;
    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            if (isInRange(value, minValue, maxValue)) {
                clearInputBuffer();
                break;
            }
            else {
                showError("输入超出范围，请输入" + std::to_string(minValue) + "到" + std::to_string(maxValue) + "之间的数值！");
            }
        }
        else {
            showError("输入格式错误，请输入有效的数值！");
            clearInputBuffer();
        }
    }
    return value;
}