//2048
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "windows.h"
#include "winioctl.h"
using std::string;
using namespace std;
int array[4][4],r1,r2,score=0;

void design()
{
	//DESIGN
	initwindow(480,640,"2048! By: Navid Hasanzadeh");
	setbkcolor(7);
	cleardevice();	
	setcolor(8);
	settextstyle (4,0,5);
	outtextxy(10, 10, "2048");
	setcolor(BLACK);
	settextstyle (10,0,1);
	outtextxy(10, 50, "Join the numbers and get to the 2048 tile!");
	setcolor(BLACK);
	settextstyle (10,0,1);
	outtextxy(10, 620, "äÓÎå í 1.0 - 1394/01/06");
	//COMMENT
	setfillstyle(1,YELLOW);
	bar(20,80,460,110);
	setcolor(5);
	setbkcolor(YELLOW);
	settextstyle (8,0,1);
	outtextxy(105, 85, "     :D");
	//SCORE
	setfillstyle(1,6);
	bar(260,10,350,45);
	setcolor(WHITE);
	setbkcolor(6);
	settextstyle (8,0,1);
	outtextxy(277, 11, "SCORE");
	//BEST
	setfillstyle(1,6);
	bar(360,10,450,45);
	setcolor(WHITE);
	setbkcolor(6);
	settextstyle (8,0,1);
	outtextxy(382, 11, "BEST");
	//Box background
	setfillstyle(1,8);
	bar(15,130,465,600);
	//BOXES
	int dis=0,dis1=0;
	for (int i=0;i<4;i++)
	{
	for (int j=0;j<4;j++)
		{
			setfillstyle(1,7);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			dis+=10;
		}
		dis1+=10;
		dis=0;
	}

}
//Print Score
void dscore(int sr)
{
	char ch[100];
	setcolor(WHITE);
	setbkcolor(6);
	settextstyle (1,0,1);
	snprintf(ch, sizeof(ch), "%d", sr);
	outtextxy(263,28,ch);
}
//Print Best
void dbest(int best)
{

}
//Print the Matrix
void printm(int array[4][4])
{
int dis=0,dis1=0;
	char ch1[100];
	for (int i=0;i<4;i++)
	{
	for (int j=0;j<4;j++)
		{
			switch (array[i][j])
			{
			case 0:
			{
			setfillstyle(1,7);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			break;
		
			}
			case 2:
			{
			setfillstyle(1,6);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(6);
			settextstyle (4,0,5);
			
				if (i==r1&&j==r2)
		
				outtextxy(dis+35+100*j,dis1+170+100*i,"*2*");	  	  
				else
				outtextxy(dis+57+100*j,dis1+170+100*i,"2");			
			
			
			break;
			}
			case 4:
			{
			setfillstyle(1,2);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			
			setbkcolor(2);
			settextstyle (4,0,5);
				if (i==r1&&j==r2)
			
				outtextxy(dis+35+100*j,dis1+170+100*i,"*4*");	  	  
				else
				outtextxy(dis+57+100*j,dis1+170+100*i,"4");			
			
			break;
			}
			case 8:
			{
			setfillstyle(1,10);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(10);
			settextstyle (4,0,5);
			outtextxy(dis+57+100*j,dis1+170+100*i,"8");			
			break;
			}
			case 16:
			{
			setfillstyle(1,12);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(12);
			settextstyle (4,0,5);
			outtextxy(dis+40+100*j,dis1+170+100*i,"16");	 	 
			break;
			}
			case 32:
			{
			setfillstyle(1,4);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(4);
			settextstyle (4,0,5);
			outtextxy(dis+40+100*j,dis1+170+100*i,"32");	 	 
			break;
			}
			case 64:
			{
			setfillstyle(1,11);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(11);
			settextstyle (4,0,5);
			
			outtextxy(dis+40+100*j,dis1+170+100*i,"64");	 	 
			break;
			}
			case 128:
			{
			setfillstyle(1,13);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(13);
			settextstyle (4,0,4);
			
			outtextxy(dis+35+100*j,dis1+170+100*i,"128");	  	  
			break;
			}
			case 256:
			{
			setfillstyle(1,5);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(5);
			settextstyle (4,0,4);
			outtextxy(dis+35+100*j,dis1+170+100*i,"256");	  	  
			break;
			}
			case 512:
			{
			setfillstyle(1,1);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(1);
			settextstyle (4,0,4);
			outtextxy(dis+35+100*j,dis1+170+100*i,"512");	  	  
			break;
			}
			case 1024:
			{
			setfillstyle(1,9);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			setbkcolor(9);
			settextstyle (4,0,3);
			outtextxy(dis+30+100*j,dis1+170+100*i,"1024");	   	   
			break;
			}
			case 2048:
			{
			setfillstyle(1,14);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			settextstyle (4,0,3);
			setbkcolor(14);
			outtextxy(dis+30+100*j,dis1+170+100*i,"2048");	   	   
			break;
			}
			case 4096:
			{
			setfillstyle(1,14);
			bar(dis+25+100*j, dis1+140+100*i,dis+ 125+100*j, dis1+240+100*i);
			settextstyle (4,0,3);
			setbkcolor(14);
			outtextxy(dis+30+100*j,dis1+170+100*i,"4096");	   	   
			break;
			}
			}
			
		dis+=10;
		}
		dis1+=10;
		dis=0;
	}

}
void genrand()
{
	int num=0,home[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},t=0,homeN;
	//generate a random number
	srand (time(NULL));
	num=((rand()%2)+1)*2;
	//find an empty home
	for (int i=0;i<4;i++)
	{
		// Make home flags
	for (int j=0;j<4;j++)
		{	
		if (array[i][j]==0)
			{
				home[t]=(i+1)*10+(j+1);
				t++;
			}
		}
	}
	srand (time(NULL));
	homeN=(rand()%t);
	array[((home[homeN]-home[homeN]%10)/10)-1][(home[homeN]%10)-1]=num;
	r1=((home[homeN]-home[homeN]%10)/10)-1;
	r2=(home[homeN]%10)-1;	 
}
void m2zero ()
{
	for (int i=0;i<4;i++)
	for (int j=0;j<4;j++)
		array[i][j]=0;
	
}
void slidearray(char key)
{
	int khar,i,j;
	switch (key)
	{
		//Left
		case 'L':
		{
	
		for (khar=0;khar<6;khar++)
		{
		for (i=0;i<4;i++)
		for (j=0;j<3;j++)
			{
			   if (array[i][j]==0)
			   {
			   array[i][j]=array[i][j+1];
			   
			   array[i][j+1]=0;
		}
			}
		}
			break;
			
		}
		//Right
		case 'R':
		{
		//	cout << "Right";
		for (khar=0;khar<6;khar++)
		for (i=0;i<4;i++)
		for (j=3;j>0;j--)
			{
			   if (array[i][j]==0)
		{
			   array[i][j]=array[i][j-1];
			   array[i][j-1]=0;
		}
			}
			break;
		}
		//Up
		case 'U':
		{
		//	cout << "Up";
		for (int khar=0;khar<6;khar++)
		for (j=0;j<4;j++)
		for (i=0;i<3;i++)
			{
			   if (array[i][j]==0)
		{
			   array[i][j]=array[i+1][j];
			   array[i+1][j]=0;
		}
			}
			break;
		}
		//Down
		case 'D':
		{
			for (int khar=0;khar<6;khar++)
		for (j=0;j<4;j++)
		for (i=3;i>0;i--)
			{
			   if (array[i][j]==0)
		{
			   array[i][j]=array[i-1][j];
			   array[i-1][j]=0;
		}
			}
		//	cout << "Down";
			break;
		}
	}
	
}
void move(char key)
{
	int khar,i,j;
	switch (key)
	{
		//Left
		case 'L':
		{
	
	//	  for (khar=0;khar<2;khar++)
		{
		for (i=0;i<4;i++)
		for (j=0;j<3;j++)
			{

			   //{
			   		   slidearray('L');
	
	//	  	  	  }
				
			   if (array[i][j]==array[i][j+1])
			   {
			   array[i][j]+=array[i][j];			   
				score+=array[i][j];	   
			   array[i][j+1]=0;
			   		   slidearray('L');
	
				}
			}
		}
			break;
			
		}
		//Right
		case 'R':
		{
		//	cout << "Right";
	//	  for (khar=0;khar<2;khar++)
		for (i=0;i<4;i++)
		for (j=3;j>0;j--)
			{
					   	   slidearray('R');
			   if (array[i][j]==array[i][j-1])
		{
			   array[i][j]+=array[i][j-1];
				score+=array[i][j];		
			   array[i][j-1]=0;
			   	   slidearray('R');
		
		}
			}
			break;
		}
		//Up
		case 'U':
		{
		//	cout << "Up";
		//for (int khar=0;khar<2;khar++)
		for (j=0;j<4;j++)
		for (i=0;i<3;i++)
			{
			slidearray('U');
			   if (array[i][j]==array[i+1][j])
		{
			   array[i][j]+=array[i+1][j];
				score+=array[i][j];
			   array[i+1][j]=0;
			   	slidearray('U');
		
		}
			}
			break;
		}
		//Down
		case 'D':
		{
//	  	  for (int khar=0;khar<2;khar++)
		for (j=0;j<4;j++)
		for (i=3;i>0;i--)
			{
			slidearray('D');
			   if (array[i][j]==array[i-1][j])
		{
			   array[i][j]+=array[i-1][j];
				score+=array[i][j];			   
			   array[i-1][j]=0;
			   slidearray('D');

		}
			}
		//	cout << "Down";
			break;
		}
	}
}
int check(int ar1[4][4],int ar2[4][4])
{
for (int i=0;i<4;i++)
for (int j=0;j<4;j++)
if (ar1[i][j]!=ar2[i][j])
{
return 0;
}
return 1;
}
int main()
{
int keycode,ar1[4][4];
	design();
	m2zero();
	genrand();
	genrand();
	printm(array);
//enter
	enter:
for (int i=0;i<4;i++)
for (int j=0;j<4;j++)
ar1[i][j]=array[i][j];
	keycode=getch();
	keycode=getch();
	//up
	switch(keycode)
{
	case 72:
	{
		move('U');
		if (check(array,ar1)!=1)
		genrand();
		printm(array);
		dscore(score);	  	  
		break;
	}	 	 
	//down
	case 80:
	{
		move('D');
if (check(array,ar1)!=1)
genrand();
		printm(array);
	dscore(score);	  	  	
			break;
	}
	//left
	case 75:
	{
		move('L');
	if (check(array,ar1)!=1)
	genrand();
			printm(array);
	dscore(score);	  	  
			break;
	}
	//right
	case 77:
	{
		move('R');
	if (check(array,ar1)!=1)
	genrand();
			printm(array);
dscore(score);	  	  	
			break;
	}
}
	cout <<"\n";
 //enter arrow key
delay(10);
 goto enter;

	getch();
	closegraph();
	return 0;
}

