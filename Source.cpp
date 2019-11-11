#include"DxLib.h"
#define TITLE 0
#define SEARCH 1
#define REPORT 3

#define SETTIME 360

int Key[256];//キーハンドル
int graph[256];//グラフハンドル

byte state;//状況

byte Titlestate;//タイトル画面の状況

void title();//タイトル画面

void move();//ボタン移動

void boxcolor();//四角カラー演出

void graphinit();//画像読み込み


int time;//タイムコード


//色
int white = GetColor(255, 255, 255);
int GreenA = GetColor(109, 247, 156);
int GreenB = GetColor(0, 255, 65);
int Glay = GetColor(140, 140, 140);
int red = GetColor(240, 0, 59);
int pink = GetColor(255, 51, 153);
int blue = GetColor(67, 125, 230);
int yellow = GetColor(251, 239, 35);
int skyblue = GetColor(135, 140, 252);
int orange = GetColor(255, 129, 25);
int purple = GetColor(142, 0, 204);

//レポート関数
void reportmain();
struct 
{
	byte state;//状況変数

	byte stateofNO1;//静岡東部編のサイン移動用変数
	byte stateofNO2;//東海・三信・琵琶湖西編のサイン移動用変数
	byte stateofNO3;//中越・上越・南東北編のサイン移動用変数
	byte stateofNO4;//北関東編のサイン移動用変数

	bool charon;//文字情報のオンオフ
	bool graphinflag;//画像読み込み確認

}Report;
//SEARCH関数
void searching();
struct
{
	byte state;//状況変数

}Search;

int UpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) {
			Key[i]++;
		}
		else {
			Key[i] = 0;
		}
	}
	return 0;
}

//画像データ処理
struct {
	int yui[5];
	int harada[5];
	int hina[5];
	int nao[5];
	int makino[5];
	int hiromi[5];
	int yasuha[4];
	int mayu[5];

	//5までは静岡,6からは長野
	int nagisa[10];

	int karen[5];
	int miku[5];
	int chie[5];
	int tomoe[5];
	int kouzue[5];
	int natumi[5];

	//2までは宮城,3から埼玉
	int minami[7];

	int nono[5];
	int marina[5];
	int otsuki[5];
	int misato[5];
	int suzuho[5];
	int nakano[5];
	int kana[5];
	int sarina[5];
	int yuki[5];
	int chika[5];
	int ibuki[5];
	int nanjo[5];
	int siki[2];
	int risa[5];
	int wakaba[4];
	int arisa[5];
	int yu[5];

}Graph;
void graphinit() {
	Graph.nanjo[0] = LoadGraph("画像/南条1.png");
	Graph.nanjo[1] = LoadGraph("画像/南条2.png");
	Graph.nanjo[2] = LoadGraph("画像/南条3.png");//横
	Graph.nanjo[3] = LoadGraph("画像/南条4.png");
	Graph.nanjo[4] = LoadGraph("画像/南条5.png");

	Graph.yui[0] = LoadGraph("画像/ゆい1.png");
	Graph.yui[1] = LoadGraph("画像/ゆい2.png");
	Graph.yui[2] = LoadGraph("画像/ゆい3.png");
	Graph.yui[3] = LoadGraph("画像/ゆい4.png");
	Graph.yui[4] = LoadGraph("画像/ゆい5.png");//横

	Graph.harada[0] = LoadGraph("画像/原田1.png");
	Graph.harada[1] = LoadGraph("画像/原田2.png");
	Graph.harada[2] = LoadGraph("画像/原田3.png");
	Graph.harada[3] = LoadGraph("画像/原田4.png");//横
	Graph.harada[4] = LoadGraph("画像/原田5.png");//横

	Graph.hina[0] = LoadGraph("画像/ひな1.png");
	Graph.hina[1] = LoadGraph("画像/ひな2.png");
	Graph.hina[2] = LoadGraph("画像/ひな3.png");
	Graph.hina[3] = LoadGraph("画像/ひな4.png");
	Graph.hina[4] = LoadGraph("画像/ひな5.png");

	Graph.nao[0] = LoadGraph("画像/神谷1.png");
	Graph.nao[1] = LoadGraph("画像/神谷2.png");
	Graph.nao[2] = LoadGraph("画像/神谷3.png");
	Graph.nao[3] = LoadGraph("画像/神谷4.png");
	Graph.nao[4] = LoadGraph("画像/神谷5.png");

	Graph.makino[0] = LoadGraph("画像/マキノ1.png");
	Graph.makino[1] = LoadGraph("画像/マキノ2.png");
	Graph.makino[2] = LoadGraph("画像/マキノ3.png");
	Graph.makino[3] = LoadGraph("画像/マキノ4.png");
	Graph.makino[4] = LoadGraph("画像/マキノ5.png");

	Graph.hiromi[0] = LoadGraph("画像/関1.png");
	Graph.hiromi[1] = LoadGraph("画像/関2.png");
	Graph.hiromi[2] = LoadGraph("画像/関3.png");//横
	Graph.hiromi[3] = LoadGraph("画像/関4.png");
	Graph.hiromi[4] = LoadGraph("画像/関5.png");

	Graph.yasuha[0] = LoadGraph("画像/岡崎1.png");
	Graph.yasuha[1] = LoadGraph("画像/岡崎2.png");//横
	Graph.yasuha[2] = LoadGraph("画像/岡崎3.png");
	Graph.yasuha[3] = LoadGraph("画像/岡崎4.png");
	

	Graph.mayu[0] = LoadGraph("画像/佐久間1.png");//横
	Graph.mayu[1] = LoadGraph("画像/佐久間2.png");
	Graph.mayu[2] = LoadGraph("画像/佐久間3.png");
	Graph.mayu[3] = LoadGraph("画像/佐久間4.png");
	Graph.mayu[4] = LoadGraph("画像/佐久間5.png");

	Graph.nagisa[0] = LoadGraph("画像/愛野1.png");
	Graph.nagisa[1] = LoadGraph("画像/愛野2.png");
	Graph.nagisa[2] = LoadGraph("画像/愛野3.png");
	Graph.nagisa[3] = LoadGraph("画像/愛野4.png");
	Graph.nagisa[4] = LoadGraph("画像/愛野5.png");//横

	//東北編起点
	Graph.karen[0] = LoadGraph("画像/北条1.png");
	Graph.karen[1] = LoadGraph("画像/北条2.png");
	Graph.karen[2] = LoadGraph("画像/北条3.png");
	Graph.karen[3] = LoadGraph("画像/北条4.png");//横
	Graph.karen[4] = LoadGraph("画像/北条5.png");//横

	Graph.miku[0] = LoadGraph("画像/前川1.png");
	Graph.miku[1] = LoadGraph("画像/前川2.png");//横
	Graph.miku[2] = LoadGraph("画像/前川3.png");
	Graph.miku[3] = LoadGraph("画像/前川4.png");
	Graph.miku[4] = LoadGraph("画像/前川5.png");

	Graph.chie[0] = LoadGraph("画像/佐々木1.png");
	Graph.chie[1] = LoadGraph("画像/佐々木2.png");
	Graph.chie[2] = LoadGraph("画像/佐々木3.png");
	Graph.chie[3] = LoadGraph("画像/佐々木4.png");
	Graph.chie[4] = LoadGraph("画像/佐々木5.png");//横

	Graph.tomoe[0] = LoadGraph("画像/村上1.png");
	Graph.tomoe[1] = LoadGraph("画像/村上2.png");
	Graph.tomoe[2] = LoadGraph("画像/村上3.png");
	Graph.tomoe[3] = LoadGraph("画像/村上4.png");//横
	Graph.tomoe[4] = LoadGraph("画像/村上5.png");

	Graph.kouzue[0] = LoadGraph("画像/遊佐1.png");
	Graph.kouzue[1] = LoadGraph("画像/遊佐2.png");
	Graph.kouzue[2] = LoadGraph("画像/遊佐3.png");
	Graph.kouzue[3] = LoadGraph("画像/遊佐4.png");//横
	Graph.kouzue[4] = LoadGraph("画像/遊佐5.png");//横

	Graph.natumi[0] = LoadGraph("画像/相馬1.png");
	Graph.natumi[1] = LoadGraph("画像/相馬2.png");//横
	Graph.natumi[2] = LoadGraph("画像/相馬3.png");
	Graph.natumi[3] = LoadGraph("画像/相馬4.png");//横
	Graph.natumi[4] = LoadGraph("画像/相馬5.png");

	Graph.minami[0] = LoadGraph("画像/新田1.png");
	Graph.minami[1] = LoadGraph("画像/新田2.png");
	

	Graph.nono[0] = LoadGraph("画像/のの1.png");
	Graph.nono[1] = LoadGraph("画像/のの2.png");//横
	Graph.nono[2] = LoadGraph("画像/のの3.png");//横
	Graph.nono[3] = LoadGraph("画像/のの4.png");
	Graph.nono[4] = LoadGraph("画像/のの5.png");

	Graph.marina[0] = LoadGraph("画像/沢田1.png");
	Graph.marina[1] = LoadGraph("画像/沢田2.png");
	Graph.marina[2] = LoadGraph("画像/沢田3.png");
	Graph.marina[3] = LoadGraph("画像/沢田4.png");
	Graph.marina[4] = LoadGraph("画像/沢田5.png");

	Graph.otsuki[0] = LoadGraph("画像/大槻1.png");
	Graph.otsuki[1] = LoadGraph("画像/大槻2.png");
	Graph.otsuki[2] = LoadGraph("画像/大槻3.png");
	Graph.otsuki[3] = LoadGraph("画像/大槻4.png");
	Graph.otsuki[4] = LoadGraph("画像/大槻5.png");

	Graph.misato[0] = LoadGraph("画像/美里1.png");
	Graph.misato[1] = LoadGraph("画像/美里2.png");
	Graph.misato[2] = LoadGraph("画像/美里3.png");
	Graph.misato[3] = LoadGraph("画像/美里4.png");
	Graph.misato[4] = LoadGraph("画像/美里5.png");

	Graph.suzuho[0] = LoadGraph("画像/上田1.png");
	Graph.suzuho[1] = LoadGraph("画像/上田2.png");
	Graph.suzuho[2] = LoadGraph("画像/上田3.png");
	Graph.suzuho[3] = LoadGraph("画像/上田4.png");
	Graph.suzuho[4] = LoadGraph("画像/上田5.png");

	Graph.nakano[0] = LoadGraph("画像/中野1.png");
	Graph.nakano[1] = LoadGraph("画像/中野2.png");
	Graph.nakano[2] = LoadGraph("画像/中野3.png");
	Graph.nakano[3] = LoadGraph("画像/中野4.png");
	Graph.nakano[4] = LoadGraph("画像/中野5.png");

	Graph.kana[0] = LoadGraph("画像/今井1.png");
	Graph.kana[1] = LoadGraph("画像/今井2.png");
	Graph.kana[2] = LoadGraph("画像/今井3.png");
	Graph.kana[3] = LoadGraph("画像/今井4.png");
	Graph.kana[4] = LoadGraph("画像/今井5.png");

	Graph.sarina[0] = LoadGraph("画像/松本1.png");
	Graph.sarina[1] = LoadGraph("画像/松本2.png");
	Graph.sarina[2] = LoadGraph("画像/松本3.png");
	Graph.sarina[3] = LoadGraph("画像/松本4.png");
	Graph.sarina[4] = LoadGraph("画像/松本5.png");

	Graph.nagisa[5] = LoadGraph("画像/渚1.png");
	Graph.nagisa[6] = LoadGraph("画像/渚2.png");
	Graph.nagisa[7] = LoadGraph("画像/渚3.png");
	Graph.nagisa[8] = LoadGraph("画像/渚4.png");
	Graph.nagisa[9] = LoadGraph("画像/渚5.png");

	Graph.yuki[0] = LoadGraph("画像/姫川1.png");
	Graph.yuki[1] = LoadGraph("画像/姫川2.png");
	Graph.yuki[2] = LoadGraph("画像/姫川3.png");
	Graph.yuki[3] = LoadGraph("画像/姫川4.png");
	Graph.yuki[4] = LoadGraph("画像/姫川5.png");

	Graph.chika[0] = LoadGraph("画像/横山1.png");
	Graph.chika[1] = LoadGraph("画像/横山2.png");
	Graph.chika[2] = LoadGraph("画像/横山3.png");
	Graph.chika[3] = LoadGraph("画像/横山4.png");
	Graph.chika[4] = LoadGraph("画像/横山5.png");

	Graph.ibuki[0] = LoadGraph("画像/小松1.png");
	Graph.ibuki[1] = LoadGraph("画像/小松2.png");
	Graph.ibuki[2] = LoadGraph("画像/小松3.png");
	Graph.ibuki[3] = LoadGraph("画像/小松4.png");
	Graph.ibuki[4] = LoadGraph("画像/小松5.png");

	//以下北関東編
	Graph.minami[2] = LoadGraph("画像/新田3.png");
	Graph.minami[3] = LoadGraph("画像/新田4.png");
	Graph.minami[4] = LoadGraph("画像/新田5.png");
	Graph.minami[5] = LoadGraph("画像/新田6.png");
	Graph.minami[6] = LoadGraph("画像/新田7.png");

	Graph.siki[0] = LoadGraph("画像/しき1.png");
	Graph.siki[1] = LoadGraph("画像/しき2.png");

	Graph.risa[0] = LoadGraph("画像/的場1.png");
	Graph.risa[1] = LoadGraph("画像/的場2.png");
	Graph.risa[2] = LoadGraph("画像/的場3.png");
	Graph.risa[3] = LoadGraph("画像/的場4.png");
	Graph.risa[4] = LoadGraph("画像/的場5.png");

	Graph.minami[3] = LoadGraph("画像/古河1.png");
	Graph.minami[3] = LoadGraph("画像/古河2.png");
	
	
	Graph.wakaba[0] = LoadGraph("画像/若葉1.png");
	Graph.wakaba[1] = LoadGraph("画像/若葉2.png");
	Graph.wakaba[2] = LoadGraph("画像/若葉3.png");
	Graph.wakaba[3] = LoadGraph("画像/若葉4.png");

	Graph.arisa[0] = LoadGraph("画像/持田1.png");
	Graph.arisa[1] = LoadGraph("画像/持田2.png");
	Graph.arisa[2] = LoadGraph("画像/持田3.png");
	Graph.arisa[3] = LoadGraph("画像/持田4.png");
	Graph.arisa[4] = LoadGraph("画像/持田5.png");

	Graph.yu[0] = LoadGraph("画像/太田1.png");
	Graph.yu[1] = LoadGraph("画像/太田2.png");
	Graph.yu[2] = LoadGraph("画像/太田3.png");
	Graph.yu[3] = LoadGraph("画像/太田4.jpg");
	Graph.yu[4] = LoadGraph("画像/太田5.jpg");

	graph[175] = LoadGraph("画像/桐生1.png");
	graph[176] = LoadGraph("画像/桐生2.png");
	graph[177] = LoadGraph("画像/桐生3.png");

	graph[180] = LoadGraph("画像/赤城1.png");
	graph[181] = LoadGraph("画像/赤城2.png");
	graph[182] = LoadGraph("画像/赤城3.png");
	graph[183] = LoadGraph("画像/赤城4.png");
	graph[184] = LoadGraph("画像/赤城5.png");

	graph[185] = LoadGraph("画像/中野6.png");
	graph[186] = LoadGraph("画像/中野7.png");
	graph[187] = LoadGraph("画像/中野8.png");
	graph[188] = LoadGraph("画像/中野9.png");
	graph[189] = LoadGraph("画像/中野10.png");

	graph[190] = LoadGraph("画像/藤原1.png");
	graph[191] = LoadGraph("画像/藤原2.png");
	graph[192] = LoadGraph("画像/藤原3.png");
	graph[193] = LoadGraph("画像/藤原4.png");
	graph[194] = LoadGraph("画像/藤原5.png");

	graph[200] = LoadGraph("画像/多田1.png");
	graph[201] = LoadGraph("画像/多田2.png");
	graph[202] = LoadGraph("画像/多田3.png");
	graph[203] = LoadGraph("画像/多田4.png");
	graph[204] = LoadGraph("画像/多田5.png");
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetBackgroundColor(255, 126, 45);
	ChangeWindowMode(TRUE), SetMainWindowText("あの子の同名地はどこだ!!!.exe"), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && UpdateKey() == 0) {
		//デバッグ↓
		//DrawFormatString(10, 10, GreenA, "%d", Report.stateofNO4);
		switch (state)//状況
		{
		case TITLE:
			title();
			break;
		case SEARCH:
			searching();
			break;
		
		case REPORT:
			reportmain();
			break;
		}
		move();//キー操作メソッド
	}

	DxLib_End();
	return 0;
}
void boxcolor() {
	time++;
	DrawBox(0, 0, time % 640, 60, GreenB, true);
	DrawBox(0, 420, 640 - (time % 640), 480, yellow, true);
	DrawBox(80, 0, 150, time % 480, skyblue, true);
	DrawBox(460, 480 - (time % 480), 530, 480, white, true);
};
void title() {
	SetFontSize(37);
	boxcolor();
	if (Titlestate == 0)
	{
		DrawString(160, 60 + time % 180, "あの子の同名地は", white);
		DrawString(220, 120 + time % 180, "どこだ!!!", blue);
		DrawString(200, 340, "START Enter", GreenA);
	}
	else
	{
		DrawString(50, 140, "A:ワードから検索", GreenA);
		
		DrawString(50, 240, "C:シリーズで検索", GreenA);
		DrawString(200, 340, "Title Enter", GreenA);
	}
}
void move() {
	switch (state)
	{
	case TITLE:
		if (Titlestate == 0)
		{
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				Titlestate = 1;
			}
		}
		else//メニュー画面
		{
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				Titlestate = 0;
			}
			/*if (Key[KEY_INPUT_A] == 1)
			{
				state = SEARCH;
			}*/
			
			if (Key[KEY_INPUT_C] == 1)
			{
				SetFontSize(31);
				DrawString(10, 370, "Now Loading...", GreenB);
				state = REPORT;
			}
		}
		break;
	case SEARCH:
		if (Key[KEY_INPUT_RETURN] == 1)
		{
			Search.state = 0;
			state = TITLE;
		}
		switch (Search.state)
		{
		case 0:
			if (Key[KEY_INPUT_A] == 1)
			{
				Search.state = 1;
			}
			if (Key[KEY_INPUT_B] == 1)
			{
				Search.state = 2;
			}
			if (Key[KEY_INPUT_C] == 1)
			{
				Search.state = 3;
			}
			break;
		case 1:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Search.state = 0;
			}
			break;
		case 2:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Search.state = 0;
			}
			break;
		case 3:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Search.state = 0;
			}
			break;
		}
		break;

	case REPORT:
		if (Report.graphinflag == false)
		{
			graphinit();
			Report.graphinflag = true;
		}
		switch (Report.state)
		{
		case 0://レポート選択画面
			if (Key[KEY_INPUT_A] == 1)//静岡東部編
			{
				Report.state = 1;
			}
			if (Key[KEY_INPUT_B] == 1)//中部地方編
			{
				Report.state = 11;
			}
			if (Key[KEY_INPUT_C] == 1)//南東北編
			{
				Report.state = 21;
			}
			if (Key[KEY_INPUT_D] == 1)//北関東編
			{
				Report.state = 31;
			}
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				state = TITLE;
			}
			break;
		case 1://静岡東部メニュー
			if (Key[KEY_INPUT_RIGHT] == 1)
			{
				if (Report.stateofNO1 == 3)
				{
					Report.stateofNO1 = 0;
				}
				else
				{
					Report.stateofNO1++;
				}
				
			}
			if (Key[KEY_INPUT_LEFT] == 1)
			{
				if (Report.stateofNO1 == 0)
				{
					Report.stateofNO1 = 3;
				}
				else
				{
					Report.stateofNO1--;
				}
			}
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				if (Report.stateofNO1 == 0)
				{
					Report.state = 2;
				}
				if (Report.stateofNO1 == 1)
				{
					Report.state = 3;
				}
				if (Report.stateofNO1 == 2)
				{
					Report.state = 4;
				}
				if (Report.stateofNO1 == 3)
				{
					Report.state = 5;
				}

			}
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 0;
			}
			break;

		case 2:
		case 3:
		case 4:
		case 5:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 1;
			}
			if (Key[KEY_INPUT_ESCAPE] == 1)
			{
				if (Report.charon == false)
				{
					Report.charon = true;
				}
				else
				{
					Report.charon = false;
				}
				
			}
			break;

		case 11://中部地方編メニュー
			if (Key[KEY_INPUT_RIGHT] == 1)
			{
				if (Report.stateofNO2 == 5)
				{
					Report.stateofNO2 = 0;
				}
				else
				{
					Report.stateofNO2++;
				}

			}
			if (Key[KEY_INPUT_LEFT] == 1)
			{
				if (Report.stateofNO2 == 0)
				{
					Report.stateofNO2 = 5;
				}
				else
				{
					Report.stateofNO2--;
				}
			}
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				if (Report.stateofNO2 == 0)
				{
					Report.state = 12;
				}
				if (Report.stateofNO2 == 1)
				{
					Report.state = 13;
				}
				if (Report.stateofNO2 == 2)
				{
					Report.state = 14;
				}
				if (Report.stateofNO2 == 3)
				{
					Report.state = 15;
				}
				if (Report.stateofNO2 == 4)
				{
					Report.state = 16;
				}
				if (Report.stateofNO2 == 5)
				{
					Report.state = 17;
				}

			}
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 0;
			}
			break;

		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 11;
			}
			if (Key[KEY_INPUT_ESCAPE] == 1)
			{
				if (Report.charon == false)
				{
					Report.charon = true;
				}
				else
				{
					Report.charon = false;
				}

			}
			break;

		case 21://東北編メニュー
			if (Key[KEY_INPUT_RIGHT] == 1)
			{
				if (Report.stateofNO3 == 8)
				{
					Report.stateofNO3 = 0;
				}
				else
				{
					Report.stateofNO3++;
				}

			}
			if (Key[KEY_INPUT_LEFT] == 1)
			{
				if (Report.stateofNO3 == 0)
				{
					Report.stateofNO3 = 8;
				}
				else
				{
					Report.stateofNO3--;
				}
			}
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				if (Report.stateofNO3 == 0)
				{
					Report.state = 22;
				}
				if (Report.stateofNO3 == 1)
				{
					Report.state = 23;
				}
				if (Report.stateofNO3 == 2)
				{
					Report.state = 24;
				}
				if (Report.stateofNO3 == 3)
				{
					Report.state = 25;
				}
				if (Report.stateofNO3 == 4)
				{
					Report.state = 26;
				}
				if (Report.stateofNO3 == 5)
				{
					Report.state = 27;
				}
				if (Report.stateofNO3 == 6)
				{
					Report.state = 28;
				}
				if (Report.stateofNO3 == 7)
				{
					Report.state = 29;
				}
				if (Report.stateofNO3 == 8)
				{
					Report.state = 30;
				}

			}
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 0;
			}
			break;

		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 21;
			}
			if (Key[KEY_INPUT_ESCAPE] == 1)
			{
				if (Report.charon == false)
				{
					Report.charon = true;
				}
				else
				{
					Report.charon = false;
				}

			}
			break;

		case 31://北関東編メニュー
			switch (Report.stateofNO4)
			{
			case 0://新田
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 10;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4++;
				}
				break;
			case 1://志木
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 9;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 2://的場
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 3://若葉
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 4://持田
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4--;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4 = 9;
				}
				break;
			case 5://太田
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4--;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4 = 14;
				}
				break;
			case 6://桐生
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 8;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4--;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4 = 14;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4++;
				}
				break;
			case 7://赤城
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 8://中野
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4 = 6;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4 = 15;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 9://古河
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 14;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4 = 1;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4 = 4;
				}
				break;
			case 10://結城
			case 11://川島
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 13;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4 = 0;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 12://大和
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 13;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 13://氏家
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4 = 10;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4--;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4 = 15;
				}
				break;
			case 14://多田
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4 = 9;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4 = 10;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4 = 6;
				}
				break;
			case 15://新藤原
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4--;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4 = 13;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4 = 8;
				}
				break;
			}
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				if (Report.stateofNO4 == 0)
				{
					Report.state = 32;
				}
				if (Report.stateofNO4 == 1)
				{
					Report.state = 33;
				}
				if (Report.stateofNO4 == 2)
				{
					Report.state = 34;
				}
				if (Report.stateofNO4 == 3)
				{
					Report.state = 35;
				}
				if (Report.stateofNO4 == 4)
				{
					Report.state = 36;
				}
				if (Report.stateofNO4 == 5)
				{
					Report.state = 37;
				}
				if (Report.stateofNO4 == 6)
				{
					Report.state = 38;
				}
				if (Report.stateofNO4 == 7)
				{
					Report.state = 39;
				}
				if (Report.stateofNO4 == 8)
				{
					Report.state = 40;
				}
				if (Report.stateofNO4 == 9)
				{
					Report.state = 41;
				}
				if (Report.stateofNO4 == 10)
				{
					Report.state = 42;
				}
				if (Report.stateofNO4 == 11)
				{
					Report.state = 43;
				}
				if (Report.stateofNO4 == 12)
				{
					Report.state = 44;
				}
				if (Report.stateofNO4 == 13)
				{
					Report.state = 45;
				}
				if (Report.stateofNO4 == 14)
				{
					Report.state = 46;
				}
				if (Report.stateofNO4 == 15)
				{
					Report.state = 47;
				}
			}
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 0;
			}
			break;

		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		case 39:
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
			if (Key[KEY_INPUT_BACK] == 1)
			{
				Report.state = 31;
			}
			if (Key[KEY_INPUT_ESCAPE] == 1)
			{
				if (Report.charon == false)
				{
					Report.charon = true;
				}
				else
				{
					Report.charon = false;
				}

			}
			break;
		}
	
		break;
	}
}
void reportmain() {
	switch (Report.state)
	{
	case 0://レポート選択画面
		SetFontSize(29);
		boxcolor();
		SetBackgroundColor(255, 126, 45);
		DrawString(50, 140, "A:Vol.1(静岡東部編)", GreenA);
		DrawString(50, 190, "B:Vol.2(中部地方編)", GreenA);
		DrawString(50, 240, "C:Vol.3(中越・上越・南東北編)", GreenA);
		DrawString(50, 290, "D:Vol.4(ほぼ北関東編)", GreenA);
		DrawString(200, 340, "Menu Enter", GreenA);
		break;
	case 1://NO1選択画面
		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawBox(0, 300, 490, 480, skyblue, true);//海
		DrawCircle(60, 280, 15, orange, true);
		DrawCircle(260, 100, 15, orange, true);
		DrawCircle(330, 150, 15, orange, true);
		DrawCircle(400, 150, 15, orange, true);

		DrawString(0, 0, "Vol.1(静岡東部編)", orange);
		DrawString(0, 230, "由比(ゆい)", orange);
		DrawString(200, 50, "岳南原田", orange);
		DrawString(300, 100, "比奈", orange);
		DrawString(370, 100, "神谷", orange);
		DrawString(400, 450, "Backspaceで戻る", orange);

		if (Report.stateofNO1 == 0)
		{
			DrawCircle(60, 280, 15, red, true);
		}
		if (Report.stateofNO1 == 1)
		{
			DrawCircle(260, 100, 15, red, true);
		}
		if (Report.stateofNO1 == 2)
		{
			DrawCircle(330, 150, 15, red, true);
		}
		if (Report.stateofNO1 == 3)
		{
			DrawCircle(400, 150, 15, red, true);
		}

		break;
	case 2:
		time++;
		DrawGraph(0, 0, Graph.yui[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 4 && time <= 360 * 5 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(100, 400, "大槻唯", yellow);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "東海道線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "静岡県静岡市清水区", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "大槻唯", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "東海道線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "静岡県静岡市清水区", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 3:
		time++;
		DrawGraph(0, 0, Graph.harada[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 3 && time <= 360 * 5 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "原田美世", pink);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "岳南電車", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "静岡県富士市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "原田美世", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "岳南電車", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "静岡県富士市", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 4:
		time++;
		DrawGraph(0, 0, Graph.hina[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "荒木比奈", skyblue);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "岳南電車", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "静岡県富士市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 5:
		time++;
		DrawGraph(0, 0, Graph.nao[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "神谷奈緒", skyblue);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "岳南電車", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "静岡県富士市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 11://NO2選択画面
		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawBox(0, 0, 90, 200, skyblue, true);//若狭湾
		DrawTriangle(0, 0, 200, 0, 90, 200, skyblue, true);//日本海
		DrawBox(55, 250, 92, 360, skyblue, true);//琵琶湖
		DrawBox(255, 300, 330, 480, skyblue, true);//伊勢湾
		DrawBox(270, 380, 490, 440, skyblue, true);//三河湾1
		DrawBox(360, 330, 390, 440, skyblue, true);//三河湾2
		DrawBox(545, 385, 575, 480, skyblue, true);//浜名湖

		DrawCircle(40, 270, 15, orange, true);//マキノ
		DrawCircle(174, 180, 15, orange, true);//南条
		DrawCircle(194, 364, 15, orange, true);//関
		DrawCircle(440, 315, 15, orange, true);//岡崎
		DrawCircle(590, 277, 15, orange, true);//佐久間
		DrawCircle(623, 435, 15, orange, true);//愛野

		DrawString(0, 0, "Vol.2(中部地方編)", orange);
		DrawString(0, 290, "マキノ", orange);
		DrawString(162, 200, "南条", orange);
		DrawString(182, 384, "関", orange);
		DrawString(416, 335, "岡崎", orange);
		DrawString(550, 297, "佐久間", orange);
		DrawString(580, 390, "愛野", orange);
		DrawString(10, 450, "Backspaceで戻る", orange);

		if (Report.stateofNO2 == 0)
		{
			DrawCircle(40, 270, 15, red, true);
		}
		if (Report.stateofNO2 == 1)
		{
			DrawCircle(174, 180, 15, red, true);
		}
		if (Report.stateofNO2 == 2)
		{
			DrawCircle(194, 364, 15, red, true);
		}
		if (Report.stateofNO2 == 3)
		{
			DrawCircle(440, 315, 15, red, true);
		}
		if (Report.stateofNO2 == 4)
		{
			DrawCircle(590, 277, 15, red, true);
		}
		if (Report.stateofNO2 == 5)
		{
			DrawCircle(623, 435, 15, red, true);
		}

		break;
	case 12:
		time++;
		DrawGraph(0, 0, Graph.makino[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "八神マキノ", skyblue);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "湖西線", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "滋賀県高島市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 13:
		time++;
		DrawGraph(0, 0, Graph.nanjo[time / 360], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 2 && time <= 360 * 3 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(100, 400, "南条光", yellow);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "北陸本線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "福井県南条郡南越前町", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "南条光", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "北陸本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "福井県南条郡南越前町", yellow);
			}
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 14:
		time++;
		DrawGraph(0, 0, Graph.hiromi[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 2 && time <= 360 * 3 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(100, 400, "関裕美", pink);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "関西本線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "三重県亀山市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "関裕美", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "関西本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "三重県亀山市", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 15:
		time++;
		DrawGraph(0, 0, Graph.yasuha[time / SETTIME], false);
		if (time >= 360 * 4 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 && time <= 360 * 2)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "岡崎泰葉", skyblue);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "東海道線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "愛知県岡崎市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "岡崎泰葉", skyblue);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "東海道線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "愛知県岡崎市", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 16:
		time++;
		DrawGraph(0, 0, Graph.mayu[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time <= 360 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "佐久間まゆ", pink);
				DrawString(230, 400, "駅路線", orange);
				DrawString(330, 400, "飯田線", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(330, 440, "静岡県浜松市天竜区", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "佐久間まゆ", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "飯田線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "静岡県浜松市天竜区", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 17:
		time++;
		DrawGraph(0, 0, Graph.nagisa[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 4 && time <= 360 * 5 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(100, 400, "愛野渚", yellow);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "東海道線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "静岡県袋井市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "愛野渚", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "東海道線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "静岡県袋井市", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 21://NO3選択画面
		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawTriangle(0, 390, 200, 240, 0, 240, skyblue, true);//日本海
		DrawBox(0, 0, 200, 240, skyblue, true);//日本海
		DrawBox(470, 200, 640, 480, skyblue, true);//太平洋
		DrawBox(550, 0, 640, 200, skyblue, true);//太平洋

		DrawCircle(120, 425, 15, orange, true);//前川
		DrawCircle(20, 429, 15, orange, true);//北条
		DrawCircle(180, 305, 15, orange, true);//佐々木
		DrawCircle(219, 227, 15, orange, true);//村上
		DrawCircle(220, 70, 15, orange, true);//遊佐
		DrawCircle(454, 82, 15, orange, true);//新田
		DrawCircle(492, 139, 15, orange, true);//ののだけ
		DrawCircle(531, 180, 15, orange, true);//沢田
		DrawCircle(451, 365, 15, orange, true);//相馬

		DrawString(0, 0, "Vol.3(中越・上越・南東北編)", orange);
		DrawString(93, 385, "前川", orange);
		DrawString(0, 390, "北条", orange);
		DrawString(133, 325, "佐々木", orange);
		DrawString(192, 247, "村上", orange);
		DrawString(193, 90, "遊佐", orange);
		DrawString(427, 42, "新田", orange);
		DrawString(437, 99, "ののだけ", orange);
		DrawString(504, 200, "沢田", orange);
		DrawString(424, 385, "相馬", orange);

		DrawString(110, 450, "Backspace:戻る", orange);
		if (Report.stateofNO3 == 0)
		{
			DrawCircle(20, 429, 15, red, true);
		}
		if (Report.stateofNO3 == 1)
		{
			DrawCircle(120, 425, 15, red, true);
		}
		if (Report.stateofNO3 == 2)
		{
			DrawCircle(180, 305, 15, red, true);
		}
		if (Report.stateofNO3 == 3)
		{
			DrawCircle(219, 227, 15, red, true);
		}
		if (Report.stateofNO3 == 4)
		{
			DrawCircle(220, 70, 15, red, true);
		}
		if (Report.stateofNO3 == 5)
		{
			DrawCircle(451, 365, 15, red, true);
		}
		if (Report.stateofNO3 == 6)
		{
			DrawCircle(454, 82, 15, red, true);
		}
		if (Report.stateofNO3 == 7)
		{
			DrawCircle(492, 139, 15, red, true);
		}
		if (Report.stateofNO3 == 8)
		{
			DrawCircle(531, 180, 15, red, true);
		}
		break;
	case 22:
		time++;
		DrawGraph(0, 0, Graph.karen[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 3 && time <= 360 * 5 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "北条加蓮", skyblue);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "信越本線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "新潟県柏崎市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "北条加蓮", skyblue);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "信越本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "新潟県柏崎市", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 23:
		time++;
		DrawGraph(0, 0, Graph.miku[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 && time <= 360 * 2 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "前川みく", pink);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "信越本線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "新潟県長岡市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "前川みく", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "信越本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "新潟県長岡市", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 24:
		time++;
		DrawGraph(0, 0, Graph.chie[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 4 && time <= 360 * 5 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "佐々木千枝", skyblue);
				DrawString(230, 400, "駅路線", orange);
				DrawString(320, 400, "白新線", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(320, 440, "新潟県新発田市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "佐々木千枝", skyblue);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "白新線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "新潟県新発田市", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 25:
		time++;
		DrawGraph(0, 0, Graph.tomoe[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 2 && time <= 360 * 3 - 1)
			{
				DrawString(400, 0, "名前", orange);
				DrawString(400, 40, "村上巴", yellow);
				DrawString(400, 80, "駅路線", orange);
				DrawString(400, 120, "羽越本線", yellow);
				DrawString(400, 160, "所在地", orange);
				DrawString(400, 200, "新潟県村上市", yellow);
			}
			else if (time >= 360 * 3 && time <= 360 * 4 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(100, 400, "村上巴", yellow);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "羽越本線", yellow);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "新潟県村上市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "村上巴", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "羽越本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "新潟県村上市", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 26:
		time++;
		DrawGraph(0, 0, Graph.kouzue[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 3 && time <= 360 * 5 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "遊佐こずえ", pink);
				DrawString(230, 400, "駅路線", orange);
				DrawString(320, 400, "羽越本線", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(320, 440, "山形県遊佐町", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "遊佐こずえ", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "羽越本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "山形県遊佐町", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 27:
		time++;
		DrawGraph(0, 0, Graph.natumi[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 && time <= 360 * 2 - 1 || time >= 360 * 3 && time <= 360 * 4 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "相馬夏美", yellow);
				DrawString(200, 400, "駅路線", orange);
				DrawString(300, 400, "常磐線", skyblue);
				DrawString(200, 440, "所在地", orange);
				DrawString(300, 440, "福島県相馬市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "相馬夏美", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "常磐線", skyblue);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "福島県相馬市", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 28:
		time++;
		DrawGraph(0, 0, Graph.minami[time / SETTIME], false);
		if (time >= 360 * 2 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "新田美波", skyblue);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "東北本線", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "宮城県登米市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 29:
		time++;
		DrawGraph(0, 0, Graph.nono[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 && time <= 360 * 3 - 1)
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "森久保乃々", skyblue);
				DrawString(230, 400, "駅路線", orange);
				DrawString(320, 400, "気仙沼線", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(320, 440, "宮城県涌谷町", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "森久保乃々", skyblue);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "気仙沼線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "宮城県涌谷町", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 30:
		time++;
		DrawGraph(0, 0, Graph.marina[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 * 4 && time <= 360 * 5 - 1)
			{
				DrawString(400, 0, "名前", orange);
				DrawString(400, 40, "沢田麻理菜", yellow);
				DrawString(400, 80, "駅路線", orange);
				DrawString(400, 120, "石巻線", yellow);
				DrawString(400, 160, "所在地", orange);
				DrawString(400, 200, "宮城県石巻市", yellow);
			}
			else
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "沢田麻理菜", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "石巻線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "宮城県石巻市", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;

	case 31://NO4選択画面

		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawCircle(800, 480 / 2, 480 / 2, skyblue, true);//太平洋
		DrawTriangle(640, 0, 560, 230, 640, 240, skyblue, true);//太平洋
		//埼玉
		DrawCircle(290, 445, 15, orange, true);//新田
		DrawCircle(160, 460, 15, orange, true);//志木
		DrawCircle(85, 300, 15, orange, true);//持田
		DrawCircle(90, 400, 15, orange, true);//的場
		DrawCircle(80, 370, 15, orange, true);//若葉
		//群馬
		DrawCircle(70, 230, 15, orange, true);//太田
		DrawCircle(55, 150, 15, orange, true);//桐生
		DrawCircle(25, 145, 15, orange, true);//赤城
		DrawCircle(40, 110, 15, orange, true);//中野
		//茨城
		DrawCircle(230, 280, 15, orange, true);//古河
		DrawCircle(310, 225, 15, orange, true);//結城
		DrawCircle(340, 225, 15, orange, true);//川島
		DrawCircle(415, 210, 15, orange, true);//大和
		//栃木
		DrawCircle(320, 50, 15, orange, true);//氏家
		DrawCircle(165, 180, 15, orange, true);//多田
		DrawCircle(206, 15, 15, orange, true);//新藤原

		DrawString(270, 0, "Vol.4(ほぼ北関東編)", orange);
		DrawString(270, 405, "新田", orange);
		DrawString(140, 420, "志木", orange);
		DrawString(65, 260, "持田", orange);
		DrawString(70, 420, "的場", orange);
		DrawString(60, 330, "若葉", orange);

		DrawString(90, 220, "太田", orange);
		DrawString(75, 140, "桐生", orange);
		DrawString(0, 165, "赤城", orange);
		DrawString(15, 70, "中野", orange);

		DrawString(205, 240, "古河", orange);
		DrawString(285, 185, "結城", orange);
		DrawString(315, 245, "川島", orange);
		DrawString(389, 170, "大和", orange);

		DrawString(298, 70, "氏家", orange);
		DrawString(140, 140, "多田", orange);
		DrawString(166, 35, "新藤原", orange);

		DrawString(410, 450, "Backspaceで戻る", orange);

		if (Report.stateofNO4 == 0)
		{
			DrawCircle(290, 445, 15, red, true);
		}
		if (Report.stateofNO4 == 1)
		{
			DrawCircle(160, 460, 15, red, true);
		}
		if (Report.stateofNO4 == 2)
		{
			DrawCircle(90, 400, 15, red, true);
		}
		if (Report.stateofNO4 == 3)
		{
			DrawCircle(80, 370, 15, red, true);
		}
		if (Report.stateofNO4 == 4)
		{
			DrawCircle(85, 300, 15, red, true);
		}
		if (Report.stateofNO4 == 5)
		{
			DrawCircle(70, 230, 15, red, true);
		}
		if (Report.stateofNO4 == 6)
		{
			DrawCircle(55, 150, 15, red, true);
		}
		if (Report.stateofNO4 == 7)
		{
			DrawCircle(25, 145, 15, red, true);
		}
		if (Report.stateofNO4 == 8)
		{
			DrawCircle(40, 110, 15, red, true);
		}
		if (Report.stateofNO4 == 9)
		{
			DrawCircle(230, 280, 15, red, true);
		}
		if (Report.stateofNO4 == 10)
		{
			DrawCircle(310, 225, 15, red, true);
		}
		if (Report.stateofNO4 == 11)
		{
			DrawCircle(340, 225, 15, red, true);
		}
		if (Report.stateofNO4 == 12)
		{
			DrawCircle(415, 210, 15, red, true);
		}
		if (Report.stateofNO4 == 13)
		{
			DrawCircle(320, 50, 15, red, true);
		}
		if (Report.stateofNO4 == 14)
		{
			DrawCircle(165, 180, 15, red, true);
		}
		if (Report.stateofNO4 == 15)
		{
			DrawCircle(206, 15, 15, red, true);
		}

		break;
	case 32:
		time++;
		DrawGraph(0, 0, Graph.minami[2 + time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "新田美波", skyblue);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "東武スカイツリーライン", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "埼玉県草加市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 33:
		time++;
		DrawGraph(0, 0, Graph.siki[time / SETTIME], false);
		if (time >= 360 * 2 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "一ノ瀬志希", pink);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "東武東上線", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "埼玉県志木市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 34://的場
		time++;
		DrawGraph(0, 0, Graph.risa[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time <= 360 * 4 - 1)
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "的場梨沙", yellow);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "川越線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "埼玉県川越市", yellow);
			}
			else
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "的場梨沙", yellow);
				DrawString(230, 400, "駅路線", orange);
				DrawString(320, 400, "川越線", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(320, 440, "埼玉県川越市", yellow);
			}
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 35:
		time++;
		DrawGraph(0, 0, Graph.wakaba[time / SETTIME], false);
		if (time >= 360 * 4 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "日下部若葉", pink);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "東武東上線", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "埼玉県坂戸市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 36:
		time++;
		DrawGraph(0, 0, Graph.arisa[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time >= 360 && time <= 360 * 3 - 1)
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "持田亜里沙", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "秩父鉄道秩父本線", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "埼玉県行田市", yellow);

			}
			else
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "持田亜里沙", pink);
				DrawString(230, 400, "駅路線", orange);
				DrawString(320, 400, "秩父鉄道秩父本線", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(320, 440, "埼玉県行田市", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 37:
		time++;
		DrawGraph(0, 0, Graph.yu[time / SETTIME], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			if (time <= 360 * 3 - 1)
			{
				DrawString(300, 0, "名前", orange);
				DrawString(300, 40, "太田優", pink);
				DrawString(300, 80, "駅路線", orange);
				DrawString(300, 120, "東武伊勢崎線など", yellow);
				DrawString(300, 160, "所在地", orange);
				DrawString(300, 200, "群馬県太田市", yellow);
			}
			else
			{
				DrawString(0, 400, "名前", orange);
				DrawString(70, 400, "太田優", pink);
				DrawString(230, 400, "駅路線", orange);
				DrawString(320, 400, "東武伊勢崎線など", yellow);
				DrawString(230, 440, "所在地", orange);
				DrawString(320, 440, "群馬県太田市", yellow);
			}
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 38:
		time++;
		DrawGraph(0, 0, graph[145 + Report.stateofNO4 * 5 + time / 360], false);
		if (time >= 360 * 3 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "桐生つかさ", skyblue);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "両毛線など", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "群馬県桐生市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 39:
		time++;
		DrawGraph(0, 0, graph[145 + Report.stateofNO4 * 5 + time / 360], false);
		if (time >= 360 * 5 - 1)
		{
			time = 0;
		}
		if (Report.charon)
		{
			DrawString(300, 0, "名前", orange);
			DrawString(300, 40, "赤城みりあ", yellow);
			DrawString(300, 80, "駅路線", orange);
			DrawString(300, 120, "東武桐生線など", yellow);
			DrawString(300, 160, "所在地", orange);
			DrawString(300, 200, "群馬県みどり市", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:文字情報", yellow);
		}
		break;
	case 40://中野
		time++;
		break;
	case 41://古河
		time++;
		break;
	case 42://結城
		time++;
		break;
	case 43://川島
		time++;
		break;
	case 44://大和
		time++;
		break;
	case 45://氏家
		time++;
		break;
	case 46://多田
		time++;
		break;
	case 47://新藤原
		time++;
		break;
	}
}
void searching() {
	switch (Search.state)
	{
	case 0://メニュー
		
		break;
	case 1:
		
		break;
	case 2:
		SetFontSize(25);
		
		break;
	case 3:
		
		break;
	}
}