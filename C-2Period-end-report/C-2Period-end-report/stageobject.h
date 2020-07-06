#ifndef INCLUDED_Stage_h_
#define INCLUDED_Stage_h_
//�Q��
#include <iostream>
#include "curses.h"
#include "Setting.h"
#include "Result.h"
#include <vector>
#include <map>
#include <random>

using namespace std;
//�X�e�[�W��`�悷���ƂȂ鍶��̍��W
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
	Plr,//�v���C���[
	Gt,//���d�@
	Ext,//�o��
	Gh
};
enum P_status {//�H�삪�߂����ǂ���
	Safe,//���S
	Cautious,//����
	Dengerous//�x��
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
enum GE_status {//���d�@���t���Ă��邩
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
	�X�e�[�W
*/
void init_stage(const char* file_name, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,Exit& e,vector<Ghost>& gts);
void show_stage(P p, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg, Exit& e, vector<Ghost>& gts);
/*
	�v���C���[
*/
void Move(vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,Exit& e,int& resultflg);
int GetGhostMinDistance(Player& pl, vector<Ghost>& ghs);
/*
	���d�@
*/
void Charge(Generator& g);
/*
	�o��
*/
void Unlock(map<pair<int,int>,Generator>& mp, Exit& e);
/*
	�H��
*/
void Gmove(vector<vector<int>>& stage,vector<Ghost>& ghs);
#endif