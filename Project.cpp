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
        void docFile(ifstream &file){
            file >> soPhong;
            file.ignore();
            getline(file,loai, ',');
            getline(file,tinhTrang, ',');
            getline(file,huongPhong, ',');
            getline(file,dichVu, ',');
            getline(file,chuPhong, ',');
        }
        // void GhiFile(ofstream &file)
        long PhiPhuThu(){
            int soTien = 0;
            const int HUONG_NUI = 500000;
            const int HUONG_BIEN = 750000;
            const int HUONG_THUONG = 0;

            if(huongPhong == "Huong nui") soTien = HUONG_NUI;
            else if(huongPhong == "Huong bien") soTien = HUONG_BIEN;
            else soTien = HUONG_THUONG;

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
            cout << soPhong << "\t" << loai << "\t" << tinhTrang << "\t" << huongPhong << "\t" << dichVu << "\t" << chuPhong << "\t";
        }
};

class SingleBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 1000000; // Gia goc cua phong Single Bed
            return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong();
        }
};

class DoubleBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 2000000; // Gia goc cua phong Single Bed
            return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong();
        }
};

class QueenSizeBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 4000000; // Gia goc cua phong Single Bed
            return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong();
        }
};

class KingSizeBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 5500000; // Gia goc cua phong Single Bed
            return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong();
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
            for(int i = 0; i < qlp.size(); i++)
                qlp[i]->InThongTin();
                cout << endl;
        }
};

int main(){
    system("cls");
    QuanLyPhong ql;
    ql.NhapThongTin();
    ql.out();
}