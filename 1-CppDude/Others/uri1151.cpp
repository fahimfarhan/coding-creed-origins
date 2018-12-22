#include <bits/stdc++.h>

using namespace std;

int main()
{
    int *a;
    a = new int[46];
    a[0]=0;
    a[1] = 1;
    for(int i=2; i<46; i++){
        a[i] = a[i-1]+a[i-2];
    }
    int n;
    scanf("%d",&n);
    printf("%d",a[0]);
    for(int i=01; i<n; i++){
        printf(" %d",a[i]);
    }
    printf("\n");
    if(!a)delete[] a;

    return 0;
}