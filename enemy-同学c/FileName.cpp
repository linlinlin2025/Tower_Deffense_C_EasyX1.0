#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
	struct enemy {
		int enemy_x, enemy_y;//敌人初始位置
		int speed;//速度
		int lifecount;//生命值
		int die_x, die_y;//死亡位置
		int enemy_number;//发起进攻的敌人的数量
		int enemy_level;//敌人等级
		int enemy_money;//消灭一个敌人赚的钱
		int died_enemycount;//死亡敌人个数

	}enemyunit;
	//enemynuit.lifecount = 100;

	int Deadenemy_money(){
		enemyunit.lifecount = 100;
		while (/*调用A*/){
			enemyunit.lifecount -= 20;
			enemyunit.died_enemycount = 0;
			enemyunit.enemy_number = 15;
			if (enemyunit.lifecount == 0) {
				if (Accelerate_speedandlevel() == 1) {
					enemyunit.enemy_money =/*暂定*/;
				}
				if (Accelerate_speedandlevel() ==2) {
					enemyunit.enemy_money =/*暂定*/;     /*   等级判定及赋值相应的钱      */
				}
				if (Accelerate_speedandlevel() == 3) {
					enemyunit.enemy_money =/*暂定*/;
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
	int Accelerate_speedandlevel() {
		enemyunit.speed = 40;
		enemyunit.enemy_level = 1;
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



	

int main()
{
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
	circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
