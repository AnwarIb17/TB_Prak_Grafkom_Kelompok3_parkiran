#include <GL/glut.h>
#include <math.h>

float objects = 10.0;
float PI = 3.1416;
float radius = 40.0;
float rotationAngle = 0.0;
float rotation = 0.0;
float aspect;

// 🔹 Posisi awal cahaya
GLfloat light_position[4] = {0.0, 20.0, 50.0, 1.0};

void reshape(int w, int h)
{
    if (h == 0) h = 1;
    aspect = (float)w / (float)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 200.0);
    gluLookAt(0.0, 20.0, 70.0, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void inisialisasi()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    glClearColor(0.1, 0.1, 0.1, 1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 🔹 Perbarui posisi kamera
    gluLookAt(0.0, 20.0, 70.0, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);

    // 🔹 Gambar posisi cahaya
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(light_position[0], light_position[1], light_position[2]);
    glEnd();

    glPointSize(6.0);
    glBegin(GL_POINTS);
    glVertex3f(light_position[0], light_position[1], light_position[2]);
    glEnd();
    glEnable(GL_LIGHTING);

    // 🔹 Bola tengah
    glPushMatrix();
    glColor3ub(126, 212, 173);
    glRotatef(rotation, 0, 1, 0);
    glutSolidSphere(10.0, 30, 30);
    glPopMatrix();

    // 🔹 Polyhedra berputar melingkar
    for (int i = 0; i < objects; ++i)
    {
        float angle = (i * (360.0f / objects) * (PI / 180.0f)) + rotationAngle;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glPushMatrix();
        glTranslatef(x, 0.0f, z);
        glutSolidTetrahedron();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x * 1.2f, 1.0f, z * 1.2f);
        glutSolidDodecahedron();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x * 1.3f, -1.0f, z * 1.2f);
        glutSolidIcosahedron();
        glPopMatrix();
    }

    // 🔹 Octahedron berputar miring
    glPushMatrix();
    glRotatef(5.0, 1.0, 0.0, 0.5);
    for (int i = 0; i < objects; ++i)
    {
        float angle = (i * (360.0f / objects) * (PI / 180.0f)) - rotationAngle;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glPushMatrix();
        glTranslatef(x, 0.0f, z);
        glutSolidOctahedron();
        glPopMatrix();
    }
    glPopMatrix();

    glutSwapBuffers();
}

// 🔹 Fungsi timer untuk rotasi halus
void update(int value)
{
    rotationAngle += 0.02f;
    rotation += 0.01f;

    if (rotationAngle > 360) rotationAngle -= 360;
    if (rotation > 360) rotation -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// 🔹 Kontrol cahaya
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // ESC
        exit(0);
        break;
    case 'w':
        light_position[2] -= 1.0;
        break;
    case 's':
        light_position[2] += 1.0;
        break;
    case 'a':
        light_position[0] -= 1.0;
        break;
    case 'd':
        light_position[0] += 1.0;
        break;
    case 'r':
        light_position[0] = 0.0;
        light_position[2] = 50.0;
        break;
    }

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2406017_AnwarIbrahim_T6");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    inisialisasi();
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
