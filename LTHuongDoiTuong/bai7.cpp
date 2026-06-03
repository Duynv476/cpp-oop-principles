#include <iostream>
#include <string>

using namespace std;
class SV{
	private:
		string masv;
		string hoten;
	
	public:
		SV(){
			masv="";
			hoten="";
		};
		
		~SV();
		
		void nhap();
		void xuat();
};


class SVCNPM: public SV{
	private:
		float dtb;
	public:
		SVCNPM(){
			dtb=0;
		};
		
		~SVCNPM();
		
		void nhap1();
		void xuat1();
		
		float getdtb(){
			return dtb;
		}		
};

SV::~SV(){}

SVCNPM::~SVCNPM(){}

void SV::nhap(){
	cout<<"Nhap ma sinh vien: ";
	getline(cin, masv);
	
	cout<<"Nhap ho ten: ";
	getline(cin, hoten);
}

void SV::xuat(){
	cout<<"Ma sinh vien: "<<masv<<endl;
	cout<<"ho ten: "<<hoten<<endl;
}

void SVCNPM::nhap1(){
	SV::nhap();
	
	do{
		cout<<"Diem trung binh: ";
		cin>>dtb;
	}
	while (dtb < 0);
	cin.ignore();
}

void SVCNPM::xuat1(){
	SV::xuat();
	
	cout<<"diem trung binh: "<<dtb<<endl;
}


int main(){
	SV sv;
	cout<<"Nhap thong tin 1 sinh vien\n";
	sv.nhap();
	cout<<endl;
	
	cout<<"Thong tin sinh vien vua nhap\n";
	sv.xuat();
	cout<<endl;
	
	int n;
	do{
		cout<<"Nhap so luong sinh vien: "<<endl;
		cin>>n;
	}
	while (n <= 0);
	cin.ignore();
	
	SVCNPM ds[100];
	for ( int i = 0; i<n; i++){
		cout<<"Sinh vien thu "<<i+1<<endl;
		ds[i].nhap1();
	}
	
	cout<<endl;
	for ( int i=0; i<n; i++){
		ds[i].xuat1();
		cout<<endl;
	}
	cout<<endl;
	
	int k = 0; 
	cout<<"\nDanh sach sinh vien dtb >= 8.5\n";
	for ( int i=0; i<n; i++){
		if(ds[i].getdtb() >= 8.5){
			ds[i].xuat1();
			k++;
			cout<<endl;
		}
	}
	
	if(k == 0){cout<<"Ko co";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

















	
	

















