Node* timKiemTheoMa(Node* head, string ma) { 
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
void suaThongTinSach(Node* head) {
    string ma;// dùng để lưu trữ tạm các ký hiệu nhập
    cout << "Nhap ma sach muon sua: ";
    cin >> ma;
    cin.ignore();
    
    Node* target = timKiemTheoMa(head, ma);//Gọi hàm timKiemTheoMa để tìm node chứa mã vừa nhập và gán địa chỉ node tìm được vào con trỏ target.
    if (target == nullptr) {
        cout << "[!] Khong tim thay sach co ma: " << ma << endl;
        return;
    }

    string maMoi;///khai bao bien mới trong void 
    cout << "Nhap ma sach moi: ";
    getline(cin, maMoi);

    // Kiểm tra mã mới có bị trùng với sách khác trong danh sách không
    if (maMoi != ma) { // mã mới khác mã cũ thì trương trình  thực hiện
        Node* checkTrung = timKiemTheoMa(head, maMoi);
        if (checkTrung != nullptr) {// mã mới bị trùng
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
    cout << "[+] Cap nhat thong tin thanh cong!\n";
}