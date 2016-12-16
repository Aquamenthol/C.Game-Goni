#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Rand �Լ��� ���� �ش�����
#include <windows.h> // ȭ�� Clear�� ���� �ش�����
#include <time.h> // Srand�� ����ϱ� ���� �ش�����
#include<conio.h> // getch�� ����ϱ� ���� �ش�����

// *************************** �÷� ����ϱ� Define �� ********************************* //

#define col GetStdHandle(STD_OUTPUT_HANDLE) // �ܼ�â�� �ڵ����� �ޱ�
#define BLACK SetConsoleTextAttribute(col, 0x0000); //������
#define GRAY SetConsoleTextAttribute(col, 0x0007); //���� ȸ��
#define RED SetConsoleTextAttribute(col,0x000c); //������
#define BLUE SetConsoleTextAttribute(col,0x0001 | 0x0008); //�Ķ���
#define HIGH SetConsoleTextAttribute(col,0x00a); // ���λ�
#define WHITE SetConsoleTextAttribute(col,0x000f); //�Ͼ��
#define SKY SetConsoleTextAttribute(col,0x000b); // �ϴû�
#define YEL SetConsoleTextAttribute(col,0x000e); // �����
#define HIG SetConsoleTextAttribute(col,0x000d); // ����
#define GOLD SetConsoleTextAttribute(col,0x0006); //  �ݻ�
#define JAJU SetConsoleTextAttribute(col,0x0005); // ���ֻ�
#define PII SetConsoleTextAttribute(col,0x0004); // �ǻ�
#define GREEN SetConsoleTextAttribute(col,0x0002); // ���
#define VIO SetConsoleTextAttribute(col,0x0001 | 0x0008 | 0x000c); // �����

// ************************* Ŀ�� ����� ��ũ�� ************************************** //
enum {HIDDEN, SHOW};

// **************************** �̷��Լ� ����Ű �ƽ�Ű�ڵ尪 *************************** //
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define Enter 13 // ���� ��
#define ESC 27



// ********************************* ó�� ���� ȭ��! *************************** //
int GameBoy(int *); // ���Ӻ��� ȭ�� 


// ************************ System �Լ� ******************************* //
void gotoxy(int ,int ); // x�� y�� �̵������ִ� �Լ�
void delay(clock_t wait); // ������ �Լ� �ð� ���ʸ� ����Ͽ���.
void color(unsigned short color); // ���� �÷��� �ֱ� ���� �Լ� 
void CursorView(char show); // Ŀ���� ����ų� �����ش�.

// ************************ ���������� �Լ� ******************************* //
void gawibawibo(int *pscore); // ���������� ���� �Լ� 

void mygawi(); // ���� ����
void mybawi(); // ���� ����
void mybo();   //  ���� ��

void comgawi(); // �� ����
void combawi(); // �� ����
void combo(); // �� ��

// ************************ �߱����� �Լ� ******************************* //
void baseball(int *);						 // Text �߱����� �����Լ�
void Num1();   // ���������� ���ڸ� ���� �Լ��� 1 ~ 9
void Num2();
void Num3();
void Num4();
void Num5();
void Num6();
void Num7();
void Num8();
void Num9();

// ************************ �̷�Ż����� �Լ� ******************************* //
void Miro(int *);			// �̷ΰ��� �����Լ�
int RpgGame();							

// ************************ ���������� �Լ� ******************************* //
void StarNum(int *);

// ************************ �����Ա� ���� �Լ� ****************************** //
void SetMap(int A[][28]);
void StarMap(int A[][28],int B[30]);
void ddang(int *);


void main()
{
	int number = 0;
	
	while(1) {
		
		static int score = 0; // ���ھ� ���� �Լ�

		number = GameBoy(&score);
		
		system("cls"); // ȭ�� ����

		switch(number) {
		case 1: gawibawibo(&score); 
			break;
		case 2: baseball(&score);
			break;
		case 3: Miro(&score);
			break;
		case 4: StarNum(&score);
			break;
		case 5: ddang(&score);
			break;

		
		}
	}
}

//************************************** �׺��� ȭ�� **************************************************//

int GameBoy(int *pscore)
{char Game[17][17] = {{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}, // ���ӱ� ��Ʋ
	{5,0,1,50,0,5},
	{5,0,0,51,0,5},
	{5,0,0,52,0,5},
	{5,0,0,53,0,5},
	{5,0,0,54,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	{5,0,0,68,2,5},
	{5,0,0,69,2},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
	{5,5,5,7,5,5,5,5,5,5,5,5,5,5,5,5,5},
	{5,5,8,6,9,5,5,5,5,5,4,5,3,5,5,5,5},
	{5,5,5,10,5,5,5,5,5,5,5,5,5,5,5,5,5},
	{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}};

	int i, j; // �ݺ������
	int randcolor = 0; // �����÷� �ֱ� ��
	int x = 1; // ȭ��ǥ�� ó�� ��ǥ
	int y = 2; // ȭ��ǥ�� ó�� ��ǥ 

	system("mode con lines=29 cols=79");
	CursorView(HIDDEN);

	for( i = 0; i < sizeof(Game) / sizeof(Game[0]); i ++)  // �ݺ���
	{
		gotoxy(20,i+7);
		for ( j = 0; j < sizeof(Game[0]); j ++)
		{
			if( Game[i][j] == 69)
			{
				printf(" ������ Score : %d �� !  ", *pscore);
			}
			else if( Game[i][j] == 68)
			{
				printf("     �� ���� ���� ��     ");
			}
			else if( Game[i][j] == 50)
			{
				printf(" 1. ���� ���� �� ���� ! ");
			}
			else if(Game[i][j] == 51)
			{
				printf(" 2. �ؽ�Ʈ �߱� ����  ! ");
			}
			else if( Game[i][j] == 52)
			{
				printf(" 3. �� Ż�� ����      ! ");
			}
			else if( Game[i][j] == 53)
			{
				printf(" 4. ���� ��� ����    ! ");
			}
			else if( Game[i][j] == 54)
			{
				printf(" 5. �� ���Ա� ����    ! ");
			}
			else if( Game[i][j] == 10)
			{
				printf("��");
			}
			else if( Game[i][j] == 9)
			{
				printf("��");
			}
			else if( Game[i][j] == 8)
			{
				printf("��");
			}
			else if( Game[i][j] == 7)
			{
				printf("��");
			}
			else if( Game[i][j] == 6)
			{
				printf("��");
			}
			else if( Game[i][j] == 5)
			{
				WHITE;
				printf("��");
				GRAY;
			}
			else if( Game[i][j] == 4)
			{
				printf("��");
			}
			else if( Game[i][j] == 3)
			{
				printf("��");
			}
			else if( Game[i][j] == 2)
			{
				printf(" ");
			}
			else if( Game[i][j] == 1)
			{
				SKY;
				printf("��");
				GRAY;
			}
			else if ( Game[i][j] == 0)
			{
				printf("  ");
			}	
		}
		printf("\n");
	}

		while(1)
		{
			gotoxy(52, 18);
			WHITE;
			printf("��");
			GRAY;

			randcolor = rand() % 6 + 1; // 1~6 ������ ���ڸ� ��

				switch(randcolor) // �����Լ����� ���� ���� �����
				{
				case 1: RED;
					break;
				case 2: BLUE;
					break;
				case 3:WHITE;
					break;
				case 4:GOLD;
					break;
				case 5: VIO;
					break;
				case 6: YEL;
					break;
				} // ����ġ ���̽� ��
				gotoxy(10, 2); 
				printf("������                   ������                       ����");
				gotoxy(10, 3);
				printf("��                       ��                     ����  ����");
				gotoxy(10, 4);
				printf("��  �� ���� ������ ��    ��  �� ����   �������� ����  ����");
				gotoxy(10,5);
				printf("������ ���� ��  �� ��    ������ ������ ��    �� ����   �� ");
				GRAY;
			

			gotoxy(52, 18);
			WHITE;
			printf("��");
			GRAY;

			for( i = 0; i < sizeof(Game) / sizeof(Game[0]); i ++)  // �ݺ���
			{	
				gotoxy(20,i+7);
				for ( j = 0; j < sizeof(Game[0]); j ++)
				{
					
					if( Game[i][j] == 69)
					{
						printf(" ������ Score : %d �� !  ", *pscore);
					}
					else if( Game[i][j] == 68)
					{
						printf("     �� ���� ���� ��     ");
					}
					else if( Game[i][j] == 50)
					{
						printf(" 1. ���� ���� �� ���� ! ");
					}
					else if(Game[i][j] == 51)
					{
						printf(" 2. �ؽ�Ʈ �߱� ����  ! ");
					}
					else if( Game[i][j] == 52)
					{
						printf(" 3. ���ڸ� ���ض�     ! ");
					}
					else if( Game[i][j] == 53)
					{
						printf(" 4. ���� ��� ����    ! ");
					}
					else if( Game[i][j] == 54)
					{
						printf(" 5. �� ���Ա� ����    ! ");
					}
					else if( Game[i][j] == 10)
					{
						printf("��");
					}
					else if( Game[i][j] == 9)
					{
						printf("��");
					}
					else if( Game[i][j] == 8)
					{
						printf("��");
					}
					else if( Game[i][j] == 7)
					{
						printf("��");
					}
					else if( Game[i][j] == 6)
					{
						printf("��");
					}
					else if( Game[i][j] == 5)
					{
						WHITE;
						printf("��");
						GRAY;
					}
					else if( Game[i][j] == 4)
					{
						printf("��");
					}
					else if( Game[i][j] == 3)
					{
						printf("��");
					}
					else if( Game[i][j] == 2)
					{
						printf(" ");
					}
					else if( Game[i][j] == 1)
					{
						SKY;
						printf("��");
						GRAY;
					}
					else if ( Game[i][j] == 0)
					{
						printf("  ");
					}			
				} // j ���� ��

				printf("\n");
			} // i ���� ��

			gotoxy(52, 18);
			WHITE;
			printf("��");
			GRAY;

			if(kbhit())
			{
			char move = 0; // ������ ���� ����
			int Number = 0; // ���� ���� ����

			move = getch();
			

			switch(move) // ���긦 �Ǵ��Ͽ� �۵� �� / �Ʒ�
			{
			case UP: if(Game[x-1][y] != 2)
					 {
						 if(Game[x-1][y] == 0) 
						 {
							 Game[x][y] = 0;
							 --x;
							  Game[x][y] = 1;
						 }
					 } // ������ ��
					 break;
					 
			case DOWN: if(Game[x+1][y] != 2)
					   {
						   if(Game[x+1][y] == 0)
						   {
							   Game[x][y] = 0;
							   ++x;
							   Game[x][y] = 1;

						   }
					   } // ������ �� 
					   break;
			case Enter: Number = x;
				break;
			} // Ư��Ű ����ġ ���̽��� ��

			if(move == Enter)
			{
				return Number;
				break;
			} // ���͸� ������ Number���� ���� �ް� ����.
				

			} // ���� Kbhit �� ����
		} // ���� �ݺ� ���Ϲ� ����
} // �����Լ� ��


void gotoxy(int x, int y) // x�� y�� �̵������ִ� �Լ�
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(unsigned short color) // ������ �÷� ��������� �Լ�
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void CursorView(char show) // Ŀ�� ����� / ���̱� 
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}


void delay(clock_t wait)
{
 //wait ms ��ŭ ��� 1000 = 1��
 clock_t goal;
 goal= wait + clock();
 while(goal > clock());
}

void gawibawibo(int *pscore)   // ���������� ���� !!
{

	int gawibawibo = 0;
	int a = 0, i, j;

	char Me[11][15] = {0}; // ���� ĭ �迭
	char Com[11][15] = {0}; // ��ǻ�� ĭ �迭
	char Main[5][5] = {{2,2,2,2,2}, // ���������� ���� ĭ �迭
	{2,1,3,2},
	{2,0,4,2},
	{2,0,5,2},
	{2,2,2,2,2}};

	int x = 1;
	int y = 1;

	int Number = 0; // ������ �������� Ȯ�� 

	char move = 0;

	// ******************** �迭 �ʱ�ȭ ************************ //
	for ( i = 0; i < sizeof(Me) / sizeof(Me[0]); i ++)
	{
		for( j = 0; j < sizeof(Me[0]); j ++)
		{
			Me[i][j] = 0;
			Com[i][j] = 0;
		}
	}




	// ************************* �� ���� �� �ο� **************************************//
	
	for( i = 0; i < sizeof(Me) / sizeof(Me[0]); i ++)
	{
		for ( j = 0; j < sizeof(Me[0]); j ++)
		{
			if ( i == 0 || i == 10 )
			{
				Me[i][j] = 2;
				Com[i][j] = 2;
			} else if ( j == 0 || j == 14)
			{
				Me[i][j] =2;
				Com[i][j] =2;
			}
		}
	}

		// *********************** �� �� ���� ************************* //
		for( i = 0; i < sizeof(Me) / sizeof(Me[0]); i ++) 
		{
			gotoxy(45, i+5);
			for ( j = 0; j < sizeof(Me[0]); j ++)
			{
				if(Me[i][j] == 0)
				{
					printf("  ");
				} else if ( Me[i][j] == 2)
				{
					WHITE;
					printf("��");
					GRAY;
				}
			}
		}

	// *********************** ��ǻ�� �� ���� *************************** //
		for( i = 0; i < sizeof(Com) / sizeof(Com[0]); i ++) 
		{
			gotoxy(45, i+17);
			for ( j = 0; j < sizeof(Com[0]); j ++)
			{
				if(Com[i][j] == 0)
				{
					printf("  ");
				} else if ( Com[i][j] == 2)
				{
					WHITE;
					printf("��");
					GRAY;
				}
			}
		}


		// *************** vs , Me, Com ��� ***************** //
	gotoxy(58, 16);
	RED;
	printf(" VS ");
	GRAY;
	
	gotoxy(40, 18);
	YEL;
	printf("Com !");
	GRAY;

	gotoxy(40, 6);
	GREEN;
	printf(" Me !");
	GRAY;
	
	srand(time(NULL)); // ������ ������ ����� ���� Srand �Լ�

	WHITE;
		gotoxy(9,0);
		printf("============================================================\n");
		gotoxy(9,1);
		printf(" ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ȯ  ��  ��  ��  ��  !!\n");
		gotoxy(9,2);
		printf("         'ESC' �� ������ ���� �˴ϴ�. ! Let's Go !            \n");
		gotoxy(9,3);
		printf("=============================================================\n");
		
	GRAY;

	

	while (1) 
	{

	gawibawibo = (rand() % 3) + 1; // �����Լ��� 3�� �������� 1�� ���� 1 ~ 3������ ������ ���� ����

	for ( i = 0; i < 5; i ++) 
	{
		gotoxy(20, i + 13);
		for ( j = 0; j < 5; j ++)
		{
			if ( Main[i][j] == 0)
			{
				printf("  ");
			}
			else if ( Main[i][j] == 1)
			{
				RED;
				printf("��");
				GRAY;
			}
			else if ( Main[i][j] == 2)
			{
				HIGH;
				printf("��");
				GRAY;
			}
			else if ( Main[i][j] == 3)
			{
				WHITE;
				printf("����");
				GRAY;
			}
			else if ( Main[i][j] == 4)
			{
				WHITE;
				printf("����");
				GRAY;
			}
			else if ( Main[i][j] == 5)
			{
				WHITE;
				printf(" �� ");
				GRAY;
			}
		}
	}


		move = getch();
		
		switch(move)
		{
		case UP: if ( Main[x-1][y] == 2 )
				 {
					 Main[x][y] = 0;
					 x = 3;
					 Main[x][y] = 1;
				 }
			else 
			{
				Main[x][y] = 0;
				--x;
				Main[x][y] = 1;
			}
			break;

		case DOWN: if ( Main[x+1][y] == 2)
				   {
					   Main[x][y] = 0;
					   x = 1;
					   Main[x][y] = 1;
				   }
			else 
			{
				Main[x][y] = 0;
				++x;
				Main[x][y] = 1;
			}
			break;
		case Enter: if( move == Enter)
					{
						Number = x;
					}
			break;
		case ESC : break;


		}// ����ġ ���̽��� ����

		// ****************** ���Ϲ� ���������� ************************* //
		if ( move == ESC )
		{
			system("cls");
			break;
		}

	// ************************ �Ǵ� If �� **************************** //
		if( Number == 1) {
			if( gawibawibo == 1 ) 
			{
				mybawi();
				combawi();
			} else if ( gawibawibo == 2) 
			{
				mybawi();
				comgawi();
				*pscore += 1;
			} else { 
				mybawi();
				combo();
				*pscore -= 1;
			}
				Number = 0;
		}
	
		

		else if ( Number == 2) {
			if( gawibawibo == 1 ) {
				mygawi();
				combawi();
				*pscore -= 1;
			} else if ( gawibawibo == 2) {
				mygawi();
				comgawi();
			} else { 
				mygawi();
				combo();
				*pscore += 1;
			}
				Number = 0;
		}
	

		else if ( Number == 3 ) {
			if( gawibawibo == 1 ) {
				mybo();
				combawi();
				*pscore += 1;
			} else if ( gawibawibo == 2) {
				mybo();
				comgawi();
				*pscore -= 1;
			} else { 
				mybo();
				combo();
			}
				Number = 0;
		}
	} // ���Ϲ� ����
} // �����Լ� ����

void mybo()
{ 
		gotoxy(47, 6);
		puts("    ������������������   ");
		gotoxy(47, 7);
		puts("    ���Ʀ��Ʀ��Ʀ��Ʀ�   ");
		gotoxy(47, 8);
		puts("    ���Ʀ��Ʀ��Ʀ��Ʀ��� ");
		gotoxy(47, 9);
		puts("�������Ʀ��Ʀ��Ʀ��Ʀ��� ");
		gotoxy(47, 10);
		puts("��  ���Ʀ��Ʀ��Ʀ��Ʀ��� ");
		gotoxy(47, 11);
		puts("�����ƢƢƢƢƢƢƢƦ��� ");
		gotoxy(47, 12);
		puts("  �����ƢƢƢƢƢƢƦ��� ");
		gotoxy(47, 13);
		puts("    �����ƢƢƢƢƦ���   ");

}
void mybawi()
{
		gotoxy(47, 6);
		puts("                         ");
		gotoxy(47, 7);
		puts("    ������������������   ");
		gotoxy(47, 8);
		puts("    ���Ʀ��Ʀ��Ʀ��Ʀ��� ");
		gotoxy(47, 9);
		puts("  ���������������������� ");
		gotoxy(47, 10);
		puts("  ���Ʀ��������ƢƢƢƦ� ");
		gotoxy(47, 11);
		puts("  �����ƢƢƢƢƢƢƦ��� ");
		gotoxy(47, 12);
		puts("    �����ƢƢƢƢƦ���   ");
		gotoxy(47, 13);
		puts("                         ");

}
void mygawi()
{
		gotoxy(47, 6);
		puts("    ����������           ");
		gotoxy(47, 7);
		puts("    ���Ʀ��Ʀ�           ");
		gotoxy(47, 8);
		puts("    ���Ʀ��Ʀ���������   ");
		gotoxy(47, 9);
		puts("  �������������Ʀ��Ʀ��� ");
		gotoxy(47, 10);
		puts("  ���Ʀ����������������� ");
		gotoxy(47, 11);
		puts("  �����ƢƢƢƢƢƢƢƦ� ");
		gotoxy(47, 12);
		puts("    �����ƢƢƢƢƢƦ��� ");
		gotoxy(47, 13);
		puts("      �����ƢƢƢƦ���   ");

}


void combo()
{ 
		gotoxy(47, 18);
		puts("    ������������������    ");
		gotoxy(47, 19);
		puts("    ���Ʀ��Ʀ��Ʀ��Ʀ�    ");
		gotoxy(47, 20);
		puts("    ���Ʀ��Ʀ��Ʀ��Ʀ���  ");
		gotoxy(47, 21);
		puts("�������Ʀ��Ʀ��Ʀ��Ʀ���  ");
		gotoxy(47, 22);
		puts("��  ���Ʀ��Ʀ��Ʀ��Ʀ���  ");
		gotoxy(47, 23);
		puts("�����ƢƢƢƢƢƢƢƦ���  ");
		gotoxy(47, 24);
		puts("  �����ƢƢƢƢƢƢƦ���  ");
		gotoxy(47, 25);
		puts("    �����ƢƢƢƢƦ���    ");

}
void combawi()
{
		gotoxy(47, 18);
		puts("                         ");
		gotoxy(47, 19);
		puts("    ������������������   ");
		gotoxy(47, 20);
		puts("    ���Ʀ��Ʀ��Ʀ��Ʀ��� ");
		gotoxy(47, 21);
		puts("  ���������������������� ");
		gotoxy(47, 22);
		puts("  ���Ʀ��������ƢƢƢƦ� ");
		gotoxy(47, 23);
		puts("  �����ƢƢƢƢƢƢƦ��� ");
		gotoxy(47, 24);
		puts("    �����ƢƢƢƢƦ���   ");
		gotoxy(47, 25);
		puts("                         ");

}
void comgawi()
{
		gotoxy(47, 18);
		puts("    ����������           ");
		gotoxy(47, 19);
		puts("    ���Ʀ��Ʀ�           ");
		gotoxy(47, 20);
		puts("    ���Ʀ��Ʀ���������   ");
		gotoxy(47, 21);
		puts("  �������������Ʀ��Ʀ��� ");
		gotoxy(47, 22);
		puts("  ���Ʀ����������������� ");
		gotoxy(47, 23);
		puts("  �����ƢƢƢƢƢƢƢƦ� ");
		gotoxy(47, 24);
		puts("    �����ƢƢƢƢƢƦ��� ");
		gotoxy(47, 25);
		puts("      �����ƢƢƢƦ���   ");

}



// ********************************** �߱����� ���� ! *********************************** //
void baseball(int *pscore)
{
	char Pan[9][30] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,3,0,51,2,5,10,2,5,11,2,5,12,2,5,13,2,5,14,2,5,15,2},
	{2,0,4,4,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,50,0,3,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},	
	{2,20,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2},
	{2,21,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2},
	{2,22,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}}; // ������ �迭

	char Join[2][11] = {{2,1,0,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2,2}}; // ����Ű �̵��� ���� �迭

	int st[2] = {0}; // ��Ʈ����ũ �� ���� üũ

	int Number = 0; // ������ ���ð��� �ޱ����� ����
	static int i,j; // �ݺ������
	int ComNum[3] = {0}; // ������ ���� ������ �迭
	int randcolor = 0; // ���� �÷��� ���� ����
	int kount = 0; // ����ġ ���̽��� ���ѹ溹 ���� ����
	int count = 0; // ������ ���� ���� Ȯ��
	int compare = 0; // �ǵ� ī��Ʈ ����
	int k = 0; // �� ��Ʈ���� ���� üũ
	
	char move = 0; // ������ ���� ����
	
	int x = 1;
	int y = 0;

	srand((unsigned)time(NULL)); // �����Լ��� �������� �ٲٱ� ���� Srand

	for(;;) {  // 1~9�� �ڸ��� ����� ���� �ݺ���
		for(i = 0; i < 3; i++) {
			ComNum[i] = rand() % 9 + 1;
		}
		if ( ComNum[0] != ComNum[1] && ComNum[0] != ComNum[2] && ComNum[1] != ComNum[2]) {
			break;
		} // j ���� ����
	} // i ���� ����



	system("mode con lines=25 cols=100"); // CMD â ũ�� ����
	gotoxy(19,0);
	WHITE;
	printf(" �߱� ���ӿ� ���� ������ ȯ�� �մϴ�.! �� �׷� ���� �մϴ�. ! ");
	gotoxy(19, 1);
	printf("            'ESC'�� ������ ������ ���� �˴ϴ�.!                ");
	GRAY;

	Num1();
	Num2();
	Num3();
	Num4();
	Num5();
	Num6();
	Num7();
	Num8();
	Num9();

	while(1)
	{
	
		// **************************** ������ ���� ************************************** //
	for ( i = 0; i < sizeof(Pan) / sizeof(Pan[0]); i++) 
	{
		gotoxy(19,i + 2);
		for( j = 0; j < sizeof(Pan[0]); j++)
			{
				if ( Pan[i][j] == 0 )
				{
					printf("  ");
				}
				else if ( Pan[i][j] == 2 )
				{
					randcolor = rand() % 5 + 1;
					switch(randcolor)
					{
					case 1: RED;
						break;
					case 2: BLUE;
						break;
					case 3: WHITE;
						break;
					case 4: YEL;
						break;
					case 5: VIO;
						break;
					}
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 3 )
				{
					randcolor = rand() % 5 + 1;
					switch(randcolor)
					{
					case 1: RED;
						break;
					case 2: BLUE;
						break;
					case 3: WHITE;
						break;
					case 4: YEL;
						break;
					case 5: VIO;
						break;
					}
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 4 )
				{
					randcolor = rand() % 5 + 1;
					switch(randcolor)
					{
					case 1: RED;
						break;
					case 2: BLUE;
						break;
					case 3: WHITE;
						break;
					case 4: YEL;
						break;
					case 5: VIO;
						break;
					}
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 5 )
				{
					printf(" ");
				}
				else if ( Pan[i][j] == 10 )
				{
					WHITE;
					printf("1ȸ  ");
					GRAY;
				}
				else if ( Pan[i][j] == 11 )
				{
					WHITE;
					printf("2ȸ  ");
					GRAY;
				}
				else if ( Pan[i][j] == 12 )
				{
					WHITE;
					printf("3ȸ  ");
					GRAY;
				}
				else if ( Pan[i][j] == 13 )
				{
					WHITE;
					printf("4ȸ  ");
					GRAY;
				}
				else if ( Pan[i][j] == 14 )
				{
					WHITE;
					printf("5ȸ  ");
					GRAY;
				}
				else if ( Pan[i][j] == 15 )
				{
					WHITE;
					printf("6ȸ  ");
					GRAY;
				}
				else if ( Pan[i][j] == 20 )
				{
					RED;
					printf("��trike ");
					GRAY;
				}
				else if ( Pan[i][j] == 21 )
				{
					SKY;
					printf("��all ");
					GRAY;
				}
				else if ( Pan[i][j] == 22 )
				{
					VIO;
					printf("��ut  ");
					GRAY;
				}
				else if ( Pan[i][j] == 50 )
				{
					GOLD;
					printf("�ɼ�");
					GRAY;
				}
				else if( Pan[i][j] == 51 )
				{
					GOLD;
					printf("��ȸ");
					GRAY;
				}
				else if( Pan[i][j] == 101)
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 102 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 103 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 104 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 105 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 106 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 107 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 108 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
				else if ( Pan[i][j] == 109 )
				{
					WHITE;
					printf("��");
					GRAY;
				}
		} // j ���� ����
	} // i ���� ����
	// ************************************* ������ �� ************************************************** //

	// ************************************* ����ǥ ���� *********************************************** //

	for ( i = 0; i < sizeof(Join) / sizeof(Join[0]); i++)
	{
		gotoxy(20, i + 22);
		for( j = 0; j < sizeof(Join[0]); j ++)
		{
			if ( Join[i][j] == 0 )
			{
				printf("       ");
			}
			else if( Join[i][j] == 1 )
			{
				randcolor = rand() % 5 + 1;

					switch(randcolor)
					{
					case 1: RED;
						break;
					case 2: BLUE;
						break;
					case 3: WHITE;
						break;
					case 4: YEL;
						break;
					case 5: VIO;
						break;
					}
					printf("��");
					GRAY;
			} // ������ ����
		} // j ���� ����
	} // i ���� ����


	// ********************************************* ����ǥ ���� ***************************************** //



	// ********************************************* ����ǥ �����̴� ���� ���� ******************************************** //
	if(kbhit())
	{
		move = getch();

		switch(move)
		{
		case LEFT:if(Join[y][x-1] == 2)
				  {
					  Join[y][x] = 0;
					  x = 9;
					  Join[y][x] = 1;
				  }
				  else 
				  {
					  Join[y][x] = 0;
					  x -= 1;
					  Join[y][x] = 1;
				  }
				  break;
		case RIGHT:if ( Join[y][x+1] == 2 )
				   {
					   Join[y][x] = 0;
					   x = 1;
					   Join[y][x] = 1;
				   }
				   else
				   {
					   Join[y][x] = 0;
					   x += 1;
					   Join[y][x] = 1;
				   }
				   break;
		case Enter: Number = x;
			count++;
			kount = count;
			compare = count;
			break;
		case ESC: break;
		} // ����ġ ���̽��� ����
	} // Kbhit �� ����

	// ****************************************************** ����ǥ �����̴� ���� ���� ************************************************* //

	// ****************************************************** ������ ���� ����ϱ� ���� ********************************************* //

	if ( move == ESC)
	{
		break;
	}

	switch(kount)
	{
	case 1: Number += 100;
		Pan[3][count + 4] = Number;
		kount = 0;
		Number = 0;
		break;
	case 2: Number += 100;
		Pan[3][count + 4] = Number;
		kount = 0;
		Number = 0;
		break;
	case 3: Number += 100;
		Pan[3][count + 4] = Number;
		kount = 0;
		Number = 0;
		break;
	case 4: Number += 100;
		Pan[3][count + 5] = Number;
		kount = 0;
		Number = 0;
		break;
	case 5: Number += 100;
		Pan[3][count + 5] = Number;
		kount = 0;
		Number = 0;
		break;
	case 6: Number += 100;
		Pan[3][count + 5] = Number;
		kount = 0;
		Number = 0;
		break;
	case 7: Number += 100;
		Pan[3][count + 6] = Number;
		kount = 0;
		Number = 0;
		break;
	case 8: Number += 100;
		Pan[3][count + 6] = Number;
		kount = 0;
		Number = 0;
		break;
	case 9: Number += 100;
		Pan[3][count + 6] = Number;
		kount = 0;
		Number = 0;
		break;
	case 10: Number += 100;
		Pan[3][count + 7] = Number;
		kount = 0;
		Number = 0;
		break;
	case 11: Number += 100;
		Pan[3][count + 7] = Number;
		kount = 0;
		Number = 0;
		break;
	case 12: Number += 100;
		Pan[3][count + 7] = Number;
		kount = 0;
		Number = 0;
		break;
	case 13: Number += 100;
		Pan[3][count + 8] = Number;
		kount = 0;
		Number = 0;
		break;
	case 14: Number += 100;
		Pan[3][count + 8] = Number;
		kount = 0;
		Number = 0;
		break;
	case 15: Number += 100;
		Pan[3][count + 8] = Number;
		kount = 0;
		Number = 0;
		break;
	case 16: Number += 100;
		Pan[3][count + 9] = Number;
		kount = 0;
		Number = 0;
		break;
	case 17: Number += 100;
		Pan[3][count + 9] = Number;
		kount = 0;
		Number = 0;
		break;
	case 18: Number += 100;
		Pan[3][count + 9] = Number;
		kount = 0;
		Number = 0;
		break;

	} // ����ġ���̽� ����

	// ********************************************************* ������ ��� ���� ********************************************** //

	// *************************************************** �ǵ� ���� ************************************************** //
	switch(compare)
	{
	case 3:
	for ( i = 0; i < 3; i++ )
	{
		if( ComNum[i] == (Pan[3][i+5] - 100) )
		{
			st[0]++;
		}
		for ( j = 0; j < 3; j++ )
		{
			if ( ComNum[i] == (Pan[3][j+5]-100) )
			{
				st[1]++;
			}
		} // j ���� ����
	} // i ���� ����
	st[1] -= st[0];
	
	if ( st[0] != 0 )
	{
		Pan[5][4] = ( st[0] + 100 );
	}
	if ( st[1] != 0 )
	{
		Pan[6][5] = ( st[1] + 100 );
	}
	if ( 103 - ( st[0] + st[1] ) != 100 )
	{
		Pan[7][5] = ( 103 - (st[0] + st[1]) );
	}

	if ( st[0] == 3 )
	{
		break;
	}

	compare = 0;
	st[0] = 0;
	st[1] = 0;
	break;

	case 6:
		for ( i = 0; i < 3; i++ )
	{
		if( ComNum[i] == (Pan[3][i+9] - 100) )
		{
			st[0]++;
		}
		for ( j = 0; j < 3; j++ )
		{
			if ( ComNum[i] == (Pan[3][j+9]-100) )
			{
				st[1]++;
			}
		} // j ���� ����
	} // i ���� ����
	st[1] -= st[0];
	
	if ( st[0] != 0 )
	{
		Pan[5][8] = ( st[0] + 100 );
	}
	if ( st[1] != 0 )
	{
		Pan[6][9] = ( st[1] + 100 );
	}
	if ( 103 - ( st[0] + st[1] ) != 100 )
	{
		Pan[7][9] = ( 103 - (st[0] + st[1]) );
	}

	if ( st[0] == 3 )
	{
		break;
	}

	compare = 0;
	st[0] = 0;
	st[1] = 0;
	break;

	case 9:
		for ( i = 0; i < 3; i++ )
	{
		if( ComNum[i] == (Pan[3][i+13] - 100) )
		{
			st[0]++;
		}
		for ( j = 0; j < 3; j++ )
		{
			if ( ComNum[i] == (Pan[3][j+13]-100) )
			{
				st[1]++;
			}
		} // j ���� ����
	} // i ���� ����
	st[1] -= st[0];
	
	if ( st[0] != 0 )
	{
		Pan[5][12] = ( st[0] + 100 );
	}
	if ( st[1] != 0 )
	{
		Pan[6][13] = ( st[1] + 100 );
	}
	if ( 103 - ( st[0] + st[1] ) != 100 )
	{
		Pan[7][13] = ( 103 - (st[0] + st[1]) );
	}

	if ( st[0] == 3 )
	{
		break;
	}

	compare = 0;
	st[0] = 0;
	st[1] = 0;
	break;

	case 12:
		for ( i = 0; i < 3; i++ )
	{
		if( ComNum[i] == (Pan[3][i+17] - 100) )
		{
			st[0]++;
		}
		for ( j = 0; j < 3; j++ )
		{
			if ( ComNum[i] == (Pan[3][j+17]-100) )
			{
				st[1]++;
			}
		} // j ���� ����
	} // i ���� ����
	st[1] -= st[0];
	
	if ( st[0] != 0 )
	{
		Pan[5][16] = ( st[0] + 100 );
	}
	if ( st[1] != 0 )
	{
		Pan[6][17] = ( st[1] + 100 );
	}
	if ( 103 - ( st[0] + st[1] ) != 100 )
	{
		Pan[7][17] = ( 103 - (st[0] + st[1]) );
	}

	if ( st[0] == 3 )
	{
		break;
	}

	compare = 0;
	st[0] = 0;
	st[1] = 0;
	break;

	case 15:
		for ( i = 0; i < 3; i++ )
	{
		if( ComNum[i] == (Pan[3][i+21] - 100) )
		{
			st[0]++;
		}
		for ( j = 0; j < 3; j++ )
		{
			if ( ComNum[i] == (Pan[3][j+21]-100) )
			{
				st[1]++;
			}
		} // j ���� ����
	} // i ���� ����
	st[1] -= st[0];
	
	if ( st[0] != 0 )
	{
		Pan[5][20] = ( st[0] + 100 );
	}
	if ( st[1] != 0 )
	{
		Pan[6][21] = ( st[1] + 100 );
	}
	if ( 103 - ( st[0] + st[1] ) != 100 )
	{
		Pan[7][21] = ( 103 - (st[0] + st[1]) );
	}

	if ( st[0] == 3 )
	{
		break;
	}

	compare = 0;
	st[0] = 0;
	st[1] = 0;
	break;

	case 18:
		for ( i = 0; i < 3; i++ )
	{
		if( ComNum[i] == (Pan[3][i+25] - 100) )
		{
			st[0]++;
		}
		for ( j = 0; j < 3; j++ )
		{
			if ( ComNum[i] == (Pan[3][j+25]-100) )
			{
				st[1]++;
			}
		} // j ���� ����
	} // i ���� ����
	st[1] -= st[0];
	
	if ( st[0] != 0 )
	{
		Pan[5][24] = ( st[0] + 100 );
	}
	if ( st[1] != 0 )
	{
		Pan[6][25] = ( st[1] + 100 );
	}
	if ( 103 - ( st[0] + st[1] ) != 100 )
	{
		Pan[7][25] = ( 103 - (st[0] + st[1]) );
	}

	if ( st[0] == 3 )
	{
		break;
	}
	else
	{
		st[0] = 4;
		break;
	}



	compare = 0;
	st[0] = 0;
	st[1] = 0;
	break;
	} // ����ġ ���̽� ����

	if ( st[0] == 3)
	{
		break;
	}
	else if ( st[0] == 4)
	{
		break;
	}

	} // ���Ϲ� ���� 

	// ********************************** Ŭ���� �� ������ ȭ�� ���� **************************************** //
	
	if ( st[0] == 3 )
	{
		
		system("cls");
		srand((unsigned)time(NULL));

		while(k < 1000)
		{
			gotoxy((rand() % 49) * 2, rand() % 25);
			color(rand() % 14 + 2);
			printf("��");
			 Sleep(1);
			 k++;
		} // While �� ����
		GRAY;
		k = 0;
		system("cls");

		gotoxy(25, 12);
		WHITE;
		printf(" �����մϴ� ! ������ ���߼̽��ϴ�.! ");
		gotoxy(25, 14);
		printf("     ������ ! %d%d%d �Դϴ�. ", ComNum[0], ComNum[1], ComNum[2]);
		GRAY;
		Sleep(2000);
		
	} // if�� ����

	else if ( st[0] == 4)
	{
		system("cls");
		srand((unsigned)time(NULL));

		while(k < 1000)
		{
			gotoxy((rand() % 49) * 2, rand() % 25);
			color(rand() % 14 + 2);
			randcolor = rand() % 2 + 1;
			if ( randcolor == 1)
			{
			printf("��");
			}
			else 
			{
			printf("��");
			}
			 Sleep(1);
			 k++;
		} // While �� ����
		GRAY;
		k = 0;
		system("cls");

		gotoxy(25, 12);
		WHITE;
		printf(" Ʋ�Ⱦ��... ���� �Ͻ��� ^^; �Ӹ��� ���ڽŰ� ����; ");
		gotoxy(25, 14);
		printf("           ������ ! %d%d%d ���µ�... ", ComNum[0], ComNum[1], ComNum[2]);
		GRAY;
		Sleep(2000);
	} // else �� ���� 

	// ************************************ Ŭ���� �� ������ ȭ�� ���� ************************************** //

} // �����Լ� ����	

	// ************************************ �߱����� ���� �ѹ� 1 ~ 9 ���� ************************************ //

void Num1()
{
	WHITE;
	gotoxy(18, 16);
	puts("���  ");
	gotoxy(18, 17);
	puts("  ��  ");
	gotoxy(18, 18);
	puts("  ��  ");
	gotoxy(18, 19);
	puts("  ��  ");
	gotoxy(18, 20);
	puts("����");
	gotoxy(18, 21);
	VIO;
	puts("  ��  ");
	GRAY;
}
void Num2()
{
	WHITE;
	gotoxy(25, 16);
	puts("����");
	gotoxy(25, 17);
	puts("    ��");
	gotoxy(25, 18);
	puts("����");
	gotoxy(25, 19);
	puts("��    ");
	gotoxy(25, 20);
	puts("����");
	gotoxy(25, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num3()
{
	WHITE;
	gotoxy(32, 16);
	puts("����");
	gotoxy(32, 17);
	puts("    ��");
	gotoxy(32, 18);
	puts("����");
	gotoxy(32, 19);
	puts("    ��");
	gotoxy(32, 20);
	puts("����");
	gotoxy(32, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num4()
{
	WHITE;
	gotoxy(39, 16);
	puts("��  ��");
	gotoxy(39, 17);
	puts("��  ��");
	gotoxy(39, 18);
	puts("����");
	gotoxy(39, 19);
	puts("    ��");
	gotoxy(39, 20);
	puts("    ��");
	gotoxy(39, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num5()
{
	WHITE;
	gotoxy(46, 16);
	puts("����");
	gotoxy(46, 17);
	puts("��    ");
	gotoxy(46, 18);
	puts("����");
	gotoxy(46, 19);
	puts("    ��");
	gotoxy(46, 20);
	puts("����");
	gotoxy(46, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num6()
{
	WHITE;
	gotoxy(53, 16);
	puts("����");
	gotoxy(53, 17);
	puts("��    ");
	gotoxy(53, 18);
	puts("����");
	gotoxy(53, 19);
	puts("��  ��");
	gotoxy(53, 20);
	puts("����");
	gotoxy(53, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num7()
{
	WHITE;
	gotoxy(60, 16);
	puts("����");
	gotoxy(60, 17);
	puts("��  ��");
	gotoxy(60, 18);
	puts("    ��");
	gotoxy(60, 19);
	puts("    ��");
	gotoxy(60, 20);
	puts("    ��");
	gotoxy(60, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num8()
{
	WHITE;
	gotoxy(67, 16);
	puts("����");
	gotoxy(67, 17);
	puts("��  ��");
	gotoxy(67, 18);
	puts("����");
	gotoxy(67, 19);
	puts("��  ��");
	gotoxy(67, 20);
	puts("����");
	gotoxy(67, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}
void Num9()
{
	WHITE;
	gotoxy(74, 16);
	puts("����");
	gotoxy(74, 17);
	puts("��  ��");
	gotoxy(74, 18);
	puts("����");
	gotoxy(74, 19);
	puts("    ��");
	gotoxy(74, 20);
	puts("����");
	gotoxy(74, 21);
	VIO;
	puts("  ��  ");
	GRAY;

}


// ********************************** ���ڸ� ���ض� ���� ! ********************************* //

void Miro(int *pscore)
{
	int n;
	n = RpgGame();

}

int RpgGame()
{
	int RpgGame();

	struct RPG {
	int x, y;
	int PlayN;
};
	struct RPG Me, Mon[20], Pre[10];
	static int Stage = 1, PreNum;
	static int i,j,k = 0, T = 0 , b, c[20][2] = {0}, d[30] = {0};
	static int Screen[18][28] ={0};
	int RandNum[2] = {0};
	char ch;
	int Life = 3, LifeN, GameOver = 0;

		srand(time(NULL));

    system("mode con lines=20 cols=58");// â ũ�� line = y��, cols = x��, line�� -1 ũ�� ���
	system("cls");
	CursorView(HIDDEN);
			system("cls");

	while(1)
	{
		RandNum[0] = 0;
		RandNum[1] = 0;

		gotoxy(22,9);
	printf("S t a g e  %d",Stage);
	Sleep(3000);
	system("cls");

	b = rand() % 14 + 2;

	for(i = 0; i < Stage * 2; i++)
	{
	c[i][0] = rand() % 14 + 2;
	c[i][1] = rand() % 22 + 3;
	}
	for(i = 0; i < 35; i++)
	{
		d[i] = rand() % 26 + 1;
	}

	Me.x = 7;
	Me.y = 1;
	Me.PlayN = 1;

	for(i = 0; i < Stage * 2; i++)
	{
	Mon[i].x = c[i][0];
	Mon[i].y = c[i][1];
	Mon[i].PlayN = 10;
	}

	for(i = 0; i < Stage;i++)
	{
		Pre[i].x = c[i][0];
		Pre[i].y = c[i][1] + 1;
		Pre[i].PlayN = 7;
	}


	for(i = 0; i < 18;i++) // �ʱ�ȭ
		{
			for(j = 0; j < 28;j++)
			{
				Screen[i][j] = 0;
			}
		}

		k = 0;
		for(i = 0; i < 18; i++) // �� ����
	   {
		   for(j = 0;j<28;j++)
		   {
			   if(i == 0 || i == 17)
			   {
				   Screen[i][j] = 9;
			   }else if(j == 0 || j == 27)
			   {
				   Screen[i][j] = 9;
			   }
		   }
	   }
		for(i = 1; i < 18; i++)
		{
			for(j = 0; j < 28; j++)
			{	
				if(d[k] == j)
				{
					Screen[i][j] = 9;
					k++;
				}
			}
		}
		Screen[b][26] = 0;	
		Screen[b][27] = 0;	
		Screen[7][1] = 1; // �ʱ�ȭ	
		Screen[6][1] = 0;
	
		for(i = 0; i < Stage * 2; i++)
		{
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
		}
		for(i = 0; i < Stage; i++)
		{
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN;
		}

	while(1)
	{
		PreNum = 0;

		for(i = 0; i < Stage * 2;i++)
		{
		RandNum[0] = rand() % 15;
		if(RandNum[0] == 0)
		{
					RandNum[1] = rand() % 4;
			switch(RandNum[1])
		   {
		   case 0 :
			   if(Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN
				   && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN)
			   {	
				   Screen[Mon[i].x][Mon[i].y] = 0;
				   Mon[i].y -= 1;
				   if(Screen[Mon[i].x][Mon[i].y] == Me.PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
			   break; // ����
		   case 1 :
			   if(Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN
				   && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN)
			   {
				   Screen[Mon[i].x][Mon[i].y] = 0;
				   Mon[i].y += 1;
				   if(Screen[Mon[i].x][Mon[i].y] == Me.PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
			   break; // ������
		   case 2 :
			   if(Screen[Mon[i].x - 1][Mon[i].y] != 9 && Screen[Mon[i].x - 1][Mon[i].y] != Mon[i].PlayN
				   && Screen[Mon[i].x - 1][Mon[i].y] != Pre[0].PlayN)
			   {
				   Screen[Mon[i].x][Mon[i].y] = 0;
				   Mon[i].x -= 1;
				   if(Screen[Mon[i].x][Mon[i].y] == Me.PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
			   break; // ����
		   case 3 :
			   if(Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN
				   && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN)
			   {
				   Screen[Mon[i].x][Mon[i].y] = 0;
				   Mon[i].x += 1;
				   if(Screen[Mon[i].x][Mon[i].y] == Me.PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
			   break; // �Ʒ���
			}//s1witch ��
		}//if ��
		}//Mon ��ġ, for ��

		for(i = 0; i < 18; i++) // ���� ���
	   {
		   gotoxy(1,i+1);
		   for(j = 0; j < 28; j++)
		   {
			   if(Screen[i][j] == 0)
			   {
				   BLACK;
				   printf("��");
			   }else if(Screen[i][j] == Me.PlayN)
			   {
				   RED;
				   printf("��");
			   }else if(Screen[i][j] == 9)
			   {
			   WHITE;
			   printf("��");
			   }else if(Screen[i][j] == Mon[0].PlayN)
			   {
				   VIO;
				   printf("��");
			   }else if(Screen[i][j] == Pre[0].PlayN)
			   {
				   YEL;
				   printf("��");
			   }//if ��
		   }// j for ��	  
		   printf("\n");
		}//i for ��
		   
	if(kbhit())	
	{
	ch = getch();
		   switch(ch)
		   {
		   case 75 :
			   if(Screen[Me.x][Me.y - 1] != 9)
			   {	
				   Screen[Me.x][Me.y] = 0;
				   Me.y -= 1;
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;
			   break; // ����
		   case 77 :
			   if(Screen[Me.x][Me.y + 1] != 9)
			   {
				   Screen[Me.x][Me.y] = 0;
				   Me.y += 1;
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;
			   break; // ������
		   case 72 :
			   if(Screen[Me.x - 1][Me.y] != 9)
			   {
				   Screen[Me.x][Me.y] = 0;
				   Me.x -= 1;
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;
			   break; // ����
		   case 80 :
			   if(Screen[Me.x + 1][Me.y] != 9)
			   {
				   Screen[Me.x][Me.y] = 0;
				   Me.x += 1;
				   if(Screen[Me.x][Me.y] == Mon[0].PlayN)
				   {
					   Me.PlayN = 99;
				   }
			   }
			   Screen[Me.x][Me.y] = Me.PlayN;
			   break; // �Ʒ���
		   case ESC: break;
		   }// switch ��
	}// if ��

	if ( ch == ESC )
	{
		break;
	}

	LifeN = Life;
	if(Me.PlayN == 99)
	{
		Life -= 1;
		break;
	}
	for(i = 0;i < 18;i++)
	{
		for(j = 0; j < 28;j++)
		{
			if(Screen[i][j] == Pre[0].PlayN)
			{
				PreNum++;
			}
		}
	}//for�� ��
	
	
	if(PreNum == 0)
	{
	if(Me.y == 27)
	{
		break;
	}
	}
	}//while2 ��

	if ( ch == ESC )
	{
		break;
	}

	if(Life != 0 && Stage != 11)
	{
		if(LifeN == Life)
		{
	Stage += 1;
	system("cls");
	gotoxy(16, 9);
	printf("S t a g e   C l e a r !!");
	Sleep(3000);
	system("cls");
		}else
		{
			gotoxy(19, 10);
			printf("G a M e  o V e R ! !");
			Sleep(3000);
			system("cls");
			gotoxy(22, 9);
			RED;
			printf("��");
			gotoxy(26, 9);
			WHITE;
			printf(" =   %d", Life);
			Sleep(3000);
			system("cls");
		GRAY;
		}	
	}

	if(Life == 0)
	{
		gotoxy(19, 9);
		printf("G a M e  o V e R ! !");
		Sleep(3000);
		system("cls");
		break;
	}
	else if (Stage == 11)
	{
		system("cls");
		WHITE;
		gotoxy(14, 9);
		printf(" C o n G r a t U L a T i o n " );
		Sleep(3000);
		system("cls");
		gotoxy(19, 9);
		printf("G a M e  o V e R ! !");
		Sleep(4000);
		GRAY;
		break;
	}// if ����\



	}//while1 ��
	return 0;
}

// **************************************** ���� ������ ���� ***************************************** //


void StarNum(int *pscore)
{

    int Screen[11][21] = {0}, Ran[30] = {0};
	int RandNum, i, j, StarPosition;
	int Inp, GameT = 0;
	char ch;
	int start, end;

	system("mode con lines=13 cols=52");

	srand(time(NULL));
	Sleep(500);
	gotoxy(15, 5);
	printf("���� �ð� 5��!!!");
	Sleep(1000);


	while(GameT < 3)
	{
		RandNum = rand() % 10 + 10;
		StarPosition = 0;
		fflush(stdin);

		for(i = 0; i < 11;i++) // �ʱ�ȭ
		{
			for(j = 0; j < 21;j++)
			{
				Screen[i][j] = 0;
			}
		}
		for(i = 0; i < 30;i++)
		{
			Ran[i] = 0;
		}

		for(i = 0; i < RandNum;i++)
		{
			Ran[i] = rand() % 18 + 1;
		}

	   system("cls"); 

	   for(i = 0; i < 11; i++) // �� ����
	   {
		   for(j = 0;j<21;j++)
		   {
			   if(i == 0 || i == 10)
			   {
				   Screen[i][j] = 2;
			   }else if(j == 0 || j == 20)
			   {
				   Screen[i][j] = 2;
			   }
		   }
	   }

	   for(i = 1; i < 10; i++) // �� ��ġ ����
	   {
		   for(j = 1; j < 20; j++)
		   {
			   
			   if(j == Ran[StarPosition])
			   {
				   Screen[i][j] = 1;
				   StarPosition++;
			   }
		   }
	   }

	   for(i = 0;i < 11; i++) // ���
	   {
		   gotoxy(5, i + 1);
		   for(j = 0; j < 21; j++)
		   {
			   if(Screen[i][j] == 0)
			   {
				   BLACK;
				   printf("��");
			   }else if(Screen[i][j] == 1)
			   {
			      switch(rand() % 12)
				   {
				   case 0 : RED;
					   break;
				   case 1 : BLUE;
					   break;
				   case 2 : HIGH;
					   break;
				   case 3 : WHITE;
					   break;
				   case 4 : SKY;
					   break;
				   case 5 : YEL;
					   break;
				   case 6 : HIG;
					   break;
				   case 7 : GOLD;
					   break;
				   case 8 : JAJU;
					   break;
				   case 9 : PII;
					   break;
				   case 10 : GREEN;
					   break;
				   default : VIO;
				  }
				   printf("��");
			   }
			   else if(Screen[i][j] == 2)
			   {
				   WHITE;
				   printf("��");
			   }
		   }
		   printf("\n");
	   }

   Sleep(2500); // ���������� �ʹ����� �����Ⱥ��̴� �Ϻη� ������ ���ɾ��ݴϴ�.
   printf("\n");

   system("cls");
   GRAY;
   start = clock();
   gotoxy(3, 5);
   printf(" ��� ���� ���� ������ � �ϱ�� ^^? : ");
   scanf("%d",&Inp);
   end = clock();
   system("cls");

   if(end - start >= 5000)
   {
	   gotoxy(15, 5);
	   printf("������ Ǯ���� T^T \n");
	   *pscore -= 1;
   }else if(Inp == RandNum) {
	   gotoxy(5, 5);
	   printf("��� ��û���� ���� ���� �̽ô� ! '-' \n");
	   *pscore += 1;
   }else {
	   gotoxy(6, 5);
	   printf("�Ѹ��� �Ҳ���. Ǳ ��. . . . . . . . \n");
	   *pscore -= 1;
   }
   Sleep(1500);
   GameT++;
   while(GameT == 5)
   {
	   system("cls");
	   getchar();
	   gotoxy(20, 13);
	   printf("�� �ϽǷ��� ? (Y/N) ");
	   scanf("%c",&ch);
	   if(ch == 'y' || ch == 'Y')
	   {
		   GameT = 0;
	   }else if(ch == 'n' || ch == 'N')
	   {
		   system("cls");
		   break;
	   }else
	   {
		   printf("�峭ġ������.");
	   }
   }
		
	}
	system("cls");
}



// **************************************** �����Ա� ���� ���� ********************************************* //
void SetMap(int A[][28])
{
	int i, j;
	for(i = 0; i < 18;i++) // �ʱ�ȭ
		{
			for(j = 0; j < 28;j++)
			{
				A[i][j] = 0;
			}
		}

	A[1][1] = 3;
	A[16][26] = 1;
	A[1][26] = 5;
	A[16][1] = 7;
}
void StarMap(int A[][28],int B[30])
{
	int i, j, k = 0;
		
	for(i = 0; i < 18; i++) // �� ����
	   {
		   for(j = 0;j<28;j++)
		   {
			   if(i == 0 || i == 17)
			   {
				   A[i][j] = 9;
			   }else if(j == 0 || j == 27)
			   {
				   A[i][j] = 9;
			   }
		   }
	   }

	for(i = 1; i < 18; i++)
	{
		for(j = 0; j < 28; j++)
		{	
			if(B[k] == j)
			{
				A[i][j] = 9;
				k++;
			}
		}
	}
}

void ddang(int *pscore)
{

	struct Player {
	int x, y;
	int playN;
	int Num;
};
    int Screen[18][28] = {0};
	int Num = 0, i, j, Score = 0;
	int RandNum = 0, RandN[30] = {0}, GameT = 0;
	int start, end, Count[4] = {0};
	char ch, ny;
	struct Player Me, Com, Cpu, Npc;

	system("mode con lines=21 cols=68");
	
	srand(time(NULL));

	while(1)
	{
			system("cls");
		SetMap(Screen);
	start = clock();
	end = clock();

		for(i = 0; i < 30;i++)
	{
		RandN[i] = rand() % 28;
	}

		Me.playN = 1;
	Me.x = 16;
	Me.y = 26;
	Me.Num = 2;
	Com.playN = 3;
	Com.x = 1;
	Com.y = 1;
	Com.Num = 4;
	Cpu.playN = 5;
	Cpu.x = 1;
	Cpu.y = 26;
	Cpu.Num = 6;
	Npc.playN = 7;
	Npc.x = 16;
	Npc.y = 1;
	Npc.Num = 8;

	while(end - start < 15000){

		Count[0] = 0;
		Count[1] = 0;
		Count[2] = 0;
		Count[3] = 0;

		StarMap(Screen,RandN);

			RandNum = rand() % 4;
			switch(RandNum)
		   {
		   case 0 :
			   if(Screen[Com.x][Com.y - 1] != 9 && Screen[Com.x][Com.y - 1] != 1 && Screen[Com.x][Com.y - 1] != 2
				   && Screen[Com.x][Com.y - 1] != 5 && Screen[Com.x][Com.y - 1] != 6
				   && Screen[Com.x][Com.y - 1] != 7 && Screen[Com.x][Com.y - 1] != 8)
			   {	
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.y -= 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // ����
		   case 1 :
			   if(Screen[Com.x][Com.y + 1] != 9 && Screen[Com.x][Com.y + 1] != 1 && Screen[Com.x][Com.y + 1] != 2
				   && Screen[Com.x][Com.y + 1] != 5 && Screen[Com.x][Com.y + 1] != 6
				   && Screen[Com.x][Com.y + 1] != 7 && Screen[Com.x][Com.y + 1] != 8)
			   {
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.y += 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // ������
		   case 2 :
			   if(Screen[Com.x - 1][Com.y] != 9 && Screen[Com.x - 1][Com.y] != 1 && Screen[Com.x - 1][Com.y] != 2
				   && Screen[Com.x - 1][Com.y] != 5 && Screen[Com.x - 1][Com.y] != 6
				   && Screen[Com.x - 1][Com.y] != 7 && Screen[Com.x - 1][Com.y] != 8)
			   {
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.x -= 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // ����
		   case 3 :
			   if(Screen[Com.x + 1][Com.y] != 9 && Screen[Com.x + 1][Com.y] != 1 && Screen[Com.x + 1][Com.y] != 2
				   && Screen[Com.x + 1][Com.y] != 5 && Screen[Com.x + 1][Com.y] != 6
				   && Screen[Com.x + 1][Com.y] != 7 && Screen[Com.x + 1][Com.y] != 8)
			   {
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.x += 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // �Ʒ���
		}//Com��ġ


			RandNum = rand() % 4;
			switch(RandNum)
		   {
		   case 0 :
			   if(Screen[Cpu.x][Cpu.y - 1] != 9 && Screen[Cpu.x][Cpu.y - 1] != 1 && Screen[Cpu.x][Cpu.y - 1] != 2
				   && Screen[Cpu.x][Cpu.y - 1] != 3 && Screen[Cpu.x][Cpu.y - 1] != 4
				   && Screen[Cpu.x][Cpu.y - 1] != 7 && Screen[Cpu.x][Cpu.y - 1] != 8)
			   {	
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.y -= 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // ����
		   case 1 :
			   if(Screen[Cpu.x][Cpu.y + 1] != 9 && Screen[Cpu.x][Cpu.y + 1] != 1 && Screen[Cpu.x][Cpu.y + 1] != 2
				   && Screen[Cpu.x][Cpu.y + 1] != 3 && Screen[Cpu.x][Cpu.y + 1] != 4
				   && Screen[Cpu.x][Cpu.y + 1] != 7 && Screen[Cpu.x][Cpu.y + 1] != 8)
			   {
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.y += 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // ������
		   case 2 :
			   if(Screen[Cpu.x - 1][Cpu.y] != 9 && Screen[Cpu.x - 1][Cpu.y] != 1 && Screen[Cpu.x - 1][Cpu.y] != 2
				   && Screen[Cpu.x - 1][Cpu.y] != 3 && Screen[Cpu.x - 1][Cpu.y] != 4
				   && Screen[Cpu.x - 1][Cpu.y] != 7 && Screen[Cpu.x - 1][Cpu.y] != 8)
			   {
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.x -= 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // ����
		   case 3 :
			   if(Screen[Cpu.x + 1][Cpu.y] != 9 && Screen[Cpu.x + 1][Cpu.y] != 1 && Screen[Cpu.x + 1][Cpu.y] != 2
				   && Screen[Cpu.x + 1][Cpu.y] != 3 && Screen[Cpu.x + 1][Cpu.y] != 4
				   && Screen[Cpu.x + 1][Cpu.y] != 7 && Screen[Cpu.x + 1][Cpu.y] != 8)
			   {
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.x += 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // �Ʒ���
		}//Cpu ��ġ


			RandNum = rand() % 4;
			switch(RandNum)
		   {
		   case 0 :
			   if(Screen[Npc.x][Npc.y - 1] != 9 && Screen[Npc.x][Npc.y - 1] != 1 && Screen[Npc.x][Npc.y - 1] != 2
				   && Screen[Npc.x][Npc.y - 1] != 3 && Screen[Npc.x][Npc.y - 1] != 4
				   && Screen[Npc.x][Npc.y - 1] != 5 && Screen[Npc.x][Npc.y - 1] != 6)
			   {	
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.y -= 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // ����
		   case 1 :
			   if(Screen[Npc.x][Npc.y + 1] != 9 && Screen[Npc.x][Npc.y + 1] != 1 && Screen[Npc.x][Npc.y + 1] != 2
				   && Screen[Npc.x][Npc.y + 1] != 3 && Screen[Npc.x][Npc.y + 1] != 4
				   && Screen[Npc.x][Npc.y + 1] != 5 && Screen[Npc.x][Npc.y + 1] != 6)
			   {
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.y += 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // ������
		   case 2 :
			   if(Screen[Npc.x - 1][Npc.y] != 9 && Screen[Npc.x - 1][Npc.y] != 1 && Screen[Npc.x - 1][Npc.y] != 2
				   && Screen[Npc.x - 1][Npc.y] != 3 && Screen[Npc.x - 1][Npc.y] != 4
				   && Screen[Npc.x - 1][Cpu.y] != 5 && Screen[Npc.x - 1][Npc.y] != 6)
			   {
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.x -= 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // ����
		   case 3 :
			   if(Screen[Npc.x + 1][Npc.y] != 9 && Screen[Npc.x + 1][Npc.y] != 1 && Screen[Npc.x + 1][Npc.y] != 2
				   && Screen[Npc.x + 1][Npc.y] != 3 && Screen[Npc.x + 1][Npc.y] != 4
				   && Screen[Npc.x + 1][Npc.y] != 5 && Screen[Npc.x + 1][Npc.y] != 6)
			   {
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.x += 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // �Ʒ���
		}//Npc ��ġ


	   	   for(i = 0; i < 18; i++)
	   {
			   	   gotoxy(5, i + 1);
		   for(j = 0; j < 28; j++)
		   {
			   if(Screen[i][j] == 0)
			   {
				   BLACK;
				   printf("��");
			   }else if(Screen[i][j] == 1)
			   {
				   RED;
				   printf("��");
			   }else if(Screen[i][j] == 2)
			   {
				   RED;
				   printf("��");
			   }else if(Screen[i][j] == 9)
			   {
				   WHITE;
				   printf("��");
			   }else if(Screen[i][j] == 3)
			   {
				   YEL;
				   printf("��");
			   }else if(Screen[i][j] == 4)
			   {
				   YEL;
				   printf("��");
			   }else if(Screen[i][j] == 5)
			   {
				   GREEN;
				   printf("��");
			   }else if(Screen[i][j] == 6)
			   {
				   GREEN;
				   printf("��");
			   }else if(Screen[i][j] == 7)
			   {
				   BLUE;
				   printf("��");
			   }else if(Screen[i][j] == 8)
			   {
				   BLUE;
				   printf("��");
			   }
		   }
		   printf("\n");
		   GRAY;
	   }

		   
		   	   // Me �̵�
		   if(kbhit())
		   {
	ch = getch();
		   switch(ch)
		   {
		   case 75 :
			   if(Screen[Me.x][Me.y - 1] != 9 && Screen[Me.x][Me.y - 1] != 3 && Screen[Me.x][Me.y - 1] != 4
				   && Screen[Me.x][Me.y - 1] != 5 && Screen[Me.x][Me.y - 1] != 6
				   && Screen[Me.x][Me.y - 1] != 7 && Screen[Me.x][Me.y - 1] != 8)
			   {	
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.y -= 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // ����
		   case 77 :
			   if(Screen[Me.x][Me.y + 1] != 9 && Screen[Me.x][Me.y + 1] != 3 && Screen[Me.x][Me.y + 1] != 4
				   && Screen[Me.x][Me.y + 1] != 5 && Screen[Me.x][Me.y + 1] != 6
				   && Screen[Me.x][Me.y + 1] != 7 && Screen[Me.x][Me.y + 1] != 8)
			   {
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.y += 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // ������
		   case 72 :
			   if(Screen[Me.x - 1][Me.y] != 9 && Screen[Me.x - 1][Me.y] != 3 && Screen[Me.x - 1][Me.y] != 4
				   && Screen[Me.x - 1][Me.y] != 5 && Screen[Me.x - 1][Me.y] != 6
				   && Screen[Me.x - 1][Me.y] != 7 && Screen[Me.x - 1][Me.y] != 8)
			   {
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.x -= 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // ����
		   case 80 :
			   if(Screen[Me.x + 1][Me.y] != 9 && Screen[Me.x + 1][Me.y] != 3 && Screen[Me.x + 1][Me.y] != 4
				   && Screen[Me.x + 1][Me.y] != 5 && Screen[Me.x + 1][Me.y] != 6
				   && Screen[Me.x + 1][Me.y] != 7 && Screen[Me.x + 1][Me.y] != 8)
			   {
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.x += 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // �Ʒ���
		   }// switch ��
		   }

		   	for(i = 0; i < 18; i++)
			{
		for(j = 0; j < 28; j++)
		{
			if(Screen[i][j] == 1 || Screen[i][j] == 2)
			{
				Count[0]++;
			}else if(Screen[i][j] == 3 || Screen[i][j] == 4)
			{
				Count[1]++;
			}else if(Screen[i][j] == 5 || Screen[i][j] == 6)
			{
				Count[2]++;
			}else if(Screen[i][j] == 7 || Screen[i][j] == 8)
			{
				Count[3]++;
			}
		}
			} //���� ���

			RED;
	printf("  �� : %d      ",Count[0]);
	YEL;
	printf("     �� : %d       ",Count[1]);
	GREEN;
	printf("     �� : %d       ",Count[2]);
	BLUE;
	printf("     �� : %d\n",Count[3]);
	GRAY;
		   end = clock();
			if(end - start >= 15000)
				break;

			if ( ch == ESC )
			{
				break;
			}
	} // while ��
	
	for(i = 1;i < 4;i++)
	{
		if(Count[0] > Count[i])
		{
			*pscore += 1;
		}else
		{
			*pscore -= 1;
		}
	}

	gotoxy(22, 9);
	printf("G a m e  o v e R ! !");
	gotoxy(25, 10);
	printf("Score  :  %d\n", *pscore);
	Sleep(4000);
	system("cls");

	if ( ch = ESC )
	{
		break;
	}

	gotoxy(1,1);
	while(1)
	{

		printf("�� �� �� �� ?? (Y/N) ");
		fflush(stdin);
		scanf("%c",&ny);
		
		if(ny =='Y' || ny == 'y')
		{
			GameT = 0;
			system("cls");
			break;
		}else if(ny =='N' || ny =='n')
		{
			GameT = 1;
			break;
		}else
		{
			printf("�峭ġ�� ����? ^^* ");
		}
	}
	if(GameT == 1)
		break;
	}  // ���Ϲ� ��
	
	system("cls");
}
