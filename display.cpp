#include "gui.hpp"
//GUIとして表示用の関数たち

void display(void){
    Board board;
    glClear(GL_COLOR_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    draw_board();
    draw_phase(board);
    glutSwapBuffers();
}