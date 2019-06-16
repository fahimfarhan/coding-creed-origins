#include<bits/stdc++.h>
using namespace std;
int n,i,j,r,a,t,tt;
int main(){
	for(cin>>n;i<=n;i++){
		if(i==n)t=0;else cin>>t;
		if(t-tt||i==n){
			r=max(r,min(a,i-j)*2);
			a=i-j;
			tt=t;
			j=i;
		}
	}
	cout<<r;
}
