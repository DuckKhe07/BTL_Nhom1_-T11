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
void Library::locTheoTheLoai(Node *head){
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
