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
        
    ll N, x1, y1, x2, y2;
    ll L;
    double a, b, ab, area = 0;
    cin>>N;
    while(N--){
        cin>>x1>>y1>>x2>>y2>>L;
        a = (L*1.0)/2;
        ab = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        b = 0.5*sqrt(L*L-ab);
        area = PI*a*b;
        if(area<0){ area = 0;   }
        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        cout<<area<<"\n";
    } 


    return 0;
}

