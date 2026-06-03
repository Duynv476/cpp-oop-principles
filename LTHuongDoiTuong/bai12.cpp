#include <iostream>
#include <string>
using namespace std;

class nhanvien{
	private:
		string manv;
		string hoten;
		int tuoi;
	
	public:
		nhanvien(){
			manv="";
			hoten="";
			tuoi=0;
		};
		
		void nhap();
		void xuat();
		
		bool vehuu();
		int gettuoi(){
			return tuoi;
		};
		
};

class canbo: public nhanvien{
	private:
		float hsl;
		float phucap;
		string trinhdo;
	
	public:
		void nhap1();
		void xuat1();
		float tinhluong(){
			if(vehuu()){
				return (hsl*1550+phucap)*0.7;
			}
			
			return hsl*1550+phucap;
		}
		float gethsl(){
			return hsl;
		};
};

void nhanvien::nhap(){
	cout<<"Nhap ma nhan vien: ";
	getline(cin, manv);
	
	cout<<"Nhap ten nhan vien: ";
	getline(cin, hoten);
	
	do{
		cout<<"Nhap tuoi: ";
	cin>>tuoi;
	}
	while (tuoi < 0);
	cin.ignore();
	
}

bool nhanvien::vehuu(){
	return gettuoi() >=60;
}
void nhanvien::xuat(){
	cout<<"Ma nv: "<<manv<<endl;
	cout<<"Ten nv: "<<hoten<<endl;
	cout<<"tuoi: "<<tuoi<<endl;
	if(vehuu()){
		cout<<"Ve huu"<<endl;
	}
	else{
		cout<<"Chua ve huu";
	}
}

void canbo::nhap1(){
	nhanvien::nhap();
	
	do{
		cout<<"he so luong: ";
		cin>> hsl;
	}
	while (hsl <= 0);
	
	do{
		cout<<"phu cap: ";
		cin>>phucap;
	}
	while (phucap < 0);
	
	cin.ignore();
	
	cout<<"Trinh do: ";
	getline(cin, trinhdo);
	
}

void canbo::xuat1(){
	nhanvien::xuat();
	cout<<endl;
	cout<<"He so luong: "<<hsl<<endl;
	cout<<"Phu cap: "<<phucap<<endl;
	cout<<"Trinh do: "<<trinhdo<<endl;
	cout<<"Luong: "<<tinhluong()<<endl;
}

int main(){
	nhanvien nv;
	cout<<"Nhap thong tin 1 nv\n";
	nv.nhap();
	
	cout<<"\nThong tin nv\n";
	nv.xuat();
	
	int n;
	do{
		cout<<"\nNhap so can bo: ";
		cin>>n;
	}
	while (n<0);
	cin.ignore();
	
	canbo ds[100];
	for ( int i = 0; i<n; i++){
		cout<<"Can bo thu "<<i+1<<endl;
		ds[i].nhap1();
	}
	
	cout<<"\nDanh sach can bo\n";
	for ( int i=0; i<n; i++){
		ds[i].xuat1();
		cout<<endl;
	}
	
	int k=0;
	cout<<"\ndanh sach can bo chua ve huu, hsl>7.0\n";
	for ( int i=0; i<n; i++){
		if( !ds[i].vehuu() && ds[i].gethsl() > 7.0){
			ds[i].xuat1();
			k++;
			cout<<endl;
		}
	}
	if(k==0){
		cout<<"Ko co";
	}
}






















