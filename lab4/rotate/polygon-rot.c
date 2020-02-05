#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Factor 3.14159265/180


float *x,*y,*x_scale,*y_scale;
float angle = 90.0;
int n = 3;

void display(){

	float tempx2,tempy2;

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	for(int i=0;i<n;i++){
		glVertex2f(x_scale[i],y_scale[i]);
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(int i=0;i<n;i++){
		glVertex2f(x[i],y[i]);
	}
	glEnd();
	glFlush();
}




void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
}

int main(int argc,char* argv[]){
	float tempx2,tempy2;
	printf("Enter the number of sides in the polygon\nn : ");
	scanf("%d",&n);
	if(n < 3){
		printf("Value entered too less enter coordinates of a triangle\n");
		n = 3;
	}

	x = (float *)malloc(n*sizeof(float));
	y = (float *)malloc(n*sizeof(float));
	x_scale = (float *)malloc(n*sizeof(float));
	y_scale = (float *)malloc(n*sizeof(float));
	
	printf("Enter the coordinates in the clockwise direction\n");

	for(int i = 0;i<n;i++){
		printf("Enter the x coord of vertex %d\nx:",i+1);
		scanf("%f",&x[i]);
		printf("y:");
		scanf("%f",&y[i]);
		printf("\n");
	}	
	
	printf("Enter the angle in degree to rotate it by\nangle:");
	scanf("%f",&angle);

	for(int i = 0;i<n;i++){
		x_scale[i] = x[i]-x[0];
		y_scale[i] = y[i]-y[0];
		tempx2 = x_scale[i];
		tempy2 = y_scale[i];
		x_scale[i] = tempx2*cos(angle*Factor)-tempy2*sin(angle*Factor);
		y_scale[i] = tempx2*sin(angle*Factor)+tempy2*cos(angle*Factor);
		x_scale[i] = x_scale[i]+x[0];
		y_scale[i] = y_scale[i]+y[0];		
			
	}

	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Translate-Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}