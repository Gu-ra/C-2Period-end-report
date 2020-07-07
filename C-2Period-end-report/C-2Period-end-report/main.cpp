#include "stageobject.h"
#define CHARBUFF 124 

//windowsize=192×50
//stagesize=20×40
/*
	外部変数
*/
vector<vector<int>> stage(STAGE_H, vector<int>(STAGE_W));//ステージ情報
map<pair<int, int>, Generator> mpg;//座標から発電機を識別する
vector<Ghost> gts(GHOSTCNT);//幽霊達を管理する可変長配列
int resultflg = 0;//1でクリア、2でゲームオーバー
Player pl = {
		0,0,0
};
Exit e = {
	Off
};
//結果出力
void FileOut(const char* fileName, int turn, const char* result);
/*
	メインファイル
*/
int main()
{
	int turn = 0;//脱出までにかかった時間
	rep(i, GHOSTCNT) {
		gts[i] = {
			0,0
		};
	}
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

	init_stage(Stage1f);//ステージ初期化

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

	while (1) {
		erase();
		show_stage(stage_pivot);
		Act(turn);
		Gmove();
		if (resultflg!=Playing) {
			break;
		}
	}
	if (resultflg == Clear) {
		FileOut("Result", turn, "Clear!");
		GameClear();
	}
	else if (resultflg == Failed) {
		FileOut("Result", turn, "Failed...");
		GameOver();
	}
	else {
		FileOut("Result", turn, "Quited");
	}
	//終了
	getch();
	endwin();
	return (0);
}

void FileOut(const char* fileName,int turn,const char* result) {
	FILE* fp;
	char s[BUFFSIZE];
	char tmp[BUFFSIZE];
	strcpy_s(tmp, fileName);
	strcat_s(tmp, ".txt");
	errno_t error;
	error = fopen_s(&fp, tmp, "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		fprintf_s(fp, "%s\nかかったターン：%dターン\n",result,turn);
		fclose(fp);
	}
}