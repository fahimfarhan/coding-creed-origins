/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
#include <cmath>
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

    ll T,n;
    long double h,c,t,p,x,y;

	cin>>T;
	while(T--){
		cin>>h>>c>>t;

		if(h+c>=2*t){   cout<<"2\n";   }
        else{
            n=(t-c)/(2*t-h-c);
            
            x=((h+c)*n-c)/(2*n-1)-t;
            y=((h+c)*n+h)/(2*n+1)-t;

            if(fabs(x)>fabs(y))cout<<2*n+1<<"\n";
            else cout<<2*n-1<<"\n";
        }
	}

	return 0;
}