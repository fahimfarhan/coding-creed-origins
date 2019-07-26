/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;


int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    ll  mycount;
    string s;
    //scanf("%d\n",&T);
    cin>>T;
    cin.ignore();
    //getline(cin,s);
    while(T--){
        s = "";
        getline(cin,s);
        mycount = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){  mycount++; }
        }
        mycount = mycount+1;
        cout<<mycount<<"\n";
    }


    return 0;
}