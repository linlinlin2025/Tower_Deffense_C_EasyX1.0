#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <graphics.h>
#include <conio.h>
using namespace std;
  
#define width 1024
#define height 768

void Game_Init();//初始化EasyX窗口、加载资源、初始化游戏数据（得分、难度、最高记录）、生成初始预览防御单位
void Game_Loop();// 游戏主循环：处理输入→调用各模块更新→调用绘制函数→控制帧率
void GameQuit();//保存最高分、释放资源、关闭窗口

int main() {
	
}

void Game_Init()//初始化EasyX窗口、加载资源、初始化游戏数据（得分、难度、最高记录）、生成初始预览防御单位 
{
	initgraph(width , height); 

	//Draw_Map();
}
void Game_Loop()// 游戏主循环：处理输入→调用各模块更新→调用绘制函数→控制帧率 
{
	
}

void GameQuit()//保存最高分、释放资源、关闭窗口
{

}