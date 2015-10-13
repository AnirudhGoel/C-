//Including Header Files
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<timer.h>


void road()	//Road Making Function
{
	bar((getmaxx() / 2)-120,0,(getmaxx() / 2)+120,getmaxy());
}
void start()	//Game Initializing Function
{
	int x,y;
	setfillstyle(SOLID_FILL,GREEN);
	bar((getmaxx() / 2) - 15, getmaxy() - 50,
	    (getmaxx() / 2) + 15, getmaxy() - 10);
	delay(1000);
	for(y=0;y<=(getmaxy() / 2) - 100;y++)
	{
		delay(10);
		cleardevice();
		setbkcolor(WHITE);
		bar((getmaxx() / 2) - 15, getmaxy() - 50 - y,
		    (getmaxx() / 2) + 15, getmaxy() - 10 - y);
	}
}

void move()	//Moving the Player and Obstacles
{
	char i=0;
	int y=0;
	int p;		//Position of Obstacles variable
	static int x=0; //To initialize the value of x only once
	time_t startTime, curTime;

	while(y<=getmaxy()+310)
	{
	y=y+7;
	cleardevice();
	setcolor(5);
	circle((getmaxx()/2)-200,y-460,20);
	setcolor(2);
	circle((getmaxx()/2)-100,y-340,20);
	setcolor(3);
	circle((getmaxx()/2),y-230,20);
	setcolor(4);
	circle((getmaxx()/2)+100,y-180,20);
	setcolor(6);
	circle((getmaxx()/2)+200,y,20);
	time(&startTime);
	do
	{
		i=getch();
		time(&curTime);
	}
	while((curTime - startTime) < 0);



	if(i=='a')      //To move left
	{
		x=x-5;
		setfillstyle(SOLID_FILL,GREEN);
		bar((getmaxx() / 2) - 15 + x, getmaxy() +50-(getmaxy() / 2),
		    (getmaxx() / 2) + 15 + x, getmaxy() +90-(getmaxy() / 2));
	}
	if(i=='d')	//To move right
	{
		x=x+5;
		setfillstyle(SOLID_FILL,GREEN);
		bar((getmaxx() / 2) - 15 + x, getmaxy() +50-(getmaxy() / 2),
		    (getmaxx() / 2) + 15 + x, getmaxy() +90-(getmaxy() / 2));
	}
	getch();
	}
}


void main()
{
	int gd=DETECT,gm;
	char i;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	road();
	start();
	move();
	getch();
	closegraph();
}
