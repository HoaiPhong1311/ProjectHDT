#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

class Phong{
    protected:
        int soPhong;
        string tinhTrang, loai, huongPhong, dichVu, chuPhong;
    
    public:
        virtual int TienPhong() = 0;

        virtual void InThongTin() = 0;

        virtual void XuatFile(ofstream &file) = 0;

        void docFile(ifstream &file){
            file >> soPhong;
            file.ignore();
            getline(file,loai, ',');
            getline(file,tinhTrang, ',');
            getline(file,huongPhong, ',');
            getline(file,dichVu, ',');
            getline(file,chuPhong, ',');
            file.ignore();
        }

        void GhiFile(ofstream &file){
            file << setw(15) << left << soPhong;
            file << setw(20) << left << loai;
            file << setw(20) << left << tinhTrang;
            file << setw(20) << left << huongPhong;
            file << setw(20) << left << dichVu;
            file << setw(25) << left << chuPhong;
        }

        int PhiPhuThu(){
            int soTien = 0;
            const int HUONG_NUI = 500000;
            const int HUONG_BIEN = 750000;
            const int TIEU_CHUAN = 0;

            if(huongPhong == "Huong nui") soTien = HUONG_NUI;
            else if(huongPhong == "Huong bien") soTien = HUONG_BIEN;
            else soTien = TIEU_CHUAN;

            const int AN_UONG = 750000;
            const int DON_DEP = 200000;
            const int GIAT_UI = 200000;
            const int TRON_GOI = 1000000;
            const int KHONG = 0;

            if(dichVu == "X") return soTien + KHONG;
            else if(dichVu == "An uong") return soTien + AN_UONG;
            else if(dichVu == "Don dep") return soTien + DON_DEP;
            else if(dichVu == "Giat ui") return soTien + GIAT_UI;
            else return soTien + TRON_GOI;
        }

        void out(){
            cout << setw(15) << left << soPhong;
            cout << setw(20) << left << loai;
            cout << setw(20) << left << tinhTrang;
            cout << setw(20) << left << huongPhong;
            cout << setw(20) << left << dichVu;
            cout << setw(25) << left << chuPhong;
        }

        string GetLoai(){
            return loai;
        }

        string GetChuPhong(){
            return chuPhong;
        }

        string GetTinhTrang(){
            return tinhTrang;
        }

        string GetHuongPhong(){
            return huongPhong;
        }

        int GetSoPhong(){
            return soPhong;
        }

        string GetDichVu(){
            return dichVu;
        }

        void SetDichVu(string dichVu){
            this->dichVu = dichVu;
        }

        void SetChuPhong(string chuPhong){
            this->chuPhong = chuPhong;
        }

        void SetTinhTrang(string tinhTrang){
            this->tinhTrang = tinhTrang;
        }

        void TieuDe(){
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(15) << left << "So phong";
            cout << setw(20) << left << "Loai phong";
            cout << setw(20) << left << "Tinh trang";
            cout << setw(20) << left << "Huong phong";
            cout << setw(20) << left << "Dich vu";
            cout << setw(25) << left << "Chu phong";
            cout << setw(20) << left << "Tien phong" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
};

class SingleBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 1000000; // Gia goc cua phong Single Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void InThongTin(){
            out();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class DoubleBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 2000000; // Gia goc cua phong Double Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void InThongTin(){
            out();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class QueenSizeBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 4000000; // Gia goc cua phong Queen size Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void InThongTin(){
            out();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class KingSizeBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 5500000; // Gia goc cua phong King size Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void InThongTin(){
            out();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class KhachHang{
    protected:
        int maKh, thoiGian, nguoiDiChung;
        string ten, dienThoai, email, loai, theThanhVien;

    public:
        virtual int PhiDiKem() = 0;

        void docFile(ifstream &file){
            file >> maKh;
            file.ignore();
            getline(file,ten, ',');
            getline(file,dienThoai, ',');
            getline(file,email, ',');
            getline(file,loai, ',');
            getline(file,theThanhVien, ',');
            file >> thoiGian;
            file.ignore();
            file >> nguoiDiChung;
            file.ignore();
        }

        void GhiFile(ofstream &file){
            file << setw(10) << left << maKh;
            file << setw(20) << left << ten;
            file << setw(20) << left << dienThoai;
            file << setw(25) << left << email;
            file << setw(10) << left << loai;
            file << setw(10) << left << theThanhVien;
            file << setw(15) << left << thoiGian;
            file << setw(15) << left << nguoiDiChung;
        }

        void InThongTin(){
            cout << setw(10) << left << maKh;
            cout << setw(20) << left << ten;
            cout << setw(20) << left << dienThoai;
            cout << setw(25) << left << email;
            cout << setw(10) << left << loai;
            cout << setw(10) << left << theThanhVien;
            cout << setw(15) << left << thoiGian;
            cout << setw(15) << left << nguoiDiChung;
        }

        void TieuDe(){
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(10) << left << "Ma KH";
            cout << setw(20) << left << "Ten KH";
            cout << setw(20) << left << "So dien thoai";
            cout << setw(25) << left << "Email";
            cout << setw(10) << left << "Loai";
            cout << setw(10) << left << "The TV";
            cout << setw(15) << left << "Thoi gian o";
            cout << setw(15) << left << "Nguoi di cung" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }

        void NhapThongTin(int id, int loai){
            cout << "====================================";
            cout << "\nVui long nhap thong tin khach hang!!\n"; 
            maKh = id;
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin,ten);
            cout << "----------------\n";
            cout << "So dien thoai: ";
            getline(cin,dienThoai);
            cout << "----------------\n";
            cout << "Email: ";
            getline(cin,email);
            if(loai == 1) this->loai = "CN";
            else if(loai == 2) this->loai = "GD";
            else this->loai = "DN";
            cout << "----------------\n";
            cout << "The thanh vien: " << endl;
            cout << "1. Co" << endl;
            cout << "2. Khong" << endl;
            int TTV;
            cin >> TTV;
            if(TTV == 1) theThanhVien = "C";
            else theThanhVien = "K";
            cout << "----------------\n";
            cout << "Thoi gian o: ";
            cin >> thoiGian;
            cout << "----------------\n";
            cout << "So nguoi di chung: ";
            cin >> nguoiDiChung;
        }

        int GetMaKh(){
            return maKh;
        }

        string GetTen(){
            return ten;
        }

        int GetThoiGian(){
            return thoiGian;
        }

        string GetTheThanhVien(){
            return theThanhVien;
        }

        int GetNguoiDiChung(){
            return nguoiDiChung;
        }

        string GetDienThoai(){
            return dienThoai;
        }

        string GetLoai(){
            return loai;
        }
};

class CaNhan : public KhachHang{
    public:
        // Voi ca nhan khong co nguoi di chung
        // nen phi = 0
        int PhiDiKem(){
            return 0;
        }
};

class GiaDinh : public KhachHang{
    public:
        // Voi gia dinh moi nguoi di chung se them phi 100k
        int PhiDiKem(){
            return 100000 * nguoiDiChung;
        }
};

class DoanhNghiep : public KhachHang{
    public:
        // Voi doanh nghiep moi nguoi di chung se them phi 150k
        int PhiDiKem(){
            return 150000 * nguoiDiChung;
        }
};

class HoaDon{
    private:
        int maPhong, tongTien = 0;
        string tenKhachHang;

    public:
        void SetTongTien(int tongTien){
            this->tongTien = tongTien;
        }

        int GetTongTien(){
            return tongTien;
        }
};

class QuanLy{
    private:
        vector <Phong*> qlp;
        vector <KhachHang*> kh;
        HoaDon hd;

    public:
        void NhapThongTinPhong(){
            ifstream file;
			file.open("Room.csv");

            if(file.is_open()){
				int tong, n, m, k, j;
				file >> tong;
                qlp.resize(tong);
                file >> n; file >> m; file >> k; file >> j;
                file.ignore(2, '\n');
                for(int i = 0; i < n; i++)
                    qlp[i] = new SingleBed();
                for(int i = n; i < n + m; i++)
                    qlp[i] = new DoubleBed();
                for(int i = n + m; i < n + m + k; i++)
                    qlp[i] = new QueenSizeBed();
                for(int i = n + m + k; i < n + m + k + j; i++)
                    qlp[i] = new KingSizeBed();
                for(int i = 0; i < qlp.size(); i++)
                    qlp[i]->docFile(file);
				file.close();
				cout << "Doc file thanh cong \n";
			}
			else cout << "File khong mo duoc\n";
        }

        void InDanhSachPhong(){
            qlp[0]->TieuDe();
            for(int i = 0; i < qlp.size(); i++){
                qlp[i]->InThongTin();
                cout << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            system("pause");
        }

        void XuatDanhSachPhong(){
			ofstream file;
			
			file.open("Room.txt");

			if(file.is_open()){
				file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
                file << setw(15) << left << "So phong";
                file << setw(20) << left << "Loai phong";
                file << setw(20) << left << "Tinh trang";
                file << setw(20) << left << "Huong phong";
                file << setw(20) << left << "Dich vu";
                file << setw(25) << left << "Chu phong";
                file << setw(20) << left << "Tien phong" << endl;
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				for(int i = 0; i < qlp.size(); i++){
					qlp[i]->XuatFile(file);
                    file << endl;
				}
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				file.close();
				cout << "Ghi file thanh cong" << endl;
			}
			else cout << "File khong mo duoc" << endl;
		}

        void TimKiemPhong(int check, string name){
            system("cls");
            if(check == 1){ // Loai phong
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetLoai() == name){
                        qlp[i]->InThongTin();
                        cout << endl;
                    }
                } 
                system("pause");
            }

            if(check == 2){ // Tinh trang
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetTinhTrang() == name){
                        qlp[i]->InThongTin();
                        cout << endl;
                    }
                }
                system("pause");
            }
            if(check == 3){ // huong phong
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetHuongPhong() == name){
                        qlp[i]->InThongTin();
                        cout << endl;
                    }
                }
                system("pause");
            }
        }

        void NhapThongTinKhachHang(){
            ifstream file;
			file.open("Guest.csv");

            if(file.is_open()){
				int tong, n, m, k;
				file >> tong;
                kh.resize(tong);
                file >> n; file >> m; file >> k;
                file.ignore(2, '\n');
                for(int i = 0; i < n; i++)
                    kh[i] = new CaNhan();
                for(int i = n; i < n + m; i++)
                    kh[i] = new GiaDinh();
                for(int i = n + m; i < n + m + k; i++)
                    kh[i] = new DoanhNghiep();
                for(int i = 0; i < kh.size(); i++)
                    kh[i]->docFile(file);
				file.close();
				cout << "Doc file thanh cong \n";
			}
			else cout << "File khong mo duoc\n";
        }

        void InDanhSachKhachHang(){
            kh[0]->TieuDe();
            for(int i = 0; i < kh.size(); i++){
                kh[i]->InThongTin();
                cout << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            system("pause");
        }

        void XuatDanhSachKhachHang(){
			ofstream file;
			
			file.open("Guest.txt");

			if(file.is_open()){
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
                file << setw(10) << left << "Ma KH";
                file << setw(20) << left << "Ten KH";
                file << setw(20) << left << "So dien thoai";
                file << setw(25) << left << "Email";
                file << setw(10) << left << "Loai";
                file << setw(10) << left << "The TV";
                file << setw(15) << left << "Thoi gian o";
                file << setw(15) << left << "Nguoi di cung" << endl;
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				for(int i = 0; i < kh.size(); i++){
					kh[i]->GhiFile(file);
                    file << endl;
				}
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				file.close();
				cout << "Ghi file thanh cong" << endl;
			}
			else cout << "File khong mo duoc" << endl;
		}

        void ThemKhachHang(int loai){
            KhachHang* khachHang;

            if(loai == 1) khachHang = new CaNhan();
            else if(loai == 2) khachHang = new GiaDinh();
            else khachHang = new DoanhNghiep();

            khachHang->NhapThongTin(kh[kh.size() - 1]->GetMaKh() + 1, loai);

            kh.push_back(khachHang);
        }

        void ThemKhachHangVaoPhong(){
            system("cls");
            TimKiemPhong(2, "X");
            cout << "------------------------------------" << endl;
            cout << "Day la danh sach cac phong con trong" << endl;

            int id;
            cout << "Chon so phong khach hang muon: ";
            cin >> id;

            if(qlp[id - 1]->GetTinhTrang() != "X"){
                cout << "--------------------------------------------\n";
                cout << "Phong da co khach vui long chon phong khac!!\n";
                return;
            }

            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetSoPhong() == id){
                    qlp[i]->SetTinhTrang("Da dat");

                    system("cls");
                    cout << "==== Chon dich vu ===" << endl;
                    cout << "1. Khong" << endl;
        		    cout << "2. An uong" << endl;
        		    cout << "3. Don dep" << endl;
                    cout << "4. Giat ui" << endl;
                    cout << "5. Tron goi" << endl;
                    cout << "=====================" << endl;
                    cout << "Nhap lua chon cua ban: ";

                    int luaChon;
                    cin >> luaChon;

                    if(luaChon == 2) qlp[i]->SetDichVu("An uong");
                    else if(luaChon == 3) qlp[i]->SetDichVu("Don dep");
                    else if(luaChon == 4) qlp[i]->SetDichVu("Giat ui");
                    else if(luaChon == 5) qlp[i]->SetDichVu("Tron goi");

                    int loai;
                    cout << "\n=== Chon loai khach hang ===" << endl;
                    cout << "1. Ca nhan" << endl;
                    cout << "2. Gia dinh" << endl;
                    cout << "3. Doanh nghiep" << endl;
                    cout << "============================" << endl;
                    cout << "Nhap lua chon cua ban: ";

                    cin >> loai;
                    if(loai != 1 && loai != 2 && loai != 3){
                        cout << "Loai khach hang khong hop le!" << endl;
                        break;
                    }
                    ThemKhachHang(loai);

                    qlp[i]->SetChuPhong(kh[kh.size() - 1]->GetTen());

                    cout << "\n------------------------------" << endl;
                    cout << "Da them khach hang thanh cong!" << endl;
                    cout << "------------------------------" << endl;
                }
            }
        }

        void XoaKhachHang(){
            system("cls");
            InDanhSachKhachHang();
            cout << "-------------------------------------" << endl;
            cout << "Day la danh sach khach hang dang o" << endl;
            cout << "Nhap id khach hang muon xoa: ";
            int id;
            cin >> id;

            if(id < 0 || id > kh.size()){
                cout << "-------------------------------\n";
                cout << "Id khach hang khong hop le!!\n";
                cout << "Vui long nhap lai!!\n";
                return;
            }

            string name;
            for(int i = 0; i < kh.size(); i++){
                if(kh[i]->GetMaKh() == id){
                    name = kh[i]->GetTen();
                    delete kh[i];
                    kh.erase(kh.begin() + i);
                } 
            }

            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetChuPhong() == name){
                    qlp[i]->SetTinhTrang("X");
                    qlp[i]->SetDichVu("X");
                    qlp[i]->SetChuPhong("X");
                }
            }

            cout << "------------------------------------------\n";
            cout << "Khach hang da duoc xoa khoi danh sach!!!\n";
        }

        void TinhTongChiPhi(){
            cout << "Danh sach cac phong dang hoat dong:" << endl;
            qlp[0]->TieuDe();
            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetTinhTrang() != "X"){
                    qlp[i]->InThongTin();
                    cout << endl;
                }
            }
            int id;
            cout << "-------------------------------------\n";
            cout << "Nhap so phong ban muon in hoa don: ";
            cin >> id;
            int phiDiKem, thoiGian, nguoiDiChung;
            string theThanhVien, ten, sdt, loai;
            for(int i = 0; i < kh.size(); i++){
                if(kh[i]->GetTen() == qlp[id - 1]->GetChuPhong()){
                    phiDiKem = kh[i]->PhiDiKem();
                    thoiGian = kh[i]->GetThoiGian();
                    nguoiDiChung = kh[i]->GetNguoiDiChung();

                    if(kh[i]->GetTheThanhVien() == "C") theThanhVien = "Co";
                    else theThanhVien = "Khong";

                    ten = kh[i]->GetTen();
                    sdt = kh[i]->GetDienThoai();

                    if(kh[i]->GetLoai() == "CN") loai = "Ca Nhan";
                    else if(kh[i]->GetLoai() == "GD") loai = "Gia Dinh";
                    else loai = "Doanh Nghiep";
                }
            }

            hd.SetTongTien((qlp[id - 1]->TienPhong() + phiDiKem) * thoiGian);
            int tamTinh = hd.GetTongTien();
            int tongTien = hd.GetTongTien();
            int giamGia = 0;

            if(theThanhVien == "Co"){
                if(tongTien >= 10000000){
                    giamGia = tongTien * 0.15;
                    tongTien *= 0.85;
                } 
                else if(tongTien >= 7500000){
                    giamGia = tongTien * 0.1;
                    tongTien *= 0.9;
                } 
            }
            else tongTien = tongTien; 

            system("cls");
            cout << "---------------------------------------------------------------------------------\n";
            cout << setw(50) << right << "HOA DON THANH TOAN\n";
            cout << "---------------------------------------------------------------------------------\n";
            cout << setw(20) << left << "Ten: " << setw(20) << left << qlp[id - 1]->GetChuPhong();
            cout << setw(15) << left << "So phong: " << qlp[id - 1]->GetSoPhong() << endl;
            cout << setw(20) << left << "So dien thoai: " << setw(20) << left << sdt;
            cout << setw(15) << left << "Loai phong: " << qlp[id - 1]->GetLoai() << endl;
            cout << setw(20) << left << "Loai: " << setw(20) << left << loai;
            cout << setw(15) << left << "Huong phong: " << qlp[id - 1]->GetHuongPhong() << endl;
            cout << setw(20) << left << "The thanh vien: " << setw(20) << left << theThanhVien; 
            cout << setw(15) << left << "Dich vu: " << qlp[id - 1]->GetDichVu() << endl;
            cout << setw(20) << left << "Thoi gian o: " << setw(20) << left << thoiGian;
            cout << setw(15) << left << "Gia phong: " << qlp[id - 1]->TienPhong() << " /ngay" << endl;
            cout << setw(20) << left << "Nguoi di kem: " << setw(20) << left << nguoiDiChung;
            cout << setw(15) << left << "Phi di kem: " << phiDiKem << endl;
            cout << "---------------------------------------------------------------------------------\n";
            cout << setw(30) << right << "Tam tinh:" << setw(20) << right << tamTinh << " VND\n";
            cout << setw(30) << right << "Giam gia:" << setw(20) << right << giamGia << " VND\n";
            cout << setw(20) << "" << "-----------------------------------" << endl;
            cout << setw(30) << right << "Tong thu:" << setw(20) << right << tongTien << " VND\n\n\n\n";
            if(theThanhVien == "Co"){
                cout << "Ghi chu: Giam gia vi khach hang co the thanh vien\n\n\n";
            }
            cout << "----- Uu dai neu co the thanh vien -----" << endl;
            cout << "Giam 15% neu tong hoa don tren 10tr" << endl;
            cout << "Giam 10% neu tong hoa don tren 7tr5" << endl;
            cout << "---------------------------------------------------------------------------------\n";
        }

        void ThongKeDoanhThu(){
            int doanhThu = 0;
            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetTinhTrang() != "X"){
                    int phiDiKem, thoiGian;
                    string theThanhVien;
                    for(int j = 0; j < kh.size(); j++){
                        if(kh[j]->GetTen() == qlp[i]->GetChuPhong()){
                            phiDiKem = kh[j]->PhiDiKem();
                            thoiGian = kh[j]->GetThoiGian();
                            theThanhVien = kh[j]->GetTheThanhVien();
                        }
                    }
                    hd.SetTongTien((qlp[i]->TienPhong() + phiDiKem) * thoiGian);
                    if(theThanhVien == "C" && hd.GetTongTien() >= 10000000) doanhThu += (int)(hd.GetTongTien() * 0.85);
                    else if (theThanhVien == "C" && hd.GetTongTien() >= 7500000) doanhThu += (int)(hd.GetTongTien() * 0.9);
                    else doanhThu += hd.GetTongTien();
                }
            }
            cout << "---------------------------------------------------------------------------------\n";
            cout << "Tong doanh thu cua khach san theo cac phong dang hoat dong la: " << doanhThu << " VND" << endl;
            cout << "---------------------------------------------------------------------------------\n";
        }

        void KhachHangTriAn(){
            int max = -1, tmp = 0, id;
            string name;
            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetTinhTrang() != "X"){
                    int phiDiKem, thoiGian;
                    string theThanhVien, nameTemp;
                    for(int j = 0; j < kh.size(); j++){
                        if(kh[j]->GetTen() == qlp[i]->GetChuPhong()){
                            phiDiKem = kh[j]->PhiDiKem();
                            thoiGian = kh[j]->GetThoiGian();
                            theThanhVien = kh[j]->GetTheThanhVien();
                            nameTemp = kh[j]->GetTen();
                        }
                    }
                    hd.SetTongTien((qlp[i]->TienPhong() + phiDiKem) * thoiGian);
                    if(theThanhVien == "C" && hd.GetTongTien() >= 10000000) tmp = (int)(hd.GetTongTien() * 0.85);
                    else if (theThanhVien == "C" && hd.GetTongTien() >= 7500000) tmp = (int)(hd.GetTongTien() * 0.9);
                    else tmp = hd.GetTongTien();
                    if(tmp > max){
                        max = tmp;
                        name = nameTemp;
                        id = i;
                    } 
                }
            }
            cout << "---------------------------------------------------\n";
            cout << "Xin chuc mung khach hang " << name << " phong " << id << endl;
            cout << "Da duoc tri an do co muc thanh toan cao nhat" << endl;
            cout << "---------------------------------------------------\n";
        }
};

class Menu{
    private:
        QuanLy ql;

    public:
        void HienThiMenuPhong() {
            int luaChon;

            do{
                cout << "======= MENU PHONG =======" << endl;
        		cout << "1. Doc danh sach phong" << endl;
        		cout << "2. In danh sach phong" << endl;
        		cout << "3. Xuat danh sach phong" << endl;
                cout << "4. Tim kiem phong" << endl;
        		cout << "5. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        ql.NhapThongTinPhong();
                        break;
                    }

                    case 2: {
                        system("cls");
                        ql.InDanhSachPhong();
                        system("cls");
                        break;
                    }


                    case 3: {
                        system("cls");
                        ql.XuatDanhSachPhong();
                        break;
                    }

                    case 4: {
                        system("cls");
                        int timKiem;
                            cout << "=== Tim kiem theo ===" << endl;
                            cout << "1. Loai Phong" << endl;
        		            cout << "2. Tinh trang" << endl;
        		            cout << "3. Huong phong" << endl;
                            cout << "4. Thoat" << endl;
                            cout << "=====================" << endl;
                            cout << "Nhap lua chon cua ban: ";

                            cin >> timKiem;
                            switch(timKiem) {
                                case 1: {
                                    system("cls");
                                    int loaiPhong;
                                    cout << "=== Chon loai phong ===" << endl;
                                    cout << "1. Single Bed" << endl;
        		                    cout << "2. Double Bed" << endl;
        		                    cout << "3. Queen Size Bed" << endl;
                                    cout << "4. King Size Bed" << endl;
                                    cout << "=======================" << endl;
                                    cout << "Nhap lua chon cua ban: ";

                                    cin >> loaiPhong;

                                    switch(loaiPhong) {
                                        case 1:
                                            ql.TimKiemPhong(1, "Single bed");
                                            system("cls");
                                            break;
                                        
                                        case 2:
                                            ql.TimKiemPhong(1, "Double bed");
                                            system("cls");
                                            break;
                                        
                                        case 3:
                                            ql.TimKiemPhong(1, "Queen size bed");
                                            system("cls");
                                            break;
                                        
                                        case 4:
                                            ql.TimKiemPhong(1, "King size bed");
                                            system("cls");
                                            break;
                                        
                                        default:
                                            cout << "Khong hop le !!!";
                                            system("cls");
                                            break;
                                    }
                                }
                                break;

                                case 2: {
                                    system("cls");
                                    int tinhTrang;
                                    cout << "=== Trang thai phong ===" << endl;
                                    cout << "1. Phong trong" << endl;
                                    cout << "2. Da dat" << endl;
                                    cout << "3. Dang su dung" << endl;
                                    cout << "========================" << endl;
                                    cout << "Nhap lua chon cua ban: ";

                                    cin >> tinhTrang;
                                    switch(tinhTrang) {
                                        case 1:
                                            ql.TimKiemPhong(2, "X");
                                            system("cls");
                                            break;

                                        case 2:
                                            ql.TimKiemPhong(2, "Da dat");
                                            system("cls");
                                            break;

                                        case 3:
                                            ql.TimKiemPhong(2, "Dang su dung");
                                            system("cls");
                                            break;
                                        
                                        default:
                                            cout << "Khong hop le !!!";
                                            system("cls");
                                            break;
                                    }
                                }
                                break;

                                case 3: {
                                    system("cls");
                                    int huongPhong;
                                    cout << "=== Chon huong phong ===" << endl;
                                    cout << "1. Tieu chuan" << endl;
                                    cout << "2. Huong nui" << endl;
                                    cout << "3. Huong bien" << endl;
                                    cout << "========================" << endl;
                                    cout << "Nhap lua chon cua ban: ";

                                    cin >> huongPhong;

                                    switch(huongPhong) {
                                        case 1:
                                            ql.TimKiemPhong(3, "Tieu chuan");
                                            system("cls");
                                            break;
                                        
                                        case 2:
                                            ql.TimKiemPhong(3, "Huong nui");
                                            system("cls");
                                            break;

                                        case 3:
                                            ql.TimKiemPhong(3, "Huong bien");
                                            system("cls");
                                            break;

                                        default:
                                            cout << "Khong hop le !!!";
                                            system("cls");
                                            break;
                                    }
                                }
                                break;

                                case 4:
                                    system("cls");
                                    break;

                                default:
                                    cout << "Lua chon khong hop le !!!" << endl;
                                    system("pause");
                                    system("cls");
                                    break;
                            }
                    }
                    break;

                    case 5:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 5);
        }

        void HienThiMenuKhach(){
            int luaChon;

            do{
                cout << "======== MENU KHACH ========" << endl;
        		cout << "1. Doc danh sach khach hang" << endl;
        		cout << "2. In danh sach khach hang" << endl;
        		cout << "3. Xuat danh sach khach hang" << endl;
                cout << "4. Them khach hang" << endl;
                cout << "5. Xoa khach hang" << endl;
        		cout << "6. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        ql.NhapThongTinKhachHang();
                        break;
                    }

                    case 2: {
                        system("cls");
                        ql.InDanhSachKhachHang();
                        system("cls");
                        break;
                    }

                    case 3: {
                        system("cls");
                        ql.XuatDanhSachKhachHang();
                        break;
                    }

                    case 4:{
                        system("cls");
                        ql.ThemKhachHangVaoPhong();
                        break;
                    }

                    case 5:
                        system("cls");
                        ql.XoaKhachHang();
                        break;

                    case 6:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 6);
        }

        void HienThiMenuHoaDon(){
            int luaChon;

            do{
                cout << "====== MENU HOA DON ======" << endl;
        		cout << "1. In hoa don cua khach hang" << endl;
        		cout << "2. Thong ke doanh thu tong" << endl;
                cout << "3. Tim ra khach hang tri an" << endl;
        		cout << "4. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        ql.TinhTongChiPhi();
                        break;
                    }

                    case 2: {
                        system("cls");
                        ql.ThongKeDoanhThu();
                        break;
                    }

                    case 3: {
                        system("cls");
                        ql.KhachHangTriAn();
                        break;
                    }

                    case 4:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 4);
        }

        void MenuTong(){
            int luaChon;

            // Load database 
            ql.NhapThongTinPhong();
            ql.NhapThongTinKhachHang();

            system("cls");

            do{
                cout << "========== MENU ==========" << endl;
        		cout << "1. Thao tac voi phong" << endl;
        		cout << "2. Thao tac voi khach hang" << endl;
                cout << "3. Thao tac voi hoa don" << endl;
        		cout << "4. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        HienThiMenuPhong();
                        break;
                    }

                    case 2: {
                        system("cls");
                        HienThiMenuKhach();
                        break;
                    }

                    case 3:{
                        system("cls");
                        HienThiMenuHoaDon();
                        break;
                    }

                    case 4:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 4);
        }
};

int main(){
    system("cls");
    Menu menu;
    menu.MenuTong();
}