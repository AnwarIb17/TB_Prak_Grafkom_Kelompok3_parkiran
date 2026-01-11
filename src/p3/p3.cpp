#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(0, 0, 0);
    glPointSize(1.5);

    glBegin(GL_LINE_LOOP);
    for (float x = -1.5f; x <= 1.5f; x+= 0.01f)
    {
        float y = 0.8f * (x * x);
        glVertex2f(x, y - 0.5);
    }
    glEnd();

    glColor3ub(100, 100, 0);
    glBegin(GL_LINES);
    glVertex2f(-20.0f, 0.0f);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(0.0f, -20.0f);
    glVertex2f(0.0f, 20.0f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2406017-Anwar Ibrahim");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}