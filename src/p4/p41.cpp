#include <GL/glut.h>

// Variabel untuk skala
float xPos = 1.0;
float yPos = 1.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.5); // warna biru gelap

    glLoadIdentity();
    glScalef(xPos, yPos, 1.0); // skala objek

    // Gambar segitiga
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 15.0);    // Titik atas
        glVertex2f(-10.0, -10.0); // Titik kiri bawah
        glVertex2f(10.0, -10.0);  // Titik kanan bawah
    glEnd();

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'd':
        case 'D':
            xPos += 0.1; // perbesar skala horizontal
            break;
        case 'a':
        case 'A':
            xPos -= 0.1; // perkecil skala horizontal
            if (xPos < 0.1) xPos = 0.1; // mencegah skala negatif
            break;
        case 'w':
        case 'W':
            yPos += 0.1; // perbesar skala vertikal
            break;
        case 's':
        case 'S':
            yPos -= 0.1; // perkecil skala vertikal
            if (yPos < 0.1) yPos = 0.1;
            break;
    }
    glutPostRedisplay(); // gambar ulang layar
}

// Inisialisasi tampilan
void init()
{
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
    glutCreateWindow("2406017_AnwarIbrahim");

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);

    init();
    glutMainLoop();

    return 0;
}
