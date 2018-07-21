#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int x,n,i,j;
double y;
cin>>n;
for(i=1;i<=n;i++)
{
scanf("%lld",&x);
y=sqrt(x);
if(y-(int)y !=0 ){
    printf("NO\n");
}else{
    for(j=2;j*j<y;j++)
    if(x%j==0) break;
    if(j*j>y&&y*y==x&&x>1) printf("YES\n");
    else printf("NO\n");

}
}
}