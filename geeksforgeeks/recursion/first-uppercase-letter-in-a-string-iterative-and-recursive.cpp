#include <bits/stdc++.h>

using namespace std;

int recursion(const string& s,int i){
    if(i>=s.size()){    return -1;  }
    if((s[i]>='A') && (s[i]<='Z')){
        return i;
    }
    return recursion(s, (i+1));
}

int main()
{
    string input = "a quick brown Fox jumped over the lazy dog";
    int out = recursion(input,0);
    if(out==-1){    cout<<"Not found\n";    }
    else{
        cout<<input[out]<<"\n";
    }

    return 0;
}