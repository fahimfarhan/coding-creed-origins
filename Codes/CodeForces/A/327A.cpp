/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int n, kount, *a, *local_maxima, maximus;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    a = new int[n+1];
    local_maxima = new int[n+1];
    for(int i=0; i<=n; i++){    local_maxima[i] = 0; a[i] = 0;   }
    kount = 0;
    for(int i=0; i<n; i++){ cin>>a[i];  }
    for(int i=0; i<n; i++){ 
        if(a[i]==0){    
            a[i] = 1;   
        }
        else{  
            a[i] = -1; 
            kount++;  
        } 
    }
    local_maxima[0] = 0;
    maximus = INT_MIN;


    for(int i=1; i<=n; i++){
        local_maxima[i] = max(local_maxima[i-1]+a[i-1], a[i-1]);
        maximus = max(local_maxima[i], maximus);
    }

    cout<<(maximus+kount)<<"\n";

    delete[] a;
    delete[] local_maxima;
    


    return 0;
}

