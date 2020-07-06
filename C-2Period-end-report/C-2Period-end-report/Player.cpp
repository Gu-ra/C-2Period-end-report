#include "stageobject.h"

void Move(vector<vector<int>>& stage,Player& pl) {
	int key = getch();
	if (key == KEY_UP) {
		if (pl.y > 0) {
			if (stage[pl.y - 1][pl.x] == 0) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y - 1][pl.x] = 2;
				--pl.y;
			}
			else if (stage[pl.y - 1][pl.x] == 3) {
				cout << "\a";
				//発電機を回す
			}
			else if (stage[pl.y - 1][pl.x] == 4) {

			}
		}
	}else if (key == KEY_DOWN) {
		if (pl.y < STAGE_H) {
			if (stage[pl.y + 1][pl.x] == 0) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y + 1][pl.x] = 2;
				++pl.y;
			}
			else if (stage[pl.y + 1][pl.x] == 3) {
				cout << "\a";
				//発電機を回す
			}
			else if (stage[pl.y + 1][pl.x] == 4) {

			}
		}
	}else if (key == KEY_RIGHT) {
		if (pl.x < STAGE_W) {
			if (stage[pl.y][pl.x + 1] == 0) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y][pl.x + 1] = 2;
				++pl.x;
			}
			else if (stage[pl.y][pl.x + 1] == 3) {
				cout << "\a";
				//発電機を回す
			}
			else if (stage[pl.y][pl.x + 1] == 4) {

			}
		}
	}else if (key == KEY_LEFT) {
		if (pl.x > 0) {
			if (stage[pl.y][pl.x - 1] == 0) {
				stage[pl.y][pl.x] = 0;
				stage[pl.y][pl.x - 1] = 2;
				--pl.x;
			}
			else if (stage[pl.y][pl.x - 1] == 3) {
				cout << "\a";
				//発電機を回す
			}
			else if (stage[pl.y][pl.x - 1] == 4) {

			}
		}
	}
}
