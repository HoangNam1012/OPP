#include<stdio.h>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class Diem
{
	private : 
	int x,y;
	public : 
	Diem()
	{
		x = 0;
		y = 0;
	}
	~Diem()
	{
	}
	friend istream &operator>>(istream &is,Diem &a)
	{
		cout<<"nhap toa do diem x :";is>>a.x;
		cout<<"nhap toa do diem y :";is>>a.y;
	}
	friend ostream &operator<<(ostream &os,Diem &a)
	{
		cout<<"("<<a.x<<","<<a.y<<")";
	}
	friend float KhoangCach(Diem A,Diem B)
	{
		float z;
		z = sqrt(pow((B.x-A.x),2)+pow((B.y-A.y),2));
		return z;
	}
};
int main()
{
	Diem a[100];
	int n;
	cout<<"nhap so luong toa do :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	if(n==3)
	{
			float p = (KhoangCach(a[0],a[1]));
			float o = (KhoangCach(a[1],a[2]));
			float i = (KhoangCach(a[0],a[2]));
			if((p+o>i)||(p+i)>o||(o+i)>p)
			{
				cout<<"\n3 diem vua nhap la 1 tam giac";
			}
			else
			{
				cout<<"\n3 diem vua nhap khong phai la 1 tam giac";
			}
	}
	else
	{
		cout<<"\nso diem vua nhap khong phai la 1 tam giac";
	}
}
