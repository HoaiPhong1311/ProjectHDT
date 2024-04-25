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

        virtual void out() = 0;

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

        long PhiPhuThu(){
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

        void InThongTin(){
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

        string GetTinhTrang(){
            return tinhTrang;
        }

        string GetHuongPhong(){
            return huongPhong;
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

        void out(){
            InThongTin();
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

        void out(){
            InThongTin();
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

        void out(){
            InThongTin();
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

        void out(){
            InThongTin();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class QuanLyPhong{
    private:
        vector <Phong*> qlp;

    public:
        void NhapThongTin(){
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
			else cout << "\nFile khong mo duoc";
        }

        void out(){
            qlp[0]->TieuDe();
            for(int i = 0; i < qlp.size(); i++){
                qlp[i]->out();
                cout << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }

        void XuatDanhSach(){
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
				cout << "\nGhi file thanh cong" << endl;
			}
			else cout << "\nFile khong mo duoc" << endl;
		}

        void TimKiemPhong(string check, string name){
            if(check == "Loai phong"){
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetLoai() == name){
                        qlp[i]->out();
                        cout << endl;
                    }
                } 
            }
            if(check == "Tinh trang"){
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetTinhTrang() == name){
                        qlp[i]->out();
                        cout << endl;
                    }
                }
            }
            if(check == "Huong phong"){
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetHuongPhong() == name){
                        qlp[i]->out();
                        cout << endl;
                    }
                }
            }
        }
};

int main(){
    system("cls");
    QuanLyPhong ql;
    ql.NhapThongTin();
    ql.out();
    ql.XuatDanhSach();
    ql.TimKiemPhong("Loai phong", "Double bed");
}