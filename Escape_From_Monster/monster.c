#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define N 10

char map[N][N] =
{
	"##########",
	"#        #",
	"#   ##   #",
	"#   ##   #",
	"#        #",
	"# ^ ^^   #",
	"#     ####",
	"#      a #",
	"#      Y #",
	"##########",
};


int ny = 1;
int nx = 1;
int hp=100;
int flag=0;
int my = 1;
int mx = 4;
int ditY[5] = {0,-1,1,0,0};
int ditX[5] = {0,0,0,-1,1};

void print()
{
	clear();
	for (int y=0; y<N; y++)
	{
		for (int x= 0; x<N; x++)
		{
			if(y == ny && x == nx) printw("🛴");
			else if(y == my && x == mx) printw("🚑");
			else if(map[y][x] == '#') printw("🔒");
			else if(map[y][x] == 'a') printw("🎃");
			else if(map[y][x] == 'Y') printw("🏡");
			else if(map[y][x] == '^') printw("🌧 ");
			else printw("%c%c",map[y][x], map[y][x]);
		}
		printw("\n");
	}
	printw("HP : %d\n", hp);
	refresh();
}
void mvMon(){
	int a = rand() % 5;
	int nextMy = my + ditY[a];
	int nextMx = mx + ditX[a];
	if(map[nextMy][nextMx] == '#') return;
	my = nextMy;
	mx = nextMx;
	return;
}
int main()
{
	setlocale(LC_CTYPE, "ko_KR.utf8");
	initscr();
	srand(time(NULL));

	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	int sec = 0;
	while(1)
	{
		print();
		
		int ch = getch();
		if (ch ==ERR) ch=0;
		if (ch ==KEY_LEFT)
		{
			flag=0;
			if(map[ny][nx-1]=='#') continue;
			nx--;
		}
		else if(ch ==KEY_RIGHT)
		{
			flag=0;
			if(map[ny][nx+1]=='#') continue;
			nx++;
		}
		else if(ch == KEY_UP)
		{
			flag=0;
			if(map[ny-1][nx]=='#') continue;
			ny--;
		}
		else if(ch ==KEY_DOWN)
		{
			flag=0;
			if(map[ny+1][nx]=='#') continue;
			ny++;
		}
		if (map[ny][nx] =='^'&& flag==0)
		{
			hp-=10;
			flag=1;
		}

		if((ny == my && nx == mx) || hp==0)
		{
			sleep(0.5);
			clear();
			mvprintw(10,10,"GAME OVER");
			refresh();
			sleep(3);
			break;
		}
		if (map[ny][nx] =='Y')
		{
			print();
			usleep(500*1000);
			clear();
			mvprintw(10,10,"WIN (%d)" ,hp);
			refresh();
			sleep(1);
			break;
		}
		if (map[ny][nx] =='a')
		{
			hp=100;
			map[ny][nx]=' ';
		}
		
		if(sec == 200){
			mvMon();
			sec = 0;
		}

		usleep(1000);
		sec++;

	}

	getch();
	endwin();
	return 0;
}

