/*		BREAKOUT
	(Inspired by Atari Breakout)
*/
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#include<graphics.h>
#include<iomanip.h>
#include<dos.h>


struct rect
{
	int ulx, uly, lrx, lry;//Upper_Left(x,y),Lower_Right(x,y)
	int poly[8];
}ob[100], ob1[2], ob2[3], ob3[4];

void run_sp();
void assign_pos();
void main_menu();
void instructions();
void str_assign(char a[10], char b[10]);
void assign_pos(rect &ob);
void run_mp();
void pre();
void obstruct(rect ob);
void commence();
void exit_0();
void pause_game_sp();
void pause_game_mp();
void game_over();
void aim();
void highscores();

int i, j, l, k, x=0, y=0, t_c=0, cn=0, sp=0, mp=0, level=15, t_o=0, p_c=0, round=1;
int score_p1 = 0;
int score_p2 = 0;
char name_p1[100], name_p2[100];
static int t[50];

void instructions()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	int k;
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(100,10,"INSTRUCTIONS");
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(10,100,"SINGLEPLAYER");
	outtextxy(10,140,"Use the '>' and '<' keys to move the bar right/left.");
	outtextxy(10,160,"Press Escape Button to Pause the Game");
	outtextxy(10,180,"Your aim is to destroy all the obstructions.");
	outtextxy(10,320,"MULTIPLAYER");
	outtextxy(10,340,"Player 1 => Use the '>' and '<' keys to move the bar right/left.");
	outtextxy(10,360,"Player 2 => Use the 'A' and 'D' keys to move the bar right/left.");
	outtextxy(10,380,"Press Escape Button to Pause the Game");
	outtextxy(10,400,"Press any key to return to main menu...");
	getch();
	main_menu();
}

void str_assign(char a[30], char b[30])
{
	int i=0;
	a="";
	while(b[i]!='\0')
	{
		a[i]=b[i];
		i++;
	}
}
void exit_0()
{
	cout<<"\b";
	clrscr();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	cout<<"\b";
	clrscr();
	cleardevice();
	cout<<"\n\n\n\t\t\t\b\b\b\b\b\b\b\b\b\b\b\bExiting---";
	for(int i=0;i<3;i++)
	{
	delay(1000);
	cout<<" . ";
	}
	delay(1000);
	cleardevice();
	exit(0);
	closegraph();
	cleardevice();
	clrscr();
	cleardevice();
}

void commence()
{
	cleardevice();
int x,y,i;
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(rand());
 int c=150;
for(int e=0;e<15;e++)
 {
  for(int i=50;i<100;i++)
  {
    setcolor(3);
    settextstyle(SMALL_FONT, HORIZ_DIR, 10);
    outtextxy(x,y,"Loading...");
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(x+5,y+5,"Please Wait... ");
    circle(x,y,i);
    circle(x,y,c);
    c--;
    cleardevice();
  }
  }
  setcolor(6);
  settextstyle(SMALL_FONT, HORIZ_DIR, 10);
  settextjustify(x,y);
  outtextxy(x-70,y-60,"MADE");
  delay(500);
  outtextxy(x-70,y-20,"BY");
  delay(500);
  outtextxy(x-10,y-20,"UBERFLEX");
  delay(500);
  outtextxy(x-70,y+15,"STUDIOS");
  delay(1000);
  outtextxy(20,300,"Press any key to continue..");
  cleardevice();
  setcolor(11);
  settextstyle(GOTHIC_FONT, HORIZ_DIR, 30);
  outtextxy(20,150,"B");
  delay(400);
  outtextxy(100,150,"R");
  delay(400);
  outtextxy(180,150,"E");
  delay(400);
  outtextxy(260,150,"A");
  delay(400);
  outtextxy(340,150,"K");
  delay(400);
  outtextxy(420,150,"O");
  delay(400);
  outtextxy(500,150,"U");
  delay(400);
  outtextxy(580,150,"T");
  getch();
}

void pause_game_sp()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(100,10,"PAUSE MENU");
	int opt=0;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(10,100,"Enter - ");
	outtextxy(10,120,"1 Resume");
	outtextxy(10,140,"2 Restart");
	outtextxy(10,160,"3 To End Game");
	outtextxy(10,180,"4 To Exit");
	cin>>opt;
	switch(opt)
	{
		case 1 :
			run_sp();
			break;
		case 2 :        score_p1=0;
				t_c=1;
				run_sp();
				break;
		case 3 : game_over();
			break;
		case 4 :
			 exit_0();
			 break;
		default : pause_game_sp();
	}

}


void pause_game_mp()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(120,10,"PAUSE MENU");
	int opt=0;
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(10,100,"Enter - ");
	outtextxy(10,120,"1 Resume");
	outtextxy(10,140,"2 Restart");
	outtextxy(10,160,"3 To Quit");
	outtextxy(10,180,"4 To Exit");
	cin>>opt;
	switch(opt)
	{
		case 1 : run_mp();
			break;
		case 2 :        score_p1=score_p2=0;
					t_c=1;
				run_mp();
				break;
		case 3 : game_over();
			break;
		case 4 : cleardevice();
			 exit_0();
			 break;
		default : pause_game_mp();
	}

}

void main_menu()
{
	clrscr();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(120,10,"MAIN MENU");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(10,100,"Enter - ");
	outtextxy(10,120,"1 For Single Player Mode");
	outtextxy(10,140,"2 For Multiplayer Mode");
	outtextxy(10,160,"3 For Instructions");
	outtextxy(10,180,"4 For Highscores");
	outtextxy(10,200,"5 To Exit");
	int v=0;
	cin>>v;
	switch(v)
	{
		case 1: t_c=1;
			sp=1;
			score_p1=0;
			pre();
			break;
		case 2 :
			t_c=1;
			mp=1;
			score_p1=score_p2=0;
			pre();
			break;
		case 3 : instructions();
			break;
		case 5 :
			clrscr();
			cleardevice();
			exit_0();
		case 4 :highscores();
			break;
		default :
			main_menu();
	}
	getch();
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	cleardevice();
}

void game_over()
{
	clrscr();
	setbkcolor(BLACK);
	setcolor(GREEN);
	cleardevice();
	delay(500);
	fstream hscore_sp, hscore_mp;
	delay(100);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(200,10,"GAME OVER");
	delay(760);
	if(sp)
	{
	cout<<"\n\n\n\n\n\n\n\n\nSCORE - "<<score_p1;
	hscore_sp.open("SP_HighScores.txt", ios::app);
	hscore_sp<<name_p1<<endl<<score_p1<<endl;
	hscore_sp.close();
	sp=0;
	}
	else if(mp)
	{
	cout<<"\n\n\n\n\n\n\n\n\n\n\tSCORE - \n\t\t"<<name_p1<<" - "<<score_p1<<endl<<"\t\t"<<name_p2<<" - "<<score_p2;
	hscore_mp.open("MP_HighScores.txt", ios::app);
	hscore_mp<<name_p1<<endl<<score_p1<<endl<<name_p2<<endl<<score_p2;
	hscore_mp.close();
	mp=0;
	}
	delay(800);
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key to Return to Main Menu...";
	if(kbhit)
	{
		int kj=getch();
		if(kj)
		main_menu();
	}
}

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	setbkcolor(BLACK);
	setcolor(GREEN);
	commence();
	main_menu();
}

void assign_pos(rect &ob)
{
		ob.ulx = 100 + 20*(random(2000)%20);
		ob.uly = 100 + 10*(random(2000)%20);
		ob.lrx = ob.ulx + 20;
		ob.lry = ob.uly + 10;
}

void pre()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	if(sp)
	{
		cout<<"SINGLE PLAYER - \n\n";
		cout<<"Enter your user name - ";
		gets(name_p1);
		cout<<"Press Any key to continue...";
		int ki=getch();
		if(ki)
		run_sp();
	}
	else if(mp)
	{
		cout<<"\t\t\tMULTIPLAYER - \n";
		cout<<"Player 1\nEnter your user name - ";
		gets(name_p1);
		cout<<"Player 2\nEnter your user name - ";
		gets(name_p2);
		cout<<"Press Any key to continue...";
		int ki=getch();
		if(ki)
		run_mp();
	}

}


void obstruct(rect ob)
{
	int p =cn;
	if(t_c)
	{
		t[p]=1;
		t_c=0;
	}
	if(t[p])
	{
		setfillstyle(1, 6);
		fillpoly(4, ob.poly);
		rectangle(ob.ulx, ob.uly,ob.lrx,ob.lry);
		if(j==ob.uly-10)
		{
			if((i<=ob.lrx+10)&&(i>=ob.ulx-10))
				{
					k=1;
					t[p]=0;
					sound(10000);
					delay(1);
					nosound();
					score_p1++;
				}
		}
		if(j==ob.lry+10)
		{
			if((i<=ob.lrx+10)&&(i>=ob.ulx-10))
				{
					k=0;
					t[p]=0;
					sound(10000);
					delay(1);
					nosound();
					score_p1++;
				}
		}
		if(i==ob.ulx-10)
		{
			if((j<=ob.uly-10)&&(j<=ob.lry+10))
			{
				l=1;
				t[p]=0;
				sound(10000);
				delay(1);
				nosound();
				score_p1++;
			}
		}
		if(i==ob.lrx+10)
		{
			if((j>=ob.uly-10)&&(j<=ob.lry+10))
			{
				l=0;
				t[p]=0;
				sound(10000);
				delay(1);
				nosound();
				score_p1++;
			}
		}
	}

}

void run_sp()
{

	int u = 4;
	i=220 + x;
	j=390;
		int ch=0;
		setbkcolor(BLACK);
		setcolor(GREEN);
		k=l=0;
		while(ch!=27)
		{
			delay(60-level);
			cleardevice();
			cout<<"SCORE\ - "<<score_p1<<endl;
			if(t_c)
			{
				int o=0;
				while(!o)
				{
					for( cn=0;cn<level;cn++)
						assign_pos(ob[cn]);
					for(cn=0;cn<level;cn++)
					{
						for(int k=1;k<level;k++)
						{
							if(!((ob[cn].ulx==ob[k].ulx)&&(ob[cn].uly==ob[k].uly)))
									o=1;
						}
					}

				}

			}
			if(t_c)
			for(int f=0;f<30;f++)
					t[f]=1;

			line(100,100,100,400);//BOX
			line(500,100,500,400);
			line(100,100,500,100);

			//BALL
			setfillstyle(1,14);
			fillellipse(i, j, 10, 10);

			for( cn=0;cn<level;cn++)
				obstruct(ob[cn]);

			//BAR
			int bar[8] = {200+x, 400, 240+x, 400, 200+x, 410, 240+x, 410};
			setfillstyle(1, 6);
			fillpoly(4, bar);

			if(j==110)//Bounce
			{
				k=0;
				sound(19000);
				delay(1);
				nosound();
			}
			if(j==390)
			{
				if((i>=190+x)&&(i<=250+x))
				{
					k=1;
					sound(19000);
					delay(1);
					nosound();
				}
			}
			if(k)
				j-=5;
			else
				j+=5;

			if(i==110)
			{
				l=0;
				sound(19000);
				delay(1);
				nosound();
			}
			if(i==490)
			{
				l=1;
				sound(19000);
				delay(1);
				nosound();
			}
			if(l)
				i-=5;
			else
				i+=5;

			if(kbhit())
			{
				ch=getch();
				switch(ch)
				{
				case 44 :
						if(200+x>=120)
						x-=20;
						break;
				case 46 :
					if(240+x<=480)
						x+=20;
						break;
				case 32 : y+=20;
						break;
				case 13 : y-=20;
						break;
				case 27 : pause_game_sp();
						break;
				default :
						x+=0;
				}
			}
			else
			{
				x+=0;
				y+=0;
			}

			if((u<1)&&(j>400))
			game_over();
			if((j>400)&&(u>0))
			{
				clrscr();
				cleardevice();
				setbkcolor(RED);
				gotoxy(200,200);
				if(u>1)
				{
					gotoxy(100,100);
					cout<<"\n\n\n\t\t\t\t"<<u<<" Lives Left.";
				}
				else
				{
					gotoxy(100,100);
					cout<<"\n\n\n\t\t\t\t"<<u<<" Life Left.";
				}
				delay(500);
				setbkcolor(BLACK);
				u-=1;
				i=220 + x;
				j=390;
			}

			int ak=1;
			for(int ad=0;ad<level;ad++)
			{
				if(t[ad]!=0)
					ak=0;
			}
			if(ak)
			{
				clrscr();
				cleardevice();
				setbkcolor(RED);
				cout<<"\n\n\n\t\t\t\t"<<"LEVEL UP";
				t_c=1;
				level+=5;
				delay(500);
				setbkcolor(BLACK);
				i=220 + x;
				j=390;
			}
		}
}


void run_mp()
{
	cleardevice();
	int ch=0;
	int u1=3, u2=3;
	setbkcolor(BLACK);
	setcolor(GREEN);
	int i, j, l, x=0, y=0;
	i=220+x;
	int k=l=0;
	j=390;
	while(ch!=27)
	{
		delay(45-(10*round));
		cleardevice();
		cout<<name_p1<<" - "<<score_p1<<endl;
		cout<<name_p2<<" - "<<score_p2<<endl;
		line(500,100,500,400);//FRAME
		line(100,100,100,400);

		//BALL
			setfillstyle(1,14);
			fillellipse(i, j, 10, 10);

		 switch(round)
		{
			case 1:
					line(250, 250, 350, 250);
					
					if((i>=240)&&(i<=360))
					{
						if(j==240)
						{
							k=1;
							sound(19000);
							delay(1);
							nosound();
						}
						if(j==260)
						{
							k=0;
							sound(19000);
							delay(1);
							nosound();
						}
					}
					
					break;
			case 2:
					line(150, 250, 250, 250);
					
					if((i>=140)&&(i<=260))
					{
						if(j==240)
						{
							k=1;
							sound(19000);
							delay(1);
							nosound();
						}
						if(j==260)
						{
							k=0;
							sound(19000);
							delay(1);
							nosound();
						}
					}

					line(350, 250, 450, 250);
					
					if((i>=340)&&(i<=460))
					{
						if(j==240)
						{
							k=1;
							sound(19000);
							delay(1);
							nosound();
						}
						if(j==260)
						{
							k=0;
							sound(19000);
							delay(1);
							nosound();
						}
					}

					break;
			case 3:
					line(200,200,200,300);
					if((j<=190)&&(j>=310))
					{
						if(i==190)
						{
							l=1;
							sound(19000);
							delay(1);
							nosound();
						}	
						else if(i==210)
						{
							l=0;
							sound(19000);
							delay(1);
							nosound();
						}		
					}
					line(400,200,400,300);					
					if((j<=190)&&(j>=310))
					{
						if(i==390)
						{
							l=1;
							sound(19000);
							delay(1);
							nosound();
						}	
						else if(i==410)
						{
							l=0;
							sound(19000);
							delay(1);
							nosound();
						}		
					}
					break;
			default:
					game_over();
		}

		 //BARS
		int bar1[8] = {200+x, 400, 240+x, 400, 240+x, 410, 200+x, 410};
			setfillstyle(1, 6);
			fillpoly(4, bar1);
		int bar2[8] = {200+y, 90, 240+y, 90, 240+y, 100, 200+y, 100};
			setfillstyle(1, 6);
			fillpoly(4, bar2);

		if(j==110)//Bounce
		{
			if((i>=190+y)&&(i<=250+y))
			{
			k=0;
			score_p2+=5;
			sound(19000);
			delay(1);
			nosound();
			}
		}
		if(j==390)
		{
			if((i>=190+x)&&(i<=250+x))
			{
			k=1;
			score_p1+=5;
			sound(19000);
			delay(1);
			nosound();
			}
		}
		if(k)
			j-=5;
		else
			j+=5;

		if(i==110)
		{
			l=0;
			sound(19000);
			delay(1);
			nosound();
		}
		if(i==490)
		{
			l=1;
			sound(19000);
			delay(1);
			nosound();
		}
		if(l)
			i-=5;
		else
			i+=5;


		if(kbhit())
		{
			ch=getch();
			switch(ch)
			{
				case 44 :       if(200+x>=120)
						x-=20;
						break;
				case 46 :       if(240+x<=480)
						x+=20;
						break;
				case 100 :      if(240+y<=480)
						y+=20;
						break;
				case 97 :       if(200+y>=120)
						y-=20;
						break;
				case 27 : pause_game_mp();
						break;
				default :
						x+=0;
			}
		}
		else
		{
			x+=0;
			y+=0;
		}




		if(((j>400)||(j<100))&&((u1<=0)||(u2<=0)))
		{
			sound(12000);
			cleardevice();
			delay(50);
			nosound();
			game_over();
		}

		if((j>400)&&(u1>0))
			{
				clrscr();
				cleardevice();
				setbkcolor(RED);
				gotoxy(200,200);
				if(u1>1)
				{
					gotoxy(100,100);
					cout<<"\n\n\n\t\t\t\t"<<name_p1<<" - "<<u1<<" Lives Left.";
				}
				else
				{
					gotoxy(100,100);
					cout<<"\n\n\n\t\t\t\t"<<name_p1<<" - "<<u1<<" Life Left.";
				}
				delay(500);
				setbkcolor(BLACK);
				u1-=1;
				score_p1-=2;
				i=220 + x;
				j=390;
			}

		if((j<100)&&(u2>0))
			{
				clrscr();
				cleardevice();
				setbkcolor(RED);
				gotoxy(200,200);
				if(u2>1)
				{
					gotoxy(100,100);
					cout<<"\n\n\n\t\t\t\t"<<name_p2<<" - "<<u2<<" Lives Left.";
				}
				else
				{
					gotoxy(100,100);
					cout<<"\n\n\n\t\t\t\t"<<name_p2<<" - "<<u2<<" Life Left.";
				}
				delay(500);
				setbkcolor(BLACK);
				u2-=1;
				score_p2-=2;
				i=220 + y;
				j=110;
			}

			if((score_p1>=50*round)||(score_p2>=50*round))
			{
				clrscr();
				cleardevice();
				setbkcolor(RED);
				cout<<"\n\n\n\t\t\t\t"<<"ROUND "<<++round;
				t_c=1;
				delay(500);
				setbkcolor(BLACK);
			}
	}
	exit(0);
}
void highscores()
{
	clrscr();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(GREEN);
	delay(100);
	int p, q, pos, large, temp1;
	char temp2[30];
	ifstream ffile;
	ffile.open("SP_Highscores.txt");
	char pname[10][30];
	int pscore[10];
	for(p=0;p<5;p++)
	{
		ffile>>pname[p]>>pscore[p];
	}
	for(p=0;p<5;p++)
	{
		large = pscore[p];
		pos = p;
		for(q=p+1;q<5;q++)
		{
			if(large<pscore[q])
			{
				large=pscore[q];
				pos=q;
			}
		}
		str_assign(temp2,pname[p]);
		str_assign(pname[p],pname[pos]);
		str_assign(pname[pos],temp2);
		temp1=pscore[p];
		pscore[p]=pscore[pos];
		pscore[pos]=temp1;
	}
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(100,10,"HIGHSCORES");
	cout<<"\n\n\n\n\n\n\n\n";
	for(p=0;p<5;p++)
		cout<<p+1<<". "<<pname[p]<<" - "<<pscore[p]<<endl;
	cout<<"\n\n\tPress any key to return.";
	if(kbhit)
	{
		int kj=getch();
		if(kj)
		{	
			cleardevice();
			clrscr();
			main_menu();
		}
	}	
}
