#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n , t = 0, s, mang[50], A, p, a;
int k = 0;
void nhap()
{
    while (n < 3)
    {
        printf("Nhap n: ");
        scanf("%d", &n);
    }

    while (t < 1)
    {
        printf("\nnhap t: ");
        scanf("%d", &t);
    }
}
int tim_s(int k){
    int r;
    int x =k-1;
    while(r %2 ==0){
        r= x / 2;
        x= x/2;
    }
    s= log((k-1) / r) / log(2);
    return s;

}

int binhPhuong(int x, int v)
{

    while (x != 0)
    {
        mang[k] = x % 2;
        x = x / 2;
        k++;
    }
    p = 1;
    for (int i = k - 1; i >= 0; i--)
    {
        A = (p * p) % n;
        if (mang[i] == 1)
        {
            p = (v * A) % n;
        }
        else if (mang[i] == 0)
        {
            p = A;
        }
    }
    return p;
}
void tinh()
{
    nhap();
    tim_s(n);
    for (int i = 1; i <= t; i++)
    {
        a = 2 + rand() % ((n - 2) + 1 - 2);
        printf("\n voi a= %d thi ", a);
        binhPhuong(n - 1, a);
        if (p != 1 && p != (n - 1))
        {
            int j = 1;
            while (j <= (s - 1) && p != (n - 1))
            {
                p = p * p % n;
                if (p == 1)
                {
                    printf("hop so");
                }
                j += 1;
            }
            if (p != (n - 1))
            {
                printf("hop so");
            }
        }
        else
        {
            printf("nguyen to");
        }
    }
}
int main()
{

    tinh();
    return 0;
}
