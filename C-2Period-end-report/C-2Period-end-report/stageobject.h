#ifndef INCLUDED_Stage_h_
#define INCLUDED_Stage_h_
//参照
#include <iostream>
#include "curses.h"
#include "Setting.h"
#include <vector>
using namespace std;
//ステージを描画する左上の座標
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
typedef struct Player {
	int x;
	int y;
	int color;
};
void init_stage(const char* file_name, vector<vector<int>>& stage,Player& pl);
void show_stage(P p, vector<vector<int>>& stage,Player& pl);

void Move(vector<vector<int>>& stage,Player& pl);
#endif