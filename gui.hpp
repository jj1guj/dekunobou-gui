#include"dekunobou.hpp"
#include"othello.hpp"
#include<GL/glut.h>

#pragma once
extern bool clicked;

//display.cpp
void display(void);

//draw.cpp
void glCircle(float r,float rx,float ry);
void draw_board();
void draw_phase(Board board);
void draw_legalmoves(Board board);
void draw_teban(Board board);
void draw_string(float x,float y,std::string str);