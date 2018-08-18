#include <bits/stdc++.h>

using namespace std;

bool can(){
    int n,m;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    if(s.find('*')==-1){
        return (s==t);    //if(s == t){ return true;    }
    }else{
        if(n-1>m){  return false;   }
        else{
            int i=0;
            while(s[i]==t[i]){  i++;    }
            int j=1;
            while(s[n-j]==t[m-j]){  j++;    }
            j = n-j;
            return (i==j);//if(i==(n-j)){   return true;    }
            //else{   return false;   }
        }
    }
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    if(can()){  cout<<"YES\n";  }
    else{   cout<<"NO\n";   }
    return 0;
}