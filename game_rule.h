#ifndef GAME_RULE_H
#define GAME_RULE_H
#include <tchar.h>
// 声明游戏相关外部变量
extern int Game_Score=0;    // 积分,初始为0
extern int Game_Coin=100;     // 金币，初始为100
extern int CurrentHP=100;     // 血量，初始为100
extern int Current_Level=1; // 等级，初始为1

//游戏按钮位置（游戏开始，游戏规则，返回）
void Interface1(int x, int y, int w, int h, const TCHAR* text);
void Interface2(int x, int y, int w, int h, const TCHAR* text);

void GameButton() {
	Interface1(280, 200, 280, 100, _T("开始游戏")); //左上（280，200）右下（560，300）
	Interface1(280, 380, 280, 100, _T("游戏规则"));//左上（280，380）右下（560，480）
	Interface2(10, 10, 100, 50, _T("返回"));//左上（10，10）右下（110，60）

}

// 图一，游戏主界面绘制
void Interface1(int x, int y, int w, int h, const TCHAR* text);//绘制按钮，文字居中
void DrawText1();                                              // 绘制文字（适配宽字符）

// 第二个图,游戏规则界面绘制
void Interface2(int x, int y, int w, int h, const TCHAR* text);//绘制按钮，文字居中
void DrawText2();// 绘制文字（适配宽字符）

#endif
