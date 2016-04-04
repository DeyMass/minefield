#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>

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
    int width=20,height=5,dif=0,menu=1;
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
int nmines=((width+height)/100)*dif;
closegraph();
for (int i=1;i<20;i++)
    for (int j=1;j<20;j++){
pole(i,j,nmines);
delay(100);
closegraph();
}
getch();
}
