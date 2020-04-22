#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<math.h>
using namespace std;
class Point
{
	float x,y;
	public :
	Point()
	{
		x=0;
		y=0;
	}
	Point(float x1,float y1)
	{
		x = x1;
		y = y1;
	}
	~Point()
	{
	}
	void nhap()
	{
		cout<<"nhap x = ";
		cin>>x;
		cout<<"nhap y = ";
		cin>>y;
	}
	void xuat()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
	friend istream &operator >>(istream &is,Point &a)
	{
		a.nhap();
		return is;
	}
	friend ostream &operator <<(ostream &os,Point &a)
	{
		a.xuat();
		return os;
	}
	friend float KhoangCach(Point A,Point B)
	{
		float z;
		z = sqrt(pow((B.x-A.x),2)+pow((B.y-A.y),2));
		return z;
	}
};
class Dagiac
{
	Point *a;
	int size;
	public :
	Dagiac()
	{
		size = 0;
		a = new Point[size];
	} 
	Dagiac(int size1)
	{
		size = size1;
		a = new Point[size];
	}
	~Dagiac()
	{
	}
	void nhap()
	{
		cout<<"nhap so luong toa do : ";
		cin>>size;
		a = new Point[size];
		for(int i=0;i<size;i++)
		{
			cin>>a[i];
		}
	}
	void xuat()
	{
		for(int i=0;i<size;i++)
		{
			cout<<a[i];
		}
	}
	friend istream &operator >>(istream &is,Dagiac &b)
	{
		b.nhap();
		return is;
	}
	friend ostream &operator <<(ostream &os,Dagiac &b)
	{
		b.xuat();
		return os;
	}
	int getsize()
	{
		return size;
	}
	bool kiemtra()
	{
		if(size == 3)
		{
			float p = (KhoangCach(a[0],a[1]));
			float o = (KhoangCach(a[1],a[2]));
			float i = (KhoangCach(a[0],a[2]));
			if((p+o>i)||(p+i)>o||(o+i)>p)
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
};
int main()
{
	Dagiac a[100];
	int n;
	int dem = 0;
	cout<<"nhap so luong da giac : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"toa do  da giac thoa man la tam giac : "<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].kiemtra() ==1 )
		{
			dem++;
			cout<<"da giac thu "<<dem<<endl;
			cout<<a[i];
		}
	}
}
