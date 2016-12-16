#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Rand 함수를 위한 해더파일
#include <windows.h> // 화면 Clear를 위한 해더파일
#include <time.h> // Srand를 사용하기 위한 해더파일
#include<conio.h> // getch를 사용하기 위한 해더파일

// *************************** 컬러 사용하기 Define 값 ********************************* //

#define col GetStdHandle(STD_OUTPUT_HANDLE) // 콘솔창의 핸들정보 받기
#define BLACK SetConsoleTextAttribute(col, 0x0000); //검정색
#define GRAY SetConsoleTextAttribute(col, 0x0007); //밝은 회색
#define RED SetConsoleTextAttribute(col,0x000c); //빨간색
#define BLUE SetConsoleTextAttribute(col,0x0001 | 0x0008); //파란색
#define HIGH SetConsoleTextAttribute(col,0x00a); // 연두색
#define WHITE SetConsoleTextAttribute(col,0x000f); //하얀색
#define SKY SetConsoleTextAttribute(col,0x000b); // 하늘색
#define YEL SetConsoleTextAttribute(col,0x000e); // 노란색
#define HIG SetConsoleTextAttribute(col,0x000d); // 형광
#define GOLD SetConsoleTextAttribute(col,0x0006); //  금색
#define JAJU SetConsoleTextAttribute(col,0x0005); // 자주색
#define PII SetConsoleTextAttribute(col,0x0004); // 피색
#define GREEN SetConsoleTextAttribute(col,0x0002); // 녹색
#define VIO SetConsoleTextAttribute(col,0x0001 | 0x0008 | 0x000c); // 보라색

// ************************* 커서 숨기기 매크로 ************************************** //
enum {HIDDEN, SHOW};

// **************************** 미로함수 방향키 아스키코드값 *************************** //
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define Enter 13 // 엔터 값
#define ESC 27



// ********************************* 처음 시작 화면! *************************** //
int GameBoy(int *); // 게임보이 화면 


// ************************ System 함수 ******************************* //
void gotoxy(int ,int ); // x축 y축 이동시켜주는 함수
void delay(clock_t wait); // 딜레이 함수 시간 몇초를 대기하여라.
void color(unsigned short color); // 랜덤 컬러를 주기 위한 함수 
void CursorView(char show); // 커서를 숨기거나 보여준다.

// ************************ 가위바위보 함수 ******************************* //
void gawibawibo(int *pscore); // 가위바위보 게임 함수 

void mygawi(); // 나의 가위
void mybawi(); // 나의 바위
void mybo();   //  나의 보

void comgawi(); // 컴 가위
void combawi(); // 컴 바위
void combo(); // 컴 보

// ************************ 야구게임 함수 ******************************* //
void baseball(int *);						 // Text 야구게임 메인함수
void Num1();   // 가위바위보 숫자를 위한 함수들 1 ~ 9
void Num2();
void Num3();
void Num4();
void Num5();
void Num6();
void Num7();
void Num8();
void Num9();

// ************************ 미로탈출게임 함수 ******************************* //
void Miro(int *);			// 미로게임 메인함수
int RpgGame();							

// ************************ 순간기억게임 함수 ******************************* //
void StarNum(int *);

// ************************ 땅따먹기 게임 함수 ****************************** //
void SetMap(int A[][28]);
void StarMap(int A[][28],int B[30]);
void ddang(int *);


void main()
{
	int number = 0;
	
	while(1) {
		
		static int score = 0; // 스코어 누적 함수

		number = GameBoy(&score);
		
		system("cls"); // 화면 리셋

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

//************************************** 겜보이 화면 **************************************************//

int GameBoy(int *pscore)
{char Game[17][17] = {{5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}, // 게임기 기틀
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

	int i, j; // 반복제어변수
	int randcolor = 0; // 램덤컬러 주기 ㅋ
	int x = 1; // 화살표의 처음 좌표
	int y = 2; // 화살표의 처음 좌표 

	system("mode con lines=29 cols=79");
	CursorView(HIDDEN);

	for( i = 0; i < sizeof(Game) / sizeof(Game[0]); i ++)  // 반복문
	{
		gotoxy(20,i+7);
		for ( j = 0; j < sizeof(Game[0]); j ++)
		{
			if( Game[i][j] == 69)
			{
				printf(" 현재의 Score : %d 점 !  ", *pscore);
			}
			else if( Game[i][j] == 68)
			{
				printf("     ★ 게임 설명 ★     ");
			}
			else if( Game[i][j] == 50)
			{
				printf(" 1. 가위 바위 보 게임 ! ");
			}
			else if(Game[i][j] == 51)
			{
				printf(" 2. 텍스트 야구 게임  ! ");
			}
			else if( Game[i][j] == 52)
			{
				printf(" 3. 벽 탈출 게임      ! ");
			}
			else if( Game[i][j] == 53)
			{
				printf(" 4. 순간 기억 게임    ! ");
			}
			else if( Game[i][j] == 54)
			{
				printf(" 5. 땅 따먹기 게임    ! ");
			}
			else if( Game[i][j] == 10)
			{
				printf("↓");
			}
			else if( Game[i][j] == 9)
			{
				printf("→");
			}
			else if( Game[i][j] == 8)
			{
				printf("←");
			}
			else if( Game[i][j] == 7)
			{
				printf("↑");
			}
			else if( Game[i][j] == 6)
			{
				printf("○");
			}
			else if( Game[i][j] == 5)
			{
				WHITE;
				printf("■");
				GRAY;
			}
			else if( Game[i][j] == 4)
			{
				printf("ⓐ");
			}
			else if( Game[i][j] == 3)
			{
				printf("ⓑ");
			}
			else if( Game[i][j] == 2)
			{
				printf(" ");
			}
			else if( Game[i][j] == 1)
			{
				SKY;
				printf("▶");
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
			printf("■");
			GRAY;

			randcolor = rand() % 6 + 1; // 1~6 까지의 숫자를 줌

				switch(randcolor) // 랜덤함수에서 받은 수를 출력함
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
				} // 스위치 케이스 끝
				gotoxy(10, 2); 
				printf("┌─┐                   ┌─┐                       ┌┐");
				gotoxy(10, 3);
				printf("│                       │                     ┌┐  ││");
				gotoxy(10, 4);
				printf("│  ─ ┌┐ │＼│ ○    │  ─ ┌┐   │＼／│ ├┘  └┘");
				gotoxy(10,5);
				printf("└─┘ └┘ │  │ │    └─┘ └┘＼ │    │ └─   ○ ");
				GRAY;
			

			gotoxy(52, 18);
			WHITE;
			printf("■");
			GRAY;

			for( i = 0; i < sizeof(Game) / sizeof(Game[0]); i ++)  // 반복문
			{	
				gotoxy(20,i+7);
				for ( j = 0; j < sizeof(Game[0]); j ++)
				{
					
					if( Game[i][j] == 69)
					{
						printf(" 현재의 Score : %d 점 !  ", *pscore);
					}
					else if( Game[i][j] == 68)
					{
						printf("     ★ 게임 설명 ★     ");
					}
					else if( Game[i][j] == 50)
					{
						printf(" 1. 가위 바위 보 게임 ! ");
					}
					else if(Game[i][j] == 51)
					{
						printf(" 2. 텍스트 야구 게임  ! ");
					}
					else if( Game[i][j] == 52)
					{
						printf(" 3. 여자를 피해라     ! ");
					}
					else if( Game[i][j] == 53)
					{
						printf(" 4. 순간 기억 게임    ! ");
					}
					else if( Game[i][j] == 54)
					{
						printf(" 5. 땅 따먹기 게임    ! ");
					}
					else if( Game[i][j] == 10)
					{
						printf("↓");
					}
					else if( Game[i][j] == 9)
					{
						printf("→");
					}
					else if( Game[i][j] == 8)
					{
						printf("←");
					}
					else if( Game[i][j] == 7)
					{
						printf("↑");
					}
					else if( Game[i][j] == 6)
					{
						printf("○");
					}
					else if( Game[i][j] == 5)
					{
						WHITE;
						printf("■");
						GRAY;
					}
					else if( Game[i][j] == 4)
					{
						printf("ⓐ");
					}
					else if( Game[i][j] == 3)
					{
						printf("ⓑ");
					}
					else if( Game[i][j] == 2)
					{
						printf(" ");
					}
					else if( Game[i][j] == 1)
					{
						SKY;
						printf("▶");
						GRAY;
					}
					else if ( Game[i][j] == 0)
					{
						printf("  ");
					}			
				} // j 포문 끝

				printf("\n");
			} // i 포문 끝

			gotoxy(52, 18);
			WHITE;
			printf("■");
			GRAY;

			if(kbhit())
			{
			char move = 0; // 움직임 제어 변수
			int Number = 0; // 게임 선택 변수

			move = getch();
			

			switch(move) // 무브를 판단하여 작동 위 / 아래
			{
			case UP: if(Game[x-1][y] != 2)
					 {
						 if(Game[x-1][y] == 0) 
						 {
							 Game[x][y] = 0;
							 --x;
							  Game[x][y] = 1;
						 }
					 } // 이프문 끝
					 break;
					 
			case DOWN: if(Game[x+1][y] != 2)
					   {
						   if(Game[x+1][y] == 0)
						   {
							   Game[x][y] = 0;
							   ++x;
							   Game[x][y] = 1;

						   }
					   } // 이프문 끝 
					   break;
			case Enter: Number = x;
				break;
			} // 특수키 스위치 케이스문 끝

			if(move == Enter)
			{
				return Number;
				break;
			} // 엔터를 누르면 Number값을 리턴 받고 종료.
				

			} // 이프 Kbhit 문 종료
		} // 무한 반복 와일문 종료
} // 메인함수 끝


void gotoxy(int x, int y) // x축 y축 이동시켜주는 함수
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(unsigned short color) // 무작위 컬러 만들기위한 함수
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void CursorView(char show) // 커서 숨기기 / 보이기 
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
 //wait ms 만큼 대기 1000 = 1초
 clock_t goal;
 goal= wait + clock();
 while(goal > clock());
}

void gawibawibo(int *pscore)   // 가위바위보 게임 !!
{

	int gawibawibo = 0;
	int a = 0, i, j;

	char Me[11][15] = {0}; // 나의 칸 배열
	char Com[11][15] = {0}; // 컴퓨터 칸 배열
	char Main[5][5] = {{2,2,2,2,2}, // 가위바위보 선택 칸 배열
	{2,1,3,2},
	{2,0,4,2},
	{2,0,5,2},
	{2,2,2,2,2}};

	int x = 1;
	int y = 1;

	int Number = 0; // 무엇을 내엇는지 확인 

	char move = 0;

	// ******************** 배열 초기화 ************************ //
	for ( i = 0; i < sizeof(Me) / sizeof(Me[0]); i ++)
	{
		for( j = 0; j < sizeof(Me[0]); j ++)
		{
			Me[i][j] = 0;
			Com[i][j] = 0;
		}
	}




	// ************************* 벽 생성 값 부여 **************************************//
	
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

		// *********************** 내 벽 생성 ************************* //
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
					printf("■");
					GRAY;
				}
			}
		}

	// *********************** 컴퓨터 벽 생성 *************************** //
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
					printf("■");
					GRAY;
				}
			}
		}


		// *************** vs , Me, Com 출력 ***************** //
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
	
	srand(time(NULL)); // 무작위 변수를 만들기 위한 Srand 함수

	WHITE;
		gotoxy(9,0);
		printf("============================================================\n");
		gotoxy(9,1);
		printf(" 가  위  바  위  보  에  오  신  것  을  환  영  합  니  다  !!\n");
		gotoxy(9,2);
		printf("         'ESC' 를 누르면 종료 됩니다. ! Let's Go !            \n");
		gotoxy(9,3);
		printf("=============================================================\n");
		
	GRAY;

	

	while (1) 
	{

	gawibawibo = (rand() % 3) + 1; // 랜덤함수에 3을 나눈값에 1을 더해 1 ~ 3까지의 무작위 변수 출현

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
				printf("▶");
				GRAY;
			}
			else if ( Main[i][j] == 2)
			{
				HIGH;
				printf("■");
				GRAY;
			}
			else if ( Main[i][j] == 3)
			{
				WHITE;
				printf("바위");
				GRAY;
			}
			else if ( Main[i][j] == 4)
			{
				WHITE;
				printf("가위");
				GRAY;
			}
			else if ( Main[i][j] == 5)
			{
				WHITE;
				printf(" 보 ");
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


		}// 스위치 케이스문 종료

		// ****************** 와일문 빠져나가기 ************************* //
		if ( move == ESC )
		{
			system("cls");
			break;
		}

	// ************************ 판단 If 문 **************************** //
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
	} // 와일문 종료
} // 메인함수 종료

void mybo()
{ 
		gotoxy(47, 6);
		puts("    ┏━┳━┳━┳━┓   ");
		gotoxy(47, 7);
		puts("    ┃▒┃▒┃▒┃▒┃   ");
		gotoxy(47, 8);
		puts("    ┃▒┃▒┃▒┃▒┃┓ ");
		gotoxy(47, 9);
		puts("┏━┃▒┃▒┃▒┃▒┃┃ ");
		gotoxy(47, 10);
		puts("┃  ┃▒┃▒┃▒┃▒┃┃ ");
		gotoxy(47, 11);
		puts("┗┓▒▒▒▒▒▒▒▒┃┃ ");
		gotoxy(47, 12);
		puts("  ┗┓▒▒▒▒▒▒▒┏┛ ");
		gotoxy(47, 13);
		puts("    ┗┓▒▒▒▒▒┏┛   ");

}
void mybawi()
{
		gotoxy(47, 6);
		puts("                         ");
		gotoxy(47, 7);
		puts("    ┏━┳━┳━┳━┓   ");
		gotoxy(47, 8);
		puts("    ┃▒┃▒┃▒┃▒┃┓ ");
		gotoxy(47, 9);
		puts("  ┏┻━┻━┓━┛━┛┃ ");
		gotoxy(47, 10);
		puts("  ┃▒┏━━┛▒▒▒▒┃ ");
		gotoxy(47, 11);
		puts("  ┗┓▒▒▒▒▒▒▒┏┛ ");
		gotoxy(47, 12);
		puts("    ┗┓▒▒▒▒▒┏┛   ");
		gotoxy(47, 13);
		puts("                         ");

}
void mygawi()
{
		gotoxy(47, 6);
		puts("    ┏━┳━┓           ");
		gotoxy(47, 7);
		puts("    ┃▒┃▒┃           ");
		gotoxy(47, 8);
		puts("    ┃▒┃▒┃━┳━┓   ");
		gotoxy(47, 9);
		puts("  ┏┻━┻━┓▒┃▒┃┓ ");
		gotoxy(47, 10);
		puts("  ┃▒┏━━┛━┛━┛┃ ");
		gotoxy(47, 11);
		puts("  ┗┓▒▒▒▒▒▒▒▒┃ ");
		gotoxy(47, 12);
		puts("    ┗┓▒▒▒▒▒▒┏┛ ");
		gotoxy(47, 13);
		puts("      ┗┓▒▒▒▒┏┛   ");

}


void combo()
{ 
		gotoxy(47, 18);
		puts("    ┏━┳━┳━┳━┓    ");
		gotoxy(47, 19);
		puts("    ┃▒┃▒┃▒┃▒┃    ");
		gotoxy(47, 20);
		puts("    ┃▒┃▒┃▒┃▒┃┓  ");
		gotoxy(47, 21);
		puts("┏━┃▒┃▒┃▒┃▒┃┃  ");
		gotoxy(47, 22);
		puts("┃  ┃▒┃▒┃▒┃▒┃┃  ");
		gotoxy(47, 23);
		puts("┗┓▒▒▒▒▒▒▒▒┃┃  ");
		gotoxy(47, 24);
		puts("  ┗┓▒▒▒▒▒▒▒┏┛  ");
		gotoxy(47, 25);
		puts("    ┗┓▒▒▒▒▒┏┛    ");

}
void combawi()
{
		gotoxy(47, 18);
		puts("                         ");
		gotoxy(47, 19);
		puts("    ┏━┳━┳━┳━┓   ");
		gotoxy(47, 20);
		puts("    ┃▒┃▒┃▒┃▒┃┓ ");
		gotoxy(47, 21);
		puts("  ┏┻━┻━┓━┛━┛┃ ");
		gotoxy(47, 22);
		puts("  ┃▒┏━━┛▒▒▒▒┃ ");
		gotoxy(47, 23);
		puts("  ┗┓▒▒▒▒▒▒▒┏┛ ");
		gotoxy(47, 24);
		puts("    ┗┓▒▒▒▒▒┏┛   ");
		gotoxy(47, 25);
		puts("                         ");

}
void comgawi()
{
		gotoxy(47, 18);
		puts("    ┏━┳━┓           ");
		gotoxy(47, 19);
		puts("    ┃▒┃▒┃           ");
		gotoxy(47, 20);
		puts("    ┃▒┃▒┃━┳━┓   ");
		gotoxy(47, 21);
		puts("  ┏┻━┻━┓▒┃▒┃┓ ");
		gotoxy(47, 22);
		puts("  ┃▒┏━━┛━┛━┛┃ ");
		gotoxy(47, 23);
		puts("  ┗┓▒▒▒▒▒▒▒▒┃ ");
		gotoxy(47, 24);
		puts("    ┗┓▒▒▒▒▒▒┏┛ ");
		gotoxy(47, 25);
		puts("      ┗┓▒▒▒▒┏┛   ");

}



// ********************************** 야구게임 시작 ! *********************************** //
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
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}}; // 전광판 배열

	char Join[2][11] = {{2,1,0,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2,2}}; // 방향키 이동을 위한 배열

	int st[2] = {0}; // 스트라이크 볼 갯수 체크

	int Number = 0; // 숫자의 선택값을 받기위한 변수
	static int i,j; // 반복제어변수
	int ComNum[3] = {0}; // 정답의 수를 저장할 배열
	int randcolor = 0; // 랜덤 컬러를 위한 변수
	int kount = 0; // 스위치 케이스문 무한방복 방지 변수
	int count = 0; // 숫자의 선택 수를 확인
	int compare = 0; // 판독 카운트 변수
	int k = 0; // 별 터트리는 숫자 체크
	
	char move = 0; // 움직임 제어 변수
	
	int x = 1;
	int y = 0;

	srand((unsigned)time(NULL)); // 랜드함수의 가지수를 바꾸기 위한 Srand

	for(;;) {  // 1~9의 자리를 만들기 위한 반복문
		for(i = 0; i < 3; i++) {
			ComNum[i] = rand() % 9 + 1;
		}
		if ( ComNum[0] != ComNum[1] && ComNum[0] != ComNum[2] && ComNum[1] != ComNum[2]) {
			break;
		} // j 포문 종료
	} // i 포문 종료



	system("mode con lines=25 cols=100"); // CMD 창 크기 조절
	gotoxy(19,0);
	WHITE;
	printf(" 야구 게임에 오신 여러분 환영 합니다.! 자 그럼 시작 합니다. ! ");
	gotoxy(19, 1);
	printf("            'ESC'를 누르면 게임이 종료 됩니다.!                ");
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
	
		// **************************** 전광판 생성 ************************************** //
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
					printf("■");
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
					printf("＼");
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
					printf("─");
					GRAY;
				}
				else if ( Pan[i][j] == 5 )
				{
					printf(" ");
				}
				else if ( Pan[i][j] == 10 )
				{
					WHITE;
					printf("1회  ");
					GRAY;
				}
				else if ( Pan[i][j] == 11 )
				{
					WHITE;
					printf("2회  ");
					GRAY;
				}
				else if ( Pan[i][j] == 12 )
				{
					WHITE;
					printf("3회  ");
					GRAY;
				}
				else if ( Pan[i][j] == 13 )
				{
					WHITE;
					printf("4회  ");
					GRAY;
				}
				else if ( Pan[i][j] == 14 )
				{
					WHITE;
					printf("5회  ");
					GRAY;
				}
				else if ( Pan[i][j] == 15 )
				{
					WHITE;
					printf("6회  ");
					GRAY;
				}
				else if ( Pan[i][j] == 20 )
				{
					RED;
					printf("ⓢtrike ");
					GRAY;
				}
				else if ( Pan[i][j] == 21 )
				{
					SKY;
					printf("ⓑall ");
					GRAY;
				}
				else if ( Pan[i][j] == 22 )
				{
					VIO;
					printf("ⓞut  ");
					GRAY;
				}
				else if ( Pan[i][j] == 50 )
				{
					GOLD;
					printf("옵션");
					GRAY;
				}
				else if( Pan[i][j] == 51 )
				{
					GOLD;
					printf("기회");
					GRAY;
				}
				else if( Pan[i][j] == 101)
				{
					WHITE;
					printf("①");
					GRAY;
				}
				else if ( Pan[i][j] == 102 )
				{
					WHITE;
					printf("②");
					GRAY;
				}
				else if ( Pan[i][j] == 103 )
				{
					WHITE;
					printf("③");
					GRAY;
				}
				else if ( Pan[i][j] == 104 )
				{
					WHITE;
					printf("④");
					GRAY;
				}
				else if ( Pan[i][j] == 105 )
				{
					WHITE;
					printf("⑤");
					GRAY;
				}
				else if ( Pan[i][j] == 106 )
				{
					WHITE;
					printf("⑥");
					GRAY;
				}
				else if ( Pan[i][j] == 107 )
				{
					WHITE;
					printf("⑦");
					GRAY;
				}
				else if ( Pan[i][j] == 108 )
				{
					WHITE;
					printf("⑧");
					GRAY;
				}
				else if ( Pan[i][j] == 109 )
				{
					WHITE;
					printf("⑨");
					GRAY;
				}
		} // j 포문 종료
	} // i 포문 종료
	// ************************************* 전광판 끝 ************************************************** //

	// ************************************* 방향표 시작 *********************************************** //

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
					printf("▲");
					GRAY;
			} // 이프문 종료
		} // j 포문 종료
	} // i 포문 종료


	// ********************************************* 방향표 종료 ***************************************** //



	// ********************************************* 방향표 움직이는 구문 시작 ******************************************** //
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
		} // 스위치 케이스문 종료
	} // Kbhit 문 종료

	// ****************************************************** 방향표 움직이는 구문 종료 ************************************************* //

	// ****************************************************** 전광판 숫자 기록하기 시작 ********************************************* //

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

	} // 스위치케이스 종료

	// ********************************************************* 전광판 기록 종료 ********************************************** //

	// *************************************************** 판독 시작 ************************************************** //
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
		} // j 포문 종료
	} // i 포문 종료
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
		} // j 포문 종료
	} // i 포문 종료
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
		} // j 포문 종료
	} // i 포문 종료
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
		} // j 포문 종료
	} // i 포문 종료
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
		} // j 포문 종료
	} // i 포문 종료
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
		} // j 포문 종료
	} // i 포문 종료
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
	} // 스위치 케이스 종료

	if ( st[0] == 3)
	{
		break;
	}
	else if ( st[0] == 4)
	{
		break;
	}

	} // 와일문 종료 

	// ********************************** 클리어 시 나오는 화면 시작 **************************************** //
	
	if ( st[0] == 3 )
	{
		
		system("cls");
		srand((unsigned)time(NULL));

		while(k < 1000)
		{
			gotoxy((rand() % 49) * 2, rand() % 25);
			color(rand() % 14 + 2);
			printf("★");
			 Sleep(1);
			 k++;
		} // While 문 종료
		GRAY;
		k = 0;
		system("cls");

		gotoxy(25, 12);
		WHITE;
		printf(" 축하합니다 ! 정답을 맞추셨습니다.! ");
		gotoxy(25, 14);
		printf("     정답은 ! %d%d%d 입니다. ", ComNum[0], ComNum[1], ComNum[2]);
		GRAY;
		Sleep(2000);
		
	} // if문 종료

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
			printf("ㅎ");
			}
			else 
			{
			printf("ㅋ");
			}
			 Sleep(1);
			 k++;
		} // While 문 종료
		GRAY;
		k = 0;
		system("cls");

		gotoxy(25, 12);
		WHITE;
		printf(" 틀렸어용... 잘좀 하시지 ^^; 머리가 나쁘신가 ㅎㅎ; ");
		gotoxy(25, 14);
		printf("           정답은 ! %d%d%d 였는데... ", ComNum[0], ComNum[1], ComNum[2]);
		GRAY;
		Sleep(2000);
	} // else 문 종료 

	// ************************************ 클리어 시 나오는 화면 종료 ************************************** //

} // 메인함수 종료	

	// ************************************ 야구게임 숫자 넘버 1 ~ 9 시작 ************************************ //

void Num1()
{
	WHITE;
	gotoxy(18, 16);
	puts("■■  ");
	gotoxy(18, 17);
	puts("  ■  ");
	gotoxy(18, 18);
	puts("  ■  ");
	gotoxy(18, 19);
	puts("  ■  ");
	gotoxy(18, 20);
	puts("■■■");
	gotoxy(18, 21);
	VIO;
	puts("  ●  ");
	GRAY;
}
void Num2()
{
	WHITE;
	gotoxy(25, 16);
	puts("■■■");
	gotoxy(25, 17);
	puts("    ■");
	gotoxy(25, 18);
	puts("■■■");
	gotoxy(25, 19);
	puts("■    ");
	gotoxy(25, 20);
	puts("■■■");
	gotoxy(25, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num3()
{
	WHITE;
	gotoxy(32, 16);
	puts("■■■");
	gotoxy(32, 17);
	puts("    ■");
	gotoxy(32, 18);
	puts("■■■");
	gotoxy(32, 19);
	puts("    ■");
	gotoxy(32, 20);
	puts("■■■");
	gotoxy(32, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num4()
{
	WHITE;
	gotoxy(39, 16);
	puts("■  ■");
	gotoxy(39, 17);
	puts("■  ■");
	gotoxy(39, 18);
	puts("■■■");
	gotoxy(39, 19);
	puts("    ■");
	gotoxy(39, 20);
	puts("    ■");
	gotoxy(39, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num5()
{
	WHITE;
	gotoxy(46, 16);
	puts("■■■");
	gotoxy(46, 17);
	puts("■    ");
	gotoxy(46, 18);
	puts("■■■");
	gotoxy(46, 19);
	puts("    ■");
	gotoxy(46, 20);
	puts("■■■");
	gotoxy(46, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num6()
{
	WHITE;
	gotoxy(53, 16);
	puts("■■■");
	gotoxy(53, 17);
	puts("■    ");
	gotoxy(53, 18);
	puts("■■■");
	gotoxy(53, 19);
	puts("■  ■");
	gotoxy(53, 20);
	puts("■■■");
	gotoxy(53, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num7()
{
	WHITE;
	gotoxy(60, 16);
	puts("■■■");
	gotoxy(60, 17);
	puts("■  ■");
	gotoxy(60, 18);
	puts("    ■");
	gotoxy(60, 19);
	puts("    ■");
	gotoxy(60, 20);
	puts("    ■");
	gotoxy(60, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num8()
{
	WHITE;
	gotoxy(67, 16);
	puts("■■■");
	gotoxy(67, 17);
	puts("■  ■");
	gotoxy(67, 18);
	puts("■■■");
	gotoxy(67, 19);
	puts("■  ■");
	gotoxy(67, 20);
	puts("■■■");
	gotoxy(67, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}
void Num9()
{
	WHITE;
	gotoxy(74, 16);
	puts("■■■");
	gotoxy(74, 17);
	puts("■  ■");
	gotoxy(74, 18);
	puts("■■■");
	gotoxy(74, 19);
	puts("    ■");
	gotoxy(74, 20);
	puts("■■■");
	gotoxy(74, 21);
	VIO;
	puts("  ●  ");
	GRAY;

}


// ********************************** 여자를 피해라 시작 ! ********************************* //

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

    system("mode con lines=20 cols=58");// 창 크기 line = y축, cols = x축, line은 -1 크기 출력
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


	for(i = 0; i < 18;i++) // 초기화
		{
			for(j = 0; j < 28;j++)
			{
				Screen[i][j] = 0;
			}
		}

		k = 0;
		for(i = 0; i < 18; i++) // 벽 생성
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
		Screen[7][1] = 1; // 초기화	
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
			   break; // 왼쪽
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
			   break; // 오른쪽
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
			   break; // 위쪽
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
			   break; // 아래쪽
			}//s1witch 끝
		}//if 끝
		}//Mon 위치, for 끝

		for(i = 0; i < 18; i++) // 최종 출력
	   {
		   gotoxy(1,i+1);
		   for(j = 0; j < 28; j++)
		   {
			   if(Screen[i][j] == 0)
			   {
				   BLACK;
				   printf("★");
			   }else if(Screen[i][j] == Me.PlayN)
			   {
				   RED;
				   printf("☆");
			   }else if(Screen[i][j] == 9)
			   {
			   WHITE;
			   printf("■");
			   }else if(Screen[i][j] == Mon[0].PlayN)
			   {
				   VIO;
				   printf("♀");
			   }else if(Screen[i][j] == Pre[0].PlayN)
			   {
				   YEL;
				   printf("♡");
			   }//if 끝
		   }// j for 끝	  
		   printf("\n");
		}//i for 끝
		   
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
			   break; // 왼쪽
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
			   break; // 오른쪽
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
			   break; // 위쪽
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
			   break; // 아래쪽
		   case ESC: break;
		   }// switch 끝
	}// if 끝

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
	}//for문 끝
	
	
	if(PreNum == 0)
	{
	if(Me.y == 27)
	{
		break;
	}
	}
	}//while2 끝

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
			printf("☆");
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
	}// if 종료\



	}//while1 끝
	return 0;
}

// **************************************** 순간 기억게임 시작 ***************************************** //


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
	printf("제한 시간 5초!!!");
	Sleep(1000);


	while(GameT < 3)
	{
		RandNum = rand() % 10 + 10;
		StarPosition = 0;
		fflush(stdin);

		for(i = 0; i < 11;i++) // 초기화
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

	   for(i = 0; i < 11; i++) // 벽 생성
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

	   for(i = 1; i < 10; i++) // 별 위치 생성
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

	   for(i = 0;i < 11; i++) // 출력
	   {
		   gotoxy(5, i + 1);
		   for(j = 0; j < 21; j++)
		   {
			   if(Screen[i][j] == 0)
			   {
				   BLACK;
				   printf("★");
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
				   printf("★");
			   }
			   else if(Screen[i][j] == 2)
			   {
				   WHITE;
				   printf("■");
			   }
		   }
		   printf("\n");
	   }

   Sleep(2500); // 마지막으로 너무빨라서 눈에안보이니 일부러 슬립을 좀걸어줍니다.
   printf("\n");

   system("cls");
   GRAY;
   start = clock();
   gotoxy(3, 5);
   printf(" 방금 나온 별의 갯수는 몇개 일까요 ^^? : ");
   scanf("%d",&Inp);
   end = clock();
   system("cls");

   if(end - start >= 5000)
   {
	   gotoxy(15, 5);
	   printf("빨리좀 풀어잉 T^T \n");
	   *pscore -= 1;
   }else if(Inp == RandNum) {
	   gotoxy(5, 5);
	   printf("우왕 엄청나게 좋은 기억력 이시답 ! '-' \n");
	   *pscore += 1;
   }else {
	   gotoxy(6, 5);
	   printf("한마디만 할께요. 풉 ㅋ. . . . . . . . \n");
	   *pscore -= 1;
   }
   Sleep(1500);
   GameT++;
   while(GameT == 5)
   {
	   system("cls");
	   getchar();
	   gotoxy(20, 13);
	   printf("더 하실래요 ? (Y/N) ");
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
		   printf("장난치지마라.");
	   }
   }
		
	}
	system("cls");
}



// **************************************** 땅따먹기 게임 시작 ********************************************* //
void SetMap(int A[][28])
{
	int i, j;
	for(i = 0; i < 18;i++) // 초기화
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
		
	for(i = 0; i < 18; i++) // 벽 생성
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
			   break; // 왼쪽
		   case 1 :
			   if(Screen[Com.x][Com.y + 1] != 9 && Screen[Com.x][Com.y + 1] != 1 && Screen[Com.x][Com.y + 1] != 2
				   && Screen[Com.x][Com.y + 1] != 5 && Screen[Com.x][Com.y + 1] != 6
				   && Screen[Com.x][Com.y + 1] != 7 && Screen[Com.x][Com.y + 1] != 8)
			   {
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.y += 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // 오른쪽
		   case 2 :
			   if(Screen[Com.x - 1][Com.y] != 9 && Screen[Com.x - 1][Com.y] != 1 && Screen[Com.x - 1][Com.y] != 2
				   && Screen[Com.x - 1][Com.y] != 5 && Screen[Com.x - 1][Com.y] != 6
				   && Screen[Com.x - 1][Com.y] != 7 && Screen[Com.x - 1][Com.y] != 8)
			   {
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.x -= 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // 위쪽
		   case 3 :
			   if(Screen[Com.x + 1][Com.y] != 9 && Screen[Com.x + 1][Com.y] != 1 && Screen[Com.x + 1][Com.y] != 2
				   && Screen[Com.x + 1][Com.y] != 5 && Screen[Com.x + 1][Com.y] != 6
				   && Screen[Com.x + 1][Com.y] != 7 && Screen[Com.x + 1][Com.y] != 8)
			   {
				   Screen[Com.x][Com.y] = Com.Num;
				   Com.x += 1;
			   }
			   Screen[Com.x][Com.y] = Com.playN;
			   break; // 아래쪽
		}//Com위치


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
			   break; // 왼쪽
		   case 1 :
			   if(Screen[Cpu.x][Cpu.y + 1] != 9 && Screen[Cpu.x][Cpu.y + 1] != 1 && Screen[Cpu.x][Cpu.y + 1] != 2
				   && Screen[Cpu.x][Cpu.y + 1] != 3 && Screen[Cpu.x][Cpu.y + 1] != 4
				   && Screen[Cpu.x][Cpu.y + 1] != 7 && Screen[Cpu.x][Cpu.y + 1] != 8)
			   {
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.y += 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // 오른쪽
		   case 2 :
			   if(Screen[Cpu.x - 1][Cpu.y] != 9 && Screen[Cpu.x - 1][Cpu.y] != 1 && Screen[Cpu.x - 1][Cpu.y] != 2
				   && Screen[Cpu.x - 1][Cpu.y] != 3 && Screen[Cpu.x - 1][Cpu.y] != 4
				   && Screen[Cpu.x - 1][Cpu.y] != 7 && Screen[Cpu.x - 1][Cpu.y] != 8)
			   {
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.x -= 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // 위쪽
		   case 3 :
			   if(Screen[Cpu.x + 1][Cpu.y] != 9 && Screen[Cpu.x + 1][Cpu.y] != 1 && Screen[Cpu.x + 1][Cpu.y] != 2
				   && Screen[Cpu.x + 1][Cpu.y] != 3 && Screen[Cpu.x + 1][Cpu.y] != 4
				   && Screen[Cpu.x + 1][Cpu.y] != 7 && Screen[Cpu.x + 1][Cpu.y] != 8)
			   {
				   Screen[Cpu.x][Cpu.y] = Cpu.Num;
				   Cpu.x += 1;
			   }
			   Screen[Cpu.x][Cpu.y] = Cpu.playN;
			   break; // 아래쪽
		}//Cpu 위치


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
			   break; // 왼쪽
		   case 1 :
			   if(Screen[Npc.x][Npc.y + 1] != 9 && Screen[Npc.x][Npc.y + 1] != 1 && Screen[Npc.x][Npc.y + 1] != 2
				   && Screen[Npc.x][Npc.y + 1] != 3 && Screen[Npc.x][Npc.y + 1] != 4
				   && Screen[Npc.x][Npc.y + 1] != 5 && Screen[Npc.x][Npc.y + 1] != 6)
			   {
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.y += 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // 오른쪽
		   case 2 :
			   if(Screen[Npc.x - 1][Npc.y] != 9 && Screen[Npc.x - 1][Npc.y] != 1 && Screen[Npc.x - 1][Npc.y] != 2
				   && Screen[Npc.x - 1][Npc.y] != 3 && Screen[Npc.x - 1][Npc.y] != 4
				   && Screen[Npc.x - 1][Cpu.y] != 5 && Screen[Npc.x - 1][Npc.y] != 6)
			   {
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.x -= 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // 위쪽
		   case 3 :
			   if(Screen[Npc.x + 1][Npc.y] != 9 && Screen[Npc.x + 1][Npc.y] != 1 && Screen[Npc.x + 1][Npc.y] != 2
				   && Screen[Npc.x + 1][Npc.y] != 3 && Screen[Npc.x + 1][Npc.y] != 4
				   && Screen[Npc.x + 1][Npc.y] != 5 && Screen[Npc.x + 1][Npc.y] != 6)
			   {
				   Screen[Npc.x][Npc.y] = Npc.Num;
				   Npc.x += 1;
			   }
			   Screen[Npc.x][Npc.y] = Npc.playN;
			   break; // 아래쪽
		}//Npc 위치


	   	   for(i = 0; i < 18; i++)
	   {
			   	   gotoxy(5, i + 1);
		   for(j = 0; j < 28; j++)
		   {
			   if(Screen[i][j] == 0)
			   {
				   BLACK;
				   printf("★");
			   }else if(Screen[i][j] == 1)
			   {
				   RED;
				   printf("☆");
			   }else if(Screen[i][j] == 2)
			   {
				   RED;
				   printf("★");
			   }else if(Screen[i][j] == 9)
			   {
				   WHITE;
				   printf("■");
			   }else if(Screen[i][j] == 3)
			   {
				   YEL;
				   printf("☆");
			   }else if(Screen[i][j] == 4)
			   {
				   YEL;
				   printf("★");
			   }else if(Screen[i][j] == 5)
			   {
				   GREEN;
				   printf("☆");
			   }else if(Screen[i][j] == 6)
			   {
				   GREEN;
				   printf("★");
			   }else if(Screen[i][j] == 7)
			   {
				   BLUE;
				   printf("☆");
			   }else if(Screen[i][j] == 8)
			   {
				   BLUE;
				   printf("★");
			   }
		   }
		   printf("\n");
		   GRAY;
	   }

		   
		   	   // Me 이동
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
			   break; // 왼쪽
		   case 77 :
			   if(Screen[Me.x][Me.y + 1] != 9 && Screen[Me.x][Me.y + 1] != 3 && Screen[Me.x][Me.y + 1] != 4
				   && Screen[Me.x][Me.y + 1] != 5 && Screen[Me.x][Me.y + 1] != 6
				   && Screen[Me.x][Me.y + 1] != 7 && Screen[Me.x][Me.y + 1] != 8)
			   {
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.y += 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // 오른쪽
		   case 72 :
			   if(Screen[Me.x - 1][Me.y] != 9 && Screen[Me.x - 1][Me.y] != 3 && Screen[Me.x - 1][Me.y] != 4
				   && Screen[Me.x - 1][Me.y] != 5 && Screen[Me.x - 1][Me.y] != 6
				   && Screen[Me.x - 1][Me.y] != 7 && Screen[Me.x - 1][Me.y] != 8)
			   {
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.x -= 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // 위쪽
		   case 80 :
			   if(Screen[Me.x + 1][Me.y] != 9 && Screen[Me.x + 1][Me.y] != 3 && Screen[Me.x + 1][Me.y] != 4
				   && Screen[Me.x + 1][Me.y] != 5 && Screen[Me.x + 1][Me.y] != 6
				   && Screen[Me.x + 1][Me.y] != 7 && Screen[Me.x + 1][Me.y] != 8)
			   {
				   Screen[Me.x][Me.y] = Me.Num;
				   Me.x += 1;
			   }
			   Screen[Me.x][Me.y] = Me.playN;
			   break; // 아래쪽
		   }// switch 끝
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
			} //갯수 출력

			RED;
	printf("  ★ : %d      ",Count[0]);
	YEL;
	printf("     ★ : %d       ",Count[1]);
	GREEN;
	printf("     ★ : %d       ",Count[2]);
	BLUE;
	printf("     ★ : %d\n",Count[3]);
	GRAY;
		   end = clock();
			if(end - start >= 15000)
				break;

			if ( ch == ESC )
			{
				break;
			}
	} // while 끝
	
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

		printf("더 할 거 임 ?? (Y/N) ");
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
			printf("장난치지 마라? ^^* ");
		}
	}
	if(GameT == 1)
		break;
	}  // 와일문 끝
	
	system("cls");
}
