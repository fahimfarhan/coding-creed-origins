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

    int n;
    
    cin>>n;
    if( (n==1) || (n==2) ){
        cout<<"1\n1\n";
    }
    else if(n == 3){
        cout<<"2\n1 3\n";
    }else{
        cout<<n<<"\n";
        for(int i=2; i<=n; i+=2){
            cout<<i<<" ";// v.push_back(i);
        }        
        for(int i=1; i<=n; i+=2){
            cout<<i<<" ";    // v.push_back(i);
        }
        cout<<"\n";
    }
    return 0;
}

