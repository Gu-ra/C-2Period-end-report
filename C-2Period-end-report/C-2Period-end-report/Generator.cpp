#include "stageobject.h"
#define CHARGETIME 5
void Charge(Generator& g) {
	g.count++;
	if (g.count >= CHARGETIME) {
		g.status = On;
	}
}