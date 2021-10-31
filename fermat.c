#include<stdio.h>
#include<math.h>
int binhphuong(int a,int k,int n)
{
    long long b =1;
    long long A = a;
    if(k==0) return (int)b;
    int t = k%2;
    k = k/2;
    if(t==1)
    {
        b = a;
    }
    for(int i = k;k>0;k=k/2)
    {
        A = A*A%n;
        t = k%2;
        if(t==1)
        {
            b = A*b%n;
        }
    }
    return (int)b;
}
int femat(int n)
{
    int t = 5;
    int a[t];
    for(int i = 0;i<t;i++)
    {
        a[i]=2 + rand()%(n-2 +1 -2);
    }
    for(int i =0;i<t;i++)
    {
        int r = binhphuong(a[i],n-1,n);
        if(r!=1)
        {
            return 0;
        }
    }
    return 1;
}
int rabin(int n)
{
    int r = n-1,s = 0,t = 5;
    int a[t];
    for(int i = 0;i<t;i++)
    {
        a[i]=2 + rand()%(n-2 + 1-2);
    }while(r%2==0)
    {
        s++;
        r = r/2;
    }
    for(int i = 1;i<=t;i++)
    {
        int y = binhphuong(a[i-1],r,n);
        if(y!=1 && y!=(n-1))
        {
            int j = 1;
            while(j <= s-1&& y !=(n-1))
            {
                y = (y*y)%n;
                if(y ==1)
                {
                    return 0;
                }
                j+=1;
            }
            if(y !=(n-1))
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n;
    printf("n");
    scanf("%d",&n);
    if(rabin(n)==1)
    {
        printf("nguyen to");
    }
    else
    {
        printf("hop so");
    }
    //if(femat(n)==1)
    //{
      //  printf(" nguyen to");
    //}else
    //{
     //   printf("hop so");
    //}

}

