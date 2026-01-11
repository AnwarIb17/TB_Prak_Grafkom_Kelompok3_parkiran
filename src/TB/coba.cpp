#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>

// -------------------------------------------------------------
// VARIABEL GLOBAL KAMERA
// -------------------------------------------------------------
float kameraX = 30.0f;
float kameraY = 30.0f;
float kameraZ = 30.0f;

// STATUS LAMPU
bool lampOn = true;

// Quadric
GLUquadric* quad = nullptr;

// -------------------------------------------------------------
// INISIALISASI QUADRIC
// -------------------------------------------------------------
void initQuadric() {
    quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
}

// -------------------------------------------------------------
// FUNGSI GAMBAR KUBUS
// -------------------------------------------------------------
void Kubus(float x, float y, float z,
           float rotateX, float rotateY, float rotateZ,
           float sizeX, float sizeY, float sizeZ)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotateX,1,0,0);
    glRotatef(rotateY,0,1,0);
    glRotatef(rotateZ,0,0,1);
    glScalef(sizeX, sizeY, sizeZ);
    glutSolidCube(1.0f);
    glPopMatrix();
}

// -------------------------------------------------------------
// TABUNG
// -------------------------------------------------------------
void Tabung(float x, float y, float z,
            float rotX, float rotY, float rotZ,
            float rBawah, float rAtas,
            float tinggi, int slices)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);
    gluCylinder(quad, rBawah, rAtas, tinggi, slices, 1);
    glPopMatrix();
}

// -------------------------------------------------------------
// BOLA (BOHLAM + CAHAYA)
// -------------------------------------------------------------
void bohlam() {
    glPushMatrix();
    glTranslatef(0, 15, 0);

    if (lampOn) {
        glEnable(GL_LIGHT1);

        float pos[]      = {0, 0, 0, 1};
        float diffuse[]  = {1.0f, 1.0f, 0.8f, 1.0f};
        float ambient[]  = {0.3f, 0.3f, 0.2f, 1.0f};
        float specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

        glLightfv(GL_LIGHT1, GL_POSITION, pos);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular);

        glColor3f(1.0f, 1.0f, 0.0f);
    } else {
        glDisable(GL_LIGHT1);
        glColor3f(0.3f, 0.3f, 0.3f); // bohlam mati
    }

    glutSolidSphere(1.0f, 32, 32);
    glPopMatrix();
}

// -------------------------------------------------------------
// LAMPU JALAN
// -------------------------------------------------------------
void lampu() {
    glColor3f(0.8f, 0.8f, 0.8f);

    Tabung(0, 15, 0, 90, 0, 0, 0.5f, 0.5f, 15.0f, 32);
    Tabung(0, 15, 0, 90, 0, 0, 2.0f, 0.5f, 2.0f, 32);
    Tabung(0, 5, 0, 90, 0, 0, 0.5f, 2.0f, 5.0f, 32);

    Kubus(0, 0, 0, 0, 0, 0, 6, 1, 6);
    Kubus(0, 1, 0, 0, 0, 0, 2.4f, 3, 2.4f);

    bohlam();
}

// -------------------------------------------------------------
// DISPLAY
// -------------------------------------------------------------
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(kameraX, kameraY, kameraZ,
              0, 0, 0,
              0, 1, 0);

    lampu();

    glutSwapBuffers();
}

// -------------------------------------------------------------
// KEYBOARD (ON / OFF)
// -------------------------------------------------------------
void keyboard(unsigned char key, int, int) {
    if (key == 'l' || key == 'L') lampOn = true;
    if (key == 'o' || key == 'O') lampOn = false;
    glutPostRedisplay();
}

// -------------------------------------------------------------
// INIT OPENGL
// -------------------------------------------------------------
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    float lightPos0[] = {10, 20, 10, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

// -------------------------------------------------------------
// RESHAPE
// -------------------------------------------------------------
void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

// -------------------------------------------------------------
// MAIN
// -------------------------------------------------------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kelompok 3");

    init();
    initQuadric();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}
