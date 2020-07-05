#include <iostream>
#include "curses.h"
#include "Setting.h"
#include <vector>
#include "stage.h"
#define BUFFSIZE 1024
#define STAGE_W 40
#define STAGE_H 20
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
char* str_tok_s(char* data, const char* delim, char** ctx);
vector<vector<int>> stage(STAGE_H, vector<int>(STAGE_W));
void init_stage(const char* file_name) {
	FILE* fp;
	char s[BUFFSIZE];
	errno_t error;
	error = fopen_s(&fp, file_name, "r");
	if (error != 0) {
		fprintf_s(stderr, "failed to open.");
	}
	else {
		int h = 0;
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			int w = 0;
			char* p1; char* ctx;
			p1 = str_tok_s(s, "/,", &ctx);
			stage[h][w++] = atoi(p1);
			while (p1 != NULL) {
				p1 = str_tok_s(NULL, "/,", &ctx);
				stage[h][w] = atoi(p1);
				++w;
				if (w >= STAGE_W)break;
			}
			++h;
			if (h >= STAGE_H)break;
		}
		fclose(fp);
	}
}
void show_stage(P p) {
	/*start_color();//�F�̏���
	init_pair(1, COLOR_WHITE, COLOR_WHITE);//��(���F�u���b�N)
	init_pair(2, COLOR_BLACK, COLOR_RED);//���d�@-off(G)�ƁA�o��-off(E)
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);//���d�@-on(G)
	init_pair(4, COLOR_BLACK, COLOR_GREEN);//�o��-on(E)
	init_pair(5, COLOR_GREEN, COLOR_BLACK);//�v���C���[-���S(P)
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);//�v���C���[-����(P)
	init_pair(7, COLOR_RED, COLOR_BLACK);//�v���C���[-�댯(P)
	init_pair(8, COLOR_BLACK, COLOR_BLACK);//�H��(g)*/
	rep(i, STAGE_H) {
		rep(j, STAGE_W) {
			if (stage[i][j] == 1) {//�ǂ�`�悷��B
				attrset(COLOR_PAIR(1));
				mvaddstr(p.y + i, p.x + j,".");
			}
			else if (stage[i][j] == 2) {//�v���C���[
				attrset(COLOR_PAIR(5));
				mvaddstr(p.y + i, p.x + j, "P");
			}
			else if (stage[i][j] == 3) {//���d�@
				attrset(COLOR_PAIR(2));
				mvaddstr(p.y + i, p.x + j, "G");
			}
			else if (stage[i][j] == 4) {//�o��
				attrset(COLOR_PAIR(2));
				mvaddstr(p.y + i, p.x + j, "E");
			}
		}
	}
}
char* str_tok_s(char* data, const char* delim, char** ctx) {
	static char* tmp;
	bool flg = false;
	if (data == NULL) {
		data = *ctx;
		if (tmp != *ctx) {
			return NULL;
		}
		data = ++ * ctx;
	}
	else {
		*ctx = data;
	}
	for (; **ctx != NULL; ++ * ctx) {
		const char* j;
		for (j = delim; *j != NULL; ++j) {
			if (**ctx == *j) {
				**ctx = NULL;
				tmp = *ctx;
				flg = true;
				break;
			}
		}
		if (flg)break;
	}
	if (!flg) {
		**ctx = NULL;
		flg = true;
	}
	return data;
}