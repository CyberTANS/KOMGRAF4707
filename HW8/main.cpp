#include <iostream>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Fungsi untuk menghitung kode (outcode) dari titik (x, y)
int computeCode(float x, float y, float xmin, float ymin, float xmax, float ymax) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Fungsi untuk menentukan titik potong antara dua garis pada window yang diberikan
void cohenSutherlandClip(float xmin, float ymin, float xmax, float ymax, float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            float x = 0, y = 0;
            int outcode = (code1 != 0) ? code1 : code2;

            // Hitung titik potong
            if (outcode & LEFT) {
                x = xmin;
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            } else if (outcode & RIGHT) {
                x = xmax;
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            } else if (outcode & BOTTOM) {
                y = ymin;
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            } else if (outcode & TOP) {
                y = ymax;
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            }

            if (outcode == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        cout << "Garis dipotong pada titik (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")" << endl;
    } else {
        cout << "Garis sepenuhnya di luar window" << endl;
    }
}

int main() {
    // Koordinat window
    float xmin = 1.0, ymin = 1.0, xmax = 4.0, ymax = 5.0;

    // Koordinat garis P dan Q
    float x1_P = -1.0, y1_P = -2.0, x2_P = 5.0, y2_P = 6.0;
    float x1_Q = -1.0, y1_Q = 5.0, x2_Q = 6.0, y2_Q = 7.0;

    // Menemukan titik potong untuk garis P
    cohenSutherlandClip(xmin, ymin, xmax, ymax, x1_P, y1_P, x2_P, y2_P);

    // Menemukan titik potong untuk garis Q
    cohenSutherlandClip(xmin, ymin, xmax, ymax, x1_Q, y1_Q, x2_Q, y2_Q);

    return 0;
}
