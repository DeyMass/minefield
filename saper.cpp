#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
void random(int w,int h,int nmines,int** a){
	for (int i=0;i<nmines;){
        int rw=rand()%w;
        int rh=rand()%h;
		if(a[rw][rh]!=1){ a[rw][rh]=1; i++;}
		
}
	
	
}
void pole(int a, int b,int c){
     initwindow(a*40,b*40+100);
     setcolor(COLOR(255,255,255));
	 for (int i=0;i<a*40;i+=40)
   line(i,0,i,b*40);//vertikal liniya
	for (int i=0;i<=b*40;i+=40)
	line(0,i,a*40,i);//gorizont liniya
	readimagefile("./image/131.jpg",(a*40)/2-25,b*40+30,((a*40)/2)+25,b*40+75);
	settextstyle(3,0,4);
	bgiout<<"mines: "<<c;
	outstreamxy(1,b*40+50);
}

int main(){
    int width=10,height=10,dif=20,menu=1;
initwindow(500,300);
settextstyle(3,0,4);
setcolor(COLOR(0,255,0));
bgiout<<"START";
outstreamxy(350,100);
bgiout<<"GAME";
outstreamxy(366,150);
setcolor(COLOR(255,255,255));
while(menu==1){

               printf("%i:%i\n",mousex(),mousey());
bgiout<<"Width: "<<width;
outstreamxy(1,1);
bgiout<<"Height: "<<height;
outstreamxy(1,100);
bgiout<<"Difficulty: "<<dif<<"%";
outstreamxy(1,200);
bgiout<<"START";
outstreamxy(350,100);
bgiout<<"GAME";
outstreamxy(366,150);


if (ismouseclick(WM_LBUTTONDOWN)&&mousex()<200&&mousex()>115&&mousey()<40){
   for (int i=255;i>0;i--){
   setcolor(COLOR(255,i,i));
   bgiout<<"Width: "<<width;
   outstreamxy(1,1);
   delay(1);
}
   width=getch()-48;
   for (int i=0;i<255;i++){
   setcolor(COLOR(255,i,i));
   bgiout<<"Width: "<<width;
   outstreamxy(1,1);
   delay(1);
}
   clearmouseclick(WM_LBUTTONDOWN);
   cleardevice();
   setcolor(COLOR(255,255,255));
}

if (ismouseclick(WM_LBUTTONDOWN)&&mousex()<200&&mousex()>100&&mousey()<170&&mousey()>100){
   for (int i=255;i>0;i--){
   setcolor(COLOR(255,i,i));
   bgiout<<"Height: "<<height;
   outstreamxy(1,100);
   delay(1);
}
   height=getch()-48;
   for (int i=0;i<255;i++){
   setcolor(COLOR(255,i,i));
   bgiout<<"Height: "<<height;
   outstreamxy(1,100);
   delay(1);
}
   clearmouseclick(WM_LBUTTONDOWN);
   cleardevice();
   setcolor(COLOR(255,255,255));
}
if (ismouseclick(WM_LBUTTONDOWN)&&mousex()<200&&mousex()>100&&mousey()<270&&mousey()>200){
   for (int i=255;i>0;i--){
   setcolor(COLOR(255,i,i));
   bgiout<<"Difficulty: "<<dif;
   outstreamxy(1,200);
   delay(1);
}
   dif=getch()-48;
   clearmouseclick(WM_LBUTTONDOWN);
      for (int i=0;i<255;i++){
   setcolor(COLOR(255,i,i));
   bgiout<<"Difficulty: "<<dif;
   outstreamxy(1,200);
   delay(1);
}
   cleardevice();
   setcolor(COLOR(255,255,255));
}
if (ismouseclick(WM_LBUTTONDOWN)&&mousex()>350&&mousey()<200&&mousey()>100){
   for (int i=255;i>0;i--){
   setcolor(COLOR(i,255,i));
   bgiout<<"START";
outstreamxy(350,100);
bgiout<<"GAME";
outstreamxy(366,150);
delay(1);
}
   menu=0;
   delay(500);
   
   break;
}
clearmouseclick(WM_LBUTTONDOWN);
delay(30);
}
int nmines=(int)((float)(width*height)/100)*dif;
pole(width,height,nmines);
int** grid;
grid=new int* [height+2];
for (int i=0;i<=height+1;i++){
    grid[i]=new int [width+2];
}

int tempx,tempy;
random(width,height,nmines,grid);
while (1){
    printf("%i\n",grid[1][1]);
    delay(100);
    }
}
