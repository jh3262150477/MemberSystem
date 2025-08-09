#include "include/System.h"

/**
 * @brief 程序主函数
 * @details 创建系统对象并启动会员管理系统
 * @return 程序退出码，0表示正常退出
 */
int main() {
    System system;  ///< 创建系统对象
    system.run();   ///< 启动系统主循环
    return 0;       ///< 正常退出
}