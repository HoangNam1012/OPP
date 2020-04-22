/*template2.cpp*/
#include <iostream> 
#include <conio.h>
using namespace std;
template<typename T> T min1(T a,T b)
{
	if(a<b)
		return a;
	else
		return b;
}
class vect
{
	int x,y;
	public:
		vect(int abs=0,int ord=0){
			x=abs,y=ord;
		}
		void display(){
			cout<<x<<""<<y<<"\n";
		}
		friend int operator<(vect,vect);
};
int operator<(vect a,vect b){
	return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
}
int main(){
	vect u(3,2),v(4,1);
	cout<<"min(u,v)=";
	min1(u,v).display();
	getch();
}

