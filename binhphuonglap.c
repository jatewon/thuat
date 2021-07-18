#include<stdio.h>
#include<math.h>
int a,n,k,t=0,mang[100];
void nhap()
{
    printf("a");
    scanf("%d",&a);
    printf("n");
    scanf("%d",&n);
    printf("k");
    scanf("%d",&k);
}
int nhiphan(int x)
{
    while(x!=0)
    {
        mang[t]=x%2;
        x = x/2;
        t++;
    }return mang;
}
void binhphuonglap()
{
    int *f;
    int bp,b=1,w;
    int g[100];
    f = nhiphan(k);
    for(int i = t-1;i>=0;i--)
    {
        g[t-1-i]=*(f+i);
    }
    for(int i =0;i<t;i++)
    {
        bp = pow(b,2);
        w = bp%n;
        if(g[i]==1)
        {
            b = (a*w)%n;
        }else if(g[i]==0)
        {
            b = w;
        }
    }
    printf("a^ k mod n = %d",b);
}
int main()
{
    nhap();
    if(k==0)
    {
        printf("1");
    }
    else
    {
        binhphuonglap();
    }
    return 0;
}
