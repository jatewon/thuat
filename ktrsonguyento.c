#include<stdio.h>
#include<math.h>
int n;
void nhap()
{
    printf("nhap N:");
    scanf("%d",&n);
    if(n<2)
    {
        printf("nhap lai!");
    }
    int d = 0;
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            d++;
        }
    }
    if(d == 0)
    {
        printf("la so nguyen to");
    }else
    {
        printf("la hop so");
    }
}
int main()
{
    nhap();
    return 0;
}
