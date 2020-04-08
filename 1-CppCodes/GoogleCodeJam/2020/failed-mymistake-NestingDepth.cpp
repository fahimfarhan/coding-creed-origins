/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    string s, a;
    int kount;

    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>s;
        a = "";

        kount = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') {    kount++;  }
            else if(s[i]=='0'){   
                // for(int j=0; j<kount; j++) {
                if(kount!=0)
                    a+="(";
                // }
                for(int j=0; j<kount; j++) {
                    a+="1";
                }
                // for(int j=0; j<kount; j++) {
                if(kount!=0)
                    a+=")";
                // }
                a+="0";
                kount=0;
            }
            if(i==s.size()-1 && kount!=0){
                // for(int j=0; j<kount; j++) {
                    a+="(";
                // }
                for(int j=0; j<kount; j++) {
                    a+="1";
                }
                // for(int j=0; j<kount; j++) {
                    a+=")";
                // }
                
            }
        }

        cout<<"Case #"<<t<<": "<<a<<"\n";

    }

    return 0;
}

