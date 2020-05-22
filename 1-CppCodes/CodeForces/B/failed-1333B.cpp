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

    int T, n;
    int a[100005];
    ll b[100005];
    bool isPossible = true;
    int firstPositiveA = 0, firstPositiveB = 0; 
    int firstNegativeA = 0, firstNegativeB = 0;
    cin>>T;
    while(T--){
        cin>>n;

        firstNegativeA = -1; 
        firstPositiveA = -1;
        for(int i=0; i<n; i++){    
            cin>>a[i];  
            if(firstNegativeA==-1 && a[i] < 0){   firstNegativeA = i;  }
            if(firstPositiveA==-1 && a[i] > 0){   firstPositiveA = i;  }
        }
        for(int i=0; i<n; i++){ 
            cin>>b[i];  
            if(firstNegativeB==-1 && b[i] < 0){   firstNegativeB = i;  }
            if(firstPositiveB==-1 && b[i] > 0){   firstPositiveB = i;  }
        }

        isPossible = true;
        if(a[0] != b[0]){
            isPossible = false;
        }
        if(firstNegativeA > firstNegativeB){
            isPossible = false;
        }
        if(firstPositiveA > firstPositiveB){
            isPossible = false;
        }

        if(isPossible){ cout<<"YES\n";  }
        else{   cout<<"NO\n";   }
    }


    return 0;
}

