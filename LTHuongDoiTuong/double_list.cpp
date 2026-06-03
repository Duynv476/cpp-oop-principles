#include<iostream>
using namespace std;
typedef struct{
    int Masv;
    string Hovaten;
}Sinhvien;

typedef struct Node{
    Sinhvien data;
    Node *Next;
    Node *Prev;  // Thêm con tr? tr? v? node tru?c
};

typedef struct{
    Node *head;
    Node *tail;
}Ds;

void khoitao(Ds &l){
    l.head=NULL;
    l.tail=NULL;
}

int ktrarong(Ds l){
    if(l.head==NULL) return 1;
    return 0;
}

void nhapdata(Sinhvien &x){
    cout<<"Nhap ma sinh vien: ";
    cin>>x.Masv;cin.ignore();
    cout<<"Nhap ho va ten sinh vien: ";
    getline(cin,x.Hovaten);
}

void hienthidata(Sinhvien x){
    cout<<"Ma sinh vien:"<<x.Masv;
    cout<<"\tHo va ten:"<<x.Hovaten<<endl;
}

Node* Tao_Node(Sinhvien x){
    Node *p=new Node;
    if(p==NULL) return NULL;
    p->data=x;
    p->Next=NULL;
    p->Prev=NULL;  // Kh?i t?o Prev
    return p;
}

void chendau(Ds &l,Node *p){
    if(ktrarong(l)){
        l.head=p;
        l.tail=p;
    }else{
        p->Next=l.head;
        l.head->Prev=p;  // C?p nh?t Prev
        l.head=p;
    }
}

void chencuoi(Ds &l,Node *p){
    if(ktrarong(l)){
        l.head=p;
        l.tail=p;
    }else{
        l.tail->Next=p;
        p->Prev=l.tail;  // C?p nh?t Prev
        l.tail=p;
    }
}
