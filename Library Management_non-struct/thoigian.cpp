#include <string>
#include <iostream>
using namespace std;

// Chuc nang: Chuyen cac du lieu ve ngay, thang, nam duoc nhap tu ban phim thanh chuoi ky tu dd/mm/yyyy
// Tham so truyen vao:	
//							int d: ngay		
//							int m: thang
//							int y: nam
// Gia tri tra ve:		
//							string date: chuoi ky tu ngay theo dang dd/mm/yyyy
string ChuyenThanhChuoiKyTuNgay(int d, int m, int y) {
	string date, dStr, mStr, yStr;
	if (d - 10 < 0) {	// ngay co 1 chu so
		dStr = '0' + to_string(d);
	}
	else {				// ngay co 2 chu so
		dStr = to_string(d);
	}

	if (m - 10 < 0) {	// thang co 1 chu so
		mStr = '0' + to_string(m);
	}
	else {				// thang co 2 chu so
		mStr = to_string(m);
	}

	yStr = to_string(y);

	date = dStr + '/' + mStr + '/' + yStr;
	return date;
}

// Chuc nang: Kiem tra mot nam co phai la nam nhuan hay khong
// Tham so truyen vao:
//						int y: nam can kiem tra
// Gia tri tra ve:
//						1 (true)		neu la nam nhuan
//						0 (false)		neu khong la nam nhuan
bool KiemTraNamNhuan(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

// Chuc nang: Xac dinh so ngay trong mot thang
// Tham so truyen vao:
//						int m: thang
//						int y: nam
// Gia tri tra ve:
//						29		neu la thang 2 cua nam nhuan
//						28		neu la thang 2 cua nam khong nhuan
//						31		neu la thang 1, 3, 5, 7, 8, 10, 12
//						30		neu la thang 4, 6, 9, 11
int SoNgayTrongThang(int m, int y) {
	switch (m) {
	case 2:
		if (KiemTraNamNhuan(y)) {
			return 29;
		}
		else {
			return 28;
		}
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	}
	return 0;
}

// Chuc nang: Nhap ngay (neu ngay khong hop le thi nhap lai)
// Tham so truyen vao:
//							int& d: ngay
//							int& m: thang
//							int& y: nam
// Gia tri tra ve: (khong co)
void NhapNgay(int& d, int& m, int& y) {
	int count = 0;
	do {
		if (count > 0) {
			cout << "Ngay khong hop le. Moi ban nhap lai.\n";
		}
		cout << "Ngay: ";
		cin >> d;
		cout << "Thang: ";
		cin >> m;
		cout << "Nam: ";
		cin >> y;
		count++;
	} while (!(m >= 1 && m <= 12 && y >= 1 && y <= 1000000000 && d >= 1 && d <= SoNgayTrongThang(m, y)));
}

// Chuc nang: Cong them n ngay
// Tham so truyen vao:
//						int& d: ngay
//						int& m: thang
//						int& y: nam
//						int n: so ngay cong them
// Gia tri tra ve: (khong co)
void CongNNgay(int& d, int& m, int& y, int n) {
	d = d + n;
	while (d > SoNgayTrongThang(m, y)) {
		d = d - SoNgayTrongThang(m, y);
		m = m + 1;
		if (m > 12) {
			m = m - 12;
			y = y + 1;
		}
	}
}

// Chuc nang: So sanh ngay thu nhat co nho hon ngay thu hai hay khong
// Tham so truyen vao:
//						int d1: ngay thu nhat
//						int m1: thang thu nhat
//						int y1: nam thu nhat
//						int d2: ngay thu hai
//						int m2: thang thu hai
//						int y2: nam thu hai
// Gia tri tra ve:
//						1 (true)	neu ngay thu nhat nho hon ngay thu hai
//						0 (false)	neu ngay thu nhat khong nho hon ngay thu hai
bool SoSanhNgayNhoHon(int d1, int m1, int y1, int d2, int m2, int y2) {
	if (y1 < y2) {
		return 1;
	}
	else if (y1 == y2) {
		if (m1 < m2) {
			return 1;
		}
		else if (m1 == m2) {
			if (d1 < d2) {
				return 1;
			}
		}
	}
	return 0;
}

// Chuc nang: Tim khoang cach giua ngay thu nhat và ngay thu hai (voi dieu kien: ngay thu nhat < ngay thu hai)
// Tham so truyen vao:
//						int d1: ngay thu nhat
//						int m1: thang thu nhat
//						int y1: nam thu nhat
//						int d2: ngay thu hai
//						int m2: thang thu hai
//						int y2: nam thu hai
// Gia tri tra ve:
//						int dis: khoang cach giua 2 ngay
int TinhKhoangCach2Ngay(int d1, int m1, int y1, int d2, int m2, int y2) {
	int dis = 0;
	if (!SoSanhNgayNhoHon(d1, m1, y1, d2, m2, y2)) {
		return 0;
	}
	while (d1 != d2 || m1 != m2 || y1 != y2) {
		CongNNgay(d1, m1, y1, 1);
		dis++;
	}
	return dis;
}

// Chuc nang: Tach chuoi ki tu ngay (dd/mm/yyyy) thanh tung gia tri ngay, thang, nam theo kieu so nguyen
// Tham so truyen vao:
//						string date: chuoi ki tu ngay theo dinh dang (dd/mm/yyyy)
//						int& d: ngay
//						int& m: thang
//						int& y: nam
// Gia tri tra ve: (khong co)
void TachChuoiKiTuNgay(string date, int& d, int& m, int& y) {
	d = (date[0] - '0') * 10 + (date[1] - '0');
	m = (date[3] - '0') * 10 + (date[4] - '0');
	y = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
}