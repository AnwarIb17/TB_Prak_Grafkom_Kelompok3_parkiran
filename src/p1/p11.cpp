#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>   // untuk fungsi exit()

// 🔹 Variabel global
float objects = 10.0;          // jumlah objek yang berputar
float PI = 3.1416;             // nilai pi
float radius = 40.0;           // jarak benda dari pusat
float rotationAngle = 100.0;     // sudut rotasi benda luar
float rotation = 100.0;          // rotasi bola tengah
float aspect;                  // rasio layar

// posisi awal cahaya
GLfloat light_position[4] = {0.0, 1.5, 0.0, 1.0};

// ---------------------------------------------------
// 🔹 FUNGSI: Mengatur tampilan saat ukuran layar berubah
void reshape(int w, int h) {
    if (h == 0) h = 1;                 // hindari pembagian dengan nol
    aspect = (float)w / (float)h;      // hitung rasio layar

    glViewport(0, 0, w, h);            // area gambar sesuai ukuran jendela

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // atur pandangan kamera (sudut pandang)
    gluPerspective(90.0, aspect, 1.0, 100.0);

    // posisi kamera: (posisi mata, titik yang dilihat, arah atas)
    gluLookAt(0.0, 20.0, 70.0,   // posisi kamera
              0.0, -20.0, 0.0,   // titik pusat pandangan
              0.0, 1.0, 0.0);    // arah atas kamera
}

// ---------------------------------------------------
// 🔹 FUNGSI: Menggambar objek-objek di dunia 3D
void objek() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 🟥 Bola di tengah
    glPushMatrix();
    glColor3ub(255, 0, 0);             // warna merah
    glRotatef(rotation, 0, 1, 0);     // rotasi bola
    glRotatef(90, 1.0, 0.0, 0.0);     // posisi bola
    glutSolidSphere(10.0, 30, 30);    // gambar bola
    glPopMatrix();

    // 🔷 Objek-objek luar (lapisan pertama)
    for (int i = 0; i < objects; ++i) {
        float angle = (i * (360.0f / objects) * (PI / 180.0f)) + rotationAngle;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glPushMatrix();
        glTranslatef(x, 0.0f, z);
        glutSolidTetrahedron();        // piramida kecil
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x * 1.2f, 1.0f, z * 1.2f);
        glutSolidDodecahedron();       // bola 12 sisi
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x * 1.3f, -1.0f, z * 1.2f);
        glutSolidIcosahedron();        // bola 20 sisi
        glPopMatrix();
    }

    // 🔶 Lapisan luar kedua (miring)
    glPushMatrix();
    glRotatef(30.0, 1.0, 0.0, 0.5);
    for (int i = 0; i < objects; ++i) {
        float angle = (i * (360.0f / objects) * (PI / 180.0f)) - rotationAngle;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glPushMatrix();
        glTranslatef(x, 0.0f, z);
        glutSolidTetrahedron();
        glPopMatrix();
    }
    glPopMatrix();

    // Perbarui sudut rotasi agar objek terus berputar
    rotation += 0.001;         // rotasi bola tengah
    rotationAngle += 0.001;   // rotasi benda-benda luar
}

// ---------------------------------------------------
// 🔹 FUNGSI: Mengatur kontrol keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:  // tombol ESC untuk keluar
            exit(0);
            break;
        case 'w': // maju ke depan
            light_position[2] -= 2.0;
            break;
        case 's': // mundur ke belakang
            light_position[2] += 2.0;
            break;
        case 'd': // geser ke kanan
            light_position[0] += 2.0;
            break;
        case 'a': // geser ke kiri
            light_position[0] -= 2.0;
            break;
        case 'r': // reset ke posisi awal
            light_position[0] = 0.0;
            light_position[2] = 0.0;
            break;
    }

    // Perbarui posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

// ---------------------------------------------------
// 🔹 FUNGSI: Menampilkan gambar ke layar
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // bersihkan layar dan z-buffer

    // Gambarkan posisi cahaya (tanpa efek pencahayaan)
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(light_position[0], light_position[1], light_position[2]);
    glEnd();

    // Titik posisi cahaya
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex3f(light_position[0], light_position[1], light_position[2]);
    glEnd();
    glEnable(GL_LIGHTING);

    // Gambar objek utama
    objek();

    glutSwapBuffers();     // tukar buffer (untuk animasi halus)
    glutPostRedisplay();   // panggil ulang display agar terus bergerak
}

// ---------------------------------------------------
// 🔹 FUNGSI: Mengatur pencahayaan dan pengaturan awal
void inisialisasi() {
    GLfloat light_diffuse[4]  = {1.0, 1.0, 1.0, 1.0};   // cahaya putih
    GLfloat light_ambient[4]  = {0.0, 0.0, 0.0, 1.0};   // tanpa cahaya sekitar
    GLfloat light_specular[4] = {1.0, 1.0, 1.0, 1.0};   // cahaya pantulan

    // atur sifat cahaya
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // aktifkan pencahayaan dan pengaturan penting lainnya
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    // warna latar belakang abu-abu gelap
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

// ---------------------------------------------------
// 🔹 FUNGSI: Main — pusat program
int main(int argc, char **argv) {
    glutInit(&argc, argv);                                // inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // aktifkan mode 3D
    glutInitWindowSize(1000, 700);                        // ukuran jendela
    glutInitWindowPosition(100, 50);                      // posisi jendela
    glutCreateWindow("2406026 - Putri Fitriani Azzahra"); // judul jendela

    inisialisasi();                   // panggil pengaturan awal
    glutDisplayFunc(display);         // fungsi untuk menggambar
    glutReshapeFunc(reshape);         // fungsi untuk menyesuaikan layar
    glutKeyboardFunc(keyboard);       // fungsi untuk kontrol keyboard
    glutMainLoop();                   // jalankan program tanpa henti

    return 0;
}
