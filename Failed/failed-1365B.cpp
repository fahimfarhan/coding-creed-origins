/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
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
#include <algorithm>
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


bool sortOrder(const pair<int,int>& p1,const pair<int,int>& p2) {
    return ((p1.second != p2.second) && (p1.first<p2.first));
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

    ll T;
    cin>>T;

    int n;
    int a, b;
    vector<pair<int,int> > v;

    while(T--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>a;
            v.push_back({a,0});
        }

        for(int i=0; i<n; i++) {
            cin>>b;
            v[i].second = b;
        }

        sort(v.begin(), v.end(), sortOrder);

        a = v[0].first;
        bool isSorted = true;
        for(int i=1; i<n; i++) {
            if(v[1].first < a) {    isSorted = false;  break;    }
            a = v[1].first;
        }

        if(isSorted) {  cout<<"Yes\n";  }
        else{   cout<<"No\n";   }
    }


    return 0;
}

/*
---------- Interactive problems ---------

    on each interactive questions' end, add `cout.flush()`
    say, cout<<"some weirdo question";
    cout<<"\n"; // end of question
    cout.flush(); // <-- just like this

    if still confusing, check out 1363D.cpp
    
*/