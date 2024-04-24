#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

class DocGia{
    protected:
        string hoTen, loai;

    public:
        virtual long TienPhaiTra() = 0;

        virtual void docFile(ifstream &file) = 0;

        virtual void InThongTin() = 0;

        virtual void NhapThongTin() = 0;

        virtual void GhiFile(ofstream &file) = 0;
};

class NguoiLon : public DocGia{
    private:
        int thang;

    public:
        long TienPhaiTra(){
            return thang * 100000;
        }

        void docFile(ifstream &file){
			getline(file,hoTen, ',');
            getline(file,loai, ',');
            file >> thang;
            file.ignore();
        }

        void InThongTin(){
            cout << setw(15) << left << hoTen << "\t";
            cout << loai << "\t";
            cout << thang << "\t\t";
            cout << TienPhaiTra() << endl;
        }

        void NhapThongTin(){
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin,hoTen);
            loai = "NgLon";
            cout << "Thang: ";
            cin >> thang;
        }

        void GhiFile(ofstream &file){
			file << setw(16) << left << hoTen;
			file << loai << "\t";
            file << thang << "\t\t\t\t";
            file << TienPhaiTra() << endl;
		}
};

class TreEm : public DocGia{
    private:
        int tuoi;

    public:
        long TienPhaiTra(){
            return tuoi * 20000;
        }

        void docFile(ifstream &file){
            getline(file,hoTen, ',');
            getline(file,loai, ',');
            file >> tuoi;
            file.ignore();
        }

        void InThongTin(){
            cout << setw(15) << left << hoTen << "\t";
            cout << loai << "\t\t";
            cout << tuoi << "\t";
            cout << TienPhaiTra() << endl;
        }

        void NhapThongTin(){
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin,hoTen);
            loai = "TreE";
            cout << "Tuoi: ";
            cin >> tuoi;
        }

        void GhiFile(ofstream &file){
			file << setw(16) << left << hoTen;
			file << loai << "\t\t\t";
            file << tuoi << "\t\t";
            file << TienPhaiTra() << endl;
		}
};

class NguoiGia : public DocGia{
    public:
        long TienPhaiTra(){
            return 0;
        }

        void docFile(ifstream &file){
            getline(file,hoTen, ',');
            getline(file,loai, ',');
        }

        void InThongTin(){
            cout << setw(15) << left << hoTen << "\t";
            cout << loai << "\t\t\t";
            cout << TienPhaiTra() << endl;
        }

        void NhapThongTin(){
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin,hoTen);
            loai = "NgGia";
        }

        void GhiFile(ofstream &file){
			file << setw(16) << left << hoTen;
			file << loai << "\t\t\t\t\t";
            file << TienPhaiTra() << endl;
		}
};

class QuanLyDocGia{
    private:
        vector <DocGia*> ds;

    public:
        int GetSoLuong(){
            return ds.size();
        }

        void nhapThongTin(){
			ifstream file;
			file.open("thuVien.csv");

			if(file.is_open()){
				int tong, n, m, k;
				file >> tong;
				ds.resize(tong);
				file >> n;
				file >> m;
                file >> k;
                file.ignore(2, '\n');
                for(int i = 0; i < n; i++){
					ds[i] = new NguoiLon();
				}
				for(int i = n; i < n + m; i++){
					ds[i] = new TreEm();
				}
                for(int i = n + m; i < n + m + k; i++){
					ds[i] = new NguoiGia();
				}
				for(int i = 0; i < n + m + k; i++){
					ds[i]->docFile(file);
				}
				file.close();
				cout << "Doc file thanh cong \n";
			}
			else cout << "\nFile khong mo duoc";
		}

        void out(){
            cout << "Ten\t\tLoai\tThang\tTuoi\tTienPhaiTra" << endl;
            for(int i = 0; i < ds.size(); i++){
                ds[i]->InThongTin();
            }
        }

        void ThemDocGia(int k, int loai){
            DocGia* docGia;

            if(loai == 1) docGia = new NguoiLon();
            else if(loai == 2) docGia = new TreEm();
            else docGia = new NguoiGia();

            docGia->NhapThongTin();

            ds.insert(ds.begin() + k, docGia);

            cout << "Da them doc gia thanh cong!" << endl;
        }

        void XoaDocGia(int k){
            delete ds[k];
            ds.erase(ds.begin() + k);

            cout << "Da xoa doc gia thanh cong!" << endl;
        }

        void SapXepTienTangDan(){
			int n = ds.size();

			for(int i = 0; i < n - 1; i++){
				int idx = i;
				for(int j = i + 1; j < n; j++){
					long tmp1 = ds[idx]->TienPhaiTra();
					long tmp2 = ds[j]->TienPhaiTra();

					if(tmp1 > tmp2) idx = j;
				}
				if(idx != i) swap(ds[i], ds[idx]);
			}
		}

        void TimKiemDocGia(){
            SapXepTienTangDan();

            cout << endl << "Doc gia dong tien nhieu nhat" << endl;
            cout << "Ten\t\tLoai\tThang\tTuoi\tTienPhaiTra" << endl;
            ds[ds.size() - 1]->InThongTin();
        }

        void LietKe(){
            SapXepTienTangDan();

            long tongTien = 0;
            for(int i = 0; i < ds.size(); i++)
                tongTien += ds[i]->TienPhaiTra();

            float tienTb = (tongTien * 1.0) / ds.size();

            cout << endl << "Tien phi trung binh: " << fixed << setprecision(2) << tienTb << endl; 
            cout << "Danh sach nhung nguoi dong phi nhieu" << endl;
            cout << "Ten\t\tLoai\tThang\tTuoi\tTienPhaiTra" << endl;
            for(int i = 0; i < ds.size(); i++){
                if(ds[i]->TienPhaiTra() > tienTb) ds[i]->InThongTin();
            }
        }

        void XuatDanhSach(){
			ofstream file;
			
			file.open("danhSachSV.txt");

			if(file.is_open()){
				file << "Ten\t\t\t\tLoai\tThang\tTuoi\tTienPhaiTra" << endl;
				for(int i = 0; i < ds.size(); i++){
					ds[i]->GhiFile(file);
				}
				file.close();
				cout << "\nGhi file thanh cong" << endl;
			}
			else cout << "\nFile khong mo duoc" << endl;
		}

};

class Menu{
    private:
        QuanLyDocGia qldg;

    public:
        void hienThiMenu(){
            int luaChon;
            do{
                cout << "========== MENU ==========" << endl;
        		cout << "1. Doc danh sach doc gia" << endl;
        		cout << "2. Xuat danh sach doc gia" << endl;
        		cout << "3. Them mot doc gia" << endl;
                cout << "4. Xoa mot doc gia" << endl;
                cout << "5. Doc gia dong tien nhieu nhat" << endl;
                cout << "6. Nhung doc gia dong phi cao" << endl; 
                cout << "7. Sap xep theo tong tien tang dan" << endl;
                cout << "8. Ghi danh sach vao file .txt" << endl;
        		cout << "9. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1:
                        qldg.nhapThongTin();
                        break;

                    case 2:
                        qldg.out();
                        break;

                    case 3: {
                        int loai, viTri;
                        cout << endl;
                        cout << "== Chon loai doc gia ==" << endl;
                        cout << "1. Nguoi lon" << endl;
        		        cout << "2. Tre em" << endl;
        		        cout << "3. Nguoi gia" << endl;
                        cout << "Nhap lua chon cua ban: ";
                        cin >> loai;
                        if(loai != 1 && loai != 2 && loai != 3){
                            cout << "Loai doc gia khong hop le!" << endl;
                            break;
                        }

                        cout << "Nhap vi tri can chen: ";
                        cin >> viTri;
                        if(viTri < 0 || viTri > qldg.GetSoLuong()){
                            cout << "Vi tri chen khong hop le!" << endl;
                            break;
                        }

                        qldg.ThemDocGia(viTri, loai);
                        break;
                    }

                    case 4: {
                        int viTri;
                        cout << endl;
                        cout << "Chon vi tri doc gia muon xoa: ";
                        cin >> viTri;
                        if(viTri < 0 || viTri > qldg.GetSoLuong()){
                            cout << "Vi tri chon khong hop le!" << endl;
                            break;
                        }

                        qldg.XoaDocGia(viTri);
                        break;
                    }

                    case 5:
                        qldg.TimKiemDocGia();
                        break;

                    case 6:
                        qldg.LietKe();
                        break;

                    case 7:
                        qldg.SapXepTienTangDan();
                        cout << "Danh sach da duoc sap xep lai!" << endl;
                        break;

                    case 8:
                        qldg.XuatDanhSach();
                        break;

                    case 9:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 9);
        }
};

int main(){
    system("cls");
    Menu menu;
    menu.hienThiMenu();
}