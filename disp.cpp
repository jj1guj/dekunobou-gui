#include "gui.hpp"
//GUIとして表示用の関数たち

void disp(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}