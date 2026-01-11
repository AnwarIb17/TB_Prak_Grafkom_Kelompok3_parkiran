#include <GL/glew.h> 
#include <GL/glut.h> 
#include <FreeImage.h> 
#include <stdio.h> 
using namespace std; 
 
// Menyimpan ID texture 
GLuint texture_Earth_ID; 
// GLuint texture_bulan_ID; // dapat ditambah sendiri 
 
// Fungsi Quadric untuk membuat object Sphere dengan UV mapping texture 
void createObject() { 
    GLUquadric* object = gluNewQuadric(); 
    gluQuadricTexture(object, GL_TRUE); 
    gluQuadricNormals(object, GLU_SMOOTH); 
    gluSphere(object, 5, 100, 100); 
} 
 
float tick = 0.0; 
 
// Render Scene 
void display() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 
    glPushMatrix(); 
    glRotatef(-90, 1.0, 0.0, 0.0); 
    glRotatef(tick += 0.01, 0.0, 0.0, 1.0); 
 
    // Bind texture ke object 
    glBindTexture(GL_TEXTURE_2D, texture_Earth_ID); 
    createObject(); 
 
    glPopMatrix(); 
    glutSwapBuffers(); 
    glutPostRedisplay(); 
} 
 
// Variabel global untuk ID texture loader 
GLuint textureID = 0; 
 
// Fungsi untuk memuat texture 
int loadTexture(const char* path) { 
    glGenTextures(1, &textureID); 
 
    void* imgData; 
    int imgWidth, imgHeight; 
 
    FREE_IMAGE_FORMAT format = FreeImage_GetFIFFromFilename(path); 
    if (format == FIF_UNKNOWN) { 
        printf("Unknown file type for texture image file %s\n", path); 
        return -1; 
    } 
 
    FIBITMAP* bitmap = FreeImage_Load(format, path, 0); 
    if (!bitmap) { 
        printf("Failed to load image %s\n", path); 
        return -1; 
    } 
 
    FIBITMAP* bitmap2 = FreeImage_ConvertTo24Bits(bitmap); 
    FreeImage_Unload(bitmap); 
 
    imgData = FreeImage_GetBits(bitmap2); 
    imgWidth = FreeImage_GetWidth(bitmap2); 
    imgHeight = FreeImage_GetHeight(bitmap2); 
 
    if (imgData) { 
        printf("Texture image loaded from file %s, size %dx%d\n", 
            path, imgWidth, imgHeight); 
 
        int formatColor = (FI_RGBA_RED == 0) ? GL_RGB : GL_BGR; 
 
        glBindTexture(GL_TEXTURE_2D, textureID); 
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, 
                     formatColor, GL_UNSIGNED_BYTE, imgData); 
 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
 
        textureID++; 
        return textureID - 1; 
    } 
    else { 
        printf("Failed to get texture data from %s\n", path); 
    } 
 
    return -1; 
} 
 
// Setup kamera & projection 
void initProjection() { 
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_POLYGON_SMOOTH); 
    glShadeModel(GL_SMOOTH); 
 
    // Enable texture 
    glEnable(GL_TEXTURE_2D); 
 
    // Texture matrix mode 
    glMatrixMode(GL_TEXTURE); 
 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
 
    gluPerspective(45.0, 1800.0 / 900.0, 1.0, 100.0); 
    gluLookAt(10.0, 10.0, 10.0, 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0); 
 
    glMatrixMode(GL_MODELVIEW); 
 
    // Load textures 
    texture_Earth_ID = loadTexture("C:/AnwarCPP/src/p10/textures/bumi.png"); 
    // texture_bulan_ID = loadTexture("textures/bulan.png"); 
} 
 
// Main Program 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glewInit(); 
 
    // Catatan: RGBA karena texture membutuhkan Alpha saat render 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
    glutInitWindowSize(1800, 900); 
    glutInitWindowPosition(100, -50); 
    glutCreateWindow("Texture"); 
 
    initProjection(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
 
    return 0; 
}