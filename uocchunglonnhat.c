#include<stdio.h>
#include<math.h>
int a,b;
void nhap()
{
    printf("a");
    scanf("%d",&a);
    printf("b");
    scanf("%d",&b);
}
void ucln()
{
    int r;
    if(b>a)
    {
        r = a;
        a = b;
        b = r;
    }
    while(b>0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    printf("%d",a);
}
void eucliemorong()
{
    int x,y,y1,y2,x1,x2,r,q,d;
    x1= 0,x2=1,y1=1,y2=0;
    if(b==0)
    {
        d = a;
        x = 1;
        y= 0;
        printf("%d %d %d",d,x,y);
    }
    while(b>0)
    {
        q = a/b;
        r = a- q*b;
        x = x2-q*x1;
        y = y2 -q*y1;

        a = b;
        b = r;
        x2 = x1;
        x1= x;
        y2 = y1;
        y1 = y;
    }
    d = a;
    x =x2;
    y = y2;
    printf("%d %d %d",d,x,y);
}
int main()
{

    nhap();
    eucliemorong();
    return 0;
}
