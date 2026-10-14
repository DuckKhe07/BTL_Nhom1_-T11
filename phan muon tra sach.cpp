void Library::muonSach(Node* head) {
    string ma;
    cout << "Nhap ma sach can muon: ";
    cin >> ma;
 
    Node* p = timKiemTheoMa(head, ma);
 
    if (p == nullptr) {
        cout << "Khong tim thay sach!" << endl;
    } else if (p->data.soLuongTon == 0) {
        cout << "Sach da het, khong the muon!" << endl;
    } else {
        p->data.soLuongTon--;
        p->data.soLuongMuon++;
        cout << "Muon sach thanh cong!" << endl;
    }
}
void Library::traSach(Node* head) {
    string ma;
    cout << "Nhap ma sach can tra: ";
    cin >> ma;
 
    Node* p = timKiemTheoMa(head, ma);
 
    if (p == nullptr) {
        cout << "Khong tim thay sach!" << endl;
    } else if (p->data.soLuongMuon == 0) {
        cout << "Khong co ai dang muon sach nay!" << endl;
    } else {
        p->data.soLuongMuon--;
        p->data.soLuongTon++;
        cout << "Tra sach thanh cong!" << endl;
    }
}