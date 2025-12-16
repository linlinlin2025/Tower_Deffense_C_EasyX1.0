#ifndef GAME_MAIN_H
#define GAME_MAIN_H

// 依赖库头文件（确保编译时能找到EasyX相关函数/类型）
#include <graphics.h>
#include <conio.h>

// 窗口与游戏区域配置宏（全局常量，供所有包含该头文件的文件使用）
#define WIDTH 1024          // 总窗口宽度
#define HEIGHT 768          // 总窗口高度
#define GAME_WIDTH 840      // 游戏核心区域宽度
#define GAME_HEIGHT 600     // 游戏核心区域高度
#define GAP 40              // 方格间距（部署/地图网格单位）

// 全局变量声明（extern表示"此处仅声明，定义在.cpp文件中"，避免重复定义）
extern int random_num;

// 函数声明（与.cpp文件中函数定义的返回值、参数列表完全一致）
/**
 * @brief 游戏初始化函数
 * @details 初始化EasyX窗口、绘制边框/网格、加载资源、初始化得分/难度/最高记录、生成初始预览防御单位
 */
void Game_Init();

/**
 * @brief 游戏主循环
 * @details 持续处理用户输入→更新游戏状态（敌人/防御塔/得分）→绘制游戏画面→控制帧率
 */
void Game_Loop();

/**
 * @brief 游戏退出处理
 * @details 保存最高分到文件、释放加载的资源、关闭EasyX窗口
 */
void Game_Quit();

/**
 * @brief 绘制游戏地图
 * @details 根据随机数选择3种地图之一，颜色规则：
 *          红色(RGB(196,43,28))=敌方基地 | 蓝色(RGB(36,98,255))=我方基地
 *          棕色(RGB(185,128,71))=可部署区域 | 深红色(RGB(53,17,10))=不可通行区域
 * @param random_num 地图选择参数（取值范围：1-3）
 */
void Game_Map(int random_num);

#endif // GAME_H
