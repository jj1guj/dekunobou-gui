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
}