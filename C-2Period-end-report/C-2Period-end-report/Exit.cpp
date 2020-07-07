#include "stageobject.h"
void Unlock() {
	bool flg = true;
	for (auto i = mpg.begin(); i != mpg.end(); i++) {
		if (i->second.status == Off) {
			flg = false;
		}
	}
	if (flg) {
		e.status = On;
	}
}