#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Factor 3.14159265/180

float start_x,start_y,end_x,end_y;
float angle = 90.0;


void display(){
	glBegin(GL_LINES);

	glColor3f(1,0,0);
	glVertex2f(start_x,start_y);
	glVertex2f(end_x,end_y);
	
	glEnd();

	float tempx2=end_x,tempy2=end_y;
	
	end_x = tempx2*cos(angle*Factor)-tempy2*sin(angle*Factor);
	end_y = tempx2*sin(angle*Factor)+tempy2*cos(angle*Factor);

	tempx2 = start_x;
	tempy2 = start_y;
	start_x = tempx2*cos(angle*Factor)-tempy2*sin(angle*Factor);
	start_y = tempx2*sin(angle*Factor)+tempy2*cos(angle*Factor);


	glBegin(GL_LINES);

	glColor3f(1,0,0);
	glVertex2f(start_x,start_y);
	glVertex2f(end_x,end_y);
	
	glEnd();
	
	glFlush();	
	
	
}


void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
}

int main(int argc,char* argv[]){

	printf("Enter the first point of the line\nx1:");
	scanf("%f",&start_x);
	printf("y1:");
	scanf("%f",&start_y);
	
	printf("Enter the second point of the line\nx2:");
	scanf("%f",&end_x);
	printf("y2:");
	scanf("%f",&end_y);

	printf("Enter the angle in degree to rotate it by\nangle:");
	scanf("%f",&angle);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Translate-Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}