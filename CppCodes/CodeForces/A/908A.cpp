#include <bits/stdc++.h>
using namespace std;


class A908
{
private:
	string s;
	int n,count;
public:
	A908(){
		count = 0;
		cin>>s;
		n=s.length();
		for(int i=0;i<n;i++){
			if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
				count++;
			}else if((s[i]>='0')&&(s[i]<='9')&&(s[i]-'0')%2){
				count++;
			}

		}

		cout<<count<<endl;
	}
	~A908(){}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	A908 a908;
	return 0;
}