#include"DxLib.h"
#define TITLE 0
#define SEARCH 1
#define REPORT 3

#define SETTIME 360

int Key[256];//�L�[�n���h��
int graph[256];//�O���t�n���h��

byte state;//��

byte Titlestate;//�^�C�g����ʂ̏�

void title();//�^�C�g�����

void move();//�{�^���ړ�

void boxcolor();//�l�p�J���[���o

void graphinit();//�摜�ǂݍ���


int time;//�^�C���R�[�h


//�F
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

//���|�[�g�֐�
void reportmain();
struct 
{
	byte state;//�󋵕ϐ�

	byte stateofNO1;//�É������҂̃T�C���ړ��p�ϐ�
	byte stateofNO2;//���C�E�O�M�E���i�ΐ��҂̃T�C���ړ��p�ϐ�
	byte stateofNO3;//���z�E��z�E�쓌�k�҂̃T�C���ړ��p�ϐ�
	byte stateofNO4;//�k�֓��҂̃T�C���ړ��p�ϐ�

	bool charon;//�������̃I���I�t
	bool graphinflag;//�摜�ǂݍ��݊m�F

}Report;
//SEARCH�֐�
void searching();
struct
{
	byte state;//�󋵕ϐ�

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

//�摜�f�[�^����
struct {
	int yui[5];
	int harada[5];
	int hina[5];
	int nao[5];
	int makino[5];
	int hiromi[5];
	int yasuha[4];
	int mayu[5];

	//5�܂ł͐É�,6����͒���
	int nagisa[10];

	int karen[5];
	int miku[5];
	int chie[5];
	int tomoe[5];
	int kouzue[5];
	int natumi[5];

	//2�܂ł͋{��,3������
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
	Graph.nanjo[0] = LoadGraph("�摜/���1.png");
	Graph.nanjo[1] = LoadGraph("�摜/���2.png");
	Graph.nanjo[2] = LoadGraph("�摜/���3.png");//��
	Graph.nanjo[3] = LoadGraph("�摜/���4.png");
	Graph.nanjo[4] = LoadGraph("�摜/���5.png");

	Graph.yui[0] = LoadGraph("�摜/�䂢1.png");
	Graph.yui[1] = LoadGraph("�摜/�䂢2.png");
	Graph.yui[2] = LoadGraph("�摜/�䂢3.png");
	Graph.yui[3] = LoadGraph("�摜/�䂢4.png");
	Graph.yui[4] = LoadGraph("�摜/�䂢5.png");//��

	Graph.harada[0] = LoadGraph("�摜/���c1.png");
	Graph.harada[1] = LoadGraph("�摜/���c2.png");
	Graph.harada[2] = LoadGraph("�摜/���c3.png");
	Graph.harada[3] = LoadGraph("�摜/���c4.png");//��
	Graph.harada[4] = LoadGraph("�摜/���c5.png");//��

	Graph.hina[0] = LoadGraph("�摜/�Ђ�1.png");
	Graph.hina[1] = LoadGraph("�摜/�Ђ�2.png");
	Graph.hina[2] = LoadGraph("�摜/�Ђ�3.png");
	Graph.hina[3] = LoadGraph("�摜/�Ђ�4.png");
	Graph.hina[4] = LoadGraph("�摜/�Ђ�5.png");

	Graph.nao[0] = LoadGraph("�摜/�_�J1.png");
	Graph.nao[1] = LoadGraph("�摜/�_�J2.png");
	Graph.nao[2] = LoadGraph("�摜/�_�J3.png");
	Graph.nao[3] = LoadGraph("�摜/�_�J4.png");
	Graph.nao[4] = LoadGraph("�摜/�_�J5.png");

	Graph.makino[0] = LoadGraph("�摜/�}�L�m1.png");
	Graph.makino[1] = LoadGraph("�摜/�}�L�m2.png");
	Graph.makino[2] = LoadGraph("�摜/�}�L�m3.png");
	Graph.makino[3] = LoadGraph("�摜/�}�L�m4.png");
	Graph.makino[4] = LoadGraph("�摜/�}�L�m5.png");

	Graph.hiromi[0] = LoadGraph("�摜/��1.png");
	Graph.hiromi[1] = LoadGraph("�摜/��2.png");
	Graph.hiromi[2] = LoadGraph("�摜/��3.png");//��
	Graph.hiromi[3] = LoadGraph("�摜/��4.png");
	Graph.hiromi[4] = LoadGraph("�摜/��5.png");

	Graph.yasuha[0] = LoadGraph("�摜/����1.png");
	Graph.yasuha[1] = LoadGraph("�摜/����2.png");//��
	Graph.yasuha[2] = LoadGraph("�摜/����3.png");
	Graph.yasuha[3] = LoadGraph("�摜/����4.png");
	

	Graph.mayu[0] = LoadGraph("�摜/���v��1.png");//��
	Graph.mayu[1] = LoadGraph("�摜/���v��2.png");
	Graph.mayu[2] = LoadGraph("�摜/���v��3.png");
	Graph.mayu[3] = LoadGraph("�摜/���v��4.png");
	Graph.mayu[4] = LoadGraph("�摜/���v��5.png");

	Graph.nagisa[0] = LoadGraph("�摜/����1.png");
	Graph.nagisa[1] = LoadGraph("�摜/����2.png");
	Graph.nagisa[2] = LoadGraph("�摜/����3.png");
	Graph.nagisa[3] = LoadGraph("�摜/����4.png");
	Graph.nagisa[4] = LoadGraph("�摜/����5.png");//��

	//���k�ҋN�_
	Graph.karen[0] = LoadGraph("�摜/�k��1.png");
	Graph.karen[1] = LoadGraph("�摜/�k��2.png");
	Graph.karen[2] = LoadGraph("�摜/�k��3.png");
	Graph.karen[3] = LoadGraph("�摜/�k��4.png");//��
	Graph.karen[4] = LoadGraph("�摜/�k��5.png");//��

	Graph.miku[0] = LoadGraph("�摜/�O��1.png");
	Graph.miku[1] = LoadGraph("�摜/�O��2.png");//��
	Graph.miku[2] = LoadGraph("�摜/�O��3.png");
	Graph.miku[3] = LoadGraph("�摜/�O��4.png");
	Graph.miku[4] = LoadGraph("�摜/�O��5.png");

	Graph.chie[0] = LoadGraph("�摜/���X��1.png");
	Graph.chie[1] = LoadGraph("�摜/���X��2.png");
	Graph.chie[2] = LoadGraph("�摜/���X��3.png");
	Graph.chie[3] = LoadGraph("�摜/���X��4.png");
	Graph.chie[4] = LoadGraph("�摜/���X��5.png");//��

	Graph.tomoe[0] = LoadGraph("�摜/����1.png");
	Graph.tomoe[1] = LoadGraph("�摜/����2.png");
	Graph.tomoe[2] = LoadGraph("�摜/����3.png");
	Graph.tomoe[3] = LoadGraph("�摜/����4.png");//��
	Graph.tomoe[4] = LoadGraph("�摜/����5.png");

	Graph.kouzue[0] = LoadGraph("�摜/�V��1.png");
	Graph.kouzue[1] = LoadGraph("�摜/�V��2.png");
	Graph.kouzue[2] = LoadGraph("�摜/�V��3.png");
	Graph.kouzue[3] = LoadGraph("�摜/�V��4.png");//��
	Graph.kouzue[4] = LoadGraph("�摜/�V��5.png");//��

	Graph.natumi[0] = LoadGraph("�摜/���n1.png");
	Graph.natumi[1] = LoadGraph("�摜/���n2.png");//��
	Graph.natumi[2] = LoadGraph("�摜/���n3.png");
	Graph.natumi[3] = LoadGraph("�摜/���n4.png");//��
	Graph.natumi[4] = LoadGraph("�摜/���n5.png");

	Graph.minami[0] = LoadGraph("�摜/�V�c1.png");
	Graph.minami[1] = LoadGraph("�摜/�V�c2.png");
	

	Graph.nono[0] = LoadGraph("�摜/�̂�1.png");
	Graph.nono[1] = LoadGraph("�摜/�̂�2.png");//��
	Graph.nono[2] = LoadGraph("�摜/�̂�3.png");//��
	Graph.nono[3] = LoadGraph("�摜/�̂�4.png");
	Graph.nono[4] = LoadGraph("�摜/�̂�5.png");

	Graph.marina[0] = LoadGraph("�摜/��c1.png");
	Graph.marina[1] = LoadGraph("�摜/��c2.png");
	Graph.marina[2] = LoadGraph("�摜/��c3.png");
	Graph.marina[3] = LoadGraph("�摜/��c4.png");
	Graph.marina[4] = LoadGraph("�摜/��c5.png");

	Graph.otsuki[0] = LoadGraph("�摜/���1.png");
	Graph.otsuki[1] = LoadGraph("�摜/���2.png");
	Graph.otsuki[2] = LoadGraph("�摜/���3.png");
	Graph.otsuki[3] = LoadGraph("�摜/���4.png");
	Graph.otsuki[4] = LoadGraph("�摜/���5.png");

	Graph.misato[0] = LoadGraph("�摜/����1.png");
	Graph.misato[1] = LoadGraph("�摜/����2.png");
	Graph.misato[2] = LoadGraph("�摜/����3.png");
	Graph.misato[3] = LoadGraph("�摜/����4.png");
	Graph.misato[4] = LoadGraph("�摜/����5.png");

	Graph.suzuho[0] = LoadGraph("�摜/��c1.png");
	Graph.suzuho[1] = LoadGraph("�摜/��c2.png");
	Graph.suzuho[2] = LoadGraph("�摜/��c3.png");
	Graph.suzuho[3] = LoadGraph("�摜/��c4.png");
	Graph.suzuho[4] = LoadGraph("�摜/��c5.png");

	Graph.nakano[0] = LoadGraph("�摜/����1.png");
	Graph.nakano[1] = LoadGraph("�摜/����2.png");
	Graph.nakano[2] = LoadGraph("�摜/����3.png");
	Graph.nakano[3] = LoadGraph("�摜/����4.png");
	Graph.nakano[4] = LoadGraph("�摜/����5.png");

	Graph.kana[0] = LoadGraph("�摜/����1.png");
	Graph.kana[1] = LoadGraph("�摜/����2.png");
	Graph.kana[2] = LoadGraph("�摜/����3.png");
	Graph.kana[3] = LoadGraph("�摜/����4.png");
	Graph.kana[4] = LoadGraph("�摜/����5.png");

	Graph.sarina[0] = LoadGraph("�摜/���{1.png");
	Graph.sarina[1] = LoadGraph("�摜/���{2.png");
	Graph.sarina[2] = LoadGraph("�摜/���{3.png");
	Graph.sarina[3] = LoadGraph("�摜/���{4.png");
	Graph.sarina[4] = LoadGraph("�摜/���{5.png");

	Graph.nagisa[5] = LoadGraph("�摜/��1.png");
	Graph.nagisa[6] = LoadGraph("�摜/��2.png");
	Graph.nagisa[7] = LoadGraph("�摜/��3.png");
	Graph.nagisa[8] = LoadGraph("�摜/��4.png");
	Graph.nagisa[9] = LoadGraph("�摜/��5.png");

	Graph.yuki[0] = LoadGraph("�摜/�P��1.png");
	Graph.yuki[1] = LoadGraph("�摜/�P��2.png");
	Graph.yuki[2] = LoadGraph("�摜/�P��3.png");
	Graph.yuki[3] = LoadGraph("�摜/�P��4.png");
	Graph.yuki[4] = LoadGraph("�摜/�P��5.png");

	Graph.chika[0] = LoadGraph("�摜/���R1.png");
	Graph.chika[1] = LoadGraph("�摜/���R2.png");
	Graph.chika[2] = LoadGraph("�摜/���R3.png");
	Graph.chika[3] = LoadGraph("�摜/���R4.png");
	Graph.chika[4] = LoadGraph("�摜/���R5.png");

	Graph.ibuki[0] = LoadGraph("�摜/����1.png");
	Graph.ibuki[1] = LoadGraph("�摜/����2.png");
	Graph.ibuki[2] = LoadGraph("�摜/����3.png");
	Graph.ibuki[3] = LoadGraph("�摜/����4.png");
	Graph.ibuki[4] = LoadGraph("�摜/����5.png");

	//�ȉ��k�֓���
	Graph.minami[2] = LoadGraph("�摜/�V�c3.png");
	Graph.minami[3] = LoadGraph("�摜/�V�c4.png");
	Graph.minami[4] = LoadGraph("�摜/�V�c5.png");
	Graph.minami[5] = LoadGraph("�摜/�V�c6.png");
	Graph.minami[6] = LoadGraph("�摜/�V�c7.png");

	Graph.siki[0] = LoadGraph("�摜/����1.png");
	Graph.siki[1] = LoadGraph("�摜/����2.png");

	Graph.risa[0] = LoadGraph("�摜/�I��1.png");
	Graph.risa[1] = LoadGraph("�摜/�I��2.png");
	Graph.risa[2] = LoadGraph("�摜/�I��3.png");
	Graph.risa[3] = LoadGraph("�摜/�I��4.png");
	Graph.risa[4] = LoadGraph("�摜/�I��5.png");

	Graph.minami[3] = LoadGraph("�摜/�É�1.png");
	Graph.minami[3] = LoadGraph("�摜/�É�2.png");
	
	
	Graph.wakaba[0] = LoadGraph("�摜/��t1.png");
	Graph.wakaba[1] = LoadGraph("�摜/��t2.png");
	Graph.wakaba[2] = LoadGraph("�摜/��t3.png");
	Graph.wakaba[3] = LoadGraph("�摜/��t4.png");

	Graph.arisa[0] = LoadGraph("�摜/���c1.png");
	Graph.arisa[1] = LoadGraph("�摜/���c2.png");
	Graph.arisa[2] = LoadGraph("�摜/���c3.png");
	Graph.arisa[3] = LoadGraph("�摜/���c4.png");
	Graph.arisa[4] = LoadGraph("�摜/���c5.png");

	Graph.yu[0] = LoadGraph("�摜/���c1.png");
	Graph.yu[1] = LoadGraph("�摜/���c2.png");
	Graph.yu[2] = LoadGraph("�摜/���c3.png");
	Graph.yu[3] = LoadGraph("�摜/���c4.jpg");
	Graph.yu[4] = LoadGraph("�摜/���c5.jpg");

	graph[175] = LoadGraph("�摜/�ː�1.png");
	graph[176] = LoadGraph("�摜/�ː�2.png");
	graph[177] = LoadGraph("�摜/�ː�3.png");

	graph[180] = LoadGraph("�摜/�ԏ�1.png");
	graph[181] = LoadGraph("�摜/�ԏ�2.png");
	graph[182] = LoadGraph("�摜/�ԏ�3.png");
	graph[183] = LoadGraph("�摜/�ԏ�4.png");
	graph[184] = LoadGraph("�摜/�ԏ�5.png");

	graph[185] = LoadGraph("�摜/����6.png");
	graph[186] = LoadGraph("�摜/����7.png");
	graph[187] = LoadGraph("�摜/����8.png");
	graph[188] = LoadGraph("�摜/����9.png");
	graph[189] = LoadGraph("�摜/����10.png");

	graph[190] = LoadGraph("�摜/����1.png");
	graph[191] = LoadGraph("�摜/����2.png");
	graph[192] = LoadGraph("�摜/����3.png");
	graph[193] = LoadGraph("�摜/����4.png");
	graph[194] = LoadGraph("�摜/����5.png");

	graph[200] = LoadGraph("�摜/���c1.png");
	graph[201] = LoadGraph("�摜/���c2.png");
	graph[202] = LoadGraph("�摜/���c3.png");
	graph[203] = LoadGraph("�摜/���c4.png");
	graph[204] = LoadGraph("�摜/���c5.png");
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetBackgroundColor(255, 126, 45);
	ChangeWindowMode(TRUE), SetMainWindowText("���̎q�̓����n�͂ǂ���!!!.exe"), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && UpdateKey() == 0) {
		//�f�o�b�O��
		//DrawFormatString(10, 10, GreenA, "%d", Report.stateofNO4);
		switch (state)//��
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
		move();//�L�[���상�\�b�h
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
		DrawString(160, 60 + time % 180, "���̎q�̓����n��", white);
		DrawString(220, 120 + time % 180, "�ǂ���!!!", blue);
		DrawString(200, 340, "START Enter", GreenA);
	}
	else
	{
		DrawString(50, 140, "A:���[�h���猟��", GreenA);
		
		DrawString(50, 240, "C:�V���[�Y�Ō���", GreenA);
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
		else//���j���[���
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
		case 0://���|�[�g�I�����
			if (Key[KEY_INPUT_A] == 1)//�É�������
			{
				Report.state = 1;
			}
			if (Key[KEY_INPUT_B] == 1)//�����n����
			{
				Report.state = 11;
			}
			if (Key[KEY_INPUT_C] == 1)//�쓌�k��
			{
				Report.state = 21;
			}
			if (Key[KEY_INPUT_D] == 1)//�k�֓���
			{
				Report.state = 31;
			}
			if (Key[KEY_INPUT_RETURN] == 1)
			{
				state = TITLE;
			}
			break;
		case 1://�É��������j���[
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

		case 11://�����n���҃��j���[
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

		case 21://���k�҃��j���[
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

		case 31://�k�֓��҃��j���[
			switch (Report.stateofNO4)
			{
			case 0://�V�c
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 10;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4++;
				}
				break;
			case 1://�u��
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
			case 2://�I��
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 3://��t
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_DOWN] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 4://���c
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
			case 5://���c
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
			case 6://�ː�
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
			case 7://�ԏ�
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4++;
				}
				if (Key[KEY_INPUT_RIGHT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 8://����
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
			case 9://�É�
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
			case 10://����
			case 11://�쓇
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
			case 12://��a
				if (Key[KEY_INPUT_UP] == 1)
				{
					Report.stateofNO4 = 13;
				}
				if (Key[KEY_INPUT_LEFT] == 1)
				{
					Report.stateofNO4--;
				}
				break;
			case 13://����
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
			case 14://���c
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
			case 15://�V����
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
	case 0://���|�[�g�I�����
		SetFontSize(29);
		boxcolor();
		SetBackgroundColor(255, 126, 45);
		DrawString(50, 140, "A:Vol.1(�É�������)", GreenA);
		DrawString(50, 190, "B:Vol.2(�����n����)", GreenA);
		DrawString(50, 240, "C:Vol.3(���z�E��z�E�쓌�k��)", GreenA);
		DrawString(50, 290, "D:Vol.4(�قږk�֓���)", GreenA);
		DrawString(200, 340, "Menu Enter", GreenA);
		break;
	case 1://NO1�I�����
		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawBox(0, 300, 490, 480, skyblue, true);//�C
		DrawCircle(60, 280, 15, orange, true);
		DrawCircle(260, 100, 15, orange, true);
		DrawCircle(330, 150, 15, orange, true);
		DrawCircle(400, 150, 15, orange, true);

		DrawString(0, 0, "Vol.1(�É�������)", orange);
		DrawString(0, 230, "�R��(�䂢)", orange);
		DrawString(200, 50, "�x�쌴�c", orange);
		DrawString(300, 100, "���", orange);
		DrawString(370, 100, "�_�J", orange);
		DrawString(400, 450, "Backspace�Ŗ߂�", orange);

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
				DrawString(0, 400, "���O", orange);
				DrawString(100, 400, "��ΗB", yellow);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "���C����", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�É����É��s������", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "��ΗB", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "���C����", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�É����É��s������", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "���c����", pink);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "�x��d��", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�É����x�m�s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���c����", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�x��d��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�É����x�m�s", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "�r�ؔ��", skyblue);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "�x��d��", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "�É����x�m�s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "�_�J�ޏ�", skyblue);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "�x��d��", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "�É����x�m�s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
		}
		break;
	case 11://NO2�I�����
		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawBox(0, 0, 90, 200, skyblue, true);//�ዷ�p
		DrawTriangle(0, 0, 200, 0, 90, 200, skyblue, true);//���{�C
		DrawBox(55, 250, 92, 360, skyblue, true);//���i��
		DrawBox(255, 300, 330, 480, skyblue, true);//�ɐ��p
		DrawBox(270, 380, 490, 440, skyblue, true);//�O�͘p1
		DrawBox(360, 330, 390, 440, skyblue, true);//�O�͘p2
		DrawBox(545, 385, 575, 480, skyblue, true);//�l����

		DrawCircle(40, 270, 15, orange, true);//�}�L�m
		DrawCircle(174, 180, 15, orange, true);//���
		DrawCircle(194, 364, 15, orange, true);//��
		DrawCircle(440, 315, 15, orange, true);//����
		DrawCircle(590, 277, 15, orange, true);//���v��
		DrawCircle(623, 435, 15, orange, true);//����

		DrawString(0, 0, "Vol.2(�����n����)", orange);
		DrawString(0, 290, "�}�L�m", orange);
		DrawString(162, 200, "���", orange);
		DrawString(182, 384, "��", orange);
		DrawString(416, 335, "����", orange);
		DrawString(550, 297, "���v��", orange);
		DrawString(580, 390, "����", orange);
		DrawString(10, 450, "Backspace�Ŗ߂�", orange);

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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "���_�}�L�m", skyblue);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "�ΐ���", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "���ꌧ�����s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(100, 400, "�����", yellow);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "�k���{��", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "���䌧����S��z�O��", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�����", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�k���{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "���䌧����S��z�O��", yellow);
			}
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(100, 400, "�֗T��", pink);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "�֐��{��", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�O�d���T�R�s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�֗T��", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�֐��{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�O�d���T�R�s", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "����חt", skyblue);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "���C����", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "���m������s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "����חt", skyblue);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "���C����", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "���m������s", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "���v�Ԃ܂�", pink);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(330, 400, "�ѓc��", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(330, 440, "�É����l���s�V����", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���v�Ԃ܂�", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�ѓc��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�É����l���s�V����", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(100, 400, "���쏍", yellow);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "���C����", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�É����܈�s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���쏍", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "���C����", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�É����܈�s", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
		}
		break;
	case 21://NO3�I�����
		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawTriangle(0, 390, 200, 240, 0, 240, skyblue, true);//���{�C
		DrawBox(0, 0, 200, 240, skyblue, true);//���{�C
		DrawBox(470, 200, 640, 480, skyblue, true);//�����m
		DrawBox(550, 0, 640, 200, skyblue, true);//�����m

		DrawCircle(120, 425, 15, orange, true);//�O��
		DrawCircle(20, 429, 15, orange, true);//�k��
		DrawCircle(180, 305, 15, orange, true);//���X��
		DrawCircle(219, 227, 15, orange, true);//����
		DrawCircle(220, 70, 15, orange, true);//�V��
		DrawCircle(454, 82, 15, orange, true);//�V�c
		DrawCircle(492, 139, 15, orange, true);//�̂̂���
		DrawCircle(531, 180, 15, orange, true);//��c
		DrawCircle(451, 365, 15, orange, true);//���n

		DrawString(0, 0, "Vol.3(���z�E��z�E�쓌�k��)", orange);
		DrawString(93, 385, "�O��", orange);
		DrawString(0, 390, "�k��", orange);
		DrawString(133, 325, "���X��", orange);
		DrawString(192, 247, "����", orange);
		DrawString(193, 90, "�V��", orange);
		DrawString(427, 42, "�V�c", orange);
		DrawString(437, 99, "�̂̂���", orange);
		DrawString(504, 200, "��c", orange);
		DrawString(424, 385, "���n", orange);

		DrawString(110, 450, "Backspace:�߂�", orange);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "�k�����@", skyblue);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "�M�z�{��", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�V��������s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�k�����@", skyblue);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�M�z�{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�V��������s", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "�O��݂�", pink);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "�M�z�{��", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�V���������s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�O��݂�", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�M�z�{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�V���������s", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "���X�ؐ�}", skyblue);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(320, 400, "���V��", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(320, 440, "�V�����V���c�s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���X�ؐ�}", skyblue);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "���V��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�V�����V���c�s", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(400, 0, "���O", orange);
				DrawString(400, 40, "����b", yellow);
				DrawString(400, 80, "�w�H��", orange);
				DrawString(400, 120, "�H�z�{��", yellow);
				DrawString(400, 160, "���ݒn", orange);
				DrawString(400, 200, "�V��������s", yellow);
			}
			else if (time >= 360 * 3 && time <= 360 * 4 - 1)
			{
				DrawString(0, 400, "���O", orange);
				DrawString(100, 400, "����b", yellow);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "�H�z�{��", yellow);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "�V��������s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "����b", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�H�z�{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�V��������s", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "�V��������", pink);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(320, 400, "�H�z�{��", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(320, 440, "�R�`���V����", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�V��������", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�H�z�{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�R�`���V����", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "���n�Ĕ�", yellow);
				DrawString(200, 400, "�w�H��", orange);
				DrawString(300, 400, "��֐�", skyblue);
				DrawString(200, 440, "���ݒn", orange);
				DrawString(300, 440, "���������n�s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���n�Ĕ�", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "��֐�", skyblue);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "���������n�s", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "�V�c���g", skyblue);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "���k�{��", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "�{�錧�o�Ďs", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "�X�v�۔T�X", skyblue);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(320, 400, "�C�����", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(320, 440, "�{�錧�O�J��", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�X�v�۔T�X", skyblue);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�C�����", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�{�錧�O�J��", yellow);
			}


		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(400, 0, "���O", orange);
				DrawString(400, 40, "��c������", yellow);
				DrawString(400, 80, "�w�H��", orange);
				DrawString(400, 120, "�Ί���", yellow);
				DrawString(400, 160, "���ݒn", orange);
				DrawString(400, 200, "�{�錧�Ί��s", yellow);
			}
			else
			{
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "��c������", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�Ί���", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�{�錧�Ί��s", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
		}
		break;

	case 31://NO4�I�����

		SetFontSize(25);
		SetBackgroundColor(0, 255, 0);
		DrawCircle(800, 480 / 2, 480 / 2, skyblue, true);//�����m
		DrawTriangle(640, 0, 560, 230, 640, 240, skyblue, true);//�����m
		//���
		DrawCircle(290, 445, 15, orange, true);//�V�c
		DrawCircle(160, 460, 15, orange, true);//�u��
		DrawCircle(85, 300, 15, orange, true);//���c
		DrawCircle(90, 400, 15, orange, true);//�I��
		DrawCircle(80, 370, 15, orange, true);//��t
		//�Q�n
		DrawCircle(70, 230, 15, orange, true);//���c
		DrawCircle(55, 150, 15, orange, true);//�ː�
		DrawCircle(25, 145, 15, orange, true);//�ԏ�
		DrawCircle(40, 110, 15, orange, true);//����
		//���
		DrawCircle(230, 280, 15, orange, true);//�É�
		DrawCircle(310, 225, 15, orange, true);//����
		DrawCircle(340, 225, 15, orange, true);//�쓇
		DrawCircle(415, 210, 15, orange, true);//��a
		//�Ȗ�
		DrawCircle(320, 50, 15, orange, true);//����
		DrawCircle(165, 180, 15, orange, true);//���c
		DrawCircle(206, 15, 15, orange, true);//�V����

		DrawString(270, 0, "Vol.4(�قږk�֓���)", orange);
		DrawString(270, 405, "�V�c", orange);
		DrawString(140, 420, "�u��", orange);
		DrawString(65, 260, "���c", orange);
		DrawString(70, 420, "�I��", orange);
		DrawString(60, 330, "��t", orange);

		DrawString(90, 220, "���c", orange);
		DrawString(75, 140, "�ː�", orange);
		DrawString(0, 165, "�ԏ�", orange);
		DrawString(15, 70, "����", orange);

		DrawString(205, 240, "�É�", orange);
		DrawString(285, 185, "����", orange);
		DrawString(315, 245, "�쓇", orange);
		DrawString(389, 170, "��a", orange);

		DrawString(298, 70, "����", orange);
		DrawString(140, 140, "���c", orange);
		DrawString(166, 35, "�V����", orange);

		DrawString(410, 450, "Backspace�Ŗ߂�", orange);

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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "�V�c���g", skyblue);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "�����X�J�C�c���[���C��", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "��ʌ������s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "��m���u��", pink);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "���������", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "��ʌ��u�؎s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
		}
		break;
	case 34://�I��
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
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "�I�ꗜ��", yellow);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "��z��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "��ʌ���z�s", yellow);
			}
			else
			{
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "�I�ꗜ��", yellow);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(320, 400, "��z��", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(320, 440, "��ʌ���z�s", yellow);
			}
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "��������t", pink);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "���������", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "��ʌ���ˎs", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���c������", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�����S�������{��", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "��ʌ��s�c�s", yellow);

			}
			else
			{
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "���c������", pink);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(320, 400, "�����S�������{��", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(320, 440, "��ʌ��s�c�s", yellow);
			}

		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
				DrawString(300, 0, "���O", orange);
				DrawString(300, 40, "���c�D", pink);
				DrawString(300, 80, "�w�H��", orange);
				DrawString(300, 120, "�����ɐ�����Ȃ�", yellow);
				DrawString(300, 160, "���ݒn", orange);
				DrawString(300, 200, "�Q�n�����c�s", yellow);
			}
			else
			{
				DrawString(0, 400, "���O", orange);
				DrawString(70, 400, "���c�D", pink);
				DrawString(230, 400, "�w�H��", orange);
				DrawString(320, 400, "�����ɐ�����Ȃ�", yellow);
				DrawString(230, 440, "���ݒn", orange);
				DrawString(320, 440, "�Q�n�����c�s", yellow);
			}
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "�ː�����", skyblue);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "���ѐ��Ȃ�", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "�Q�n���ː��s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
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
			DrawString(300, 0, "���O", orange);
			DrawString(300, 40, "�ԏ�݂肠", yellow);
			DrawString(300, 80, "�w�H��", orange);
			DrawString(300, 120, "�����ː����Ȃ�", yellow);
			DrawString(300, 160, "���ݒn", orange);
			DrawString(300, 200, "�Q�n���݂ǂ�s", yellow);
		}
		else
		{
			DrawString(300, 450, "Esc:�������", yellow);
		}
		break;
	case 40://����
		time++;
		break;
	case 41://�É�
		time++;
		break;
	case 42://����
		time++;
		break;
	case 43://�쓇
		time++;
		break;
	case 44://��a
		time++;
		break;
	case 45://����
		time++;
		break;
	case 46://���c
		time++;
		break;
	case 47://�V����
		time++;
		break;
	}
}
void searching() {
	switch (Search.state)
	{
	case 0://���j���[
		
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