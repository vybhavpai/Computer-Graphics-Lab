#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float *x,*y;
float tx = 0.0,ty = 0.0;
int n = 3;

void display(){
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(int i=0;i<n;i++){
		glVertex2f(x[i],y[i]);
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(int i=0;i<n;i++){
		glVertex2f(x[i]+tx,y[i]+ty);
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

	printf("Enter the number of sides in the polygon\nn : ");
	scanf("%d",&n);
	if(n < 3){
		printf("Value entered too less enter coordinates of a triangle\n");
		n = 3;
	}

	x = (float *)malloc(n*sizeof(float));
	y = (float *)malloc(n*sizeof(float));
	printf("Enter the coordinates in the clockwise direction\n");

	for(int i = 0;i<n;i++){
		printf("Enter the x coord of vertex %d\nx:",i+1);
		scanf("%f",&x[i]);
		printf("y:");
		scanf("%f",&y[i]);
		printf("\n");
	}	

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