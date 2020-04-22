#include<bits\\stdc++.h>
#include<ostream>
#include<string>
using namespace std;
class NV{
	protected:
		string id;
		string ht;
		int tuoi;
	public:
		NV(){
			id="";
			ht="";
			tuoi=18;
		}
		NV(string id1,string ht1,int tuoi1){
			id=id1;
			ht=ht1;
			tuoi=tuoi1;
		}
		virtual void nhap(){
			cout<<"nhap ma nhan vien:";fflush(stdin);getline(cin,id);
			cout<<"nhap ho va ten :";fflush(stdin);getline(cin,ht);
			cout<<"nhap tuoi:";cin>>tuoi;
		}
		virtual void xuat()
		{
			cout<<id<<setw(5)<<ht<<setw(5)<<tuoi;
		}
		virtual float tongluong()
		{		
		}
		virtual void ktra()
		{
			if(tuoi>=60)
			{
				xuat();
				cout<<tongluong();
			}
		}
};
class CN:public NV{
	private:
		int mluong;
		string taynghe;
		int ngaycong;
		public:
		CN(){
			mluong=5;
			taynghe="";
			ngaycong=5;
		}
		CN(int mluong1,string taynghe1,int ngaycong1,string id1,string ht1,int tuoi1):NV(id1, ht1, tuoi1){
			mluong=mluong1;
			taynghe=taynghe1;
			ngaycong=ngaycong1;
		}
		void nhap(){
			NV::nhap();
			cout<<"nhap muc luong:";cin>>mluong;
			cout<<"nhap tay nghe:";fflush(stdin);getline(cin,taynghe);
			cout<<"nhap ngay cong:";cin>>ngaycong;
		}
		void xuat(){
			cout<<"\nthong tin cong nhan : \n";
			NV::xuat();
			cout<<setw(5)<<mluong<<setw(5)<<taynghe<<setw(5)<<ngaycong<<endl;
		}
		float tongluong()
		{
			return mluong*ngaycong;
		}
		void ktra()
		{
			if(tuoi>=60)
			{
				xuat();
				cout<<"tong luong : "<<tongluong();
			}
		}
};
class CB:public NV{
	private:
		int hsl;
		string trinhdo;
		int phucap;
		public:
		CB(){
			hsl=1;
			trinhdo="";
			phucap=1;
		}
		CB(int hsl1,string trinhdo1,int phucap1,string id1,string ht1,int tuoi1):NV(id1, ht1, tuoi1){
			hsl=hsl1;
			trinhdo=trinhdo1;
			phucap=phucap1;
		}
		void nhap(){
			NV::nhap();
			cout<<"nhap he so luong:";cin>>hsl;
			cout<<"nhap trinh do:";fflush(stdin);getline(cin,trinhdo);
			cout<<"nhap phu cap:";cin>>phucap;
		}
		void xuat(){
			cout<<"\nthong tin can bo : \n";
			NV::xuat();
			cout<<setw(5)<<hsl<<setw(5)<<trinhdo<<setw(5)<<phucap<<endl;
		}
		float tongluong(){
			return hsl*14500+phucap;
		}
		void ktra()
		{
			if(tuoi>=60)
			{
				xuat();
				cout<<"tong luong : "<<tongluong();
			}
		}
};
int main(){
	NV *b[100];
	int n;
	cout<<"nhap so nhan vien:";cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nChon CV cua ban:";
		cout<<"\n1: CONG NHAN";
		cout<<"\n2: CAN BO";
		int chon;cout<<"\nchon:";cin>>chon;
		if(chon==1){
			b[i]=new CN;
			b[i]->nhap();
		}
		else if(chon==2){
			b[i]=new CB;
			b[i]->nhap();
		}
	}
	for(int i=0;i<n;i++)
	{
		b[i]->xuat();
	}
	cout<<"\ndanh sach nhan vien da ve huu : \n";
	for(int i=0;i<n;i++)
	{
		b[i]->ktra();
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[i]->tongluong()>b[j]->tongluong())
			{
				NV *temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp; 
			}
		}
	}
	cout<<"\nsap xep nhan vien theo tang dan ve luong : \n";
	for(int i=0;i<n;i++)
	{
		b[i]->xuat();
	}
}
