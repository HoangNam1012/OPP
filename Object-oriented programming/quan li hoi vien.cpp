#include<bits/stdc++.h>
using namespace std;
class date
{
private:
    int day, month, year;

public:
    date(int d=0, int m=0, int y=0);
    ~date();
    void set_date(int d, int m, int y);
    date get_date();
    int maxday( int m, int y);
};
date::date(int d, int m, int y)
{
    set_date(d,m,y);
}
date::~date()
{
}
int date::maxday(int m, int y)
{
    int mon[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if( ((y%4==0)&&(y%100!=0))||y%400==0)
        mon[2]=29;
    return (mon[m]);
}
class nguoi
{
protected:
    char ht[30];
    char dc[30];
public:
    friend istream & operator ( istream & is, nguoi &a)
    {
        cout<<"nhap ho va ten :";
        is>>a.ht;
        cout<<"nhap dia chi :";
        is>>a.dc;
    }
};
class cgd : public nguoi
{
private:
    date t;
    nguoi vo;
public:
   friend istream & operator(istream &is, cgd &a)
   {
       cout<<"nhap ho va ten vo :";
       cin0
   }
};
