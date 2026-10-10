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
	public:
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
//Hàm tạo node
Node *Library::createNode(Sach s){
	Node* newNode = new Node();
    newNode->data = s;
    newNode->next = NULL;
    return newNode;
}
//addbook vào Library
void Library::themSach(Node*& head, Sach s){
	Node* newNode = createNode(s);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void Library::docFile(Node*& head, string filename){
	ifstream file(filename); //lệnh trích xuất/đọc file 
    if (!file.is_open()) // check tên file
	{
        cout << "[!] Khong the mo file " << filename << " (Hoac file chua ton tai).\n";
        return;
    }
    
    // Xóa danh sách cũ nếu có
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    Sach s; //khai báo lại dữ liệu s
    while (file >> s.maSach) // trích xuất/đọc file và lưu vào s cho đến khi cuối danh sách EOF
	{
        file.ignore();
        getline(file, s.tenSach); //trích xuất/đọc dữ liệu và lưu dữ liệu vào s 
        getline(file, s.theLoai); // trích xuất/đọc dữ liệu và lưu dữ liệu vào s 
        file >> s.soLuongTon >> s.soLuongMuon; //trích xuất dữ liệu và lưu dữ liệu vào s 
        themSach(head, s); //thêm những dữ liệu sách đã đc lưu
    }
    file.close(); //dừng việc trích xuất/đọc file
    cout << "Doc du lieu tu file " << filename << " thanh cong!\n";
}
void Library::ghiFile(Node* head, string filename){
	ofstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the tao/mo file de ghi!\n";
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        file << temp->data.maSach << "\n"
             << temp->data.tenSach << "\n"
             << temp->data.theLoai << "\n"
             << temp->data.soLuongTon << " " << temp->data.soLuongMuon << "\n";
        temp = temp->next;
    }
    file.close();
    cout << "Luu du lieu vao file " << filename << "thanh cong!\n";
}
void Library::giaiPhongBoNho(Node*& head){
	while (head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main(){
	Library L;
	Node* head = NULL;
    string filename = "Ms001.txt";
    int choise;

    // Tự động tải dữ liệu từ file khi khởi động
    L.docFile(head, filename);

    do {
        cout << "\n================ HE THONG QUAN LY KHO SACH ================\n";
        cout << "1. Hien thi danh sach sach\n";
        cout << "2. Them sach moi\n";
        cout << "3. Sua thong tin sach\n";
        cout << "4. Muon sach\n";
        cout << "5. Tra sach\n";
        cout << "6. Loc sach theo the loai\n";
        cout << "7. Sap xep sach theo ten (A-Z)\n";
        cout << "8. Luu danh sach vao File .txt\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "-----------------------------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choise;

        switch (choise) {
            case 1:
                L.hienThiDanhSach(head);
                break;
            case 2: {
                Sach s;
                cout << "Nhap ma sach: "; cin >> s.maSach;
                cin.ignore();
                cout << "Nhap ten sach: "; getline(cin, s.tenSach);
                cout << "Nhap the loai: "; getline(cin, s.theLoai);
                cout << "Nhap so luong ton kho: "; cin >> s.soLuongTon;
                s.soLuongMuon = 0;
                L.themSach(head, s);
                cout << "Them sach thanh cong!\n";
                break;
            }
            case 3:
                L.suaThongTinSach(head);
                break;
            case 4:
                L.muonSach(head);
                break;
            case 5:
                L.traSach(head);
                break;
            case 6:
                L.locTheoTheLoai(head);
                break;
            case 7:
                L.sapXepTheoTen(head);
                L.hienThiDanhSach(head);
                break;
            case 8:
                L.ghiFile(head, filename);
                break;
            case 0:
                L.ghiFile(head, filename); // Tự động lưu trước khi thoát
                L.giaiPhongBoNho(head);
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (choise != 0);
    return 0;
}

