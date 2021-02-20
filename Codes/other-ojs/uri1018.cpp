#include<stdio.h>
int main()
{
    int a[]={100,50,20,10,5,2,1};
    int n, i, sum;
    scanf("%d", &n);
    printf("%d\n", n);   // <--- You forgot to add this line
    for(i=0; i<7; i++)
    {
        sum=n/a[i];
       printf("%d nota(s) de R$ %d,00\n", sum, a[i]);
        n=n%a[i];
    }
 
return 0;
}