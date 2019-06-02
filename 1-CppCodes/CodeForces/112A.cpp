#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class A112{
private:
	string s1, s2;
	int n;
public:
	A112(){
		cin>>s1>>s2;//string s = "AbcDe";
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		//cout<<s<<endl;
		//cout<<s[0]<<" "<<s[1];
		n=0;
		for(int i=0; i<s1.length(); i++){
			if(s1[i]==s2[i]){}
			else if(s1[i]<s2[i]){  n=-1; break;	}
			else if(s1[i]>s2[i]){  n= 1; break;	}
		}
		
		cout<<n<<"\n";
		
	}
	
	~A112(){}
		
};

int main()
{
	A112 a;
	return 0;
}





