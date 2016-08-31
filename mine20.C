#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>

int initmouse();
void showmouseptr();
void mines();
void values();
void gameOver(int z);
void getmousepos(int* ,int* ,int*);
void hidemouseptr();
int scr(int);
int stc(int);

void restrictmouseptr(int,int,int,int);
time_t start_time;
time_t stop_time;


int ctr=0;int timeelasped;

typedef struct block
{
int count;
struct block *up;
struct block *right;
struct block *down;
struct block *left;
}block;
 struct list
{
char p[20];
int score;
}list[20];

union REGS i,o;
int gd=DETECT,gm;
  int n=9,l;
block *temp,*head,*end,*temp1,*end1,*a[9][9];
int noofrclicks=0;
int nooflclicks=0;
FILE *fp;
void main()
{
int i,j,button,x,y;
int p,q0,q1,q2,q3,q4,q5,q6,q7,q8;
int mid1,mid2;

struct printingAgain
{
int posx;
int posy;
};
struct printingAgain arr[30],arr0[80],arr1[80],arr2[80],arr3[80],arr4[80];
struct printingAgain arr5[80],arr6[80],arr7[80],arr8[80];

p=q0=q1=q2=q3=q4=q5=q6=q7=q8=0;

initgraph(&gd,&gm,"C:\\TC\\BGI");




printf("The Numbers IN The Blocks represent The Number Of mines Touching The Block.\n Open The Blocks Where There Are No Mines And right Click Where The Mines Are Placed.\n The Time taken to decode represents your score!");


temp=head=end=temp1=end1=NULL;
printf("WELCOME TO THE WORLD OF MINES!\n");
delay(5000);
clrscr();
printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
gotoxy(300,90);
printf("CHOOSE THE MODE YOU WANT TO PLAY!\n");
gotoxy(300,100);
printf("1.AMATEUR\n");
gotoxy(300,110);
printf("2.SEMI PROFESSIONAL\n");
gotoxy(300,120);
printf("3.PROFESSIONAL\n");
gotoxy(300,130);
printf("4.LEGENDARY\n");
gotoxy(300,140);
printf("5.HIGH SCORES\n");
gotoxy(300,150);
printf("ENTER YOUR CHOICE ");
scanf("%d",&l);
clrscr();
if(l==1)
{

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=(block*)malloc(sizeof(block));
a[i][j]->count=0;
a[i][j]->right=a[i][j]->left=a[i][j]->up=a[i][j]->down=NULL;
}}
head=a[0][0];
for(i=0;i<9;i++)
{
for(j=0;j<8;j++)
{
a[i][j]->right=a[i][j+1];
}
}
for(i=0;i<9;i++)
{
for(j=8;j>0;j--)
{
a[i][j]->left=a[i][j-1];
}
}
for(i=0;i<8;i++)
{
for(j=0;j<9;j++)
{
a[i][j]->down=a[i+1][j];
}
}
for(i=8;i>0;i--)
{
for(j=0;j<9;j++)

{
a[i][j]->up=a[i-1][j];
}
}


mines(9);
values();

}
else
if(l==2)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=(block*)malloc(sizeof(block));
a[i][j]->count=0;
a[i][j]->right=a[i][j]->left=a[i][j]->up=a[i][j]->down=NULL;
}}
head=a[0][0];
for(i=0;i<9;i++)
{
for(j=0;j<8;j++)
{
a[i][j]->right=a[i][j+1];
}
}
for(i=0;i<9;i++)
{
for(j=8;j>0;j--)
{
a[i][j]->left=a[i][j-1];
}
}
for(i=0;i<8;i++)
{
for(j=0;j<9;j++)
{
a[i][j]->down=a[i+1][j];
}
}
for(i=8;i>0;i--)
{
for(j=0;j<9;j++)

{
a[i][j]->up=a[i-1][j];
}
}


mines(12);
values();

}
else
if(l==3)
{
 for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=(block*)malloc(sizeof(block));
a[i][j]->count=0;
a[i][j]->right=a[i][j]->left=a[i][j]->up=a[i][j]->down=NULL;
}}
head=a[0][0];
for(i=0;i<9;i++)
{
for(j=0;j<8;j++)
{
a[i][j]->right=a[i][j+1];
}
}
for(i=0;i<9;i++)
{
for(j=8;j>0;j--)
{
a[i][j]->left=a[i][j-1];
}
}
for(i=0;i<8;i++)
{
for(j=0;j<9;j++)
{
a[i][j]->down=a[i+1][j];
}
}
for(i=8;i>0;i--)
{
for(j=0;j<9;j++)

{
a[i][j]->up=a[i-1][j];
}
}


mines(15);
values();

}
else
if(l==4)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=(block*)malloc(sizeof(block));
a[i][j]->count=0;
a[i][j]->right=a[i][j]->left=a[i][j]->up=a[i][j]->down=NULL;
}}
head=a[0][0];
for(i=0;i<9;i++)
{
for(j=0;j<8;j++)
{
a[i][j]->right=a[i][j+1];
}
}
for(i=0;i<9;i++)
{
for(j=8;j>0;j--)
{
a[i][j]->left=a[i][j-1];
}
}
for(i=0;i<8;i++)
{
for(j=0;j<9;j++)
{
a[i][j]->down=a[i+1][j];
}
}
for(i=8;i>0;i--)
{
for(j=0;j<9;j++)

{
a[i][j]->up=a[i-1][j];
}
}


mines(20);
values();

}
/*else
if(l==5)
stc(l);
*/
if(!initmouse())
{
printf("Mouse Support Not Available. Please Attach a Mouse and Re-run");
}

while(!kbhit())
{

setbkcolor(GREEN);


for(i=125;i<=325;i+=25)
{
for(j=150;j<375;j+=25)
{
rectangle(j+25,i,j+50,i+25);

}

}
rectangle(170,120,405,355);
rectangle(169,119,406,356);

showmouseptr();
restrictmouseptr(175,125,400,350);



for(i=0;i<q0;i++)
outtextxy(arr0[i].posx,arr0[i].posy,"0");

for(i=0;i<q1;i++)
outtextxy(arr1[i].posx,arr1[i].posy,"1");

for(i=0;i<q2;i++)
outtextxy(arr2[i].posx,arr2[i].posy,"2");

for(i=0;i<q3;i++)
outtextxy(arr3[i].posx,arr3[i].posy,"3");

for(i=0;i<q4;i++)
outtextxy(arr4[i].posx,arr4[i].posy,"4");

for(i=0;i<q5;i++)
outtextxy(arr5[i].posx,arr5[i].posy,"5");

for(i=0;i<q6;i++)
outtextxy(arr6[i].posx,arr6[i].posy,"6");

for(i=0;i<q7;i++)
outtextxy(arr7[i].posx,arr7[i].posy,"7");

for(i=0;i<q8;i++)
outtextxy(arr8[i].posx,arr8[i].posy,"8");


for(i=0;i<p;i++)
outtextxy(arr[i].posx,arr[i].posy,"M");

getmousepos(&button,&x,&y);

if(button==1)
{    if(ctr==0){ctr++;  start_time=time(NULL);          }
button=-1;
cleardevice();
nooflclicks++;
mid1=(x-175)/25;
mid2=(y-125)/25;
temp=head;
for(i=0;i<mid1;i++)
temp=temp->down;
for(j=0;j<mid2;j++)
temp=temp->right;

if(temp->count==9)
gameOver(0);

if(temp->count==0)
{
outtextxy(x,y,"0");
arr0[q0].posx=x;
arr0[q0].posy=y;
q0++;
}

if(temp->count==1)
{
outtextxy(x,y,"1");
arr1[q1].posx=x;
arr1[q1].posy=y;
q1++;

}
if(temp->count==2)
{
outtextxy(x,y,"2");
arr2[q2].posx=x;
arr2[q2].posy=y;
q2++;

}
if(temp->count==3)
{
outtextxy(x,y,"3");
arr3[q3].posx=x;
arr3[q3].posy=y;
q3++;

}
if(temp->count==4)
{
outtextxy(x,y,"4");
arr4[q4].posx=x;
arr4[q4].posy=y;
q4++;
}
if(temp->count==5)
{
outtextxy(x,y,"5");
arr5[q5].posx=x;
arr5[q5].posy=y;
q5++;

}
if(temp->count==6)
{
outtextxy(x,y,"6");
arr6[q6].posx=x;
arr6[q6].posy=y;
q6++;
}
if(temp->count==7)
{
outtextxy(x,y,"7");
arr7[q7].posx=x;
arr7[q7].posy=y;
q7++;
}
if(temp->count==8)
{
outtextxy(x,y,"8");
arr8[q8].posx=x;
arr8[q8].posy=y;
q8++;
}

}
else if(button==2)
{
button=-1;
cleardevice();
noofrclicks++;
if(noofrclicks==15&&nooflclicks!=66)
{
gameOver(1);
}
if(noofrclicks==15&&nooflclicks==66)
{
gameOver(2);
}

outtextxy(x,y,"M");
getch();          //getch() if removed mouse bug
arr[p].posx=x;
arr[p].posy=y;    p++;
}


}
	     closegraph();
	    getch();


}//main closes


int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void hidemouseptr()
{
i.x.ax=2;
int86(0X33,&i,&o);
}

void getmousepos(int *button,int *x,int *y)
{
i.x.ax=3;
int86(0x0033,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}

void restrictmouseptr(int x1,int y1,int x2,int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0X33,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0X33,&i,&o);
}



void mines(int g)
{        int i,j;
   int randomint;  int r,c;
for(i=0;i<g;i++)
{
randomint=rand()%(n*n);
r=randomint/n;
c=randomint%n;
temp=head;
for(j=0;j<r;j++)
{
temp=temp->down;
}
for(j=0;j<c;j++)
{
temp=temp->right;
}

if(temp->count==9)
{
i--;
}
else
{
temp->count=9;
}
}//outer for loop closes

}//mines closes




void values()
{
temp=head;
temp1=head;

while(temp1!=NULL)
{

while(temp!=NULL)
{
if(temp->count>=9)
{}
else if(temp->count==0)
{
if(temp->up->count==9)
++temp->count;
if(temp->up->right->count==9)
++temp->count;
if(temp->right->count==9)
++temp->count;
if(temp->right->down->count==9)
++temp->count;
if(temp->down->count==9)
++temp->count;
if(temp->down->left->count==9)
++temp->count;
if(temp->left->count==9)
++temp->count;
if(temp->left->up->count==9)
++temp->count;
}
temp=temp->right;

}                 //inner loop closes

temp1=temp1->down;
temp=temp1;
}//outer loop closes

}//values closes


void gameOver(int z)
{
stop_time=time(NULL);

timeelasped=difftime(stop_time,start_time);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t",timeelasped);
gotoxy(310,90);
printf("Time Elasped: %d ",timeelasped);
if(z==0)
{
outtextxy(267,237,"Game Over");
outtextxy(240,262,"Stepped On A MINE\n");
//scr(0);
delay(5000);
exit(0);
}
else
if(z==1)
{
outtextxy(267,237,"Game Over ");
outtextxy(240,262,"Moves Exceeded!");
//scr(1);
delay(5000);
exit(0);
}
else
if(z==2)
{
outtextxy(267,237,"Game Successful ");
outtextxy(240,262,"Perfect!");
//scr(2);
delay(5000);
exit(0);
}

}

int scr(int a)
{
int i,h=0;
fp=fopen("SCORE.txt","w");
if(fp==NULL)
{
puts("SCORE FILE NOT FOUND!!!");
exit(1);
}

fprintf(fp,"%d\n ",h++);
i=h;
if(a==0)
{
list[i].score=0;
if(l==1)
strcpy(list[i].p,"AMATEUR");
else if(l==2)
strcpy(list[i].p,"SEMI PRO");
else
if(l==3)
strcpy(list[i].p,"PROFESSIONAL");
else
if(l==4)
strcpy(list[i].p,"LEGENDARY");
printf("YOUR SCORE: %d ",list[i].score);
i++;
}
else
if(a==1)
{
list[i].score=0;
if(l==1)
strcpy(list[i].p,"AMATEUR");
else if(l==2)
strcpy(list[i].p,"SEMI PRO");
else
if(l==3)
strcpy(list[i].p,"PROFESSIONAL");
else
if(l==4)
strcpy(list[i].p,"LEGENDARY");
printf("YOUR SCORE: %d ",list[i].score);
i++;
}
else
if(a==2)
{
list[i].score=timeelasped;
if(l==1)
strcpy(list[i].p,"AMATEUR");
else if(l==2)
strcpy(list[i].p,"SEMI PRO");
else
if(l==3)
strcpy(list[i].p,"PROFESSIONAL");
else
if(l==4)
strcpy(list[i].p,"LEGENDARY");
printf("YOUR SCORE: %d ",list[i].score);
i++;
}
for(i=0;i<h;i++)
fwrite(&list[i],sizeof(list[i]),1,fp);
fclose(fp);
fopen("SCORE.txt","r");
if(fp==NULL)
{
puts("SCORE FILE NOT FOUND!");
exit(1);
}
for(i=0;i<h;i++)
{
while(fread(&list[i],sizeof(list[i]),1,fp)==1)
{
clrscr();
printf("%d\t %s \t%d\n",i+1,list[i].p,list[i].score);
}
}
fclose(fp);
return 1;
}

int stc(int z)
{
}