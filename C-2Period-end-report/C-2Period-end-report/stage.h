#ifndef INCLUDED_Stage_h_
#define INCLUDED_Stage_h_
//�Q��
//�X�e�[�W��`�悷�鍶��̍��W
#define STAGE_PIVOT_X 2
#define STAGE_PIVOT_Y 2
typedef struct P {
	int x;
	int y;
};
void init_stage(const char* file_name);
void show_stage(P p);
#endif