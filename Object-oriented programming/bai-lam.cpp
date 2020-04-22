#include<stdio.h>
#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std;
class CauThu
{
	string HoTen;
	int Tuoi;
	string ViTri;
	int CanNang;
	int ChieuCao;
	public : 
	CauThu()
	{
		HoTen = "";
		Tuoi = 0;
		ViTri = "";
		CanNang = 0 ;
		ChieuCao = 0;
	}
	~CauThu()
	{
	}
	void nhap()
	{
		cout<<"nhap ho ten : ";cin>>HoTen;
		cout<<"nhap tuoi : ";cin>>Tuoi;
		cout<<"nhap vi tri : ";cin>>ViTri;
		cout<<"nhap can nang : ";cin>>CanNang;
		cout<<"nhap chieu cao : ";cin>>ChieuCao;
	}
	void xuat()
	{
		cout<<"ho ten : "<<HoTen<<setw(5)<<" tuoi : "<<Tuoi<<setw(5)<<" vi tri : "<<ViTri<<setw(5)<<" can nang : "<<CanNang<<setw(5)<<" chieu cao : "<<ChieuCao<<endl;
	}
	friend istream &operator>>(istream &is,CauThu &a)
	{
		a.nhap();
		return is;
		
	}
	friend ostream &operator<<(ostream &os,CauThu &a)
	{
		a.xuat();
		return os;
	}
	virtual int getChieuCao()
	{
		return ChieuCao;
	}
	virtual int getCanNang()
	{
		return CanNang;
	}
	friend bool operator <(CauThu a,CauThu b)
	{
		if(a.getChieuCao()<b.getChieuCao())
		{
			return true;
		}
		else if(a.getCanNang()<b.getCanNang())
		{
			return true;
		}
		else return false;
	}
};
template<class T,class X>
void swap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

class DanhSach
{
	CauThu * ds;
	int size;
	public : 
	DanhSach()
	{
		size = 0;
		ds = new CauThu[size];
	}
	void nhap()
	{
		cout<<"nhap so Cau Thu : ";
		cin>>size;
		ds = new CauThu[size];
		for(int i=0;i<size;i++)
		{
			cin>>ds[i];
		}	
	}
	void xuat()
	{
		for(int i=0;i<size;i++)	
		{
			cout<<ds[i];
		}
	}	
	friend ostream &operator<<(ostream &os,DanhSach &a)
	{
		a.xuat();
		return os;
	}
	friend istream &operator>>(istream &is,DanhSach &a)
	{
		a.nhap();
		return is;
	}
	void sapxep()
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(ds[i]<ds[j])
				{
					swap(ds[i],ds[j]);
				}
			}
		}
	}
};
int main()
{
	DanhSach a;
	cout<<"nhap danh sach cau thu : "<<endl;
	cin>>a;
	cout<<a;
	a.sapxep();
	cout<<"danh sach sau khi sap xep : \n";
	cout<<a;
	/////////////////////////////////////////////////

	int b[100],n;
	cout<<"nhap n so nguyen  :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"b["<<i<<"] : ";
		cin>>b[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<setw(5)<<b[i];
	}
}
