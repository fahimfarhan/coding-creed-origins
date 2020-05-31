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

/**
 * @brief: I learned this algo when I was in class 9 from a friend
 *         named usama. The game was a grid puzzle, where you have
 *         to draw grids / something like that... 10 years have 
 *         passed since that event.   
 * 
*/
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

    int T, n, x, u, v, *degree;

    cin>>T;
    while(T--) {
        cin>>n>>x;
        degree = new int[n+1];
        for(int i=0; i<=n; i++) {   degree[i] = 0;  }

        for(int i=0; i<n-1; i++) {    
            cin>>u>>v;  
            degree[u]++; 
            degree[v]++;
        }

        if(degree[x] <= 1)  {   cout<<"Ayush\n";    }
		else{
			if(n % 2){  cout << "Ashish\n";  }
			else{   cout << "Ayush\n";   }	
		}

        delete[] degree;
    }


    return 0;
}

