#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int n = 5;         
    int k = 2;         
    float r = 0.8f;    
    float angle;       
    float x[10], y[10]; 

    for (int i = 0; i < n; i++) {
        angle = 2 * PI * i / n;   
        x[i] = r * cos(angle);    
        y[i] = r * sin(angle);    
    }
    glColor3f(1.0f, 0.5f, 0.0f);  
    glBegin(GL_LINES);
    for (int i = 0; i < n; i++) {
        int next = (i + k) % n;
        glVertex2f(x[i], y[i]);      
        glVertex2f(x[next], y[next]);
    }
    glEnd();

    glFlush(); 
}


void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glColor3f(0.0f, 0.0f, 0.0f);          
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);                 
    glutCreateWindow("Bintang Geometri");
    init();                                       
    glutDisplayFunc(display);                     
    glutMainLoop();                               
    return 0;
}
