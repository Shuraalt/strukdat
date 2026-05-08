#include <iostream>
#include <string>
using namespace std;

struct Nasabah {
    string nama;
    bool isPrio;
    Nasabah *next, *prev;
};

Nasabah *head = NULL, *tail = NULL;

void tambah(string n, bool p) {
    Nasabah *baru = new Nasabah;
    baru->nama = n; baru->isPrio = p;
    if (!head) {
        head = tail = baru; head->next = head->prev = head;
    } else {
        if (p) {
            Nasabah *b = head;
            if (!head->isPrio) {
                baru->next = head; baru->prev = tail;
                head->prev = baru; tail->next = baru; head = baru;
            } else {
                while (b->next != head && b->next->isPrio) b = b->next;
                baru->next = b->next; baru->prev = b;
                b->next->prev = baru; b->next = baru;
                if (b == tail) tail = baru;
            }
        } else {
            baru->prev = tail; baru->next = head;
            tail->next = baru; head->prev = baru; tail = baru;
        }
    }
}

void panggil() {
    if (!head) return;
    Nasabah *h = head;
    cout << "Memanggil: " << h->nama << endl;
    if (head == tail) head = tail = NULL;
    else { head = head->next; tail->next = head; head->prev = tail; }
    delete h;
}

void cetak() {
    if (!head) return;
    Nasabah *b = head;
    do {
        cout << "[" << b->nama << (b->isPrio ? "*Prio" : "") << "] <-> ";
        b = b->next;
    } while (b != head);
    cout << "(LOOP)\n";
}

int main() {
    int pil; string n; char c;
    do {
        cout << "\n[TAKE HOME - MENU ANTREAN DLLC]\n1. Tambah Nasabah\n2. Panggil (Hapus)\n3. Lihat Antrean\n0. Keluar\nPilih: ";
        cin >> pil;
        if (pil == 1) {
            cout << "Nama: "; cin >> n;
            cout << "Prioritas? (y/n): "; cin >> c;
            tambah(n, (c == 'y'));
        } else if (pil == 2) panggil();
        else if (pil == 3) cetak();
    } while (pil != 0);
    return 0;
}