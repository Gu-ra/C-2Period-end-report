#include "stageobject.h"

void Gmove() {
	random_device rnd;
	mt19937 mt(rnd());
	rep(i, GHOSTCNT) {
		uniform_int_distribution<> rand4(0, 4);
		int r = (int)rand4(mt);
		if (r == 0) {
			if (gts[i].y > 0) {
				if (stage[gts[i].y - 1][gts[i].x] == Root) {
					stage[gts[i].y][gts[i].x] = Root;
					stage[gts[i].y - 1][gts[i].x] = Gh;
					--gts[i].y;
				}
			}
		}else if (r== 1) {
			if (gts[i].y < STAGE_H) {
				if (stage[gts[i].y + 1][gts[i].x] == Root) {
					stage[gts[i].y][gts[i].x] = Root;
					stage[gts[i].y + 1][gts[i].x] = Gh;
					++gts[i].y;
				}
			}
		}else if (r == 2) {
			if (gts[i].x > 0) {
				if (stage[gts[i].y][gts[i].x - 1 ] == Root) {
					stage[gts[i].y][gts[i].x] = Root;
					stage[gts[i].y][gts[i].x - 1 ] = Gh;
					--gts[i].x;
				}
			}
		}else if (r == 3) {
			if (gts[i].x < STAGE_W) {
				if (stage[gts[i].y][gts[i].x + 1] == Root) {
					stage[gts[i].y][gts[i].x] = Root;
					stage[gts[i].y][gts[i].x + 1] = Gh;
					++gts[i].x;
				}
			}
		}
	}
}