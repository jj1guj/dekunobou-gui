#include "gui.hpp"
//描画用の関数たち

//円の描画
void glCircle(float r,float rx,float ry){
    int i,n=100;
    float pi=3.14159265358979;
    float x,y,x0,y0;
    double rate;

    for(i=0;i<n;i++){
        rate=(double)i/n;
        x=r*cos(2.0*pi*rate)+rx;
        y=r*sin(2.0*pi*rate)+ry;
        glVertex2f(x,y);
    }
}

//盤の描画
void draw_board(){
    //盤の線を引く
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    for(int i=0;i<9;++i){
        //縦線の描画
        glVertex2f(56.25*i+25,475);
        glVertex2f(56.25*i+25,25);

        //横線の描画
        glVertex2f(25,56.25*i+25);
        glVertex2f(475,56.25*i+25);
    }
    glEnd();

    //盤に星を打つ
    glColor3f(0,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(137.5,137.5);
        glVertex2f(362.5,137.5);
        glVertex2f(137.5,362.5);
        glVertex2f(362.5,362.5);
    glEnd();
}