#include "iostream"
#include "stdlib.h"
#include "windows.h"
#include "conio.h"
/*snake game made by mirza ahmad */
using namespace std;
int height=20,width=20,gameover;
int score;
int tailX[100],tailY[100];
int counttail=0;
int x,y,fooda,foody,opes;
void border();
void input();
void logic();
void setup();
void setup()
{
gameover=0;
x=height/2;
y=width/2;
first:
fooda=rand()%height;
if(fooda==0)
goto first;
second:
foody=rand()%width;
if(foody==0)
goto second;
score=0;
}
void border()
{
system("cls");
for(int i=0; i<height; i++)
{
for(int j=0; j<width; j++)
{
if(i==0 || i==height-1 || j==0 || j==width-1)
{
cout<<"*";
}
else if(i==x && j==y)
{
cout<<"o";	
}
else if(i==fooda && j==foody)
{
cout<<"F";
}
else
{
int v=0;
for(int k=0; k<counttail; k++)
{
if(i==tailX[k] && j==tailY[k])
{
cout<<"o";
v=1;
}
}
if(v==0)
cout<<" ";
}
}
cout<<"\n";
}
cout<<"SCORE IS : "<<score<<endl;		
}
void takeinput()
{
if(kbhit())
{
switch(getch())
{
case 'a':
opes=1;
break;
case 'd':
opes=2;
break;
case 'v':
opes=3;
break;
case 'f':
opes=4;
break;	
case 'z':
gameover=1;
break;
}
}
}
void logic()
{
int px;
px=tailX[0];
int py;
py=tailY[0];
int p2x,p2y;
tailX[0]=x;
tailY[0]=y;
for(int i=1; i<counttail; i++)
{
p2x=tailX[i];
p2y=tailY[i];
tailX[i]=px;
tailY[i]=py;
px=p2x;
py=p2y;
}
switch(opes)
{
case 1:
y--;
break;
case 2:
y++;
break;
case 3:
x--;
break;
case 4:
x++;
break;
default:
break;
}	
if(x<0 || x>width || y<0 || y>height)
gameover=1;	
for(int i=0; i<counttail; i++)
if(x==tailX[i] && y==tailY[i])
{
gameover=1;
}
if(x==fooda && y==foody)
{
fourth:
fooda=rand()%height;
if(fooda==0)
goto fourth;
fifth:
foody=rand()%width;
if(foody==0)
goto fifth;
score+=10;
counttail++;
}	
}	
int main(void)
{
six:
char k;
setup();
while(!gameover)
{
border();	
takeinput();
logic();
Sleep(100);
}
cout<<"Are you want to sure to close this game (y/n):";
cin>>k;
while(1)
{
if(k=='y' || k=='Y')
{
break;
}
else
{
goto six;
}
}
return 0;
}
