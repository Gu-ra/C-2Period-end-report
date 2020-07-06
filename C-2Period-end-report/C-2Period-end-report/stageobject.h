#ifndef INCLUDED_Stage_h_
#define INCLUDED_Stage_h_
//参照
#include <iostream>
#include "curses.h"
#include "Setting.h"
#include <vector>
#include <map>

using namespace std;
//ステージを描画する基準となる左上の座標
#define STAGE_PIVOT_X 2
#define STAGE_PIVOT_Y 2

#define BUFFSIZE 1024

#define STAGE_W 40
#define STAGE_H 20

#define rep(i,n) for(int i=0;i<n;i++)

typedef struct P {
	int x;
	int y;
};
enum Stage_Objects {
	Root,
	Wall,
	Plr,//プレイヤー
	Gt,//発電機
	Ext//出口
};
enum P_status {//幽霊が近いかどうか
	Safe,//安全
	Cautious,//注意
	Dengerous//警戒
};
typedef struct Player {
	int x;
	int y;
	int status;
};
enum G_status {//発電機が付いているか
	Off,
	On
};
typedef struct Generator {
	int status;
	int count;
};
/*
	ステージ
*/
void init_stage(const char* file_name, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,vector<Generator>& gts);
void show_stage(P p, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg);
/*
	プレイヤー
*/
void Move(vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg);
/*
	発電機
*/

void Charge(Generator& g);
#endif