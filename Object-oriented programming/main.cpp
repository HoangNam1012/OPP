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
class tamgiac: public diem
{
private:
    diem a;
    diem b;
    diem c;
public:
    tg()
    {
        a.hd=0;
        b.hd=0;
        c.hd=0;
        a.td=0;
        b.td=0;
        c.td=0;
    }
    tg(diem d1,diem d2, diem d3)
    {
        a=d1;
        b=d2;
        c=d3;
    }
    void nhap()
    {
        // while ( (kc(a,b)!=kc(a,c)||kc(c,b)!=kc(a,c))||kc(c,b)!=kc(b,a))
        //{
        cout<<"nhap 3 canh cua tam giac :"<<endl;
        cin>>a>>b>>c;
        //}
    }
    float chuvi()
    {
        float cv;
        return cv=kc(a,b)+kc(a,c)+kc(b,c);
    }
    float dientich()
    {
        float s;
        float p=((kc(a,b)+kc(b,c)+kc(a,c))/2);
        return s=sqrt(p*(p-kc(a,b))*(p-kc(b,c))*(p-kc(a,c)));
    }
};
int main()
{
    int n;
    float s=0;
    float c=0;
    cout<<"nhap so luong tam giac :";
    cin>>n;
    tamgiac tg[n];
    for (int i=0; i<n; i++)
    {
        tg[i].nhap();
        c+=tg[i].chuvi();
        s+=tg[i].dientich();
    }
    cout<<"tong dien tich cua cac tam giac la :"<<s<<endl;
    cout<<"tong chu vi cua tam giac la :"<<c<<endl;
}
