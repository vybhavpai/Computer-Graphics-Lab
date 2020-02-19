#include <GL/glut.h>
#include <stdio.h>

static GLfloat input[8][3]=
{
    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
    {30,30,0},{80,30,0},{80,80,0},{30,80,0}

};
static GLfloat input1[4][3]=
{
    
    {0,0,100},{100,0,0},{0,0,-100},{-100,0,0}

};
int choice;
float output[8][3],output1[4][3],outputapex[3];

static GLfloat apex[3] = {0,100,0};
void drawCube(float a[8][3])
{

glBegin(GL_QUADS);
glColor3f(0.7,0.4,0.5); //behind
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[3]);

glColor3f(0.8,0.2,0.4);  //bottom
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[5]);
glVertex3fv(a[4]);

glColor3f(0.3,0.6,0.7); //left
glVertex3fv(a[0]);
glVertex3fv(a[4]);
glVertex3fv(a[7]);
glVertex3fv(a[3]);

glColor3f(0,1,0);  //right
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[6]);
glVertex3fv(a[5]);

glColor3f(1,0,0); //up
glVertex3fv(a[2]);
glVertex3fv(a[3]);
glVertex3fv(a[7]);
glVertex3fv(a[6]);

glColor3f(0,0,1);
glVertex3fv(a[4]);
glVertex3fv(a[5]);
glVertex3fv(a[6]);
glVertex3fv(a[7]);

glEnd();


		glFlush();
}

void drawPyramid(float a[4][3],float apex[3])
{

glBegin(GL_QUADS);

glColor3f(0.8,0.2,0.4);  //bottom
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[3]);

glEnd();

glBegin(GL_TRIANGLES);

glColor3f(1,0,0);  

glVertex3fv(apex);
glVertex3fv(a[0]);
glVertex3fv(a[1]);

glEnd();

glBegin(GL_TRIANGLES);

glColor3f(0,1,0);  

glVertex3fv(apex);
glVertex3fv(a[1]);
glVertex3fv(a[2]);

glEnd();

glBegin(GL_TRIANGLES);

glColor3f(0,0,1);  

glVertex3fv(apex);
glVertex3fv(a[2]);
glVertex3fv(a[3]);

glEnd();

glBegin(GL_TRIANGLES);

glColor3f(1,1,0);  

glVertex3fv(apex);
glVertex3fv(a[3]);
glVertex3fv(a[0]);

glEnd();


		glFlush();
}

void display(){
	// glClearColor(1,1,1,1);
	
	if(choice == 1){
		drawCube(input);
		drawCube(output);
	}
	else{
		drawPyramid(input1,apex);
		drawPyramid(output1,outputapex);
	}
	glFlush();

}

void init(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(-300,300,-300,300,300,-300);
}

int main(int argc, char* argv[]){

	// int option = -1;
	 
	// printf("Enter the type of operation number\n1. Transition \n2. Pyramid Rotation 3. Scaling\n 4. Cube Reflection\n");

	printf("Enter translation factor\n");
	float x,y,z;
	printf("x:");
	scanf("%f",&x);
	printf("y:");
	scanf("%f",&x);
	printf("z:");
	scanf("%f",&x);

	for(int i=0;i<8;i++){
		output[i][0] = input[i][0] + x;
		output[i][1] = input[i][1] + y;
		output[i][2] = input[i][2] + z;
			
	}
	for(int i=0;i<4;i++){
		output1[i][0] = input1[i][0] + x;
		output1[i][1] = input1[i][1] + y;
		output1[i][2] = input1[i][2] + z;
			
	}
	
		outputapex[0] = apex[0] + x;
		outputapex[1] = apex[1] + y;
		outputapex[2] = apex[2] + z;
	
	printf("draw 1.cube 2.pyramid\n");

	scanf("%d",&choice);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Transformations");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

}