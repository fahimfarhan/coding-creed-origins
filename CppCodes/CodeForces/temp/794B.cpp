#include <cstdio>
#include <cmath>
using namespace std;
int n,h;
int main()
{
    scanf("%d %d",&n,&h);
    for(int i=1;i<n;i++)
        printf("%.12f ",(sqrt((double)i/n)*h));
    return 0;
}
