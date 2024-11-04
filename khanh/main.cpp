#include <bits/stdc++.h>
#include <windows.h>
#include "khachhang.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // Set UTF-8 encoding for console
    vector<KhachHang> khachhangs = KhachHang::Docfile("data/Costumer.csv");

    while (true) {
        cout << "\n=== Quan Li Khach Hang ===\n";
        cout << "1. Tim kiem theo ngay\n";
        cout << "2. Tim kiem theo ten\n";
        cout << "3. Them thong tin khach hang\n";
        cout << "4. Chinh sua thong tin khach hang\n";
        cout << "5. Thoat\n";
        cout << "Chon chuc nang(1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                KhachHang::TimTheoNgay(khachhangs);
                break;
            case 2:
                KhachHang::TimTheoTen(khachhangs);
                break;
            case 3:
                KhachHang::ThemVaSuaTT(khachhangs, "data/Costumer.csv");
                break;
            case 4:
                KhachHang::ChinhSuaTT(khachhangs, "data/Costumer.csv");
                break;
            case 5:
                cout << "Cam on ban da su dung chuong trinh!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}