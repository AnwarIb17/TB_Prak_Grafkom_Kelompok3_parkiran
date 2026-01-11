#include <GL/glut.h>

void display() {
    glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.0f); // warna oranye
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // mode display
    glutInitWindowSize(640, 480);                // ukuran window
    glutCreateWindow("2406025 Muhammad Saepul Hidayat"); 
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
