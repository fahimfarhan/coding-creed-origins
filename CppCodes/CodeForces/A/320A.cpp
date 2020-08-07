#include <bits/stdc++.h>
// using c++ 14 ; g++ -std=c++14 A320.cpp
using namespace std;
class A320
{
private:
	string s;
public:
	A320(){
		cin>>s;
		bool b =regex_match(s,regex("(1|14|144)*")); // regex_match(s,regex("(1|14|144)*"));//
		if(b){cout<<"YES\n";}
		else cout<<"NO\n";
	}
	~A320(){}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	A320 a320;
	return 0;
}