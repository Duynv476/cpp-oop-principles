#include <iostream>
#include <string>

using namespace std;

class SV{
	private:
		string MaSV;
		string Hoten;
	
	public:
		SV();
		~SV();
		
		void nhap();
		void xuat();
};

class SVTMDT: public SV
{
	private:
		float diem;
	
	public:
		SVTMDT();
		~SVTMDT();
		
		void nhap();
		void xuat();
		bool operator < (SVTMDT a);
};

SV::SV()
{
	MaSV = "";
	Hoten = "";
}

SV::~SV()
{
}

void SV::nhap()
{
	cout << "Nhap ma SV: ";
	getline(cin, MaSV);

	cout << "Nhap ho ten: ";
	getline(cin, Hoten);
}

void SV::xuat()
{
	cout << "Ma SV: " << MaSV << endl;
	cout << "Ho ten: " << Hoten << endl;
}

SVTMDT::SVTMDT()
{
	diem = 0;
}

SVTMDT::~SVTMDT()
{
}

void SVTMDT::nhap()
{
	SV::nhap();
	cout<<"Nhap diem: ";
	cin >> diem;
	cin.ignore();
}

void SVTMDT::xuat()
{
	SV::xuat();
	cout <<"Diem: " <<diem<<endl;
}

bool SVTMDT::operator <(SVTMDT a)
{
	return diem <a.diem;
}

int main()
{
	SV sv;
	cout<<"Nhap 1 sinh vien"<<endl;
	sv.nhap();
	cout<<"\nThongtin sinh vien\n"<<endl;
	sv.xuat();
	
	int n;
	cout<<"Nhap so sv TMDT:  ";
	cin >> n;
	cin.ignore();
	SVTMDT ds[100];
	
	for ( int i=0; i<n; i++){
		cout<<"Nhap sv thu "<<i+1<<endl;
		ds[i].nhap();
	}
	
	cout<<"Danh sach sv"<<endl;
	
	for ( int i = 0; i<n; i++){
		ds[i].xuat();
		cout<<endl;
	}
	
	for ( int i = 0; i<n-1; i++){
		for ( int j = i+1; j<n; j++){
			if( ds[i] < ds[j]){
				SVTMDT temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	
	cout<<"danh sach xep theo diem giam dan\n"<<endl;
	for ( int i = 0; i<n; i++){
		ds[i].xuat();
		cout<<endl;
	}
	return 0;
	
	
}
























