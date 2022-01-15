#pragma once
#include <string>
using namespace std;

#define MAXRD 10
#define MAXCD 9

void XuatDSDocGia(string a[MAXRD][MAXCD], int n);
void ThemDocGia(string a[MAXRD][MAXCD], int& n);
int ViTriDocGiaTheoMaDocGia(string a[MAXRD][MAXCD], int n, string x);
bool KiemTraMaDocGia(string a[MAXRD][MAXCD], int n, string x);
string NhapMaDocGia(string a[MAXRD][MAXCD], int n);
void ChinhSuaDocGia(string a[MAXRD][MAXCD], int n, string x);
void XoaDocGia(string a[MAXRD][MAXCD], int& n, string x);
void XuatDongDSDocGia(string a[MAXRD][MAXCD], int n, int x);
int TimDocGiaTheoCMND(string a[MAXRD][MAXCD], int n, string x);
int TimDocGiaTheoHoTen(string a[MAXRD][MAXCD], int n, string x);
int DemDocGiaTheoGioiTinh(string a[MAXRD][MAXCD], int n, string x);