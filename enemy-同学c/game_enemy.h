#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include <graphics.h>		
#include <conio.h>
#include <stdio.h>
#include <cstdlib>  // 包含 rand() 和 srand()
#include <ctime>    // 包含 time()
using namespace std;
struct enemy {
	int enemy_radius;//敌人初始位置
	int speed1, speed2, speed3;//速度
	int lifecount;//生命值
	int enemy_number;//发起进攻的敌人的数量

	//int enemy_level_1;//敌人等级
	//int enemy_level_2;             /*待定，感觉用不到*/
	//int enemy_level_3;

	int enemy_money_1;
	int enemy_money_2;
	int enemy_money_3;//消灭一个敌人赚的钱
	int died_enemycount;//死亡敌人个数
};
//extern int enemy_x, enemy_y;         /*待定，不清楚要不要用*/
//extern int die_x, die_y;//死亡位置   /*待定，不清楚要不要用*/
int Point_x_y(void);//返回给B敌人的位置坐标,会不断更新位置
int Deadenemy_count(int ifshoot);//死亡敌人数给D
int Deadenemy_level(int point);//D给我当前积分数，我判断后变更等级，返回死亡敌人等级数给D
int Deadenemy_money(int die_num);//死亡敌人返回的总钱数给A
int Reach_basement_num(int base_x,int base_y);//接受基地坐标,返回到达基地的敌人个数给D
int Enemy_route_design(int enemy_start_x, int enemy_start_y);//接受敌人初始位置,敌人路线设计（碰到棕色块往其他地方走）
int Accelerate_speedandlevel();//根据积分数改变敌人速度和等级
void Deadenemy_renewal(int die_x, int die_y);//更新敌人在地图上的状态，敌人死了就抹除
void Enemy_appearance(int enemy_start_x,int enemy_start_y);//接受敌人初始位置，进行敌人形象绘制
#endif