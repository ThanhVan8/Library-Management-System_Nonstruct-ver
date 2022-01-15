#include <iostream>
#include <iomanip>

using namespace std;

// Chuc nang: Xuat Menu chinh cua thu vien
// Tham so truyen vao: (khong co)
// Gia tri tra ve: (khong co)
void XuatMenuChinh() {
	cout << endl;
	cout << setw(55) << left << "" << "MENU ---- THU VIEN TRUONG DH KHTN TPHCM\n\n";
	cout << setw(60) << left << "" << "1: Quan ly doc gia\n";
	cout << setw(60) << left << "" << "2: Quan ly sach\n";
	cout << setw(60) << left << "" << "3: Lap phieu muon sach\n";
	cout << setw(60) << left << "" << "4: Lap phieu tra sach\n";
	cout << setw(60) << left << "" << "5: Thong ke\n\n";
	cout << setw(60) << left << "" << "0: Thoat chuong trinh\n";
}

// Chuc nang: Xuat Menu cho chuc nang Quan ly doc gia
// Tham so truyen vao: (khong co)
// Gia tri tra ve: (khong co)
void XuatMenu1() {
	cout << setw(65) << left << "" << "QUAN LY DOC GIA\n\n";
	cout << setw(60) << left << "" << "a: Xem danh sach doc gia trong thu vien\n";
	cout << setw(60) << left << "" << "b: Them doc gia\n";
	cout << setw(60) << left << "" << "c: Chinh sua thong tin mot doc gia\n";
	cout << setw(60) << left << "" << "d: Xoa thong tin mot doc gia\n";
	cout << setw(60) << left << "" << "e: Tim kiem doc gia theo CMND\n";
	cout << setw(60) << left << "" << "f: Tim kiem doc gia theo ho ten\n";
}

// Chuc nang: Xuat Menu cho chuc nang Quan ly sach
// Tham so truyen vao: (khong co)
// Gia tri tra ve: (khong co)
void XuatMenu2() {
	cout << setw(65) << left << "" << "QUAN LY SACH\n\n";
	cout << setw(60) << left << "" << "a: Xem danh sach cac sach trong thu vien\n";
	cout << setw(60) << left << "" << "b: Them sach\n";
	cout << setw(60) << left << "" << "c: Chinh sua thong tin mot quyen sach\n";
	cout << setw(60) << left << "" << "d: Xoa thong tin sach\n";
	cout << setw(60) << left << "" << "e: Tim kiem sach theo ISBN\n";
	cout << setw(60) << left << "" << "f: Tim kiem sach theo ten sach\n";
}

// Chuc nang: Xuat Menu cho chuc nang Thong ke
// Tham so truyen vao: (khong co)
// Gia tri tra ve: (khong co)
void XuatMenu5() {
	cout << setw(70) << left << "" << "THONG KE\n\n";
	cout << setw(60) << left << "" << "a: Thong ke so luong sach trong thu vien\n";
	cout << setw(60) << left << "" << "b: Thong ke so luong sach theo the loai\n";
	cout << setw(60) << left << "" << "c: Thong ke so luong doc gia\n";
	cout << setw(60) << left << "" << "d: Thong ke so luong doc gia theo gioi tinh\n";
	cout << setw(60) << left << "" << "e: Thong ke so luong sach dang duoc muon\n";
	cout << setw(60) << left << "" << "f: Thong ke danh sach doc gia bi tre han\n";
}