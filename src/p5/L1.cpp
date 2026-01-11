#include <GL/glut.h>

// Variabel untuk transformasi
float xPos = 0.0f;   // posisi X (translate)
float yPos = 0.0f;   // posisi Y (translate)
float zPos = -6.0f;  // posisi Z (translate)

float xRot = 0.0f;   // rotasi di sumbu X
float yRot = 0.0f;   // rotasi di sumbu Y
float scale = 1.0f;  // skala objek

// Fungsi untuk menggambar tetrahedron (segitiga 3D)
void gambarsegitiga() {
    glBegin(GL_TRIANGLES);

    // Sisi depan (merah)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f( 0.0, 1.0, 0.0);
    glVertex3f(-1.0,-1.0, 1.0);
    glVertex3f( 1.0,-1.0, 1.0);

    // Sisi kanan (hijau)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f( 0.0, 1.0, 0.0);
    glVertex3f( 1.0,-1.0, 1.0);
    glVertex3f( 1.0,-1.0,-1.0);

    // Sisi kiri (biru)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 0.0, 1.0, 0.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0, 1.0);

    // Sisi bawah (kuning)
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0,-1.0, 1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f( 1.0,-1.0,-1.0);

    glEnd();
}

// Fungsi untuk menampilkan objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Penerapan transformasi
    glTranslatef(xPos, yPos, zPos);
    glScalef(scale, scale, scale);
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);

    gambarsegitiga();

    glutSwapBuffers();
}

// Fungsi input keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Gerakan (Translate)
        case 'w': yPos += 0.1f; break;
        case 's': yPos -= 0.1f; break;
        case 'a': xPos -= 0.1f; break;
        case 'd': xPos += 0.1f; break;
        case 'z': zPos += 0.1f; break;
        case 'x': zPos -= 0.1f; break;

        // Rotasi
        case 'i': xRot += 5.0f; break;
        case 'k': xRot -= 5.0f; break;
        case 'j': yRot += 5.0f; break;
        case 'l': yRot -= 5.0f; break;

        // Skala
        case '+': scale += 0.1f; break;
        case '-': scale -= 0.1f; if (scale < 0.1f) scale = 0.1f; break;

        // Keluar
        case 27: exit(0); // ESC
    }

    glutPostRedisplay();
}

// Pengaturan awal
void init3D() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

// Fungsi reshape (jika jendela diubah ukurannya)
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(720, 720);
    glutCreateWindow("2406017 - anwarIbrahim - Grapkom");

    init3D();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
