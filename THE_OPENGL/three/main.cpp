#include<GL/glut.h>
float ver[][3]={{0,0,0},{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1}};
float theta[]={0,0,0};
int axis=0;
void polygon(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);

	glColor3fv(ver[a]);
	glVertex3fv(ver[a]);

	glColor3fv(ver[b]);
	glVertex3fv(ver[b]);

	glColor3fv(ver[c]);
	glVertex3fv(ver[c]);

	glColor3fv(ver[d]);
	glVertex3fv(ver[d]);

	glEnd();
}
void ColorCube(void)
{
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	ColorCube();
	glFlush();
	glutSwapBuffers();
}
void SpinCube()
{
	theta[axis]+=0.5;
	if(theta[axis]>360)
		theta[axis]=0;
	display();
}
/*void mouse(int btn,int state,int x,int y)
{
	if(btn=GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		axis=0;
	if(btn=GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
		axis=1;
	if(btn=GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		axis=2;
}*/
void mouse(int btn,int status,int x,int y)
{

    if(btn=GLUT_LEFT_BUTTON && status==GLUT_DOWN)
        axis=0;
    if(btn=GLUT_MIDDLE_BUTTON && status==GLUT_DOWN)
        axis=1;
    if(btn=GLUT_RIGHT_BUTTON && status==GLUT_DOWN)
        axis=2;
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///because we are including the 2d and 3d frames thhroughout the program
	glutInitWindowSize(700,700);
	glutCreateWindow("ROTATING COLOR CUBE: C Tathva");
	//glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(SpinCube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
