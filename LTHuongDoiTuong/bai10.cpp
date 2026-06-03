#include <iostream>
#include <string>
using namespace std;

class Nguoi{
	private:
		string hoten;
		string gioitinh;
		int namsinh;
	public:
		Nguoi(){
			hoten="";
			gioitinh="";
			namsinh=0;
			
		};
		
		~Nguoi();
		
		void nhap();
		void xuat();
		int tuoi(){
			return 2020-namsinh;
		}
};

class Nhanvien: public Nguoi{
	private:
		float hsthamnien;
		float mucluong;
		float anca;
	
	public:
		Nhanvien(){
			hsthamnien=0;
			mucluong=0;
			anca=0;
		};
		
		~Nhanvien();
		
		void nhap1();
		void xuat1();
		
		bool nghihuu();
		float luong();
		
};

Nguoi::~Nguoi(){}

Nhanvien::~Nhanvien(){}


void Nguoi::nhap(){
	cout<<"Nhap ho ten: ";
	getline(cin, hoten);
	
	cout<<"Nhap gioi tinh: ";
	getline(cin, gioitinh);
	
	do{
		cout<<"Nam sinh: ";
		cin>>namsinh;
	}
	while (namsinh <=0 );
	cin.ignore();
}

void Nguoi::xuat(){
	cout<<"Ho ten: "<<hoten<<endl;
	cout<<"Gioi tinh"<<gioitinh<<endl;
	cout<<"Nam sinh: "<<namsinh<<endl;
	cout<<"Tuoi: "<<tuoi()<<endl;
}

void Nhanvien::nhap1(){
	Nguoi::nhap();
	
	do{
		cout<<"He so tham nien: ";
	cin>>hsthamnien;
	}
	while ( hsthamnien <=0);
	
	do{
		cout<<"Muc luong: ";
	cin>>mucluong;
	}
	while (mucluong <= 0);
	
	do{
		cout<<"Tien an ca: ";
	cin>>anca;
	}
	while (anca < 0);
	
	cin.ignore();
}

bool Nhanvien::nghihuu(){
	return tuoi() >=60;
}

float Nhanvien::luong(){
	if(nghihuu()){
		return 0.75*mucluong*hsthamnien;
	}
	
	return mucluong*hsthamnien+anca;
}

void Nhanvien::xuat1(){
	Nguoi::xuat();
	cout<<"He so tham nien: "<<hsthamnien<<endl;
	cout<<"Muc luong: "<<mucluong<<endl;
	cout<<"Tien an ca: "<<anca<<endl;
	cout<<"Luong: "<<luong()<<endl;
}	
int main(){
	Nguoi ng;
	cout<<"Nhap thong tin 1 nguoi\n";
	ng.nhap();
	
	cout<<"Nguoi vua nhap\n";
	ng.xuat();
	cout<<endl;
	
	int n;
	do{
		cout<<"Nhap so luong nhan vien: ";
		cin>>n;
	}
	while ( n<=0 );
	cin.ignore();
	
	Nhanvien ds[100];
	for( int i=0; i<n; i++){
		cout<<"Nhan vien thu "<<i+1<<endl;
		ds[i].nhap1();
	}
	
	cout<<"\nDanh sach nhan vien\n";
	for ( int i = 0; i<n; i++){
		ds[i].xuat1();
		cout<<endl;
	}
	

	cout<<"\ndanh sach nhan vien da den tuoi nghi huu\n";
	int k=0;
	for (int i=0; i<n; i++){
		if(ds[i].nghihuu()){
			ds[i].xuat1();
			cout<<endl;
			k++;
		}
	}
	if(k==0){
		cout<<"Ko co";
	}
	
	return 0;
}

















