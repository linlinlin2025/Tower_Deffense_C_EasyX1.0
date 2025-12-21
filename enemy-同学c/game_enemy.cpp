#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include "game_enemy.h"
#include "game_core.h"
int enemy_money_1;
int enemy_money_1;
struct enemy enemyunit = { 20,10,30,40,100,15,10,25,40,0};

	int Deadenemy_money(int die_num){           /*得到0/1，判断有没有在打击范围里*/
			while (die_num){/*有则进行返钱*/
				if (/*调用D同学的积分函数判断level*/ == 1) {
					return  enemyunit.enemy_money_1 * Deadenemy_count(/*形参*/);
				}
				if (/*调用D同学的积分函数判断level*/ == 2) {
					return  enemyunit.enemy_money_2* Deadenemy_count(/*形参*/);  /*   等级判定及赋值相应的钱      */
				}
				if /*调用D同学的积分函数判断level*/ == 3) {
					return  enemyunit.enemy_money_3 * Deadenemy_count(/*形参*/);
				}                                  
				while (enemyunit.enemy_number) {
					enemyunit.enemy_number--;           /*判断死亡的敌人个数并自增*/
					enemyunit.died_enemycount++;
				}
				return (/*调用level得level值*/) * (enemyunit.enemy_money) * (enemyunit.died_enemycount);
			}
	    }
		return 0;
	}
	int flag = 1;
	int Deadenemy_count(int ifshoot/*调用B同学的是否在打击范围内（返回0/1）的函数*/) {
		while (ifshoot) {
			enemyunit.lifecount -= 20;
			if (enemyunit.lifecount == 0) {
				flag = 0;
				enemyunit.enemy_number--;
				enemyunit.died_enemycount++;
			}
			if (enemyunit.enemy_number == 0) {
				break;
			}
		}
		return enemyunit.died_enemycount;
	}

	int Accelerate_speedandlevel() {
		enemyunit.speed1 = 40;
		enemyunit.enemy_level_1 = 1;
		if (/*调用A的积分函数*/) {
			if (enemyunit.enemy_level < 4 && enemyunit.enemy_level>0) {
				enemyunit.enemy_level += 1;
			}
			if (enemyunit.enemy_level == 1) {
				enemyunit.speed += 20;
			}
			if (enemyunit.enemy_level == 2) {
				enemyunit.speed += 40;
			}
			if (enemyunit.enemy_level == 3) {
				enemyunit.speed += 80;
			}
			return enemyunit.enemy_level;
		}
		return enemyunit.enemy_level;
	}



	

void enemy_appearance()
{
	initgraph(1024,768 );	// 创建绘图窗口，大小为 640x480 像素
	circle(40,40,10);	// 画圆，圆心(200, 200)，半径 100
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return ;
}
