#ifndef INCLUDED_Stage_h_
#define INCLUDED_Stage_h_
//参照
#include <iostream>
#include "curses.h"
#include "Setting.h"
#include "Result.h"
#include <vector>
#include <map>
#include <random>

using namespace std;
//ステージを描画する基準となる左上の座標
#define STAGE_PIVOT_X 2
#define STAGE_PIVOT_Y 2

#define BUFFSIZE 1024

#define STAGE_W 40
#define STAGE_H 20
#define GHOSTCNT 5
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
	Ext,//出口
	Gh
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
typedef struct Ghost {
	int x;
	int y;
};
enum GE_status {//発電機が付いているか
	Off,
	On
};
typedef struct Generator {
	int status;
	int count;
};
typedef struct Exit {
	int status;
};
/*
	ステージ
*/
void init_stage(const char* file_name, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,Exit& e,vector<Ghost>& gts);
void show_stage(P p, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg, Exit& e, vector<Ghost>& gts);
/*
	プレイヤー
*/
void Move(vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,Exit& e,int& resultflg);
int GetGhostMinDistance(Player& pl, vector<Ghost>& ghs);
/*
	発電機
*/
void Charge(Generator& g);
/*
	出口
*/
void Unlock(map<pair<int,int>,Generator>& mp, Exit& e);
/*
	幽霊
*/
void Gmove(vector<vector<int>>& stage,vector<Ghost>& ghs);
#endif