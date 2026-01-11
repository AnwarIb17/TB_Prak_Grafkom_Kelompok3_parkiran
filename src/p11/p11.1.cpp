#include <GL/glut.h> 
#include <math.h> 
 
float tick[3] = {0.0, 0.0, 0.0}; 
int windows[10]; 
int size = 0; 
 
void drawCartecius(); 
void initScene(); 
void firstWindows(); 
void secondWindows(); 
void thirdWindows(); 
void addWindows(const char *title, void (*displayCallback)(void), void 
(*initCallback)(void)); 
void keyboard(unsigned char key, int x, int y); 
 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitWindowSize(800, 800);  
    glutInitWindowPosition(200, 0); 
    addWindows("First", firstWindows, initScene); 
 
    glutInitWindowSize(400, 400);  
    glutInitWindowPosition(50, 0); 
    addWindows("Second", secondWindows, initScene); 
 
    glutInitWindowSize(400, 400);  
    glutInitWindowPosition(800, 0); 
    addWindows("Third", thirdWindows, initScene); 
 
    glutKeyboardFunc(keyboard); 
    glutMainLoop(); 
    return 0; 
} 
 
void drawCartecius() 
{ 
    glLineWidth(1.0); 
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_LINES); 
 
    glVertex3f(-50.0, 0.0, 0.0); 
    glVertex3f(50.0, 0.0, 0.0); 
 
    glVertex3f(0.0, -50.0, 0.0); 
    glVertex3f(0.0, 50.0, 0.0); 
 
    glVertex3f(0.0, 0.0, -50.0); 
    glVertex3f(0.0, 0.0, 50.0); 
    glEnd(); 
} 
 
void initScene() 
{ 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_COLOR_MATERIAL); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(70.0, 1.0, 1.0, 100.0); 
    gluLookAt(10.0, 10.0, 17.0, 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0); 
    glMatrixMode(GL_MODELVIEW); 
    glClearColor(0.1, 0.1, 0.1, 1.0); 
} 
 
void thirdWindows() 
{ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    drawCartecius(); 
    glPushMatrix(); 
 
    glRotatef(tick[2] += 0.1, 1.0, 1.0, 1.0); 
    glColor3f(0.7, 0.7, 0.7); 
    glutSolidCube(10); 
    glColor3f(0.9, 0.9, 0.9); 
    glutWireCube(11); 
 
    glPopMatrix(); 
    glutSwapBuffers(); 
    glutPostRedisplay(); 
} 
 
void secondWindows() 
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    drawCartecius(); 
    glPushMatrix(); 
    glRotatef(tick[1] += 1, 1.0, 0.0, 1.0); 
    glColor3f(0.7, 0.7, 0.7); 
    glutSolidSphere(10, 35, 35); 
    glColor3f(0.9, 0.9, 0.9); 
    glutWireSphere(11, 35, 35); 
 
    glPopMatrix(); 
    glutSwapBuffers(); 
    glutPostRedisplay(); 
} 
 
void firstWindows() 
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    drawCartecius(); 
    glPushMatrix(); 
    glRotatef(tick[0] += 0.1, 0.0, 1.0, 1.0); 
    glColor3f(0.7, 0.7, 0.7); 
    glutSolidTeapot(10); 
    glColor3f(0.9, 0.9, 0.9); 
    glutWireTeapot(11); 
 
    glPopMatrix(); 
    glutSwapBuffers(); 
    glutPostRedisplay(); 
} 
 
void addWindows(const char *title, void (*displayCallback)(void), void 
(*initCallback)(void)) 
{ 
    windows[size++] = glutCreateWindow(title); 
    glutDisplayFunc(displayCallback); 
    initCallback(); 
} 
 
void keyboard(unsigned char key, int x, int y) 
{ 
     
        if (key == 'q') 
        { 
            for (int i = 0; i < size; i++) 
            { 
                glutDestroyWindow(windows[i]); 
            } 
        } 
     
} 