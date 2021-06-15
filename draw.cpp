#include "gui.hpp"
//描画用の関数たち
float line_interval=56.25;//盤の線の間隔
float stone_r=line_interval/2-5;//石の半径

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
        glVertex2f(line_interval*i+25,475);
        glVertex2f(line_interval*i+25,25);

        //横線の描画
        glVertex2f(25,line_interval*i+25);
        glVertex2f(475,line_interval*i+25);
    }
    glEnd();

    //盤に星を打つ
    glColor3f(0,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(2*line_interval+25,2*line_interval+25);
        glVertex2f(6*line_interval+25,2*line_interval+25);
        glVertex2f(2*line_interval+25,6*line_interval+25);
        glVertex2f(6*line_interval+25,6*line_interval+25);
    glEnd();
}

//局面の描画
void draw_phase(Board board){
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(board.board[i][j]==1){
                glColor3f(0,0,0);
                glBegin(GL_POLYGON);
                    glCircle(stone_r,line_interval*(i+0.5)+25,line_interval*(j+0.5)+25);
                glEnd();
            }else if(board.board[i][j]==-1){
                glColor3f(1,1,1);
                glBegin(GL_POLYGON);
                    glCircle(stone_r,line_interval*(i+0.5)+25,line_interval*(j+0.5)+25);
                glEnd();
            }
        }
    }
}

//文字列の挿入
void draw_string(float x,float y,std::string str){
    glRasterPos2f(x,y);
    for(int i=0;i<str.size();++i)glutBitmapCharacter(GLUT_BITMAP_8_BY_13,str[i]);
}