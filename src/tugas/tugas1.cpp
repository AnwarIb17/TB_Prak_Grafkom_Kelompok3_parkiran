// Anwar Ibrahim
// Transformasi Afine 2D dengan OpenGL

#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;
float scale = 1.0f;
float tx = 0.0f;
float ty = 0.0f;
float shearX = 0.0f;

void drawSquare() {
    glBegin(GL_QUADS);
        glVertex2f(-20, -20);
        glVertex2f( 20, -20);
        glVertex2f( 20,  20);
        glVertex2f(-20,  20);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Translasi
    glTranslatef(tx, ty, 0.0f);

    // Rotasi
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Skala
    glScalef(scale, scale, 1.0f);

    // Shear (manual dengan matriks)
    GLfloat shearMatrix[16] = {
        1, shearX, 0, 0,
        0,    1,   0, 0,
        0,    0,   1, 0,
        0,    0,   0, 1
    };
    glMultMatrixf(shearMatrix);

    glColor3f(0.2f, 0.6f, 1.0f);
    drawSquare();

    glutSwapBuffers();
}

void timer(int value) {
    angle += 2.0f;
    scale = 1.0f + 0.3f * sin(angle * 3.14 / 180);
    tx = 30.0f * cos(angle * 3.14 / 180);
    ty = 30.0f * sin(angle * 3.14 / 180);
    shearX = 0.5f * sin(angle * 3.14 / 180);

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Transformasi Afine 2D - OpenGL");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}