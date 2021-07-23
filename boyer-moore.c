#include<stdio.h>
#include<math.h>
char t[100],p[100];
int l[150];
void nhap()
{
    printf("T");
    fgets(t,sizeof(t),stdin);
    printf("p");
    fgets(p,sizeof(p),stdin);
    for(int i = 0;i<150;i++)
    {
        l[i]=-1;
    }
    for(int i = 0;i<(int)(strlen(t)-1);i++)
    {
        l[(int)t[i]]=i;
    }
}
int kiemtra()
{
    int d= 0;
    int j = strlen(p)-2,congthem = 0,i= strlen(p)-2;
    while(i<strlen(t))
    {
        if(congthem !=0)
        {
            d = 0;
            i = i +congthem;
            j = strlen(p)-2;
        }
        if(t[i]==p[j])
        {
            i--;
            j--;
            d++;
            congthem = 0;
        }else{
            int min;
            if(j >1 + l[(int)t[i]])
            {
                min = 1 + l[(int)t[i]];
            }else
            {
                min = j;
            }
            congthem = (strlen(p)-1)-min;
        }
        if(d  == (int)strlen(p)-1)
        {
            printf("P co trong T o vi tri %d",i);
            return 0;
        }
    }
    printf("ko co trong T");
}
int main()
{
    nhap();
    kiemtra();
    getchar();
    return 0;
}
