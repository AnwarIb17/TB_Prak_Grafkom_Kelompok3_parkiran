#include <GL/glut.h>

float angle = 0.0; // sudut rotasi

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.0, 0.0, 0.5); // warna biru gelap

    // Rotasi terhadap sumbu Z
    glRotatef(angle, 0.0, 0.0, 1.0);

    // Gambar segitiga
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 15.0);    // Titik atas
        glVertex2f(-15.0, -10.0); // Titik kiri bawah
        glVertex2f(15.0, -10.0);  // Titik kanan bawah
    glEnd();

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r':
        case 'R':
            angle += 45.0; // tambah sudut 15 derajat setiap tekan 'r'
            if (angle >= 360.0)
                angle = 0.0;
            glutPostRedisplay();
            break;
    }
}

void init(const char *title)
{
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0); // latar belakang putih
    glColor3f(0.0, 0.0, 0.0);         // warna garis hitam
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);

    init("2406017_anwar_Ibrahim");

    glutMainLoop(); // menjalankan loop utama

    return 0;
}
