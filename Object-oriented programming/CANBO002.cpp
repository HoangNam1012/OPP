#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class NGUOI
 {
   protected : 	  
      char Hoten[50],Que[20],Ma[50];
      int Tuoi;
   public :
      NGUOI()
      {
      	strcpy(Ma," "); 
      	strcpy(Hoten," "); 
      	strcpy(Que," "); 
	  	Tuoi = 0;
	  }
	  NGUOI(char Hoten[50],char Que[20],char Ma[50],int Tuoi)
      {
      	strcpy(Ma,Ma); 
      	strcpy(Hoten,Hoten); 
      	strcpy(Que,Que); 
	  	Tuoi = Tuoi;
	  }
	  void nhap()
	  {
	  	cout<<"Nhap ma:";
	  	fflush(stdin);
	  	gets(Ma);//nhap chuoi
	  	cout<<"Nhap ten:";
	  	fflush(stdin);
	  	gets(Hoten);
	  	
	  	cout<<"Nhap tuoi:";
	  	cin>>Tuoi;
	  	
	  	cout<<"Nhap que:";
	  	fflush(stdin);
	  	gets(Que);
	  }
	  
	  void xuat()
	  {
	  	cout<<setw(10)<<Ma<<setw(20)<<Hoten<<setw(15)<<Que<<setw(5)<<Tuoi<<endl;
	  }
 };
class CANBO : public NGUOI
 {
   private : 
      float HSL, PC;
   public:
      CANBO()
      {
    
	  	HSL = 0;
	  	PC = 0;
	  }
	  CANBO(float HSL,float PC)
      {
	  	HSL = HSL;
	  	PC = PC;
	  }
	  void nhap()
	  {
	  	cin>>Tuoi;
	  	NGUOI::nhap();
	  	
		cout<<"Nhap HSL:";
	  	cin>>HSL;
	  	cout<<"Nhap PC:";
	  	cin>>PC;
	  }
	  
	  void xuat()
	  {
	  	NGUOI::xuat();
	  	cout<<setw(5)<<HSL<<setw(15)<<PC<<endl;
	  }
	  float Luong()
	  {
	  	float TL = 1500000 * HSL + PC;
	  	return TL;
	  }
 };
 

int main()
{
	CANBO A[100];
	int n;
	cout<<"Nhap so luong can bo:";
	cin>>n;
	
	for(int i = 0 ; i< n; i++)
	{
		A[i].nhap();
	}
	for(int i = 0 ; i< n; i++)
	{
		A[i].xuat();
	}
	
	
}
 
