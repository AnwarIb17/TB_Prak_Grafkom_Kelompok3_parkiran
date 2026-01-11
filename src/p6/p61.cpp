#include <gl/glut.h>

struct Vector
{
  float x, y, z;
  Vector(float x, float y, float z) : x(x), y(y), z(z) {}
};
GLfloat light_position[4] = {0.0, 1.5, 0.0, 1.0};
class Cube
{
  private:
    GLfloat angleY = 0.0;
    Vector *pos;

  public:
    Cube(Vector &position): pos(&position){}

    void onTick()
    {
      glPushMatrix();
      glTranslatef(pos->x, pos->y, pos->z);
      glRotatef(angleY, 1.0, 1.0, 1.0);
      glBegin(GL_QUADS);

      //mukaDepan
      glNormal3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 1.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);
    
      //muka belakang
      glNormal3f(0.0f, 0.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(1.0f, 1.0f, -1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

      //muka atas
      glNormal3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, -1.0f);
      
      //Muka Bawah
      glNormal3f(0.0f, -1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);

      //Muka kanan
      glNormal3f(1.0f, 0.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glVertex3f(1.0f, 1.0f, -1.0f);
      glVertex3f(1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      //Muka Kiri
      glNormal3f(-1.0f, 0.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glEnd();

      glPopMatrix();
    }
};

Cube *object;

void idle()
{
  object->onTick();
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glDisable(GL_LIGHTING);
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(light_position[0], light_position[1], light_position[2]);
  glEnd();

  glColor3f(1.0, 1.0, 1.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex3f(light_position[0], light_position[1], light_position[2]);
  glEnd();
  glEnable(GL_LIGHTING);

  object ->onTick();
    glutSwapBuffers();
    glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 'w':
      light_position[2]-=0.1;
      break;
    case 's':
      light_position[2] += 0.1;
      break;
    case 'd':
      light_position[0] += 0.1;
      break;
    case'a':
      light_position[0] -= 0.1;
      break;
    case 'r':
      light_position[0] = 0.0;
      light_position[2] = 0.0;
      break;
  }
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void inisialisasi()
{
  //pencahayaan
  GLfloat light_diffuse[4] = {1.0, 1.0, 1.0, 1.0};
  GLfloat light_ambient[4] = {0.0, 0.0, 0.0, 1.0};
  GLfloat light_specular[4] = {1.0, 1.0, 1.0, 1.0};
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);

  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0, 1.0, 1.0, 50.0);
  gluLookAt(0.0, 4.0, 6.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.1, 0.1, 0.1, 1.0);
  object = new Cube (*new Vector(0.0, 0.0, 0.0));
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE |GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(50, 0);
  glutCreateWindow("2406017 - Anwar Ibrahim");
  glutDisplayFunc(display);
  glutKeyboardFunc(myKeyboard);
  glutIdleFunc(idle);
  inisialisasi();
  glutMainLoop();
  return 0;
}