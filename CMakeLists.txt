# =============================================================================
# 会员管理系统 CMake 构建配置文件
# Member Management System CMake Configuration
# =============================================================================
# 
# 项目信息：
# - 项目名称：MemberSystem
# - 版本：1.0
# - 作者：系统开发者
# - 日期：2024
# 
# 功能说明：
# - 配置 C++20 标准
# - 包含所有源文件和头文件
# - 设置输出目录和包含路径
# - 支持跨平台编译
# =============================================================================

# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本
project(MemberSystem)

# 设置 C++ 标准为 C++20
set(CMAKE_CXX_STANDARD 20)

# 添加所有源文件到构建列表
# 源文件包括：
# - main.cpp：程序入口点
# - Member.cpp：会员类实现
# - System.cpp：系统控制类实现
# - MemberManager.cpp：会员管理器实现
# - Utils.cpp：工具函数实现
set(SOURCES
    main.cpp
    Member.cpp
    System.cpp
    MemberManager.cpp
    Utils.cpp
)

# 创建可执行文件，包含所有源文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置可执行文件输出目录
# 输出到 build/bin 目录，便于管理
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)

# 添加头文件目录
# 包含 include/ 目录，使编译器能找到头文件
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加库文件目录（预留，当前项目未使用外部库）
# 如果后续需要链接外部库，可以在此添加
link_directories(${CMAKE_SOURCE_DIR}/lib)
