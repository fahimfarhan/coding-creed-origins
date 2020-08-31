#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
cin>>a>>b>>c;
int x,y,z;
x=sqrt((a*b)/c);
y=a/x;
z=b/x;
cout<<4*(x+y+z);
}
