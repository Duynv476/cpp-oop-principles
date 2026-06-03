#include <iostream>
#include <string>
using namespace std;
class date{
	private:
		int ngay,thang,nam;
	
	public:
		date(){
			ngay=0;
			thang=0;
			nam=0;
		};
		
		void nhap1();
		void xuat1();
};

class muontra: public date{
	private:
		string madg;
		string masach;
		int soluong;
		static float phicuoc;
	
	public:
		muontra(){
			madg="";
			masach="";
			soluong=0;
		}
		
		void nhap2();
		void xuat2();
		
		float tienmuon();
		
		bool operator < (muontra a);
		
		
};

float muontra::phicuoc=10;
float muontra::tienmuon(){
	return soluong*phicuoc;
}

void date::nhap1(){
	do{
		cout<<"nhap 1 date: ";
		cin>>ngay>>thang>>nam;
	}
	while ( ngay<=0 || ngay >31 || thang <=0 ||thang >12|| nam <=0);
	cin.ignore();
}

void date::xuat1(){
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;						
}


void muontra::nhap2(){
	cout<<"Ma doc gia: ";
	getline(cin, madg);
	
	cout<<"Ma sach: ";
	getline(cin, masach);
	
	date::nhap1();
	
	do{cout<<"so luong: ";
	cin>>soluong;
	}
	while ( soluong<= 0);
	
	cin.ignore();
}

void muontra::xuat2(){
	cout<<"Ma doc gia: "<<madg<<endl;
	cout<<"ma sach: "<<masach<<endl;
	date::xuat1();
	cout<<"so luong: "<<soluong<<endl;
	cout<<"Phi cuoc: "<<phicuoc<<endl;
	cout<<"Tien muon: "<<tienmuon()<<endl;
}

bool muontra::operator <(muontra a){
	return soluong < a.soluong;
}

int main(){
	date da;
	cout<<"Nhap 1 date\n";
	da.nhap1();
	
	cout<<"Date vua nhap: ";
	da.xuat1();
	
	int n;
	do{
		cout<<"Nhap so luong muon tra: ";
		cin>>n;
	}
	while (n<=0);
	cin.ignore();
	
	muontra ds[100];
	
	for(int i=0;i<n; i++){
		cout<<"\nDoi tung muon tra thu "<<i+1<<endl;
		ds[i].nhap2();
	}
	
	cout<<"\ndanh sach muon tra\n";
	for (int i=0; i<n; i++){
		ds[i].xuat2();
		cout<<endl;
	}
	
	for ( int i=0; i<n-1; i++){
		for ( int j=i+1; j<n; j++){
			if(ds[i].tienmuon() < ds[j].tienmuon()){
				muontra temp;
				temp  = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	
	cout<<"\n sap xep giam theo tiem cuoc\n";
	for ( int i=0; i<n; i++){
		ds[i].xuat2();
		cout<<endl;
	}
	
	return 0;
}




















