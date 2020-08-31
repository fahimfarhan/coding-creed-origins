#include<bits/stdc++.h>
using namespace std;
string a[505];
int main(){
	int n,m,i,j,k,cnt=0,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		cin>>a[i];
		for(j=0;j<m;++j)if(a[i][j]=='*')++cnt;
	}
	//cout<<a[0];
	for(i=1;i<n-1;++i)
		for(j=1;j<m-1;++j)if(a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'){
			for(t=1,k=i-1;k>=0&&a[k][j]=='*';--k)++t;
			for(k=i+1;k<n&&a[k][j]=='*';++k)++t;
			for(k=j-1;k>=0&&a[i][k]=='*';--k)++t;
			for(k=j+1;k<m&&a[i][k]=='*';++k)++t;
			if(t==cnt){
				puts("YES");
				return 0;
			}
		}
	puts("NO");
	return 0;
}
