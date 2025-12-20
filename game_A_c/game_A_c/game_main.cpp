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
#include "game_core.h"
using namespace std;

int random_num;

int main() {
	
	// 在程序开始时设置随机种子
	srand(time(NULL));
	random_num = (int)rand()%3+1;  // 生成1到3之间的随机数
	initgraph(width, height, EX_DBLCLKS);
	Game_Init();


	Game_Quit();
	return 0;
}

