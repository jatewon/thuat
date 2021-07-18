#include<stdio.h>
#include<math.h>
int n,a,b,d;
void nhap()
{
    printf("n");
    scanf("%d",&n);
}
int ucln(a,b)
{
    int r;
    if(b>a)
    {
        r =a;
        a =b;
        b = r;
    }
    while(b>0)
    {
        r = a%b;
        a =b;
         b = r;
    }
    return a;
}

void thuasokotamthuong()
{
    int a = 2,b =2,i = 1,d;
    while(1)
    {
        a = (a*a +i)%n;
        b = (b*b + i)%n;
        b =(b*b + i )%n;
        d = ucln(a-b,n);
        if(d >1 && d<n)
        {
            printf("%d ",d);
            break;
        }else if(d ==n)
        {
            i++;
        }
    }
}
int main()
{
    nhap();
    thuasokotamthuong();
    return 0;
}
