#include <iostream>
#include <string>
using namespace std;
class ptgt{
	protected:
		string hangsx;
		string ten;
		int namsx;
		float Vmax;
		
	public:
		ptgt();
		~ptgt();
		void nhap();
		void xuat();
		
		string gethangsx(){
			return hangsx;
		} 
		
};

class oto: public ptgt{
	private:
		int sochongoi;
		string kieudongco;
		
	public:
		oto();
		~oto();
		void nhap();
		void xuat();
		
		float Vcoso();
		
};

ptgt::ptgt(){
	hangsx="";
	ten="";
	namsx=0;
	Vmax=0;
}

ptgt::~ptgt(){}
 
void ptgt::nhap(){
	cout<<"Nhap hang san xuat: ";
	getline(cin, hangsx);
	
	cout<<"Nhap ten phuong tien: ";
	getline(cin, ten);
	
	cout<<"Nam san xuat: ";
	cin>>namsx; 
	
	cout<<"Van toc toi da: ";
	cin>>Vmax;
	
	cin.ignore(); 
}


void ptgt::xuat(){
	cout<<"Hang sx: "<<hangsx<<endl;
	cout<<"Ten phuong tien: "<<ten<<endl;
	cout<<"Nam sx: "<<namsx<<endl;
	cout<<"Van toc toi da: "<<Vmax<<endl;
	}
	
oto::oto(){
	sochongoi=0;
	kieudongco="";
}

oto::~oto(){}

void oto::nhap(){
	ptgt::nhap();
	
	cout<<"So cho ngoi: ";
	cin>> sochongoi;
	cin.ignore(); 
	
	cout<<"Kieu dong co: ";
	getline(cin, kieudongco); 
	
}

float oto::Vcoso(){
	return Vmax/4; 
} 

void oto::xuat(){
	ptgt::xuat();
	
	cout<<"So cho ngoi: "<<sochongoi<<endl;
	cout<<"Kieu dong co: "<<kieudongco<<endl;
	cout<<"Van toc co so: "<<Vcoso()<<endl;
}

int main ()
{
	ptgt pt;
	cout<<"Nhap 1 pt giao thong: "<<endl;
	pt.nhap();
	
	cout<<"Phuong tien vua nhap: "<<endl;
	pt.xuat();
	
	int n;
	cout<<"Nhap so pt giao thong: "<<endl;
	cin>>n;
	cin.ignore();
	
	oto  ds[100];
	
	for ( int i=0; i<n; i++){
		cout<<"\nNhap pt thu "<<i+1<<endl;
		ds[i].nhap();
	} 
	
	cout<<"\nDanh sach phuong tien\n"<<endl;
	for ( int i = 0; i<n; i++){
		ds[i].xuat();
		cout<<endl;	 
	} 
	
	cout<<"\nDanh sach oto hang Honda\n"<<endl;
	int k=0;
	for ( int i=0; i<n; i++){
		if (ds[i].gethangsx() == "Honda"){
			ds[i].xuat();
			k++; 
		} 
	} 
	
	if (k==0){
		cout<<"Ko co xe nao"; 
	} 
	return 0; 
 } 


















