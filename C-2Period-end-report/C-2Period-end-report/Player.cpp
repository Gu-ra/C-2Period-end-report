#include "stageobject.h"
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
void Move(vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,Exit& e, int& resultflg) {
	int key = getch();
	int H, W;
	if (key == KEY_UP) {
		if (pl.y > 0) {
			if (stage[pl.y - 1][pl.x] == Root) {
				stage[pl.y][pl.x] = Root;
				stage[pl.y - 1][pl.x] = Plr;
				--pl.y;
			}
			else if (stage[pl.y - 1][pl.x] == Gt) {
				Charge(mpg[pair<int, int>(pl.y - 1, pl.x)]);
				//発電機を回す
			}
			else if (stage[pl.y - 1][pl.x] == Gh) {
				resultflg = 2;//ゲームオーバー
			}
		}
		if (stage[pl.y - 1][pl.x] == Ext) {
			if (e.status == On) {
				resultflg = 1;//ゲームクリア
			}
		}
	}else if (key == KEY_DOWN) {
		if (pl.y < STAGE_H) {
			if (stage[pl.y + 1][pl.x] == Root) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y + 1][pl.x] = 2;
				++pl.y;
			}
			else if (stage[pl.y + 1][pl.x] == Gt) {
				Charge(mpg[pair<int, int>(pl.y + 1, pl.x)]);
				//発電機を回す
			}
			else if (stage[pl.y + 1][pl.x] == Gh) {
				resultflg = 2;//ゲームオーバー
			}
		}
		if (stage[pl.y + 1][pl.x] == Ext) {
			if (e.status == On) {
				resultflg = 1;//ゲームクリア
			}
		}
	}else if (key == KEY_RIGHT) {
		if (pl.x < STAGE_W) {
			if (stage[pl.y][pl.x + 1] == Root) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y][pl.x + 1] = 2;
				++pl.x;
			}
			else if (stage[pl.y][pl.x + 1] == Gt) {
				Charge(mpg[pair<int, int>(pl.y, pl.x + 1)]);
				//発電機を回す
			}
			else if (stage[pl.y][pl.x + 1] == Gh) {
				resultflg = 2;//ゲームオーバー
			}
		}
		if (stage[pl.y][pl.x + 1] == Ext) {
			if (e.status == On) {
				resultflg = 1;//ゲームクリア
			}
		}
	}else if (key == KEY_LEFT) {
		if (pl.x > 0) {
			if (stage[pl.y][pl.x - 1] == Root) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y][pl.x - 1] = 2;
				--pl.x;
			}
			else if (stage[pl.y][pl.x - 1] == Gt) {
				Charge(mpg[pair<int, int>(pl.y, pl.x - 1)]);
				//発電機を回す
			}
			else if (stage[pl.y][pl.x - 1] == Gh) {
				resultflg = 2;//ゲームオーバー
			}
		}
		if (stage[pl.y][pl.x - 1] == Ext) {
			if (e.status == On) {
				resultflg = 1;//ゲームクリア
			}
		}
	}
	else if (key == 'q') {
		resultflg = 3;//ゲームをやめる
	}
}
int GetGhostMinDistance(Player& pl, vector<Ghost>& ghs) {
	int dis = 100;
	int num = 0;
	rep(i, GHOSTCNT) {
		if (dis > abs(pl.y - ghs[i].y) + abs(pl.x - ghs[i].x)) {
			dis = abs(pl.y - ghs[i].y) + abs(pl.x - ghs[i].x);
		}
	}
	if (dis <= 3) {
		num = Dengerous;
	}
	else if (dis <= 5) {
		num = Cautious;
	}
	else {
		num = Safe;
	}
	return num;
}