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

    int n;
    ll *a;
    int temp=0, maximus=0;
    cin>>n;

    a = new ll[n+1];

    for(int i=0; i<n; i++){    cin>>a[i];     }

    temp=1;
    for(int i=1; i<n; i++){
        if(a[i]>a[i-1]){    temp++; }
        else{
            maximus = max(maximus, temp);
            temp=1;
        }
    }
    maximus = max(maximus, temp);
            
    cout<<maximus<<"\n";

    delete[] a;
    return 0;
}
