#include <iostream>
#include <iomanip>
#include <string>
#include "docgia.h"
#include "sach.h"
#include "phieusach.h"
#include "thoigian.h"

// Chuc nang: Dem tong so sach cua 1 doc gia dang muon
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						(MAXRP: so dong toi da gom cac doc gia muon sach;
//						 MAXCP: 9 cot cua ma tran gom ma doc gia, ngay muon, ngay tra du kien, so sach muon, ISBN1, ISBN2, ISBN3, ISBN4, ISBN5)
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string x: ma doc gia
// Gia tri tra ve:
//						int s: tong so sach cua doc gia dang muon
int DemSoSachDocGiaDaMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x) {
	int s = 0;
	for (int i = 0; i < nP; i++) {
		if (x == PhieuSach[i][0]) {
			s = s + stoi(PhieuSach[i][3]);
		}
	}
	return s;
}

// Chuc nang: Dien thong tin cho phieu muon sach (gom: ma doc gia, so luong sach muon, isbn, ngay muon)
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int& nP: so dong cua ma tran quan ly muon/tra sach (them 1 dong de nhap thong tin moi)
//						string DocGia[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int nD: so dong cua ma tran quan ly doc gia
//						string Sach[MAXRS][MAXCS]: ma tran quan ly sach
//						int nS: so dong cua ma tran quan ly sach
//						string& x: ma doc gia (thay doi gia tri sau khi nhap)
// Gia tri tra ve: (khong co)
void DienPhieuMuon(string PhieuSach[MAXRP][MAXCP], int& nP, string DocGia[MAXRD][MAXCD], int nD, string Sach[MAXRS][MAXCS], int nS, string& x) {
	nP++;

	// Nhap ma doc gia
	x = NhapMaDocGia(DocGia, nD);
	if (x == "") {
		nP--;
		return;
	}
	PhieuSach[nP - 1][0] = x;

	// Nhap so luong sach muon
	int quant = 0, quantCur, quantBef = DemSoSachDocGiaDaMuon(PhieuSach, nP - 1, x);
	if (quantBef == 5) {
		cout << "DA MUON TOI DA SO SACH QUY DINH!";
		nP--;
		return;
	}
	do {
		cout << "Nhap so luong sach muon (toi da 5 cuon): ";
		cin >> quantCur;
		quant = quantCur + quantBef;
	} while (quant <= 0 || quant > MAXBORROW);
	PhieuSach[nP - 1][3] = to_string(quantCur);

	//Nhap ISBN
	cout << "Nhap ISBN cua cac sach\n";
	for (int i = 4; i < 4 + quantCur; i++) {
		bool valid = 1;
		do {
			if (!valid) {
				cout << "ISBN khong ton tai. Moi ban nhap lai.\n";
			}
			cin >> PhieuSach[nP - 1][i];
			valid = 0;
		} while (!KiemTraISBN(Sach, nS, PhieuSach[nP - 1][i]));
	}

	// Nhap ngay muon
	int d, m, y;
	cout << "Nhap ngay muon (Nhap rieng tung gia tri) \n";
	NhapNgay(d, m, y);
	PhieuSach[nP - 1][1] = ChuyenThanhChuoiKyTuNgay(d, m, y);
	// Tinh ngay tra du kien
	CongNNgay(d, m, y, 7);
	PhieuSach[nP - 1][2] = ChuyenThanhChuoiKyTuNgay(d, m, y);
}

// Chuc nang: Xuat phieu muon sach
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string x: ma doc gia
// Gia tri tra ve: (khong co)
void XuatPhieuMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x) {
	cout << setw(60) << left << "" << "Danh sach ISBN cac sach duoc muon (toi da 5 cuon)\n";
	int quant = 0;
	// Xuat tat ca lan muon
	for (int i = 0; i < nP; i++) {
		if (PhieuSach[i][0] == x) {
			for (int j = 4; j < MAXCP; j++) {
				if (PhieuSach[i][j] != "") {
					cout << setw(60) << "" << left << PhieuSach[i][j] << endl;
					quant++;
				}
			}
			cout << setw(63) << left << "" << "Ngay muon: " << PhieuSach[i][1] << endl;
			cout << setw(63) << left << "" << "Ngay tra du kien: " << PhieuSach[i][2] << endl;
		}
	}
	cout << endl;
	cout << setw(60) << left << "" << "TONG SO SACH DANG MUON: " << quant << " CUON\n";
	cout << setw(60) << left << "" << "SO SACH TOI DA CO THE MUON TIEP: " << MAXBORROW - quant << " CUON\n";
}

// Chuc nang: Tim ngay tra du kien cua 1 doc gia voi 1 quyen sach ma doc gia do muon
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string x: ma doc gia
//						string isbn: isbn cua sach can tim
// Gia tri tra ve:
//						PhieuSach[i][2]: ngay tra du kien (theo dang dd/mm/yyyy)	neu ma doc gia va ma sach tuong ung nhap vao duoc tim thay
//						""															neu ma doc gia va ma sach tuong ung nhap vao khong duoc tim thay
string TimNgayTraDuKien(string PhieuSach[MAXRP][MAXCP], int nP, string x, string isbn) {
	for (int i = 0; i < nP; i++) {
		if (PhieuSach[i][0] == x) {
			for (int j = 4; j < MAXCP; j++) {
				if (PhieuSach[i][j] == isbn) {
					return PhieuSach[i][2];
				}
			}
		}
	}
	return "";
}

// Chuc nang: Tim ngay muon cua 1 doc gia voi 1 quyen sach ma doc gia do muon
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string x: ma doc gia
//						string isbn: isbn cua sach can tim
// Gia tri tra ve:
//						PhieuSach[i][1]: ngay muon (theo dang dd/mm/yyyy)	neu ma doc gia va ma sach tuong ung nhap vao duoc tim thay
//						""													neu ma doc gia va ma sach tuong ung nhap vao khong duoc tim thay
string TimNgayMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x, string isbn) {
	for (int i = 0; i < nP; i++) {
		if (PhieuSach[i][0] == x) {
			for (int j = 4; j < MAXCP; j++) {
				if (PhieuSach[i][j] == isbn) {
					return PhieuSach[i][1];
				}
			}
		}
	}
	return "";
}

// Chuc nang: Dien thong tin cho phieu tra sach (gom: ma doc gia, bao mat sach, so luong sach, isbn, ngay tra thuc te)
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string DocGia[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int nD: so dong cua ma tran quan ly doc gia
//						string Sach[MAXRS][MAXCS]: ma tran quan ly sach
//						int nS: so dong cua ma tran quan ly sach
//						string& x: ma doc gia (thay doi gia tri sau khi nhap)
//						string tra[MAXL]: gom cac isbn cua sach doc gia tra
//						int& quant: so luong sach doc gia tra (thay doi gia tri sau khi nhap)
//						string& dCur: ngay tra thuc te (thay doi gia tri sau khi nhap)
//						int& f: tien phat (thay doi gia tri sau khi tinh)
// Gia tri tra ve: (khong co)
void DienPhieuTra(string PhieuSach[MAXRP][MAXCP], int nP, string DocGia[MAXRD][MAXCD], int nD, string Sach[MAXRS][MAXCS], int nS, string& x, string tra[MAXL], int& quant, string& dCur, int& f) {
	// Nhap ma doc gia
	x = NhapMaDocGia(DocGia, nD);
	if (x == "") {
		return;
	}
	bool retype = 1;
	if (!KiemTraDocGiaCoMuonSach(PhieuSach, nP, x)) {
		do {
			cout << "Doc gia nay khong muon sach! Ban co muon nhap lai? (Co -> chon 1; Khong -> chon 0) ";
			cin >> retype;
			if (!retype) {
				x = "";
				return;
			}
			x = NhapMaDocGia(DocGia, nD);
			if (x == "") {
				return;
			}
		} while (!KiemTraDocGiaCoMuonSach(PhieuSach, nP, x));
	}

	// Nhap ngay tra thuc te
	int d1, m1, y1;
	cout << "Nhap ngay tra sach (Nhap rieng tung gia tri)\n";
	NhapNgay(d1, m1, y1);
	dCur = ChuyenThanhChuoiKyTuNgay(d1, m1, y1);

	// Nhap so luong sach
	int quantBef = DemSoSachDocGiaDaMuon(PhieuSach, nP, x);
	do {
		cout << "Nhap so luong sach tra: ";
		cin >> quant;
	} while (quant <= 0 || quant > quantBef);

	f = 0;
	// Nhap ISBN
	for (int i = 0; i < quant; i++) {
		bool valid = 1;
		do {
			if (!valid) {
				cout << "Doc gia khong muon sach co ISBN nay! Moi ban nhap lai.\n";
			}
			cout << "Nhap ISBN: ";
			cin >> tra[i];
			valid = 0;
		} while (!KiemTraISBNDuocMuon(PhieuSach, nP, x, tra[i]));

		// Bao mat sach
		bool lost;
		cout << "Co mat sach khong? (Co -> chon 1; Khong -> chon 0) ";
		cin >> lost;

		// Tinh tien phat
		if (lost) {
			for (int u = 1; u < nS; u++) {
				if (tra[i] == Sach[u][0]) {
					int cost = stoi(Sach[u][6]);
					f = f + cost * 2;
					// Cap nhat lai so luong cua cuon sach nay trong thu vien
					int n = stoi(Sach[u][7]) - 1;
					Sach[u][7] = to_string(n);
					break;
				}
			}
		}
		else {
			// Tinh so ngay tre han
			int d2, m2, y2;
			TachChuoiKiTuNgay(TimNgayTraDuKien(PhieuSach, nP, x, tra[i]), d2, m2, y2);
			int dist = TinhKhoangCach2Ngay(d2, m2, y2, d1, m1, y1);
			f = f + 5000 * dist;
		}
	}
}

// Chuc nang: Xoa ISBN cua sach doc gia da tra trong ma tran quan ly muon/tra sach
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int& nP: so dong cua ma tran quan ly muon/tra sach (neu tra het sach thi xoa dong)
//						string x: ma doc gia
//						string isbn: isbn cua sach da tra
// Gia tri tra ve: (khong co)
void XoaISBNDaTra(string PhieuSach[MAXRP][MAXCP], int& nP, string x, string isbn) {
	for (int i = 0; i < nP; i++) {
		if (PhieuSach[i][0] == x) {
			for (int j = 4; j < MAXCP; j++) {
				if (PhieuSach[i][j] == isbn) {
					for (int u = j; u < MAXCP - 1; u++) {
						PhieuSach[i][u] = PhieuSach[i][u + 1];
					}
					PhieuSach[i][MAXCP - 1] = "";
					// Cap nhat lai so sach dang muon
					int n = stoi(PhieuSach[i][3]);
					n--;
					PhieuSach[i][3] = to_string(n);
					// Neu da tra het thi xoa dong thong tin do
					if (n == 0) {
						XoaDongDocGiaDaTra(PhieuSach, nP, i);
					}
					return;
				}
			}
		}
	}
}

// Chuc nang: Xuat phieu tra sach
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int& nP: so dong cua ma tran quan ly muon/tra sach (sau khi tra het sach thi xoa thong tin cua dong muon)
//						string x: ma doc gia (thay doi gia tri sau khi nhap)
//						string tra[MAXL]: gom cac isbn cua sach doc gia tra
//						int quant: so luong sach doc gia tra
//						string dCur: ngay tra thuc te
//						int f: tien phat
// Gia tri tra ve: (khong co)
void XuatPhieuTra(string PhieuSach[MAXRP][MAXCP], int& nP, string x, string tra[MAXL], int quant, string dCur, int f) {
	if (x == "" || !KiemTraDocGiaCoMuonSach(PhieuSach, nP, x)) {
		return;
	}

	cout << setw(60) << left << "" << "Danh sach ISBN cac sach duoc tra" << endl;
	for (int i = 0; i < quant; i++) {
		cout << setw(60) << left << "" << tra[i] << endl;
		cout << setw(63) << left << "" << "Ngay muon: " << TimNgayMuon(PhieuSach, nP, x, tra[i]) << endl;
		cout << setw(63) << left << "" << "Ngay tra du kien: " << TimNgayTraDuKien(PhieuSach, nP, x, tra[i]) << endl;
	}
	cout << endl;
	cout << setw(60) << left << "" << "Ngay tra thuc te: " << dCur << endl;
	cout << setw(60) << left << "" << "Tien phat: " << f << " dong" << endl;

	// Xoa thong tin sau khi tra
	for (int i = 0; i < quant; i++) {
		XoaISBNDaTra(PhieuSach, nP, x, tra[i]);
	}

	// Kiem tra doc gia tra het sach chua -> Xuat so sach dang duoc muon
	cout << endl;
	cout << setw(60) << left << "" << "Ghi chu:\n";
	if (KiemTraDocGiaCoMuonSach(PhieuSach, nP, x)) {
		cout << setw(60) << left << "" << "SACH CHUA DUOC TRA HET!\n";
		XuatPhieuMuon(PhieuSach, nP, x);
	}
	else {
		cout << setw(60) << left << "" << "DA TRA HET SACH!\n";
		cout << setw(60) << left << "" << "SO SACH TOI DA CO THE MUON TIEP: 5 CUON\n";
	}
}

// Chuc nang: Xoa dong thong tin cua doc gia khi da tra het 1 dot muon sach trong ma tran quan ly muon/tra sach
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int& nP: so dong cua ma tran quan ly muon/tra sach (tru di 1 dong xoa)
//						int k: chi so dong muon xoa
// Gia tri tra ve: (khong co)
void XoaDongDocGiaDaTra(string PhieuSach[MAXRP][MAXCP], int& nP, int k) {
	for (int i = k; i < nP - 1; i++) {
		for (int j = 0; j < MAXCP; j++) {
			PhieuSach[i][j] = PhieuSach[i + 1][j];
		}
	}
	nP--;
}

// Chuc nang: Kiem tra doc gia co muon sach hay khong
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string x: ma doc gia
// Gia tri tra ve:
//						1 (true)	neu doc gia co muon sach
//						0 (false)	neu doc gia khong muon sach
bool KiemTraDocGiaCoMuonSach(string PhieuSach[MAXRP][MAXCP], int nP, string x) {
	for (int i = 0; i < nP; i++) {
		if (PhieuSach[i][0] == x) {
			return 1;
		}
	}
	return 0;
}

// Chuc nang: Kiem tra doc gia co muon cuon sach nay hay khong
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						string x: ma doc gia
//						string isbn: ma sach can kiem tra
// Gia tri tra ve:
//						1 (true)	neu doc gia co muon sach nay
//						0 (false)	neu doc gia khong muon sach nay
bool KiemTraISBNDuocMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x, string isbn) {
	for (int i = 0; i < nP; i++) {
		if (PhieuSach[i][0] == x) {
			for (int j = 4; j < MAXCP; j++) {
				if (PhieuSach[i][j] == isbn) {
					return 1;
				}
			}
		}
	}
	return 0;
}

// Chuc nang: Dem tong so sach ma tat ca doc gia da muon cua thu vien
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
// Gia tri tra ve:
//						int s: tong so sach duoc muon trong thu vien
int DemSoSachDuocMuon(string PhieuSach[MAXRP][MAXCP], int nP) {
	int s = 0;
	for (int i = 0; i < nP; i++) {
		s = s + stoi(PhieuSach[i][3]);
	}
	return s;
}

// Chuc nang: Thong ke cac doc gia bi tre han roi sao chep cac ma doc gia do vao mang 1 chieu
// Tham so truyen vao:	
//						string PhieuSach[MAXRP][MAXCP]: ma tran quan ly muon/tra sach
//						int nP: so dong cua ma tran quan ly muon/tra sach
//						int dCur: ngay hien tai
//						int mCur: thang hien tai
//						int yCur: nam hien tai
//						string trehan[MAXL]: mang 1 chieu gom cac ma doc gia bi tre han
//						int& nTh: so luong doc gia bi tre han
// Gia tri tra ve: (khong co)
void ThongKeDocGiaTreHan(string PhieuSach[MAXRP][MAXCP], int nP, int dCur, int mCur, int yCur, string trehan[MAXL], int& nTh) {
	int dExp, mExp, yExp;
	for (int i = 0; i < nP; i++) {
		TachChuoiKiTuNgay(PhieuSach[i][2], dExp, mExp, yExp);
		if (SoSanhNgayNhoHon(dExp, mExp, yExp, dCur, mCur, yCur)) {
			if (!KiemTraTonTaiTruocDo(trehan, nTh, PhieuSach[i][0])) {
				nTh++;
				trehan[nTh - 1] = PhieuSach[i][0];
			}
		}
	}
}

// Chuc nang: Xuat danh sach cac doc gia bi tre han
// Tham so truyen vao:
//						string trehan[MAXL]: mang 1 chieu gom cac ma doc gia bi tre han
//						int nTh: so luong doc gia bi tre han
// 						string DocGia[MAXRD][MAXCD]: ma tran quan ly doc gia
//						int nD: so dong cua ma tran quan ly doc gia
// Gia tri tra ve: (khong co)
void XuatDSDocGiaTreHan(string trehan[MAXL], int nTh, string DocGia[MAXRD][MAXCD], int nD) {
	cout << setw(65) << left << "" << setw(20) << left << "Ma doc gia" << "Ho ten" << endl;
	for (int i = 0; i < nTh; i++) {
		for (int j = 1; j < nD; j++) {
			if (trehan[i] == DocGia[j][0]) {
				cout << setw(65) << left << "" << setw(20) << left << trehan[i] << DocGia[j][1] << endl;
			}
		}
	}
}