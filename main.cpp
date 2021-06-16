#include "gui.hpp"

bool clicked = false;
bool turn_player = false;//êlä‘ÇÃéËî‘
float X[2];
int move_X[2];

Board board;
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("dekunobou-gui");
    glClearColor(0,0.31,0.18,1);
    gluOrtho2D(0,600,600,0);
    glutDisplayFunc(display);
    glutPassiveMotionFunc(mouse_motion);
    glutMouseFunc(mouse_clicked);
    glutMainLoop();
}