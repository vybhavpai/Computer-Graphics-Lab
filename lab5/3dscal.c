#include <GL/glut.h>
#include <stdio.h>

static GLfloat input[8][3]=
{
    {0,0,0},{50,0,0},{50,50,0},{0,50,0},
    {-10,-10,50},{40,-10,50},{40,40,50},{-10,40,50}

};
static GLfloat input1[4][3]=
{
    
    {0,-100,100},{100,-100,0},{0,-100,-100},{-100,-100,0}

};
int choice;
float output[8][3],output1[4][3],outputapex[3];

static GLfloat apex[3] = {0,0,0};
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

	printf("Enter scaling factor\n");
	int x,y,z;
	printf("x:");
	scanf("%d",&x);
	printf("y:");
	scanf("%d",&y);
	printf("z:");
	scanf("%d",&z);
	// printf("%d%d%d",x,y,z);

	// for(int i=1;i<8;i++){
	// 	output[i][0] = (input[i][0]-input[0][0])*x + input[0][0];
	// 	output[i][1] = (input[i][1]-input[0][1])*y + input[0][1];
	// 	output[i][2] = (input[i][2]-input[0][2])*z + input[0][2];
		
			
	// }
	// for(int i=1;i<4;i++){
	// 	output1[i][0] = (input1[i][0]-input1[0][0])*x + input1[0][0];
	// 	output1[i][1] = (input1[i][1]-input1[0][1])*y + input1[0][1];
	// 	output1[i][2] = (input1[i][2]-input1[0][2])*z + input1[0][2];
		
			
	// }
	
	// outputapex[0] = (outputapex[0]-input1[0][0])*x + input1[0][0];
	// outputapex[1] = (outputapex[0]-input1[0][1])*y + input1[0][1];
	// outputapex[2] = (outputapex[0]-input1[0][2])*z + input1[0][2];
	for(int i=0;i<8;i++){
		output[i][0] = input[i][0] * x;
		output[i][1] = input[i][1] * y;
		output[i][2] = input[i][2] * z;
			
	}
	for(int i=0;i<4;i++){
		output1[i][0] = input1[i][0] * x;
		output1[i][1] = input1[i][1] * y;
		output1[i][2] = input1[i][2] * z;
			
	}
	
		outputapex[0] = apex[0] * x;
		outputapex[1] = apex[1] * y;
		outputapex[2] = apex[2] * z;
		
	
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
