#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glColor3f(1.0, 0.0, 0.0);         
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 10.0, -2.0, 2.0); 
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glColor3ub(30, 32, 30);
    glPointSize(2.0);
    glBegin(GL_LINE_STRIP);
    for (float x = 0.0; x <= 6.28; x += 0.1) {
        float y = sin(x);
        glVertex2f(x, y);
    }
    glEnd();

    
    glBegin(GL_LINES);
    glColor3ub(60, 61, 55);
    glVertex2f(-10.0, 0.0);
    glVertex2f(10.0, 0.0);
    glVertex2f(0.0, -10.0);
    glVertex2f(0.0, 10.0);
    glEnd();

    glFlush();
}

void kunci(unsigned char key, int x, int y) {
    switch (key) {
        case 27:  // ESC
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2406017-ANWAR IBRAHIM");

    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);

    myinit();
    glutMainLoop();
    return 0;
}
