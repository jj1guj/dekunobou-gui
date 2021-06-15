#include "gui.hpp"
//GUIとして表示用の関数たち

void display(void){
    Board board;
    glClear(GL_COLOR_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    draw_board();
    draw_phase(board);
    draw_legalmoves(board);

    //手番の描画
    draw_teban(board);
    glutSwapBuffers();
}