#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


float *x,*y,*x_scale,*y_scale;
float tx = 0.0,ty = 0.0;
int n = 3;
float scale = 0.0;
bool show_scale = false;

void display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	if(show_scale){
		glBegin(GL_POLYGON);
		glColor3f(0,0,1);
		for(int i=0;i<n;i++){
			glVertex2f(x_scale[i]+x[0],y_scale[i]+y[0]);
		}
		glEnd();
	}
	else{
		glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		for(int i=0;i<n;i++){
			glVertex2f(x[i],y[i]);
		}
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



	printf("\nEnter the scaling factor\nscale:");
	scanf("%f",&scale);
	if(scale<0)
		scale *= -1;

	for(int i = 0;i<n;i++){
		x_scale[i] = x[i]-x[0];
		y_scale[i] = y[i]-y[0];
		x_scale[i] *= scale;
		y_scale[i] *= scale;
			
	}

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