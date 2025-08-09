#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <regex>
#include <iostream>
#include <limits>
#include <ctime>

/**
 * @brief 工具类
 * @details 提供一些通用的验证和工具函数
 */
class Utils {
public:
    /**
     * @brief 验证中文姓名
     * @param name 待验证的姓名
     * @return true 如果是有效的中文姓名，false 否则
     */
    static bool isValidChineseName(const std::string& name);
    
    /**
     * @brief 验证电话号码
     * @param phone 待验证的电话号码
     * @return true 如果是有效的电话号码，false 否则
     */
    static bool isValidPhoneNumber(const std::string& phone);
    
    /**
     * @brief 验证生日格式
     * @param birthday 待验证的生日字符串（YYYY-MM-DD格式）
     * @return true 如果是有效的生日格式，false 否则
     */
    static bool isValidBirthday(const std::string& birthday);
    
    /**
     * @brief 验证数值范围
     * @param value 待验证的数值
     * @param min 最小值
     * @param max 最大值
     * @return true 如果在范围内，false 否则
     */
    static bool isInRange(int value, int min, int max);
    
    /**
     * @brief 验证数值范围
     * @param value 待验证的数值
     * @param min 最小值
     * @param max 最大值
     * @return true 如果在范围内，false 否则
     */
    static bool isInRange(double value, double min, double max);
    
    /**
     * @brief 清除输入缓冲区
     */
    static void clearInputBuffer();
    
    /**
     * @brief 显示错误信息
     * @param message 错误信息
     */
    static void showError(const std::string& message);
    
    /**
     * @brief 显示成功信息
     * @param message 成功信息
     */
    static void showSuccess(const std::string& message);
    
    /**
     * @brief 安全获取字符串输入
     * @param prompt 提示信息
     * @param maxLength 最大长度限制
     * @return 用户输入的字符串
     */
    static std::string getStringInput(const std::string& prompt, size_t maxLength = 100);
    
    /**
     * @brief 安全获取整数输入
     * @param prompt 提示信息
     * @param minValue 最小值
     * @param maxValue 最大值
     * @return 验证通过的整数值
     */
    static int getIntInput(const std::string& prompt, int minValue = INT_MIN, int maxValue = INT_MAX);
    
    /**
     * @brief 安全获取双精度浮点数输入
     * @param prompt 提示信息
     * @param minValue 最小值
     * @param maxValue 最大值
     * @return 验证通过的双精度浮点数值
     */
    static double getDoubleInput(const std::string& prompt, double minValue = -std::numeric_limits<double>::max(), double maxValue = std::numeric_limits<double>::max());
};

#endif // UTILS_H 