#include "stageobject.h"

char* str_tok_s(char* data, const char* delim, char** ctx);
void init_stage(const char* file_name,vector<vector<int>>& stage,Player& pl,map<pair<int,int>,Generator>& mp,Exit& e) {
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
		int gt_cnt = 0;
		rep(i, STAGE_H) {
			rep(j, STAGE_W) {
				if (stage[i][j] == Plr) {
					pl.y = i;
					pl.x = j;
				}
				else if (stage[i][j] == Gt) {
					Generator g = {
						0,Off
					};
					mp[pair<int, int>(i, j)] = g;
					++gt_cnt;
				}
				else if(stage[i][j]==Ext){
					e.status = Off;
				}
			}
		}
		fclose(fp);
	}
}
void show_stage(P p,vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mp,Exit& e) {
	rep(i, STAGE_H) {
		rep(j, STAGE_W) {
			if (stage[i][j] == Wall) {//壁を描画する。
				attrset(COLOR_PAIR(1));
				mvaddstr(p.y + i, p.x + j,".");
			}
			else if (stage[i][j] == Plr) {//プレイヤー
				attrset(COLOR_PAIR(5));
				mvaddstr(p.y+pl.y, p.x+pl.x, "P");
			}
			else if (stage[i][j] == Gt) {//発電機
				if (mp[pair<int, int>(i, j)].status == On) {
					attrset(COLOR_PAIR(3));
				}
				else {
					attrset(COLOR_PAIR(2));
				}
				mvaddstr(p.y + i, p.x + j, "G");
			}
			else if (stage[i][j] == Ext) {//出口
				Unlock(mp,e);
				if (e.status == On) {
					attrset(COLOR_PAIR(4));
				}
				else {
					attrset(COLOR_PAIR(2));
				}
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