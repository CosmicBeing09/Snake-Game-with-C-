#include<bits/stdc++.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;
void check();
void End();
void win();
void border_End();
//void walleat();
int m[500],n[500],con=3,p,k,life=3,maxx,maxy;
clock_t start,stop;
int d,score = 0;
int main()
{
freopen("HighScore.txt","r",stdin);
int gd=DETECT,gm,ch,x=195,y=210,p,q,spd=100,v=0;
initgraph(&gd,&gm,"..\bgi");
setcolor(3);
settextstyle(4,0,4);
outtextxy(80,2," Project-1: Snake");
settextstyle(6,0,2);
setcolor(WHITE);
outtextxy(00,80," Submitted by:");
outtextxy(20,140,"Maksudur Rahman Munif");
outtextxy(20,160,"Registration No: 2016831003");
outtextxy(20,180,"Mohammed Raihan Ullah ");
outtextxy(20,200,"Registration No: 2016831009");
outtextxy(00,280," Submitted to: ");
outtextxy(20,320,"Asif Mohammed Samir Sir ");
outtextxy(20,340,"Assistant Professor");
outtextxy(20,360,"IICT,SUST");
ch=getch();
cleardevice();
ch=getch();
//level1:
cleardevice();
maxx=getmaxx();
maxy=getmaxy();
cout<<maxx<<" "<<maxy<<endl;
//left border
for(k=0;k<maxy;k=k+10)
{
setcolor(3);
rectangle(0,41,10,k);
}
//top border
for(k=0;k<maxx;k=k+10)
{
setcolor(3);
rectangle(0,30,k,40);
}
//bpttom border
for(k=0;k<maxx;k=k+10)
{
setcolor(3);
rectangle(0,maxy-10,k,maxy);
}
//Right border
for(k=0;k<maxy;k=k+10)
{
setcolor(3);
rectangle(maxx-10,0,maxx,k);
}

ram:
p=rand()%(400);
int temp=p%13;
p=p-temp;
q=rand()%(400);
temp=q%14;
q=q-temp;
cout<<p<<" "<<q<<endl;
if(p<15 || q<50)
    goto ram;

start=clock();
int a=4,i=0,j,t;
bool point=false;
int bonus;
cin >> d;
while(1)
{

 if(score >0 && score%5==4) point = true;
 else{ bonus = 500;
 point = false;
 }
 if(!point || bonus == 0){
 setcolor(BLACK);
 outtextxy((maxx/2)+20,00,"BONUS!");
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 circle(p,q,5); //x position,y position,size
 floodfill(p,q,BLACK);
 }
 else
 {
 setcolor(rand()%9);
 setfillstyle(SOLID_FILL,WHITE);
 circle(p,q,5);
 floodfill(p,q,BLACK);

 char spp[1000];
 setcolor(rand()%9);
 sprintf(spp,"BONUS!",bonus);
 outtextxy((maxx/2)+20,00,"BONUS!");
 setcolor(rand()%9);
 outtextxy((maxx/2)+20,00,spp);
// clears
 }

   if( kbhit() )
   {
     ch=getch();
     if(ch==0) ch=getch();
     if(ch==72 && a!=2) a=1;
     if(ch==80&& a!=1) a=2;
     if(ch==75&& a!=4) a=3;
     if(ch==77&& a!=3) a=4;
      }
       else
     {
     if(ch==27) break;
     }
level1:
       if(i<3){
 		   m[i]=x;
 		   n[i]=y;
 		   i++;
	       }

		 if(i>=3)

		 {
	 		  for(j=con;j>=0;j--){
		 		  m[1+j]=m[j];
		 		  n[1+j]=n[j];
	 		 		  }
		   m[0]=x;
		   n[0]=y;

//Mouth
		   setcolor(WHITE);
		   setfillstyle(SOLID_FILL,WHITE);
		   circle(m[0],n[0],8);
		  // rectangle(m[0],n[0],16,16);
		   floodfill(m[0],n[0],WHITE);
//Body
		   setcolor(WHITE);
		   for(j=1;j<con;j++){
		  setfillstyle(SOLID_FILL,6);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		 		      }
       delay(spd+20);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
          circle(m[0],n[0],8);
		    //rectangle(m[0],n[0],16,16);
		   floodfill(m[0],n[0],BLACK);

		   setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);
		   }
     stop=clock();
     t=(stop-start)/CLK_TCK;
     setcolor(3);
     char arr[100];
     sprintf(arr,"BEST: %d",d);
     outtextxy(maxx-130,00,arr);
     sprintf(arr,"SCORE: %d",score);
     outtextxy(00,00,arr);
     sprintf(arr,"LIFE: %d",life);
     outtextxy(210,00,arr);
     check();

    if(x==p&&y==q) { if(score%5==4)score+=3; else score+=1;
    con=con+1; if(spd>=1) spd=spd-1; else spd=1;
		 		      if(con>450) win();
	ran:
     p=rand()%400; temp=p%13;  p=p-temp;
     q=rand()%400; temp=q%14;   q=q-temp;
     cout<<p<<" "<<q<<endl;

     if(p<20 || q<50)
        goto ran;

		 		    }

    if(a==1)  y =  y-14; //if(y<0) { temp=maxy%14;y=maxy-temp;}
     if(y<=43)
        border_End();

    if(a==2)  y =  y+14; if(y>maxy-12) border_End();
    if(a==3)  x =  x-13; //if(x<0) { temp=maxx%13;x=maxx-temp;} else
    if(x<=13) border_End();
    if(a==4)  x =  x+13; if(x>maxx-12) border_End();
    if(a==0){  y = y+14 ;  x=x+13; }
		 }
		  if(point){
    if(bonus>0)
    bonus-=10;
    if(bonus==0){
         setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLUE);
 circle(p,q,15);
 floodfill(p,q,BLACK);
    }
    }

 }

void check(){
   int a,i,j;
   for(a=1;a<con;a++)

if(m[0]==m[a] && n[0]==n[a] && life==0) End();
   else if(m[0]==m[a] && n[0]==n[a] && life>0)
           {
               life-=1;
                setcolor(WHITE);
   for(i=0;i<2;i++){
    delay(500);
   for(j=0;j<=con;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }

		 }
		 setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);
		   clearviewport();
		   //left border
for(k=0;k<maxy;k=k+10)
{
setcolor(3);
rectangle(0,41,10,k);
}
//top border
for(k=0;k<maxx;k=k+10)
{
setcolor(3);
rectangle(0,30,k,40);
}
//bpttom border
for(k=0;k<maxx;k=k+10)
{
setcolor(3);
rectangle(0,maxy-10,k,maxy);
}
//Right border
for(k=0;k<maxy;k=k+10)
{
setcolor(3);
rectangle(maxx-10,0,maxx,k);
}

           }
   else
        continue;
}
void End()

{
    freopen("HighScore.txt","w",stdout);
    if(d < score)
    {
        d = score;
        cout << d;

    }
    int j,i;
   setcolor(WHITE);
   for(i=0;i<5;i++){
   delay(500);
    cleardevice();
    delay(500);
   for(j=0;j<=con;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }

		 }

    settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    getch();
    getch();
    exit(0);
    }

void win()
{
int j,i;
setcolor(WHITE);
   for(i=0;i<5;i++){
   for(j=0;j<=con;j++){
		   setfillstyle(SOLID_FILL,con);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }
    delay(500);
    cleardevice();
    delay(500);
		 }
  settextstyle(3,0,4);
  outtextxy(210,320," YOU WIN ");
  getch();
  exit(0);
}
void border_End()

{
    freopen("HighScore.txt","w",stdout);
    if(d < score)
    {
        d = score;
        cout << d;

    }
    int j,i;
   setcolor(WHITE);
   for(i=0;i<2;i++){
   delay(500);
    cleardevice();
    delay(500);
   for(j=0;j<=con;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }

		 }

    settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    setcolor(RED);
    outtextxy(20,300,"BORDER COST ALL 3 OF YOUR LIVES");
    getch();
    getch();
    exit(0);
    }
