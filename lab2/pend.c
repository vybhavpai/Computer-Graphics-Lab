#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float xc,yc,r,w,h;
void initialize(){
	glClearColor(1,1,1,1);
	gluOrtho2D(-250.0,250.0,-250.0,250.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void draw8points(float x,float y){
	glBegin(GL_POINTS);
	glColor3f(1,0,0);

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

void circle(){
	float x = 0, y = r;
	float d = 3 - 2*r;
	do{
		draw8points(x,y);
		x++;
		if(d>0){
			y--;
			d = d +4*(x-y) + 10;
		}
		else{
			d = d + 4*x + 6;
		}
	}while(x<=y);

	glFlush();
}
void drawpoint(int x,int y){
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	glEnd();
}
void line(float x1,float y1,float x2,float y2){

	int incx =1, incy =1, inc1, inc2;
	int dx, dy, dec;
	int x,y,i;

	dx = x2-x1;
	dy = y2-y1;
	if(dx<0){
		dx = -dx;
		incx = -incx;
	}
	if(dy<0){
		dy = -dy;
		incy = -incy;
	}

	x = x1;
	y = y1;

	if(dx>dy){
		drawpoint(x,y);
		dec = 2*dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for(i=0;i<dx;i++){
			if(dec>=0){
				y += incy;
				dec += inc1;
			}
			else{
				dec += inc2;
			}
			x += incx;
			drawpoint(x,y);
		}
	}
	else{
		drawpoint(x,y);
		dec = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for(i=0;i<dy;i++){
			if(dec>=0){
				x += incx;
				dec += inc1;
			}
			else{
				dec += inc2;
			}
			y += incy;
			drawpoint(x,y);
		}	
	}

}
void display(){
	circle();

	float y1,y2;
	y1 = yc + sqrt((double)(r*r+w*w/4));
	y2 = y1 + h;

	line(xc-w/2,y1,xc-w/2,y2);
	line(xc+w/2,y1,xc+w/2,y2);
	line(xc-w/2,y2,xc+w/2,y2);

	glFlush();

}



int main(int argc,char* argv[]){
	printf("Enter the centre of the circle which is at the bottom of the pendulum\nx : ");
	scanf("%f",&xc);
	printf("y : ");
	scanf("%f",&yc);
	printf("Enter its radius\nr : ");
	scanf("%f",&r);

	printf("enter width of the pendulum\nNote : it should be less than radius\n");
	scanf("%f",&w);
	printf("enter height of the pendulum\nNote : it should be less than %f to fit in window\n",200-yc-r);
	scanf("%f",&h);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);

	glutCreateWindow("pendulum");
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();



}