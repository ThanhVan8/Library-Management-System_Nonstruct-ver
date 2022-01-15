#pragma once
#include <string>
using namespace std;

bool KiemTraNamNhuan(int y);
int SoNgayTrongThang(int m, int y);
string ChuyenThanhChuoiKyTuNgay(int d, int m, int y);
void NhapNgay(int& d, int& m, int& y);
void CongNNgay(int& d, int& m, int& y, int n);
bool SoSanhNgayNhoHon(int d1, int m1, int y1, int d2, int m2, int y2);
int TinhKhoangCach2Ngay(int d1, int m1, int y1, int d2, int m2, int y2);
void TachChuoiKiTuNgay(string date, int& d, int& m, int& y);