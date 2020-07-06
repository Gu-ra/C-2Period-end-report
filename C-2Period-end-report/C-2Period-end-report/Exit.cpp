#include "stageobject.h"
void Unlock(map<pair<int, int>, Generator>& mp,Exit& e) {
	bool flg = true;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		if (i->second.status == Off) {
			flg = false;
		}
	}
	if (flg) {
		e.status = On;
	}
}