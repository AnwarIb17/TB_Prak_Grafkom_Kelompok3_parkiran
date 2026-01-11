#include <GL/glut.h>

// Fungsi untuk menggambar segitiga 2D
void drawTriangle() {
    glColor3f(1.0f, 0.4f, 0.2f); // Warna oranye

    glBegin(GL_TRIANGLES);   // Menggunakan 3 titik untuk segitiga
        glVertex2f(0.0f, 0.6f);   // Titik atas
        glVertex2f(-0.6f, -0.4f); // Titik kiri bawah
        glVertex2f(0.6f, -0.4f);  // Titik kanan bawah
    glEnd();
}

// Fungsi untuk menggambar ke layar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawTriangle();  // Gambar segitiga 2D

    glFlush();
}

// Setup awal OpenGL
void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Background gelap

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Mode 2D
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Segitiga 2D OpenGL");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
