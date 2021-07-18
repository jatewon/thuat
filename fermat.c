#include<stdio.h>
#include<math.h>
int a,b,p,n,t,x=0,mang[100];
void nhap()
{
    while(n<3)
    {
        printf("n");
        scanf("%d",&n);
    }
    while(t<1)
    {
        printf("t");
        scanf("%d",&t);
    }
}
void binhphuong(int m,int v)
{
    while(m!=0)
    {
        mang[x]=m%2;
        m = m/2;
        x++;
    }
    p = 1;
    for(int i = x-1;i>=0;i--)
    {
        b = (p*p)%n;
        if(mang[i]==1)
        {
            p = (b*v)%n;
        }else if(mang[i]==0)
        {
            p = b;
        }
    }
    return p;
}
int main()
{
    nhap();
    for(int i = 1;i<t;i++)
    {
        a = 2 + rand()%((n-2)-1);
        printf("%d",a);
        binhphuong(n-1,a);
        if(p==1)
        {
            printf("nguyen to");
        }
        else
        {
            printf ("hop so");
        }
    }
    return 0;
}
