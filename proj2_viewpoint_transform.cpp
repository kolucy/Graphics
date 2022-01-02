#include <GL/glut.h>

GLfloat cx = 0;
GLfloat cy = 0;
GLfloat cz = 10;
GLfloat an = 0;
GLfloat anx = 0;
GLfloat any = 0;
GLfloat anz = 0;

void InitLight() {
    GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cx, cy, cz, cx, cy, cz - 1.0, 0.0, 1.0, 0.0);  //시점 좌표계 설정
    glRotatef(anx, 1, 0, 0);
    glRotatef(any, 0, 1, 0);
    glRotatef(anz, 0, 0, 1);
    glutSolidTeapot(0.5);
    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
        //카메라의 x, y, z축 이동 적용
            //카메라의 방향은 항상 수평이 되도록 설정
    case 'a': //물체 왼쪽으로 이동하는 것처럼
        cx += 0.1f; break;
    case 's': //물체 오른쪽으로 이동하는 것처럼
        cx -= 0.1f; break;
    case 'd': //물체 아래로 이동하는 것처럼
        cy += 0.1f; break;
    case 'f': //물체 위로 이동하는 것처럼
        cy -= 0.1f; break;
    case 'z': //물체가 뒤로 이동하는 것처럼
        cz += 0.1f; break;
    case 'x': //물체가 앞으로 이동하는 것처럼
        cz -= 0.1f; break;

        //모델의 x, y, z축 회전 적용
    case 'g':
        anx += 5.0f; break; //x축 반시계 방향 회전(물체는 반대로)
    case 'h':
        anx -= 5.0f; break; //x축 시계 방향 회전(")
    case 'j':
        any += 5.0f; break; //y축 반시계 방향 회전(")
    case 'k':
        any -= 5.0f; break; //y축 시계 방향 회전(")
    case 'l':
        anz += 5.0f; break; //z축 반시계 방향 회전(")
    case 'm':
        anz -= 5.0f; break; //z축 시계 방향 회전(")
    }
    glutPostRedisplay(); //디스플레이 함수 다시 실행
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //윈도우 크기가 변함에 따라 뷰포트도 윈도우 크기와 같게 변화하도록 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 1.0, 0.5, 50.0); //원근 투상 적용
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(0.4, 0.4, 0.4, 0.0); //rgb 같게 -> 회색, 투명도 0.0으로 하여 그려지는 물체가 보이도록 초기화
    InitLight();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}