#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

// Definisikan PI untuk perhitungan sudut
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// KAMERA (Posisi kamera akan dihitung)
float kameraX = 100.0f;
float kameraY = 200.0f;
float kameraZ = 100.0f;

// PARAMETER ORBIT KAMERA
float jarak_kamera = 100.0f; // Jarak kamera dari titik tengah (0,0,0)
float horizontal = 1;
float vertikal = 1;
float kecepatan_rotasi = 0.05f; // Kecepatan rotasi
float kecepatan_zoom = 5.0f; // Kecepatan zoom

// VARIABEL KONTROL MOBIL (Baru ditambahkan)
float mobilX = 80.0f;
float mobilY = 5.0f; 
float mobilZ = 75.0f;
float mobilRotasi = 90.0f; 
float kecepatan_mobil = 2.0f;
float kecepatan_belok = 5.0f;

// STATUS LAMPU
bool lampOn = true;

// Quadric untuk tabung & bola
GLUquadric* quad = nullptr;

// INISIALISASI QUADRIC
void initQuadric() {
  quad = gluNewQuadric();
  gluQuadricNormals(quad, GLU_SMOOTH);
}

//========2406017-Anwar Ibrahim========
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

//========2406017-Anwar Ibrahim========
//=======Lantai dasar Parkiran=========
void LantaiParkiran(){
  glPushMatrix();
  glColor3f(0.2,0.2,0.2);
  Kubus(0, -0.25f, 10, 0, 0, 0, 300.0f, 0.5f, 200.0f);
  glPopMatrix();
}

//========2406017-Anwar Ibrahim========
//===============panto===============
void panto(){
  //pintu
  glPushMatrix();
  glColor3f(1,1,1);
  Kubus(-5,5,0,0,0,0,10,20,1);
  Kubus(5.2,5,0,0,0,0,10,20,1);
  glPopMatrix();

  //gagang pintu
  glPushMatrix();
  glColor3f(1,1,0);
  Kubus(-0.6,5,1,0,0,0,1,5,0.5);
  Kubus(0.62,5,1,0,0,0,1,5,0.5);

  glPopMatrix();
}

//======2406025-M.Saepul hidayat=======
//===============jendela===============
  void jendela(){
    glPushMatrix();
    glColor3f(1,1,1);
    Kubus(0,10,0,0,0,0,20,10,0.5);
    glPopMatrix();
    
    glPushMatrix(); //garis tengah
    glColor3f(0,0,0);
    Kubus(0,10,0,0,0,0,20,0.5,1);
    glPopMatrix();

    glPushMatrix(); //garis tengah
    glColor3f(0,0,0);
    Kubus(0,10,0,0,0,90,10,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas atas
    glColor3f(0.8,0.8,60);
    Kubus(-4,13,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas bawah
    glColor3f(0.8,0.8,60);
    Kubus(-6,12.5,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas atas
    glColor3f(0.8,0.8,60);
    Kubus(6,13,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas bawah
    glColor3f(0.8,0.8,60);
    Kubus(4,12.5,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas atas
    glColor3f(0.8,0.8,60);
    Kubus(6,7.5,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas bawah
    glColor3f(0.8,0.8,60);
    Kubus(4,6.75,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas atas
    glColor3f(0.8,0.8,60);
    Kubus(-4,7.5,0,0,0,45,2,0.5,1);
    glPopMatrix();

    glPushMatrix(); //kanan atas bawah
    glColor3f(0.8,0.8,60);
    Kubus(-6,6.75,0,0,0,45,2,0.5,1);
    glPopMatrix();

  }

//========2406017-Anwar Ibrahim========
//===============logo ITG==============
void itg(){
  glPushMatrix();
  glScalef(1,1,0.1);
  glColor3f(1,1,1);
  Bola(0,0,0,5);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0,0,0);

  //I
  Kubus(-3,0,1,0,0,0,0.5,3,0.5);
  //T
  Kubus(-1,0,1,0,0,0,0.5,3,0.5);
  Kubus(-1,1.3,1,0,0,90,0.5,2.8,0.5);
  //G
  Kubus(1,0,1,0,0,0,0.5,3,0.5);
  Kubus(3,-0.5,1,0,0,0,0.5,1.5,0.5);
  Kubus(2.2,1.3,1,0,0,90,0.5,2,0.5);
  Kubus(2.2,-1.3,1,0,0,90,0.5,2,0.5);
  Kubus(2.5,0,1,0,0,90,0.5,1,0.5);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0,0,0);
  Tabung(0,0,0,0,0,0,5,5,1,32);
  glPopMatrix();
}

//========2406017-Anwar Ibrahim========
//===============bangunan==============
void bangunan(){
  glPushMatrix();
  glColor3f(1,2,3);
  Kubus(40,0,0,0,0,0,180,40,40); //lantai 1
  Kubus(110,0,40,0,0,0,40,40,40);
  Kubus(-111,20,30,0,0,0,122,80,100);
  Kubus(60,30,0,0,0,0,140,30,40); //lantai 2
  Kubus(-30,44,0,0,0,0,40,2,40); //atap lantai 2 kantin
  Kubus(-30,30,-20,0,0,0,40,30,2); //tutup belakang kantin
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.7,0.7,0.7);
  Kubus(-30,-18,50,0,0,0,40,5,60); //lantai deket kaca
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.2,1.2,1.2);
  Kubus(-50,5,50,0,0,0,2,30,50); //kaca
  glPopMatrix();

  glPushMatrix();
  glColor3f(1,1,1);
  Kubus(20,19,21,0,0,0,140,2,4); //palang lantai 1
  Kubus(20,9,21,0,0,0,140,2,4);

  Kubus(88,19,43,0,90,0,40,2,4);
  Kubus(88,9,43,0,90,0,40,2,4);

  Kubus(110,19,61,0,0,0,40,2,4);
  Kubus(110,9,61,0,0,0,40,2,4);

  Kubus(40,43,21,0,0,0,180,2,4); //palang lantai 2
  glPopMatrix();

  //jendela
  glPushMatrix();// jendela lantai 1 bangunan kanan
  glTranslatef(70,-15,21);
  jendela();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10,-15,21);
  jendela();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(40,-15,21);
  jendela();
  glPopMatrix();

  glPushMatrix(); // jendela lantai 2 bangunan kanan
  glTranslatef(70,22,21);
  jendela();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10,22,21);
  jendela();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(40,22,21);
  jendela();
  glPopMatrix();

  glPushMatrix(); //jendela lantai 2 bangunan kiri
  glTranslatef(-80,30,80);
  jendela();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-110,30,80);
  jendela();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-140,30,80);
  jendela();
  glPopMatrix();

  //panto 
  glPushMatrix(); // panto depan bangunan
  glTranslatef(110,-15,60);
  panto();
  glPopMatrix();

  glPushMatrix(); // panto kantin
  glTranslatef(-50,25,0);
  glRotatef(90,0,1,0);
  panto();
  glPopMatrix();

  glPushMatrix(); // logo ITG
  glTranslatef(110,15,63);
  itg();
  glPopMatrix();

  //parkiran atas
  glPushMatrix();
  glColor3f(1,1,1);
  Kubus(-110,20,125,0,0,0,120,5,90); //lantai parkiran atas
  Kubus(-110,58,125,0,0,0,120,5,90); //atap parkiran atas
  Kubus(-168,27,125,0,0,0,5,10,90); //pagar kiri
  Kubus(-53,27,100,0,0,0,5,10,60); //pagar kanan
  Kubus(-110,27,167.5,0,0,0,120,10,5); //pagar depan
  Kubus(-165,20.5,165,0,0,0,10,80,10); //tihang penyangga kiri
  Kubus(-55,20.5,165,0,0,0,10,80,10); //tihang penyangga kanan
  Kubus(-18,-2,145,0,0,-35,80,2,30); //tanjakan parkiran
  glPopMatrix();
}

//======2406025-M.Saepul hidayat=======
//===============Benteng===============
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

//=========2406017-Anwar ibrahim=========
//===========kumpulan benteng============
void kumpulan_benteng(){
    //benteng kiri
  glPushMatrix();
  glTranslatef(-149,6,20);
  glScalef(3.0f,3.0f,3.0f);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-149,6,80);
  glScalef(3.0f,3.0f,3.0f);
  glRotatef(90,0,1,0);
  benteng();
  glPopMatrix();

  //benteng tengah
  glPushMatrix();
  glTranslatef(-120,6,109);
  glScalef(3.0f,3.0f,3.0f);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-60,6,109);
  glScalef(3.0f,3.0f,3.0f);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,6,109);
  glScalef(3.0f,3.0f,3.0f);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(60,6,109);
  glScalef(3.0f,3.0f,3.0f);
  benteng();
  glPopMatrix();

  //benteng kanan
  glPushMatrix();
  glTranslatef(149,6,20);
  glScalef(3.0f,3.0f,3.0f);
  glRotatef(-90,0,1,0);
  benteng();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(149,6,80);
  glScalef(3.0f,3.0f,3.0f);
  glRotatef(-90,0,1,0);
  benteng();
  glPopMatrix();
}

//=========2406017-Anwar ibrahim=========
//==============Roda mobil===============
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

//=========2406017-Anwar ibrahim=========
//================mobil==================
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

//=========2406006-Rahmat Apandi=========
//================Bohlam=================
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

void lampu() {
  glColor3f(0.8f, 0.8f, 0.8f);

  Tabung(0, 15, 0, 90, 0, 0, 0.5f, 0.5f, 15.0f, 32);
  Tabung(0, 15, 0, 90, 0, 0, 2.0f, 0.5f, 2.0f, 32);
  Tabung(0, 5, 0, 90, 0, 0, 0.5f, 2.0f, 5.0f, 32);

  Kubus(0, 0, 0, 0, 0, 0, 6, 1, 6);
  Kubus(0, 1, 0, 0, 0, 0, 2.4f, 3, 2.4f);

  bohlam();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  gluLookAt(
      kameraX, kameraY, kameraZ,
      0, 0, 0,
      0, 1, 0
  );

  //lantai dasar parkiran
  glPushMatrix();
  LantaiParkiran();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20,20,-70);
  bangunan();
  glPopMatrix();

  glPushMatrix();
  kumpulan_benteng();
  glPopMatrix();

  // MOBIL
  glPushMatrix();
  glTranslatef(mobilX, mobilY, mobilZ);
  glRotatef(mobilRotasi, 0, 1, 0);
  glScalef(2.5f, 2.5f, 2.5f);
  mobil();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(80,5,-15);
  glRotatef(-90,0,1,0);
  glScalef(2.5f,2.5f,2.5f);
  mobil();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(50,5,-15);
  glRotatef(-90,0,1,0);
  glScalef(2.5f,2.5f,2.5f);
  mobil();
  glPopMatrix();


//
  glPushMatrix();
  glTranslatef(-123,0,105);
  lampu();  
  glPopMatrix();

  // 
  glPushMatrix();
  glTranslatef(-123,0,13);
  lampu();  
  glPopMatrix();
  //
  glPushMatrix(); 
  glTranslatef(93,0,107);
  lampu();
  glPopMatrix();

  glPushMatrix(); 
  glTranslatef(144,0,107);
  lampu();
  glPopMatrix();

  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    float radian = mobilRotasi * M_PI / 180.0f;
    float nextX = mobilX;
    float nextZ = mobilZ;

    if (key == 27) { // 27 = ASCII ESC
          exit(0);
    }

    // --- KONTROL MOBIL (WASD) ---
    if (key == 'w' || key == 'W') { 
        mobilX -= cos(radian) * kecepatan_mobil;
        mobilZ += sin(radian) * kecepatan_mobil;
    }
    if (key == 's' || key == 'S') { 
        mobilX += cos(radian) * kecepatan_mobil;
        mobilZ -= sin(radian) * kecepatan_mobil;
    }
    if (key == 'a' || key == 'A') { // Belok Kiri
        mobilRotasi += kecepatan_belok;
    }
    if (key == 'd' || key == 'D') { // Belok Kanan
        mobilRotasi -= kecepatan_belok;
    }

    // --- POSISI KAMERA (1, 2, 3, 4) ---
    if (key == '1') { // depan
        kameraX = 0.5f; kameraY = 200.0f; kameraZ = 250.0f;
    }
    if (key == '2') { // samping
        kameraX = 250.0f; kameraY = 200.0f; kameraZ = 0.5f;
    }
    if (key == '3') { // atas
        kameraX = 0.001f; kameraY = 400.0f; kameraZ = 1.0f;
    }

    //saklar lampu
    if (key == 'c') {
        lampOn = !lampOn; // toggle
    }

    // // ZOOM KAMERA (+/-)
    // if (key == '+' || key == '=') {
    //     jarak_kamera -= kecepatan_zoom;
    //     if (jarak_kamera < 10.0f) jarak_kamera = 10.0f;
    // }
    // if (key == '-') {
    //     jarak_kamera += kecepatan_zoom;
    // }
    glutPostRedisplay();
}


//anwar
// INISIALISASI OPENGL
void init() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Latar Belakang

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
  gluPerspective(60, (float)w / h, 1, 1000); //Jarak Pandang sejauh mana dan sedekat apa sebuah onjek dapat terlihat
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