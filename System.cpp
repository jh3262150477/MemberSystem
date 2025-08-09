/**
 * @file System.cpp
 * @brief 系统主控制类实现文件
 * @details 实现会员管理系统的主要控制逻辑，包括用户界面交互、菜单显示和业务逻辑控制
 * @author 系统开发者
 * @date 2024
 * @version 1.0
 */

#include "System.h"
#include "Utils.h"
#include <iostream>
#include <limits>
#include <iomanip>

/**
 * @brief 系统主运行函数
 * @details 显示主菜单并处理用户选择，实现系统的主要控制循环
 */
void System::run() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                    欢迎使用会员管理系统                          ║" << std::endl;
    std::cout << "║                        Member Management System                  ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════════════════╝" << std::endl;
    
    while (true) {
        showMainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: handleMemberInfo(); break;      // 会员信息管理
        case 2: handlePoints(); break;          // 会员积分管理
        case 3: handleConsumption(); break;     // 消费记录管理
        case 4: handleSystemSettings(); break;  // 系统设置与查询
        case 0: handleExit(); return;           // 退出系统
        default: std::cout << "无效选项！请重新选择。" << std::endl;
        }
    }
}

/**
 * @brief 显示系统主菜单
 * @details 展示系统的主要功能模块供用户选择
 */
void System::showMainMenu() const {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        会员管理系统主菜单                        │" << std::endl;
    std::cout << "├──────────────────────────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  [1] 会员信息管理  - 添加、查询、修改、删除会员信息              │" << std::endl;
    std::cout << "│  [2] 会员积分管理  - 积分计算、兑换、查询积分历史                │" << std::endl;
    std::cout << "│  [3] 消费记录管理  - 消费记录、统计、查询消费明细                │" << std::endl;
    std::cout << "│  [4] 系统设置查询  - 积分规则设置、数据保存加载                  │" << std::endl;
    std::cout << "│  [0] 退出系统      - 安全退出会员管理系统                        │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    std::cout << "请输入选项 [0-4]: ";
}

/**
 * @brief 处理会员信息管理模块
 * @details 显示会员信息管理子菜单并处理相关操作
 */
void System::handleMemberInfo() {
    while (true) {
        showMemberInfoMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) break;  // 返回主菜单
        switch (choice) {
        case 1: handleAddMember(); break;     // 添加新会员
        case 2: handleListMembers(); break;   // 查看所有会员
        case 3: handleFindMember(); break;    // 查询会员
        case 4: handleUpdatePhone(); break;   // 修改会员信息
        case 5: handleDeleteMember(); break;  // 删除会员
        default: std::cout << "无效选项！请重新选择。" << std::endl;
        }
    }
}

/**
 * @brief 显示会员信息管理子菜单
 * @details 展示会员信息管理的具体功能选项
 */
void System::showMemberInfoMenu() const {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        会员信息管理                              │" << std::endl;
    std::cout << "├──────────────────────────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  [1] 添加新会员      - 注册新会员信息                            │" << std::endl;
    std::cout << "│  [2] 查看所有会员    - 显示所有会员完整信息                      │" << std::endl;
    std::cout << "│  [3] 根据电话查询    - 通过电话号码查找会员                      │" << std::endl;
    std::cout << "│  [4] 修改会员信息    - 更新会员电话号码等基本信息                │" << std::endl;
    std::cout << "│  [5] 删除会员        - 删除指定会员（需确认）                    │" << std::endl;
    std::cout << "│  [0] 返回主菜单      - 返回系统主菜单                            │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    std::cout << "请输入选项 [0-5]: ";
}

/**
 * @brief 处理会员积分管理模块
 * @details 显示积分管理子菜单并处理相关操作
 */
void System::handlePoints() {
    while (true) {
        showPointsMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) break;  // 返回主菜单
        switch (choice) {
        case 1: handleAddSpending(); break;      // 添加消费并计算积分
        case 2: handleRedeemPoints(); break;     // 积分兑换
        case 3: handleShowPointsHistory(); break; // 查看积分历史
        default: std::cout << "无效选项！请重新选择。" << std::endl;
        }
    }
}

/**
 * @brief 显示会员积分管理子菜单
 * @details 展示积分管理的具体功能选项
 */
void System::showPointsMenu() const {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        会员积分管理                              │" << std::endl;
    std::cout << "├──────────────────────────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  [1] 添加消费记录    - 记录消费并自动计算积分                    │" << std::endl;
    std::cout << "│  [2] 积分兑换        - 使用积分兑换商品或服务                    │" << std::endl;
    std::cout << "│  [3] 查看积分历史    - 显示会员积分变化记录                      │" << std::endl;
    std::cout << "│  [0] 返回主菜单      - 返回系统主菜单                            │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    std::cout << "请输入选项 [0-3]: ";
}

/**
 * @brief 处理消费记录管理模块
 * @details 显示消费记录管理子菜单并处理相关操作
 */
void System::handleConsumption() {
    while (true) {
        showConsumptionMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) break;  // 返回主菜单
        switch (choice) {
        case 1: handleAddSpending(); break;      // 添加消费记录
        case 2: handleShowConsumption(); break;  // 查看消费明细
        case 3: handleTotalSpent(); break;       // 统计总消费
        case 4: handleRecentConsumption(); break; // 查看最近消费
        default: std::cout << "无效选项！请重新选择。" << std::endl;
        }
    }
}

/**
 * @brief 显示消费记录管理子菜单
 * @details 展示消费记录管理的具体功能选项
 */
void System::showConsumptionMenu() const {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        消费记录管理                              │" << std::endl;
    std::cout << "├──────────────────────────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  [1] 添加消费记录    - 记录会员消费信息                          │" << std::endl;
    std::cout << "│  [2] 查看消费明细    - 显示会员详细消费记录                      │" << std::endl;
    std::cout << "│  [3] 统计总消费      - 计算会员累计消费金额                      │" << std::endl;
    std::cout << "│  [4] 查看最近消费    - 显示最近N次消费记录                       │" << std::endl;
    std::cout << "│  [0] 返回主菜单      - 返回系统主菜单                            │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    std::cout << "请输入选项 [0-4]: ";
}

/**
 * @brief 处理系统设置与查询模块
 * @details 显示系统设置子菜单并处理相关操作
 */
void System::handleSystemSettings() {
    while (true) {
        showSystemMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                handleSetPointsRule();
                break;
            case 2:
                handleSaveData();
                break;
            case 3:
                handleLoadData();
                break;
            case 4:
                handleLevelPrediction();
                break;
            case 0:
                return;
            default:
                std::cout << "无效的选择，请重试！\n";
        }
        std::cout << "\n按回车键继续...";
        std::cin.get();
    }
}

/**
 * @brief 显示系统设置与查询子菜单
 * @details 展示系统设置的具体功能选项
 */
void System::showSystemMenu() const {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                      系统设置与查询                              │" << std::endl;
    std::cout << "├──────────────────────────────────────────────────────────────────┤" << std::endl;
    std::cout << "│  [1] 设置积分规则                                                │" << std::endl;
    std::cout << "│  [2] 保存数据到文件                                              │" << std::endl;
    std::cout << "│  [3] 从文件加载数据                                              │" << std::endl;
    std::cout << "│  [4] 会员等级预测器                                              │" << std::endl;
    std::cout << "│  [0] 返回主菜单                                                  │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    std::cout << "请输入选项 [0-4]: ";
}

// ==================== 会员信息管理功能实现 ====================

/**
 * @brief 处理添加新会员操作
 * @details 收集用户输入的会员信息并调用管理器添加会员
 */
void System::handleAddMember() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                          添加新会员                              │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    // 获取并验证中文姓名
    std::string name;
    while (true) {
        name = Utils::getStringInput("请输入会员姓名: ", 20);
        if (Utils::isValidChineseName(name)) {
            break;
        }
        Utils::showError("姓名格式无效！请输入2-10个中文字符。");
    }
    
    // 获取并验证电话号码
    std::string phone;
    while (true) {
        phone = Utils::getStringInput("请输入联系电话: ", 15);
        if (Utils::isValidPhoneNumber(phone)) {
            break;
        }
        Utils::showError("电话号码格式无效！请输入7-8位座机号或11位手机号（仅数字）。");
    }
    
    // 获取并验证生日
    std::string birthday;
    while (true) {
        birthday = Utils::getStringInput("请输入会员生日（YYYY-MM-DD格式）: ", 10);
        if (Utils::isValidBirthday(birthday)) {
            break;
        }
        Utils::showError("生日格式无效！请输入YYYY-MM-DD格式的有效日期（不能是未来日期）。");
    }
    
    std::cout << "\n";
    manager.addMember(name, phone, birthday);
}

/**
 * @brief 处理查看所有会员列表操作
 * @details 调用管理器显示所有会员信息
 */
void System::handleListMembers() {
    std::cout << "\n";
    manager.listAllMembers();
}

/**
 * @brief 处理根据电话查询会员操作
 * @details 根据用户输入的电话号码查找并显示会员信息
 */
void System::handleFindMember() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                          查询会员                                │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    std::string phone;
    while (true) {
        phone = Utils::getStringInput("请输入要查询的电话号码: ", 15);
        if (Utils::isValidPhoneNumber(phone)) {
            break;
        }
        Utils::showError("电话号码格式无效！请输入7-8位座机号或11位手机号（仅数字）。");
    }
    
    std::cout << "\n";
    manager.findMemberByPhone(phone);
}

/**
 * @brief 处理修改会员电话操作
 * @details 根据会员ID修改其电话号码
 */
void System::handleUpdatePhone() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        修改会员信息                              │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入要修改的会员ID: ", 1, 999999);
    
    std::string newPhone;
    while (true) {
        newPhone = Utils::getStringInput("请输入新的电话号码: ", 15);
        if (Utils::isValidPhoneNumber(newPhone)) {
            break;
        }
        Utils::showError("电话号码格式无效！请输入7-8位座机号或11位手机号（仅数字）。");
    }
    
    std::cout << "\n";
    manager.updateMemberPhone(id, newPhone);
}

/**
 * @brief 处理删除会员操作
 * @details 根据会员ID删除会员，包含确认机制防止误删
 */
void System::handleDeleteMember() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                          删除会员                                │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入要删除的会员ID: ", 1, 999999);
    
    // 确认删除操作，防止误删
    std::cout << "\n警告：此操作不可撤销！" << std::endl;
    std::string confirm = Utils::getStringInput("确认要删除ID为 " + std::to_string(id) + " 的会员吗？(y/n): ", 10);
    
    std::cout << "\n";
    if (confirm == "y" || confirm == "Y") {
        manager.deleteMember(id);
    } else {
        Utils::showSuccess("删除操作已取消。");
    }
}

// ==================== 会员积分管理功能实现 ====================

/**
 * @brief 处理添加消费并计算积分操作
 * @details 支持通过会员ID或电话号码添加消费记录并自动计算积分
 */
void System::handleAddSpending() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        添加消费记录                              │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    std::string input = Utils::getStringInput("请输入会员ID或电话号码: ", 15);

    int id;
    // 判断输入是ID还是电话号码
    if (!input.empty() && std::isdigit(input[0])) {
        try {
            id = std::stoi(input);
            // 验证ID是否有效
            if (!Utils::isInRange(id, 1, 999999)) {
                Utils::showError("会员ID格式无效！请输入1-999999之间的整数。");
                return;
            }
            // 验证ID是否存在
            bool found = false;
            for (const auto& member : manager.getMembers()) {
                if (member.getId() == id) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                Utils::showError("未找到该ID的会员！");
                return;
            }
        }
        catch (...) {
            Utils::showError("输入无效！");
            return;
        }
    }
    else {
        // 验证电话号码格式
        if (!Utils::isValidPhoneNumber(input)) {
            Utils::showError("电话号码格式无效！");
            return;
        }
        // 通过电话号码查找会员ID
        id = manager.getMemberIdByPhone(input);
        if (id == -1) {
            Utils::showError("未找到该电话的会员！");
            return;
        }
    }

    double amount = Utils::getDoubleInput("请输入消费金额: ", 0.01, 1000000.0);
    
    std::cout << "\n";
    manager.addSpending(id, amount);
}

/**
 * @brief 处理积分兑换操作
 * @details 根据会员ID和兑换积分数量进行积分兑换
 */
void System::handleRedeemPoints() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                          积分兑换                                │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入会员ID: ", 1, 999999);
    int points = Utils::getIntInput("请输入要兑换的积分数量: ", 1, 1000000);
    
    std::cout << "\n";
    manager.redeemPoints(id, points);
}

/**
 * @brief 处理查看积分历史操作
 * @details 显示指定会员的最近N次消费记录
 */
void System::handleShowPointsHistory() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        查看积分历史                              │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入会员ID: ", 1, 999999);
    int n = Utils::getIntInput("请输入要查看的最近消费记录数量: ", 1, 1000);
    
    std::cout << "\n";
    manager.showMemberSpendingHistory(id, n);
}

// ==================== 消费记录管理功能实现 ====================

/**
 * @brief 处理查看会员消费明细操作
 * @details 显示指定会员的所有消费记录
 */
void System::handleShowConsumption() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        查看消费明细                              │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入会员ID: ", 1, 999999);
    
    std::cout << "\n";
    manager.showMemberSpendingHistory(id, -1); // -1表示显示全部记录
}

/**
 * @brief 处理统计总消费金额操作
 * @details 计算并显示指定会员的总消费金额
 */
void System::handleTotalSpent() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        统计总消费金额                             │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入会员ID: ", 1, 999999);
    
    std::cout << "\n";
    for (const auto& member : manager.getMembers()) {
        if (member.getId() == id) {
            std::cout << "┌─────────────────────────────────────────────────────────────────┐" << std::endl;
            std::cout << "│ 会员姓名: " << std::left << std::setw(15) << member.getName() << std::endl;
            std::cout << "│ 会员ID: " << std::left << std::setw(15) << member.getId() << std::endl;
            std::cout << "│ 总消费金额: " << std::left << std::setw(15) << std::fixed << std::setprecision(2) << member.getTotalSpent() << "元" << std::endl;
            std::cout << "│ 年度消费: " << std::left << std::setw(15) << std::fixed << std::setprecision(2) << member.getAnnualSpent() << "元" << std::endl;
            std::cout << "└─────────────────────────────────────────────────────────────────┘" << std::endl;
            return;
        }
    }
    Utils::showError("未找到该ID的会员！");
}

/**
 * @brief 处理查看最近消费记录操作
 * @details 显示指定会员的最近N次消费记录
 */
void System::handleRecentConsumption() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        查看最近消费记录                           │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int id = Utils::getIntInput("请输入会员ID: ", 1, 999999);
    int n = Utils::getIntInput("请输入要查看的最近消费记录数量: ", 1, 1000);
    
    std::cout << "\n";
    manager.showMemberSpendingHistory(id, n);
}

// ==================== 系统设置与查询功能实现 ====================

/**
 * @brief 处理设置积分规则操作
 * @details 设置消费金额与积分的兑换比例
 */
void System::handleSetPointsRule() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        设置积分规则                               │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    int rule = Utils::getIntInput("请输入新的积分规则（1元 = ?积分）: ", 1, 100);
    
    std::cout << "\n";
    manager.setPointsRule(rule);
}

/**
 * @brief 处理保存数据到文件操作
 * @details 将当前所有会员数据保存到指定文件
 */
void System::handleSaveData() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                          保存数据                                │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    std::cout << "请输入保存文件名（默认为members.dat）: ";
    std::string filename;
    getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "members.dat";
    }
    
    std::cout << "\n";
    manager.saveToFile(filename);
}

/**
 * @brief 处理从文件加载数据操作
 * @details 从指定文件加载会员数据到系统
 */
void System::handleLoadData() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                          加载数据                                │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    
    std::cout << "请输入加载文件名（默认为members.dat）: ";
    std::string filename;
    getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "members.dat";
    }
    
    std::cout << "\n";
    manager.loadFromFile(filename);
}

/**
 * @brief 处理退出系统操作
 * @details 显示退出信息并结束程序
 */
void System::handleExit() {
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                        感谢使用会员管理系统                      ║" << std::endl;
    std::cout << "║                        Thanks for using MMS                      ║" << std::endl;
    std::cout << "║                              再见！                              ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << "\n按任意键退出..." << std::endl;
    std::cin.get();
}

void System::handleLevelPrediction() {
    std::cout << "\n";
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                        会员等级预测                              │" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;

    // 获取会员手机号
    std::string input = Utils::getStringInput("请输入会员ID或电话号码: ", 15);

    int id;
    // 判断输入是ID还是电话号码
    if (!input.empty() && std::isdigit(input[0])) {
        try {
            id = std::stoi(input);
            // 验证ID是否有效
            if (!Utils::isInRange(id, 1, 999999)) {
                Utils::showError("会员ID格式无效！请输入1-999999之间的整数。");
                return;
            }
            // 验证ID是否存在
            bool found = false;
            for (const auto& member : manager.getMembers()) {
                if (member.getId() == id) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                Utils::showError("未找到该ID的会员！");
                return;
            }
        }
        catch (...) {
            Utils::showError("输入无效！");
            return;
        }
    }
    else {
        // 验证电话号码格式
        if (!Utils::isValidPhoneNumber(input)) {
            Utils::showError("电话号码格式无效！");
            return;
        }
        // 通过电话号码查找会员ID
        id = manager.getMemberIdByPhone(input);
        if (id == -1) {
            Utils::showError("未找到该电话的会员！");
            return;
        }
    }

    // 查找会员
    const Member* foundMember = nullptr;
    const auto& members = manager.getMembers(); // 显式引用绑定，延长生命周期

    for (const Member& member : members) {
        if (member.getId() == id) {
            foundMember = &member; // 安全：指向持久对象
            break;
        }
    }

    if (!foundMember) {
        Utils::showError("未找到该会员！");
        return;
    }

    // 获取当前信息
    double currentSpent = foundMember->getAnnualSpent();
    Member::Level currentLevel = foundMember->getCurrentLevel();
    
    // 验证消费金额的有效性
    if (currentSpent < 0) {
        currentSpent = 0.0;
    }

    std::string levelStr;
    switch (currentLevel) {
    case Member::NORMAL: levelStr = "普通会员"; break;
    case Member::SILVER: levelStr = "银卡会员"; break;
    case Member::GOLD: levelStr = "金卡会员"; break;
    case Member::DIAMOND: levelStr = "钻石会员"; break;
    default: levelStr = "普通会员"; break;
    }

    // 获取当前时间信息
    time_t now = time(0);
    struct tm ltm;
#ifdef _WIN32
    localtime_s(&ltm, &now);
#else
    localtime_r(&now, &ltm);
#endif
    int currentMonth = ltm.tm_mon + 1;
    if (currentMonth <= 0 || currentMonth > 12) {
        currentMonth = 1;  // 如果月份无效，默认为1月
    }
    int remainingMonths = 12 - currentMonth;

    // 计算月均消费
    double monthlyAverage = (currentMonth > 0) ? (currentSpent / currentMonth) : 0.0;
    double predictedSpent = currentSpent + (monthlyAverage * remainingMonths);

    // 显示当前状态
    std::cout << "\n当前状态：" << std::endl;
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│ 当前消费额：" << std::fixed << std::setprecision(2) << currentSpent << "元" << std::endl;
    std::cout << "│ 当前等级：" << levelStr << std::endl;
    std::cout << "│ 月均消费：" << std::fixed << std::setprecision(2) << monthlyAverage << "元" << std::endl;
    std::cout << "│ 剩余月份：" << remainingMonths << "个月" << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;

    // 预测年末等级
    Member::Level predictedLevel = currentLevel;
    if (predictedSpent >= 20000) {
        predictedLevel = Member::DIAMOND;
    }
    else if (predictedSpent >= 10000) {
        predictedLevel = Member::GOLD;
    }
    else if (predictedSpent >= 5000) {
        predictedLevel = Member::SILVER;
    }
    else {
        predictedLevel = Member::NORMAL;
    }

    // 显示预测结果
    std::cout << "\n预测结果：" << std::endl;
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    std::string predictedLevelStr;
    switch (predictedLevel) {
    case Member::NORMAL: predictedLevelStr = "普通会员(无折扣)"; break;
    case Member::SILVER: predictedLevelStr = "银卡会员(95折)"; break;
    case Member::GOLD: predictedLevelStr = "金卡会员(9折)"; break;
    case Member::DIAMOND: predictedLevelStr = "钻石会员(8折)"; break;
    default: predictedLevelStr = "普通会员(无折扣)"; break;
    }

    std::cout << "│ 预测年末消费：" << std::fixed << std::setprecision(2) << predictedSpent << "元" << std::endl;
    std::cout << "│ 预测年末等级：" << predictedLevelStr << std::endl;
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;

    // 计算升级所需金额
    double upgradeAmount = 0;
    std::string nextLevelStr;
    if (currentLevel == Member::NORMAL && predictedLevel == Member::SILVER) {
        upgradeAmount = 5000 - currentSpent;
        nextLevelStr = "银卡会员(95折)";
    }
    else if (currentLevel == Member::SILVER && predictedLevel == Member::GOLD) {
        upgradeAmount = 10000 - currentSpent;
        nextLevelStr = "金卡会员(9折)";
    }
    else if (currentLevel == Member::GOLD && predictedLevel == Member::DIAMOND) {
        upgradeAmount = 20000 - currentSpent;
        nextLevelStr = "钻石会员(8折)";
    }

    // 显示升级建议
    if (upgradeAmount > 0) {
        std::cout << "\n升级建议：" << std::endl;
        std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
        std::cout << "│ 距离" << nextLevelStr << "还需消费：" << std::fixed << std::setprecision(2) << upgradeAmount << "元" << std::endl;
        
        // 提供具体的升级建议
        if (upgradeAmount <= 2000) {
            std::cout << "│ 建议：推荐购买季度健身套餐(1500元)可提前升级" << std::endl;
        }
        else if (upgradeAmount <= 5000) {
            std::cout << "│ 建议：推荐购买年度健身套餐(3000元)可提前升级" << std::endl;
        }
        else if (upgradeAmount <= 10000) {
            std::cout << "│ 建议：推荐购买高级私教课程(5000元)可提前升级" << std::endl;
        }
        else {
            std::cout << "│ 建议：推荐购买VIP会员套餐(10000元)可提前升级" << std::endl;
        }
        std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
    }

    // 显示消费趋势分析
    std::cout << "\n消费趋势分析：" << std::endl;
    std::cout << "┌──────────────────────────────────────────────────────────────────┐" << std::endl;
    if (monthlyAverage >= 2000) {
        std::cout << "│ 您的消费能力很强，建议考虑升级到更高级别的会员" << std::endl;
    }
    else if (monthlyAverage >= 1000) {
        std::cout << "│ 您的消费能力良好，保持当前消费习惯即可" << std::endl;
    }
    else {
        std::cout << "│ 建议适当增加消费频率，以获得更多会员权益" << std::endl;
    }
    std::cout << "└──────────────────────────────────────────────────────────────────┘" << std::endl;
}