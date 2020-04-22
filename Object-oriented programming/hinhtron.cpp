#include<bits/stdc++.h>
using namespace std;
class diem
{
public:
    float hd;
    float td;
    friend istream & operator >>(istream & is, diem & d )
    {
        cout<<("nhap hoanh do :");
        is>>d.hd;
        cout<<("nhap tung do :");
        is>>d.td;
    }
    void xuat ()
    {
        cout<<("tung do: ",td,setw(5),"hoang do ",hd);
    }
    float kc(diem a, diem b)
    {
        float kc;
        return kc=sqrt((a.hd-b.hd)*(a.hd-b.hd)+(a.td-b.td)*(a.td-b.td));
    }
};
class hinhtron:public diem
{
   private:
       diem d;
       float bk;
   public:
        float cv()
        {
            return bk*2*3.14;
        }
        float dientich()
        {
            return bk*bk*3.14;
        }
        friend istream & operator(istream &s, hinhtron &h)
        {
                cout<<"nhap trong tam hinh tron :";
                is>>h.d;
                cout<<"nhap ban kinh :";
                is>>h.bk;
        }

};
