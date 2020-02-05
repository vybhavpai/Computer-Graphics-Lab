#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float start_x,start_y,end_x,end_y;
float scale = 0.0;
bool show_scale = false;




void display(){

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	if(!show_scale){	
		glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex2f(start_x,start_y);
		glVertex2f(end_x,end_y);
		glEnd();
	}

	float x,y;

	if(show_scale){	

		x = start_x + (end_x - start_x)*scale;
		y = start_y + (end_y - start_y)*scale;
		glBegin(GL_LINES);
		glColor3f(0,0,1);
		glVertex2f(start_x,start_y);
		glVertex2f(x,y);
		glEnd();
	}

	glutSwapBuffers();
	show_scale = !show_scale;
}


void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
}

void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(1000,Timer,0);
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

	printf("\nEnter the scaling factor\nscale:");
	scanf("%f",&scale);
	if(scale<0)
		scale *= -1;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Translate-Line");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(0,Timer,0);
	glutMainLoop();


}