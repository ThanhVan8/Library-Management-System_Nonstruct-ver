#pragma once
#include <string>
using namespace std;

#define MAXRS 10
#define MAXCS 8

#define MAXRP 10
#define MAXCP 9

#define MAXL 10

#define MAXBORROW 5

void XuatDSSach(string a[MAXRS][MAXCS], int h);
void ThemSach(string a[MAXRS][MAXCS], int& h);
int ViTriSachTheoISBN(string a[MAXRS][MAXCS], int h, string x);
bool KiemTraISBN(string a[MAXRS][MAXCS], int h, string x);
string NhapISBN(string a[MAXRS][MAXCS], int h);
void ChinhSuaSach(string a[MAXRS][MAXCS], int h, string x);
void XoaSach(string a[MAXRS][MAXCS], int& h, string x);
void XuatDongDSSach(string a[MAXRS][MAXCS], int h, int x);
int TimSachTheoTen(string a[MAXRS][MAXCS], int h, string x);
int DemSoLuongSach(string a[MAXRS][MAXCS], int h);
void ThongKeTheLoai(string a[MAXRS][MAXCS], int h, string theloai[MAXL], int& k);
bool KiemTraTonTaiTruocDo(string a[MAXL], int n, string x);
int DemSoLuongSachTheoTheLoai(string a[MAXRS][MAXCS], int h, string x);
void XuatSoLuongSachTheoTheLoai(string theloai[MAXL], int nTl, string a[MAXRS][MAXCS], int h);
