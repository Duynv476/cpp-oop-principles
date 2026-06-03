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


class SVSDH: public SV{
	private:
		float hocphi;
	public:
		SVSDH(){
			hocphi=0;
		};
		~SVSDH();
		void nhap1();
		void xuat1();
		
		float gethocphi(){
			return hocphi;
		}
		
		
};

	
SV::~SV() {
}

SVSDH::~SVSDH() {
}


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


void SVSDH::nhap1(){
	SV::nhap();
	
	cout<<"Hoc phi: ";
	cin>>hocphi;
	cin.ignore();
}


void SVSDH::xuat1(){
	SV::xuat();
	cout<<"Hoc phi: "<<hocphi<<endl;
}

int main(){
	SV sv;
	cout<<"Nhap thong tin 1 sinh vien\n";
	sv.nhap();
	
	cout<<endl;
	
	sv.xuat();
	
	int n;
	do{
		cout<<"Nhap so luong sinh vien: ";
		cin>>n;
	}
	
	while (n<=0);
	cin.ignore();
	cout<<endl;
	
	SVSDH ds[100];
	
	for (int i=0; i<n; i++){
		cout<<"Sinh vien thu "<<i+1<<endl;
		ds[i].nhap1();
	}
	
	cout<<"\nDanh sach sinh vien\n";
	for ( int i = 0; i<n; i++){
		ds[i].xuat1();
		cout<<endl;
	}
	
	int k =0;
	cout<<"\nDanh sach sinh vien co hoc phi >9000";
	for ( int i = 0; i<n; i++){
		if(ds[i].gethocphi() > 9000){
			ds[i].xuat1();
			k++;
		}
	}
	
	if(k==0){
		cout<<"Ko co";
	}
		
	return 0;

}




















