#include <GL/glut.h>

GLfloat ctrlPoints[4][3] = {
    {-4.0, -2.0, 0.0},
    {-2.0,  4.0, 0.0},
    { 2.0, -4.0, 0.0},
    { 4.0,  2.0, 0.0}
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar titik kontrol
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++)
        glVertex3fv(ctrlPoints[i]);
    glEnd();

    // Gambar kurva Bézier
    glColor3f(0.0, 0.0, 1.0);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlPoints[0][0]);
    glEnable(GL_MAP1_VERTEX_3);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glEnable(GL_MAP1_VERTEX_3);
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kurva Bezier 2D");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}