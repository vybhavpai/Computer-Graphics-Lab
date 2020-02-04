#include <GL/glut.h>
#include <stdio.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

}

int length = 30;
void init(){
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,600,600,0);
	glPointSize(4);
}

void drawStar(int x,int y){
	// printf("Click detected at %d,%d\n",x,y);
    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
      
	glColor3f(1,0,0);
	glVertex2i(x,y+2*length/3);
	glVertex2i(x-length/2,y-length/3);
	glVertex2i(x+length/2,y-length/3);



	glVertex2i(x,y-2*length/3);
	glVertex2i(x-length/2,y+length/3);
	glVertex2i(x+length/2,y+length/3);

	glEnd();
	

	glFlush();
    
}

void mouse(int button,int state,int x,int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		drawStar(x,y);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		exit(0);
	}

}
void keyboard(unsigned char key,int x,int y){

	if(key == 's'){
		length += 15;
	}
	if(key == 'r'){
		length -= 15;
		}


}
int main(int argc,char* argv[]){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("stars");
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
