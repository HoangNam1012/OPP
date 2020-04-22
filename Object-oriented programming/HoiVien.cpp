#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
class date{
	public:
	int ngay , thang, nam;
	public:
		int getngay()
		{
			return ngay;
		}
		int getthang()
		{
			return thang;
		}
		int getnam()
		{
			return nam;
		}
		void nhap()
		{
			cout<<"nhap vao ngay -thang -nam:";
			cin>>ngay>>thang>>nam;
			
		}
		void xuat()
		{
			cout<<"ngay"<<ngay<<"thang"<<thang<<"nam"<<nam;
		}
};
class HV:public date{
	public:
		char hoten[20];
		char diachi[20];
	public:
		
		void nhap()
		{ 
		    date::nhap();
			cout<<"nhap vao ho ten hoi vien:";
			fflush(stdin);
			gets(hoten);
			cout<<"nhap vao dia chi hoi vien:";
			fflush(stdin);
			gets(diachi);
		}
		void xuat()
		{
			date::xuat();
			cout<<"ho ten"<<hoten<<"diachi"<<diachi<<endl;
		}
};
class GD:public HV{
	public:
		char tenvo[10];
	public :
		void nhap ()
		{
			HV::nhap();
			cout<< "nhap vao ten vo:";
			fflush(stdin);
			gets(tenvo);
		}
		void xuat()
		{ 
		    HV:xuat();
			cout<<"ten vo:"<<tenvo;
		}
};
class NY:public GD{
	private :
		int sdt;
	public:
		void nhap()
		{
			GD::nhap();
			cout<<"nhap vao sdt :";
			cin>>sdt;
		}
		void xuat()
		{
			GD::xuat();
			cout<<"sdt"<<sdt;
		}
		
};
class DSHV{
	int n;
	NY a[100];
	public:
		void setN()
		{
			cout<<"nhap vao danh sach hoi vien:"<<endl;
			cin>>n;
			
		}
		void nhap()
		{
			for(int i=0;i<n;i++)
			{
				a[i].nhap();
				cout<<endl;
			}
		}
		void xuat()
		{
			for(int i=0;i<n;i++)
			{
				a[i].xuat();
				cout<<endl;
			}
		}
		void Ngaycuoi()
		{
			cout<<"hoi vien co ngay cuoi 11.11.2011"<<endl;
			for(int i=0;i<n;i++)
			{
				if(a[i].getngay()==11 && a[i].getthang()==11 && a[i].getnam()==2011)
				{
					cout<<"hoten"<<a[i].hoten<<setw(5)<<"diachi"<<a[i].diachi<<setw(5)<<"ten vo"<<a[i].tenvo;
			    }
			}
		}
		

};
int main()
{
	DSHV ds;
	ds.setN();
	ds.nhap();
	
	ds.Ngaycuoi();
	ds.xuat();
}

