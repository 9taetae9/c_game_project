#include <windows.h>//制亀酔 遂 呪弦精 敗呪級聖 舛税 (COORD, SetConsoleCursorPosition(), GetStdHandle())
#include <stdio.h>//妊層脊窒径 虞戚崎君軒 
#include <conio.h>/* 嬬車 脊窒径 敗呪研 薦因馬澗 伯希 督析
getch()敗呪  */ 
 
// 惟績 発井 痕呪
#define MAX_DDONG       100 // 極税 置企 鯵呪.

#define LEVEL_COUNT     3   // 傾婚原陥 潅嬢劾 極鯵呪
#define LEVEL_SPEED     15  // 傾婚原陥 察虞霜 什杷球 (1000 = 1段, 15 = 0.015段)
// 極 姥繕端.
int score = 0;
char choose;
struct DDONG{
    int x, y, wait;
};
// 鉢檎税 働舛 是帖稽 戚疑背 爽澗 敗呪.
void gotoxy(int x, int y){
    COORD Pos = {x, y};//X,Y 疎妊澗 鉢檎 獄遁 庚切 漆税 伸引 楳.  
    /*COORD coord;
    coord.X=x;
    coord.Y=y;
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
	*/
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)/*嬬車 鉢檎 獄遁拭 企廃 輩級 */, Pos/*歯 朕辞 是帖研\
	走舛馬澗 COORD 姥繕端*/);//走舛吉 嬬車 鉢檎 獄遁拭辞 朕辞 是帖研 竺舛馬澗 敗呪 
}
// 徹脊径 敗呪
BOOL IsKeyDown(int Key){
	return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

// 惟績 敗呪.
int game(int level){
	system("Color F0");
    struct DDONG ddong[MAX_DDONG], user;
    int i, key, check = 1, evade = 0;
    int speed = 75 - level * LEVEL_SPEED;
    int count = 5 + level * LEVEL_COUNT;
    // 傾婚穣拭 琶推廃 極鯵呪
    int levelup = 20 + level * 20;
    // 極鯵呪 端滴. (置企葵聖 角走 省亀系 繕舛)
    if( count >= MAX_DDONG ) count = MAX_DDONG - 1;
    // 什杷球 端滴. (置社葵戚 10 左陥 拙走 省亀系 煽舛)
    if( speed < 10 ) speed = 10;
    // 政煽 獣拙 是帖.
    user.x = 12;
    user.y = 19;
    // 極 段奄鉢.
    for(i=0; i<count; i++)
    {
        ddong[i].x = rand() % 24 + 1;
        ddong[i].y = 3;
        ddong[i].wait = rand() % 20;
    }
    // 惟績 欠覗
    while(check)
    {
		score ++;
        // 什杷球拭 魚献 獣尻 走尻.
        Sleep(speed);
        // 鉢檎 走酔奄.
        system("cls");
        // 惟績 発井 窒径.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
        printf("[極杷馬奄惟績]\tLEVEL %d\n繊呪 : %d", level,score);
		gotoxy(0,user.y+3);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x00);
		printf("けけけけけけけけけけけけけ");
		printf("けけけけけけけけけけけけけ");
        // 紫寓 崇送績 坦軒
		if (IsKeyDown(VK_LEFT))
		{
			if(user.x > 1)
			{
				user.x--;
				if(IsKeyDown(VK_DOWN))
					user.x--;
			}
		}
		if (IsKeyDown(VK_RIGHT))
		{
			if(user.x <= 23)
			{
				user.x++;
				if(IsKeyDown(VK_DOWN) && user.x <= 22)
					user.x++;
			}
		}
        // 紫寓 窒径
        gotoxy(user.x, user.y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
        printf("し");
		gotoxy(user.x, user.y+1);
		printf("さ");
		gotoxy(user.x, user.y+2);
		printf("さ");
        // 極 崇送績 坦軒
        for(i=0; i<count; i++)
        {
            if( ddong[i].wait > 0 )
            {
                // 企奄獣娃 疑照 焼送 極聖 恭嬢襟軒走 省澗陥.
                ddong[i].wait--;
            }
            else
            {
                // 極聖 廃牒 焼掘稽 戚疑廃陥.
                ddong[i].y++;
                // 極戚 置馬舘拭 亀鐸 梅聖 凶 坦軒.
                if( ddong[i].y >= 22 )
                {
                    ddong[i].x = rand() % 24 + 1;
                    ddong[i].y = 3;
                    evade++;    // 杷廃 極鯵呪 朝錘闘
                }
                // 極 窒径
                gotoxy(ddong[i].x, ddong[i].y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf5);
                printf("��");
                // 中宜 端滴
                if( abs(ddong[i].x - user.x) < 2 && ddong[i].y == user.y )
                {
                    // 搾覗製 窒径.
                    printf("\a");
                    check = 0;
                }
            }
        }
        // 杷廃 極鯵呪亜 20鯵檎 傾婚穣.
        if(evade > levelup)
			return 1;
    }
    return 2;
}
// 五昔 敗呪
int main()
{
	system("mode con: cols=26 lines=25"); 
    int level = 1;

	system("Color 0A");
	gotoxy(6,1);
	printf("[極杷馬奄惟績]");
	gotoxy(6,11);
	printf("1: 惟績獣拙");
	gotoxy(6,12);
	printf("2:  亜戚球");
	gotoxy(6,13);
	printf("3:  魁鎧奄");
	gotoxy(0,24);
	printf(" ");

	choose = _getch();

	if (choose == '1')
	{
		choose == '0';
		while(1)
		{
			// 鉢檎 走酔奄.
			system("cls");
			system("Color 0A");
			// 傾婚 妊獣.
			gotoxy(6,1); printf("[極杷馬奄惟績]");
			gotoxy(9,11); printf("LEVEL %d", level); 
			// 獣娃 走尻 (1段 = 1000)
			Sleep(1500);
			// 惟績 獣拙.
			if( game(level) == 2 )
			{
				system("cls");
				gotoxy(8, 5);
				system("Color 0F");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0D);
				printf("惟績 神獄\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0A);
				gotoxy(8, 12);
				printf("傾婚 : %d", level);
				gotoxy(8, 13);
				printf("繊呪 : %d", score);
				gotoxy(8, 22);
				printf("1: 五昔五敢");
				gotoxy(8, 23);
				printf("2: 魁鎧奄");
				gotoxy(0, 24);
				printf(" ");

				do
				{
					choose = _getch();
					if (choose == '1')
						main();
					if (choose == '2')
						break;
				} while(1);
				break;
			}
			else
				level++;
		}
	}
	else if (choose == '2')
	{
		choose = '0';
		system("cls");
		system("Color 0A");
		gotoxy(6,1);
		printf("[極杷馬奄惟績]");
		gotoxy(10,8);
		printf("繕拙狛");
		gotoxy(3,10);
		printf("戚疑   : 疎,酔 鉢詞妊");
		gotoxy(3,11);
		printf("採什斗 : 焼掘 鉢詞妊");
		gotoxy(8,23);
		printf("1: 宜焼亜奄");
		gotoxy(0,24);
		printf(" ");

		while(choose != '1')
		{
			choose = _getch();
		}
		main();
	}
	else
		return 0;
}
