#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);   // 🔹 Garis nyambung (strip)
        glColor3f(1.0f, 0.0f, 0.0f);   // merah
        glVertex2f(-0.5f, -0.5f);      // Titik A

        glColor3f(0.0f, 1.0f, 0.0f);   // hijau
        glVertex2f(-0.2f,  0.5f);      // Titik B

        glColor3f(0.0f, 0.0f, 1.0f);   // biru
        glVertex2f(0.2f, -0.3f);       // Titik C

        glColor3f(1.0f, 1.0f, 0.0f);   // kuning
        glVertex2f(0.5f,  0.5f);       // Titik D
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Contoh GL_LINE_STRIP");

    glClearColor(1.0, 1.0, 1.0, 1.0);   // background putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
