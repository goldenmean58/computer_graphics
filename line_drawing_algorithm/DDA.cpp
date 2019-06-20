/******************************************************************
 * FileName : DDA.cpp
 * Author   : Lishuxiang
 * E-mail   : lishuxiang@cug.edu.cn
 * Time     : Fri 21 Jun 2019 12:01:02 AM CST
 * Function : Digital Differential Analyzer
******************************************************************/

#include<iostream>
#include<math.h>
#include<GL/glut.h>
using std::cin;
using std::cout;
using std::endl;

typedef struct {
    int x;
    int y;
}Point;

int step;
float x_increment;
float y_increment;
Point *p;

void DDA(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for(int i = 0; i < step; i++){
        glVertex2i(p[i].x, p[i].y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]){
    int x0, y0, x1, y1;
    cout<<"x0="; 
    cin>>x0;
    cout<<"y0="; 
    cin>>y0;
    cout<<"x1="; 
    cin>>x1;
    cout<<"y1="; 
    cin>>y1;
    int dx = x1 - x0;
    int dy = y1 - y0;
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_increment = dx / step;
    y_increment = dy / step;
    p = new Point[step];
    p[0].x=x0;
    p[0].y=y0;
    for(int i=1;i<step;i++){
        p[i].x = p[i-1].x + x_increment;
        p[i].y = p[i-1].y + y_increment;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("DDA");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 450.0);
    glutDisplayFunc(DDA);
    glutMainLoop();
    delete p;
    return 0;
}
