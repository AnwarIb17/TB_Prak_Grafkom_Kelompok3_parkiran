#include <GL/glut.h>

void garis();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(350, 100);
    glutCreateWindow("2406017 - Anwar Ibrahim");

    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(garis);
    glutMainLoop();
    return 0;
}

// void garis() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glBegin(GL_LINES);
//         // Garis pertama (bawah) - biru tua
//         glColor3f(0.0f, 0.0f, 0.5f);
//         glVertex2f(-0.5f, -0.5f);
//         glVertex2f(0.5f, -0.5f);

//         // Garis kedua (tengah) - biru muda
//         glColor3f(0.0f, 0.5f, 1.0f);
//         glVertex2f(-0.5f, 0.0f);
//         glVertex2f(0.5f, 0.0f);

//         // Garis ketiga (atas) - putih
//         glColor3f(0.0f, 1.0f, 1.0f);
//         glVertex2f(-0.5f, 0.5f);
//         glVertex2f(0.5f, 0.5f);
//     glEnd();
//     glFlush();
// }

// void garis() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     glBegin(GL_LINES);

//         glColor3f(0.0f, 0.0f, 0.5f);
//         glVertex2f(-0.5f, -0.5f);   // titik bawah
//         glVertex2f(-0.5f,  0.5f);   // titik atas

//         glColor3f(0.0f, 0.5f, 1.0f);
//         glVertex2f(0.0f, -0.5f);    // titik bawah
//         glVertex2f(0.0f,  0.5f);    // titik atas

//         glColor3f(1.0f, 0.0f, 1.0f);
//         glVertex2f(0.5f, -0.5f);    // titik bawah
//         glVertex2f(0.5f,  0.5f);    // titik atas

//     glEnd();

//     glFlush();
// }

// void garis() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     glBegin(GL_LINES);

//         // Garis miring biru tua
//         glColor3f(0.0f, 0.0f, 0.5f);
//         glVertex2f(-0.5f, -0.5f);   // titik kiri bawah
//         glVertex2f( 0.5f,  0.5f);   // titik kanan atas

//         // Garis miring biru muda
//         glColor3f(0.0f, 0.5f, 1.0f);
//         glVertex2f(-0.5f,  0.5f);   // titik kiri atas
//         glVertex2f( 0.5f, -0.5f);   // titik kanan bawah

//     glEnd();

//     glFlush();
// }

void garis() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);   // merah

        // Bawah
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);

        // Kanan
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);

        // Atas
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);

        // Kiri
        glVertex2f(-0.5f,  0.5f);
        glVertex2f(-0.5f, -0.5f);
    glEnd();

    glFlush();
}
