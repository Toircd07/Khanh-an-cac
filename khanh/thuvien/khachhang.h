#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <string>
#include <vector>

class KhachHang {
private:
    std::string ngay;
    std::string ten;
    std::string sdt;
    std::string loaithit;
    int soluong;

public:
    KhachHang();

    static std::vector<KhachHang> Docfile(const std::string& filename);
    static void TimTheoNgay(const std::vector<KhachHang>& khachhangs);
    static void TimTheoTen(const std::vector<KhachHang>& khachhangs);
    static void ChinhSuaTT(std::vector<KhachHang>& khachhangs, const std::string& filename);
    static void ThemVaSuaTT(std::vector<KhachHang>& khachhangs, const std::string& filename);

    // Getters and Setters
    std::string getNgay() const;
    void setNgay(const std::string& d);
    std::string getTen() const;
    void setTen(const std::string& n);
    std::string getSdt() const;
    void setSdt(const std::string& p);
    std::string getLoaiThit() const;
    void setLoaiThit(const std::string& m);
    int getSoLuong() const;
    void setSoLuong(int q);
};

#endif // KHACHHANG_H