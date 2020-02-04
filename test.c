#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float X1,Y1,X2,Y2;

void initialize(){
	glClearColor(1,1,1,0.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250.0, 250.0,-250.0, 250.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);
	
}


void display(){
	float dx,dy,x,y,temp,incx,incy;
	int dif;
	glBegin(GL_POINTS);
	glScalef(2.0,2.0,2.0);
	
	glColor3f(1,0,0);
	glVertex2i(50,50);
	glEnd();
	glFlush();  // Render now
}


int main(int argc, char* argv[]){
	

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);

	glutCreateWindow("dda");
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();

return 1;
}