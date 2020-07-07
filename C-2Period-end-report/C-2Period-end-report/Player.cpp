#include "stageobject.h"
void Act(int& turn) {
	int key = getch();
	int H, W;
	++turn;
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
				resultflg = Failed;//ゲームオーバー
			}
		}
		if (stage[pl.y - 1][pl.x] == Ext) {
			if (e.status == On) {
				resultflg = Clear;//ゲームクリア
			}
		}
	}else if (key == KEY_DOWN) {
		if (pl.y < STAGE_H) {
			if (stage[pl.y + 1][pl.x] == Root) {
				stage[pl.y][pl.x] = Root;
				stage[pl.y + 1][pl.x] = Plr;
				++pl.y;
			}
			else if (stage[pl.y + 1][pl.x] == Gt) {
				Charge(mpg[pair<int, int>(pl.y + 1, pl.x)]);
				//発電機を回す
			}
			else if (stage[pl.y + 1][pl.x] == Gh) {
				resultflg = Failed;//ゲームオーバー
			}
		}
		if (stage[pl.y + 1][pl.x] == Ext) {
			if (e.status == On) {
				resultflg = Clear;//ゲームクリア
			}
		}
	}else if (key == KEY_RIGHT) {
		if (pl.x < STAGE_W) {
			if (stage[pl.y][pl.x + 1] == Root) {
				stage[pl.y][pl.x] = Root;
				stage[pl.y][pl.x + 1] = Plr;
				++pl.x;
			}
			else if (stage[pl.y][pl.x + 1] == Gt) {
				Charge(mpg[pair<int, int>(pl.y, pl.x + 1)]);
				//発電機を回す
			}
			else if (stage[pl.y][pl.x + 1] == Gh) {
				resultflg = Failed;//ゲームオーバー
			}
		}
		if (stage[pl.y][pl.x + 1] == Ext) {
			if (e.status == On) {
				resultflg = Clear;//ゲームクリア
			}
		}
	}else if (key == KEY_LEFT) {
		if (pl.x > 0) {
			if (stage[pl.y][pl.x - 1] == Root) {
				stage[pl.y][pl.x] = Root;
				stage[pl.y][pl.x - 1] = Plr;
				--pl.x;
			}
			else if (stage[pl.y][pl.x - 1] == Gt) {
				Charge(mpg[pair<int, int>(pl.y, pl.x - 1)]);
				//発電機を回す
			}
			else if (stage[pl.y][pl.x - 1] == Gh) {
				resultflg = Failed;//ゲームオーバー
			}
		}
		if (stage[pl.y][pl.x - 1] == Ext) {
			if (e.status == On) {
				resultflg = Clear;//ゲームクリア
			}
		}
	}
	else if (key == 'q') {
		resultflg = Quited;//ゲームをやめる
	}
}
int GetGhostMinDistance() {
	int dis = 100;
	int num = 0;
	rep(i, GHOSTCNT) {
		if (dis > abs(pl.y - gts[i].y) + abs(pl.x - gts[i].x)) {
			dis = abs(pl.y - gts[i].y) + abs(pl.x - gts[i].x);
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