#include<stdio.h>
#include<math.h>
int a,p;
void nhap()
{
    printf("a");
    scanf("%d",&a);
    printf("p");
    scanf("%d",&p);
}
void ngichdao()
{
    int u,v,x,x1,x2,q,r;
    u = a;
    v = p;
     x1 =1;
     x2 = 0;
     while(u!=1)
     {
         q = v/u;
        r = v - q*u;
        x = x2-q*x1;

        v = u;
        u = r;
        x2= x1;
        x1= x;
     }
     printf(" %d mod %d",x1,p);
}
int main()
{
    nhap();
    ngichdao();
    return 0;
}
