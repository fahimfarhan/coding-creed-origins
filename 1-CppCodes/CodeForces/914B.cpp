#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
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
    int N = 100005;
    int n,m, a[100005];
    
    for(int i=0; i<N; i++){ a[i]=0; }
    
    cin>>n;
    for(int i=0; i<n; i++){ cin>>m; a[m]++; }
    bool b = true;
    for(int i=0; i<N; i++){
        if( (a[i]&1) == 1){ b = false; break; }
    }
    if(b){  cout<<"Agasa\n";    }
    else{   cout<<"Conan\n";    }
    return 0;
}
