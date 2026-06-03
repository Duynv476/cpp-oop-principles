#include <iostream>
#include <string>
using namespace std;
class Nguoi{
	private:
		string madd;
		string hoten;
	public:
		Nguoi();
		~Nguoi();
		void nhap();
		void xuat();

};

class Nhanvien: public Nguoi{
	private:
		int namsinh;
		float hsl;
		static float phucap;
		
	public:
		Nhanvien();
		~Nhanvien();
		
		void nhap();
		void xuat();
		
		float tinhluong();
		
		bool operator < (Nhanvien a);
};
	
	float Nhanvien::phucap=500;
	
	Nguoi::Nguoi(){
		madd="";
		hoten="";
	}
	
	Nguoi::~Nguoi(){}
	
	void Nguoi::nhap(){
		cout<<"Nhap ma dinh danh: ";
		getline(cin, madd);
		
		cout<<"Nhap ho ten: ";
		getline(cin, hoten);
	}
	
	void Nguoi::xuat(){
		cout<<"Ma dinh danh: "<<madd<<endl;
		cout<<"Ho ten: "<<hoten<<endl;
	}
	
	Nhanvien::Nhanvien(){
		namsinh=0;
		hsl=0;
	}
	
	Nhanvien::~Nhanvien(){}		
	
	void Nhanvien::nhap(){
		Nguoi::nhap();
		cout<<"Nhap nam sinh: ";
		cin>>namsinh;
		
		cout<<"Nhap he so luong: ";
		cin>>hsl;
		
		cin.ignore();
	}
	
	float Nhanvien::tinhluong(){
		return hsl*1550+phucap;
	}
	
	void Nhanvien::xuat(){
		Nguoi::xuat();
		
		cout<<"Nam sinh: "<<namsinh<<endl;
		cout<<"He so luong: "<<hsl<<endl;
		cout<<"Luong: "<<tinhluong()<<endl;
	}
	
	bool Nhanvien::operator < (Nhanvien a){
		return tinhluong() < a.tinhluong();
	}
	
	
	int main(){
		//cau 1
		Nguoi ng;
		cout<<"Nhap 1 nhan vien: "<<endl;
		ng.nhap();
		
		//cau2
		cout<<"\nThong tin nhan vien\n"<<endl;
		ng.xuat();
		
		//cau3
		int n;
		cout<<"Nhap so nhan vien: "<<endl;
		cin>>n;
		cin.ignore();
		
		Nhanvien ds[100];
		
		for ( int i = 0; i<n; i++){
			cout<<"\nNhan vien thu "<<i+1<<endl;
			ds[i].nhap();
		}
		
		cout<<"\nDanh sach nhan vien\n"<<endl;
		for ( int i =0; i<n; i++){
			ds[i].xuat();
			cout<<endl;
		}
		
		//cau 5
		for ( int i = 0; i<n-1; i++){
			for ( int j = i+1; j<n; j++){
				if( ds[i] < ds[j]){
					Nhanvien temp;
					temp = ds[i];
					ds[i] = ds[j];
					ds[j] = temp;
				}
			}
		}
		
		cout<<"\nDanh sach nhan vien xep theo luong GIAM dan\n"<<endl;
		for ( int i = 0; i<n; i++){
			ds[i].xuat();
			cout<<endl;
		}
		
		
		
		return 0;
		}























