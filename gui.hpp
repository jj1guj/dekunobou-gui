#include"dekunobou.hpp"
#include"othello.hpp"
#include<GL/glut.h>
extern bool clicked;

extern int line_interval;//盤の線の間隔
extern float stone_r;//石の半径

extern float X[];//マウスポインタの座標
extern int move_X[];//実際に打つときの配列上の座標

extern Board board;//盤面の情報
#pragma once

//display.cpp
void display(void);

//draw.cpp
void glCircle(float r,float rx,float ry);
void draw_board();
void draw_phase();
void draw_legalmoves();
void draw_teban();
void draw_string(float x,float y,std::string str);

//mouse_event.cpp
void mouse_motion(int x, int y);
void mouse_clicked(int button, int state, int x, int y);