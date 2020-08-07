#include <bits/stdc++.h>

using namespace std;

class A41{
private:
    string s,t;
    int len;
public:
    A41(){
        cin>>s;
        cin>>t;
        len = s.length();
        for(int i=0; i<len; i++){
            if(s[i] != t[len-1-i]){
                printf("NO\n");
                exit(0);
            }
        }
        printf("YES\n");
    }
    ~A41(){}
};
int main()
{
    A41 a41;
    return 0;
}