#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define UP 8
#define DOWN 4
#define RIGHT 2
#define LEFT 1

float min_x,max_x,min_y,max_y;
float a1,a2,a3,b1,b2,b3;

int code(int x,int y){
	int c = 0;
	if(y > max_y)
			c = 8;
	if(y < min_y)
			c = 4;

	if(x > max_x)
			c = c | 2;
	if(x < min_x)
			c = c | 1;

	return c;

}

void drawinside(float x1,float y1,float x2,float y2){

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}

void drawoutside(float x1,float y1,float x2,float y2){

	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}

void cohen(float u1,float v1,float u2,float v2){

	float start_x = u1;
	float start_y = v1;
	float end_x = u2;
	float end_y = v2;

	int code1,code2;
	float m = (end_y - start_y)/(end_x - start_x);

	printf("\nstart : %f %f\nend : %f %f\n",start_x,start_y,end_x,end_y);
	code1 = code(start_x,start_y);
	code2 = code(end_x,end_y);

	if( (code1 | code2) == 0){
		drawinside(start_x,start_y,end_x,end_y);
		return;
	}

	if( (code1 & code2) != 0){
		drawoutside(start_x,start_y,end_x,end_y);
		return;
	}

	float x1 = start_x,x2 = end_x,y1 = start_y,y2 = end_y;
	float x,y;
	int c;

	while( (code1 | code2) != 0){
		x = x1;
		y = y1;
		c = code1;

	if(c == 0){
		x = x2;
		y = y2;
		c = code2;
	}
	printf("chose %f %f %d\n",x,y,c);
	
	if((c & 8)>0)
    {
       x=x+ 1.0/m*(max_y-y);
       y=max_y;
    }
    else
      if((c & 4)>0)
      {
          x=x+1.0/m*(min_y-y);
          y=min_y;
      }
      else
       if((c & 2)>0)
       {
           y=y+m*(max_x-x);
           x=max_x;
       }
       else
       if((c & 1)>0)
       {
           y=y+m*(min_x-x);
           x=min_x;
       }
	printf("got %f %f %d\n",x,y,c);
	
       if(c==code1)
       {
           x1=x;
           y1=y;
           code1=code(x1,y1);

       }

       if(c==code2)
       {
           x2=x;
           y2=y;
           code2=code(x2,y2);
       }



	}
	printf("%f %f\n",start_x,start_y);
	printf("%f %f\n",x1,y1);
	printf("%f %f\n",x2,y2);
	printf("%f %f\n",end_x,end_y);

	drawinside(x1,y1,x2,y2);
	drawoutside(start_x,start_y,x1,y1);
	drawoutside(x2,y2,end_x,end_y);

}

void display(){
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(min_x,min_y);
	glVertex2f(min_x,max_y);
	glVertex2f(max_x,max_y);
	glVertex2f(max_x,min_y);
	glEnd();	
	
	cohen(a1,b1,a3,b3);

	cohen(a1,b1,a2,b2);

	cohen(a2,b2,a3,b3);

	glFlush();

}

void init(){
	glClearColor(1,1,1,1);
	gluOrtho2D(-300,300,-300,300);
	glClear(GL_COLOR_BUFFER_BIT);;
}


void main(int argc, char* argv[]){

	printf("Enter the clipping area co-ordinates\nmin_x : ");
	scanf("%f",&min_x);
	printf("min_y : ");
	scanf("%f",&min_y);
	printf("max_x : ");
	scanf("%f",&max_x);
	printf("max_y : ");
	scanf("%f",&max_y);

	printf("Enter the co-ordinates of 1st point\nx1 : ");
	scanf("%f",&a1);
	printf("y1 : ");
	scanf("%f",&b1);
	printf("Enter the co-ordinates of 2nd point\nx2 : ");
	scanf("%f",&a2);
	printf("y2 : ");
	scanf("%f",&b2);
	printf("Enter the co-ordinates of 3rd point\nx3 : ");
	scanf("%f",&a3);
	printf("y3 : ");
	scanf("%f",&b3);

	// if(end_x == start_x){

	// }
	// else
		

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("clipping");

	init();
	glutDisplayFunc(display);
	glutMainLoop();


}
