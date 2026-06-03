#include <iostream>
#include <string>
using namespace std;
class monhoc{
	private:
		string mamh;
		string tenmh;
		float dtb;
		int sotc;
		
	public:
		monhoc(){
			mamh="";
			tenmh="";
			dtb=0;
			sotc=0;
		};
		
		~monhoc();
		
		float getdtb(){
			return dtb;
		}
		
		int tinchi(){
			return sotc;
		}
		void nhap();
		void xuat();
};

class sinhvien{
	private:
		string masv;
		string hoten;
		int somh;
		monhoc arr[100];
		
	public:
		sinhvien(){
			masv="";
			hoten="";
			somh=0;
			
		};
		
		~sinhvien();
		
		void nhap1();
		void xuat1();
		float Dtk();
};

monhoc::~monhoc()
{}

sinhvien::~sinhvien(){}

void monhoc::nhap(){
	cout<<"Nhap ma mon hoc: ";
	getline(cin, mamh);
	
	cout<<"Nhap ten mon hoc: ";
	getline(cin, tenmh);
	
	do{
		cout<<"Nhap dtb:";
	cin>>dtb;
	}
	while ( dtb < 0 || dtb > 10);
	
	do{
		cout<<"So tin chi: ";
	cin>>sotc;
	}
	while (sotc <= 0 );
	
	cin.ignore();
}

void monhoc::xuat(){
	cout<<"Ma mon hoc: "<<mamh<<endl;
	cout<<"Ten mon hoc: "<<tenmh<<endl;
	cout<<"dtb: "<<dtb<<endl;
	cout<<"so tin chi: "<<sotc<<endl;
}

void sinhvien::nhap1(){
	cout<<"Ma sinh vien: ";
	getline(cin, masv);
	
	cout<<"ten sinh vien: ";
	getline(cin, hoten);
	
	do{
		cout<<"so mon hoc: ";
	cin>>somh;
	}
	while (somh <=0 );
	cin.ignore();
	
	for ( int i=0;i<somh; i++){
		cout<<"\nMonhoc thu: "<<i+1<<endl;
		arr[i].nhap();
	}
}

float sinhvien::Dtk(){
	float tong =0;
	int tongtc = 0;
	for ( int i=0; i<somh; i++){
		tong += arr[i].getdtb()*arr[i].tinchi();
		tongtc += arr[i].tinchi();
	}
	return tong/tongtc;
}

void sinhvien::xuat1(){
	cout<<"ma sinh vien: "<<masv<<endl;
	cout<<"ten sinh vien: "<<hoten<<endl;
	cout<<"so mon hoc: "<<somh<<endl;
	
	for ( int i=0; i<somh; i++){
		cout<<"'nMon hoc thu: "<<i+1<<endl;
		arr[i].xuat();
	}
	cout<<"Diem tong ket: "<<Dtk()<<endl;
	
}
	
int main()
{
	monhoc mh;
	cout<<"Nhap thong tin 1 mon hoc\n";
	mh.nhap();
	
	cout<<"\nMon hoc vua nhap\n";
	mh.xuat();
	
	int n;
	do{
		cout<<"Nhap so luong sinh vien: ";
		cin>>n;
	}
	while ( n<=0);
	cin.ignore();
	sinhvien ds[100];
	for ( int i=0; i<n; i++){
		cout<<"Sinh vien thu "<<i+1<<endl;
		ds[i].nhap1();
	}
	
	cout<<"\nDanh sach sinh vien\n";
	for ( int i=0; i<n; i++){
		ds[i].xuat1();
		cout<<endl;
	}
	
	
	int k=0;
	for ( int i=0; i<n; i++){
		if (ds[i].Dtk() < 4){
			k++;
		}
	}
	cout<<"\nSo sinh vien hoc lai: "<<k<<endl;
	
	
	
	return 0;
}
















	
	
	













