#include<stdio.h>
#include<math.h>
int p,a,b,n,t,k=0,mang[100],s;
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
int tims(int k)
{
    int r;
    int x = k-1;
    while(r%2==0)
    {
        r = x/2;
        x = x/2;
    }
    s =(log(k-1)/r)/log(2);
    return s;
}
int binhphuong(int m,int v)
{
    while(m!=0)
    {
        mang[k]=m%2;
        m = m/2;
        k++;
    }
    p = 1;
    for(int i = k-1; i>=0; i--)
    {
        b = p*p%n;
        if(mang[i]==1)
        {
            p = b*v%n;
        }
        else if(mang[i]==0)
        {
            p = b;
        }
    }
    return p;
}
int main()
{
    nhap();
    tims(n);
    for(int i =1; i<t; i++)
    {
        a = rand()%((n-2)+1-2);
        binhphuong(n-1,a);
        if(p!=1 && p!=(n-1))
        {
            int j = 1;
            while(j <(s-1) && p!=(n-1))
            {
                p = p*p%n;
                j+=1;
            }
        }
        if(p !=1)
            {
                printf("hop so");
                return 0;
            }
            else
            {
                printf("nguyen to");
                return 0;
            }
    }
}

