#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
void random(int w,int h,int nmines,int** a){
	for (int i=0;i<nmines;){
printf("sup");
        int rw,rh;
        rw=(rand()%(w-1))+1;
        rh=(rand()%(h-1))+1;
        printf("%i:%i",rw,rh);
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
printf("sup");
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
char out[3];
int** opened;
int** grid;
int** secondg;
int** thirdg;
grid=new int* [height+3];
secondg=new int* [height+3];
thirdg=new int* [height+3];
opened=new int* [height+3];
for (int i=0;i<height+2;i++){
    grid[i]=new int [width+2];
    secondg[i]=new int [width+2];
    thirdg[i]=new int [width+2];
    opened[i]=new int [width+2];
}
     for (int i=0;i<height+2;i++)
    for (int j=0;j<width+2;j++){
        grid[i][j]=0;
        thirdg[i][j]=0;
        opened[i][j]=0;
    }
random(width,height,nmines,grid);
for (int i=1;i<height+1;i++)
    for (int j=1;j<width+1;j++){
   secondg[i][j]=(grid[i-1][j]+grid[i+1][j]+grid[i][j-1]+grid[i][j+1]+grid[i-1][j-1]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j+1]);   
}
int tempx,tempy;
setcolor(COLOR(255,255,255));
while (1){
      tempy=mousey()/40+1;
      tempx=mousex()/40+1;
    if (ismouseclick(WM_LBUTTONDOWN)&&mousey()<height*40&&thirdg[tempx][tempy]==0){
    if (grid[tempx][tempy]==1) break;
        out[0]=48+secondg[tempx][tempy];
        out[1]=0;
        opened[tempx][tempy]=1;
        setcolor(COLOR(255,255,255));
       outtextxy((tempx-1)*40+10,(tempy-1)*40+5,out);
       clearmouseclick(WM_LBUTTONDOWN);
    }
    if (ismouseclick(WM_RBUTTONDOWN)&&opened[tempx][tempy]==0&&mousey()<height*40&&thirdg[tempx][tempy]==0){
     
    out[0]='A';
    thirdg[tempx][tempy]=1;
    setcolor(COLOR(255,0,0));
    outtextxy((tempx-1)*40+10,(tempy-1)*40+5,out);
    clearmouseclick(WM_RBUTTONDOWN);
    }
    
    if (ismouseclick(WM_RBUTTONDOWN)&&opened[tempx][tempy]==0&&mousey()<height*40&&thirdg[tempx][tempy]==1){
    out[0]=' ';
    out[1]=' ';
    out[2]=0;
    thirdg[tempx][tempy]=0;
    setcolor(COLOR(255,0,0));
    outtextxy((tempx-1)*40+10,(tempy-1)*40+5,out);
    clearmouseclick(WM_RBUTTONDOWN);
    }
    //readimage("");
    clearmouseclick(WM_LBUTTONDOWN);
    clearmouseclick(WM_RBUTTONDOWN);
       
    delay(100);
    
    }
}
