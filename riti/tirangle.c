#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k;
    for(i=0; i<10; i++)
    {
        for(j=10-i; j>0;j--)
        {
            printf(".");
        }
        for(k=0; k<i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}