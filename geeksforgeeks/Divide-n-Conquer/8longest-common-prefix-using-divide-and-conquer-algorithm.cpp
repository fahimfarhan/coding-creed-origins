#include <bits/stdc++.h>

using namespace std;

string longestPrefix(string *a, int l, int r){
    int len = r-l+1;
    if(len==1){ return a[l];    }

    int mid = (l+r)>>1;
    string p1,p2;
    p1=longestPrefix(a,l,mid);
    p2=longestPrefix(a,mid+1,r);

    string ret = "";

    len = min(p1.size(),p2.size());

    for(int i=0; i<len; i++){
        if(p1[i]==p2[i]){   ret=ret+p1[i];  }
        else{   break;  }
    }

    return ret;
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"}; 
    int n = sizeof (arr) / sizeof (arr[0]); 

    cout<<longestPrefix(arr,0,n-1)<<"\n";

    return 0;
}