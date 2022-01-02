#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/GLAUX.H>


#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#pragma comment(linker, "/ENTRY:mainCRTStartup")

#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "glaux.lib")

GLfloat cx = 0;
GLfloat cy = 0;
GLfloat cz = 10;
GLfloat an = 0;
GLfloat anx = 0;
GLfloat any = 0;
GLfloat anz = 0;

GLfloat xrot = 0.9f, yrot = 0.8f, zrot = 1.0f;
unsigned int MyTextureObject[1];
AUX_RGBImageRec* pTextureImage[1];			//텍스쳐 저장 공간을 가리키는 포인터

void MyLightInit()
{
    GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

    glEnable(GL_LIGHTING);//조명 기능 활성화
    glEnable(GL_LIGHT0);//광원 활성화

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
    glLightfv(GL_LIGHT0, GL_SHININESS, mat_shininess);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

}

void MyDisplay() {
    GLfloat LightPosition[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat LightDirection[] = { -0.5, -1.0, -1.0 };
    GLfloat SpotAngle[] = { 40.0 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	//앞면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	//뒷면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	//윗면
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	//아랫면
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	//우측면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	//좌측면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    void glTexGenf(GLenum coord, GLenum pname, GLdouble param);
    void glTexGenf(GLenum coord, GLenum pname, GLdouble *param);
    /*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); */
    static GLfloat MyPlane[] = { 1.0, 0.0, 0.0, 0.0 };
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGenfv(GL_S, GL_OBJECT_PLANE, MyPlane);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    /*void glTexParameteri(GLenum target, GLenum pname, GLint  param)*/

    glEnd();

    glutSwapBuffers();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cx, cy, cz, cx, cy, cz - 1.0, 0.0, 1.0, 0.0);  //시점 좌표계 설정
    glRotatef(anx, 1, 0, 0);
    glRotatef(any, 0, 1, 0);
    glRotatef(anz, 0, 0, 1);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDirection);
    glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, SpotAngle);
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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

AUX_RGBImageRec* LoadBMP()
{

    return auxDIBImageLoad("apple.bmp");

}

int LoadGLTextures()						//파일을 로드하고 텍스쳐로 변환
{

    int Status = FALSE;

    glClearColor(0.0, 0.0, 0.0, 0.5);

    memset(pTextureImage, 0, sizeof(void*) * 1);				//포인터를 널로

    if (pTextureImage[0] = LoadBMP())				//비트맵을 로드하고 오류확인
    {

        Status = TRUE;										//상태 플랙을 True로
        glGenTextures(1, &MyTextureObject[0]);				//텍스쳐 생성
        glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage[0]->sizeX, pTextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glEnable(GL_TEXTURE_2D);

    }

    if (pTextureImage[0])									//텍스쳐가 존재하면
    {

        if (pTextureImage[0]->data)							//텍스쳐 영상이 존재하면
        {
            free(pTextureImage[0]->data);					//텍스쳐 영상공간 반납
        }

        free(pTextureImage[0]);								//텍스쳐 반납

    }

    return Status;

}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("주전자 텍스처");
    glClearColor(0.4, 0.4, 0.4, 0.0); //rgb 같게 -> 회색, 투명도 0.0으로 하여 그려지는 물체가 보이도록 초기화
    MyLightInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();

    if (LoadGLTextures())
    {

        glEnable(GL_TEXTURE_2D);
        glShadeModel(GL_SMOOTH);
        glClearDepth(1.0);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
        glutMainLoop();

    }

}