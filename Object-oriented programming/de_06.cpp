#include<conio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;
class may
{
	private : 
	float trongluong;
	int namsx;
	string hangsx;
	public :
		//friend class mayinkim;
	may()
	{
		trongluong = 0;
		namsx = 0;
		hangsx = "";
	}
	may(float trongluong1,int namsx1,string hangsx1)
	{
		trongluong = trongluong1;
		namsx = namsx1;
		hangsx = hangsx1;
	}
	~may()
	{
	}
	virtual void tenlm()
	{
	}
	virtual void nhap()
	{
		cout<<"nhap trong luong : ";
		cin>>trongluong;
		cout<<"nhap nam sx : ";
		cin>>namsx;
		cout<<"nhap hang sx : ";
		fflush(stdin);
		getline(cin,hangsx);
	}
	virtual void xuat()
	{
		cout<<"trong luong   : "<<trongluong<<endl<<"nam san xuat  : "<<namsx<<endl<<"hang san xuat : "<<hangsx<<endl;
	}
	friend istream &operator>>(istream &is, may &may)
	{
		may.nhap();
		return is;
	}
	friend ostream &operator<<(ostream &os, may &may)
	{
		may.xuat();
		return os;
	}
	virtual float gettrongluong()
	{
		return trongluong;
	}
	friend bool operator>(may a, may b) 
	{
		
		if(a.gettrongluong()>b.gettrongluong())
			return true;
		else return false;
		
	}
	virtual void inLoaiMay()
	{
		cout<<"May BT";
	}
};
class mayinkim : public may
{	
	protected : 
	int sokim ;
	int tocdoin;
	public : 
	mayinkim(): may()
	{
		sokim = 0;
		tocdoin = 0;
	}
	mayinkim(int sokim1,int tocdoin1,float trongluong1,int namsx1,string hangsx1) : may(trongluong1,namsx1,hangsx1)
	{
		sokim = sokim1;
		tocdoin = tocdoin1;
	}
	~mayinkim()
	{
	}
	void nhap()
	{
		may::nhap();
		cout<<"nhap so kim : ";
		cin>>sokim;
		cout<<"nhap toc do in : ";
		cin>>tocdoin;
	}
	void inLoaiMay()
	{
		cout<<"May in kim";
	}
	void xuat()
	{
		cout<<"===================================="<<endl;
		cout<<"may in kim : "<<endl;
		may::xuat();
		cout<<"so kim        : "<<sokim<<endl<<"toc do in     : "<<tocdoin<<endl;
	}
	friend istream &operator>>(istream &is, mayinkim &mayinkim1)
	{
		mayinkim1.nhap();
		
		return is;
	}
	friend ostream &operator<<(ostream &os, mayinkim &mayinkim)
	{
		mayinkim.xuat();
		return os;
	}

};
class mayinlaser : public may
{
	int dophangiai;
	int tocdoin;
	public : 
	mayinlaser() : may()
	{
		dophangiai = 0;
		tocdoin = 0;
	}
	mayinlaser(int dophangiai1,int tocdoin1,float trongluong1,int namsx1,string hangsx1):may(trongluong1,namsx1,hangsx1)
	{
		dophangiai = dophangiai1;
		tocdoin = tocdoin1;
	} 
	~mayinlaser()
	{
	}
	void nhap()
	{
		may::nhap();
		cout<<"nhap do phan giai : ";
		cin>>dophangiai;
		cout<<"nhap toc do in : ";
		cin>>tocdoin;
	}
	void xuat()
	{	cout<<"===================================="<<endl;
		cout<<"may in laser : "<<endl;
		may::xuat();
		cout<<"do phan giai  : "<<dophangiai<<endl<<"toc do in     : "<<tocdoin<<endl;
	}	
	friend istream &operator>>(istream &is, mayinlaser &mayinlaser)
	{
		mayinlaser.nhap();
		return is;
	}
	friend ostream &operator<<(ostream &os, mayinlaser &mayinlaser)
	{
		mayinlaser.xuat();
		return os;
	}
	void inLoaiMay()
	{
		cout<<"May in laser";
	}
	void inTSKT()
	{
		cout<<dophangiai<<tocdoin;
	}
};
int main()
{
	may *a[100];
	int n,m;
	cout<<"nhap so luong may in kim : ";
	cin>>n;
	cout<<"nhap so luong may in laser : ";
	cin>>m;
	for(int i=0;i<n;i++)
	{
		cout<<"nhap may in kim"<<endl;
		a[i]= new mayinkim;
		cin>>*a[i];
	}
	for(int i=n;i<m+n;i++)
	{

		cout<<"nhap may in laser"<<endl;
		a[i] = new mayinlaser;
		cin>>*a[i];
	}	
	
	for(int i=0;i<n+m;i++)
	{
		cout<<endl;
		cout<<*a[i];
	}
	for(int i=0;i<n+m-1;i++)
	{
		for(int j=i+1;j<n+m;j++)
		{
			if(*a[i] > *a[j])
			{
				may *temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout<<"Sap xep\n";
	for(int i=0;i<n+m;i++)
	{
		cout<<endl;
		cout<<*a[i];
	}
	cout<<"In loai may\n";
	for(int i=0;i<n+m;i++)
	{
		cout<<endl;
		a[i]->inLoaiMay();
	}
}

