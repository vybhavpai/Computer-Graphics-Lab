#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
float red = 0.0;
float blue = 0.0;
float green = 0.0;


void drawSolid(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red,green,blue);
    glutSolidTeapot(.5);

    glFlush();
}

void drawWired(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red,green,blue);
    glutWireTeapot(.5);

    glFlush();
}

void Clear(){
	glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

void solid(int choice){
	red = 0.0;
	green = 0.0;
	blue = 0.0;
	
	switch(choice){
		case 1:
				red = 1.0;
				green = 1.0;
				blue = 1.0;
				drawSolid();
				break;

		case 2:
				red = 1.0;
				drawSolid();
				break;

		case 3:
				green = 1.0;
				drawSolid();				
				break;

		case 4:
				blue = 1.0;
				drawSolid();
				break;

	}
}
void wired(int choice){
	red = 0.0;
	green = 0.0;
	blue = 0.0;
	
	switch(choice){
		case 1:
				red = 1.0;
				green = 1.0;
				blue = 1.0;
				drawWired();
				break;

		case 2:
				red = 1.0;
				drawWired();
				break;

		case 3:
				green = 1.0;
				drawWired();				
				break;

		case 4:
				blue = 1.0;
				drawWired();
				break;

	}
}

void teapot(int choice){
	switch(choice){
		case 1:
				Clear();
				break;
		case 2:
				exit(0);
				break;
	}
}

void display(){

}

void init(){
	glClearColor(0,0,0,1);
	// gluOrtho2D(-300,300,-300,300);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}


int main(int argc,char* argv[]){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("menu driven");

	int solid_subMenu = glutCreateMenu(solid);
	glutAddMenuEntry("Default", 1);
	glutAddMenuEntry("Red",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("Blue",4);
	
	int wired_subMenu = glutCreateMenu(wired);
	glutAddMenuEntry("Default", 1);
	glutAddMenuEntry("Red",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("Blue",4);
	
	int menu = glutCreateMenu(teapot);
	glutAddSubMenu("Solid Teapot", solid_subMenu);
	glutAddSubMenu("Wired Teapot", wired_subMenu);
	glutAddMenuEntry("Clear", 1);
	glutAddMenuEntry("Exit", 2);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}