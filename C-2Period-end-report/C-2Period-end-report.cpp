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
//stagesize=20×20
int main()
{
	extern vector<vector<int>> stage;
	//現在のディレクトリ
	char curdir[CHARBUFF];
	getCurrentDirectory(curdir);
	//setting.ini
	char setf[CHARBUFF];
	sprintf_s(setf, "%s\\setting.ini", curdir);
	const char* section= "Stage1";
	char Stage1f[CHARBUFF];//ファイル名
	readChar(section, "In", "NotFound", Stage1f, setf);
	read_stage(Stage1f);
	//printf("%s\n", Stage1f);

	rep(i, STAGE_H) {
		rep(j, STAGE_W) {
			cout << stage[i][j]<<" ";
		}
		cout << endl;
	}
}