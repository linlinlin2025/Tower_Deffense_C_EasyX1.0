
#include "game_rule.h"
#include<easyx.h>  // 必须包含EasyX头文件
#include<conio.h>  // 包含_getch()的头文件
using namespace std;

// 对应头文件的变量，进行定义和初始化
int Game_Score=0 ;
int Game_Coin =100;
int CurrentHP =100;
int Current_Level=1;



/**
 * @biref :游戏开始菜单页面
 * @details :开始游戏or阅读游戏规则
 * @param :无
 * @return :无
 */

void Interface1(int x, int y, int w, int h, const TCHAR* text)  // 改为const TCHAR*
{
	// 绘制圆角按钮底色
	setfillcolor(0xFFFACD);
	fillroundrect(x, y, x + w, y + h, 5, 5);

	// 绘制按钮文字并居中（所有字符串用_T()包裹）
	settextcolor(BLACK);
	settextstyle(40, 0, _T("微软雅黑"));  // 字体名加_T()
	int hSpace = (w - textwidth(text)) / 2;  // textwidth支持TCHAR
	int vSpace = (h - textheight(text)) / 2; // textheight支持TCHAR
	outtextxy(x + hSpace, y + vSpace, text);
}
// 绘制文字（适配宽字符）
void DrawText1()
{
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("微软雅黑"));
	settextcolor(BLACK);
	
	Interface1(280, 200, 280, 100, _T("开始游戏"));  // 字符串加_T()
	Interface1(280, 380, 280, 100, _T("游戏规则"));

    outtextxy(280, 120, _T("历史记录:"));
}

//第二个图,游戏规则


void Interface2(int x, int y, int w, int h, const TCHAR* text)  // 改为const TCHAR*
{
	// 绘制圆角按钮底色

	setfillstyle(BS_SOLID); // 新增：实心填充
	setfillcolor(0xFFFACD);
	fillroundrect(x, y, x + w, y + h, 5, 5);
	// 绘制按钮文字并居中（所有字符串用_T()包裹）
	settextcolor(BLACK);
	settextstyle(40, 0, _T("微软雅黑"));  // 字体名加_T()
	int hSpace = (w - textwidth(text)) / 2;  // textwidth支持TCHAR
	int vSpace = (h - textheight(text)) / 2; // textheight支持TCHAR
	outtextxy(x + hSpace, y + vSpace, text);
}	
// 绘制文字（适配宽字符）
void DrawText2()
{
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("微软雅黑"));
	settextcolor(BLACK);
	Interface1(650, 500, 80, 60, _T("返回"));
	// 字符串加_T()
}

int main() {
	// 初始化图形窗口
	initgraph(840, 600, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	// 绘制文字和按钮
	DrawText2();

	// 暂停窗口（按任意键退出）
	_getch();
	closegraph();
	return 0;
}