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

int interact(vector<int> s) {
    // give interactive input
    cout<<"? "<<s.size()<<" ";
    for(int i=0; i<s.size(); i++) { cout<<s[i]<<" ";    }
    cout<<"\n";
    cout.flush();
    
    // get interactive output and return
    int x;
    cin>>x;
    return x;
}

vector<int> getComplement(vector<int> v, int n) {
    vector<int> ask, occur(n+1); // 0,0,0,...,0 n+1 zeroes
    for(int i : v) {    occur[i] = 1;   }

    for(int i=1; i<=n; i++) {
        if(!occur[i]) { ask.push_back(i);   }
    }

    return ask;
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

    ---------- Interactive problems ---------
    
        on each interactive questions' end, add `cout.flush()`
        say, cout<<"some weirdo question";
        cout<<"\n"; // end of question
        cout.flush(); // <-- just like this

        if still confusing, check out 1363D.cpp
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin>>T;
    while(T--) {
        // 1. take input
        int n,k;
        cin>>n>>k;
        vector< vector<int> > s(k);
        vector<int> ans(k);
        int c = 0, temp = 0;
        for(int i=0; i<k; i++) {
            cin>>c;
            for(int j=0; j<c; j++) {
                cin>>temp;
                s[i].push_back(temp);
            }
        }

        // 2. the actual stuff
        vector<int> ask;
        for(int i=1; i<=n; i++) {   ask.push_back(i);   }
        int maximus = interact(ask);    // the 1st question: get Maximus

        // find subset with maximus element
        int start = 0; 
        int end = k - 1;

        while(start < end) {
            int mid = (start + end) >> 1;
            ask.clear();

            for(int i=0; i<=mid; i++) {
                for(int j : s[i]) {
                    ask.push_back(j);
                }
            }

            int tempMaximus = interact(ask);
            if(tempMaximus == maximus) {    end = mid;  }
            else{    start = mid + 1;    }
        }

        ask = getComplement(s[start], n);

        for(int i=0; i<k; i++) {
            if(i == start) {    ans[i] = interact(ask);  }
            else{   ans[i] = maximus;       }
        }

        cout<<"! ";
        for(int i : ans) {  cout<<i<<" ";   }
        cout<<"\n"; 
        cout.flush();

        string isCorrect;
        cin>>isCorrect;

        if(isCorrect == "Incorrect") {
            exit(0);
        }
    }

    return 0;
}

