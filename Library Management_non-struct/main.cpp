#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "docgia.h"
#include "sach.h"
#include "phieusach.h"
#include "thoigian.h"
#include "menu.h"

int main() {
	string DocGia[MAXRD][MAXCD] = { "Ma doc gia", "Ho ten", "CMND", "Ngay sinh", "Gioi tinh", "Email", "Dia chi", "Ngay lap the", "Ngay het han the",
									"21A001", "Tran Thi Thanh Van", "000111222333", "26/08/2003", "Nu", "van@gmail.com", "Vuon Lai, Tan Phu", "08/12/2021", "08/12/2025",
									"21B010", "Nguyen Van A", "012345678912", "01/02/2003", "Nam", "nva@gmail.com", "Nguyen Van Cu, Q.5", "12/12/2021", "12/12/2025",
									"21C100", "Vo Van B", "001122334455", "03/01/2002", "Nam", "vvb@gmail.com", "CMT8, Tan Binh", "20/12/2021", "20/12/2025" };
	int nD = 4;

	string Sach[MAXRS][MAXCS] = { "ISBN", "Ten sach", "Tac gia", "Nha xuat ban", "Nam xuat ban", "The loai", "Gia sach", "So quyen sach",
								 "AAA000", "C++", "ABC", "DEF", "2020", "KH-CN", "50000", "80",
								 "AAA001", "Lap trinh", "ABC", "XYZ", "2021", "KH-CN", "77000", "150",
								 "AAA002", "Nhap mon lap trinh", "TDT-NTP-DBT-TMT", "Khoa hoc va ky thuat", "2021", "Giao trinh", "84000", "120",
								 "AAA003", "Mat biec", "Nguyen Nhat Anh", "Tre", "2019", "Truyen dai", "110000", "55",
								 "AAA004", "Kinh te dai cuong", "CBA", "XYZ", "2018", "Kinh te", "150000", "100" };
	int nS = 6;

	string PhieuSach[MAXRP][MAXCP];
	int nP = 0;

	while (true) {
		system("CLS");
		XuatMenuChinh();
		int mainChoice;
		char subChoice = '0';
		cout << "\n\nMoi ban nhap chuc nang muon su dung: ";
		cin >> mainChoice;
		system("CLS");

		if (mainChoice == 0) {
			cout << endl << endl;
			cout << setw(60) << left << "" << "CAM ON BAN DA SU DUNG CHUONG TRINH\n\n";
			return 0;
		}

		else if (mainChoice == 1) {
			XuatMenu1();
			cout << "\n\nMoi ban nhap chuc nang cu the: ";
			cin >> subChoice;
			system("CLS");
			if (subChoice == 'a') {
				cout << setw(100) << right << "----- DANH SACH DOC GIA TRONG THU VIEN -----\n\n";
				XuatDSDocGia(DocGia, nD);
			}

			else if (subChoice == 'b') {
				cout << setw(88) << right << "----- THEM DOC GIA -----\n\n";
				ThemDocGia(DocGia, nD);
				cout << "DA THEM DOC GIA!\n";
			}

			else if (subChoice == 'c') {
				cout << setw(90) << right << "----- CHINH SUA DOC GIA -----\n\n";
				string x = NhapMaDocGia(DocGia, nD);

				if (x != "") {
					ChinhSuaDocGia(DocGia, nD, x);
					cout << "DA CHINH SUA DOC GIA!\n";
				}
			}

			else if (subChoice == 'd') {
				cout << setw(88) << right << "----- XOA DOC GIA -----\n\n";
				string x = NhapMaDocGia(DocGia, nD);

				if (x != "") {
					XoaDocGia(DocGia, nD, x);
					cout << "DA XOA DOC GIA!\n";
				}
			}

			else if (subChoice == 'e') {
				cout << setw(90) << right << "----- TIM DOC GIA THEO CMND -----\n\n";
				string x;
				bool valid = 1;
				bool retype = 1;
				do {
					if (!valid) {
						cout << "CMND khong ton tai! Ban co muon nhap lai? (Co -> chon 1; Khong -> chon 0) ";
						cin >> retype;
						if (!retype) {
							break;
						}
					}
					cout << "Nhap CMND: ";
					cin >> x;
					valid = 0;
				} while (TimDocGiaTheoCMND(DocGia, nD, x) == -1);

				if (retype) {
					int index = TimDocGiaTheoCMND(DocGia, nD, x);
					XuatDongDSDocGia(DocGia, nD, 0);
					cout << endl;
					XuatDongDSDocGia(DocGia, nD, index);
					cout << endl;
				}
			}

			else if (subChoice == 'f') {
				cout << setw(100) << right << "----- TIM DOC GIA THEO HO TEN -----\n\n";
				string x;
				bool valid = 1;
				bool retype = 1;
				do {
					if (!valid) {
						cout << "Ho ten khong ton tai! Ban co muon nhap lai? (Co -> chon 1; Khong -> chon 0) ";
						cin >> retype;
						if (!retype) {
							cin.ignore();
							break;
						}
					}
					cin.ignore();
					cout << "Nhap ho ten: ";
					getline(cin, x);
					valid = 0;
				} while (TimDocGiaTheoHoTen(DocGia, nD, x) == -1);

				if (retype) {
					int index = TimDocGiaTheoHoTen(DocGia, nD, x);
					XuatDongDSDocGia(DocGia, nD, 0);
					cout << endl;
					XuatDongDSDocGia(DocGia, nD, index);
					cout << endl;
				}
			}

			else {
				cout << "Chuc nang khong co trong danh sach! Moi ban nhap lai.\n";
			}
		}

		else if (mainChoice == 2) {
			XuatMenu2();
			cout << "\n\nMoi ban nhap chuc nang cu the: ";
			cin >> subChoice;
			system("CLS");

			if (subChoice == 'a') {
				cout << setw(100) << right << "----- DANH SACH SACH TRONG THU VIEN -----\n\n";
				XuatDSSach(Sach, nS);
			}

			else if (subChoice == 'b') {
				cout << setw(88) << right << "----- THEM SACH -----\n\n";
				ThemSach(Sach, nS);
				cout << "DA THEM SACH!\n";
			}

			else if (subChoice == 'c') {
				cout << setw(90) << right << "----- CHINH SUA SACH -----\n\n";
				string x = NhapISBN(Sach, nS);

				if (x != "") {
					ChinhSuaSach(Sach, nS, x);
					cout << "DA CHINH SUA SACH!\n";
				}
			}

			else if (subChoice == 'd') {
				cout << setw(90) << right << "----- XOA SACH -----\n\n";
				string x = NhapISBN(Sach, nS);

				if (x != "") {
					XoaSach(Sach, nS, x);
					cout << "DA XOA SACH!\n";
				}
			}

			else if (subChoice == 'e') {
				cout << setw(90) << right << "----- TIM SACH THEO ISBN -----\n\n";
				string x = NhapISBN(Sach, nS);

				if (x != "") {
					int index = ViTriSachTheoISBN(Sach, nS, x);
					XuatDongDSSach(Sach, nS, 0);
					cout << endl;
					XuatDongDSSach(Sach, nS, index);
					cout << endl;
				}
			}

			else if (subChoice == 'f') {
				cout << setw(90) << right << "----- TIM SACH THEO TEN -----\n\n";
				string x;
				bool valid = 1;
				bool retype = 1;
				do {
					if (!valid) {
						cout << "Ten sach khong ton tai! Ban co muon nhap lai? (Co -> chon 1; Khong -> chon 0) ";
						cin >> retype;
						if (!retype) {
							cin.ignore();
							break;
						}
					}
					cout << "Nhap ten sach: ";
					cin.ignore();
					getline(cin, x);
					valid = 0;
				} while (TimSachTheoTen(Sach, nS, x) == -1);

				if (retype) {
					int index = TimSachTheoTen(Sach, nS, x);
					XuatDongDSSach(Sach, nS, 0);
					cout << endl;
					XuatDongDSSach(Sach, nS, index);
					cout << endl;
				}
			}

			else {
				cout << "Chuc nang khong co trong danh sach! Moi ban nhap lai.\n";
			}
		}

		else if (mainChoice == 3) {
			cout << setw(100) << right << "----- LAP PHIEU MUON SACH -----\n\n";
			cout << "DIEN THONG TIN\n";
			string x;
			DienPhieuMuon(PhieuSach, nP, DocGia, nD, Sach, nS, x);
			if (x != "") {
				cout << endl << setw(90) << right << "PHIEU MUON SACH\n";
				cout << setw(60) << left << "" << "Ma doc gia: " << x << endl << endl;
				XuatPhieuMuon(PhieuSach, nP, x);
			}
		}

		else if (mainChoice == 4) {
			cout << setw(100) << right << "----- LAP PHIEU TRA SACH -----\n\n";
			cout << "DIEN THONG TIN\n";
			string x, dCur;
			int f;
			string tra[MAXL];
			int quant = 0;
			DienPhieuTra(PhieuSach, nP, DocGia, nD, Sach, nS, x, tra, quant, dCur, f);
			if (x != "") {
				cout << endl << setw(90) << right << "PHIEU TRA SACH\n";
				cout << setw(60) << left << "" << "Ma doc gia: " << x << endl << endl;
				XuatPhieuTra(PhieuSach, nP, x, tra, quant, dCur, f);
			}
		}

		else if (mainChoice == 5) {
			XuatMenu5();
			cout << "\n\nMoi ban nhap chuc nang cu the: ";
			cin >> subChoice;
			system("CLS");

			if (subChoice == 'a') {
				cout << setw(108) << right << "----- THONG KE SO LUONG SACH TRONG THU VIEN -----\n\n";
				cout << setw(70) << left << "" << "Tong cong: " << DemSoLuongSach(Sach, nS) << " cuon\n";
			}

			else if (subChoice == 'b') {
				cout << setw(108) << right << "----- THONG KE SO LUONG SACH THEO THE LOAI -----\n\n";
				string theloai[MAXL];
				int nTl = 0;
				ThongKeTheLoai(Sach, nS, theloai, nTl);
				cout << setw(63) << left << "" << "Thu vien gom " << nTl << " the loai sach khac nhau\n\n";
				cout << setw(70) << left << "" << "(Don vi: cuon)\n";
				XuatSoLuongSachTheoTheLoai(theloai, nTl, Sach, nS);
			}

			else if (subChoice == 'c') {
				cout << setw(103) << right << "----- THONG KE SO LUONG DOC GIA -----\n\n";
				cout << setw(70) << left << "" << "Tong cong: " << nD - 1 << " doc gia\n";
			}

			else if (subChoice == 'd') {
				cout << setw(108) << right << "----- THONG KE SO LUONG DOC GIA THEO GIOI TINH -----\n\n";
				cout << setw(70) << left << "" << "(Don vi: doc gia)\n";
				cout << setw(70) << left << "" << "- " << "Nam: " << DemDocGiaTheoGioiTinh(DocGia, nD, "Nam") << endl;
				cout << setw(70) << left << "" << "- " << "Nu: " << DemDocGiaTheoGioiTinh(DocGia, nD, "Nu") << endl;
			}

			else if (subChoice == 'e') {
				cout << setw(108) << right << "----- THONG KE SO LUONG SACH DANG DUOC MUON -----\n\n";
				cout << setw(70) << left << "" << "Tong cong: " << DemSoSachDuocMuon(PhieuSach, nP) << " cuon\n";
			}

			else if (subChoice == 'f') {
				cout << setw(108) << right << "----- THONG KE DANH SACH DOC GIA BI TRE HAN -----\n\n";
				string trehan[MAXL];
				int nTh = 0;
				cout << "Nhap ngay hom nay (Nhap rieng tung gia tri):\n";
				int dCur, mCur, yCur;
				NhapNgay(dCur, mCur, yCur);
				ThongKeDocGiaTreHan(PhieuSach, nP, dCur, mCur, yCur, trehan, nTh);
				cout << setw(65) << left << "" << "Tong cong: " << nTh << " doc gia\n\n";
				XuatDSDocGiaTreHan(trehan, nTh, DocGia, nD);
			}

			else {
				cout << "Chuc nang khong co trong danh sach! Moi ban nhap lai.\n";
			}
		}

		else {
			cout << "Chuc nang khong co trong danh sach! Moi ban nhap lai.\n";
		}

		cout << endl;
		if (!((mainChoice == 1 && subChoice == 'f') || (mainChoice == 2 && subChoice == 'f') || (mainChoice == 2 && subChoice == 'b'))) {
			cin.ignore();
		}
		do {
			cout << "Nhan Enter de tro ve menu chinh ";
		} while (cin.get() != '\n');
	}
	return 0;
}