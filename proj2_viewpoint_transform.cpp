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
    gluLookAt(cx, cy, cz, cx, cy, cz - 1.0, 0.0, 1.0, 0.0);  //���� ��ǥ�� ����
    glRotatef(anx, 1, 0, 0);
    glRotatef(any, 0, 1, 0);
    glRotatef(anz, 0, 0, 1);
    glutSolidTeapot(0.5);
    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
        //ī�޶��� x, y, z�� �̵� ����
            //ī�޶��� ������ �׻� ������ �ǵ��� ����
    case 'a': //��ü �������� �̵��ϴ� ��ó��
        cx += 0.1f; break;
    case 's': //��ü ���������� �̵��ϴ� ��ó��
        cx -= 0.1f; break;
    case 'd': //��ü �Ʒ��� �̵��ϴ� ��ó��
        cy += 0.1f; break;
    case 'f': //��ü ���� �̵��ϴ� ��ó��
        cy -= 0.1f; break;
    case 'z': //��ü�� �ڷ� �̵��ϴ� ��ó��
        cz += 0.1f; break;
    case 'x': //��ü�� ������ �̵��ϴ� ��ó��
        cz -= 0.1f; break;

        //���� x, y, z�� ȸ�� ����
    case 'g':
        anx += 5.0f; break; //x�� �ݽð� ���� ȸ��(��ü�� �ݴ��)
    case 'h':
        anx -= 5.0f; break; //x�� �ð� ���� ȸ��(")
    case 'j':
        any += 5.0f; break; //y�� �ݽð� ���� ȸ��(")
    case 'k':
        any -= 5.0f; break; //y�� �ð� ���� ȸ��(")
    case 'l':
        anz += 5.0f; break; //z�� �ݽð� ���� ȸ��(")
    case 'm':
        anz -= 5.0f; break; //z�� �ð� ���� ȸ��(")
    }
    glutPostRedisplay(); //���÷��� �Լ� �ٽ� ����
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //������ ũ�Ⱑ ���Կ� ���� ����Ʈ�� ������ ũ��� ���� ��ȭ�ϵ��� ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 1.0, 0.5, 50.0); //���� ���� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    glClearColor(0.4, 0.4, 0.4, 0.0); //rgb ���� -> ȸ��, ���� 0.0���� �Ͽ� �׷����� ��ü�� ���̵��� �ʱ�ȭ
    InitLight();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}