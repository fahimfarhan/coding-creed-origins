#include <bits/stdc++.h>

using namespace std;

int recursion(string s){
    // base case 
    if(s.size() == 1){
        int ret = s[0]-'0';
        return ret;
    }
    int msb = s[0] - '0';
    for(int i=0; i<s.size()-1; i++ ){
        msb = msb*10;
    }
    string t = s.substr(1);
    int ret = msb + recursion(t);
    return ret;
}

int main()
{
    string s;
    cin>>s;
    int n = recursion(s);
    printf("%d\n",n);

    return 0;
}
