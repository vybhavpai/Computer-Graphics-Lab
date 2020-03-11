#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
#include<time.h>
#define MAX 5

int stack[MAX];
int stack_length = 0;

char text_display[20];
int length = 0;

char full[20]="stack full";
char empty[20]="stack empty";
char insertion[20]="insertion";
char deletion[20]="deletion";

char insert[100]="Press key 'i' to insert elements to stack";
char delete[100]="Press key 'd' to delete elements from stack";


void displaytext(int length,char string[]){

	glClearColor(1,1,1,1);
	glColor3f(0,0,0);
	glRasterPos2f(150, 0);
	int i;
	
	for (i = 0; i < length; i++) {
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	}

	glColor3f(0,1,0);
	glRasterPos2f(50, 150);
	length = 41;
	for (i = 0; i < length; i++) {
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, insert[i]);
	}
	glFlush();

	glColor3f(1,0,0);
	glRasterPos2f(50, 120);
	length = 43;
	for (i = 0; i < length; i++) {
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, delete[i]);
	}
	glFlush();


}
void displaynumber(int pos,char number){

	glColor3f(1,0,0);
	glRasterPos2f(0, pos);
	int i;
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, number);
	glFlush();
}
void stack_display(){
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	// printf("%s is content \n", text_display);
	displaytext(length,text_display);

	// printf("stack length %d\n",stack_length);
	float x_left = -20;
	float x_right = 20;
	float y = -40;

	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2f(x_left,y);
	glVertex2f(x_left,y+100);

	glVertex2f(x_right,y);
	glVertex2f(x_right,y+100);

	for(int i = 0;i<6;i++){
		glVertex2f(x_left,y);
		glVertex2f(x_right,y);
		y += 20;
	}

	glEnd();
	glFlush();
	y = -35;
	for(int i = 0;i<stack_length;i++){
		displaynumber(y,stack[i] + '0');
		y += 20;
	}
}

void draw_arrow(int centre){
	glClearColor(1,1,1,1);
	
	centre  = centre*20 - 50;
	glBegin(GL_LINES);
	glColor3f(0.5,0.5,1);
	glVertex2f(30,centre);
	glVertex2f(40,centre+10);

	glVertex2f(30,centre);
	glVertex2f(40,centre-10);

	glVertex2f(40,centre+5);
	glVertex2f(40,centre+10);

	glVertex2f(40,centre-5);
	glVertex2f(40,centre-10);

	glVertex2f(40,centre+5);
	glVertex2f(55,centre+5);

	glVertex2f(40,centre-5);
	glVertex2f(55,centre-5);

	glVertex2f(55,centre+5);
	glVertex2f(55,centre-5);
	
	glEnd();
	glFlush();
}

void display(){
	stack_display();
	draw_arrow(stack_length);
	glFlush();
}

void init(){
	glClearColor(1,1,1,1);
	gluOrtho2D(-300,300,-300,300);
	glClear(GL_COLOR_BUFFER_BIT);
}

void keyboard(unsigned char key,int x,int y){

	if(key == 'i'){
		if(stack_length == MAX){
			return;
		}

		if(stack_length < MAX-1){
			strcpy(text_display,insertion);
			length = 9;
			stack[stack_length] = rand()%10;
			// printf("%d inserted\n",stack[stack_length]);
			stack_length++;
			stack_display();
			draw_arrow(stack_length);
		}else{
			strcpy(text_display,full);
			length = 10;
			stack[stack_length] = rand()%10;
			// printf("%d inserted\n",stack[stack_length]);
			stack_length++;
			stack_display();	
			draw_arrow(stack_length);
		}

	}

	if(key == 'd'){
		if(stack_length == 0){
			return;
		}

		if(stack_length > 1){
			strcpy(text_display,deletion);
			length = 8;
			stack_length--;
			// printf("%d deleted\n",stack[stack_length]);
			stack_display();
			draw_arrow(stack_length);
		}else{
			strcpy(text_display,empty);
			length = 11;
			stack_length--;
			// printf("%d deleted\n",stack[stack_length]);
			stack_display();	
			draw_arrow(stack_length);
		}

	}



}

int main(int argc, char* argv[]){

	srand(time(0)); 	
	
	strcpy(text_display,empty);
	length = 11;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("STACK");
	glutKeyboardFunc(keyboard);

	init();
	glutDisplayFunc(display);
	glutMainLoop();


}