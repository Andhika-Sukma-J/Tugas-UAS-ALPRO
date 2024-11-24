#include <iostream>
#include <cmath>

using namespace std;

struct Perhitungan {
    int *bil;          // Pointer untuk menyimpan array bilangan (ubah ke int)
    int JmlBil;        // Jumlah bilangan
    int bilangan1;     // Bilangan untuk faktorial atau basis pangkat
};

void printMenu() {
     cout<< "---------------------------------------------"<<endl;
    cout<< "|             Anggota Kelompok 8            |"<<endl;
    cout<< "---------------------------------------------"<<endl;
    cout<< "| No  |           Nama Anggota              |"<<endl;
    cout<< "---------------------------------------------"<<endl;
    cout<< "|  1  |       Andhika Eka Pratama           |"<<endl;
    cout<< "|  2  |       Andhika Sukma Jiwatama        |"<<endl;
    cout<< "|  3  |       Muhammad Ghifari Gilbran      |"<<endl;
    cout<< "---------------------------------------------"<<endl;
    cout << endl;



    cout<< "---------------------------------------------"<<endl;
    cout<< "|             Kalkulator Scientific         |"<<endl;
    cout<< "---------------------------------------------"<<endl;
    cout<< "| No  |         Metode        |    Simbol   |"<<endl;
    cout<< "---------------------------------------------"<<endl;
    cout<< "|  1  |       Penjumlahan     |     (+)     |"<<endl;
    cout<< "|  2  |       Pengurangan     |     (-)     |"<<endl;
    cout<< "|  3  |       Perkalian       |     (*)     |"<<endl;
    cout<< "|  4  |       Pembagian       |     (/)     |"<<endl;
    cout<< "|  5  |       Faktorial       |     (!)     |"<<endl;
    cout<< "|  6  |       Berpangkat      |     (^)     |"<<endl;
    cout<< "|  7  |       Akar Pangkat    |  (√/sqrt) |"<<endl;
    cout<< "|  8  |       Eksponen        |    (e^x)    |"<<endl;
    cout<< "|  9  |       Trigonomteri    |(Sin/Cos/Tan)|"<<endl;
    cout<< "| 10  |       Logaritma       |    (Log)    |"<<endl;
     cout<< "---------------------------------------------"<<endl;
    cout<< "|   Pilih angka selain 1-10 untuk Keluar    |"<<endl;
    cout<< "---------------------------------------------"<<endl;
    cout << "=========================\n";
}

int penjumlahan(Perhitungan &p) {
    int hasil = 0;
    cout << "Operasi: ";
    for (int i = 0; i < p.JmlBil; i++) {
        hasil += p.bil[i];
        cout << p.bil[i];
        if (i != p.JmlBil - 1) {
            cout << " + ";
        } else {
            cout << " = ";
        }
    }
    cout << hasil << endl;
    return hasil;
}

int pengurangan(Perhitungan p) {
    int hasil = p.bil[0];
    cout << "Operasi: " << p.bil[0];
    for (int i = 1; i < p.JmlBil; i++) {
        hasil -= p.bil[i];
        cout << " - " << p.bil[i];
    }
    cout << " = " << hasil << endl;
    return hasil;
}

int perkalian(Perhitungan &p) {
    int hasil = 1;
    cout << "Operasi: ";
    for (int i = 0; i < p.JmlBil; i++) {
        hasil *= p.bil[i];
        cout << p.bil[i];
        if (i != p.JmlBil - 1) {
            cout << " * ";
        } else {
            cout << " = ";
        }
    }
    cout << hasil << endl;
    return hasil;
}

float pembagian(Perhitungan &p) {
    if (p.JmlBil < 1) {
        cout << "Error: Pembagian tidak valid!\n";
        return 0;
    }
    float hasil = p.bil[0];
    cout << "Operasi: " << p.bil[0];
    for (int i = 1; i < p.JmlBil; i++) {
        if (p.bil[i] != 0) {
            hasil /= p.bil[i];
            cout << " / " << p.bil[i];
        } else {
            cout << "\nError: Pembagian dengan nol!\n";
            return 0;
        }
    }
    cout << " = " << hasil << endl;
    return hasil;
}

// Fungsi Faktorial Rekursif
int faktorial(Perhitungan &p) {
    if (p.bilangan1 <= 1) {
        cout << p.bilangan1 << " = ";
        return 1;
    } else {
        cout << p.bilangan1 << " * ";
        p.bilangan1--;
        return (p.bilangan1 + 1) * faktorial(p);
    }
}

// Fungsi Pangkat
int pangkat(Perhitungan &p) {
    cout << p.bilangan1;
    for (int i = 1; i < p.JmlBil; i++) {
        cout << " * " << p.bilangan1;
    }
    cout << " = ";
    return pow(p.bilangan1, p.JmlBil);
}

//Akar Pangkat
double akarPangkat(Perhitungan &p) {
    int metode;
    cout << "Pilih metode akar pangkat:\n";
    cout << "1. Akar Pangkat 2\n";
    cout << "2. Akar Pangkat 3\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> metode;

    if (metode == 1) {
        cout << "Akar Pangkat 2 dari " << p.bilangan1 << " = ";
        return sqrt(p.bilangan1);
    } else if (metode == 2) {
        cout << "Akar Pangkat 3 dari " << p.bilangan1 << " = ";
        return cbrt(p.bilangan1);
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }
}

//eksponen
double eksponen ( Perhitungan &p )
{
    int metode;
    cout<< "Pilih metode akar pangkat:"<<endl;
    cout<< "1. Eksponen Umum"<<endl;
    cout<< "2. Eksponen Biner"<<endl;
    cout<< "3. Eksponen Minus"<<endl;
    cout<< endl;
    cout<< "Eksponen apa yang ingin anda hitung (1-3) : ";
    cin>> metode;
    cout<<endl;
    if ( metode == 1 )
    {
        cout<< "Eksponen ("<<p.bilangan1<< ") = ";
        return exp(p.bilangan1);
    }
    else if ( metode == 2 )
    {
        cout<< "Eksponen Biner ("<<p.bilangan1<< ") =";
        return exp2(p.bilangan1);
    }
    else if ( metode == 3)
    {
        cout<< "Eksponen Minus 1 ("<<p.bilangan1<< ") = ";
        return expm1(p.bilangan1);
    }else {
        cout << "Pilihan tidak valid!" << endl;
        return 0; // Kembalikan 0 jika metode tidak valid
    }
}
//fungsi trigonometri
double trigonometri(double K) {
    int metode, cara;

    cout << "Metode Trigonometri" << endl;
    cout << "1. Trigonometri Umum" << endl;
    cout << "2. Trigonometri Hiperbolik" << endl;

    cout << endl;
    cout << "Trigonometri Apa yang ingin anda hitung ?(1/2) : ";
    cin >> metode;
    cout << endl;

    if (metode == 1) {  // Trigonometri Umum
        cout << "Metode Trigonometri Umum" << endl;
        cout << "1. Cos" << endl;
        cout << "2. Sin" << endl;
        cout << "3. Tan" << endl;
        cout << endl;
        cout << "Ingin menghitung apa?(1-3) : ";
        cin >> cara;
        cout << endl;

        switch (cara) {
            case 1:
                cout << "Cos (" << K << ") = ";
                return cos(K);
            case 2:
                cout << "Sin (" << K << ") = ";
                return sin(K);
            case 3:
                cout << "Tan (" << K << ") = ";
                return tan(K);
            default:
                cout << "Pilihan tidak valid!" << endl;
                return 0;
        }
    } else if (metode == 2) {  // Trigonometri Hiperbolik
        cout << "-------------------------------------" << endl;
        cout << "Metode Trigonometri Hiperbolik" << endl;
        cout << "1. Cosh" << endl;
        cout << "2. Sinh" << endl;
        cout << "3. Tanh" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl;
        cout << "Ingin menghitung apa?(1-3) : ";
        cin >> cara;
        cout << endl;

        switch (cara) {
            case 1:
                cout << "Cos Hiperbolik (" << K << ") = ";
                return cosh(K);
            case 2:
                cout << "Sin Hiperbolik (" << K << ") = ";
                return sinh(K);
            case 3:
                cout << "Tan Hiperbolik (" << K << ") = ";
                return tanh(K);
            default:
                cout << "Pilihan tidak valid!" << endl;
                return 0;
        }
    }
    return 0;
}

//logaritma
float logaritma(float a, int jenisLog) {
    if (a <= 0) {
        cout << "Error: Logaritma dari angka non-positif tidak terdefinisi!\n";
        return 0;
    }

    // Pilihan logaritma berdasarkan jenis
    if (jenisLog == 1) {
        // Logaritma Natural (ln)
        return log(a);
    } else if (jenisLog == 2) {
        // Logaritma basis 10
        return log10(a);
    } else {
        cout << "Pilihan logaritma tidak valid!" << endl;
        return 0;
    }
}


int main() {
    Perhitungan p;
    p.bil = new int[10]; // Alokasikan memori untuk 10 bilangan (ubah ke int)

    if (p.bil == nullptr) {
        cout << "Error: Alokasi memori gagal!\n";
        return 1;
    }

    int pilih;
    string lagi;
    do {
        printMenu();
        cout << "Pilih fitur (1-11): ";
        cin >> pilih;

        //untuk exit jadi selain 1-10 akan exit
        if (pilih < 1 || pilih > 10)
        {
            break;
        }

        switch (pilih) {
            case 1: {
                cout << "Masukkan bilangan pertama: ";
                cin >> p.bil[0];
                cout << "Berapa angka yang ingin ditambahkan? ";
                cin >> p.JmlBil;
                p.JmlBil++;
                for (int i = 1; i < p.JmlBil; i++) {
                    cout << "Masukkan bilangan ke-" << (i + 1) << ": ";
                    cin >> p.bil[i];
                }
                penjumlahan(p);
                break;
            }
            case 2: {
                cout << "Masukkan bilangan pertama: ";
                cin >> p.bil[0];
                cout << "Berapa angka yang ingin dikurangkan? ";
                cin >> p.JmlBil;
                p.JmlBil++;
                for (int i = 1; i < p.JmlBil; i++) {
                    cout << "Masukkan bilangan ke-" << (i + 1) << ": ";
                    cin >> p.bil[i];
                }
                pengurangan(p);
                break;
            }
            case 3: {
                cout << "Masukkan bilangan pertama: ";
                cin >> p.bil[0];
                cout << "Berapa angka yang ingin dikalikan? ";
                cin >> p.JmlBil;
                p.JmlBil++;
                for (int i = 1; i < p.JmlBil; i++) {
                    cout << "Masukkan bilangan ke-" << (i + 1) << ": ";
                    cin >> p.bil[i];
                }
                perkalian(p);
                break;
            }
            case 4: {
                cout << "Masukkan bilangan pertama: ";
                cin >> p.bil[0];
                cout << "Berapa angka yang ingin dibagi? ";
                cin >> p.JmlBil;
                p.JmlBil++;
                for (int i = 1; i < p.JmlBil; i++) {
                    cout << "Masukkan bilangan ke-" << (i + 1) << ": ";
                    cin >> p.bil[i];
                }
                pembagian(p);
                break;
            }
            case 5: {
                cout << "Masukkan bilangan untuk faktorial: ";
                cin >> p.bilangan1;
                cout << "Hasil Faktorial: ";
                cout << faktorial(p) << endl;
                break;
            }
            case 6: {
                cout << "Masukkan bilangan: ";
                cin >> p.bilangan1;
                cout << "Masukkan pangkat: ";
                cin >> p.JmlBil;
                cout << "Hasil Pangkat: ";
                cout << pangkat(p) << endl;
                break;
            }
            case 7: {
                cout << "Masukkan angka untuk akar pangkat: ";
                cin >> p.bilangan1;
                cout << "Hasil Akar Pangkat: " << akarPangkat(p) << endl;
                break;
            }
            case 8: {
                //float a;
                cout << "Masukkan angka untuk eksponen: ";
                cin >> p.bilangan1;
                cout << "Hasil Eksponen: " << eksponen(p) << endl;
                break;
            }
            case 9: {
                double angle;
                double hasilTrigonometri;
                cout << "Masukkan Bilangan yang ingin anda hitung Trigonometrinya : ";
                cin >> angle;  // Input angle in radians
                hasilTrigonometri = trigonometri(angle);
                if (hasilTrigonometri != 0) {
                cout << "Hasil Trigonometri: " << hasilTrigonometri << endl;
                }
                break;
            }

            case 10: {
                float a;
                int jenisLog;

                cout << "Masukkan angka untuk logaritma (harus positif): ";
                cin >> a;

                cout << "Pilih jenis logaritma:\n";
                cout << "1. Logaritma Natural (ln)\n";
                cout << "2. Logaritma Basis 10 (log10)\n";
                cout << "Masukkan pilihan (1/2): ";
                cin >> jenisLog;

               // Memanggil fungsi logaritma untuk menghitung log(a) sesuai dengan pilihan
               float hasil = logaritma(a, jenisLog);
               if (hasil != 0) {
               cout << "Hasil Logaritma: " << hasil << endl;
               }
               break;
            }
        }

        cout << "Apakah Anda ingin melanjutkan perhitungan dengan angka lain? (y/n): ";
        cin >> lagi;
    } while (lagi == "y" || lagi == "Y");

    cout << "Terima kasih telah menggunakan kalkulator ini!" << endl;

    return 0;

    delete[] p.bil; // Bebaskan memori yang telah dialokasikan
    return 0;
}