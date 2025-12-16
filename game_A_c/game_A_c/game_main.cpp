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

int random_num;

void Game_Init();//初始化EasyX窗口、加载资源、初始化游戏数据（得分、难度、最高记录）、生成初始预览防御单位
void Game_Loop();// 游戏主循环：处理输入→调用各模块更新→调用绘制函数→控制帧率
void Game_Quit();//保存最高分、释放资源、关闭窗口
void Game_Map(int random_num);//绘制游戏地图

int main() {
	// 在程序开始时设置随机种子
	srand(time(NULL));
	random_num = (int)rand()%3+1;  // 生成1到3之间的随机数
	Game_Init();
	Game_Map(random_num);

	Game_Quit();
	return 0;
}

void Game_Init()//初始化EasyX窗口、加载资源、初始化游戏数据（得分、难度、最高记录）、生成初始预览防御单位 
{
	initgraph(width , height, EX_DBLCLKS);
	setbkcolor(RGB(237, 231, 216));
	cleardevice();//用白色清屏

	setlinecolor(BLACK);//设置线条颜色为黑色
	setlinestyle(PS_SOLID, 2);//设置线条为实线，宽度为3
	line(0, 0, width, 0);//上边框
	line(0, Game_height, Game_width, Game_height);//下边框
	line(0, 0, 0, Game_height);//左边框
	line(Game_width, 0, Game_width, height);//右边框

	//画方格
	for (int i = 0; i < Game_height; i += Gap)
	{
		setlinecolor(RGB(200, 200, 200));//设置线条颜色为黑色
		setlinestyle(PS_SOLID, 1);//设置线条为实线，宽度为3
		line(0, i, Game_width, i);
	}for (int i = 0; i < Game_width; i += Gap)
	{
		setlinecolor(RGB(200, 200, 200));//设置线条颜色为黑色
		setlinestyle(PS_SOLID, 1);//设置线条为实线，宽度为3
		line(i, 0, i, Game_height);
	}
	
}
void Game_Loop()// 游戏主循环：处理输入→调用各模块更新→调用绘制函数→控制帧率 
{
	
}

void Game_Quit()//保存最高分、释放资源、关闭窗口
{

	//关闭画布
	_getch();
	closegraph();	
}

/**
 * @brief 三种游戏地图
 * @details 通过参数选择地图，红方块是敌方基地，蓝色是我方基地，棕色是防御单位可部署区域,深红色为不可通行区域
 * @param 随机值 random_num (1-3)
 * @retval 无
 * 
 */

void Game_Map(int random_num)
{
	switch (random_num) {
	case 1:
		//地图1的绘制代码
		setfillcolor(RGB(196, 43, 28));//红色敌方基地
		for (int i = 0; i < Gap * 2; i += Gap) {
			for (int j = 0; j < Gap * 2; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//左上角
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//右上角
			}
		}
		for (int i = 0; i < Gap * 2; i += Gap) {//左下角
			for (int j = Game_height - Gap * 2; j < Game_height; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//右下角
			}
		}

		setfillcolor(RGB(36, 98, 255));//蓝色我方基地
		fillrectangle(10 * Gap, 7 * Gap, 11 * Gap, 8 * Gap);

		setfillcolor(RGB(185, 128, 71));//棕色
		for(int i = 5 * Gap; i < 8 * Gap; i += Gap) {//中间左侧
			for (int j = 3 * Gap; j < 12 * Gap; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//中间右侧	
			}
		}
		break;
	case 2:
		//地图2的绘制代码
		setfillcolor(RGB(196, 43, 28));//红色敌方基地
		for(int i = 0; i < 5; i ++) {
			fillrectangle((4 + i * 3) * Gap , 0 , (5 + i * 3) * Gap, Gap);
		}

		setfillcolor(RGB(36, 98, 255));//蓝色我方基地
		fillrectangle(10 * Gap, 13 * Gap, 11 * Gap, 14 * Gap);

		setfillcolor(RGB(185, 128, 71));//棕色
		for(int i = 0; i < 2 * Gap ; i += Gap) {
			for (int j = 4 * Gap; j < Game_height; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//左侧
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//右侧
			}
		}
		for(int i=2*Gap;i<3*Gap;i+=Gap) {
			for (int j = 7 * Gap; j < Game_height; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//左侧突出部分
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//右侧突出部分
			}
		}
		for(int i=3*Gap;i<4*Gap;i+=Gap) {
			for (int j = 8 * Gap; j < 10*Gap; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//左侧突出部分
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//右侧突出部分
			}
		}
		for(int i=3*Gap;i<7*Gap;i+=Gap) {
			for (int j = 13 * Gap; j < Game_height; j += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//底部突出部分左
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//底部突出部分右
			}
		}
		for(int i=7*Gap;i<Game_width-7*Gap;i+=Gap) {
			fillrectangle( i, Game_height-Gap,  i + Gap, Game_height);//底部
		}
		break;
	case 3:
		//地图3的绘制代码
		setfillcolor(RGB(53, 17, 10));//深红色
		for (int i = 0; i < 3 * Gap; i += 40)
		{
			fillrectangle(i, 0, i + Gap, Gap);//左上角
			fillrectangle(i, Game_height - Gap, i + Gap, Game_height);//左下角	
			fillrectangle(Game_width - i, 0, Game_width - i - Gap, Gap);//右上角
			fillrectangle(Game_width - i, Game_height - Gap, Game_width - i - Gap, Game_height);//右下角
		}
		for(int i=Gap;i<3*Gap;i+=Gap) {
			fillrectangle(0, i, Gap, i + Gap);//左上侧
			fillrectangle(0, Game_height - i - Gap, Gap, Game_height - i);//左下侧
			fillrectangle(Game_width - Gap, i, Game_width, i + Gap);//右上侧
			fillrectangle(Game_width - Gap, Game_height - i - Gap, Game_width, Game_height - i);//右下侧
		}
		setfillcolor(RGB(196, 43, 28));//红色敌方基地
		for (int i = 3 * Gap; i >= 0; i -= Gap)
		{
			static int j = 0;
			fillrectangle(i, j, i + Gap, j + Gap);//左上角
			fillrectangle(Game_width - i - Gap, j, Game_width - i, j + Gap);//右上角
			fillrectangle(i, Game_height - Gap - j, i + Gap, Game_height - j);//左下角
			fillrectangle(Game_width - i - Gap, Game_height - j - Gap, Game_width - i, Game_height - j);//右下角
			j += Gap;
		}fillrectangle(Gap, Gap, Gap * 2, Gap * 2);
		fillrectangle(Game_width - 2 * Gap, Gap, Game_width - Gap, Gap * 2);
		fillrectangle(Gap, Game_height - 2 * Gap, Gap * 2, Game_height - Gap);
		fillrectangle(Game_width - 2 * Gap, Game_height - 2 * Gap, Game_width - Gap, Game_height - Gap);
		
		setfillcolor(RGB(185, 128, 71));//棕色
		for (int j = 0; j <3*Gap; j += Gap) {
			for(int i = 7 * Gap+j; i < 10*Gap; i += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//上左侧
				fillrectangle(i, Game_height - j, i + Gap, Game_height - j - Gap);//下左侧
				if (i != Gap * 10) {
					fillrectangle(Game_width - i, Game_height - j - Gap, Game_width - i - Gap, Game_height - j);//下右侧
					fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//上右侧
				}
			}
		}
		for (int j = 0; j < 4 * Gap; j += Gap)
		{
			fillrectangle(10 * Gap, j , 11 * Gap, j + Gap);//上中侧
			fillrectangle(10 * Gap, Game_height - j - Gap, 11 * Gap, Game_height - j);//下中侧
		}
		for (int j = 4 * Gap; j < 6 * Gap; j += Gap) {
			static int Move_Gap=0;
			for (int i = 4 * Gap+Move_Gap; i < 7 * Gap + Move_Gap; i += Gap) {
				fillrectangle(i, j, i + Gap, j + Gap);//中左侧
				fillrectangle(Game_width - i, j, Game_width - i - Gap, j + Gap);//中右侧	
				fillrectangle(i, Game_height - j - Gap, i + Gap, Game_height - j);//中左侧
				fillrectangle(Game_width - i, Game_height - j - Gap, Game_width - i - Gap, Game_height - j);//中右侧
			}Move_Gap = 40;
		}

		setfillcolor(RGB(36, 98, 255));//蓝色我方基地
		fillrectangle(10 * Gap, 7 * Gap, 11 * Gap, 8 * Gap);
		break;
	}
}