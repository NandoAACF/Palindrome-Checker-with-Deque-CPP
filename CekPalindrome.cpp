// Program untuk memeriksa palindrome dengan spasi
// Nama: Agustinus Angelo Christian Fernando
// NIM: 21/473804/TK/52235
// Laporan dan Petunjuk sudah saya lampirkan di file PDF
#include <iostream>
#include <string>
#include <deque>
#include <algorithm> 

using namespace std;

// Merapikan string inputan
string setup(string inputan) {
    
    // Memeriksa panjang string inputan
    int panjangStr = inputan.length();
    
    // Mengubah huruf kapital menjadi huruf kecil
    string rapi = "";
    for (int i = 0; i < panjangStr; i++) {
        rapi += tolower(inputan[i]);
    }
    // Untuk menghilangkan spasi
    rapi.erase(remove(rapi.begin(), rapi.end(), ' '), rapi.end());

    return rapi;
}

// Mengecek palindrome atau tidak
bool cekPalindrome(string inputan) {

    // Memanggil string yang sudah dirapikan
    inputan = setup(inputan); 

    deque<char> charDeque;
    // Memeriksa panjang string
    int panjangStr = inputan.length();
    // Memasukkan huruf huruf dari string inputan ke deque
    for (int i = 0; i < panjangStr; i++) {
        charDeque.push_back(inputan[i]);
    }

    bool sama = true;

    // Selama masih ada lebih dari 1 huruf, lalu huruf pertama & huruf terakhirnya masih sama, maka looping akan terus berlangsung
    while (charDeque.size() > 1 && sama) {
        // Mengambil huruf pertama
        char pertama = charDeque.front();
        // Menghapus huruf pertama sehingga bisa diupdate dengan huruf berikutnya
        charDeque.pop_front();
        // Mengambil huruf terakhir
        char terakhir = charDeque.back();
        // Menghapus huruf terakhir sehingga bisa diupdate dengan huruf sebelumnya
        charDeque.pop_back();
        // Jika huruf pertama dan terakhir berbeda, maka BUKAN palindrome
        if (pertama != terakhir) { 
            sama = false;
        }
    }

    // Memberitahu pengguna mengenai status palindrome
    // Jika memenuhi syarat palindrom, maka print "Memenuhi palindrome"
    if(sama==true){
        cout<<"==================="<<endl;
        cout<<"Memenuhi palindrome"<<endl;
        cout<<"==================="<<endl;
    }
    // Jika TIDAK memenuhi syarat palindrom, maka print "Bukan palindrome"
    else{
        cout<<"================"<<endl;
        cout<<"Bukan palindrome"<<endl;
        cout<<"================"<<endl;
    }
    return sama;
}

int main() {

    // Mengambil input kata/kalimat yang ingin di cek status polindromnya
    string inputan;
    cout<<"Masukkan kata/kalimat yang ingin dicek: ";
    getline(cin, inputan);
    // Mengecek apakah inputan tersebut palindrom atau tidak
    inputan = cekPalindrome(inputan);

    return 0;
}
