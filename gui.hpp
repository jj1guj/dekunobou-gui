#include"dekunobou.hpp"
#include"othello.hpp"
#include<GL/glut.h>
extern bool clicked;

extern float X[];//マウスポインタの座標
extern int move_X[];//実際に打つときの配列上の座標

extern Board board;//盤面の情報
#pragma once

//display.cpp
void display(void);

//draw.cpp
void glCircle(float r,float rx,float ry);
void draw_board();
void draw_phase(Board board);
void draw_legalmoves(Board board);
void draw_teban(Board board);
void draw_string(float x,float y,std::string str);

//mouse_event.cpp
void mouse_motion(int x, int y);
void mouse_clicked(int button, int state, int x, int y);