#include<stdio.h>
#include<math.h>

int w;
long long p,x,y,a[100],b[100];
void nhap()
{
    int k;
    printf("P");
    scanf("%lld",&p);
    printf("W");
    scanf("%lld",&w);

    while(1)
    {
        printf("nhap so ban chon");
        printf("1 so");
        printf("2 mang");
        printf("so ban chon");
        scanf("%d",&k);
        if(k ==1)
        {
            printf("a");
            scanf("%lld",&x);
            printf("b");
            scanf("%lld",&y);
            Tru_tren_f(k);
            break;
        }
    }
}
int tinh_t()
{
    int t,m;
    m = ceil(log(p)/log(2));
    t = ceil((float)m/w);
    return t;
}

long long *bieu_dien(long long a)
{
    static long long mang[100];
    int t;
    t = tinh_t();
    int j = t-1;
    long long uoc ,luythua;
    for(int i = t-1;i>=0;i--)
    {
        luythua = pow(2,i*w);
        uoc = a/luythua;
        a = a%luythua;
        mang[j]=uoc;
        j--;
    }
    return mang;
}
long *Tru(int k)
{
    static long long c[100];
    long long hieu,luythua;
    int t ,e=0;
    if(k==1)
    {
        long long *r,*o;
        r = bieu_dien(x);
        for(int i =0;i<t;i++)
        {
            a[i]=*(r+i);
        }
        o = bieu_dien(y);
        for(int i = 0;i<t;i++)
        {
            b[i]=*(o+i);
        }

    }
    for(int i = 0;i<= t-1;i++)
    {
        luythua = pow(2,w);
        hieu = a[i]- b[i]-e;
        if(hieu<0)
        {
            c[i]=hieu+luythua;
            e=1;
        }
        else
        {
            c[i]=hieu;
            e = 0;
        }
    }
    c[t]=e;
    return c;
}
void Cong(long long a[])
{
    long long *r,tong,luythua;
    long long c[100];
    int t,e=0;
    t = tinh_t();
    r = bieu_dien(p);
    for(int i = 0;i<t;i++)
    {
        b[i]=*(r +i);
    }
    for(int i = 0;i<=t-1;i++)
    {
        tong = a[i]+b[i]+e;
        luythua = pow(2,w);
        if(tong >=pow(2,w))
        {
            c[i]=tong%luythua;
            e=1;
        }
        else
        {
            e = 0;
            c[i]=tong;
        }
        printf("%lld ,e = %d",c[i],e);
    }

}
void Tru_tren_f(int k)
{

    long long *o,c[100];
    int t;
    t = tinh_t();
    o =Tru(k);
    for(int i = 0;i<=t;i++)
    {
        c[i]=*(o +i);
        if(i == t)
        {
            c[i]=*(o +i);
        }
    }
    if(c[t]==0)
    {
        for(int i = 0;i<=t-1;i++)
        {
            printf("%lld",c[i]);
        }
        printf(" e=%lld",c[t]);
    }else if(c[t]==1)
    {
        Cong(c);
    }
}
int main()
{
    nhap();
    return 0;
}
