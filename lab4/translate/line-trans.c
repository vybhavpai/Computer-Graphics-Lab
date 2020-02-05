#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float start_x,start_y,end_x,end_y;
float tx = 0.0,ty = 0.0;





void display(){
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(start_x,start_y);
	glVertex2f(end_x,end_y);
	
	glVertex2f(start_x + tx,start_y + ty);
	glVertex2f(end_x + tx,end_y + ty);
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

	printf("\nEnter the translation factor\ntx:");
	scanf("%f",&tx);
	printf("ty:");
	scanf("%f",&ty);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Translate-Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}