#include <GL/glut.h>
#include <math.h>

void drawCircle(float radius, int segments) {
    glColor3f(0.2f, 1.0f, 0.4f);  // Warna hijau muda

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Titik tengah lingkaran

        for (int i = 0; i <= segments; i++) {
            float angle = i * 2.0f * 3.1415926f / segments;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle(0.6f, 100);  // radius 0.6, jumlah segmen 100

    glFlush();
}

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lingkaran 2D OpenGL");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
