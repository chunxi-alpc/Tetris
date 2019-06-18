//# include <stdafx.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <conio.h>
# include <graphics.h>
  int a,newsize0,newsize1,size1,size0,visit[30][15],Color[30][15],minX=30,minY=30,maxX=310,maxY=610,speed=500,score=0,rank=0;
  int color[]={GREEN,CYAN,MAGENTA,BROWN,LIGHTGRAY,LIGHTBLUE,LIGHTGREEN,LIGHTRED,YELLOW}; 
  int bricks[7][4][4][4] =
{
	{   // I�ͷ���
		{{0, 0, 0, 0},
		 {0, 0, 0, 0},
		 {1, 1, 1, 1},
		 {0, 0, 0, 0}},

		{{0, 1, 0, 0},
		 {0, 1, 0, 0},
		 {0, 1, 0, 0},
		 {0, 1, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 0, 0, 0},
		 {1, 1, 1, 1},
		 {0, 0, 0, 0}},

		{{0, 1, 0, 0},
		 {0, 1, 0, 0},
		 {0, 1, 0, 0},
		 {0, 1, 0, 0}}
	},
	{   // T�ͷ���
		{{0, 0, 0, 0},
		 {0, 2, 0, 0},
		 {2, 2, 2, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 2, 0, 0},
		 {0, 2, 2, 0},
		 {0, 2, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 0, 0, 0},
		 {2, 2, 2, 0},
		 {0, 2, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 2, 0, 0},
		 {2, 2, 0, 0},
		 {0, 2, 0, 0}},
	},
	{   // L�ͷ���
		{{0, 3, 0, 0},
		 {0, 3, 0, 0},
		 {0, 3, 3, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {3, 3, 3, 0},
		 {3, 0, 0, 0},
		 {0, 0, 0, 0}},	

		{{3, 3, 0, 0},
		 {0, 3, 0, 0},
		 {0, 3, 0, 0},
		 {0, 0, 0, 0}},	

		{{0, 0, 3, 0},
		 {3, 3, 3, 0},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}}
	},            
	{	// J�ͷ���
		{{0, 4, 0, 0},
		 {0, 4, 0, 0},
		 {4, 4, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 4, 0, 0},
		 {0, 4, 4, 4},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 4, 4, 0},
		 {0, 4, 0, 0},
		 {0, 4, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 4, 4, 4},
		 {0, 0, 0, 4},
		 {0, 0, 0, 0}}
	},			
	{	// O�ͷ���
		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}}
	},		
	{   // S�ͷ���
		{{0, 6, 0, 0},
		 {0, 6, 6, 0},
		 {0, 0, 6, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 6, 6, 0},
		 {6, 6, 0, 0},
		 {0, 0, 0, 0}},

		{{6, 0, 0, 0},
		 {6, 6, 0, 0},
		 {0, 6, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 6, 6, 0},
		 {6, 6, 0, 0},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}}
	},
	{	// Z�ͷ���
		{{0, 0, 7, 0},
		 {0, 7, 7, 0},
		 {0, 7, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 7, 7, 0},
		 {0, 0, 7, 7},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 7, 0},
		 {0, 7, 7, 0},
		 {0, 7, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 7, 7, 0},
		 {0, 0, 7, 7},
		 {0, 0, 0, 0}}
	}		
};

	  
  void Interface();//��������
  void nextbricks();//������һ������
  void newbricks();//����һ���ŵ���������
  void move(int x,int y,int A);//�ƶ�����
  int couldmove(int x0,int y0,int A,char dir);//�ж��ܷ��ƶ�
  int couldrotate(int x0,int y0,int A,int next);//�ж��ܷ���ת
  void mark(int x0,int y0,int A);//��Ƿ���̶����λ��
  void full();//�ж���û���ܹ����е�
  void down(int x);//�����еĽ�����ķ�������һ��
  int gameover();//�ж���Ϸ�Ƿ����
  void restart();

  int main()
  {
	  Interface();
	  nextbricks();
	  memset(visit,0,sizeof(visit));
	  getch();
	  while(1)
	  {
		  newbricks();
		  full();
		  if(gameover())
			  break;
	  }
	  getch();
	  closegraph();
	  return 0;
  }

 
  void Interface()
  {
	  int i,j;
	  char str[10];
	  initgraph(850, 660);
	  Sleep(100);
	  for(i=0;i<=255;i++)
		  for(j=0;j<=255;j++)
		  {
			  setcolor(RGB((i+j+128)%255,i,j));
			  setfont(100,0,"����");
			  outtextxy(200,200,"����˹����");
			  setfont(40,0,"����"); 
			  outtextxy(250,500,"--�밴�������ʼ��Ϸ--");
			  if(kbhit()) 
				 break; 
			  Sleep(5);

		  }
		  cleardevice();
		  setcolor(WHITE);
		  rectangle(29,29,334,633);
		  rectangle(28,28,335,634);
		  rectangle(370,50,500,190);
		  setfont(24,0, "����");
		  setcolor(LIGHTGRAY);
		  outtextxy(405,215,"��һ��:");
		  setcolor(YELLOW);
		  outtextxy(405,250,"����:");
		  sprintf(str,"%d",score);
		  outtextxy(415,280,str);
		  outtextxy(405,325,"�ȼ�:");
		  sprintf(str,"%d",rank);
		  outtextxy(425,355,str);

		  setfont(22,0, "����");
		  setcolor(WHITE);
		  outtextxy(390,400,"����˵��:");
		  outtextxy(390,425,"S:��ͣ/��ʼ");
		  outtextxy(390,450,"��: ��ת");
		  outtextxy(390,475,"��: �½�");
		  outtextxy(390,500,"��: ����");
		  outtextxy(390,525,"��: ����");
		  outtextxy(390,550,"�ո�: ֱ�ӽ����ײ�");
		  outtextxy(390,575,"N: ������¹ⱦ���������¿�ʼ����");
		  for(i=0;i<=7;i++)
			  {
				  setcolor(RGB(35*i,255-35*i,255));
				 for(j=i;j<10-i;j++,Sleep(4))
					  outtextxy(600+20*i,30+20*j,"��");
				  for(j=i;j<7-i;j++,Sleep(4))
					  outtextxy(600+20*j,30+20*(15-i),"��");
				  for(j=10-1-i;j>=i;j--,Sleep(4))
					  outtextxy(600+20*(7-i),30+20*j,"��");
				  for(j=7-i;j>=i;j--,Sleep(4))
					  outtextxy(600+20*j,30+20*i,"��");
				 
			  }
  }
 void nextbricks()//��ʾ��һ������
  {
	  int i,j,x=391,y=71;
	  setfont(20,0,"����");
	  setcolor(BLACK);
	  for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
			  outtextxy(x+20*j,y+20*i,"��");
		  srand(time(NULL));
		  a=rand()%9;//ѡ������ɫ
		  setcolor(color[a]);
		  newsize0=rand()%7;//��������
		  newsize1=rand()%4;//��ʼ״̬
		  for(i=0;i<4;i++)
			  for(j=0;j<4;j++)
				  if(bricks[newsize0][newsize1][i][j] != 0)
					  outtextxy(x+20*j,y+20*i,"��");
  } 
void newbricks()//���·�����ϲ��Ž�
  {
	  int x=130,y=30,A=a,i,j;
	  setfont(20,0,"����");
	  
	  for(i=0;i<=7;i++)
			  {
				 // setcolor(RGB(35*i,255-35*i,255));
					setcolor(color[A]);
				  for(j=i;j<10-i;j++,Sleep(4))
					  outtextxy(600+20*i,30+20*j,"��");
				  for(j=i;j<7-i;j++,Sleep(4))
					  outtextxy(600+20*j,30+20*(15-i),"��");
				  for(j=10-1-i;j>=i;j--,Sleep(4))
					  outtextxy(600+20*(7-i),30+20*j,"��");
				  for(j=7-i;j>=i;j--,Sleep(4))
					  outtextxy(600+20*j,30+20*i,"��");
				 /* 	setcolor(BLACK);
				  for(j=i;j<10-i;j++,Sleep(8))
					  outtextxy(600+20*i,30+20*j,"��");
				  for(j=i;j<7-i;j++,Sleep(8))
					  outtextxy(600+20*j,30+20*(29-i),"��");
				  */

			  }

	  setfont(20,0,"����");
	  size1=newsize1;
	  size0=newsize0;
	  nextbricks();
	  move(x,y,A);
  }
 void move(int x,int y,int A)
  {
	  int num = 0;
	  int i,j,f,k=0,Speed=100,key=0,nex;
	  while(1)
	  {
		  f=couldmove(x,y+k,A,'x');
		  if(f==0)
		  {
			  mark(x,y+k,A);
			  break;
		  }
		  if(kbhit())
		  {
			  setcolor(BLACK);
			  for(i=0;i<4;i++)
				  for(j=0;j<4;j++)
					  if(bricks[size0][size1][i][j] != 0 &&y+20*i+k>=30)
						  outtextxy(x+20*j,y+20*i+k,"��");
				  int x0=(y+k-minY)/20;
				  int y0=(x-minX)/20;
				  while (y+20*i+k<=600)
				  {	  if (visit[x0+i][y0+1]!=1)
					  outtextxy(x+20,y+20*i+k,"||");
					  i++;
				  }
			  key=getch();
			  if(key==72)     //����
			  {
				  nex=(size1+1)%4;
				  if(couldrotate(x,y+k,A,nex))
					  size1=nex;
			  }
			  else if (key==80) //����
				  Speed = 10;
			  else if (key==' ')   //�ո��
			  {
				  while (couldmove(x,y+k,A,'x') == 1)
					 k+=20;
				  mark(x,y+k,A);
				  setcolor(color[A]);
				  for(i=0;i<4;i++)
					  for(j=0;j<4;j++)
						  if(bricks[size0][size1][i][j] != 0 &&y+20*i+k>=30)
							  outtextxy(x+20*j,y+20*i+k,"��");
				break;
			  }
			  else if((key==75)&&(couldmove(x,y+k+20,A,'l')))//  ����
				  x-=20;
			  else if((key==77)&&(couldmove(x,y+k+20,A,'r')))//  ����
				  x+=20;	  
			  else if(key=='s')
			  {
				  while (getch()!='s')
					getch();
			  }
			  else if(key=='n')
			  {
			    restart();
				break;
			  }
		  }

		  if (num % 50 == 0) 
		  {
			  setcolor(BLACK);
			  for(i=0;i<4;i++)
				  for(j=0;j<4;j++)
					  if(bricks[size0][size1][i][j] != 0 &&y+20*i+k>=30)
						  outtextxy(x+20*j,y+20*i+k,"��");
					  int x0=(y+k-minY)/20;
				  int y0=(x-minX)/20;
				  while (y+20*i+k<=600)
				  {	  if (visit[x0+i][y0+1]!=1)
					  outtextxy(x+20,y+20*i+k,"||");
					  i++;
				  }
			k+=20;
			
		  }
		  if ((key!=0)||(num % 50 == 0))
		  {
		    setcolor(color[A]);
			  for(i=0;i<4;i++)
				  for(j=0;j<4;j++)
					  if(bricks[size0][size1][i][j] != 0 &&y+20*i+k>=30)
						  outtextxy(x+20*j,y+20*i+k,"��");
			key=0;
			int x0=(y+k-minY)/20;
				  int y0=(x-minX)/20;
				  setcolor(WHITE);
				  while ((visit[x0+i][y0+1]!=1)&&(y+20*i+k<=600))
				  {
					  outtextxy(x+20,y+20*i+k,"||");
					  i++;
				  }

          }
		  Sleep(Speed / 10);
		  num++;
	}
  }
  int couldmove(int x0,int y0,int A,char dir)
  {
	  int i,j,x,y,f=1;//f=0��ʾ�����ƶ�
	  x=(y0-minY)/20;
	  y=(x0-minX)/20;//����
	  if(dir=='x')//����
	  {
		  for(i=0;i<4;i++)
			  for(j=0;j<4;j++)
			  if(bricks[size0][size1][i][j] != 0
				 &&(x+i+1==30||(x+i+1>=0&&x+i+1<30&&y+j>=0&&y+j<15&&visit[x+i+1][y+j]==1))) 
				   f=0;
	  }
	  else if(dir=='l')
	  {
		  for(i=0;i<4;i++)
			  for(j=0;j<4;j++)
				  if(bricks[size0][size1][i][j] != 0&&(y+j==0||(x+i>=0&&x+i<30&&y+j-1>=0&&y+j-1<15&&visit[x+i][y+j-1]==1)))
					  f=0;
	  }
	  else if(dir=='r')
	  {
		  for(i=0;i<4;i++)
			  for(j=0;j<4;j++)
				  if(bricks[size0][size1][i][j] != 0&&(y+j+1==15||(x+i>=0&&x+i<30&&y+j+1>=0&&y+j+1<15&&visit[x+i][y+j+1]==1)))
					  f=0;
	  }
	  return f;
  }
  int couldrotate(int x0,int y0,int A,int next)
  {
	  int i,j,x,y,f=1;
	  x=(y0-minY)/20;
	  y=(x0-minX)/20;
	  if(!couldmove(x0,y0,A,'x'))
		  f=0;
	  for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
			  if(bricks[size0][next][i][j] != 0&&(y+j==-1||y+j==15||(x+i>=0&&x+i<30&&y+j>=0&&y+j<15&&visit[x+i][y+j]==1)))
				  f=0;
			  return f;
  }
  void mark(int x0,int y0,int A)
  {
	  int i,j,x,y;
	  x=(y0-minY)/20;
	  y=(x0-minX)/20;
	  for(i=0;i<4;i++)
		  for(j=0;j<4;j++)
			  if(bricks[size0][size1][i][j] != 0)
			  {
				  visit[x+i][y+j]=1;
				  Color[x+i][y+j]=color[A];
			  }
			  setcolor(BLACK);
	          while (y0+20*i<=600)
				  {	  if (visit[x+i][y+1]!=1)
					  outtextxy(x0+20,y0+20*i,"||");
					  i++;
				  }
  }
  void full()//�ж���û���ܹ���
  {
	  int i,j,k=0;
	  char str[10];
	  for(i=29;i>=0;i--)
	  {
		  for(j=0;j<15;j++)
			  if(visit[i][j]==0)
				  break;
			  if(j==15)
			  {
				  k++;
				  down(i);
				  i++;
			  }
	  }
	  setfont(24,0, "����");

	  setcolor(YELLOW);
	  if (k==1) score+=100;
	  else if (k==2) score+=200;
	  else if (k==3) score+=400;
	  else score+=200*k;

	  sprintf(str,"%d",score);
	  outtextxy(415,280,str);
	  rank=(score/50);
	  sprintf(str,"%d",rank);
	  outtextxy(425,355,str);
  }
  void down(int x)//�����еĽ�����ķ�������һ��
  {
	  int i,j;
	  for(i=x;i>0;i--)
		  for(j=0;j<15;j++)
			  if(visit[i-1][j]==1)
			  {
				  visit[i][j]=visit[i-1][j];
				  Color[i][j]=Color[i-1][j];
				  setcolor(Color[i-1][j]);
				  outtextxy(minX+20*j,minY+20*i,"��");
			  }
			  else
			  {
				  visit[i][j]=visit[i-1][j];
				  setcolor(BLACK);
				  outtextxy(minX+20*j,minY+20*i,"��");
			  }
			  setcolor(BLACK);
			  for(j=0;j<15;j++)
			  {
				  visit[0][j]=0;
				  outtextxy(minX+20*j,minY,"��");
			  }
			  for(i=0;i<=7;i++)
			  {
				  setcolor(BLACK);
				  for(j=i;j<10-i;j++,Sleep(8))
					  outtextxy(600+20*i,30+20*j,"��");
				  for(j=i;j<7-i;j++,Sleep(8))
					  outtextxy(600+20*j,30+20*(15-i),"��");
				  for(j=10-1-i;j>=i;j--,Sleep(8))
					  outtextxy(600+20*(7-i),30+20*j,"��");
				  for(j=7-i;j>=i;j--,Sleep(8))
					  outtextxy(600+20*j,30+20*i,"��");
				 /* 	setcolor(BLACK);
				  for(j=i;j<10-i;j++,Sleep(8))
					  outtextxy(600+20*i,30+20*j,"��");
				  for(j=i;j<7-i;j++,Sleep(8))
					  outtextxy(600+20*j,30+20*(29-i),"��");
				  */

			  }
  }
  int gameover()
  {
	  int i,j;
	  for(i=0;i<15;i++)
		  if(visit[0][i]==1)
		  {
			  for(i=0;i<=7;i++)
			  {
				  setcolor(RGB(35*i,255-35*i,255));
				  for(j=i;j<30-i;j++,Sleep(20))
					  outtextxy(30+20*i,30+20*j,"��");
				  for(j=i;j<15-i;j++,Sleep(20))
					  outtextxy(30+20*j,30+20*(29-i),"��");
				  for(j=30-1-i;j>=i;j--,Sleep(20))
					  outtextxy(30+20*(14-i),30+20*j,"��");
				  for(j=15-1-i;j>=i;j--,Sleep(20))
					  outtextxy(30+20*j,30+20*i,"��");
			  }
			  setcolor(WHITE);
			  setfont(45,0,"����");
			  outtextxy(75,300,"GAME OVER!");
			  Sleep(5000);
			  return 1;
		  }
		  return 0;
  }
  void restart()
  {
	int i,j;
	char str[10];
	score = 0;
	setfont(24,0, "����");
	setcolor(BLACK);
	outtextxy(415,280,"����������");
	outtextxy(425,355,"����������");
	setcolor(YELLOW);
	sprintf(str,"%d",score);
	outtextxy(415,280,str);
	rank=0;
    sprintf(str,"%d",rank);
    outtextxy(425,355,str);
    setcolor(BLACK);
	  for(i=0;i<=7;i++)
	  {
		  for(j=i;j<30-i;j++)
			  outtextxy(30+20*i,30+20*j,"����");
		  for(j=i;j<15-i;j++)
			  outtextxy(30+20*j,30+20*(29-i),"��");
		  for(j=30-1-i;j>=i;j--)
			  outtextxy(30+20*(14-i),30+20*j,"��");
		  for(j=15-1-i;j>=i;j--)
			  outtextxy(30+20*j,30+20*i,"��");
	  }
	  nextbricks();
	  memset(visit,0,sizeof(visit));
	  newbricks();
  }
