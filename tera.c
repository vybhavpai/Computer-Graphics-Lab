#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int rec = 1;

int orig_x[3] = {-200,0,200};
int orig_y[3] = {-100	,173*2-100,-100};


void draw_triangle(int x[3],int y[3]){
	glBegin(GL_TRIANGLES);

	glColor3f(1,0,0);
	glVertex2d(x[0],y[0]);
	glVertex2d(x[1],y[1]);
	glVertex2d(x[2],y[2]);
	
	glEnd();	
}

void sierpinski(int recursions, int x[3], int y[3]){
	if(recursions == 1){
		draw_triangle(x,y);	
		return;
	}

	int mid_x[3],mid_y[3];
	for(int i = 0;i<3;i++){
		mid_x[i] = (x[i] + x[(i+1)%3])/2;
		mid_y[i] = (y[i] + y[(i+1)%3])/2;
	}
	int next_x[3],next_y[3];
	next_x[0] = x[0];
	next_x[1] = mid_x[0];
	next_x[2] = mid_x[2];
	next_y[0] = y[0];
	next_y[1] = mid_y[0];
	next_y[2] = mid_y[2];
	
	sierpinski(recursions-1,next_x,next_y);
	next_x[0] = mid_x[0];
	next_x[1] = x[1];
	next_x[2] = mid_x[1];
	next_y[0] = mid_y[0];
	next_y[1] = y[1];
	next_y[2] = mid_y[1];

	sierpinski(recursions-1,next_x,next_y);
	next_x[0] = mid_x[2];
	next_x[1] = mid_x[1];
	next_x[2] = x[2];
	next_y[0] = mid_y[2];
	next_y[1] = mid_y[1];
	next_y[2] = y[2];
	
	
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

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Triangle");
	
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}