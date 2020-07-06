#include "curses.h"

void GameClear() {
	erase();
	attrset(COLOR_PAIR(5));
	mvaddstr(0, 0, "GameClear!");
	getch();
}
void GameOver() {
	erase();
	attrset(COLOR_PAIR(7));
	mvaddstr(0, 0, "GameOver!");
	getch();
}