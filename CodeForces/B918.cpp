
#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n,m;
	string s1,s2;
	map<string, string> mp;
public:
    Soln(){
		scanf("%d %d",&n,&m);
		for(int i=0; i<n; i++){
			cin>>s1>>s2;
			s2=s2+'\n';
			mp[s2] = s1;
		}
		for(int i=0; i<m; i++){
			cin>>s1>>s2;
			string s3 = s2;
			s3[s3.length()-1] = '\n';
			cout<<s1<<" "<<s2<<" #"<<mp[s3]<<"\n";
		}
		

	}
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}