#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
class date 
{
	private:
		int ngay,thang,nam;
		friend class DS;
	public:
		date()
		{
			ngay=thang=nam=0;
		}
		~date()
		{
			cout<<"\n ham huy date\n";
		}
		friend istream& operator>>(istream& is, date &a)
		{
			cout<<"nhap ngay: ";
			cin>>a.ngay;
			cout<<"nhap thang: ";
			cin>>a.thang;
			cout<<"nhap nam: ";
			cin>>a.nam;
			return is;
		}
		friend ostream& operator<<(ostream& os, date a)
		{
			os<<a.ngay<<"/"<<a.thang<<"/"<<a.nam<<endl;
			return os;
		}
		friend bool operator >(date a,date b)
		{
			if(a.nam>b.nam)
			{
				return 1;
			}
			else if(a.nam<b.nam)
			{
				return 0;
			}
			else if(a.nam==b.nam)
			{
				if(a.thang>b.thang)
				{
					return 1;
				}
				else if(a.thang<b.thang)
				{
					return 0;
				}
				else if(a.thang==b.thang)
				{
					if(a.ngay>b.ngay)
					{
						return 1;
					}
					else 
					{
						return 0;
					}
				}
				
			}
			
		}
};
class DS
{
	private:
		date *arr;
		int size;
	public:
		int getSize()
		{
			return size;
		}
		DS()
		{
			size=0;
			arr=new date[size];
		}
		~DS()
		{
			cout<<"\n ham huy danh sach\n";
		}
		friend istream& operator>>(istream& is,DS &b)
		{
			cout<<"nhap so danh sach ngay: ";
			is>>b.size;
			b.arr=new date[b.size];
			for(int i=0;i<b.size;i++)
			{
				is>>b.arr[i];
				
			}
			return is;
		}
		friend ostream& operator<<(ostream& os,DS b)
		{
			for(int i=0;i<b.size;i++)
			{
				os<<b.arr[i];
				
			}
			return os;
			
		}
		void sapxep()
		{
			
			for(int i=0;i<size-1;i++)
			{
				for(int j=i+1;j<size;j++)
				{
					if(arr[i]>arr[j])
					{
						date tam=arr[i];
						arr[i]=arr[j];
						arr[j]=tam;
					}
				}
			}
		}
		
};


int main(int argc, char** argv) {
	DS a;
	cin>>a;
	cout<<a;
	a.sapxep();
	cout<<a;
	return 0;
}
