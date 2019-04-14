#include<bits/stdc++.h>
using namespace std;
char s[300005];
int l,ans;
int main(){
	int n;
	scanf("%d%s",&n,s+1);
	if(n%2!=0){
		puts(":(");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(s[i]=='(')
			l++;
	for(int i=1;i<=n;i++)
		if(s[i]=='?'&&l<n/2)
			l++,s[i]='(';
	for(int i=1;i<=n;i++){
		if(s[i]=='?')
			s[i]=')';
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='(')
			ans++;
		else{
			ans--;
			if(ans==0&&i!=n||ans<0){
				puts(":(");
				return 0;
			}
		}
	}
	if(!ans){
		printf("%s",s+1);
	}
	else{
		puts(":(");
	}
	return 0;
}