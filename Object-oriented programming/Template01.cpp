/*template1.cpp*/ 
#include <iostream> 
#include <conio.h>
using namespace std;

template <class U> U min1(U a, U b) {
	if ( a < b) return a;
	else return b;
}
int main() {
	int n = 4, p = 12;
	float x = 2.5, y= 3.25;
	max<int>(n, p);  
	cout<<"min (n, p) = "<<min1(n,p)<<"\n";//int min(int, int)
	cout<<"min (x, y) = "<<min1(x,y)<<"\n";//float min(float, float)
	char* adr1="DHBK";
	char* adr2="CDSD";
	cout<<"min(adr1,adr2)="<<min1(adr1,adr2);
	getch();
}
