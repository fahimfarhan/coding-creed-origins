#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int



int main(int argc, char const *argv[])
{
    /* code */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */

    string s1="",s2="", t="";
    cin>>t;

    int ns=0, nt=t.size();
    for(int i=0; i<t.size(); i++){
        s1+=t[i];
        if(t[i]!='a')  s2+=t[i];  
        ns = s1.size() + s2.size();
        if(ns>=nt){ break; }  
    }
    string s; s = s1+s2;
    if(t==s){
        cout<<s1<<"\n";
        exit(0);
    }else{  
        cout<<":(\n"; exit(0);
    }
    return 0;
}
