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

    int t;
    cin>>t;
    string s;
    int oneKount, left, right, n;
    while(t--){
        cin>>s;
        oneKount = 0; left = -1; right = -1;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] =='1'){
                oneKount++;
                right = i;
                if(left == -1){
                    left = i;
                }
            }
        }
        if(oneKount<=1){
            cout<<"0\n";
        }else{
            n = right - left +1;
            n = n - oneKount;
            cout<<n<<"\n";
        }
    }


    return 0;
}

