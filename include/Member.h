#pragma once
#include <string>
#include <vector>
#include <ctime>

/**
 * @class Member
 * @brief 会员类
 * @details 表示一个会员实体，包含会员的基本信息、积分、消费记录和等级系统
 *          支持积分计算、等级自动升级、折扣优惠等功能
 */
class Member {
public:
    /**
     * @enum Level
     * @brief 会员等级枚举
     * @details 定义会员的不同等级，不同等级享受不同的折扣优惠
     */
    enum Level { 
        NORMAL,   ///< 普通会员，无折扣
        SILVER,   ///< 白银会员，95折优惠
        GOLD,     ///< 黄金会员，9折优惠
        DIAMOND   ///< 钻石会员，8折优惠
    };

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
     */
    Member(int id, const std::string& name, const std::string& phone, const std::string& birthday,
           int rule = 1, double annualSpent = 0.0, Level level = NORMAL, int lastYear = 0);

    // ==================== 基本信息获取 ====================
    
    /**
     * @brief 获取会员ID
     * @return 会员唯一标识ID
     */
    int getId() const;
    
    /**
     * @brief 获取会员姓名
     * @return 会员姓名
     */
    const std::string& getName() const;
    
    /**
     * @brief 获取会员电话
     * @return 会员电话号码
     */
    const std::string& getPhone() const;
    
    /**
     * @brief 获取会员生日
     * @return 会员生日信息
     */
    const std::string& getBirthday() const;

    // ==================== 消费和积分信息 ====================
    
    /**
     * @brief 获取总消费金额
     * @return 会员累计总消费金额（原价）
     */
    double getTotalSpent() const;
    
    /**
     * @brief 获取当前积分
     * @return 会员当前累计积分
     */
    int getPoints() const;
    
    /**
     * @brief 获取积分规则
     * @return 当前积分规则（1元=多少积分）
     */
    int getPointsPerDollar() const;
    
    /**
     * @brief 获取上次消费年份
     * @return 上次消费的年份，用于年度重置判断
     */
    int getLastYear() const;

    // ==================== 等级管理 ====================
    
    /**
     * @brief 获取当前会员等级
     * @return 当前会员等级枚举值
     */
    Level getCurrentLevel() const;
    
    /**
     * @brief 获取年度累计消费
     * @return 当前年度累计消费金额
     */
    double getAnnualSpent() const;
    
    /**
     * @brief 设置积分规则
     * @param rule 新的积分规则（1元=多少积分）
     * @details 更新积分计算规则，影响后续消费的积分计算
     */
    void setPointsRule(int rule);
    
    /**
     * @brief 添加消费记录
     * @param amount 消费金额
     * @details 记录消费并自动计算积分、更新等级、应用折扣优惠
     */
    void addSpending(double amount);
    
    /**
     * @brief 积分兑换
     * @param pointsToRedeem 要兑换的积分数量
     * @details 使用积分进行兑换，减少当前积分余额
     */
    void redeemPoints(int pointsToRedeem);
    
    /**
     * @brief 显示消费历史记录
     * @param n 显示最近N次消费记录，-1表示显示全部
     * @details 显示会员的消费历史，包括原价、折扣和实际支付金额
     */
    void showConsumptionHistory(int n) const;

    /**
     * @brief 确定会员等级
     * @details 根据年度消费金额自动确定会员等级
     */
    void determineLevel();
    
    /**
     * @brief 获取折扣率
     * @return 当前等级对应的折扣率（0.8-1.0）
     * @details 根据会员等级返回对应的折扣率
     */
    double getDiscountRate() const;

private:
    int id;                                    ///< 会员唯一标识ID
    std::string name;                          ///< 会员姓名
    std::string phone;                         ///< 会员电话号码
    std::string birthday;                      ///< 会员生日
    double totalSpent;                         ///< 总消费金额（原价）
    int points;                                ///< 累计积分
    int pointsPerDollar;                       ///< 积分规则（1元 = ?积分）
    std::vector<std::pair<double, double>> consumptionHistory;  ///< 消费历史记录 <原价, 折扣率>
    double annualSpent;                        ///< 年度累计消费（原价）
    Level currentLevel;                        ///< 当前会员等级
    int lastYear;                              ///< 上次消费的年份（用于判断是否跨年）
};