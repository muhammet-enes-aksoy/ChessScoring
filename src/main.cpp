#include "ThreatStatus.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ThreatStatus threatStatus;
    string fileName;

    // Kullanıcıdan dosya ismini isteyen bir mesaj gösterilir.
    cout << "Dosya ismi giriniz. (Örnek: board1.txt)" << endl;

    // Kullanıcının dosya ismini girmesi beklenir.
    cin >> fileName;

    // Girilen dosyadan tahta verileri yüklenir.
    threatStatus.loadFromFile(fileName);

    // Tahtanın toplam skoru hesaplanır ve ekrana yazdırılır.
    threatStatus.printTotatScore();

    return 0;
}
