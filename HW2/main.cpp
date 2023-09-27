#include <iostream>
using namespace std;

void inputMatriks(int matriks[2][2]) {
    cout << "Masukkan nilai matriks:" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cout << "Baris " << i+1 << ", Kolom " << j+1 << ": ";
            cin >> matriks[i][j];
        }
    }
}
void tambahMatriks(int A[2][2], int B[2][2], int hasil[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}
void kurangMatriks(int A[2][2], int B[2][2], int hasil[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}
void kaliSkalar(int matriks[2][2], int skalar, int hasil[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            hasil[i][j] = matriks[i][j] * skalar;
        }
    }
}
void kaliMatriks(int A[2][2], int B[2][2], int hasil[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            hasil[i][j] = 0;
            for (int k = 0; k < 2; k++){
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriksA[2][2];
    int matriksB[2][2];
    int hasil[2][2];
    int pilihan;
    inputMatriks(matriksA);
    inputMatriks(matriksB);
        cout << "\n========================"<< endl;
        cout << "Matriks A : " << endl;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                cout << matriksA[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Matriks B : " << endl;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                cout << matriksB[i][j] << " ";
            }
            cout << endl;
        }
    do{
        cout << "\n========================"<< endl;
        cout << "\nMenu Operasi Matriks:" << endl;
        cout << "1. Penjumlahan Matriks" << endl;
        cout << "2. Pengurangan Matriks" << endl;
        cout << "3. Perkalian Skalar" << endl;
        cout << "4. Perkalian Matriks" << endl;
        cout << "5. Keluar" << endl;
        cout << "\nPilih operasi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Penjumlahan Matriks A dan B: \n" << endl;
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Pengurangan Matriks A dan B: \n" << endl;
                break;
            case 3:
                int skalar;
                cout << "Masukkan skalar: ";
                cin >> skalar;

                char matriksPilihan;
                cout << "Pilih matriks yang akan dikalikan skalar (A/B): ";
                cin >> matriksPilihan;

                if (matriksPilihan == 'A' || matriksPilihan == 'a') {
                    kaliSkalar(matriksA, skalar, hasil);
                    cout << "\nHasil Perkalian Skalar Matriks A dengan " << skalar << ":\n" << endl;
                } else if (matriksPilihan == 'B' || matriksPilihan == 'b') {
                    kaliSkalar(matriksB, skalar, hasil);
                    cout << "\nHasil Perkalian Skalar Matriks B dengan " << skalar << ":\n" << endl;
                } else {
                    cout << "\nPilihan matriks tidak valid." << endl;
                }
                break;
            case 4:
                kaliMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Perkalian Matriks A dan B: \n" << endl;
                break;
            case 5:
                cout << "\nTerima kasih! Program berakhir." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan pilih kembali." << endl;
                break;
        }

        if (pilihan != 5) {
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    cout << hasil[i][j] << " ";
                }
                cout << endl;
            }
        }
    } while (pilihan != 5);

    return 0;
}
