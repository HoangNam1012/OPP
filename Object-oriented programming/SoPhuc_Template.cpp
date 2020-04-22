#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
class SP
{
	private: 
		int thuc,ao;
	public:
		SP()
		{
			thuc=0;
			ao=0;
		}
		void nhap()
		{
			cout<<"nhap phan thuc: ";
			cin>>thuc;
			cout<<"nhap phan ao: ";
			cin>>ao;
		}
		friend istream& operator>>(istream& is,SP &a)//em thieu tham chieu &
		{
			a.nhap();
			return is;
		}
		friend ostream& operator<<(ostream& os,SP a)
		{
			os<<a.ao<<"+"<<a.thuc<<"i"<<endl;//thay bo sung chuoi "i"
			return os;
		}
		SP operator+(SP a)
		{
			SP b;
			b.thuc=thuc+a.thuc;
			b.ao=ao+a.ao;
			return b;
		}
		
};
template<class T>
class DS
{
	private: 
		T *array;
		int size;
	public:
		DS()
		{
			size=0;
			array=new T[size];	
		}
		DS(int s)
		{
			size=s;
			array=new T[s];	
		}
		~DS()
		{
			cout<<"\n ham huy\n";
		}
		void nhap()
		{
			cout<<"nhap so luong phan tu: ";
			cin>>size;
			array=new T[size];
			for(int i=0;i<size;i++)
			{
				cin>>array[i];
			}
		}
		void xuat()
		{
			for(int i=0;i<size;i++)
			{
				cout<<array[i];
			}
		}
		T tinhtong()
		{
			T tong;
			for(int i=0;i<size;i++)
			{
				tong=tong+array[i];
			}
			return tong;
		}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	DS<SP> a;//chu y cho nay
	a.nhap();
	a.xuat();
	cout<<"tong cua cac SP vua nhap la: "<<a.tinhtong();
	
	
	return 0;
}
