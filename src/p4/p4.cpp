#include <GL/glut.h>

float xPos = 0.0;
float yPos = 0.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.5); // warna biru gelap

    glLoadIdentity();

    // Geser posisi segitiga sesuai input
    glTranslated(xPos, yPos, 0);

    // Gambar segitiga
    glBegin(GL_TRIANGLES);
        glVertex2f(5.0, 15.0);    // titik atas
        glVertex2f(0.0, 5.0);     // titik kiri bawah
        glVertex2f(10.0, 5.0);    // titik kanan bawah
    glEnd();

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
    case 'D':
        xPos += 1.0; // geser kanan
        break;
    case 'a':
    case 'A':
        xPos -= 1.0; // geser kiri
        break;
    case 'w':
    case 'W':
        yPos += 1.0; // geser atas
        break;
    case 's':
    case 'S':
        yPos -= 1.0; // geser bawah
        break;
    }
    glutPostRedisplay(); // gambar ulang
}

void myInit(const char *title)
{
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 50.0, 0.0, 50.0); // area pandang
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

    myInit("2406017_AnwarIbrahim");

    glutMainLoop();
    return 0;
}
