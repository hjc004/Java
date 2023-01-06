// circle algorithm.cpp : Defines the entry point for the console application.
//

//This program was updated by Ms Huang Jing in Beijing Normal Unbersity Zhuhai Campus 
//  in Oct 20 in 2012,Contact email: 306744855@qq.com 

#include "stdafx.h"

#include <glut.h>
//#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

#define N 1000       //maximum line numbers

int cx=150,cy=150,radius=80,ri=50,ro=80,n=3,samples=1,flag=1;
int ww,hh;     // for display window width and height
int line[N][4], k=0;  //for line's endpoint coordinates and line number

void Myinit(void);
void plotC(int x,int y,int xc,int yc);
void Bresenham_Circle_Algorithm(int cx, int cy, int radius);
void DrawOneLine(int x1,int y1,int x2,int y2);
void NSidedPolygon(int n, int cx, int cy, int radius);
void SampleCircle(int inner, int outer, int samples, int cx, int cy);
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void Drawlines();
void myMouse(int button,int state,int x,int y);
void myMotion(int x,int y);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 
	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutCreateWindow("Basic_Primitive_Algorithm");
   Myinit();  //��ʼ����
   glutDisplayFunc(Display);  //ע�������Ӧ�ص�����
   glutKeyboardFunc(Keyboard);  //ע�������Ӧ�ص�����
   glutReshapeFunc(Reshape);    //ע�ᴰ�ڸı�ص�����
    glutMouseFunc(myMouse);    //ע����갴ť�ص�����
    glutMotionFunc(myMotion);  //ע������ƶ��ص�����
   glutMainLoop();
   return 0;
}


void Myinit(void)
{
glClearColor(0.0,0.0,0.0,0.0);  //����ɫ
glLineWidth(4.0);  //�߿�
}

void Display(void)
{
  
	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //���þ���ģʽΪģ�ͱ任ģʽ����ʾ����������ϵ��
    glLoadIdentity();   //����ǰ��������Ϊ��λ����

	if (flag==1)  //��Բ
      Bresenham_Circle_Algorithm(cx,cy,radius);
	if (flag==2)  //�������
      NSidedPolygon(n,cx,cy,radius);
	if (flag==3)  //����Բ
	   SampleCircle(ri,radius,samples,cx,cy);  
    if (flag==4)  //��껮��
	  Drawlines();
		
     glutSwapBuffers();
}


void Keyboard(unsigned char key, int x, int y)
{
   switch(key)
 {

   case 'r':
	   if ((flag==1)&&(radius>1))  radius--; //������Բʱ�뾶��С
	   if ((flag==3)&&(radius>ri)) radius--;  //����Բʱ�⾶��С
	   break;
   case 'R':     
        if ((radius<ww/2)&&(radius<hh/2))
          radius++;  //�뾶����
		break;
   case 'n':     
        if ((flag==2)&&(n>3)) n--;  //����α����ݼ�
		break;
   case 'N':     
        if (flag==2) n++;  //����α�������
		break;
   case 'i':
	   if ((flag==3)&&(ri>1)) ri--;  //����Բʱ�ھ���С
	   break;
   case 'I':     
        if ((flag==3)&&(ri<radius)) ri++;  //����Բʱ�ھ����
		break;
   case 's':     
        if (samples>1) samples--; //����������
		break;
   case 'S':     
        samples++;   //����������
		break;
   case 'a':     
       //cancel antialias 
	    glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
		break;
   case 'A':     
	    //enable antialias 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glEnable(GL_POINT_SMOOTH);
        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_POLYGON_SMOOTH);
		break;
   case '1':
	   flag=1;  //��Բ
	   break;
   case '2':
	   flag=2;  //�������
	   break;
   case '3':
       flag=3;   //����Բ
	   //cancel antialias 
	    glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
	   break;
   case '4':
       flag=4;  //��껮��
       for (int i=0;i<=k;i++)
	   {
		   line[i][0]=0;
		   line[i][1]=0;
		   line[i][2]=0;
		   line[i][3]=0;
	   }
	   k=0;
	   break;

	 case 27:
	    exit(0);
	//  default:
	//	 return;
   }

     glutPostRedisplay();
}


void Reshape(int w, int h)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();   
   glViewport(0, 0, w, h);
   gluOrtho2D(0, w, 0, h);
   ww=w;
   hh=h;
   cx=w/2;
   cy=h/2;
}

void Bresenham_Circle_Algorithm(int cx, int cy, int radius)
{
   /* YOUR CODE HERE ,
   Update the followling codes with Bresenham_Circle_Algorithm  */
       
 
   
	glColor3f(1,1,1);
    glTranslatef(cx,cy,0);
    glutWireSphere(radius,40,40);
    
}


void NSidedPolygon(int n, int cx, int cy, int radius)
{
    
  int x[100],y[100];  
  double angle;
   
  angle=2*3.1415926/n;  

  glColor3f(1,1,1);

   for (int i=0;i<=n;i++)
   {
	   x[i]=(int)(cx+radius*cos(i*angle));
	   y[i]=(int)(cy+radius*sin(i*angle));	   	  
   }

   for (int i=0;i<=(n-1);i++) 
   {
	   DrawOneLine(x[i],y[i],x[i+1], y[i+1]); 
   }

}


void DrawOneLine(int xa, int ya, int xb, int yb)
{
  
	/* YOUR CODE HERE */
  //update the following codes with DDA line algorithm

	glColor3f(1,1,1);
	glBegin(GL_LINES);
	 glVertex2f(xa,ya);
	 glVertex2f(xb,yb);
	glEnd();	
  

}


void  Drawlines()  
{

	
	   for(int i=0;i<=k;i++) //********
		{
			DrawOneLine(line[i][0],line[i][1], line[i][2],line[i][3]);
			
		}
}


void SampleCircle(int inner, int outer, int samples, int cx, int cy)
{
   
    float r2, ro2,ri2;   //r2Ϊ�����صİ뾶
    int x,y,nx,ny;   //x,y Ϊ��Բ�ڵ�һ�� 
    float color_value;  //��ɫ����
    int count; //�����ϸ��������
    

     //#########  Calculate outer radius's square and inner's square 

      ro2=outer*outer;   //��Բ�⾶ƽ��
      ri2=inner*inner;   //��Բ�ھ�ƽ��
	
     //#########  for each pixel(x,y), testing its sample 

	  //1/4��Բ�ڵĵ����
	for (x=0;x<outer;x++)
	 for (y=0;y<=outer;y++)
	 {
	   
         //######## count available subpixels for each pixel      
		    count=0;	
          
			//ÿ�����зֳ�smaples*samples��������
			//�ж��������Ƿ�����Բ��
	   	 for (nx=0;nx<=samples; nx++)
		  for (ny=0;ny<=samples;ny++)		   
		   {
		      r2=(x+(float)nx/(float)samples)*(x+(float)nx/(float)samples);
		      r2=r2+(y+(float)ny/(float)samples)*(y+(float)ny/(float)samples);

			   if ((r2<=ro2) && (r2>=ri2))  count++; //�����ϸ��������

             }
		            
		  
              //########## calculate color gray level for each pixel
		 color_value=((float)count)/(((float)samples+1.0)*((float)samples+1.0));

              //########## draw pixel by using the color calculated above
		  glColor3f(color_value,color_value,color_value);
                  
		       //�Գƻ���
                glBegin(GL_POINTS); 
		       glVertex2f(cx+x,cy+y);
               glVertex2f(cx+x,cy-y);
		       glVertex2f(cx-x,cy+y);
		       glVertex2f(cx-x,cy-y);
                glEnd();
		
      }
}

//��갴ť��Ӧ�¼�..
void myMouse(int button,int state,int x,int y)
{
 
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
	   line[k][0]=x;   //�߶����x����
	   line[k][1]=hh-y;  //�߶����y����
	}

	if(button==GLUT_LEFT_BUTTON&&state==GLUT_UP)
	{
			line[k][2]=x;   //�߶��յ�x����
			line[k][3]=hh-y;   //�߶��յ�y����
			k++;
		glutPostRedisplay();
	 }

}

//����ƶ�ʱ�������ƶ��е�����-----------------------------------------------------
void myMotion(int x,int y)
{
	
	 //get the line's motion point
		line[k][2]=x;   //��̬�յ��x����
		line[k][3]=hh-y;  //��̬�յ��y����  
	glutPostRedisplay();
	
}
