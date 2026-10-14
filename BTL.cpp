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
	Node *head;
	Node* createNode(Sach s);
	void themSach(Sach s);
	void inDinhDangSach(Sach s);
	void hienThiDanhSach();
	Node* timKiemTheoMa( string ma);
	void suaThongTinSach();
	void muonSach();
	void traSach();
	void locTheoTheLoai();
	void sapXepTheoTen();
	void docFile(string filename);
	void ghiFile(string filename);
	void giaiPhongBoNho();
};
void Library::sapXepTheoTen() {
    for (Node* i = head; i != nullptr && i->next != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data.tenSach < minNode->data.tenSach) {
                minNode = j;
            }
        }
        if (minNode != i) {
            swap(i->data, minNode->data);
        }
    }
    cout << "[+] Da sap xep danh sach theo ten (A-Z)!\n";
}

void Library::locTheoTheLoai(){
	cin.ignore();
	string TheLoai;
	cout<<"nhap the loai sach"<<endl;
	getline(cin,TheLoai);
	bool found = false;
	cout << left << setw(10) <<"Ma Sach"
		<< setw(30) <<"Ten Sach"
		<< setw(20) <<"The Loai"
		<< setw(12) <<"Ton Kho"
		<< setw(12) <<"Da Muon" << endl;
	Node *test = head;
	while (test != NULL)
	{
		if (test->data.theLoai == TheLoai)
		{
			inDinhDangSach(test->data);
			found = true;
		}
		test = test->next;
	}
	if(found == false) cout<<"The Loai nay khong ton tai!"<<endl;
	
}
int main(){

}
