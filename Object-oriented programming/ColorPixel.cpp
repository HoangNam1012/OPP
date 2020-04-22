#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;
class color
{
	private:
		char tenmau[20];
		char mamau[20];		
	public:
		color()
		{
			strcpy(tenmau,"");
			strcpy(mamau,"");
		}
		~color()
		{
			cout<<"\n ham huy\n";
		}
		virtual void nhap()
		{
			cout<<"nhap ten mau: ";
			gets(tenmau);
			fflush(stdin);
			cout<<"nhap ma mau: ";
			gets(mamau);
		}
		friend istream& operator>>(istream& is,color &a)
		{
			a.nhap();
			return is;	
		} 
		virtual void xuat()
		{
			cout<<tenmau<<"\t"<<mamau;
		}
		friend ostream& operator<<(ostream& os,color a)
		{
			a.xuat();
			return os;
		}
		char* gettenmau()
		{
			return tenmau;
		}
		
};
class point
{
	private:
		int x,y;
		
	public:
		point()
		{
			x=y=0;
		}
		~point()
		{
			cout<<"\n ham huy \n";
		}
		virtual void nhap()
		{
			cout<<"nhap toa do x: ";
			cin>>x;
			cout<<"nhap toa do y: ";
			cin>>y;
		}
		friend istream& operator>>(istream& is,point &a)
		{
			a.nhap();
			return is;	
		} 
		virtual void xuat()
		{
			cout<<x<<"\t"<<y;
		}
		friend ostream& operator<<(ostream& os,point a)
		{
			a.nhap();
			return os;
		}
		void cheochinh()
		{
			if(x=y)
			cout<<"thuoc duong cheo chinh: ";
			else 
			cout<<"khong thuoc cheo chinh: ";
		}
		
		
		
};
class pixel:public point,public color
{
	public:
		friend istream& operator>>(istream& is,pixel &a)
		{
			a.color::nhap();
			a.point::nhap();
			return is;	
		} 
		friend ostream& operator<<(ostream& os,pixel a)
		{
			a.color::xuat();
			a.point::xuat();
			return os;
		}
		void kiemtra()
		{
			point::cheochinh();
			char* b=color::gettenmau();
			char *l="xanh";
			int m=strcmp(b,l);
			
			if(m==0)
			cout<<"co mau xanh";
			else
			cout<<"khong co mau xanh";
		}
		
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cout<<"so pixel can nhap: ";
	cin>>n;
	pixel a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	
	return 0;
}
