/**
 * @file Member.cpp
 * @brief 会员类实现文件
 * @details 实现会员类的所有功能，包括会员信息管理、积分计算、等级管理和消费记录等
 * @author 系统开发者
 * @date 2024
 * @version 1.0
 */

#include "Member.h"
#include <iostream>
#include <ctime>
#include <iomanip>

/**
 * @brief 构造函数
 * @param id 会员ID
 * @param name 会员姓名
 * @param phone 会员电话
 * @param birthday 会员生日
 * @param rule 积分规则（1元=多少积分），默认为1
 * @param annualSpent 年度累计消费，默认为0
 * @param level 会员等级，默认为普通会员
 * @param lastYear 上次消费年份，默认为0
 * @details 初始化会员对象的所有成员变量
 */
Member::Member(int id, const std::string& name, const std::string& phone, const std::string& birthday,
               int rule, double annualSpent, Level level, int lastYear)
    : id(id), 
      name(name), 
      phone(phone), 
      birthday(birthday), 
      totalSpent(0.0), 
      points(0),
      pointsPerDollar(rule), 
      annualSpent(0.0), 
      currentLevel(NORMAL), 
      lastYear(0) {
    
    // 设置年度消费金额
    this->annualSpent = annualSpent;
    this->totalSpent = annualSpent;
    
    // 设置会员等级
    this->currentLevel = level;
    this->lastYear = lastYear;
    
    // 根据年度消费金额确定会员等级
    determineLevel();
}

// ==================== 基本信息获取函数 ====================

/**
 * @brief 获取会员ID
 * @return 会员唯一标识ID
 */
int Member::getId() const {
    return id;
}

/**
 * @brief 获取会员姓名
 * @return 会员姓名
 */
const std::string& Member::getName() const {
    return name;
}

/**
 * @brief 获取会员电话
 * @return 会员电话号码
 */
const std::string& Member::getPhone() const {
    return phone;
}

/**
 * @brief 获取会员生日
 * @return 会员生日信息
 */
const std::string& Member::getBirthday() const {
    return birthday;
}

// ==================== 消费和积分信息获取函数 ====================

/**
 * @brief 获取总消费金额
 * @return 会员累计总消费金额（原价）
 */
double Member::getTotalSpent() const {
    return totalSpent;
}

/**
 * @brief 获取当前积分
 * @return 会员当前累计积分
 */
int Member::getPoints() const {
    return points;
}

/**
 * @brief 获取积分规则
 * @return 当前积分规则（1元=多少积分）
 */
int Member::getPointsPerDollar() const {
    return pointsPerDollar;
}

/**
 * @brief 获取上次消费年份
 * @return 上次消费的年份，用于年度重置判断
 */
int Member::getLastYear() const {
    return lastYear;
}

// ==================== 等级管理函数 ====================

/**
 * @brief 获取当前会员等级
 * @return 当前会员等级枚举值
 */
Member::Level Member::getCurrentLevel() const {
    return currentLevel;
}

/**
 * @brief 获取年度累计消费
 * @return 当前年度累计消费金额
 */
double Member::getAnnualSpent() const {
    return annualSpent;
}

/**
 * @brief 设置积分规则
 * @param rule 新的积分规则（1元=多少积分）
 * @details 更新积分计算规则，影响后续消费的积分计算
 */
void Member::setPointsRule(int rule) {
    if (rule <= 0) {
        std::cout << "积分规则必须大于 0！" << std::endl;
        return;
    }
    pointsPerDollar = rule;
}

/**
 * @brief 积分兑换
 * @param pointsToRedeem 要兑换的积分数量
 * @details 使用积分进行兑换，减少当前积分余额
 */
void Member::redeemPoints(int pointsToRedeem) {
    if (pointsToRedeem <= 0 || pointsToRedeem > points) {
        std::cout << "积分不足或兑换数量无效！" << std::endl;
        return;
    }
    points -= pointsToRedeem;
    std::cout << "成功兑换 " << pointsToRedeem << " 积分，剩余积分: " << points << std::endl;
}

/**
 * @brief 确定会员等级
 * @details 根据年度消费金额自动确定会员等级
 * 等级规则：
 * - 钻石会员：年度消费 >= 20000元
 * - 黄金会员：年度消费 >= 10000元
 * - 白银会员：年度消费 >= 5000元
 * - 普通会员：年度消费 < 5000元
 */
void Member::determineLevel() {
    if (annualSpent >= 20000) currentLevel = DIAMOND;
    else if (annualSpent >= 10000) currentLevel = GOLD;
    else if (annualSpent >= 5000) currentLevel = SILVER;
    else currentLevel = NORMAL;
}

/**
 * @brief 获取折扣率
 * @return 当前等级对应的折扣率（0.8-1.0）
 * @details 根据会员等级返回对应的折扣率
 * 折扣规则：
 * - 钻石会员：8折优惠
 * - 黄金会员：9折优惠
 * - 白银会员：95折优惠
 * - 普通会员：无折扣
 */
double Member::getDiscountRate() const {
    switch (currentLevel) {
    case DIAMOND: return 0.8;  // 钻石会员8折
    case GOLD: return 0.9;     // 黄金会员9折
    case SILVER: return 0.95;  // 白银会员95折
    default: return 1.0;       // 普通会员无折扣
    }
}

/**
 * @brief 添加消费记录并更新积分/等级
 * @param amount 消费金额
 * @details 记录消费并自动计算积分、更新等级、应用折扣优惠
 * 处理流程：
 * 1. 检查是否跨年，如果是则重置年度消费
 * 2. 更新年度消费金额
 * 3. 重新确定会员等级
 * 4. 计算折扣后的实际支付金额
 * 5. 根据实际支付金额计算积分
 * 6. 更新总消费和积分
 * 7. 记录消费历史
 */
void Member::addSpending(double amount) {
    // 获取当前时间信息
    time_t now = time(0);
    tm timeInfo;

    errno_t ltm = localtime_s(&timeInfo, &now);
    int currentYear = 1900 + timeInfo.tm_year;

    // 检查是否跨年，如果是则重置年度消费
    if (lastYear != currentYear) {
        annualSpent = 0.0;
        lastYear = currentYear;
    }

    // 更新年度消费金额
    annualSpent += amount;
    
    // 重新确定会员等级
    determineLevel();
    
    // 获取当前等级的折扣率
    double discountRate = getDiscountRate();
    
    // 计算折扣后的实际支付金额
    double actualAmount = amount * discountRate;
    
    // 根据实际支付金额计算积分
    int earnedPoints = static_cast<int>(actualAmount * pointsPerDollar);

    // 更新总消费和积分
    totalSpent += amount;
    points += earnedPoints;
    
    // 记录消费历史（原价和折扣率）
    consumptionHistory.push_back({ amount, discountRate });

    // 输出消费详情
    std::cout << "消费 " << amount << " 元，享受 " << discountRate * 10 << " 折优惠，实际支付 " << actualAmount << " 元，累计积分: " << points << std::endl;
}

/**
 * @brief 显示消费记录
 * @param n 显示最近N次消费记录，-1表示显示全部
 * @details 显示会员的消费历史，包括原价、折扣和实际支付金额
 */
void Member::showConsumptionHistory(int n) const {
    if (consumptionHistory.empty()) {
        std::cout << "暂无消费记录！" << std::endl;
        return;
    }
    
    // 确定显示的起始位置
    int startIndex = (n == -1) ? 0 : std::max(0, static_cast<int>(consumptionHistory.size()) - n);
    int displayCount = consumptionHistory.size() - startIndex;
    
    std::cout << "\n消费记录 (" << displayCount << " 条):" << std::endl;
    std::cout << "┌─────────────┬─────────────┬─────────────┬─────────────┐" << std::endl;
    std::cout << "│    序号     │    原价     │    折扣     │  实际支付   │" << std::endl;
    std::cout << "├─────────────┼─────────────┼─────────────┼─────────────┤" << std::endl;
    
    // 遍历并显示消费记录
    for (int i = startIndex; i < consumptionHistory.size(); ++i) {
        double original = consumptionHistory[i].first;    // 原价
        double rate = consumptionHistory[i].second;       // 折扣率
        double actual = original * rate;                  // 实际支付金额
        int recordNum = i - startIndex + 1;               // 显示序号
        
        std::cout << "│ " << std::left << std::setw(11) << recordNum
                  << " │ " << std::left << std::setw(5) << std::fixed << std::setprecision(2) << original << "元"
                  << " │ " << std::left << std::setw(5) << std::fixed << std::setprecision(1) << (rate * 10) << "折"
                  << " │ " << std::left << std::setw(5) << std::fixed << std::setprecision(2) << actual << "元"
                  << " │" << std::endl;
    }
    std::cout << "└─────────────┴─────────────┴─────────────┴─────────────┘" << std::endl;
}