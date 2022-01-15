#include <iostream>
#include <iomanip>
#include <string>
#include "sach.h"
#include "phieusach.h"

// Chuc nang: Xuat danh sach cac sach co trong thu vien
// Tham so truyen vao:	
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						(MAXRS: so dong toi da tuong ung voi so sach toi da cua ma tran;
//						 MAXCS: 8 cot cua ma tran gom ISBN, ten sach, tac gia, nha xuat ban, nam xuat ban, the loai, gia sach, so quyen)
//						int h: so dong cua ma tran
// Gia tri tra ve: (khong co)
void XuatDSSach(string a[MAXRS][MAXCS], int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < MAXCS; j++) {
			switch (j)
			{
			case 0: case 4: case 6:
				cout << setw(15) << left;
				break;
			case 1: case 2: case 3:
				cout << setw(30) << left;
				break;
			case 5:
				cout << setw(20) << left;
				break;
			default:
				break;
			}
			cout << a[i][j];
		}
		cout << endl;
	}
}

// Chuc nang: Them 1 sach vao thu vien
// Tham so truyen vao:	
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int& h: so dong cua ma tran (sau khi them sach thi so dong cua ma tran se tang len)
// Gia tri tra ve: (khong co)
void ThemSach(string a[MAXRS][MAXCS], int& h) {
	cin.ignore();
	for (int i = 0; i < MAXCS; i++) {
		switch (i)
		{
		case 0:
			cout << "ISBN: ";
			break;
		case 1:
			cout << "Ten sach: ";
			break;
		case 2:
			cout << "Tac gia: ";
			break;
		case 3:
			cout << "Nha xuat ban: ";
			break;
		case 4:
			cout << "Nam xuat ban: ";
			break;
		case 5:
			cout << "The loai: ";
			break;
		case 6:
			cout << "Gia sach: ";
			break;
		case 7:
			cout << "So quyen: ";
			break;
		}
		getline(cin, a[h][i]);
		if (i == 0) {
			int add, index;
			if (KiemTraISBN(a, h, a[h][i])) {
				cout << "Sach dang co trong thu vien.\nNhap so luong muon them: ";
				cin >> add;
				index = ViTriSachTheoISBN(a, h, a[h][i]);
				int quant = stoi(a[index][7]);
				quant = quant + add;
				a[index][7] = to_string(quant);
				cin.ignore();
				return;
			}
		}
	}
	h++;
}

// Chuc nang: Tim vi tri cua sach theo ISBN
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
//						string x: ISBN
// Gia tri tra ve:
//						chi so dong chua ISBN			neu ISBN duoc tim thay
//						-1								neu ISBN khong duoc tim thay
int ViTriSachTheoISBN(string a[MAXRS][MAXCS], int h, string x) {
	for (int i = 1; i < h; i++) {
		if (x == a[i][0]) {
			return i;
		}
	}
	return -1;
}

// Chuc nang: Kiem tra ISBN co hop le khong (co nam trong ma tran quan ly sach khong)
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
//						string x: ISBN
// Gia tri tra ve:
//						0			neu vi tri chua ISBN = -1 (khong tim thay)
//						1			neu vi tri chua ISBN khac 0 (duoc tim thay)
bool KiemTraISBN(string a[MAXRS][MAXCS], int h, string x) {
	if (ViTriSachTheoISBN(a, h, x) == -1) {
		return 0;
	}
	return 1;
}

// Chuc nang: Nhap ISBN (trong do kiem tra ISBN co dung voi ma tran quan ly sach da nhap vao hay khong)
// Tham so truyen vao:		
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
// Gia tri tra ve:
//						""						neu nguoi dung nhap sai ma khong muon nhap lai
//						string x: ma doc gia	neu nguoi dung nhap ISBN hop le
string NhapISBN(string a[MAXRS][MAXCS], int h) {
	string x;
	bool retype = 1;
	bool valid = 1;
	do {
		if (!valid) {
			cout << "ISBN khong ton tai! Ban co muon nhap lai? (Co -> chon 1; Khong -> chon 0) ";
			cin >> retype;
			if (!retype) {
				return "";
			}
		}
		cout << "Nhap ISBN: ";
		cin >> x;
		valid = 0;
	} while (!KiemTraISBN(a, h, x));
	return x;
}

// Chuc nang: Chinh sua thong tin cua sach theo ISBN duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
//						string x: ISBN
// Gia tri tra ve: (khong co)
void ChinhSuaSach(string a[MAXRS][MAXCS], int h, string x) {
	int index = ViTriSachTheoISBN(a, h, x);

	bool edit;
	cout << "(Sua -> chon 1; Khong sua -> chon 0)\n";

	for (int i = 0; i < MAXCS; i++) {
		switch (i)
		{
		case 0:
			cout << "ISBN - ";
			break;
		case 1:
			cout << "Ten sach - ";
			break;
		case 2:
			cout << "Tac gia - ";
			break;
		case 3:
			cout << "Nha xuat ban - ";
			break;
		case 4:
			cout << "Nam xuat ban - ";
			break;
		case 5:
			cout << "The loai - ";
			break;
		case 6:
			cout << "Gia sach - ";
			break;
		case 7:
			cout << "So quyen - ";
			break;
		}
		cin >> edit;
		if (edit) {
			cout << "Thong tin cu: " << a[index][i] << endl;
			cout << "Nhap thong tin moi: ";
			cin.ignore();
			getline(cin, a[index][i]);
		}
	}
}

// Chuc nang: Xoa thong tin cua sach theo ISBN duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int& h: so dong cua ma tran (sau khi xoa 1 sach thi so dong se giam di 1)
//						string x: ISBN
// Gia tri tra ve: (khong co)
void XoaSach(string a[MAXRS][MAXCS], int& h, string x) {
	int index = ViTriSachTheoISBN(a, h, x);
	for (int i = index + 1; i < h; i++) {
		for (int j = 0; j < MAXCS; j++) {
			a[i - 1][j] = a[i][j];
		}
	}
	h--;
}

// Chuc nang: Xuat 1 dong tu ma tran quan ly sach
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
//						int x: chi so dong muon xuat ra
// Gia tri tra ve: (khong co)
void XuatDongDSSach(string a[MAXRS][MAXCS], int h, int x) {
	for (int i = 0; i < MAXCS; i++) {
		switch (i)
		{
		case 0: case 4: case 6:
			cout << setw(15) << left;
			break;
		case 1: case 2: case 3:
			cout << setw(30) << left;
			break;
		case 5:
			cout << setw(20) << left;
			break;
		default:
			break;
		}
		cout << a[x][i];
	}
}

// Chuc nang: Tim thong tin cua sach theo ten sach duoc nhap vao tu ban phim
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
//						string x: ten cua sach
// Gia tri tra ve:
//						vi tri dong chua ten		neu ten duoc tim thay (hop le)
//						-1							neu ten khong duoc tim thay (khong hop le)
int TimSachTheoTen(string a[MAXRS][MAXCS], int h, string x) {
	for (int i = 1; i < h; i++) {
		if (a[i][1] == x) {
			return i;
		}
	}
	return -1;
}

// Chuc nang: Dem tong so sach co trong thu vien
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
// Gia tri tra ve:
//						int s: tong so sach trong thu vien
int DemSoLuongSach(string a[MAXRS][MAXCS], int h) {
	int s = 0;
	for (int i = 1; i < h; i++) {
		s = s + stoi(a[i][7]);
	}
	return s;
}

// Chuc nang: Thong ke cac the loai co trong thu vien roi sao chep cac the loai do vao mang 1 chieu
// Tham so truyen vao:	
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran quan ly sach
//						string theloai[MAXL]: mang 1 chieu gom cac the loai
//						int& k: so luong the loai
// Gia tri tra ve: (khong co)
void ThongKeTheLoai(string a[MAXRS][MAXCS], int h, string theloai[MAXL], int& k) {
	for (int i = 1; i < h; i++) {
		if (!KiemTraTonTaiTruocDo(theloai, k, a[i][5])) {
			k++;
			theloai[k - 1] = a[i][5];
		}
	}
}

// Chuc nang: Kiem tra 1 gia tri kieu chuoi ki tu co ton tai trong mang 1 chieu truoc do hay chua
// Tham so truyen vao:	
//						string a[MAXL]: mang 1 chieu
//						int n: so luong phan tu cua mang
//						string x: gia tri can kiem tra
// Gia tri tra ve:
//						1 (true)	neu da co trong mang 1 chieu
//						0 (false)	neu chua co trong mang 1 chieu
bool KiemTraTonTaiTruocDo(string a[MAXL], int n, string x) {
	for (int i = 0; i < n; i++) {
		if (x == a[i]) {
			return 1;
		}
	}
	return 0;
}

// Chuc nang: Dem tong so sach theo 1 the loai
// Tham so truyen vao:
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
//						string x: the loai
// Gia tri tra ve:
//						int s: tong so sach theo 1 the loai
int DemSoLuongSachTheoTheLoai(string a[MAXRS][MAXCS], int h, string x) {
	int s = 0;
	for (int i = 1; i < h; i++) {
		if (x == a[i][5]) {
			s = s + stoi(a[i][7]);
		}
	}
	return s;
}

// Chuc nang: Xuat so luong sach theo cac the loai
// Tham so truyen vao:
// 						string theloai[MAXL]: mang 1 chieu gom cac the loai
//						int nTl: so luong the loai
//						string a[MAXRS][MAXCS]: ma tran quan ly sach
//						int h: so dong cua ma tran
// Gia tri tra ve:
//						int s: tong so sach theo 1 the loai
void XuatSoLuongSachTheoTheLoai(string theloai[MAXL], int nTl, string a[MAXRS][MAXCS], int h) {
	for (int i = 0; i < nTl; i++) {
		cout << setw(70) << left << ""  << "- " << theloai[i] << ": " << DemSoLuongSachTheoTheLoai(a, h, theloai[i]) << endl;
	}
}