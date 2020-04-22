#include<conio.h>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class CanBo
{
	protected:
	char hoten[25];
	long int CMND;
	char phongban[30];
public:
	virtual void nhap()
	{
		cout<<"nhap ho ten can bo:";
		fflush(stdin);
		gets(hoten);
		cout<<"nhap so CMND can bo:";
		fflush(stdin);
		cin>>CMND;
		cout<<"nhap phong ban can bo:";
		fflush(stdin);
		gets(phongban);
	}
	friend ostream& operator<<(ostream& os, CanBo cb)
	{
		os<<"=========================================="<<endl;
		os<<"ten"<<setw(10)<<"CMND"<<setw(10)<<"phong ban"<<endl;
		os<<cb.hoten<<setw(10)<<cb.CMND<<setw(10)<<cb.phongban<<endl;
		return os;
	}
	friend istream& operator>>(istream& is, CanBo &cb)
	{
		cb.nhap();
		return is;
	}
	virtual float tongluong()
	{
		return 1;
	}
};

class BienChe:public CanBo
{
private:
	int bac;
public:
	void nhap()
	{
		CanBo::nhap();
		cout<<"nhap bac luong cua can bo:";
		fflush(stdin);
		cin>>bac;
	}
	friend ostream& operator<<(ostream& os, BienChe bc)
	{
		CanBo c = bc;
		os<<bc;
		os<<setw(5)<<bc.bac;
		return os;
	}
	friend istream& operator>>(istream& is, BienChe &bc)
	{
		bc.nhap();
		return is;
	}
	float tongluong()
	{
		return bac*2;
	}
};

class HopDong:public CanBo
{
private:
	float sogio;
	float tc1gio;
public:
	void nhap()
	{
		CanBo::nhap();
		cout<<"nhap so gio lam cua can bo:";
		fflush(stdin);
		cin>>sogio;
		cout<<"nhap tien cong 1 gio lam cua can bo:";
		fflush(stdin);
		cin>>tc1gio;
	}
	friend ostream& operator<<(ostream& os, HopDong hd)
	{
		CanBo c = hd;
		os<<c;
		os<<setw(5)<<hd.sogio<<setw(5)<<hd.tc1gio;
		return os;
	}
	friend istream& operator>>(istream& is, HopDong &hd)
	{
		hd.nhap();
		return is; 
	}
	float tongluong()
	{
		return sogio*tc1gio;
	}
};

int main()
{
	CanBo *A[100];
	int n;
	cout<<"nhap so luong can bo:";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"chon can bo:"<<endl;
		cout<<"1.Bien Che:"<<endl;
		cout<<"2.Hop Dong:"<<endl;
		int chon;
		cout<<"chon:";
		cin>>chon;
		if(chon == 1)
		{
			A[i] = new BienChe();
			cin>>*A[i];
		}
		else
		{
			A[i] = new HopDong();
			cin>>*A[i];
		}
	}
	for(int i=0; i<n; i++)
	{
		cout<<*A[i];
	}
	cout<<"luong cua can bo:";
	for(int i=0; i<n; i++)
	{
		cout<<A[i]->tongluong()<<endl<<"luong cua can bo:";	
	}
	//cout<<"luong cua can bo hop dong:";
	//for(int i=0; i<n; i++)
	//{
		//cout<<A[i]->tongluong()<<endl;
	//}
}
