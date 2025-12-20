#ifndef GAME_CORE_H
#define GAME_CORE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <graphics.h>
#include <conio.h>
#include <cstdlib>  // 包含 rand() 和 srand()
#include <ctime>    // 包含 time()
using namespace std;

#define width 1024 //窗口宽度
#define height 768//窗口高度
#define Game_width 840//游戏窗口宽度
#define Game_height 600//游戏窗口高度
#define Gap 40//方格间距

extern int random_num;

struct Enemy_BasePos {//敌方基地单个坐标结构体
	int x;
	int y;
};

void Game_Init(void);//初始化EasyX窗口、加载资源、初始化游戏数据（得分、难度、最高记录）、生成初始预览防御单位
void Game_Loop(void);// 游戏主循环：处理输入→调用各模块更新→调用绘制函数→控制帧率
void Game_Quit(void);//保存最高分、释放资源、关闭窗口
void Game_Map(int random_num);//绘制游戏地图
void Game_SidebarData(void);//侧边栏数据绘制函数
#endif
