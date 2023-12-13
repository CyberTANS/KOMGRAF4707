#include <GL/glut.h>
#include <math.h>

// Titik A dan B
float pointA[3] = {1.0f, 3.0f, 1.0f}; // Titik A (x, y, w)
float pointB[3] = {3.0f, 2.0f, 1.0f}; // Titik B (x, y, w)

// Fungsi untuk menggambar garis
void drawLine(float* point1, float* point2) {
    glBegin(GL_LINES);
    glVertex2f(point1[0], point1[1]);
    glVertex2f(point2[0], point2[1]);
    glEnd();
}

// Fungsi untuk melakukan translasi garis
void translateLine(float* pointA, float* pointB, float tx, float ty) {
    // Matriks transformasi translasi
    float translationMatrix[3][3] = {
        {1.0f, 0.0f, tx},
        {0.0f, 1.0f, ty},
        {0.0f, 0.0f, 1.0f}
    };

    // Melakukan translasi terhadap titik A dan B
    float newPointA[3], newPointB[3];
    for (int i = 0; i < 3; ++i) {
        newPointA[i] = 0;
        newPointB[i] = 0;
        for (int j = 0; j < 3; ++j) {
            newPointA[i] += translationMatrix[i][j] * pointA[j];
            newPointB[i] += translationMatrix[i][j] * pointB[j];
        }
    }

    // Menggambar garis awal sebelum translasi
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk garis awal
    drawLine(pointA, pointB);

    // Menggambar garis setelah translasi
    glColor3f(0.0f, 0.0f, 1.0f); // Warna hijau untuk garis setelah translasi
    drawLine(newPointA, newPointB);
}

// Fungsi untuk melakukan scaling terhadap garis
void scaleLine(float* pointA, float* pointB, float sx, float sy) {
    // Matriks transformasi scaling
    float scalingMatrix[3][3] = {
        {sx, 0.0f, 0.0f},
        {0.0f, sy, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    // Melakukan scaling terhadap titik A dan B
    float newPointA[3], newPointB[3];
    for (int i = 0; i < 3; ++i) {
        newPointA[i] = 0;
        newPointB[i] = 0;
        for (int j = 0; j < 3; ++j) {
            newPointA[i] += scalingMatrix[i][j] * pointA[j];
            newPointB[i] += scalingMatrix[i][j] * pointB[j];
        }
    }

    // Menggambar garis awal sebelum scaling
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk garis awal
    drawLine(pointA, pointB);

    // Menggambar garis setelah scaling
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru untuk garis setelah scaling
    drawLine(newPointA, newPointB);
}

// Fungsi untuk melakukan rotasi terhadap garis
void rotateLine(float* pointA, float* pointB, float angle) {
    // Mengonversi sudut ke radian
    float theta = angle * 3.14159 / 180.0;
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    // Matriks transformasi rotasi
    float rotationMatrix[3][3] = {
        {cosTheta, -sinTheta, 0.0f},
        {sinTheta, cosTheta, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    // Melakukan rotasi terhadap titik A dan B
    float newPointA[3], newPointB[3];
    for (int i = 0; i < 3; ++i) {
        newPointA[i] = 0;
        newPointB[i] = 0;
        for (int j = 0; j < 3; ++j) {
            newPointA[i] += rotationMatrix[i][j] * pointA[j];
            newPointB[i] += rotationMatrix[i][j] * pointB[j];
        }
    }

    // Menggambar garis awal sebelum rotasi
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk garis awal
    drawLine(pointA, pointB);

    // Menggambar garis setelah rotasi
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru untuk garis setelah rotasi
    drawLine(newPointA, newPointB);
}

// Fungsi untuk melakukan mirror (refleksi) terhadap sumbu x
void mirrorXLine(float* pointA, float* pointB) {
    // Matriks transformasi mirror (refleksi) sumbu x
    float mirrorMatrix[3][3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, -1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    // Melakukan mirror (refleksi) terhadap titik A dan B
    float newPointA[3], newPointB[3];
    for (int i = 0; i < 3; ++i) {
        newPointA[i] = 0;
        newPointB[i] = 0;
        for (int j = 0; j < 3; ++j) {
            newPointA[i] += mirrorMatrix[i][j] * pointA[j];
            newPointB[i] += mirrorMatrix[i][j] * pointB[j];
        }
    }

    // Menggambar garis awal sebelum mirror (refleksi)
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk garis awal
    drawLine(pointA, pointB);

    // Menggambar garis setelah mirror (refleksi)
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru untuk garis setelah mirror (refleksi)
    drawLine(newPointA, newPointB);
}

// Fungsi untuk melakukan transformasi komposit dalam satu perhitungan matriks
void compositeTransform(float* pointA, float* pointB, float tx, float ty, float sx, float sy, float angle) {
    // Mengonversi sudut rotasi ke radian
    float theta = angle * 3.14159 / 180.0;
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    // Matriks transformasi komposit
    float compositeMatrix[3][3] = {
        {cosTheta * sx, -sinTheta * sy, tx},
        {sinTheta * sx, cosTheta * sy, ty},
        {0.0f, 0.0f, 1.0f}
    };

    // Melakukan transformasi komposit terhadap titik A dan B
    float newPointA[3], newPointB[3];
    for (int i = 0; i < 3; ++i) {
        newPointA[i] = 0;
        newPointB[i] = 0;
        for (int j = 0; j < 3; ++j) {
            newPointA[i] += compositeMatrix[i][j] * pointA[j];
            newPointB[i] += compositeMatrix[i][j] * pointB[j];
        }
    }

    // Menggambar garis awal sebelum transformasi komposit
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk garis awal
    drawLine(pointA, pointB);

    // Menggambar garis setelah transformasi komposit
    glColor3f(0.0f, 1.0f, 1.0f); // Warna biru untuk garis setelah transformasi komposit
    drawLine(newPointA, newPointB);
}

// Fungsi untuk mengatur tampilan
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Panggil fungsi untuk melakukan translasi garis
    translateLine(pointA, pointB, 3.0f, 0.0f);

    // Panggil fungsi untuk melakukan scaling garis
    scaleLine(pointA, pointB, 2.0f, 2.0f);

    // Panggil fungsi untuk melakukan rotasi garis
    rotateLine(pointA, pointB, 45.0f); // Sudut rotasi 45 derajat

    // Panggil fungsi untuk melakukan mirror (refleksi) terhadap sumbu x
    mirrorXLine(pointA, pointB);

    // Translasi, scaling, rotasi, refleksi
    compositeTransform(pointA, pointB, 2.0f, 1.0f, 2.0f, 2.0f, 45.0f);

    glFlush();
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Translasi Garis menggunakan GLUT");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
