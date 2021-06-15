#include"dekunobou.hpp"
#include"othello.hpp"
#include<GL/glut.h>

#pragma once
//display.cpp
void display(void);

//draw.cpp
void glCircle(float r,float rx,float ry);
void draw_board();
void draw_phase(Board board);