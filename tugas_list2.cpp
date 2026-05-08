#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node *next, *prev;
};

Node *head = NULL, *tail = NULL;
int countNode = 0;

void insertChar(char c) {
    Node *baru = new Node;
    baru->data = c;
    baru->next = NULL;
    baru->prev = NULL;
    if (!head) { 
        head = tail = baru; 
    } else { 
        tail->next = baru; 
        baru->prev = tail; 
        tail = baru; 
    }
    countNode++;
}

void enkripsi(char key) {

    if (countNode < 6) { 
        cout << "Gagal: Password minimal 6 karakter!\n"; 
        return; 
    }

    for (int i = 0; i < 3; i++) {
        Node *pindah = tail;
        tail = tail->prev;
        tail->next = NULL; 
        
        pindah->prev = NULL;
        pindah->next = head;
        head->prev = pindah;
        head = pindah;
    }

    Node *bantu = head;
    for (int i = 0; i < 2; i++) { 
        bantu = bantu->next;
    }

    Node *sisip = new Node;
    sisip->data = key;
    sisip->next = bantu->next;
    sisip->prev = bantu;
    if (bantu->next != NULL) bantu->next->prev = sisip;
    bantu->next = sisip;
    
    countNode++; 
    cout << "Enkripsi Berhasil!\n";
}

void tampil() {
    if (!head) { 
        cout << "List Kosong!\n"; 
        return; 
    }
    Node *b = head;
    while (b != NULL) { 
        cout << b->data; 
        b = b->next; 
    }
    cout << endl;
}

int main() {
    int pil; 
    string p; 
    char k;
    
    do {
        cout << "\n[ --- MENU ENKRIPSI --- ]\n";
        cout << "1. Input Password\n2. Jalankan Enkripsi\n3. Tampilkan\n0. Keluar\nPilih: ";
        
        if (!(cin >> pil)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Masukkan angka menu yang benar!\n";
            continue;
        }

        if (pil == 1) {
            head = tail = NULL; 
            countNode = 0;
            cout << "Input Password (min 6): "; 
            cin >> p;
            for (int i = 0; i < p.length(); i++) insertChar(p[i]);
        } else if (pil == 2) {
            cout << "Masukkan SATU Karakter Kunci (Contoh: @ atau # atau !): "; 
            cin >> k;
            cin.ignore(1000, '\n'); 
            enkripsi(k);
        } else if (pil == 3) {
            cout << "Password Saat Ini: ";
            tampil();
        }
    } while (pil != 0);
    
    return 0;
}