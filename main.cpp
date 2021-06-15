#include "gui.hpp"

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("dekunobou-gui");
    glClearColor(0,0.31,0.18,1);
    gluOrtho2D(0,600,600,0);
    glutDisplayFunc(disp);
    glutMainLoop();
}