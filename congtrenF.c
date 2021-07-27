#include<stdio.h>
#include<math.h>
int w;
long long p,x,y,a[100],b[100];
void nhap()
{
    printf("p");
    scanf("%lld",&p);
    printf("w");
    scanf("%d",&w);
    printf("x");
    scanf("%lld",&x);
    printf("y");
    scanf("%lld",&y);
    congtrenf();
}
int tinht()
{
    int t,m;
    m= ceil(log(p)/log(2));
    t = ceil((float)m/w);
    return t;
}
long long *bieudien(long long a)
{
    int t,j;
    t = tinht();
    j = t -1;
    long long uoc,luythua;
    static long long mang[100];
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
long long *cong()
{
    int t,ep =0;
    t = tinht();
    static long long c[100];
    long long luythua,tong;
    long long *g,*f;
    g =bieudien(x);
    for(int i = 0;i<t;i++)
    {
        a[i]=*(g+i);
    }
    f = bieudien(y);
    for(int i = 0;i<t;i++)
    {
        b[i]=*(f+i);
    }
    for(int i = 0;i<=t-1;i++)
    {
        tong = a[i]+b[i]+ep;
        luythua = pow(2,w);
        if(tong >= pow(2,w))
        {
            c[i]=tong%luythua;
            ep = 1;
        }
        else
        {
            c[i]=tong;
            ep = 0;
        }
    }
    c[t]=ep;
    return c;
}
void congtrenf()
{
    long long *f,c[100];
    int t = tinht();
    f = cong();
    for(int i = 0;i<=t;i++)
    {
        c[i]=*(f+i);
        if(i==t)
        {
            c[i]=*(f+t);
        }
    }
    if(c[t]==0)
    {
        for(int i = 0;i<=t-1;i++)
        {
            printf("c[%d] = %lld",i,c[i]);
        }
        printf("e = %lld",c[t]);
    }
    else if(c[t]==1)
    {
        tru(c);
    }
}
void tru(long long a[])
{
    long long *g,hieu,luythua;
    static long long c[100];
    int t,ep = 0;
    t = tinht();
    g = bieudien(p);
    for(int i = 0;i<t;i++)
    {
        b[i]=*(g+i);
    }
    for(int i = 0;i<=t-1;i++)
    {
        hieu = a[i]-b[i]-ep;
        luythua = pow(2,w);
        if(hieu<0)
        {
            c[i]=hieu + luythua;
            ep = 1;
        }
        else
        {
            c[i]=hieu;
            ep = 0;
        }
        printf("c[%d] = %lld",i,c[i]);
    }
}
int main()
{
    nhap();
    return 0;
}

