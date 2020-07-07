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
enum GE_status {//発電機がオンかオフか、出口の鍵が解除されているか
	Off,
	On
};
enum Result_Status {
	Playing,//プレイ中
	Clear,
	Failed,
	Quited//中断
};
typedef struct P {
	int x;
	int y;
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
typedef struct Generator {
	int status;
	int count;//オンにするのに必要な操作回数
};
typedef struct Exit {
	int status;
};
/*
	extern宣言
*/
extern vector<vector<int>> stage;
extern map<pair<int, int>, Generator> mpg;//座標から発電機を識別する
extern vector<Ghost> gts;
extern int resultflg;//1でクリア、2でゲームオーバー、3で中断されたことを記録する
extern Player pl;
extern Exit e;
/*
	ステージ
*/
void init_stage(const char* file_name);//ステージの初期化
void show_stage(P p);//ステージやステージ上オブジェクトの表示
/*
	プレイヤー
*/
void Act(int& turn);//移動、発電機を回す、脱出など
int GetGhostMinDistance();//一番近い幽霊との距離を取得
/*
	発電機
*/
void Charge(Generator& g);//発電機を回す
/*
	出口
*/
void Unlock();//出口をオンにし、脱出可能にする
/*
	幽霊
*/
void Gmove();//幽霊はランダムに動く
#endif