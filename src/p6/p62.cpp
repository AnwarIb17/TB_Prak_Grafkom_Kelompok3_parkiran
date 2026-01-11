#include <GL/glut.h>
#include <math.h>

float objects = 10.0;
float PI = 3.1416;
float radius = 40.0;
float rotationAngle = 0.0;
float rotation = 0.0;
float aspect;

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

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // ESC
        exit(0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bola tengah berputar perlahan
    glPushMatrix();
    glColor3ub(126, 212, 173);
    glRotatef(rotation, 0, 1, 0);
    glutSolidSphere(10.0, 30, 30);
    glPopMatrix();

    // Objek berputar melingkar
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

    // Octahedron berputar dengan sumbu miring
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

// Fungsi timer untuk mengatur kecepatan rotasi
void update(int value)
{
    rotationAngle += 0.02f;  // 🔹 Lebih kecil = lebih pelan
    rotation += 0.01f;       // 🔹 Bola tengah lebih pelan dari orbit luar

    if (rotationAngle > 360) rotationAngle -= 360;
    if (rotation > 360) rotation -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // panggil lagi setiap 16 ms (~60 FPS)
}

void inisialisasi()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Polyhedra Model (Slow & Smooth Rotation)");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    inisialisasi();
    glutTimerFunc(0, update, 0); // mulai animasi terjadwal
    glutMainLoop();
    return 0;
}
