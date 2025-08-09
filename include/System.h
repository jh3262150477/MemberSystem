#pragma once
#include "MemberManager.h"
#include "Utils.h"

/**
 * @class System
 * @brief 会员管理系统主控制类
 * @details 负责处理用户界面交互、菜单显示和业务逻辑控制
 *          包含会员信息管理、积分管理、消费记录管理和系统设置等功能模块
 */
class System {
private:
    MemberManager manager;  ///< 会员管理器对象，负责具体的业务逻辑处理

public:
    /**
     * @brief 系统主运行函数
     * @details 启动系统并进入主控制循环
     */
    void run();

private:
    // ==================== 菜单显示函数 ====================
    
    /**
     * @brief 显示系统主菜单
     * @details 展示系统的主要功能模块供用户选择
     */
    void showMainMenu() const;
    
    /**
     * @brief 显示会员信息管理子菜单
     * @details 展示会员信息管理的具体功能选项
     */
    void showMemberInfoMenu() const;
    
    /**
     * @brief 显示会员积分管理子菜单
     * @details 展示积分管理的具体功能选项
     */
    void showPointsMenu() const;
    
    /**
     * @brief 显示消费记录管理子菜单
     * @details 展示消费记录管理的具体功能选项
     */
    void showConsumptionMenu() const;
    
    /**
     * @brief 显示系统设置与查询子菜单
     * @details 展示系统设置的具体功能选项
     */
    void showSystemMenu() const;

    // ==================== 模块处理函数 ====================
    
    /**
     * @brief 处理会员信息管理模块
     * @details 显示会员信息管理子菜单并处理相关操作
     */
    void handleMemberInfo();
    
    /**
     * @brief 处理会员积分管理模块
     * @details 显示积分管理子菜单并处理相关操作
     */
    void handlePoints();
    
    /**
     * @brief 处理消费记录管理模块
     * @details 显示消费记录管理子菜单并处理相关操作
     */
    void handleConsumption();
    
    /**
     * @brief 处理系统设置与查询模块
     * @details 显示系统设置子菜单并处理相关操作
     */
    void handleSystemSettings();

    // ==================== 会员信息管理功能 ====================
    
    /**
     * @brief 处理添加新会员操作
     * @details 收集用户输入的会员信息并调用管理器添加会员
     */
    void handleAddMember();
    
    /**
     * @brief 处理查看所有会员列表操作
     * @details 调用管理器显示所有会员信息
     */
    void handleListMembers();
    
    /**
     * @brief 处理根据电话查询会员操作
     * @details 根据用户输入的电话号码查找并显示会员信息
     */
    void handleFindMember();
    
    /**
     * @brief 处理修改会员电话操作
     * @details 根据会员ID修改其电话号码
     */
    void handleUpdatePhone();
    
    /**
     * @brief 处理删除会员操作
     * @details 根据会员ID删除会员，包含确认机制防止误删
     */
    void handleDeleteMember();

    // ==================== 会员积分管理功能 ====================
    
    /**
     * @brief 处理添加消费并计算积分操作
     * @details 支持通过会员ID或电话号码添加消费记录并自动计算积分
     */
    void handleAddSpending();
    
    /**
     * @brief 处理积分兑换操作
     * @details 根据会员ID和兑换积分数量进行积分兑换
     */
    void handleRedeemPoints();
    
    /**
     * @brief 处理查看积分历史操作
     * @details 显示指定会员的最近N次消费记录
     */
    void handleShowPointsHistory();

    // ==================== 消费记录管理功能 ====================
    
    /**
     * @brief 处理查看会员消费明细操作
     * @details 显示指定会员的所有消费记录
     */
    void handleShowConsumption();
    
    /**
     * @brief 处理统计总消费金额操作
     * @details 计算并显示指定会员的总消费金额
     */
    void handleTotalSpent();
    
    /**
     * @brief 处理查看最近消费记录操作
     * @details 显示指定会员的最近N次消费记录
     */
    void handleRecentConsumption();

    // ==================== 系统设置与查询功能 ====================
    
    /**
     * @brief 处理会员等级预测操作
     * @details 根据会员当前消费情况预测年度可能达到的等级
     */
    void handleLevelPrediction();
    
    /**
     * @brief 处理设置积分规则操作
     * @details 设置消费金额与积分的兑换比例
     */
    void handleSetPointsRule();
    
    /**
     * @brief 处理保存数据到文件操作
     * @details 将当前所有会员数据保存到指定文件
     */
    void handleSaveData();
    
    /**
     * @brief 处理从文件加载数据操作
     * @details 从指定文件加载会员数据到系统
     */
    void handleLoadData();
    
    /**
     * @brief 处理退出系统操作
     * @details 显示退出信息并结束程序
     */
    void handleExit();
};