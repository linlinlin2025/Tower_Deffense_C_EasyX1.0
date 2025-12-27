#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include <graphics.h>		
#include <conio.h>
#include <stdio.h>
#include <cstdlib>  // 包含 rand() 和 srand()
#include <ctime> // 包含 time()
#include <math.h>
using namespace std;
#define GRID_SIZE   /*地图方格像素为40*/
#define  ENEMY_RADIUS 20    /*绘制敌人的半径*/
#define MAX_ENEMYCOUNT 50  /*同时存在的最大敌人数*/
#define MAX_PATH_NODE  10  /*单地图最大路径节点数为10*/
#define MAX_BRANCH 3      /*单个节点最大分支数为3*/
#define MAX_MAP_NUM 3    /*最大地图数为3*/
#define ENEMY_GRADE_NUM 3 /*敌人最大等级数*/
#define ENEMY_SPAWN_NUM 15/*单次出来的敌人数*/

typedef struct {
	int x;    /*坐标点（包括节点坐标，分支坐标，目标坐标，后续会赋值到这里来）*/
	int y;
}Point;

typedef struct {
	Point pos;    /*节点坐标,分为普通节点和分支节点*/
	int is_branch;/*是否为分支，0为否，继续走固定路线，1为是，用随机种子随机选择分支路线，再移动*/
	Point  branch_pos[MAX_BRANCH];/*保存分支目标点，当走到该分支点时，判断是否是最后*/
	int branch_count;  /*分支数量，最大分支数为3*/
}Pathnode; /*路线节点信息*/

typedef struct {
	Pathnode nodes[MAX_PATH_NODE];/*保存10个路线里节点的信息（pathnode里的）*/
	int node_count;/*有效节点数，最大是10个路线，但不一定有10个路线，所以记录下来，避免操作无内容元素*/
}Map_path;  /*地图路线*/

typedef struct {
	Map_path leftup_path;        //左上路线
	Map_path rightup_path;        //右上路线
	Map_path leftdown_path;     //左下路线
	Map_path rightdown_path;   //右下路线
}Map_route_set;

typedef struct {
	int speed[ENEMY_GRADE_NUM];//速度
	int hp[ENEMY_GRADE_NUM]; //生命值
	int score_reward[ENEMY_GRADE_NUM];//不同等级的得分
	int money_reward[ENEMY_GRADE_NUM];////不同等级的敌人的钱
	COLORREF color[ENEMY_GRADE_NUM];////不同等级的颜色
}enemy_base;/*敌人基础信息结构体*/


//typedef struct {
//	int x;         /*敌人初始坐标*/
//	int y;
//}Enemy_base;

typedef struct {
	int id;  /*敌人编号*/
	int speed;/*速度*/
	int hp;/*生命值*/
	int level;/*等级1/2/3*/
	int radius;/*半径*/
	int money_reward;/*死亡敌人的金币奖励*/
	int score_reward;/*死亡敌人的得分奖励*/
	int map_type;/*地图类型*/
	int is_alive;/*敌人是否存活，存活为1，继续扣血，否则为0，退出扣血函数*/
	int in_attack_range;/*是否在攻击范围内，是为1，否为0，退出扣血函数*/
	Point pos;/*当前敌人坐标*/
	int cur_node_idx;/*当前目标节点索引，*/
	int if_branch_mode;/*是否是分支节点，1为是，则进行随机分支路线选择，选好后移动*/
	Point target_pos;/*目标节点坐标，判断是否到了目标节点的位置，到了则更换下一个新的目标节点，
	或者已经是最后一个节点，则更换为用户基地坐标*/
}Enemy;/*敌人单位信息*/

typedef struct {
	int grade_1_count;    /*不同等级敌人的死亡数，D定义一个结构体保存死亡数*/
	int grade_2_count;
	int grade_3_count;
	int total_money;     /*总钱数*/
}Deadenemy_stat;/*敌人死亡数统计*/

typedef struct {
	int enemy_id;    /*被攻击的敌人编号*/
	Point attack_pos;/*保存被攻击的坐标点*/
	int if_hit;/*保存是否被打击的值，1为是，0为否*/
}Attack_back; /*接受B给的是否在攻击范围的结构体函数返回的结构体*/

typedef struct {
	int enemy_level;
	int is_reach;
	int reach_count;
}Reach_base_stat;

extern Enemy enemies[MAX_ENEMYCOUNT];//地图中出现的敌人基本信息，B同学可以直接用来判断射程
extern Deadenemy_stat dead_enemy_stat;//敌人死亡数统计，C,D同学可以直接用
extern Reach_base_stat reach_base_stat;//到达基地统计，D同学可以直接用
extern Map_route_set map_routes[MAX_MAP_NUM];//三张地图的路线集，0-2代表地图1-3，每一个地图里有四个方位的路线

void Enemy_System_Init();                  // 敌人系统初始化（路线、基础属性、随机种子）
void Map_Route_Init(int map_type);         // 初始化指定地图的4个方位路线
// 2. 敌人生成函数
int Spawn_Enemy(int map_type);             // 生成15个敌人（返回生成成功数）
Point Get_Random_Spawn_Pos(int map_type);  // 获取指定地图的随机出生点（4方位随机）
// 3. 敌人移动函数
void Enemy_Move();                         // 全体敌人移动（含分支路线选择）
void Enemy_Branch_Select(Enemy* p_enemy, Pathnode* p_branch_node); // 分支点路线随机选择
// 4. 攻击与扣血函数
Attack_back Enemy_Attack_Check(Attack_back attack_info); // 攻击检测与扣血
Deadenemy_stat Enemy_Dead_Count();         // 统计死亡敌人信息（给D模块）
// 5. 基地检测函数
Reach_base_stat Enemy_Reach_Base_Check();  // 检测是否到达基地
// 6. 绘制与更新函数
void Enemy_Draw();                         // 绘制所有存活敌人
void Enemy_Update();                       // 更新敌人状态（死亡/到达基地后擦除）
// 7. 工具函数
int Get_Enemy_Index_By_ID(int enemy_id);   // 根据ID获取敌人数组索引
void Reset_Enemy_Stat();
#endif 