#include <GL/glut.h>

float cubePosX = 0.0f;
float cubePosY = 0.0f;
float cubePosZ = 0.0f;
float cubeRotationX = 0.0f;
float cubeRotationY = 0.0f;
float cubeRotationZ = 0.0f;
float cubeScale = 1.0f;
bool mirrorX = false;
bool mirrorY = false;
bool mirrorZ = false;

float cameraX = 2.0f;
float cameraY = 3.0f;
float cameraZ = 8.0f;
float lookAtX = 0.0f;
float lookAtY = 0.0f;
float lookAtZ = 0.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, lookAtX, lookAtY, lookAtZ, 0.0, 1.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-100.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -100.0, 0.0);
    glVertex3f(0.0, 100.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glEnd();

    glPushMatrix();

    ///////
    glTranslatef(cubePosX, cubePosY, cubePosZ);
    glRotatef(cubeRotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(cubeRotationY, 0.0f, 1.0f, 0.0f);
    glRotatef(cubeRotationZ, 0.0f, 0.0f, 1.0f);
    glScalef(cubeScale, cubeScale, cubeScale);
     // Melakukan mirror terhadap sumbu X dan memindahkan ke sisi lain sumbu X
    if (mirrorX) {
        glTranslatef(-2.0f * cubePosX, 0.0f, 0.0f);
        glScalef(-1.0f, 1.0f, 1.0f);
    }
    // Melakukan mirror terhadap sumbu Y dan memindahkan ke sisi lain sumbu Y
    if (mirrorY) {
        glTranslatef(0.0f, -2.0f * cubePosY, 0.0f);
        glScalef(1.0f, -1.0f, 1.0f);
    }
    // Melakukan mirror terhadap sumbu Z dan memindahkan ke sisi lain sumbu Z
    if (mirrorZ) {
        glTranslatef(0.0f, 0.0f, -2.0f * cubePosZ);
        glScalef(1.0f, 1.0f, -1.0f);
    }
    // Menggambar kubus
    glBegin(GL_QUADS);
    // Sisi depan
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    // Sisi belakang
    glColor3f(0.0, 1.0, 0.0); // Warna hijau
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    // Sisi atas
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    // Sisi bawah
    glColor3f(1.0, 1.0, 0.0); // Warna kuning
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    // Sisi kiri
    glColor3f(1.0, 0.0, 1.0); // Warna ungu
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    // Sisi kanan
    glColor3f(0.0, 1.0, 1.0); // Warna cyan
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void onKeyDown(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            cubePosX -= 0.1f;
            break;
        case 'd':
            cubePosX += 0.1f;
            break;
        case 'w':
            cubePosY += 0.1f;
            break;
        case 's':
            cubePosY -= 0.1f;
            break;
        case 'q':
            cubePosZ += 0.1f;
            break;
        case 'e':
            cubePosZ -= 0.1f;
            break;
        case 'u':
            cubeRotationY += 5.0f;
            break;
        case 'j':
            cubeRotationY -= 5.0f;
            break;
        case 'i':
            cubeRotationX += 5.0f;
            break;
        case 'k':
            cubeRotationX -= 5.0f;
            break;
        case 'o':
            cubeRotationZ += 5.0f;
            break;
        case 'l':
            cubeRotationZ -= 5.0f;
            break;
        case '+':
            cubeScale += 0.1f; // Menambah skala kubus
            break;
        case '-':
            if (cubeScale > 0.1f) { // Mengurangi skala kubus (dengan batasan minimum)
                cubeScale -= 0.1f;
            }
            break;
        case 'x':
            mirrorX = !mirrorX; // Toggle mirror terhadap sumbu X
            break;
        case 'y':
            mirrorY = !mirrorY; // Toggle mirror terhadap sumbu Y
            break;
        case 'z':
            mirrorZ = !mirrorZ; // Toggle mirror terhadap sumbu Z
            break;
        case 'r':
            cameraX += 0.1f; // Menggerakkan kamera ke atas
            break;
        case 't':
            cameraX -= 0.1f; // Menggerakkan kamera ke bawah
            break;
        case 'f':
            cameraY -= 0.1f; // Menggerakkan kamera ke kiri
            break;
        case 'g':
            cameraY += 0.1f; // Menggerakkan kamera ke kanan
            break;
        case 'v':
            cameraZ -= 0.1f; // Menggerakkan kamera ke depan
            break;
        case 'b':
            cameraZ += 0.1f; // Menggerakkan kamera ke belakang
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Moving and Rotating Cube");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(onKeyDown);

    init();
    glutMainLoop();
    return 0;
}
