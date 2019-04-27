#include <bits/stdc++.h>

using namespace std;

string s;

bool recursion(int l, int r){
    bool b;
    if(s[l] == s[r]){   b=true; }
    else{   return false; }
    if(l==0){   return b; }
    int l1, r1;
    l1 = l-1; r1=r+1;
    return recursion(l1, r1);
}

int main()
{
    s = "1237320";
    int l,r,mid, len;
    len = s.size();
    if( (len&1) == 1){ mid = len>>1; l = mid-1; r=mid+1; }
    else{   r = len>>1; l=r-1;    }

    cout<<recursion(l,r)<<"\n";

    return 0;
}