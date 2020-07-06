#include "stageobject.h"

void Move(vector<vector<int>>& stage,Player& pl, map<pair<int, int>, Generator>& mpg,Exit& e) {
	int key = getch();
	if (key == KEY_UP) {
		if (pl.y > 0) {
			if (stage[pl.y - 1][pl.x] == Root) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y - 1][pl.x] = 2;
				--pl.y;
			}
			else if (stage[pl.y - 1][pl.x] == Gt) {
				Charge(mpg[pair<int, int>(pl.y - 1, pl.x)]);
				//発電機を回す
			}
			else if (stage[pl.y - 1][pl.x] == Ext) {
				if (e.status == On) {
					stage[pl.y][pl.x] = 0;
					stage[pl.y - 1][pl.x] = 2;
					--pl.y;
					//ゲームクリア
				}
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
			else if (stage[pl.y + 1][pl.x] == Ext) {

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
			else if (stage[pl.y][pl.x + 1] == Ext) {

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
			else if (stage[pl.y][pl.x - 1] == Ext) {

			}
		}
	}
}
