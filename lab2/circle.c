#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float xc,yc,r;

void draw8points(float xc,float yc, float x,float y){
	glBegin(GL_POINTS);
	glColor3f(0,0,1);
	glVertex2i(xc+x,yc+y);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc-x,yc-y);
	
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc+y,yc-x);
	glVertex2i(xc-y,yc+x);
	glVertex2i(xc-y,yc-x);
	glEnd();
}

void bres(float xc,float yc,float r){
	float x = 0;
	float y = r;
	float dec_param = 3-2*r;
	do{
		draw8points(xc,yc,x,y);
		x++;
		if(dec_param < 0){
			dec_param = dec_param + 4*x + 6;
		}
		else{
			y--;
			dec_param = dec_param + 4*(x-y) + 10;	
		}
	}while(x<=y);
	glFlush();
}

void initialize(){
	glClearColor(1,1,1,1);
	gluOrtho2D(-200.0,200.0,-200.0,200.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void display(){
	bres(xc,yc,r);
}
int main(int argc,char* argv[]){
	

	printf("enter the centre of the circle\nx : ");
	scanf("%f",&xc);
	printf("y : ");
	scanf("%f",&yc);

	printf("enter the radius of the circle\nr : ");
	scanf("%f",&r);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);

	glutCreateWindow("bresenham-circle");
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();
	

}