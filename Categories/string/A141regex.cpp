#include <bits/stdc++.h>
using namespace std;

class A141{
private:
    string s1,s2,s3;
public:
    A141(){
        cin>>s1>>s2>>s3;
        s1 = "("+s1+s2+")"+"+";
        if (regex_match(s3, regex(s1))) printf("YES\n");
        else printf("NO\n");
    }
    ~A141(){}
};
int main()
{
    A141 a141;
    return 0;
}