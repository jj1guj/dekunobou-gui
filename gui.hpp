#include"dekunobou.hpp"
#include"othello.hpp"
#include<GL/glut.h>
extern bool clicked;

extern int line_interval;//�Ղ̐��̊Ԋu
extern float stone_r;//�΂̔��a

extern float X[];//�}�E�X�|�C���^�̍��W
extern int move_X[];//���ۂɑłƂ��̔z���̍��W

extern Board board;//�Ֆʂ̏��
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