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
#include <set>
#include <map>
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

int primes[] = {2,3,5, 
                7,11,13, 
                17,19,23, 
                29,31};

int a[1005] = {0};

void preprocess(){
    int color=0;
    for(int j=0; j<11; j++){
        int m = primes[j];
        color++;
        for(int i=m; i<1005; i=i+m){
            // if(a[i]==0)
                a[i] = color;
        }
    }
}

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

    preprocess();

    int T, n, b, m, kolor;
    vector<int> v;
    // set<int> s;
            
    cin>>T;
    while(T--){
        cin>>n;
        kolor = 1;
        int mp[12] = {0};
    
        for(int i=0; i<n; i++){ 
            cin>>b;
            v.push_back(a[b]);
            if(!mp[a[b]]){
                mp[a[b]] = kolor;
                kolor++;
            }

        }

        m = kolor-1;//mp.size();
        cout<<m<<"\n";
        for(int i=0; i<n; i++){
            cout<<mp[v[i]]<<" ";
        }cout<<"\n";

        v.clear();
        // mp.clear();
    }

    return 0;
}

