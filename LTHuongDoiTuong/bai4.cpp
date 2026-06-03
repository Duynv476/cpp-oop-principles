#include <iostream> 
#include <string>
using namespace std;

class SV{
	private:
		string masv;
		string hoten;
		
	public:
		SV()
		{
			masv="";
			hoten="";
		};
		~SV();
		
		void nhap();
		void xuat();	
};

class SVAI: public SV{
	private:
		float dtb;
	
	public:
		SVAI(){
			dtb=0;
		};
		~SVAI();
		
		void nhap();
		void xuat();
		
		bool operator < (SVAI a);
		
};

SV::~SV(){};
SVAI::~SVAI(){};

void SV::nhap(){
	cout<<"Ma sinh vien: ";
	getline(cin, masv);
	
	cout<<"Ten sinh vien: ";
	getline(cin, hoten);
}


void SV::xuat(){
	cout<<"Ma sinh vien: "<<masv<<endl;
	cout<<"Ho ten: "<<hoten<<endl;
}

void SVAI::nhap(){
	SV::nhap();
	cout<<"Diem trung binh: ";
	cin>>dtb;
	cin.ignore();
}

void SVAI::xuat(){
	SV::xuat();
	cout<<"Diem trung binh: "<<dtb<<endl;
}

bool SVAI::operator < (SVAI a){
	return dtb < a.dtb;
}

int main(){
	SV sv;
	cout<<"Nhap 1 sinh vien: "<<endl;
	sv.nhap();
	
	cout<<"Thong tin sinh vien vua nhap:\n"<<endl;
	sv.xuat();
	
	int n;
	cout<<"\nNhap so luong sinh vien: ";
	cin>>n;
	cin.ignore();
	SVAI ds[100];
	for ( int i =0; i<n; i++){
		cout<<"Sinh vien thu "<<i+1<<endl;
		ds[i].nhap();
		cout<<endl;
	}
	
	cout<<"\nDanh sach sinh vien\n"<<endl;
	for ( int i=0; i<n; i++){
		ds[i].xuat();
		cout<<endl;
	}
	
	cout<<"\nDanh sách sv xep theo DTB giam dan\n"<<endl;
	for ( int i = 0; i< n-1; i++){
		for ( int j=i+1; j<n; j++){
			if (ds[i] < ds[j]){
				SVAI temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	
	for ( int i = 0; i<n; i++){
		ds[i].xuat();
		cout<<endl;
	}
	
	return 0;












}





















