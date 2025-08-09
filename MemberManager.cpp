/**
 * @file MemberManager.cpp
 * @brief 会员管理器类实现文件
 * @details 实现会员管理器的所有功能，包括会员信息的增删改查、积分管理、消费记录管理和数据持久化等
 * @author 系统开发者
 * @date 2024
 * @version 1.0
 */

// MemberManager.cpp
#include "MemberManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

/**
 * @brief 获取所有会员列表
 * @return 会员向量副本
 */
std::vector<Member> MemberManager::getMembers() const {
    return members;
}

/**
 * @brief 添加新会员
 * @param name 会员姓名
 * @param phone 会员电话
 * @param birthday 会员生日
 * @details 创建新会员对象并添加到会员列表中，自动分配唯一ID
 */
void MemberManager::addMember(const std::string& name, const std::string& phone, const std::string& birthday) {
    Member newMember(nextId++, name, phone, birthday, pointsRule);
    members.push_back(newMember);
    std::cout << "会员 " << name << " 添加成功！ID: " << newMember.getId() << std::endl;
}

/**
 * @brief 删除指定会员
 * @param memberId 要删除的会员ID
 * @details 根据会员ID查找并删除会员，包含用户友好的提示信息
 */
void MemberManager::deleteMember(int memberId) {
    auto it = std::find_if(members.begin(), members.end(),
                           [memberId](const Member& m) { return m.getId() == memberId; });
    if (it != members.end()) {
        std::string memberName = it->getName();
        members.erase(it);
        std::cout << "会员 " << memberName << " (ID: " << memberId << ") 已成功删除！" << std::endl;
    } else {
        std::cout << "未找到ID为 " << memberId << " 的会员！" << std::endl;
    }
}

/**
 * @brief 显示所有会员列表
 * @details 遍历所有会员并显示其完整信息，包括基本信息、等级、积分、消费等
 */
void MemberManager::listAllMembers() const {
    if (members.empty()) {
        std::cout << "当前没有会员记录！" << std::endl;
        return;
    }
    
    std::cout << "\n=== 会员列表 ===" << std::endl;
    std::cout << "总会员数: " << members.size() << " 人\n" << std::endl;
    
    for (const auto& member : members) {
        // 获取等级名称
        std::string levelName;
        switch (member.getCurrentLevel()) {
        case Member::DIAMOND: levelName = "钻石会员"; break;
        case Member::GOLD: levelName = "黄金会员"; break;
        case Member::SILVER: levelName = "白银会员"; break;
        default: levelName = "普通会员"; break;
        }
        
        // 获取折扣率
        double discountRate = member.getDiscountRate();
        std::string discountText = (discountRate < 1.0) ? 
            std::to_string(static_cast<int>(discountRate * 10)) + "折" : "无折扣";
        
        std::cout << "┌─────────────────────────────────────────────────────────────────┐" << std::endl;
        std::cout << "│ 会员ID: " << std::left << std::setw(8) << member.getId() << std::endl;
        std::cout << "│ 姓名: " << std::left << std::setw(15) << member.getName() << std::endl;
        std::cout << "│ 电话: " << std::left << std::setw(15) << member.getPhone() << std::endl;
        std::cout << "│ 生日: " << std::left << std::setw(15) << member.getBirthday() << std::endl;
        std::cout << "│ 等级: " << std::left << std::setw(15) << levelName << std::endl;
        std::cout << "│ 优惠: " << std::left << std::setw(15) << discountText << std::endl;
        std::cout << "│ 总消费: " << std::left << std::setw(5) << std::fixed << std::setprecision(2) << member.getTotalSpent() << "元" << std::endl;
        std::cout << "│ 年度消费: " << std::left << std::setw(5) << std::fixed << std::setprecision(2) << member.getAnnualSpent() << "元" << std::endl;
        std::cout << "│ 积分: " << std::left << std::setw(15) << member.getPoints() << std::endl;
        std::cout << "│ 积分规则: 1元=" << std::left << member.getPointsPerDollar() << "积分" << std::endl;
        std::cout << "│ 上次消费年份: " << std::left << std::setw(15) << member.getLastYear() << std::endl;
        std::cout << "└─────────────────────────────────────────────────────────────────┘" << std::endl;
        std::cout << std::endl;
    }
}

/**
 * @brief 根据电话号码查找会员
 * @param phone 要查找的电话号码
 * @details 遍历会员列表查找匹配的电话号码并显示会员完整信息
 */
void MemberManager::findMemberByPhone(const std::string& phone) const {
    bool found = false;
    for (const auto& member : members) {
        if (member.getPhone() == phone) {
            // 获取等级名称
            std::string levelName;
            switch (member.getCurrentLevel()) {
            case Member::DIAMOND: levelName = "钻石会员"; break;
            case Member::GOLD: levelName = "黄金会员"; break;
            case Member::SILVER: levelName = "白银会员"; break;
            default: levelName = "普通会员"; break;
            }
            
            // 获取折扣率
            double discountRate = member.getDiscountRate();
            std::string discountText = (discountRate < 1.0) ? 
                std::to_string(static_cast<int>(discountRate * 10)) + "折" : "无折扣";
            
            std::cout << "┌─────────────────────────────────────────────────────────────────┐" << std::endl;
            std::cout << "│ 会员ID: " << std::left << std::setw(8) << member.getId() << std::endl;
            std::cout << "│ 姓名: " << std::left << std::setw(15) << member.getName() << std::endl;
            std::cout << "│ 电话: " << std::left << std::setw(15) << member.getPhone() << std::endl;
            std::cout << "│ 生日: " << std::left << std::setw(15) << member.getBirthday() << std::endl;
            std::cout << "│ 等级: " << std::left << std::setw(15) << levelName << std::endl;
            std::cout << "│ 优惠: " << std::left << std::setw(15) << discountText << std::endl;
            std::cout << "│ 总消费: " << std::left << std::setw(5) << std::fixed << std::setprecision(2) << member.getTotalSpent() << "元" << std::endl;
            std::cout << "│ 年度消费: " << std::left << std::setw(5) << std::fixed << std::setprecision(2) << member.getAnnualSpent() << "元" << std::endl;
            std::cout << "│ 积分: " << std::left << std::setw(15) << member.getPoints() << std::endl;
            std::cout << "│ 积分规则: 1元=" << std::left << member.getPointsPerDollar() << "积分" << std::endl;
            std::cout << "│ 上次消费年份: " << std::left << std::setw(15) << member.getLastYear() << std::endl;
            std::cout << "└─────────────────────────────────────────────────────────────────┘" << std::endl;
            std::cout << std::endl;

            found = true;
            break;
        }
    }
    if (!found) std::cout << "未找到该电话的会员！" << std::endl;
}

/**
 * @brief 更新会员电话号码
 * @param id 会员ID
 * @param newPhone 新的电话号码
 * @details 根据会员ID查找会员并更新其电话号码
 */
void MemberManager::updateMemberPhone(int id, const std::string& newPhone) {
    for (auto& member : members) {
        if (member.getId() == id) {
            member = Member(id, member.getName(), newPhone, member.getBirthday(), member.getPointsPerDollar());
            std::cout << "会员 " << id << " 电话已更新为: " << newPhone << std::endl;
            return;
        }
    }
    std::cout << "未找到该ID的会员！" << std::endl;
}

/**
 * @brief 根据电话号码获取会员ID
 * @param phone 电话号码
 * @return 会员ID，如果未找到则返回-1
 */
int MemberManager::getMemberIdByPhone(const std::string& phone) const {
    for (const auto& member : members) {
        if (member.getPhone() == phone) {
            return member.getId();
        }
    }
    return -1;
}

/**
 * @brief 添加消费记录并计算积分
 * @param id 会员ID
 * @param amount 消费金额
 * @details 为指定会员添加消费记录并自动计算积分
 */
void MemberManager::addSpending(int id, double amount) {
    for (auto& member : members) {
        if (member.getId() == id) {
            member.addSpending(amount);
            return;
        }
    }
    std::cout << "未找到该ID的会员！" << std::endl;
}

/**
 * @brief 积分兑换
 * @param id 会员ID
 * @param pointsToRedeem 要兑换的积分数量
 * @details 为指定会员进行积分兑换操作
 */
void MemberManager::redeemPoints(int id, int pointsToRedeem) {
    for (auto& member : members) {
        if (member.getId() == id) {
            member.redeemPoints(pointsToRedeem);
            return;
        }
    }
    std::cout << "未找到该ID的会员！" << std::endl;
}

/**
 * @brief 显示会员消费历史
 * @param id 会员ID
 * @param n 显示最近N次消费记录，-1表示显示全部
 * @details 显示指定会员的消费历史记录，包含会员基本信息
 */
void MemberManager::showMemberSpendingHistory(int id, int n) const {
    for (const auto& member : members) {
        if (member.getId() == id) {
            // 获取等级名称
            std::string levelName;
            switch (member.getCurrentLevel()) {
            case Member::DIAMOND: levelName = "钻石会员"; break;
            case Member::GOLD: levelName = "黄金会员"; break;
            case Member::SILVER: levelName = "白银会员"; break;
            default: levelName = "普通会员"; break;
            }
            
            // 获取折扣率
            double discountRate = member.getDiscountRate();
            std::string discountText = (discountRate < 1.0) ? 
                std::to_string(static_cast<int>(discountRate * 10)) + "折" : "无折扣";
            
            // 显示会员基本信息
            std::cout << "\n=== 会员消费历史 ===" << std::endl;
            std::cout << "┌─────────────────────────────────────────────────────────────────┐" << std::endl;
            std::cout << "│ 会员ID: " << std::left << std::setw(8) << member.getId() << std::endl;
            std::cout << "│ 姓名: " << std::left << std::setw(15) << member.getName() << std::endl;
            std::cout << "│ 电话: " << std::left << std::setw(15) << member.getPhone() << std::endl;
            std::cout << "│ 生日: " << std::left << std::setw(15) << member.getBirthday() << std::endl;
            std::cout << "│ 等级: " << std::left << std::setw(15) << levelName << std::endl;
            std::cout << "│ 优惠: " << std::left << std::setw(15) << discountText << std::endl;
            std::cout << "│ 总消费: " << std::left << std::setw(15) << std::fixed << std::setprecision(2) << member.getTotalSpent() << "元" << std::endl;
            std::cout << "│ 年度消费: " << std::left << std::setw(15) << std::fixed << std::setprecision(2) << member.getAnnualSpent() << "元" << std::endl;
            std::cout << "│ 积分: " << std::left << std::setw(15) << member.getPoints() << std::endl;
            std::cout << "│ 积分规则: 1元=" << std::left << std::setw(15) << member.getPointsPerDollar() << "积分" << std::endl;
            std::cout << "│ 上次消费年份: " << std::left << std::setw(15) << member.getLastYear() << std::endl;
            std::cout << "└─────────────────────────────────────────────────────────────────┘" << std::endl;
            
            // 显示消费历史
            member.showConsumptionHistory(n);
            return;
        }
    }
    std::cout << "未找到该ID的会员！" << std::endl;
}

/**
 * @brief 设置积分规则
 * @param rule 新的积分规则（1元=多少积分）
 * @details 更新系统积分规则并应用到所有现有会员
 */
void MemberManager::setPointsRule(int rule) {
    pointsRule = rule;
    for (auto& member : members) {
        member.setPointsRule(rule);
    }
    std::cout << "积分规则已更新：1元=" << rule << "积分" << std::endl;
}

/**
 * @brief 保存数据到文件
 * @param filename 文件名
 * @details 将所有会员数据以CSV格式保存到指定文件
 */
void MemberManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }
    
    // 保存每个会员的完整信息到CSV格式
    for (const auto& member : members) {
        file << member.getId() << ","
            << member.getName() << ","
            << member.getPhone() << ","
            << member.getBirthday() << ","
            << member.getTotalSpent() << ","
            << member.getPoints() << ","
            << member.getPointsPerDollar() << ","
            << member.getAnnualSpent() << ","
            << static_cast<int>(member.getCurrentLevel()) << ","
            << member.getLastYear() << "\n";
    }
    file.close();
    std::cout << "数据已保存到文件: " << filename << std::endl;
}

/**
 * @brief 从文件加载数据
 * @param filename 文件名
 * @details 从指定CSV文件加载会员数据到系统
 */
void MemberManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }
    
    // 清空现有数据并重置ID计数器
    members.clear();
    nextId = 1;
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> data;
        
        // 解析CSV格式的数据
        while (std::getline(iss, token, ',')) {
            data.push_back(token);
        }
        
        // 验证数据完整性（应该有10个字段）
        if (data.size() != 10) continue;
        
        // 解析各个字段并创建会员对象
        int id = std::stoi(data[0]);
        nextId = std::max(nextId, id + 1);  // 更新下一个可用ID
        
        // 确保数值字段有效
        double totalSpent = std::stod(data[4]);
        int points = std::stoi(data[5]);
        int pointsRule = std::stoi(data[6]);
        double annualSpent = std::stod(data[7]);
        int level = std::stoi(data[8]);
        int lastYear = std::stoi(data[9]);
        
        // 验证数值的有效性
        if (totalSpent < 0) totalSpent = 0.0;
        if (points < 0) points = 0;
        if (pointsRule < 1) pointsRule = 1;
        if (annualSpent < 0) annualSpent = 0.0;
        if (level < 0 || level > 3) level = 0;  // 0-3 对应 NORMAL-DIAMOND
        if (lastYear < 0) lastYear = 0;
        
        Member member(id, data[1], data[2], data[3], pointsRule,
                     annualSpent, static_cast<Member::Level>(level),
                     lastYear);
        
        // 恢复会员的积分规则
        member.setPointsRule(pointsRule);
        
        members.push_back(member);
    }
    file.close();
    std::cout << "数据已从文件加载: " << filename << std::endl;
}
