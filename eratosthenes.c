#include<stdio.h>
#include<math.h>
int n;
void nhap()
{
    printf("n");
    scanf("%d",&n);
}
void eratothes()
{
    int a[1000];
    for(int i = 2;i<=n;i++)
    {
        a[i]=1;
    }
    for(int i =2;i<=n;i++)
    {
        if(a[i]==1)
        {
            for(int j = i+1;j<=n;j++)
            {
                if(j%i==0)
                {
                    a[j]=0;
                }
            }
        }
    }
    for(int i =2;i<=n;i++)
    {
        if(a[i]==1)
        {
            printf("%d ",i);
        }
    }
}
void phandoan()
{
    int a[1000];
    int phantu,sophandoan;
    phantu = sqrt(n)-1;
    if((n-1)%phantu==0)
    {
        sophandoan = (n/phantu)+1;
    }
    else
    {
        sophandoan = (n/phantu)+1;
    }
    for(int i = 2;i<=n;i++)
    {
        a[i]=1;
    }
    for(int w =0;w<sophandoan;w++)
    {
        for(int i= (w*phantu)+2;i<((w+1)*phantu)+2;i++)
        {
            if(i<=n)
            {
                for(int j = 2;j<((w+1)*phantu)+2;j++)
                {
                    if(a[j]==1 && i!=j)
                    {
                        if(i%j==0)
                        {
                            a[i]=0;
                            break;
                        }
                    }
                }
            }
            else
            {
                break;
            }
        }
        for(int i  =(w*phantu)+2;i<((w+1)*phantu)+2;i++)
        {
            if(a[i]==1)
            {
                printf("%d ",i);
            }
            else if(a[i]==0)
            {
                printf(" ..");
            }
        }
    }
}
int main()
{
    nhap();
    phandoan();
    return 0;
}
