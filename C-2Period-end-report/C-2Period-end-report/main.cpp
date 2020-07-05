#include <iostream>
#include "curses.h"
#include <vector>
#include <stdio.h>
#include "Setting.h"
#include "stage.h"
#define STAGE_W 10
#define STAGE_H 20
#define CHARBUFF 124 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
//windowsize=192×50
//stagesize=20×40

/*
	メインファイル
*/
int main()
{
	//外部変数
	extern vector<vector<int>> stage;
	//変数
	int H, W;//ウィンドウサイズ
	P stage_pivot;
	stage_pivot.x=STAGE_PIVOT_X;
	stage_pivot.y = STAGE_PIVOT_Y;
	//現在のディレクトリ
	char curdir[CHARBUFF];
	getCurrentDirectory(curdir);
	//setting.ini
	char setf[CHARBUFF];
	sprintf_s(setf, "%s\\setting.ini", curdir);
	const char* section= "Stage1";
	char Stage1f[CHARBUFF];//ファイル名
	readChar(section, "In", "NotFound", Stage1f, setf);
	//printf("%s\n", Stage1f);ステージファイル取得

	/*rep(i, STAGE_H) {
		rep(j, STAGE_W) {
			cout << stage[i][j]<<" ";
		}
		cout << endl;
	}*///ステージデータ取得
	init_stage(Stage1f);//

	initscr();//処理開始
	noecho();//キー入力した文字の非表示モード
	curs_set(0);//カーソル非表示
	cbreak();//エンターキー不要の入力モード
	keypad(stdscr, TRUE);//特殊キー有効化
	start_color();//色の準備
	init_pair(1, COLOR_WHITE, COLOR_WHITE);//壁(白色ブロック)
	init_pair(2, COLOR_BLACK, COLOR_RED);//発電機-off(G)と、出口-off(E)
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);//発電機-on(G)
	init_pair(4, COLOR_BLACK, COLOR_GREEN);//出口-on(E)
	init_pair(5, COLOR_GREEN, COLOR_BLACK);//プレイヤー-安全(P)
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);//プレイヤー-注意(P)
	init_pair(7, COLOR_RED, COLOR_BLACK);//プレイヤー-危険(P)
	init_pair(8, COLOR_BLACK, COLOR_BLACK);//幽霊(g)
	getmaxyx(stdscr, H, W);//ウィンドウの幅と高さ取得
	show_stage(stage_pivot);
	//終了
	getch();
	endwin();
	return (0);
}