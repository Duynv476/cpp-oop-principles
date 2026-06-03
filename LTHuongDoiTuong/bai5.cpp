#include <iostream>
#include <string>

using namespace std;

class DATE{
	private:
		int ngay,thang,nam;
	public:
		DATE();
		void nhap();
		void xuat();
	
};

class MAYTINH: public DATE{
	private:
		string mamt;
		string tenmt;
		float giany;
		static float khuyenmai;
	
		
	public:
		MAYTINH();
		~MAYTINH();
		void nhap();
		void xuat();
		
		float Giabanreal();
		string getten(){
			return tenmt;
		}
		
};

DATE::DATE(){
	ngay=0;
	thang=0;
	nam=0;
}

void DATE::nhap(){
	do{
		cout<<"Nhap ngay: ";
		cin>>ngay;
	}
	while(ngay<=0|| ngay>31);
	
	do{	
		cout<<"nhap thang: ";
		cin>>thang;
	}
	while (thang <=0 || thang >12);

	do{	
		cout<<"Nhap nam: ";
		cin>>nam;

	}
	while( nam <=0);
	cin.ignore();
}

void DATE::xuat(){
	cout<<ngay<<"/"
		<<thang<<"/"
		<<nam<<endl;
}

MAYTINH::MAYTINH(){
	mamt = "";
	tenmt="";
	giany=0;
	
}

MAYTINH::~MAYTINH()
{
	}
	
void MAYTINH::nhap(){
	cout<<"Ma may tinh: ";
	getline(cin, mamt);
	
	cout<<"Ten may tinh: ";
	getline(cin, tenmt);
	
	DATE::nhap();
	
	do{	
		cout<<"Gia ban niem yet: ";
		cin>>giany;
	}	
	while (giany <=0);
	cin.ignore();
}

float MAYTINH::khuyenmai = 0.1;
float MAYTINH::Giabanreal(){
	return giany-giany*khuyenmai;
}

void MAYTINH::xuat(){
	cout<<"Ma may tinh: "<<mamt<<endl;
	
	cout<<"Ten may tinh: "<<tenmt<<endl;
	
	DATE::xuat();
	
	cout<<"Gia ban niem yet: "<<giany<<endl;
	
	cout<<"Khuyen mai: "<<khuyenmai<<endl;
	
	cout<<"Gia ban thuc te: "<<Giabanreal()<<endl;
}


	
int main(){
	DATE ngay;
	cout<<"Nhap 1 date\n";
	ngay.nhap();
	
	cout<<"Date vua nhap: ";
	ngay.xuat();
	
	int n;
	do{
		cout<<"Nhap so luong may tinh: ";
		cin>>n;
	}
	while (n <0);
	
	cin.ignore();
	
	MAYTINH ds[100];
	for ( int i =0; i<n; i++){
		cout<<"May tinh thu "<<i+1<<endl;
		ds[i].nhap();
	}
	
	cout<<"Danh sach may tinh\n"<<endl;
	for ( int i=0; i<n; i++){
		ds[i].xuat();
		cout<<endl;
	}
	
	int k=0;
	cout<<"danh sach may tinh ten ASUS\n";
	for ( int i=0; i<n; i++){
		if (ds[i].getten() == "ASUS"){
			ds[i].xuat();
			k++;
		}
	}
	
	if (k == 0){cout<<"Ko co";}
	
	float min = ds[0].Giabanreal();
	for ( int i = 1; i<n; i++){
		if (ds[i].Giabanreal() < min){
			min = ds[i].Giabanreal();
		}
	}
	
	cout<<"\nMay tinh co gia ban real min: ";
	for ( int i = 0; i<n; i++){
		if (min == ds[i].Giabanreal()){
			ds[i].xuat();
			cout<<endl;
		}
	}
	
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
