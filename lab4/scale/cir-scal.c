#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float x,y,r;
float tx = 0.0,ty = 0.0;
float scale = 0.0;
bool is_blue = true;

void draw8points(float xc,float yc, float x,float y){
	glBegin(GL_POINTS);
	if(is_blue)
		glColor3f(0,0,1);
	else
		glColor3f(0,1,0);
	
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

void display(){

	bres(x,y,r);
	is_blue = false;
	bres(x,y,r*scale);
	
	glFlush();
}




void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
}

int main(int argc,char* argv[]){

	printf("Enter the centre of the circle\nxc:");
	scanf("%f",&x);
	printf("yc:");
	scanf("%f",&y);
	printf("Enter the radius of the circle\nr:");
	scanf("%f",&r);

	printf("\nEnter the scaling factor\nscale:");
	scanf("%f",&scale);
	if(scale<0)
		scale *= -1;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Translate-Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}