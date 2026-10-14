Node* timKiemTheoMa(Node* head, string ma) { 
    Node* temp = head; 
    while (temp != NULL) { 
        if (temp->data.maSach == ma) { 
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;/
}
void suaThongTinSach(Node* head) {
    string ma;
    cout << "Nhap ma sach muon sua: ";
    cin >> ma;
    cin.ignore();
    
    Node* target = timKiemTheoMa(head, ma);
    if (target == nullptr) {
        cout << "[!] Khong tim thay sach co ma: " << ma << endl;
        return;
    }

    string maMoi;///khai bao bien m?i trong void 
    cout << "Nhap ma sach moi: ";
    getline(cin, maMoi);

    
    if (maMoi != ma) { 
        Node* checkTrung = timKiemTheoMa(head, maMoi);
        if (checkTrung != nullptr) {
            cout << "[!] Loi: Ma sach '" << maMoi << "' da ton tai trong he thong!\n";
            return;
        }
    }
    target->data.maSach = maMoi;
    cout << "Nhap ten sach moi: ";
    getline(cin, target->data.tenSach);
    cout << "Nhap the loai moi: ";
    getline(cin, target->data.theLoai);
    cout << "[+] Cap nhat thong tin thanh cong!\n";
}