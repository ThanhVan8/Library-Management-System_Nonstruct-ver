#include <iostream>
#include <iomanip>
#include <string>
#include "docgia.h"
#include "thoigian.h"

using namespace std;

// Chuc nang: Xuat danh sach doc gia trong thu vien
// Tham so truyen vao:	
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						(MAXRD: so dong toi da tuong ung voi so doc gia toi da cua ma tran;
//						 MAXCD: 9 cot cua ma tran gom ma doc gia, ho ten, cmnd, ngay sinh, gioi tinh, email, dia chi, ngay lap the, ngay het han)
//						int n: so dong cua ma tran
// Gia tri tra ve: (khong co)
void XuatDSDocGia(string a[MAXRD][MAXCD], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAXCD; j++) {
			switch (j)
			{
			case 0: case 2: case 3: case 4: case 7:
				cout << setw(15) << left;
				break;
			case 1: case 5: case 6:
				cout << setw(25) << left;
				break;
			default:
				break;
			}
			cout << a[i][j];
		}
		cout << endl;
	}
}

// Chuc nang: Them 1 doc gia vao danh sach hien tai
// Tham so truyen vao:	
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int& n: so dong cua ma tran (sau khi them doc gia thi so dong cua ma tran se tang len)
// Gia tri tra ve: (khong co)
void ThemDocGia(string a[MAXRD][MAXCD], int &n) {
	n++;
	cin.ignore();
	for (int j = 0; j < MAXCD - 2; j++) {
		switch (j)
		{
		case 0:
			cout << "Ma doc gia: ";
			break;
		case 1:
			cout << "Ho ten: ";
			break;
		case 2:
			cout << "CMND: ";
			break;
		case 3:
			cout << "Ngay sinh (Nhap rieng tung gia tri)\n";
			break;
		case 4:
			cout << "Gioi tinh (Nam/Nu): ";
			break;
		case 5:
			cout << "Email: ";
			break;
		case 6:
			cout << "Dia chi: ";
			break;
		default:
			break;
		}
		if (j == 3) {
			int dB, mB, yB;
			NhapNgay(dB, mB, yB);
			cin.ignore();
			a[n - 1][j] = ChuyenThanhChuoiKyTuNgay(dB, mB, yB);
		}
		else {
			getline(cin, a[n - 1][j]);
		}
	}

	int day, month, year;
	cout << "Ngay lap the (Nhap rieng tung gia tri)\n";
	NhapNgay(day, month, year);
	a[n - 1][7] = ChuyenThanhChuoiKyTuNgay(day, month, year);
	a[n - 1][8] = ChuyenThanhChuoiKyTuNgay(day, month, year + 4);
}

// Chuc nang: Tim vi tri cua doc gia theo ma doc gia
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						string x: ma doc gia
// Gia tri tra ve:
//						chi so dong chua ma doc gia		neu ma doc gia duoc tim thay
//						-1								neu ma doc gia khong duoc tim thay
int ViTriDocGiaTheoMaDocGia(string a[MAXRD][MAXCD], int n, string x) {
	for (int i = 1; i < n; i++) {
		if (x == a[i][0]) {
			return i;
		}
	}
	return -1;
}

// Chuc nang: Kiem tra ma doc gia co hop le khong (co nam trong ma tran quan ly doc gia khong)
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						string x: ma doc gia
// Gia tri tra ve:
//						0			neu vi tri chua ma doc gia = -1 (khong tim thay)
//						1			neu vi tri chua ma doc gia khac 0 (duoc tim thay)
bool KiemTraMaDocGia(string a[MAXRD][MAXCD], int n, string x) {
	if (ViTriDocGiaTheoMaDocGia(a, n, x) == -1) {
		return 0;
	}
	return 1;
}

// Chuc nang: Nhap ma doc gia (trong do kiem tra ma doc gia co dung voi ma tran quan ly doc gia hay khong)
// Tham so truyen vao:		
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
// Gia tri tra ve:
//						""						neu nguoi dung nhap sai ma khong muon nhap lai
//						string x: ma doc gia	neu nguoi dung nhap ma doc gia hop le
string NhapMaDocGia(string a[MAXRD][MAXCD], int n) {
	string x;
	bool retype = 1;
	bool valid = 1;
	do {
		if (!valid) {
			cout << "Ma doc gia khong ton tai! Ban co muon nhap lai? (Co -> chon 1; Khong -> chon 0) ";
			cin >> retype;
			if (!retype) {
				return "";
			}
		}
		cout << "Nhap ma doc gia: ";
		cin >> x;
		valid = 0;
	} while (!KiemTraMaDocGia(a, n, x));
	return x;
}

// Chuc nang: Chinh sua thong tin cua doc gia theo ma doc gia duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						string x: ma doc gia
// Gia tri tra ve: (khong co)
void ChinhSuaDocGia(string a[MAXRD][MAXCD], int n, string x) {
	int index = ViTriDocGiaTheoMaDocGia(a, n, x);

	bool edit;
	cout << "(Sua -> chon 1; Khong sua -> chon 0)\n";
	
	for (int i = 0; i < 8; i++) {
		switch (i)
		{
		case 0:
			cout << "Ma doc gia - ";
			break;
		case 1:
			cout << "Ho ten - ";
			break;
		case 2:
			cout << "CMND - ";
			break;
		case 3:
			cout << "Ngay sinh - ";
			break;
		case 4:
			cout << "Gioi tinh (Nam/Nu) - ";
			break;
		case 5:
			cout << "Email - ";
			break;
		case 6:
			cout << "Dia chi - ";
			break;
		case 7:
			cout << "Ngay lap the - ";
			break;
		}
		cin >> edit;
		if (edit) {
			cout << "Thong tin cu: " << a[index][i] << endl;
			cout << "Nhap thong tin moi: ";
			if (i == 7) {
				int day, month, year;
				cout << "(Nhap rieng tung gia tri)\n";
				NhapNgay(day, month, year);
				a[index][7] = ChuyenThanhChuoiKyTuNgay(day, month, year);
				a[index][8] = ChuyenThanhChuoiKyTuNgay(day, month, year + 4);
			}
			else if (i == 3) {
				int day, month, year;
				cout << "(Nhap rieng tung gia tri)\n";
				NhapNgay(day, month, year);
				a[index][3] = ChuyenThanhChuoiKyTuNgay(day, month, year);
			}
			else {
				cin.ignore();
				getline(cin, a[index][i]);
			}
		}
	}
}

// Chuc nang: Xoa thong tin cua doc gia theo ma doc gia duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int& n: so dong cua ma tran (sau khi xoa 1 doc gia thi so dong se giam di 1)
//						string x: ma doc gia
// Gia tri tra ve: (khong co)
void XoaDocGia(string a[MAXRD][MAXCD], int& n, string x) {
	int index = ViTriDocGiaTheoMaDocGia(a, n, x);
	for (int i = index + 1; i < n; i++) {
		for (int j = 0; j < MAXCD; j++) {
			a[i - 1][j] = a[i][j];
		}
	}
	n--;
}

// Chuc nang: Xuat 1 dong tu ma tran quan ly doc gia
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						int x: chi so dong muon xuat ra
// Gia tri tra ve: (khong co)
void XuatDongDSDocGia(string a[MAXRD][MAXCD], int n, int x) {
	for (int i = 0; i < MAXCD; i++) {
		switch (i)
		{
		case 0: case 2: case 3: case 4: case 7:
			cout << setw(15) << left;
			break;
		case 1: case 5: case 6:
			cout << setw(25) << left;
			break;
		default:
			break;
		}
		cout << a[x][i];
	}
}

// Chuc nang: Tim thong tin cua doc gia theo CMND duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						string x: chuoi ky tu so CMND
// Gia tri tra ve:
//						vi tri dong chua CMND		neu CMND duoc tim thay (hop le)
//						-1							neu CMND khong duoc tim thay (khong hop le)
int TimDocGiaTheoCMND(string a[MAXRD][MAXCD], int n, string x) {
	for (int i = 1; i < n; i++) {
		if (a[i][2] == x) {
			return i;
		}
	}
	return -1;
}

// Chuc nang: Tim thong tin cua doc gia theo ho ten duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						string x: ho ten cua doc gia
// Gia tri tra ve:
//						vi tri dong chua ho ten		neu ho ten duoc tim thay (hop le)
//						-1							neu ho ten khong duoc tim thay (khong hop le)
int TimDocGiaTheoHoTen(string a[MAXRD][MAXCD], int n, string x) {
	for (int i = 1; i < n; i++) {
		if (a[i][1] == x) {
			return i;
		}
	}
	return -1;
}

// Chuc nang: Dem tong so doc gia theo gioi tinh
// Tham so truyen vao:
//						string a[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int n: so dong cua ma tran
//						string x: gioi tinh ("Nam"/"Nu")
// Gia tri tra ve:
//						int s: tong so doc gia theo gioi tinh
int DemDocGiaTheoGioiTinh(string a[MAXRD][MAXCD], int n, string x) {
	int s = 0;
	for (int i = 1; i < n; i++) {
		if (a[i][4] == x) {
			s++;
		}
	}
	return s;
}
