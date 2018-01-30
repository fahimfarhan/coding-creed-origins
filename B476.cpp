#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1, s2;

	cin>>s1>>s2;
	int a=0, b=0;
	for(int i=0; i<s1.size(); i++){
		if(s1[i]=='+') a++;
		else b++;
	}

	for(int i=0; i<s2.size(); i++){
		if(s2[i]=='+') a--;
		else if(s2[i]=='-') b--;
	}	

	double ans = 1;
	if(a<0 || b<0) ans = 0;
	else{
		for(int i=b+1; i<=a+b; i++){
			ans = ans*i/(i-b);
		}

		for(int i=0; i<a+b; i++) ans = ans/2;
	}

	printf("%.10f\n",ans);
	return 0;
}