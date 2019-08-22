#include <bits/stdc++.h>

using namespace std;

set<string> v;


/*int recursion(string s, int l, int r, int n){
    if(n==1){ return 1;  }
    if(n<=0){   return 0;   }

    int ret = 0;
    if(s[l]==s[r]){ ret++;  }
    ret = ret+recursion(s, (l))
}*/

int main()
{

    string s = "abcab";
    int count = 0;
    for(int i=0; i<s.size(); i++){
        for(int j=i; j<s.size(); j++){
            if(s[i] == s[j]){   count++;   }
        }
    }

    cout<<count<<"\n";
    return 0;
}