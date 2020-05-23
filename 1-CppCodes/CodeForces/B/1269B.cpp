/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <bits/stdc++.h>


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
     * @brief: a[i] + x mod m = b_pi
     *       => x = b_pi - a[i]  + m mod m, 
     *  such as x = b0 - a[i] + m mod m
     *  so we can bruteforce to find the minimum x
     * 
     * MOD formula: bi = (ai + x)%m     <=>     x = (bi - ai + m)%m
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

    int n,m, x;
    int minimus = INT_MAX;

    cin>>n>>m;
    int a[n];
    int b[n];

    for(int i=0; i<n; i++) {    cin>>a[i];  }
    for(int i=0; i<n; i++) {    cin>>b[i];  }

    multiset<int> msB;
    for(int i=0; i<n; i++) {    msB.insert(b[i]);   }

    multiset<int> msTemp;
    for(int i=0; i<n; i++) {
        x = (b[0] - a[i] + m) % m;  // x for ith a
        msTemp.clear();

        for(int j=0; j<n; j++) {    
            int temp = (a[j] + x ) % m;
            msTemp.insert(temp);    // for x[i] , create the new permutation
        }
        if(msTemp == msB) {  // then check if these 2 permutations are equal or not
            minimus = min(minimus,x);   // if yes, update minimus
        }
    }
    cout<<minimus<<"\n"; // output minimus x

    return 0;
}

