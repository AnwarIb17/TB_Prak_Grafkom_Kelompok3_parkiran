#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath> // Untuk fungsi cos, sin, dan atan (jika diperlukan)

// Definisikan PI untuk perhitungan sudut
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// KAMERA (Posisi kamera akan dihitung)
float kameraX;
float kameraY;
float kameraZ;

// PARAMETER ORBIT KAMERA
// Nilai awal dihitung agar mendekati posisi kamera awal (100, 50, 100.01)
float cameraRadius = 150.0f; // Jarak kamera dari titik tengah (0,0,0)
float cameraAngle_h = M_PI / 4.0f; // Sudut horizontal (radian, 45 derajat)
float cameraAngle_v = 0.3398f; // Sudut vertikal (radian, sekitar 19.5 derajat)
float angle_step = 0.05f; // Kecepatan rotasi
float radius_step = 5.0f; // Kecepatan zoom

// STATUS LAMPU
bool lampOn = true;

// Quadric untuk tabung & bola
GLUquadric* quad = nullptr;

// INISIALISASI QUADRIC
void initQuadric() {
  quad = gluNewQuadric();
  gluQuadricNormals(quad, GLU_SMOOTH);
}

// Template Kubus
void Kubus( float x, float y, float z,
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

// Template Tabung
void Tabung(float x, float y, float z,
            float rotX, float rotY, float rotZ,
            float radiusAtas, float radiusBawah,
            float tinggi, int slices) 
{
  glPushMatrix();
  glTranslatef(x, y, z);
  glRotatef(rotX, 1, 0, 0);
  glRotatef(rotY, 0, 1, 0);
  glRotatef(rotZ, 0, 0, 1);

  gluCylinder(quad, radiusBawah, radiusAtas, tinggi, slices, 1);

  glPopMatrix();
}

//Template Bola
void Bola(float x, float y, float z, float radius) 
{
  glPushMatrix();
  glTranslatef(x, y, z);
  glutSolidSphere(radius, 32, 32);
  glPopMatrix();
}

//Aef
//Benteng
void benteng(){
  glPushMatrix();
  glColor3f(0.35,0.35,0.35); ///benteng
  Kubus(0,0,0,0,0,0,20,4,1);
  glPopMatrix();

  //keramik 
  glPushMatrix();
  glColor3f(5.0f, 5.0f, 5.0f);
  Kubus(0,0,0,0,0,45,1.8,2,1.3);
  Kubus(-6,0,0,0,0,45,1.8,2,1.3);
  Kubus(6,0,0,0,0,45,1.8,2,1.3);
  glPopMatrix();

  //besi berdiri
  glPushMatrix();
  glColor3f(0.85,0.85,0.85);
  Tabung(-9.5,5,0,90,0,0,0.5,0.5,4,32); 
  Tabung(9.5,5,0,90,0,0,0.5,0.5,4,32);
  Tabung(0,5,0,90,0,0,0.5,0.5,4,32);
  Tabung(-4.75,5,0,90,0,0,0.5,0.5,4,32);
  Tabung(4.75,5,0,90,0,0,0.5,0.5,4,32);
  Tabung(-10,5,0,0,90,0,0.5,0.5,20,32);
  glPopMatrix();

  //besi panjang di tengah
  glPushMatrix();
  glColor3f(0.35,0.35,0.35);
  Tabung(-10,3.5,0,0,90,0,0.2,0.2,20,32);
  glPopMatrix();
  
  //besi silang
  glPushMatrix();
  glColor3f(0.35,0.35,0.35);
  Tabung(-9.1,4.7,0,90,58,0,0.2,0.2,5,32); ///miring ke kiri 1
  Tabung(-4.2,4.7,0,90,58,0,0.2,0.2,5,32); ///miring ke kiri 2
  Tabung(4.9,4.7,0,90,58,0,0.2,0.2,5,32); ///miring ke kiri 3
  Tabung(0.6,4.7,0,90,58,0,0.2,0.2,5,32); ///miring ke kiri
  Tabung(-5,4.7,0,90,-58,0,0.2,0.2,5,32); ///miring ke kanan 
  Tabung(-0,4.7,0,90,-58,0,0.2,0.2,5,32); ///miring ke kanan
  Tabung(4.4,4.7,0,90,-58,0,0.2,0.2,5,32); ///miring ke kanan
  Tabung(9.1,4.7,0,90,-58,0,0.2,0.2,5,32); ///miring ke kanan
  glPopMatrix();
  
  //hiasan di atas besi yang bulet
  glPushMatrix();
  glColor3f(0.35,0.35,0.35);
  Bola(0,5.5,0,0.7);
  Bola(-9.5,5.5,0,0.7);
  Bola(9.5,5.5,0,0.7);
  Bola(-4.75,5.5,0,0.7);
  Bola(4.75,5.5,0,0.7);
  glPopMatrix();
}

//haikal rapi
//pohon
void tanaman(){
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    Kubus(0,0,0,90,0,0,3,3,0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.8,0.5,0.2);
    Tabung(0,5,0,90,0,0,1,0.6,5,30);  
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,1,0);
    Bola(0,5,0,0.7);
    Bola(0,6,0,0.7);
    Bola(0,7,0,0.7);
    Bola(1,6.5,0,0.7);
    Bola(1,5.5,0,0.7);
    Bola(-1,6.5,0,0.7);
    Bola(-1,5.5,0,0.7);
    Bola(0,6.5,1,0.7);
    Bola(0,5.5,1,0.7);
    Bola(0,6.5,-1,0.7);
    Bola(0,5.5,-1,0.7);
    Bola(0,6,2,0.7);
    Bola(0,6,-2,0.7);
    Bola(2,6,0,0.7);
    Bola(-2,6,0,0.7);
    Bola(-2,6,0,0.7);
    Bola(0.7,6,0.8,0.7);
    Bola(-0.7,6,0.8,0.7);
    Bola(-0.7,6,-0.8,0.7);
    Bola(0.7,6,-0.8,0.7);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    Bola(1,6,1,0.3);
    Bola(0.9,7,1,0.3);
    Bola(1,7,-2,0.3);
    glPopMatrix();
}

//anwar
//roda mobil
void roda(){
  glPushMatrix();
  glColor3f(1.0f, 0.0f, 0.0f);
  //pelk
  Tabung(0,1,0,90,0,0,0.1f,0.1f,2.0f,32);
  Tabung(-1,0,0,0,90,0,0.1f,0.1f,2.0f,32);
  Tabung(-0.7,0.7,0,90,45,0,0.1f,0.1f,2.0f,32);
  Tabung(0.7,0.7,0,90,-45,0,0.1f,0.1f,2.0f,32);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  //roda
  Tabung(0,0,-0.3,0,0,0,1.0f,1.0f,0.5f,32);
  glPopMatrix();
}
//Anwar
void mobil(){
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  Kubus(0,0,0,0,0,0,10.0f,0.5f,6.0f); // BAK BAWAH
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.5f, 0.5f, 0.5f);
  Kubus(-5.2,0.8,0,0,0,0,0.5f,2.0f,7.0f); //BAK DEPAN
  Kubus(5.2,0.8,0,0,0,0,0.5f,2.0f,7.0f); //BAK BELAKANG
  Kubus(0,0.8,3.2,0,0,0,10.0f,2.0f,0.5f); // BAK KANAN
  Kubus(0,0.8,-3.2,0,0,0,10.0f,2.0f,0.5f); // BAK KIRI
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.5f, 0.5f, 0.5f);
  Kubus(-7,3,0,0,0,0,5.0f,6.3f,7.4f); // KEPALA MOBIL UTAMA
  Kubus(-9,1.4,0,0,0,0,5.0f,3.0f,7.4f); // KEPALA MOBIL BAWAH
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glRotatef(45,0,0,1);
  Kubus(-4,10,0,0,0,0,4.0f,0.3f,7.4f); //KACA MOBIL
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0f, 1.0f, 0.0f);
  Bola(-11.9,1,2,0.5f); // LAMPU KANAN DEPAN
  Bola(-11.9,1,-2,0.5f); // LAMPU KIRI DEPAN
  glPopMatrix();
  glPushMatrix();
  glColor3f(0.5f, 0.5f, 0.5f);
  Tabung(-11.9,1.0,2,90,90,0,0.5f,0.5f,0.5f,32); // kap LAMPU KANAN DEPAN
  Tabung(-11.9,1.0,-2,90,90,0,0.5f,0.5f,0.5f,32); // kap LAMPU KIRI DEPAN
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-7.5f,-0.5f,4.5f);
  glScalef(1.5f,1.5f,2.0f);
  roda(); //RODA KANAN DEPAN
  glPopMatrix();

  glPushMatrix();
  glTranslatef(3.0f,-0.5f,4.0f);
  glScalef(1.5f,1.5f,2.0f);
  roda(); //RODA KANAN BELAKANG
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-7.5f,-0.5f,-4.5f);
  glScalef(1.5f,1.5f,2.0f);
  roda(); //RODA KIRI DEPAN
  glPopMatrix();

  glPushMatrix();
  glTranslatef(3.0f,-0.5f,-4.0f);
  glScalef(1.5f,1.5f,2.0f);
  roda(); //RODA KIRI BELAKANG
  glPopMatrix();
}

//mamat
void bohlam() {
  glPushMatrix();
  glTranslatef(0, 15, 0);

  if (lampOn) {
    glEnable(GL_LIGHT1);

    float pos[]       = {0, 0, 0, 1};
    float diffuse[]   = {1.0f, 1.0f, 0.8f, 1.0f};
    float ambient[]   = {0.3f, 0.3f, 0.2f, 1.0f};
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

//mamat
// LAMPU JALAN
void lampu() {
  glColor3f(0.8f, 0.8f, 0.8f);

  Tabung(0, 15, 0, 90, 0, 0, 0.5f, 0.5f, 15.0f, 32);
  Tabung(0, 15, 0, 90, 0, 0, 2.0f, 0.5f, 2.0f, 32);
  Tabung(0, 5, 0, 90, 0, 0, 0.5f, 2.0f, 5.0f, 32);

  Kubus(0, 0, 0, 0, 0, 0, 6, 1, 6);
  Kubus(0, 1, 0, 0, 0, 0, 2.4f, 3, 2.4f);

  bohlam();
}


//Anwar
void LantaiParkiran(){
  glPushMatrix();
  glColor3f(0.3f, 0.3f, 0.3f);
  Kubus(0, -0.25f, 0, 0, 0, 0, 100.0f, 0.5f, 100.0f);
  glPopMatrix();
}

//Anwar
void trotoar(){
  //trotoar hitam
  glPushMatrix();
  glColor3f(0.4f, 0.4f, 0.4f);
  Kubus(0, 1.0f, 0.0f, 0, 0, 0, 100.0f, 2.0f, 12.0f);
  glPopMatrix();
  
  //garis luar trotoar
  glPushMatrix();
  glColor3f(0.98f, 0.95f, 0.50f);
  Kubus(0, 1.0f, 8.0f, 0, 0, 0, 100.0f, 2.0f, 3.0f);
  Kubus(0, 1.0f, -8.0f, 0, 0, 0, 100.0f, 2.0f, 3.0f);
  glPopMatrix();
}

void markajalan(){
  //marka jalan tengah
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  for (int i = -45; i <= 45; i += 10) {
    Kubus(0, 0.1f, i, 0, 0, 0, 2.0f, 0.2f, 5.0f);
  }
  glPopMatrix();
}

//anwar
// DISPLAY
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  // Hitung posisi kamera berdasarkan parameter orbit
  // Jarak XZ dari pusat
  float R_xz = cameraRadius * cos(cameraAngle_v);
  
  // Hitung koordinat X, Y, Z
  kameraX = R_xz * cos(cameraAngle_h);
  kameraY = cameraRadius * sin(cameraAngle_v);
  kameraZ = R_xz * sin(cameraAngle_h);

  gluLookAt(
      kameraX, kameraY, kameraZ,
      0, 0, 0,
      0, 1, 0
  );

  //lantai dasar parkiran
  glPushMatrix();
  LantaiParkiran();
  glPopMatrix();

  //tanaman
  glPushMatrix();
  glTranslatef(45,0,5);
  glScalef(2.0f,2.0f,2.0f);
  tanaman();
  glPopMatrix();

    glPushMatrix();
  glTranslatef(45,0,-10);
  glScalef(2.0f,2.0f,2.0f);
  tanaman();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(45,0,-25);
  glScalef(2.0f,2.0f,2.0f);
  tanaman();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45,0,5);
  glScalef(2.0f,2.0f,2.0f);
  tanaman();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45,0,-10);
  glScalef(2.0f,2.0f,2.0f);
  tanaman();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45,0,-25);
  glScalef(2.0f,2.0f,2.0f);
  tanaman();
  glPopMatrix();

  //marka jalan
  glPushMatrix();
  glTranslatef(0,0,30);
  glRotatef(90,0,1,0);
  markajalan();
  glPopMatrix();

  //trotroar depan benteng kiri
  glPushMatrix();
  glTranslatef(-20,0,13);
  glScalef(0.6f,0.5f,0.3f);
  trotoar();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(40,0,13);
  glScalef(0.2f,0.5f,0.3f);
  trotoar();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,0,47.5);
  glScalef(1.0f,0.5f,0.3f);
  trotoar();
  glPopMatrix();

  //pager belakang
  glPushMatrix();
  glTranslatef(-40,2,-50);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-20,2,-50);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,2,-50);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(40,2,-50);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20,2,-50);
  benteng();
  glPopMatrix();

  //pager depan
  glPushMatrix();
  glTranslatef(-40,2,10); 
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-20,2,10); 
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,2,10); 
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(40,2,10);
  benteng();
  glPopMatrix();

  //pager kiri
  glPushMatrix();
  glTranslatef(-50,2,-40);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-50,2,-20);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-50,2,0);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  //pager kanan
  glPushMatrix();
  glTranslatef(50,2,-40);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef(50,2,-20);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(50,2,0);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  //lampu
  glPushMatrix();
  glTranslatef(-47,0,-47);
  glScalef(0.7f,0.7f,0.7f);
  lampu();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(47,0,-47);
  glScalef(0.7f,0.7f,0.7f);
  lampu();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-47,0,13);
  glScalef(0.7f,0.7f,0.7f);
  lampu();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(47,0,13);
  glScalef(0.7f,0.7f,0.7f);
  lampu();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,2,-5);
  glScalef(1.0f,1.0f,1.0f);
  glRotatef(90,0,1,0);
  mobil();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-15,2,-5);
  glScalef(1.0f,1.0f,1.0f);
  glRotatef(90,0,1,0);
  mobil();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-30,2,-5);
  glScalef(1.0f,1.0f,1.0f);
  glRotatef(90,0,1,0);
  mobil();
  glPopMatrix();


  glutSwapBuffers();
}

//keyboard (telah dimodifikasi)
void keyboard(unsigned char key, int, int) {
    if (key == 'l' || key == 'L') lampOn = true;
    if (key == 'o' || key == 'O') lampOn = false;

    // KONTROL ORBIT KAMERA
    if (key == 'a' || key == 'A') { // Rotasi horizontal ke kiri
        cameraAngle_h += angle_step;
    }
    if (key == 'd' || key == 'D') { // Rotasi horizontal ke kanan
        cameraAngle_h -= angle_step;
    }
    if (key == 'w' || key == 'W') { // Rotasi vertikal ke atas (Elevasi)
        cameraAngle_v += angle_step;
        // Batasi sudut vertikal agar tidak terbalik (di antara 5.7 derajat dan 84.3 derajat)
        if (cameraAngle_v > M_PI / 2.0f - 0.1f) cameraAngle_v = M_PI / 2.0f - 0.1f;
    }
    if (key == 's' || key == 'S') { // Rotasi vertikal ke bawah (Depresi)
        cameraAngle_v -= angle_step;
        // Batasi sudut vertikal
        if (cameraAngle_v < 0.1f) cameraAngle_v = 0.1f;
    }
    if (key == '+' || key == '=') { // Zoom in (Perkecil radius)
        cameraRadius -= radius_step;
        if (cameraRadius < 10.0f) cameraRadius = 10.0f; // Batas minimum
    }
    if (key == '-') { // Zoom out (Perbesar radius)
        cameraRadius += radius_step;
    }

    glutPostRedisplay();
}


//anwar
// INISIALISASI OPENGL
void init() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  float lightPos[] = { 10, 10, 10, 1 };
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

//anwar
// RESHAPE
void reshape(int w, int h) {
  if (h == 0) h = 1;

  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (float)w / h, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
}

// anwar
// MAIN
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Project TB - Parkiran - kelompok 3");

  init();
  initQuadric();

  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);

  glutMainLoop();
  return 0;
}