#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node *head = NULL, *tail = NULL;

int isEmpty() {
    return (head == NULL) ? 1 : 0;
}

void tambahData(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Data " << nilai << " masuk ke list.\n";
}

void hapusData(int target) {
    if (isEmpty()) {
        cout << "List kosong!\n";
        return;
    }
    Node *hapus = head;
    while (hapus != NULL && hapus->data != target) {
        hapus = hapus->next;
    }
    if (hapus == NULL) {
        cout << "Data tidak ditemukan.\n";
        return;
    }
    if (hapus == head) {
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
    } else if (hapus == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }
    delete hapus;
    cout << "Data terhapus.\n";
}

void cetak() {
    if (isEmpty()) {
        cout << "List kosong.\n";
        return;
    }
    Node *bantu = head;
    while (bantu != NULL) {
        cout << bantu->data << " <=> ";
        bantu = bantu->next;
    }
    cout << "NULL\n";
}

int main() {
    int pil, val;
    do {
        cout << "\n[ --- MENU UTAMA --- ]\n1. Tambah Data\n2. Hapus Data\n3. Cek Kosong\n4. Cetak\n0. Keluar\nPilih: ";
        cin >> pil;
        switch(pil) {
            case 1: cout << "Nilai: "; cin >> val; tambahData(val); break;
            case 2: cout << "Hapus Nilai: "; cin >> val; hapusData(val); break;
            case 3: cout << (isEmpty() ? "Kosong\n" : "Ada Isinya\n"); break;
            case 4: cetak(); break;
        }
    } while (pil != 0);
    return 0;
}