#include<stdio.h>
#include<math.h>
#include<string.h>
char t[100],p[100];
void nhap()
{
    printf("T");
    scanf("%s",&t);
    printf("P");
    scanf("%s",&p);
}
void vetcan()
{
    int d= 0;
    for(int i =0;i<strlen(t);i++)
    {
        d = 0;
        for(int j = 0;j<strlen(p);j++)
        {
            if(t[i+j]==p[j])
            {
                d++;
            }
        }
        if(d == (int)(strlen(p)))
        {
            printf("vi tri bat dau la %d",i+1);
            break;
        } else if(i == (int)(strlen(t)-1) && d<(int)(strlen(p)))
        {
            printf("khong co trong T");
        }
    }
}
int main()
{
    nhap();
    vetcan();
    return 0;
}
