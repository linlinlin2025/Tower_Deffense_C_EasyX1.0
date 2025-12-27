//#include <graphics.h>		// 引用图形库头文件
//#include <conio.h>
//#include <stdio.h>
#include "game_enemy.h"
#include "game_core.h"
Enemy enemies[MAX_ENEMYCOUNT];//地图中出现的敌人基本信息，B同学可以直接用来判断射程
Deadenemy_stat deadenemy_stat; // 敌人死亡数统计，C, D同学可以直接用
Reach_base_stat reacg_base_stat;//到达基地统计，D同学可以直接用
Map_route_set map_routes[MAX_MAP_NUM];//三张地图的路线集，0-2代表地图1-3，每一个地图里有四个方位的路线
Enemy_BasePos map1[4] = { {60,60 }, {780, 60},{ 60, 540},{ 780, 60} };
Enemy_BasePos map2[4] = { {200,20},{320,20},{560,20},{640,20} };   /*不同地图的几个不同的敌人初始坐标*/
Enemy_BasePos map3[4] = { {20,140},{20,460},{820,140},{820,460} };
static Enemy_base  enemy_base = { {20,40,80},{100，150，200},{10,25,40},{10,25,40},{RGB(),RGB(),RGB()}};
//Pathnode map1_nodes[4][MAX_PATH_NODE] = { {{260,60},0,{},{}, };
//Map_path map1_path = { };
//Pathnode map1_nodes[MAX_PATH_NODE] = {};
//Map_path map1_path = {};                               /*初始化*/
//Pathnode map1_nodes[MAX_PATH_NODE] = {};
//Map_path map1_path = {};
//Map_path map_paths[4] = { {},map1_path,map2_path ,map3_path };
//Enemy enemy_list[MAX_ENEMYCOUNT];
//int enemy_count = 0;
//int global_enemy_id = 0;
//Deadenemy_stat dead_stat = { 0,0,0,0 ,0};
//void Initrandom() {
//	srand((unsigned int)time(NULL));
//}
//void Initgraphics() {
//	initgraph(840, 600);
//	setbkcolor(WHITE);
//	cleardevice();
//}
//Point enemy_startpos(int random_num) {
//	Point pos;
//	int idx;
//	switch (random_num) {
//	case 1:
//		idx = rand() % 4;
//		pos.x = map1[idx].x;
//		pos.y = map1[idx].y;
//		break;
//	case 2:
//		idx = rand() % 5;
//		pos.x = map2[idx].x;
//		pos.y = map2[idx].y;
//		break;
//	case 3:
//		idx = rand() % 4;
//		pos.x = map3[idx].x;
//		pos.y = map3[idx].y;
//		break;
//	default:
//		pos.x = map1[0].x;
//		pos.y = map1[0].y;
//		break;
//	}
//	return pos;
//}


void Enemy_System_Init() {

}            // 敌人系统初始化（路线、基础属性、随机种子）
void Map_Route_Init(int random_num) {

}      // 初始化指定地图的4个方位路线
// 2. 敌人生成函数
int Spawn_Enemy(int random_num) {}           // 生成15个敌人（返回生成成功数）
Point Get_Random_Spawn_Pos(int map_type) {}  // 获取指定地图的随机出生点（4方位随机）
// 3. 敌人移动函数
void Enemy_Move() {}                      // 全体敌人移动（含分支路线选择）
void Enemy_Branch_Select(Enemy* p_enemy, Pathnode* p_branch_node) {}// 分支点路线随机选择
// 4. 攻击与扣血函数
Attack_back Enemy_Attack_Check(Attack_back attack_info) {

} // 攻击检测与扣血
Deadenemy_stat Enemy_Dead_Count() {}    // 统计死亡敌人信息（给D模块）
// 5. 基地检测函数
Reach_base_stat Enemy_Reach_Base_Check() {  }// 检测是否到达基地
// 6. 绘制与更新函数
void Enemy_Draw() {}                   // 绘制所有存活敌人
void Enemy_Update() {}                // 更新敌人状态（死亡/到达基地后擦除）
// 7. 工具函数
int Get_Enemy_Index_By_ID(int enemy_id) {} // 根据ID获取敌人数组索引
void Reset_Enemy_Stat() {}


























//int Createnemy(int random_num, int level) {
//	if (enemy_count >= MAX_ENEMYCOUNT)
//		return -1;
//}
//	if (random_num == 1) {
//		srand((unsigned int)time(NULL));
//		int idex = rand() % 4;
//		/*enemyunit.enemy_x = map1[idex].x;
//		enemyunit.enemy_y= map1[idex].y;*/
//		points.x = map1[idex].x;
//		points.y = map1[idex].y;
//		return points;
//	}
//	if (random_num == 2) {
//		srand((unsigned int)time(NULL));
//		int idex = rand() % 5;
//		/*enemyunit.enemy_x= map2[idex].x;
//		enemyunit.enemy_y = map2[idex].y;*/
//		points.x = map2[idex].x;
//		points.y = map2[idex].y;
//		return points;
//	}
//	if (random_num == 3) {
//		srand((unsigned int)time(NULL));
//		int idex = rand() % 4;
//		/*enemyunit.enemy_x = map1[idex].x;
//		enemyunit.enemy_y = map1[idex].y;*/
//		points.x = map3[idex].x;
//		points.y = map3[idex].y;
//		return points;
//	}
//}
//struct Points_2 position_x_y;
//struct Points_2 current_move_x_y() {
//
//}
//Dead_enemy_count record[1] = {0};
//Dead_enemy_count Deadenemy_count(int ifshoot) {
//	while (ifshoot) {
//		enemyunit1.lifecount -= 20;
//		if (enemyunit1.lifecount == 0) {
//			enemyunit1.lifecount = 100;
//			enemyunit1.died_enemycount++;
//			enemyunit1.enemy_number--;
//			if (enemyunit1.enemy_flag) {
//				enemyunit1.current_speed = 20;
//				record[1].enemy_grade_1= enemyunit1.died_enemycount;
//			}
//			if (enemyunit1.enemy_flag) {
//				enemyunit1.current_speed = 40
//				record[1].enemy_grade_2= enemyunit1.died_enemycount-record[1].enemy_grade_1;
//				enemyunit1.died_enemycount = 0;
//			}
//			if (/*调用D给的积分函数*/ > 300) {
//				record[1].enemy_grade_3 = enemyunit1.died_enemycount;
//			}
//			if (enemyunit1.enemy_number == 0) {
//				enemyunit1.enemy_number = 15;
//				break;
//			}
//		}
//	}
//	return record[3];
//}
//int Deadenemy_level(int point) {
//	if (point >= 100 && point < 300) {
//		enemyunit.current_level = 2;
//	}
//	if (point >= 300) {
//		 enemyunit.current_level = 3;
//	}
//	return enemyunit.current_level;
//}
//int Deadenemy_money(int Deadenemy_num) {
//	Dead_enemy_count Deadenemy_count(/*调用B的是否在打击范围内的函数*/);
//	return record[1].enemy_grade_1 * 10 + record[1].enemy_grade_2 * 25 + record[1].enemy_grade_3 * 40;
//}
//int Reach_basement_num(int base_x, int base_y) {
//
//
//}
//
//	//int Deadenemy_money(int die_num){           /*得到0/1，判断有没有在打击范围里*/
//	//		while (die_num){/*有则进行返钱*/
//	//			if (/*调用D同学的积分函数判断level*/ == 1) {
//	//				return  enemyunit.enemy_money_1 * Deadenemy_count(/*形参*/);
//	//			}
//	//			if (/*调用D同学的积分函数判断level*/ == 2) {
//	//				return  enemyunit.enemy_money_2* Deadenemy_count(/*形参*/);  /*   等级判定及赋值相应的钱      */
//	//			}
//	//			if /*调用D同学的积分函数判断level*/ == 3) {
//	//				return  enemyunit.enemy_money_3 * Deadenemy_count(/*形参*/);
//	//			}                                  
//	//			while (enemyunit.enemy_number) {
//	//				enemyunit.enemy_number--;           /*判断死亡的敌人个数并自增*/
//	//				enemyunit.died_enemycount++;
//	//			}
//	//			return (/*调用level得level值*/) * (enemyunit.enemy_money) * (enemyunit.died_enemycount);
//	//		}
//	//    }
//	//	return 0;
//	//}
//	int flag = 1;
//	int Deadenemy_count(int ifshoot/*调用B同学的是否在打击范围内（返回0/1）的函数*/) {
//		while (ifshoot) {
//			enemyunit.lifecount -= 20;
//			if (enemyunit.lifecount == 0) {
//				flag = 0;
//				enemyunit.enemy_number--;
//				enemyunit.died_enemycount++;
//			}
//			if (enemyunit.enemy_number == 0) {
//				break;
//			}
//		}
//		return enemyunit.died_enemycount;
//	}
//
//	int Accelerate_speedandlevel() {
//		enemyunit.speed1 = 40;
//		enemyunit.enemy_level_1 = 1;
//		if (/*调用A的积分函数*/) {
//			if (enemyunit.enemy_level < 4 && enemyunit.enemy_level>0) {
//				enemyunit.enemy_level += 1;
//			}
//			if (enemyunit.enemy_level == 1) {
//				enemyunit.speed += 20;
//			}
//			if (enemyunit.enemy_level == 2) {
//				enemyunit.speed += 40;
//			}
//			if (enemyunit.enemy_level == 3) {
//				enemyunit.speed += 80;
//			}
//			return enemyunit.enemy_level;
//		}
//		return enemyunit.enemy_level;
//	}
//
//	void Enemy_appearance(int enemy_start_x, int enemy_start_y) {
//		enemy_start_x, enemy_start_y=Point_x_y(random_num);
//		/*enemyunit.enemy_radius = 20;*/
//		circle(enemy_start_x, enemy_start_y, enemyunit.enemy_radius);
//		setfillcolor(LIGHTMAGENTA);
//		//_getch();
//		//closegraph();			// 关闭绘图窗口
//		//return;
//	}
//	
//
//
//
//	
//
////void enemy_appearance()
////{
////	initgraph(1024,768 );	// 创建绘图窗口，大小为 640x480 像素
////	circle(40,40,10);	// 画圆，圆心(200, 200)，半径 100
////	//_getch();				// 按任意键继续
////	//closegraph();			// 关闭绘图窗口
////	//return ;
////}
