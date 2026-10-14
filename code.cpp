#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
typedef struct S {
    string maSach;
    string tenSach;
    string theLoai;
    int soLuongTon;
    int soLuongMuon;
}Sach;
struct Node {
    Sach data;
    Node* next;
};
class Library{
	Node* createNode(Sach s);
	void themSach(Node*& head, Sach s);
	void inDinhDangSach(Sach s);
	void hienThiDanhSach(Node* head);
	Node* timKiemTheoMa(Node* head, string ma);
	void suaThongTinSach(Node* head);
	void muonSach(Node* head);
	void traSach(Node* head);
	void locTheoTheLoai(Node* head);
	void sapXepTheoTen(Node* head);
	void docFile(Node*& head, string filename);
	void ghiFile(Node* head, string filename);
	void giaiPhongBoNho(Node*& head);
};
// Hàm hiển thị một cuốn sách dưới dạng dòng trong bảng
void inDinhDangSach(Sach s) {
    cout << left << setw(10) << s.maSach
         << setw(30) << s.tenSach
         << setw(20) << s.theLoai
         << setw(12) << s.soLuongTon
         << setw(12) << s.soLuongMuon << endl;
}

// Hàm hiển thị toàn bộ danh sách sách
void hienThiDanhSach(Node* head) {
    if (head == NULL) {
        cout << "\n[!] Danh sach sach hien dang rong!\n";
        return;
    }
    cout << "\n================================ DANH SACH SACH ================================\n";
    cout << left << setw(10) << "Ma Sach"
         << setw(30) << "Ten Sach"
         << setw(20) << "The Loai"
         << setw(12) << "Ton Kho"
         << setw(12) << "Da Muon" << endl;
    cout << string(84, '-') << endl;
    
    Node* temp = head;
    while (temp != NULL) {
        inDinhDangSach(temp->data);
        temp = temp->next;
    }
    cout << string(84, '=') << endl;
}