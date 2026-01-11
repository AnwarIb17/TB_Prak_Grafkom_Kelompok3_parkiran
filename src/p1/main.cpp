#include <GL/glut.h> 


class sumbuGaris {
    public:
    float negatif = -0.5f;
    float positif = 0.5f;
    void tambah(int x, int y) {
        negatif += x;
        positif += y;
    };
    void kurang(int y, int x) {
        negatif -= x;
        positif-= y;
    }
}sumbu;

void display() {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(sumbu.negatif, sumbu.negatif);
        glVertex2f( sumbu.positif, sumbu.negatif);
        glVertex2f( sumbu.positif,  sumbu.positif);
        glVertex2f(sumbu.negatif,  sumbu.positif);
    glEnd();

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
        sumbu.tambah(x = 0.5f, y = 0.5f);
        case '-':
        sumbu.kurang(x = 0.5f, y = 0.5f);
        }
        glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Kelompok");
    glutInitWindowSize(640, 480);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();

    return 0;
}
