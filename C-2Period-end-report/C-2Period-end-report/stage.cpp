#include "stageobject.h"

char* str_tok_s(char* data, const char* delim, char** ctx);
void init_stage(const char* file_name,vector<vector<int>>& stage,Player& pl) {
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
		rep(i, STAGE_H) {
			rep(j, STAGE_W) {
				if (stage[i][j] == 2) {
					pl.y = i;
					pl.x = j;
				}
			}
		}
		fclose(fp);
	}
}
void show_stage(P p,vector<vector<int>>& stage,Player& pl) {
	rep(i, STAGE_H) {
		rep(j, STAGE_W) {
			if (stage[i][j] == 1) {//壁を描画する。
				attrset(COLOR_PAIR(1));
				mvaddstr(p.y + i, p.x + j,".");
			}
			else if (stage[i][j] == 2) {//プレイヤー
				attrset(COLOR_PAIR(5));
				mvaddstr(p.y+pl.y, p.x+pl.x, "P");
			}
			else if (stage[i][j] == 3) {//発電機
				attrset(COLOR_PAIR(2));
				mvaddstr(p.y + i, p.x + j, "G");
			}
			else if (stage[i][j] == 4) {//出口
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