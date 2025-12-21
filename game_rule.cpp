#include "game_rule.h"
#include<easyx.h>  // 必须包含EasyX头文件
#include<conio.h>  // 包含_getch()的头文件
using namespace std;
//图一，游戏主界面，开始游戏，游戏规则按钮
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

//第二个图,游戏规则界面


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
/**
 * 绘制游戏规则（多行文本，适配宽字符）
 * @param x 起始x坐标
 * @param y 起始y坐标
 * @param lineHeight 行高（控制行间距）
 */
void DrawGameRules(int x, int y, int lineHeight)
{
 	// 设置文本样式（游戏规则专用）
 	setbkmode(TRANSPARENT);
 	settextstyle(18, 0, _T("微软雅黑")); // 字体大小适中，便于阅读
 	settextcolor(BLACK);

 	// 按行拆分游戏规则（每行长度适配界面，避免超出显示范围）
 	const TCHAR* rules[] = {
 		_T("玩法说明: 一张空白的地图，让怪兽按照你摆的炮塔的阵型来回移动，并且可以通过搭建和贱卖出口的炮塔，"),
 		_T("使怪兽来回移动，达到最长的移动距离，以便于炮塔不断的轰击怪兽。"),
 		_T(""), // 空行分隔
 		_T("高阶玩法提示：选择武器并部署到地图后，怪物将朝着基地进攻。提供大炮攻击怪物，另设有可充当"),
 		_T("\"防御塔\"的路障。首要任务是策略性布置大炮，通过大炮和路障墙配合以限制怪物行进路线。"),
 		_T("可随时升级现有武器，所有武器会自动攻击射程内的怪物。\"金币\"用于购买和升级武器，消灭怪物可增加金币。"),
 		_T("\"生命值\"会因怪物抵达终点而减少，拆除任何大炮可返还50%金币。"),
 		_T(""), // 空行分隔
 		_T("温馨提示：抵制不良游戏，拒绝盗版游戏，注意自我保护，谨防受骗上当，适度游戏益脑，沉迷游戏伤身，"),
 		_T("合理安排时间，享受健康生活。最佳视频游戏机")
 	};

 	// 逐行绘制文本
 	int lineCount = sizeof(rules) / sizeof(rules[0]); // 计算总行数
 	for (int i = 0; i < lineCount; i++)
 	{
 		outtextxy(x, y + i * lineHeight, rules[i]); // 按行高偏移绘制
 	}
}
