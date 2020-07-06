#include "stageobject.h"

char* str_tok_s(char* data, const char* delim, char** ctx);
void init_stage(const char* file_name,vector<vector<int>>& stage,Player& pl,map<pair<int,int>,Generator>& mp,Exit& e,vector<Ghost>& gts) {
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
		random_device rnd;
		mt19937 mt(rnd());
		uniform_int_distribution<> randh(0, STAGE_H);
		uniform_int_distribution<> randw(0, STAGE_W);
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
		rep(i, GHOSTCNT) {
			P p= {
				randw(mt),randh(mt)
			};
			if (0 < p.y && p.y < STAGE_H && 0 < p.x && p.x < STAGE_W) {
				if (stage[p.y][p.x] == 0) {
					gts[i] = {
						p.x,p.y
					};
					stage[p.y][p.x] = Gh;
				}
				else {
					--i;
				}
			}
			else {
				--i;
			}
		}
		fclose(fp);
	}
}
void show_stage(P p,vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mp,Exit& e, vector<Ghost>& gts) {
	rep(i, STAGE_H) {
		rep(j, STAGE_W) {
			if (stage[i][j] == Wall) {//壁を描画する。
				attrset(COLOR_PAIR(1));
				mvaddstr(p.y + i, p.x + j,".");
			}
			else if (stage[i][j] == Plr) {//プレイヤー
				if (GetGhostMinDistance(pl, gts)==Safe) {
					attrset(COLOR_PAIR(5));
				}
				else if (GetGhostMinDistance(pl, gts) == Cautious) {
					attrset(COLOR_PAIR(6));
				}
				else if (GetGhostMinDistance(pl, gts) == Dengerous) {
					attrset(COLOR_PAIR(7));
				}
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
			else if (stage[i][j] == Gh) {//幽霊
				attrset(COLOR_PAIR(8));
				mvaddstr(p.y + i, p.x + j, "H");
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