#ifndef INCLUDED_Stage_h_
#define INCLUDED_Stage_h_
//�Q��
#include <iostream>
#include "curses.h"
#include "Setting.h"
#include <vector>
#include <map>

using namespace std;
//�X�e�[�W��`�悷���ƂȂ鍶��̍��W
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
	Plr,//�v���C���[
	Gt,//���d�@
	Ext//�o��
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
enum G_status {//���d�@���t���Ă��邩
	Off,
	On
};
typedef struct Generator {
	int status;
	int count;
};
/*
	�X�e�[�W
*/
void init_stage(const char* file_name, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,vector<Generator>& gts);
void show_stage(P p, vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg);
/*
	�v���C���[
*/
void Move(vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg);
/*
	���d�@
*/

void Charge(Generator& g);
#endif