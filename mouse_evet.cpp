#include"gui.hpp"

void mouse_motion(int x, int y) {
    X[0] = x;
    X[1] = y;
    //�J�[�\�����Տ�ɂ���Ȃ�Ֆʂ̃}�X�ڂ̒����̍��W�Ɋۂ߂�
    if (x >= 25 && x <= 25 + line_interval * 8 &&
        y >= 25 && y <= 25 + line_interval * 8) {
        X[0] = (x - 25) / line_interval * line_interval + 25;
        X[1] = (y - 25) / line_interval * line_interval + 25;
    }
    glutPostRedisplay();
}

void mouse_clicked(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)return;
    clicked = true;
    X[0] = x;
    X[1] = y;
    //�J�[�\�����Տ�ɂ���Ȃ�Ֆʂ̃}�X�ڂ̒����̍��W�Ɋۂ߂�
    if (x >= 25 && x <= 25 + line_interval * 8 &&
        y >= 25 && y <= 25 + line_interval * 8) {
        X[0] = (x - 25) / line_interval * line_interval + 25;
        X[1] = (y - 25) / line_interval * line_interval + 25;
    }
    glutPostRedisplay();
}