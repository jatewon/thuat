#include<stdio.h>
#include<math.h>
int w;
long long p,e,d,a[100],b[100];
void nhap()
{
    printf("p");
    scanf("%lld",&p);
    printf("w");
    scanf("%d",&w);
    printf("a");
    scanf("%lld",&d);
    printf("b");
    scanf("%lld",&e);
    Congtrenf();
}
int tinh_t()
{
    int t,m;
    m = ceil(log(p)/log(2));
    t  = ceil((float)m/w);
    return t;
}
long long *bieu_dien(long long a)
{
    static long long mang[100];
    int t;
    t = tinh_t();
    long long uoc,luythua;
    int j = t-1;
    for(int i =t-1;i>=0;i--)
    {
        luythua = pow(2,i*w);
        uoc = a/luythua;
        a = a%luythua;
        mang[j]=uoc;
        j--;
    }
    return mang;
}
long long *cong()
{
    static long long c[100];
    int t,e= 0;
    long long luythua,tong;
    t=tinh_t();
    long long *f,*g;
    f = bieu_dien(d);
    for(int i = 0;i<t;i++)
    {
        a[i]=*(f+i);
    }
    g = bieu_dien(e);
    for(int i = 0;i<t;i++)
    {
        b[i]=*(g+i);
    }
    for(int i = 0;i<=t-1;i++)
    {
        tong = a[i]+b[i]+e;
        luythua = pow(2,w);
        if(tong >= pow(2,w))
        {
            c[i]=tong %luythua;
             e= 1;
        }
        else
        {
            c[i]=tong;
            e = 0;
        }
    }
    c[t]=e;
    return c;
}
void Tru( long long a[])
{
    long long *f,hieu,luythua;
    long long c[100];
    int t,e = 0;
    t = tinh_t();
    f = bieu_dien(p);
    for(int i = 0;i<=t;i++)
    {
        b[i]=*(f+i);
    }
    for(int i = 0;i<=t-1;i++)
    {
        hieu = a[i]-b[i]-e;
        luythua = pow(2,w);
        if(hieu < 0)
        {
            c[i]=hieu + luythua;
            e=1;
        }
        else
        {
            c[i]=hieu;
            e = 0;
        }
        printf("%lld ",c[i]);
    }
}
long long sochinhxac(long long c[])
{
    int t;
    long long tong = 0;
    t = tinh_t();
    for(int i = 0;i<=t-1;i++)
    {
        tong  = tong + c[i]*pow(2,i*w);
    }
    return tong;
}
void Congtrenf()
{
    long long *f,c[100];
    int t;
    long long soc;
     t = tinh_t();
     f = cong();
     for(int i = 0;i<=t;i++)
     {
         c[i]=*(f+i);
     }
     soc = sochinhxac(c);
     if(c[t]==0)
     {
         if(soc<p)
         {
             for(int i = 0;i<=t-1;i++)
             {
                 printf("%lld ",c[i]);
             }
             printf(" e = %lld",c[t]);
         }
         else
         {
             Tru(c);
         }
     }
     else if (c[t]==1)
     {
         Tru(c);
     }
}
int main()
{
    nhap();
}


