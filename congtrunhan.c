#include<stdio.h>
#include<math.h>
int w;
long long p,x,y,a[100],b[100];
void nhap()
{
    int k;
    printf("P:");
    scanf("%lld",&p);
    printf("w");
    scanf("%d",&w);

    while(1)
    {
        printf("ban chon :");
        printf("1 so\n");
        printf("2 mang\n");
        printf("so chon :");
        scanf("%d",&k);
        if(k ==1 )
        {
            printf("a:");
            scanf("%lld",&x);
            printf("b:");
            scanf("%lld",&y);
            Nhan(k);
            break;
        }
    }
}
int tinht()
{
    int t,m;
    m = ceil(log(p)/log(2));
    t = ceil((float)m/w);
    return t;
}
long long *bieu_dien(long long a)

{
    int t;
    t = tinht();
    int j = t-1;
    long long uoc,luythua;
    static long long mang[100];
    for(int i = t-1; i>=0; i--)
    {
        luythua =pow(2,i*w);
        uoc = a/luythua;
        a = a%luythua;
        mang[j]=uoc;
        j--;
    }
    return mang;
}
void Cong(int k)
{
    long long c[100],luythua,e=0;
    int t;
    t= tinht();
    int j = t-1;
    int tong;
    if(k ==1)
    {
        long long *r,*o;
        r= bieu_dien(x);
        for(int i = 0;i<t;i++)
        {
            a[i]=*(r+i);
        }
        o = bieu_dien(y);
        for(int i = 0;i<t;i++)
        {
            b[i]=*(o+i);
        }
    }
    for(int i =0;i<=t-1;i++)
    {
        tong = a[i]+b[i]+e;
        luythua = pow(2,w);
        if(tong >= luythua){
            c[i]=tong%luythua;
            e=1;
        }
        else{
                c[i]=tong;
                e = 0;
        }
        printf("%lld ,e = %d",c[i],e);
    }
}
void Tru(int k)
{
    long long c[100],luythua;
    int hieu,t,e=0;
    t = tinht();
    if(k==1)
    {
        long long *r,*o;
        r= bieu_dien(x);
        for(int i =0; i<t; i++)
        {
            a[i]=*(r+i);
        }
        o= bieu_dien(y);
        for(int i = 0; i<t; i++)
        {
            b[i]=*(o+i);
        }
    }
    for(int i = 0; i<=t-1; i++)
    {
        hieu = a[i]-b[i]-e;
        luythua = pow(2,w);
        if(hieu<0)
        {
            c[i]=hieu +luythua;
            e = 1;
        }
        else
        {
            c[i]=hieu;
            e = 0;
        }
        printf("%lld,e = %d  ",c[i],e);
    }
}
void Nhan(int k)
{
    int t,u,v;
    long long c[100],luythua,uv;
    luythua = pow(2,w);
    t = tinht();
    if(k ==1)
    {
        long long *r,*o;
        r = bieu_dien(x);
        for(int i = 0; i<t; i++)
        {
            a[i]=*(r+i);
        }
        o = bieu_dien(y);
        for(int i = 0; i<t; i++)
        {
            b[i]=*(o+i);
        }
    }
    for(int i = 0;i<=(2*t)-1;i++)
    {
        c[i]=0;
    }
    for(int i = 0;i<=t-1;i++)
    {
        u = 0;
        for(int j =0;j<=t-1;j++)
        {
            uv= c[i+j]+a[i]*b[j]+u;
            u = uv/luythua;
            v = uv%luythua;
            c[i+j]=v;
        }
        c[i+t]=u;
    }
    for(int i =0;i<w;i++)
    {
        printf("%lld   ",c[i]);
    }
}
int main()
{
    nhap();
    return 0;
}
