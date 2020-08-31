#include <bits/stdc++.h>
using namespace std; 
const int mod=998244353;
int main(){
	int t,a;cin>>t;
	while(t--){
		int i=1;
		cin>>a;
		while((180*i)%a || (180*i)/a <i+2)
		i++;
		cout<<180*i/a<<endl;
	}
}
