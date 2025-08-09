// MemberManager.h
#pragma once
#include "Member.h"
#include <vector>
#include <string>

/**
 * @class MemberManager
 * @brief 会员管理器类
 * @details 负责管理所有会员数据，包括会员信息的增删改查、
 *          积分管理、消费记录管理和数据持久化等功能
 */
class MemberManager {
private:
    std::vector<Member> members;  ///< 存储所有会员的向量
    int nextId = 1;               ///< 下一个可用的会员ID
    int pointsRule = 1;           ///< 积分规则（1元=多少积分）

public:
    // ==================== 基础数据访问 ====================
    
    /**
     * @brief 获取所有会员列表
     * @return 会员向量副本
     */
    std::vector<Member> getMembers() const;

    // ==================== 会员信息管理 ====================
    
    /**
     * @brief 添加新会员
     * @param name 会员姓名
     * @param phone 会员电话
     * @param birthday 会员生日
     * @details 创建新会员对象并添加到会员列表中，自动分配唯一ID
     */
    void addMember(const std::string& name, const std::string& phone, const std::string& birthday);
    
    /**
     * @brief 删除指定会员
     * @param memberid 要删除的会员ID
     * @details 根据会员ID查找并删除会员，包含用户友好的提示信息
     */
    void deleteMember(int memberid);
    
    /**
     * @brief 显示所有会员列表
     * @details 遍历所有会员并显示其基本信息，如果没有会员则显示提示信息
     */
    void listAllMembers() const;
    
    /**
     * @brief 根据电话号码查找会员
     * @param phone 要查找的电话号码
     * @details 遍历会员列表查找匹配的电话号码并显示会员信息
     */
    void findMemberByPhone(const std::string& phone) const;
    
    /**
     * @brief 更新会员电话号码
     * @param id 会员ID
     * @param newPhone 新的电话号码
     * @details 根据会员ID查找会员并更新其电话号码
     */
    void updateMemberPhone(int id, const std::string& newPhone);
    
    /**
     * @brief 根据电话号码获取会员ID
     * @param phone 电话号码
     * @return 会员ID，如果未找到则返回-1
     */
    int getMemberIdByPhone(const std::string& phone) const;

    // ==================== 会员积分管理 ====================
    
    /**
     * @brief 添加消费记录并计算积分
     * @param id 会员ID
     * @param amount 消费金额
     * @details 为指定会员添加消费记录并自动计算积分
     */
    void addSpending(int id, double amount);
    
    /**
     * @brief 积分兑换
     * @param id 会员ID
     * @param pointsToRedeem 要兑换的积分数量
     * @details 为指定会员进行积分兑换操作
     */
    void redeemPoints(int id, int pointsToRedeem);

    // ==================== 消费记录管理 ====================
    
    /**
     * @brief 显示会员消费历史
     * @param id 会员ID
     * @param n 显示最近N次消费记录，-1表示显示全部
     * @details 显示指定会员的消费历史记录
     */
    void showMemberSpendingHistory(int id, int n) const;

    // ==================== 系统设置与查询 ====================
    
    /**
     * @brief 设置积分规则
     * @param rule 新的积分规则（1元=多少积分）
     * @details 更新系统积分规则并应用到所有现有会员
     */
    void setPointsRule(int rule);
    
    /**
     * @brief 保存数据到文件
     * @param filename 文件名
     * @details 将所有会员数据以CSV格式保存到指定文件
     */
    void saveToFile(const std::string& filename) const;
    
    /**
     * @brief 从文件加载数据
     * @param filename 文件名
     * @details 从指定CSV文件加载会员数据到系统
     */
    void loadFromFile(const std::string& filename);

};