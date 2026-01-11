#include <GL/glut.h>

// Fungsi untuk menggambar segi empat
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar

    glColor3f(0.0f, 0.8f, 0.3f);  // Warna hijau

    glBegin(GL_QUADS);            // Menggambar segi empat
        glVertex2f(-0.5f, -0.5f); // Titik kiri bawah
        glVertex2f( 0.5f, -0.5f); // Titik kanan bawah
        glVertex2f( 0.5f,  0.5f); // Titik kanan atas
        glVertex2f(-0.5f,  0.5f); // Titik kiri atas
    glEnd();

    glFlush();
}

// Setup tampilan awal
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Mengatur sistem koordinat 2D
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Away");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
