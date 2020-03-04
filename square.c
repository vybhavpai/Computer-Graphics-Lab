#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int rec = 1;

int orig_x[4] = {-150,-150,150,150};
int orig_y[4] = {-150,150,150,-150};


void draw_square(int x[4],int y[4]){
	// printf("%d %d\n",x[0],y[0]);
	// printf("%d %d\n",x[1],y[1]);
	// printf("%d %d\n",x[2],y[2]);
	// printf("%d %d\n",x[3],y[3]);
	
	glBegin(GL_QUADS);

	glColor3f(1,0,0);
		
	glVertex2d(x[0],y[0]);
	glVertex2d(x[1],y[1]);
	glVertex2d(x[2],y[2]);
	glVertex2d(x[3],y[3]);
	
	glEnd();	
}

void sierpinski(int recursions, int x[4], int y[4]){
	// printf("\nrec %d\n",recursions);
	if(recursions == 1){
		// printf("CAlling draw\n");
		draw_square(x,y);	
		return;
	}
	int d = y[1] - y[0];

	int left_x[2],right_x[2],up_x[2],down_x[2];
	int left_y[2],right_y[2],up_y[2],down_y[2];
	int centre_x[4],centre_y[4];
	
	int next_x[4],next_y[4];

	left_x[0] = x[0];
	left_x[1] = x[0];

	up_x[0] = x[0]+d/3*2;
	up_x[1] = x[0]+d/3;

	right_x[0] = x[2];
	right_x[1] = x[2];

	down_x[0] = x[0] + d/3;
	down_x[1] = x[0] + d/3*2;

	left_y[0] = y[0] + d/3*2;
	left_y[1] = y[0] + d/3;

	up_y[0] = y[1];
	up_y[1] = y[1];

	right_y[0] = y[0] + d/3;
	right_y[1] = y[0] + d/3*2;

	down_y[0] = y[0];
	down_y[1] = y[0];

	centre_x[0] = down_x[0];
	centre_x[1] = down_x[0];
	centre_x[2] = down_x[1];
	centre_x[3] = down_x[1];

	centre_y[0] = right_y[0];
	centre_y[1] = right_y[1];
	centre_y[2] = right_y[1];
	centre_y[3] = right_y[0];

	next_x[0] = x[0];
	next_x[1] = left_x[1];
	next_x[2] = centre_x[0];
	next_x[3] = down_x[0];
	
	next_y[0] = y[0];
	next_y[1] = left_y[1];
	next_y[2] = centre_y[0];
	next_y[3] = down_y[0];

	sierpinski(recursions-1,next_x,next_y);

	next_x[0] = left_x[1];
	next_x[1] = left_x[0];
	next_x[2] = centre_x[1];
	next_x[3] = centre_x[0];
	
	next_y[0] = left_y[1];
	next_y[1] = left_y[0];
	next_y[2] = centre_y[1];
	next_y[3] = centre_y[0];
	
	sierpinski(recursions-1,next_x,next_y);
	
	next_x[0] = left_x[0];
	next_x[1] = x[1];
	next_x[2] = up_x[1];
	next_x[3] = centre_x[1];
	
	next_y[0] = left_y[0];
	next_y[1] = y[1];
	next_y[2] = up_y[1];
	next_y[3] = centre_y[1];
	
	sierpinski(recursions-1,next_x,next_y);
	
	next_x[0] = centre_x[1];
	next_x[1] = up_x[1];
	next_x[2] = up_x[0];
	next_x[3] = centre_x[2];
	
	next_y[0] = centre_y[1];
	next_y[1] = up_y[1];
	next_y[2] = up_y[0];
	next_y[3] = centre_y[2];
	
	sierpinski(recursions-1,next_x,next_y);
	
	next_x[0] = centre_x[2];
	next_x[1] = up_x[0];
	next_x[2] = x[2];
	next_x[3] = right_x[1];
	
	next_y[0] = centre_y[2];
	next_y[1] = up_y[0];
	next_y[2] = y[2];
	next_y[3] = right_y[1];
	
	sierpinski(recursions-1,next_x,next_y);
	
	next_x[0] = centre_x[3];
	next_x[1] = centre_x[2];
	next_x[2] = right_x[1];
	next_x[3] = right_x[0];
	
	next_y[0] = centre_y[3];
	next_y[1] = centre_y[2];
	next_y[2] = right_y[1];
	next_y[3] = right_y[0];
	
	sierpinski(recursions-1,next_x,next_y);
	
	next_y[0] = down_y[1];
	next_y[1] = centre_y[3];
	next_y[2] = right_y[0];
	next_y[3] = y[3];
	
	next_x[0] = down_x[1];
	next_x[1] = centre_x[3];
	next_x[2] = right_x[0];
	next_x[3] = x[3];
	
	sierpinski(recursions-1,next_x,next_y);
	
	next_x[0] = down_x[0];
	next_x[1] = centre_x[0];
	next_x[2] = centre_x[3];
	next_x[3] = down_x[1];
	
	next_y[0] = down_y[0];
	next_y[1] = centre_y[0];
	next_y[2] = centre_y[3];
	next_y[3] = down_y[1];
	
	sierpinski(recursions-1,next_x,next_y);
	
}


void display(){

	sierpinski(rec,orig_x,orig_y);
	glFlush();
}

void init(){
	glClearColor(1,1,1,1);
	gluOrtho2D(-300,300,-300,300);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[]){

	printf("Enter the number of recursions\n");
	scanf("%d",&rec);
	rec++;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Triangle");
	
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}