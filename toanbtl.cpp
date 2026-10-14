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
		Node *head;
	    Node* createNode(Sach s);
	    void init();
	    void themSach(Node*& head, Sach s);
	void inDinhDangSach(Sach s);
	void hienThiDanhSach();
	Node* timKiemTheoMa(string ma);
	void suaThongTinSach();
	void muonSach();
	void traSach();
	void locTheoTheLoai();
	void sapXepTheoTen();
	void docFile(Node*& head, string filename);
	void ghiFile(string filename);
	void giaiPhongBoNho(Node*& head);
};
//Hàm khởi tạo
void Library::init(){
	head=NULL;
}
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
// Hàm hiển thị một cuốn sách dưới dạng dòng trong bảng
void Library::inDinhDangSach(Sach s) {
    cout << left << setw(10) << s.maSach
         << setw(30) << s.tenSach
         << setw(20) << s.theLoai
         << setw(12) << s.soLuongTon
         << setw(12) << s.soLuongMuon << endl;
}

// Hàm hiển thị toàn bộ danh sách sách
void Library::hienThiDanhSach(){
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
Node* Library::timKiemTheoMa(string ma) { 
    Node* temp = head; // tạo biến node temp và đang trỏ tới head
    while (temp != NULL) { // xét vòng lặp while với đkien temp khác NULL 
        if (temp->data.maSach == ma) {//so sánh mã sách trong dữ liệu của node hiện tại với chuỗi mã ma 
            return temp;
        }
        temp = temp->next;//Di chuyển con trỏ temp sang node tiếp theo trong danh sác
    }
    return nullptr;// hết vòng lặp while mà không thấy node nào trùng mã, hàm trả về nullptr 
}
// Chức năng Sửa thông tin sách
void Library::suaThongTinSach(){
    string ma;// dùng để lưu trữ tạm các ký hiệu nhập
    cout << "Nhap ma sach muon sua: ";
    cin >> ma;
    cin.ignore();
    
    Node* target = timKiemTheoMa(ma);//Gọi hàm timKiemTheoMa để tìm node chứa mã vừa nhập và gán địa chỉ node tìm được vào con trỏ target.
    if (target == NULL) {
        cout << "[!] Khong tim thay sach co ma: " << ma << endl;
        return;
    }

    string maMoi;///khai bao bien mới trong void 
    cout << "Nhap ma sach moi: ";
    getline(cin, maMoi);

    // Kiểm tra mã mới có bị trùng với sách khác trong danh sách không
    if (maMoi != ma) { // mã mới khác mã cũ thì trương trình  thực hiện
        Node* checkTrung = timKiemTheoMa(maMoi);
        if (checkTrung != NULL) {// mã mới bị trùng
            cout << "[!] Loi: Ma sach '" << maMoi << "' da ton tai trong he thong!\n";// thong báo lỗi và dùng returrn để dừng 
            return;
        }
    }

    // Cập nhật mã mới nếu hợp lệ
    target->data.maSach = maMoi;//khi maMOi hợp lệ thì đưa vao maSach
    cout << "Nhap ten sach moi: ";
    getline(cin, target->data.tenSach);
    cout << "Nhap the loai moi: ";
    getline(cin, target->data.theLoai);
    cout << "Cap nhat thong tin thanh cong!\n";
}
void Library::muonSach() {
    string ma;
    cout << "Nhap ma sach can muon: ";
    cin >> ma;
 
    Node* p = timKiemTheoMa(ma);
 
    if (p == NULL) {
        cout << "Khong tim thay sach!" << endl;
    } else if (p->data.soLuongTon == 0) {
        cout << "Sach da het, khong the muon!" << endl;
    } else {
        p->data.soLuongTon--;
        p->data.soLuongMuon++;
        cout << "Muon sach thanh cong!" << endl;
    }
}
void Library::traSach() {
    string ma;
    cout << "Nhap ma sach can tra: ";
    cin >> ma;
 
    Node* p = timKiemTheoMa(ma);
 
    if (p == NULL) {
        cout << "Khong tim thay sach!" << endl;
    } else if (p->data.soLuongMuon == 0) {
        cout << "Khong co ai dang muon sach nay!" << endl;
    } else {
        p->data.soLuongMuon--;
        p->data.soLuongTon++;
        cout << "Tra sach thanh cong!" << endl;
    }
}
void Library::sapXepTheoTen() {
    for (Node* i = head; i != NULL && i->next != NULL; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data.tenSach < minNode->data.tenSach) {
                minNode = j;
            }
        }
        if (minNode != i) {
            swap(i->data, minNode->data);
        }
    }
    cout << "Da sap xep danh sach theo ten (A-Z)!\n";
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
void Library::ghiFile(string filename){
	ofstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the tao/mo file de ghi!\n";
        return;
    }
    
    Node* temp = head;
    while (temp != NULL){
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
    string filename = "Ms001.txt";
    L.init();
    int choise;

    // Tự động tải dữ liệu từ file khi khởi động
    L.docFile(L.head, filename);

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
                L.hienThiDanhSach();
                break;
            case 2: {
                Sach s;
                cout << "Nhap ma sach: "; cin >> s.maSach;
                cin.ignore();
                cout << "Nhap ten sach: "; getline(cin, s.tenSach);
                cout << "Nhap the loai: "; getline(cin, s.theLoai);
                cout << "Nhap so luong ton kho: "; cin >> s.soLuongTon;
                s.soLuongMuon = 0;
                L.themSach(L.head, s);
                cout << "Them sach thanh cong!\n";
                break;
            }
            case 3:
                L.suaThongTinSach();
                break;
            case 4:
                L.muonSach();
                break;
            case 5:
                L.traSach();
                break;
            case 6:
                L.locTheoTheLoai();
                break;
            case 7:
                L.sapXepTheoTen();
                L.hienThiDanhSach();
                break;
            case 8:
                L.ghiFile(filename);
                break;
            case 0:
                L.ghiFile(filename); // Tự động lưu trước khi thoát
                L.giaiPhongBoNho(L.head);
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (choise != 0);
    return 0;
}

