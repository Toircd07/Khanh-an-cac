#include "khachhang.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <windows.h>

using namespace std;

// Constructor
KhachHang::KhachHang() : soluong(0) {}

// Read file
vector<KhachHang> KhachHang::Docfile(const string& filename) {
    vector<KhachHang> khachhangs;
    ifstream file(filename);
    string line;

    getline(file, line);  // Skip header
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        KhachHang customer;
        string soluongStr, ngay, ten, sdt, loaithit;
        getline(ss, ngay, ',');
        getline(ss, ten, ',');
        getline(ss, sdt, ',');
        getline(ss, loaithit, ',');
        getline(ss, soluongStr, ',');

        customer.setNgay(ngay);
        customer.setTen(ten);
        customer.setSdt(sdt);
        customer.setLoaiThit(loaithit);
        customer.setSoLuong(stoi(soluongStr));

        khachhangs.push_back(customer);
    }
    return khachhangs;
}

// Search by date
void KhachHang::TimTheoNgay(const vector<KhachHang>& khachhangs) {
    string timngay;
    cout << "Nhap ngay can tim: ";
    cin >> timngay;

    bool found = false;
    cout << "\nKet qua tim kiem theo ngay " << timngay << ":\n";
    cout << "----------------------------------------\n";
    for (const KhachHang& c : khachhangs) {
        if (c.getNgay() == timngay) {
            cout << "Ten: " << c.getTen() << endl;
            cout << "SDT: " << c.getSdt() << endl;
            cout << "Loai thit: " << c.getLoaiThit() << endl;
            cout << "So luong: " << c.getSoLuong() << endl;
            cout << "----------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay khach hang nao trong ngay!\n";
    }
}

// Search by name
void KhachHang::TimTheoTen(const vector<KhachHang>& khachhangs) {
    string timten;
    cout << "Nhap ten khach hang can tim: ";
    cin.ignore();
    getline(cin, timten);

    string timten_lower = timten;
    transform(timten_lower.begin(), timten_lower.end(), timten_lower.begin(), ::tolower);

    bool found = false;
    cout << "\nKet qua tim kiem cho ten \"" << timten << "\":\n";
    cout << "----------------------------------------\n";

    for (const KhachHang& c : khachhangs) {
        string tenKhachHang = c.getTen();
        string tenKhachHang_lower = tenKhachHang;
        transform(tenKhachHang_lower.begin(), tenKhachHang_lower.end(), tenKhachHang_lower.begin(), ::tolower);

        if (tenKhachHang_lower.find(timten_lower) != string::npos) {
            cout << "Ngay: " << c.getNgay() << endl;
            cout << "Ten: " << c.getTen() << endl;
            cout << "SDT: " << c.getSdt() << endl;
            cout << "Loai thit: " << c.getLoaiThit() << endl;
            cout << "So luong: " << c.getSoLuong() << endl;
            cout << "----------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay khach hang!\n";
    }
}

// Edit customer information
void KhachHang::ChinhSuaTT(vector<KhachHang>& khachhangs, const string& filename) {
    string timten;
    cout << "Nhap ten khach hang can chinh sua: ";
    cin.ignore();
    getline(cin, timten);

    string timten_lower = timten;
    transform(timten_lower.begin(), timten_lower.end(), timten_lower.begin(), ::tolower);

    bool found = false;

    for (KhachHang& c : khachhangs) {
        string tenKhachHang = c.getTen();
        string tenKhachHang_lower = tenKhachHang;
        transform(tenKhachHang_lower.begin(), tenKhachHang_lower.end(), tenKhachHang_lower.begin(), ::tolower);

        if (tenKhachHang_lower == timten_lower) {
            found = true;
            cout << "Thong tin hien tai:\n";
            cout << "Ngay: " << c.getNgay() << endl;
            cout << "Ten: " << c.getTen() << endl;
            cout << "SDT: " << c.getSdt() << endl;
            cout << "Loai thit: " << c.getLoaiThit() << endl;
            cout << "So luong: " << c.getSoLuong() << endl;

            string ngay, sdt, loaithit;
            int soluong;

            cout << "\nNhap thong tin moi:\n";
            cout << "Ngay (dd/mm/yyyy): ";
            cin >> ngay;
            c.setNgay(ngay);
            cout << "SDT: ";
            cin.ignore();
            getline(cin, sdt);
            c.setSdt(sdt);
            cout << "Loai thit: ";
            getline(cin, loaithit);
            c.setLoaiThit(loaithit);
            cout << "So luong: ";
            cin >> soluong;
            c.setSoLuong(soluong);

            cout << "Da chinh sua thong tin khach hang \"" << c.getTen() << "\" thanh cong!\n";
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay khach hang!\n";
        return;
    }

    ofstream file(filename);
    file << "Ngay,Ten,SDT,Loai Thit,So luong\n";
    for (const KhachHang& c : khachhangs) {
        file << c.getNgay() << ","
             << c.getTen() << ","
             << c.getSdt() << ","
             << c.getLoaiThit() << ","
             << c.getSoLuong() << "\n";
    }
}

// Add or edit customer information
void KhachHang::ThemVaSuaTT(vector<KhachHang>& khachhangs, const string& filename) {
    KhachHang KHmoi;
    string ngay, ten, sdt, loaithit;
    int soluong;

    cout << "Nhap thong tin khach hang moi:\n";
    cout << "Ngay (dd/mm/yyyy): ";
    cin >> ngay;
    KHmoi.setNgay(ngay);
    cout << "Ten: ";
    cin.ignore();
    getline(cin, ten);
    KHmoi.setTen(ten);
    cout << "SDT: ";
    getline(cin, sdt);
    KHmoi.setSdt(sdt);
    cout << "Loai thit: ";
    getline(cin, loaithit);
    KHmoi.setLoaiThit(loaithit);
    cout << "So luong: ";
    cin >> soluong;
    KHmoi.setSoLuong(soluong);

    khachhangs.push_back(KHmoi);

    ofstream file(filename);
    file << "Ngay,Ten,SDT,Loai Thit,So luong\n";
    for (const KhachHang& c : khachhangs) {
        file << c.getNgay() << ","
             << c.getTen() << ","
             << c.getSdt() << ","
             << c.getLoaiThit() << ","
             << c.getSoLuong() << "\n";
    }

    cout << "Da them thong tin thanh cong\n";
}

// Getters and Setters
string KhachHang::getNgay() const { return ngay; }
void KhachHang::setNgay(const string& d) { this->ngay = d; }
string KhachHang::getTen() const { return ten; }
void KhachHang::setTen(const string& n) { this-> ten = n; }
string KhachHang::getSdt() const { return sdt; }
void KhachHang::setSdt(const string& p) { this-> sdt = p; }
string KhachHang::getLoaiThit() const { return loaithit; }
void KhachHang::setLoaiThit(const string& m) { this->loaithit = m; }
int KhachHang::getSoLuong() const { return soluong; }
void KhachHang::setSoLuong(int q) { this->soluong = q; }