#pragma once
#include <string>
using namespace std;

#include "docgia.h"
#include "sach.h"

int DemSoSachDocGiaDaMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x);
void DienPhieuMuon(string PhieuSach[MAXRP][MAXCP], int& nP, string DocGia[MAXRD][MAXCD], int nD, string Sach[MAXRS][MAXCS], int nS, string& x);
void XuatPhieuMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x);
void DienPhieuTra(string PhieuSach[MAXRP][MAXCP], int nP, string DocGia[MAXRD][MAXCD], int nD, string Sach[MAXRS][MAXCS], int nS, string& x, string tra[MAXL], int& quant, string& dCur, int& f);
void XoaISBNDaTra(string PhieuSach[MAXRP][MAXCP], int& nP, string x, string isbn);
string TimNgayMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x, string isbn);
string TimNgayTraDuKien(string PhieuSach[MAXRP][MAXCP], int nP, string x, string isbn);
void XuatPhieuTra(string PhieuSach[MAXRP][MAXCP], int& nP, string x, string tra[MAXL], int quant, string dCur, int f);
void XoaDongDocGiaDaTra(string PhieuSach[MAXRP][MAXCP], int& nP, int k);
bool KiemTraDocGiaCoMuonSach(string PhieuSach[MAXRP][MAXCP], int nP, string x);
bool KiemTraISBNDuocMuon(string PhieuSach[MAXRP][MAXCP], int nP, string x, string isbn);
int DemSoSachDuocMuon(string PhieuSach[MAXRP][MAXCP], int nP);
void ThongKeDocGiaTreHan(string PhieuSach[MAXRP][MAXCP], int nP, int dCur, int mCur, int yCur, string trehan[MAXL], int& nTh);
void XuatDSDocGiaTreHan(string trehan[MAXL], int nTh, string DocGia[MAXRD][MAXCD], int nD);