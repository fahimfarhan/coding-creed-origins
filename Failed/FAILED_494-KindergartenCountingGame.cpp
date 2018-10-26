#include <bits/stdc++.h>
//#include <regex>
//#include <string>
using namespace std;
class KCG494{
private:
    string s;
    int n;
    smatch base_match;
public:
    KCG494(){
        n=0;
        while(getline(cin,s)){
            regex_match(s,base_match,regex("[A-Za-z]*"));
            n = base_match.size();
            cout<<n<<endl;//printf("%d\n",n);
        }
    }
    ~KCG494(){}
};
int main()
{
    KCG494 k;
    return 0;
}