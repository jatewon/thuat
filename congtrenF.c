#include<stdio.h>
#include<math.h>
int w;
long long p,x,y,a[100],b[100];
void nhap()
{

    int k;
    printf("P:");
    scanf("%lld",&p);
    printf("W:");
    scanf("%lld",&w);
    printf("a:");
    scanf("%lld",&x);
    printf("b:");
    scanf("%lld",&y);
    congtrenF(k);
}

int tinht()
{
    int t,m;
    m = ceil(log(p)/log(2));
    t = ceil((float)m/w);
    return t;
}
long long bieu_dien(long long a)
{
    int t;
    int j = t-1;
    long long int uoc,luythua;

    t = tinht();
    static long long mang[100];
    for(int i = t-1; i>=0; i--)
    {
        luythua = pow(2, i * w);
        uoc = a / luythua;
        a = a % luythua;
        mang[j] = uoc;
        j--;
    }
    return mang;
}
long long *cong(int k)
{
    static long long c[100];
    long long tong,luythua;
    int t ,e=0;
    t = tinht();
    long long *r,*o;
    r = bieu_dien(x);
    for(int i = 0;i<t;i++)
    {
        a[i]= *(r+i);
    }
    o = bieu_dien(y);
    for(int i = 0;i<t;i++)
    {
        b[i]=*(o+i);
    }
    for(int i = 0;i<=t-1;i++)
    {
        luythua = pow(2,w);
        tong = a[i]+b[i]+e;
        if(tong >=luythua)
        {
            c[i]=tong%luythua;
            e = 1;
        }
        else
        {
            c[i]=tong;
            e = 0;
        }
        c[t]=e;
        return c;
    }
}

void tru(long long a[])
{
   long long *r,hieu,luythua;
   long long c[100];
   int t ,e = 0;
   t = tinht();
   r = bieu_dien(p);
   for(int i = 0;i<t;i++)
   {
       b[i]=*(r+i);
   }
   for(int i = 0;i<=t-1;i++)
   {
       hieu= a[i]-b[i]-e;
       luythua = pow(2,w);
       if(hieu <0)
       {
           c[i]=hieu+luythua;
           e= 1;
       }else
       {
           e = 0;
           c[i]=hieu;
       }
       printf("%lld ,e = %d",c[i],e);
   }
}
void congtrenF(k)
{
    long long  *o,c[100];
    int t;
    t = tinht();
    o = cong(k);
    for(int i = 0;i<=t;i++)
    {
        c[i]=*(o+i);
        if(i==t)
        {
            c[i]=*(o+i);
        }
    }
    if(c[t]==0)
    {
        for(int i = 0;i<=t-1;i++)
        {
            printf("%lld",c[i]);
        }
        printf("e = %lld",c[t]);
    }
    else if(c[t]==1)
    {
       cong(c);
    }
}
int main()
{
    nhap();
    return 0;
}
