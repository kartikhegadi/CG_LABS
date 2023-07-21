#include<GL/glut.h>
#include<stdio.h>
#include<GL/glu.h>
int x2,x1,y1,y2;

void draw(int x,int y)
{

    glColor3i(1,0,0);

    glBegin(GL_POINTS);
        glPointSize(5);
        glVertex2i(x,y);
    glEnd();
}


void init()
{

    glClearColor(1,1,1,1);
    gluOrtho2D(0.0, 500.0 ,0.0 ,500.0);
}
void linedraw(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int m=dy/dx;

    if(m<1)
    {
        int dp=2*dy-dx;
        int x=x1;
        int y=y1;
        if(dx<0)
        {
            x=x2;
            y=y2;
            x2=x1;
        }
        draw(x,y);
        while(x<x2)
        {

            if(dp>=0)
            {

                x=x+1;
                y=y+1;
                dp=dp+2*dy-2*dx*(y+1-y);
            }
            else
            {
                x=x+1;
                y=y;
                dp=dp+2*dy-2*dx*(y-y);

            }
             draw(x,y);
        }

    }
    else if (m>1)
    {

        int dp=2*dy-dx;
        int x=x1;
        int y=y1;


        if(dy<0)
        {
            x=x2;
            y=y2;
            y2=y1;
        }
        draw(x,y);
        while(y<y2)
        {

            if(dp>=0)
            {

                x=x+1;
                y=y+1;
                dp=dp+2*dy-2*dx*(x+1-x);
            }
            else
            {
                y=y+1;
                x=x;
                dp=dp+2*dy-2*dx*(x-x);

            }
             draw(x,y);


        }
     }

    else if(m==1)
    {
        int x=x1;
        int y=y1;
        draw(x,y);
        while(x<x2)
        {

            x=x+1;
            y=y+1;
            draw(x,y);
        }


    }

}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    linedraw(x1,y1,x2,y2);

    glFlush();

}

int main(int argc , char **argv)
{

    printf("Enter the first point (x1,y2)");
    scanf("%d%d",&x1,&y2);

    printf("Enter the first point (x2,y2)");
    scanf("%d%d",&x2,&y2);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(220,220);
    glutCreateWindow("prog 1");

    init();
    glutDisplayFunc(display);

    glutMainLoop();



}
