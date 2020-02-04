#include <GL/glut.h>
#include <stdio.h>


void initialize(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(-300.0,300.0,-300.0,300.0);
}

float xc,yc,r;
float vertical = 0;
float horizontal = 0;
GLfloat scale = 1;

void draw8points(float xc,float yc, float x,float y){
	glBegin(GL_POINTS);
	glColor3f(0,0,1);
	glPushMatrix();
	glVertex2i(scale*xc+scale*x,scale*yc+scale*y);
	glVertex2i(scale*xc+scale*x,scale*yc-scale*y);
	glVertex2i(scale*xc-scale*x,scale*yc+scale*y);
	glVertex2i(scale*xc-scale*x,scale*yc-scale*y);
	
	glVertex2i(scale*xc+scale*y,scale*yc+scale*x);
	glVertex2i(scale*xc+scale*y,scale*yc-scale*x);
	glVertex2i(scale*xc-scale*y,scale*yc+scale*x);
	glVertex2i(scale*xc-scale*y,scale*yc-scale*x);
	glEnd();
	glPopMatrix();
}

void circle(float xc,float yc,float r){
	float x = 0;
	float y = r;
	float dec_param = 3-2*r;
	do{
		draw8points(xc,yc,x,y);
		x++;
		if(dec_param < 0){
			dec_param = dec_param + 4*x + 6;
		}
		else{
			y--;
			dec_param = dec_param + 4*(x-y) + 10;	
		}
	}while(x<=y);
	glFlush();
}

void draw4points(float xc,float yc, float x,float y){
	glBegin(GL_POINTS);
	glColor3f(0,0,1);
	glPushMatrix();
	glScalef(scale,scale,scale);
	glVertex2i(scale*xc+scale*x,scale*yc-scale*y);
	glVertex2i(scale*xc-scale*x,scale*yc-scale*y);
	
	glVertex2i(scale*xc+scale*y,scale*yc-scale*x);
	glVertex2i(scale*xc-scale*y,scale*yc-scale*x);
	glEnd();

	glPopMatrix();
}

void semicircle(float xc,float yc,float r){
	float x = 0;
	float y = r;
	float dec_param = 3-2*r;
	do{
		draw4points(xc,yc,x,y);
		x++;
		if(dec_param < 0){
			dec_param = dec_param + 4*x + 6;
		}
		else{
			y--;
			dec_param = dec_param + 4*(x-y) + 10;	
		}
	}while(x<=y);
	glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y){

	if(key == 'e'){
		horizontal += 10;
	}else
	if(key == 'f'){
		horizontal -= 10;
	}else
	if(key == 'c'){
		scale += 0.1;
	}else
	if(key == 'd'){
		if(scale > 0.0)
			scale -= 0.1;
		
	}else
	if(key == 'r'){
		horizontal = 0;
		scale = 1;
	}else
	if(key == 'x'){
		exit(0);
	}


	glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	circle(0+horizontal,0,scale*200);
	circle(0+horizontal,0,scale*10);
	circle(-75+horizontal,75,scale*40);
	circle(75+horizontal,75,scale*40);
	semicircle(0+horizontal,-50,scale*60);
	circle(-75+horizontal,55,scale*20);
	circle(75+horizontal,55,scale*20);

}

int main(int argc,char* argv[]){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("stars");
	glutKeyboardFunc(keyboard);
	initialize();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
