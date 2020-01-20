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
	glPointSize(2.0);
	
}

void vertex(float x,float y){

	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	glEnd();
}

float absol(float x){
	if(x<0.0)
		return -x;
	return x;
}

void display(){
	float dx,dy,x,y,temp,incx,incy;
	int dif;
	if(absol(X2-X1)>absol(Y2-Y1)){
		printf("inside if\n");
		if(X2<X1){
			printf("swapping\n");
			temp = X2;
			X2 = X1;
			X1 = temp;

			temp = Y2;
			Y2 = Y1;
			Y1 = temp;
				
		}
		dx = X2-X1;
		dy = Y2-Y1;
		printf("%f %f\n",X1,Y1);
		printf("%f %f\n",X2,Y2);
		
		incx = 1.0;
		incy = dy/dx;
		dif=dx;
		x = X1;
		y = Y1;

		for(int i = 0;i<dif;i++){
			vertex(x,y);
			x = x+incx;
			y = y+incy;
		}
	}
	else{
		printf("inside else\n");
		if(Y2<Y1){
			printf("swapping\n");
			temp = X2;
			X2 = X1;
			X1 = temp;

			temp = Y2;
			Y2 = Y1;
			Y1 = temp;
				
		}
		dx = X2-X1;
		dy = Y2-Y1;
		printf("%f %f\n",X1,Y1);
		printf("%f %f\n",X2,Y2);
		
		incx = dx/dy;
		incy = 1.0;
		dif=dy;
		x = X1;
		y = Y1;

		for(int i = 0;i<dif;i++){
			vertex(x,y);
			x = x+incx;
			y = y+incy;
		}

	}
	// glBegin(GL_POINTS);
	// glColor3f(1,1,1);
	// glVertex2i(100.0,100.0);
	// glEnd();

	glFlush();  // Render now
}


int main(int argc, char* argv[]){
	printf("Enter the 1st point\nx: ");
	scanf("%f",&X1);
	printf("y: ");
	scanf("%f",&Y1);

	printf("Enter the 2nd point\nx: ");
	scanf("%f",&X2);
	printf("y: ");
	scanf("%f",&Y2);

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
