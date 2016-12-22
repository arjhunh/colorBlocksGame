#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
int a[8][8],b[8][8];
int row,col; //user's input
int r1,c1;
int uf,df,rf,lf; //flags for checking move
char dir; //user's input
int opt;  //user's input
int x,y;   //computer's version (0 - 7)
long score;
char score_c[20]; //score in string

void menu1();
void menu2();
void menu3();
void game();
void check_move();
void after_move();
void col_fill();
void first_page()
{
		settextstyle(3,0,5);
		for(int i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,i,"C");
			delay(10);
		}

		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,i,"o");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,i,"L");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,i,"o");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,i,"r");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,i,"B");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,i,"L");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,i,"o");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,i,"c");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,i,"k");
			delay(5);
		}
		for(i=0;i<100;i++)
		{
			cleardevice();
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,i,"s");
			delay(5);
		}
		for(i=140;i<=390;i++)
		{
			line(140,150,i,150);
			delay(5);
		}
		for(int j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			settextstyle(1,0,j);
			outtextxy(400,150,"B");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			settextstyle(3,0,j);
			outtextxy(420,150,"y");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			settextstyle(3,0,j);
			outtextxy(400,200,"A");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			outtextxy(400,200,"A");
			settextstyle(3,0,j);
			outtextxy(430,200,"r");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			outtextxy(400,200,"A");
			outtextxy(430,200,"r");
			settextstyle(3,0,j);
			outtextxy(450,200,"j");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			outtextxy(400,200,"A");
			outtextxy(430,200,"r");
			outtextxy(450,200,"j");
			settextstyle(3,0,j);
			outtextxy(460,200,"h");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			outtextxy(400,200,"A");
			outtextxy(430,200,"r");
			outtextxy(450,200,"j");
			outtextxy(460,200,"h");
			settextstyle(3,0,j);
			outtextxy(480,200,"u");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			outtextxy(400,200,"A");
			outtextxy(430,200,"r");
			outtextxy(450,200,"j");
			outtextxy(460,200,"h");
			outtextxy(480,200,"u");
			settextstyle(3,0,j);
			outtextxy(500,200,"n");
			delay(50);
		}
		for(j=1;j<=5;j++)
		{
			cleardevice();
			settextstyle(3,0,5);
			outtextxy(150,100,"C");
			outtextxy(170,100,"o");
			outtextxy(190,100,"L");
			outtextxy(210,100,"o");
			outtextxy(230,100,"r");
			outtextxy(270,100,"B");
			outtextxy(290,100,"L");
			outtextxy(310,100,"o");
			outtextxy(330,100,"c");
			outtextxy(350,100,"k");
			outtextxy(370,100,"s");
			line(140,150,390,150);
			outtextxy(400,150,"B");
			outtextxy(420,150,"y");
			outtextxy(400,200,"A");
			outtextxy(430,200,"r");
			outtextxy(450,200,"j");
			outtextxy(460,200,"h");
			outtextxy(480,200,"u");
			outtextxy(500,200,"n");
			settextstyle(3,0,j);
			outtextxy(540,200,"H");
			delay(50);
		}
		outtextxy(50,350,"LOADING....");
		circle(450,350,51);
		for(i=90;i<=360;i++)
		{
			setcolor(BLUE);
			setfillstyle(1,BLUE);
			pieslice(450,350,90,i,50);
			delay(15);
		}
		for(i=0;i<=90;i++)
		{
			setfillstyle(1,BLUE);
			pieslice(450,350,0,i,50);
			delay(15);
		}
		setcolor(WHITE);
		settextstyle(3,0,3);
		outtextxy(150,420,"Press any key to continue..");
}
void layout()
{
	rectangle(230,40,630,440);
	line(280,40,280,440);
	line(330,40,330,440);
	line(380,40,380,440);
	line(430,40,430,440);
	line(480,40,480,440);
	line(530,40,530,440);
	line(580,40,580,440);

	line(230,90,630,90);
	line(230,140,630,140);
	line(230,190,630,190);
	line(230,240,630,240);
	line(230,290,630,290);
	line(230,340,630,340);
	line(230,390,630,390);
	settextstyle(3,0,3);
	outtextxy(250,5,"1");
	outtextxy(300,5,"2");
	outtextxy(350,5,"3");
	outtextxy(400,5,"4");
	outtextxy(450,5,"5");
	outtextxy(500,5,"6");
	outtextxy(550,5,"7");
	outtextxy(600,5,"8");

	outtextxy(200,50,"1");
	outtextxy(200,100,"2");
	outtextxy(200,150,"3");
	outtextxy(200,200,"4");
	outtextxy(200,250,"5");
	outtextxy(200,300,"6");
	outtextxy(200,350,"7");
	outtextxy(200,400,"8");

}
void def_col_array()  //assigning random values to the array
{
	randomize();
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			b[i][j]=random(5)+1;
		}
	}
}
void ini_repeat() //checking for repetition
{
	randomize();
	for(int i=0;i<8;i++)
	{
		for(int j=2;j<8;j++)
		{
			do
			{
				if((b[i][j-2]==b[i][j-1])&&(b[i][j-1]==b[i][j]))
				b[i][j]=random(5)+1;
			}while((b[i][j-2]==b[i][j-1])&&(b[i][j-1]==b[i][j]));
		}
	}
	for(int j=0;j<8;j++)
	{
		for(int i=2;i<8;i++)
		{
			do
			{
				if((b[i-2][j]==b[i-1][j])&&(b[i-1][j]==b[i][j]))
				b[i][j]=random(5)+1;
			}while((b[i-2][j]==b[i-1][j])&&(b[i-1][j]==b[i][j]));
		}
	}
}

void col_fill()   //filling the blocks with colours
{
	int cox,coy;
	cox=240;
	coy=50;
	for(int i=0;i<8;i++)
	{
		cox=240;
		for(int j=0;j<8;j++)
		{
			if(b[i][j]==1)
			{
				setfillstyle(1,RED);
				floodfill(cox,coy,WHITE);
			}
			else if(b[i][j]==2)
			{
				setfillstyle(1,BLUE);
				floodfill(cox,coy,WHITE);
			}
			else if(b[i][j]==3)
			{
				setfillstyle(1,MAGENTA);
				floodfill(cox,coy,WHITE);
			}
			else if(b[i][j]==4)
			{
				setfillstyle(1,CYAN);
				floodfill(cox,coy,WHITE);
			}
			else if(b[i][j]==5)
			{
				setfillstyle(1,GREEN);
				floodfill(cox,coy,WHITE);
			}
			cox=cox+50;
		}
		coy=coy+50;
	}
}
void user_input()
{
	gotoxy(1,1);
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	cout<<endl;
	cout<<"                       ";
	gotoxy(1,1);
	do
	{
	do
	{
		cout<<"\nEnter the row : ";
		cin>>row;
		if(row==15)
		{
			menu1();
		}
	}while(((row>8)||(row<=0)));
	do
	{
		cout<<"\nEnter the column : ";
		cin>>col;
		if(col==15)
		{
			menu1();
		}
	}while(((col>8)||(col<=0)));
	do
	{
		cout<<"\nEnter the direction : ";
		cin>>dir;
		if(dir=='q')
		{
			menu1();
		}
		tolower(dir);
	}while(((dir!='u')&&(dir!='d')&&(dir!='l')&&(dir!='r')));
	if((((col==1)&&(dir=='l'))||((col==8)&&(dir=='r')))||(((row==1)&&(dir=='u'))||((row==8)&&(dir=='d'))))
	{
		cout<<"\nInvalid move\n";
		getch();
		gotoxy(1,1);
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		cout<<endl;
		cout<<"                       ";
		gotoxy(1,1);
	}
	}while((((col==1)&&(dir=='l'))||((col==8)&&(dir=='r')))||(((row==1)&&(dir=='u'))||((row==8)&&(dir=='d'))));
}
void assign_temp()  //assigning the temp variable to check moves
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			a[i][j]=b[i][j];
		}
	}
}
void check_move()   //move is possible or not if yes continues
{
	int x=row-1;
	uf=-1;df=-1;lf=-1;rf=-1;
	int y=col-1;
	if(dir=='u')
	{
		int t=a[x][y];
		a[x][y]=a[x-1][y];
		a[x-1][y]=t;
		if(((a[x-1][y]==a[x-1][y-1])&&(a[x-1][y]==a[x-1][y+1]))||((a[x-1][y]==a[x-1][y-1])&&(a[x-1][y]==a[x-1][y-2]))||((a[x-1][y]==a[x-1][y+1])&&(a[x-1][y]==a[x-1][y+2]))||((a[x-1][y]==a[x-2][y])&&(a[x-1][y]==a[x-3][y])))
		{
			uf=1;
			t=b[x][y];
			b[x][y]=b[x-1][y];
			b[x-1][y]=t;
			r1=x-1;
			c1=y;
			score+=50;
			after_move();
			cleardevice();
			layout();
			col_fill();
		}
		if(((a[x][y]==a[x][y-1])&&(a[x][y]==a[x][y+1]))||((a[x][y]==a[x][y-1])&&(a[x][y]==a[x][y-2]))||((a[x][y]==a[x][y+1])&&(a[x][y]==a[x][y+2]))||((a[x][y]==a[x-1][y])&&(a[x][y]==a[x-2][y])))
		{
			if(uf==1)
			{
				r1=x;
				c1=y;
				score+=50;
				after_move();
				cleardevice();
				layout();
				col_fill();
			}
		}
	}
	else if(dir=='d')
	{
		int t=a[x][y];
		a[x][y]=a[x+1][y];
		a[x+1][y]=t;
		if(((a[x+1][y]==a[x+1][y-1])&&(a[x+1][y]==a[x+1][y+1]))||((a[x+1][y]==a[x+1][y-1])&&(a[x+1][y]==a[x+1][y-2]))||((a[x+1][y]==a[x+1][y+1])&&(a[x+1][y]==a[x+1][y+2]))||((a[x+1][y]==a[x+2][y])&&(a[x+1][y]==a[x+3][y])))
		{
			df=1;
			t=b[x][y];
			b[x][y]=b[x+1][y];
			b[x+1][y]=t;
			r1=x+1;
			c1=y;
			score+=50;
			after_move();
			cleardevice();
			layout();
			col_fill();
		}
		if(((a[x][y]==a[x][y-1])&&(a[x][y]==a[x][y+1]))||((a[x][y]==a[x][y-1])&&(a[x][y]==a[x][y-2]))||((a[x][y]==a[x][y+1])&&(a[x][y]==a[x][y+2]))||((a[x][y]==a[x+1][y])&&(a[x][y]==a[x+2][y])))
		{
			if(df==1)
			{
				r1=x;
				c1=y;
				score+=50;
				after_move();
				cleardevice();
				layout();
				col_fill();
			}
		}

	}
	else if(dir=='l')
	{
		int t=a[x][y];
		a[x][y]=a[x][y-1];
		a[x][y-1]=t;
		if(((a[x][y-1]==a[x-1][y-1])&&(a[x][y-1]==a[x+1][y-1]))||((a[x][y-1]==a[x-1][y-1])&&(a[x][y-1]==a[x-2][y-1]))||((a[x][y-1]==a[x+1][y-1])&&(a[x][y-1]==a[x+2][y-1]))||((a[x][y-1]==a[x][y-2])&&(a[x][y-1]==a[x][y-3])))
		{
			lf=1;
			t=b[x][y];
			b[x][y]=b[x][y-1];
			b[x][y-1]=t;
			r1=x;
			c1=y-1;
			score+=50;
			after_move();
			cleardevice();
			layout();
			col_fill();
		}
		if(((a[x][y]==a[x-1][y])&&(a[x][y]==a[x+1][y]))||((a[x][y]==a[x-1][y])&&(a[x][y]==a[x-2][y]))||((a[x][y]==a[x+1][y])&&(a[x][y]==a[x+2][y]))||((a[x][y]==a[x][y-1])&&(a[x][y]==a[x][y-2])))
		{
			if(lf==1)
			{
				r1=x;
				c1=y;
				score+=50;
				after_move();
				cleardevice();
				layout();
				col_fill();
			}
		}

	}
	else if(dir=='r')
	{
		int t=a[x][y];
		a[x][y]=a[x][y+1];
		a[x][y+1]=t;
		if(((a[x][y+1]==a[x-1][y+1])&&(a[x][y+1]==a[x+1][y+1]))||((a[x][y+1]==a[x-1][y+1])&&(a[x][y+1]==a[x-2][y+1]))||((a[x][y+1]==a[x+1][y+1])&&(a[x][y+1]==a[x+2][y+1]))||((a[x][y+1]==a[x][y+2])&&(a[x][y+1]==a[x][y+3])))
		{
			rf=1;
			t=b[x][y];
			b[x][y]=b[x][y+1];
			b[x][y+1]=t;
			r1=x;
			c1=y+1;
			score+=50;
			after_move();
			cleardevice();
			layout();
			col_fill();
		}
		if(((a[x][y]==a[x-1][y])&&(a[x][y]==a[x+1][y]))||((a[x][y]==a[x-1][y])&&(a[x][y]==a[x-2][y]))||((a[x][y]==a[x+1][y])&&(a[x][y]==a[x+2][y]))||((a[x][y]==a[x][y+1])&&(a[x][y]==a[x][y+2])))
		{
			if (rf==1)
			{
				r1=x;
				c1=y;
				score+=50;
				after_move();
				cleardevice();
				layout();
				col_fill();
			}

		}

	}
}
void after_move() //assigning random values after move is over
{
	randomize();
	if(dir=='u')
	{
		if((b[r1][c1]==b[r1][c1-1])&&(b[r1][c1]==b[r1][c1+1]))
		{
			do
			{
				b[r1][c1-1]=random(5)+1;
			}while((b[r1][c1-1]==b[r1][c1-2])||(b[r1][c1-1]==b[r1][c1])||(b[r1][c1-1]==b[r1-1][c1-1])||(b[r1][c1-1]==b[r1+1][c1-1]));
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1-1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1+1]=random(5)+1;
			}while((b[r1][c1+1]==b[r1][c1])||(b[r1][c1+1]==b[r1][c1]+2)||(b[r1][c1+1]==b[r1-1][c1+1])||(b[r1][c1+1]==b[r1+1][c1+1]));
		}    //u1
		else if((b[r1-2][c1]==b[r1][c1])&&(b[r1-1][c1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1-1][c1]=random(5)+1;
			}while((b[r1-1][c1]==b[r1-1][c1-1])||(b[r1-1][c1]==b[r1-1][c1+1])||(b[r1-1][c1]==b[r1][c1])||(b[r1-1][c1]==b[r1-2][c1]));
			do
			{
				b[r1-2][c1]=random(5)+1;
			}while((b[r1-2][c1]==b[r1-2][c1-1])||(b[r1-2][c1]==b[r1-2][c1+1])||(b[r1-2][c1]==b[r1-1][c1])||(b[r1-2][c1]==b[r1-3][c1]));

		}        //u4
		else if((b[r1][c1+1]==b[r1][c1])&&(b[r1][c1+2]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1+1]=random(5)+1;
			}while((b[r1][c1+1]==b[r1][c1])||(b[r1][c1+1]==b[r1][c1+2])||(b[r1][c1+1]==b[r1-1][c1+1])||(b[r1][c1+1]==b[r1+1][c1+1]));
			do
			{
				b[r1][c1+2]=random(5)+1;
			}while((b[r1][c1+2]==b[r1][c1+1])||(b[r1][c1+2]==b[r1][c1+3])||(b[r1][c1+2]==b[r1-1][c1+2])||(b[r1][c1+2]==b[r1+1][c1+2]));
		}//u2
		else if((b[r1][c1-1]==b[r1][c1])&&(b[r1][c1-2]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1-1]=random(5)+1;
			}while((b[r1][c1-1]==b[r1][c1-2])||(b[r1][c1-1]==b[r1][c1])||(b[r1][c1-1]==b[r1-1][c1-1])||(b[r1][c1-1]==b[r1+1][c1-1]));
			do
			{
				b[r1][c1-2]=random(5)+1;
			}while((b[r1][c1-2]==b[r1][c1-3])||(b[r1][c1-2]==b[r1][c1-1])||(b[r1][c1-2]==b[r1-1][c1-2])||(b[r1][c1-2]==b[r1+1][c1-2]));

		}   //u3
	}
	else if(dir=='d')
	{
		if((b[r1][c1]==b[r1][c1-1])&&(b[r1][c1]==b[r1][c1+1]))
		{
			do
			{
				b[r1][c1-1]=random(5)+1;
			}while((b[r1][c1-1]==b[r1][c1-2])||(b[r1][c1-1]==b[r1][c1])||(b[r1][c1-1]==b[r1-1][c1-1])||(b[r1][c1-1]==b[r1+1][c1-1]));
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1+1]=random(5)+1;
			}while((b[r1][c1+1]==b[r1][c1])||(b[r1][c1+1]==b[r1][c1+2])||(b[r1][c1+1]==b[r1-1][c1+1])||(b[r1][c1+1]==b[r1+1][c1+1]));
		}  //d1
		else if((b[r1+2][c1]==b[r1][c1])&&(b[r1+1][c1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1+1][c1]=random(5)+1;
			}while((b[r1+1][c1]==b[r1+1][c1-1])||(b[r1+1][c1]==b[r1+1][c1+1])||(b[r1+1][c1]==b[r1][c1])||(b[r1+1][c1]==b[r1+2][c1]));
			do
			{
				b[r1+2][c1]=random(5)+1;
			}while((b[r1+2][c1]==b[r1+2][c1-1])||(b[r1+2][c1]==b[r1+2][c1+1])||(b[r1+2][c1]==b[r1+1][c1])||(b[r1+2][c1]==b[r1+3][c1]));
		}    //d4
		else if((b[r1][c1+1]==b[r1][c1])&&(b[r1][c1+2]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1+1]=random(5)+1;
			}while((b[r1][c1+1]==b[r1][c1])||(b[r1][c1+1]==b[r1][c1+2])||(b[r1][c1+1]==b[r1-1][c1+1])||(b[r1][c1+1]==b[r1+1][c1+1]));
			do
			{
				b[r1][c1+2]=random(5)+1;
			}while((b[r1][c1+2]==b[r1][c1+1])||(b[r1][c1+2]==b[r1][c1+3])||(b[r1][c1+2]==b[r1-1][c1+2])||(b[r1][c1+2]==b[r1+1][c1+2]));
		}   //d2
		else if((b[r1][c1-1]==b[r1][c1])&&(b[r1][c1-2]==b[r1][c1]))
		{

			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1-1]=random(5)+1;
			}while((b[r1][c1-1]==b[r1][c1-2])||(b[r1][c1-1]==b[r1][c1])||(b[r1][c1-1]==b[r1-1][c1-1])||(b[r1][c1-1]==b[r1+1][c1-1]));
			do
			{
				b[r1][c1-2]=random(5)+1;
			}while((b[r1][c1-2]==b[r1][c1-3])||(b[r1][c1-2]==b[r1][c1-1])||(b[r1][c1-2]==b[r1-1][c1-2])||(b[r1][c1-2]==b[r1+1][c1-2]));
		}    //d3
	}
	else if(dir=='l')
	{
		if((b[r1][c1]==b[r1-1][c1])&&(b[r1][c1]==b[r1+1][c1]))
		{
			do
			{
				b[r1-1][c1]=random(5)+1;
			}while((b[r1-1][c1]==b[r1-1][c1-1])||(b[r1-1][c1]==b[r1-1][c1+1])||(b[r1-1][c1]==b[r1-2][c1])||(b[r1-1][c1]==b[r1][c1]));
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1+1][c1]=random(5)+1;
			}while((b[r1+1][c1]==b[r1+1][c1-1])||(b[r1+1][c1]==b[r1+1][c1+1])||(b[r1+1][c1]==b[r1][c1])||(b[r1+1][c1]==b[r1+2][c1]));
		}   //l1
		else if((b[r1][c1-2]==b[r1][c1])&&(b[r1][c1-1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1-1]=random(5)+1;
			}while((b[r1][c1-1]==b[r1][c1-2])||(b[r1][c1-1]==b[r1][c1])||(b[r1][c1-1]==b[r1-1][c1-1])||(b[r1][c1-1]==b[r1+1][c1-1]));
			do
			{
				b[r1][c1-2]=random(5)+1;
			}while((b[r1][c1-2]==b[r1][c1-3])||(b[r1][c1-2]==b[r1][c1-1])||(b[r1][c1-2]==b[r1-1][c1-2])||(b[r1][c1-2]==b[r1+1][c1-2]));

		}    //l4
		else if((b[r1-1][c1]==b[r1][c1])&&(b[r1-2][c1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1-1][c1]=random(5)+1;
			}while((b[r1-1][c1]==b[r1-1][c1-1])||(b[r1-1][c1]==b[r1-1][c1+1])||(b[r1-1][c1]==b[r1][c1])||(b[r1-1][c1]==b[r1-2][c1]));
			do
			{
				b[r1-2][c1]=random(5)+1;
			}while((b[r1-2][c1]==b[r1-2][c1-1])||(b[r1-2][c1]==b[r1-2][c1+1])||(b[r1-2][c1]==b[r1-1][c1])||(b[r1-2][c1]==b[r1-3][c1]));

		}    //l2
		else if((b[r1+1][c1]==b[r1][c1])&&(b[r1+2][c1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1+1][c1]=random(5)+1;
			}while((b[r1+1][c1]==b[r1+1][c1-1])||(b[r1+1][c1]==b[r1+1][c1+1])||(b[r1+1][c1]==b[r1][c1])||(b[r1+1][c1]==b[r1+2][c1]));
			do
			{
				b[r1+2][c1]=random(5)+1;
			}while((b[r1+2][c1]==b[r1+2][c1-1])||(b[r1+2][c1]==b[r1+2][c1+1])||(b[r1+2][c1]==b[r1+1][c1])||(b[r1+2][c1]==b[r1+3][c1]));
		}       //l3
	}
	else if(dir=='r')
	{
		if((b[r1][c1]==b[r1-1][c1])&&(b[r1][c1]==b[r1+1][c1]))
		{
			do
			{
				b[r1-1][c1]=random(5)+1;
			}while((b[r1-1][c1]==b[r1-1][c1-1])||(b[r1-1][c1]==b[r1-1][c1+1])||(b[r1-1][c1]==b[r1-2][c1])||(b[r1-1][c1]==b[r1][c1]));
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1+1][c1]=random(5)+1;
			}while((b[r1+1][c1]==b[r1+1][c1-1])||(b[r1+1][c1]==b[r1+1][c1+1])||(b[r1+1][c1]==b[r1][c1])||(b[r1+1][c1]==b[r1+2][c1]));
		}   //r1
		else if((b[r1][c1+2]==b[r1][c1])&&(b[r1][c1+1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1][c1+1]=random(5)+1;
			}while((b[r1][c1+1]==b[r1][c1])||(b[r1][c1+1]==b[r1][c1+2])||(b[r1][c1+1]==b[r1-1][c1+1])||(b[r1][c1+1]==b[r1+1][c1+1]));
			do
			{
				b[r1][c1+2]=random(5)+1;
			}while((b[r1][c1+2]==b[r1][c1+1])||(b[r1][c1+2]==b[r1][c1+3])||(b[r1][c1+2]==b[r1-1][c1+2])||(b[r1][c1+2]==b[r1+1][c1+2]));
		}    //r4
		else if((b[r1-1][c1]==b[r1][c1])&&(b[r1-2][c1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1-1][c1]=random(5)+1;
			}while((b[r1-1][c1]==b[r1-1][c1-1])||(b[r1-1][c1]==b[r1-1][c1+1])||(b[r1-1][c1]==b[r1][c1])||(b[r1-1][c1]==b[r1-2][c1]));
			do
			{
				b[r1-2][c1]=random(5)+1;
			}while((b[r1-2][c1]==b[r1-2][c1-1])||(b[r1-2][c1]==b[r1-2][c1+1])||(b[r1-2][c1]==b[r1-1][c1])||(b[r1-2][c1]==b[r1-3][c1]));

		}    //r2
		else if((b[r1+1][c1]==b[r1][c1])&&(b[r1+2][c1]==b[r1][c1]))
		{
			do
			{
				b[r1][c1]=random(5)+1;
			}while((b[r1][c1]==b[r1][c1-1])||(b[r1][c1]==b[r1][c1+1])||(b[r1][c1]==b[r1-1][c1])||(b[r1][c1]==b[r1+1][c1]));
			do
			{
				b[r1+1][c1]=random(5)+1;
			}while((b[r1+1][c1]==b[r1+1][c1-1])||(b[r1+1][c1]==b[r1+1][c1+1])||(b[r1+1][c1]==b[r1][c1])||(b[r1+1][c1]==b[r1+2][c1]));
			do
			{
				b[r1+2][c1]=random(5)+1;
			}while((b[r1+2][c1]==b[r1+2][c1-1])||(b[r1+2][c1]==b[r1+2][c1+1])||(b[r1+2][c1]==b[r1+1][c1])||(b[r1+2][c1]==b[r1+3][c1]));
		}    //r3
	}
}
void delay()
{
		cleardevice();
		settextstyle(3,0,5);
		outtextxy(100,200,"LOADING....");
		circle(450,200,51);
		for(int i=90;i<=360;i++)
		{
			setcolor(BLUE);
			setfillstyle(1,BLUE);
			pieslice(450,200,90,i,50);
			delay(2);
		}
		for(i=0;i<=90;i++)
		{
			setfillstyle(1,BLUE);
			pieslice(450,200,0,i,50);
			delay(2);
		}
}
void head()
{
	setcolor(WHITE);
	settextstyle(3,0,4);
	outtextxy(220,30,"CoLor BLocks");
	line(215,70,425,70);
}
void about()
{
	delay();
	cleardevice();
	head();
	settextstyle(3,0,3);
	setcolor(CYAN);
	outtextxy(150,100,"Version : 1.0.0.1");
	outtextxy(150,150,"Creator : Arjhun H");
	outtextxy(260,200,"Std 12,Vidya Mandir");
	outtextxy(150,250,"Email   : arjhun@cblocks.com");
	setcolor(GREEN);
	outtextxy(60,400,"Press any key to go back to the main menu");
}
void inst()
{
	delay();
	cleardevice();
	head();
	settextstyle(3,0,2);
	setcolor(YELLOW);
	outtextxy(50,100,"Move a block to the left, right, up or down");
	outtextxy(50,130,"to get three consecutive blocks of the same");
	outtextxy(50,160,"colour.Make as many triples as you can.");
	outtextxy(50,210,"Each triple yields a score of 50 points.");
	outtextxy(50,250,"Type 15 in row or column to quit the game");
	outtextxy(50,280,"Press q in the direction to quit the game");
	setcolor(GREEN);
	outtextxy(100,420,"Press any key to go back to the main menu");
}
void controls()
{
	delay();
	cleardevice();
	head();
	setcolor(BROWN);
	settextstyle(3,0,2);
	outtextxy(20,100," 1.Type the row of the block you want to move.");
	outtextxy(20,130," 2.Type the column of the block you want to move.");
	outtextxy(20,160," 3.Type the direction in which you want to move the block.");
	outtextxy(30,220,"Directions : ");
	outtextxy(150,250," l - left");
	outtextxy(150,280," r - right");
	outtextxy(150,310," u - up");
	outtextxy(150,340," d - down");
	setcolor(GREEN);
	outtextxy(100,420,"Press any key to go back to the main menu");
}
void finish()
{
	cleardevice();
	settextstyle(3,0,3);
	outtextxy(100,100,"Congrats.. You have finished this level");
	setcolor(GREEN);
	outtextxy(100,420,"Press any key to go back to the main menu");
}

void menu1() //main menu
{
	do
	{
	cleardevice();
	head();
	settextstyle(3,0,3);
	gotoxy(1,1);
	outtextxy(220,150,"1. Play Game");
	outtextxy(220,180,"2. Instructions");
	outtextxy(220,210,"3. Controls");
	outtextxy(220,240,"4. About");
	outtextxy(220,270,"5. Exit");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	do
	{
		cout<<"\t\t\tEnter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:{
					menu2();
				}break;
			case 2:{
					inst();
					getch();
				}break;
			case 3:{
					controls();
					getch();
				}break;
			case 4:{
					about();
					getch();
				}break;
			case 5:{
					exit(0);
				}break;
		}
	}while((opt<1)||(opt>5));
	}while(5);
}
void count_score()
{
		itoa(score,score_c,10);
		outtextxy(462,440,"Score : ");
		outtextxy(550,440,score_c);
}
void game_fast()
{
	cleardevice();
	layout();
	def_col_array();
	ini_repeat();
	assign_temp();
	col_fill();
	do
	{
		count_score();
		user_input();
		assign_temp();
		check_move();
	}while(score<500);
	if(score>=500)
	{
		finish();
		getch();
	}
}
void game_norm()
{
	cleardevice();
	layout();
	def_col_array();
	ini_repeat();
	assign_temp();
	col_fill();
	do
	{
		count_score();
		user_input();
		assign_temp();
		check_move();
	}while(score<2500);
	if(score>=2500)
	{
		finish();
		getch();
	}
}
void game_slo()
{
	cleardevice();
	layout();
	def_col_array();
	ini_repeat();
	assign_temp();
	col_fill();
	do
	{
		count_score();
		user_input();
		assign_temp();
		check_move();
	}while(score<7500);
	if(score>=7500)
	{
		finish();
		getch();
	}
}
void game_no()
{
	cleardevice();
	layout();
	def_col_array();
	ini_repeat();
	assign_temp();
	col_fill();
	do
	{
		user_input();
		assign_temp();
		check_move();
	}while(5);
}

void menu2()
{
	cleardevice();
	head();
	settextstyle(3,0,3);
	gotoxy(1,1);
	outtextxy(150,150,"1. Classic Game - No score");
	outtextxy(150,210,"2. Scored Game");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	do
	{
		cout<<"\t\t\tEnter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:{
					game_no();
				}break;
			case 2:{
					menu3();
				}break;
		}
	}while((opt<1)||(opt>2));
}
void menu3()
{
	cleardevice();
	head();
	settextstyle(3,0,3);
	gotoxy(1,1);
	outtextxy(150,150,"1. Fast Game - Max score is 500");
	outtextxy(150,210,"2. Normal Game - Max score is 2500");
	outtextxy(150,270,"3. Slow Game - Max score is 7500");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	do
	{
		cout<<"\t\t\tEnter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:{
					game_fast();
				}break;
			case 2:{
					game_norm();
				}break;
			case 3:{
					game_slo();
				}break;
		}
	}while((opt<1)||(opt>3));
}
void main()
{
	int	a=9,b=2;
		initgraph(&a,&b,"C:\\TC\\BGI");
		cleardevice();
		first_page();
		getch();
		cleardevice();
		menu1();
		getch();
}