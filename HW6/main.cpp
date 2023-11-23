#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan translasi titik (x, y) dengan vektor translasi (tx, ty)
vector<double> translasiTitik(double x, double y, double tx, double ty) {
    // Matrix transformasi 3x3 untuk translasi
    vector<vector<double>> transformMatrix = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };

    // Titik awal (x, y, 1)
    vector<double> point = {x, y, 1};

    // Hasil perkalian matriks untuk translasi
    vector<double> hasil(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            hasil[i] += transformMatrix[i][j] * point[j];
        }
    }

    return hasil;
}

int main() {
    double x = 1.0;
    double y = 3.0;
    double tx = 5.0; // translasi x
    double ty = 5.0; // translasi y

    vector<double> hasil = translasiTitik(x, y, tx, ty);

    cout << "Titik awal: (" << x << ", " << y << ")" << endl;
    cout << "Setelah translasi: (" << hasil[0] << ", " << hasil[1] << ")" << endl;

    return 0;
}
