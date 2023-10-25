#include <GL/glut.h>
#include <math.h>

float xstart = 10.0, ystart = 20.0, xend = 30.0, yend = 30.0;
float tx = 20.0, ty = 0.0;
float angle = 45.0; // Sudut rotasi dalam derajat
float sx = 1.5, sy = 1.5; // Faktor scaling

void drawLine(float xstart, float ystart, float xend, float yend, float r, float g, float b) {
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    glVertex2f(xstart, ystart);
    glVertex2f(xend, yend);
    glEnd();
}

void translateLine(float& xstart, float& ystart, float& xend, float& yend, float tx, float ty) {
    xstart += tx;
    ystart += ty;
    xend += tx;
    yend += ty;
}

void rotateLine(float& xstart, float& ystart, float& xend, float& yend, float angle) {
    float radians = angle * (M_PI / 180.0);
    float temp_xstart = xstart, temp_ystart = ystart;
    xstart = temp_xstart * cos(radians) - temp_ystart * sin(radians);
    ystart = temp_xstart * sin(radians) + temp_ystart * cos(radians);
    float temp_xend = xend, temp_yend = yend;
    xend = temp_xend * cos(radians) - temp_yend * sin(radians);
    yend = temp_xend * sin(radians) + temp_yend * cos(radians);
}

void scaleLine(float& xstart, float& ystart, float& xend, float& yend, float sx, float sy) {
    xstart *= sx;
    ystart *= sy;
    xend *= sx;
    yend *= sy;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar garis awal (hitam)
    drawLine(xstart, ystart, xend, yend, 0.0, 0.0, 0.0);

    // Translasi garis
    translateLine(xstart, ystart, xend, yend, tx, ty);

    // Gambar garis setelah translasi (hitam)
    drawLine(xstart, ystart, xend, yend, 1.0, 0.0, 0.0);

    glFlush();
}

void displayRotation() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar garis awal (hitam)
    drawLine(xstart, ystart, xend, yend, 0.0, 0.0, 0.0);

    // Rotasi garis
    rotateLine(xstart, ystart, xend, yend, angle);

    // Gambar garis setelah rotasi (merah)
    drawLine(xstart, ystart, xend, yend, 1.0, 0.0, 0.0);

    glFlush();
}

void displayScaling() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar garis awal (hitam)
    drawLine(xstart, ystart, xend, yend, 0.0, 0.0, 0.0);

    // Scaling garis
    scaleLine(xstart, ystart, xend, yend, sx, sy);

    // Gambar garis setelah scaling (hijau)
    drawLine(xstart, ystart, xend, yend, 0.0, 1.0, 0.0);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Translasi Garis");
    init();
    glutDisplayFunc(display);

    glutCreateWindow("Rotasi Garis");
    init();
    glutDisplayFunc(displayRotation);

    glutCreateWindow("Scaling Garis");
    init();
    glutDisplayFunc(displayScaling);

    glutMainLoop();
    return 0;
}
