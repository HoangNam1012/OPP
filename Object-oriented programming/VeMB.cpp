#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
class VMB
{
	private:
		char tenchuyen[30];
		char ngaybay[30];
		int gia;
	public:
		VMB()
		{
			strcpy(tenchuyen,"");
			strcpy(ngaybay,"");
			gia=0;
		}
		~VMB()
		{
			cout<<"\n ham huy\n";
			
		}
	    void nhap()
		{
			cout<<"nhap ten chuyen bay: ";
			fflush(stdin);
			gets(tenchuyen);
			cout<<"nhap ngay bay: ";
			gets(ngaybay);
			cout<<"nhap gia ve: ";
			cin>>gia;
		}
	    void hien()
		{
			cout<<tenchuyen<<"\t"<<ngaybay<<"\t"<<gia<<endl;
		}
		int getgiave()
		{
			return gia;
		}
};
class Nguoi
{
	private:
		char hoten[30];
		char gioitinh[30];
		int tuoi;
	public:
		Nguoi()
		{
			strcpy(hoten,"");
			strcpy(gioitinh,"");
			tuoi=0;
		}
		~Nguoi()
		{
			cout<<"\n ham huy\n";
			
		}
		void nhap()
		{
			cout<<"nhap ten KH : ";
			fflush(stdin);
			gets(hoten);
			cout<<"nhap gioi tinh: ";
			fflush(stdin);
			gets(gioitinh);
			cout<<"nhap tuoi: ";
			fflush(stdin);
			cin>>tuoi;
		}
		void hien()
		{
			cout<<hoten<<"\t"<<gioitinh<<"\t"<<tuoi<<"\t";
		}
		
};
class KH:public Nguoi
{
	private:
		VMB *ve;
		int soluong;
	public:
		KH()
		{
			soluong=0;
			ve=new VMB[soluong];
		}
		~KH()
		{
			cout<<"\n ham huy\n";
			
		}
		void nhap()
		{
			Nguoi::nhap();
			ve->nhap();
			cout<<"nhap so luong ve mua: ";
			fflush(stdin);
			cin>>soluong;
		}
		void hien()
		{
			Nguoi::hien();
			cout<<tongtien()<<endl;
		}
		int tongtien()
		{
			return  soluong*ve->getgiave();
		}
		
		
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n;
	cout<<"So khach hang la: ";
	cin>>n;
	KH h[n];
	for(int i=0;i<n;i++)
	{
		h[i].nhap();
	}
	for(int i=0;i<n;i++)
	{
		h[i].hien();
	}
	
	return 0;
}
