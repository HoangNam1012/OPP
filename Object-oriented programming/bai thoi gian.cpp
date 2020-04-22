#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
class ThoiGian
{
	int gio,phut,giay,tong;
	public :
	ThoiGian()
	{
		gio = 0;
		phut = 0;
		giay = 0;
	}
	void nhap()
	{
		cout<<"nhap gio : ";cin>>gio;
		cout<<"nhap phut : ";cin>>phut;
		cout<<"nhap giay : ";cin>>giay;
	}
	void xuat()
	{
		cout<<"thoi gian vua nhap la : "<<endl;
		cout<<gio<<":"<<phut<<":"<<giay<<endl;
	}
	friend istream& operator >>(istream &is, ThoiGian &a)
	{
		a.nhap();
		return is;
	}
	friend ostream &operator <<(ostream &os, ThoiGian &a)
	{
		a.xuat();
		return os;
	}
	int getthoigian()
	{
		tong = gio*3600+phut*60+giay;
		return tong;
	}
	friend int khoangcach(ThoiGian a,ThoiGian b)
	{
		int kc;
		if(a.getthoigian()>b.getthoigian())
		{
			kc = a.getthoigian()-b.getthoigian();
			return kc;
		}
		else
		{
			kc = b.getthoigian()-a.getthoigian();
			return kc;
		}
	}
	bool operator >(const ThoiGian& a,const ThoiGian& b)
	{
		if(a.getthoigian()>b.getthoigian())
		{
			return true;
		}
		else return false;
	}
};
template<class T>
class DanhSach
{
	T *arr;
	int size;
	public : 
	DanhSach()
	{
		size = 0;
		arr = new T[size];
	}
	DanhSach(int size1)
	{
		size = size1;
		arr = new T[size1];
	}
	void nhap()
	{
		cout<<"nhap so luong thoi gian : ";
		cin>>size;
		arr = new T[size];
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
	}
	void xuat()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i];
		}
	}
	friend istream& operator >>(istream &is, DanhSach &a)
	{
		a.nhap();
		return is;
	}
	friend ostream &operator <<(ostream &os, DanhSach &a)
	{
		a.xuat();
		return os;
	}
	T sapxep()
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(arr[i]>arr[j])
				{
					T temp;
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	
};
int main()
{
	DanhSach<ThoiGian> a;
	cin>>a;
	cout<<a;
	a.sapxep();
	cout<<"sap xep tang dan theo thoi gian : "<<endl;
	cout<<a;
}
