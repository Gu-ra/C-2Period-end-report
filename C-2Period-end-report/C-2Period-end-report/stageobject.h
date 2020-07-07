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
enum GE_status {//���d�@���I�����I�t���A�o���̌�����������Ă��邩
	Off,
	On
};
enum Result_Status {
	Playing,//�v���C��
	Clear,
	Failed,
	Quited//���f
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
	int count;//�I���ɂ���̂ɕK�v�ȑ����
};
typedef struct Exit {
	int status;
};
/*
	extern�錾
*/
extern vector<vector<int>> stage;
extern map<pair<int, int>, Generator> mpg;//���W���甭�d�@�����ʂ���
extern vector<Ghost> gts;
extern int resultflg;//1�ŃN���A�A2�ŃQ�[���I�[�o�[�A3�Œ��f���ꂽ���Ƃ��L�^����
extern Player pl;
extern Exit e;
/*
	�X�e�[�W
*/
void init_stage(const char* file_name);//�X�e�[�W�̏�����
void show_stage(P p);//�X�e�[�W��X�e�[�W��I�u�W�F�N�g�̕\��
/*
	�v���C���[
*/
void Act(int& turn);//�ړ��A���d�@���񂷁A�E�o�Ȃ�
int GetGhostMinDistance();//��ԋ߂��H��Ƃ̋������擾
/*
	���d�@
*/
void Charge(Generator& g);//���d�@����
/*
	�o��
*/
void Unlock();//�o�����I���ɂ��A�E�o�\�ɂ���
/*
	�H��
*/
void Gmove();//�H��̓����_���ɓ���
#endif