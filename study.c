#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h> 
//惟績 発井 痕呪
#define MAX_DDONG		100 // 極税 置企 鯵呪

#define LEVEL_COUNT		3 // 傾婚原陥 潅嬢劾 極 鯵呪 
#define LEVEL_SPEED		15// 傾婚原陥 察虞霜 什杷球 (1000腔軒室珍球 =1段, 15腔軒室珍球=0.015段)
//極 姥繕端
int score=0;
char choose;
struct DDONG{
	int x,y, wait;
}; 
//鉢檎税 働舛 是帖稽 戚疑背爽澗 敗呪
void gotoxy(int x, int y){
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
} 
//徹脊径 敗呪 (????)
BOOL IsKeyDown(int Key){
	return ((GetAsyncKeyState(Key)&0x8000) != 0);//徹左球税 徹亜 喚携澗走研 端滴馬澗 敗呪
	/*硲窒吉 獣繊拭辞 徹 雌殿研 繕紫馬食, 五獣走 泥研 暗帖走 省壱
郊稽 軒渡聖 背 爽糠稽 徹 脊径聖 郊稽 坦軒背 匝 呪亜 赤陥.

GetKeyState() 敗呪澗 硲窒吉 獣繊拭辞 五獣走 泥研 暗帖悟,
五獣走 降持 板税 雌殿研 軒渡馬惟 鞠糠稽, 徹左球 五獣走 坦軒 欠鴇鎧拭辞 紫遂背醤 廃陥.

惟績引 旭戚 徹 脊径拭 郊稽 鋼誓聖 背 操醤 馬澗 覗稽益轡拭辞澗
GetAsyncKeyState()敗呪研 紫遂馬澗 畷戚 疏陥.*/

} 
//惟績 敗呪
int game(int level){
	system("Color F0");
	struct DDONG ddong[MAX_DDONG], user;
	int i, key, check =1, evade = 0;
	int speed =75-level * LEVEL_SPEED;
	int count = 5 + level * LEVEL_COUNT;// 極鯵呪? 
	//傾婚穣拭 琶推廃 極鯵呪
	int levelup=20 + level*20;
	//極鯵呪 端滴 (置企葵聖 角走 省亀系 繕舛)
	if(count>= MAX_DDONG) count =MAX_DDONG-1;
	//什杷球 端滴 (置社葵戚 10 左陥 拙走 省亀系 繕舛)
	if(speed<10) speed = 10;
	//政煽 獣拙 是帖
	user.x = 12;
	user.y = 19;
	//極段奄鉢
		for(i=0; i<count; i++){
		srand(time(NULL));
		ddong[i].x = rand() % 24 + 1;// 1~24 鋼発 
		ddong[i].y = 3;
		ddong[i].wait = rand() % 20; //0~19 鋼発 
	} 
	//惟績 欠覗
	while(check){
	score++;
	//什杷球拭 魚献 獣尻 走尻
	sleep(speed);// ?? sleep(x) x拭 級嬢亜澗 依?
	system("cls");// 鉢檎 走酔奄 
	//惟績 発井 窒径	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xf0);
	// SetConsoleTextAttribute(GetStdHandle//妊層輩級聖 鋼発馬澗 敗呪(STD_OUTPUT_HANDLE//戚耕 #define 吉 析曽税 ID),事雌);
	/* 事雌 : 古鯵痕呪 展脊 WORD 
	typedef unsigned short WORD=> 聡 舛呪葵聖 隔生檎喫
	short莫=>2byte,16bit 16搾闘(0000 0000 1111 1111=0x00FF)掻 及税 8搾闘拭 爽鯉背醤鞠澗汽 
	16搾闘掻 固及税 4搾闘澗 越切税 事雌, 益蒋税 4鯵税 搾闘澗 壕井事聖 走舛敗
	聡 恥 16亜走税 事雌税 壕井引 越切稽 走舛 亜管, 
	*/ 
	printf("[極杷馬奄惟績]\tLEVEL %d\n繊呪 : %d", level,score); 
	gotoxy(0, user.y+3); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x00);
	printf("けけけけけけけけけけけけけ");
	printf("けけけけけけけけけけけけけ");
    // 紫寓 崇送績 坦軒
/*VK澗 Virtual Key税 鉦切戚壱 //VK_UP (是楕 号狽徹),VK_LEFT (図楕 号狽徹),VK_DOWN (焼掘楕 号狽徹),VK_RIGHT (神献楕 号狽徹)
VK_SPACE (什凪戚什 郊)*/
	if (IsKeyDown(VK_LEFT)){
		if(user.x > 1){
			user.x--;
			if(IsKeyDown(VK_DOWN))
				user.x--;
		}
	} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
} 
