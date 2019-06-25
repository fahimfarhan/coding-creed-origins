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
    int n, *a;
    cin>>n;
    a = new int[n+1];
    int maximus=0;
    int maximusCount=0;
    for(int i=0; i<n; i++){ cin>>a[i]; maximus = max(maximus, a[i]); }
    for(int i=0; i<n; i++){  if(a[i]==maximus){  maximusCount++; }   }

    // cout<<maximus<<" "<<maximusCount<<"\n";
    if( (maximusCount&1) == 1){ cout<<"Conan\n";    }
    else{
        if((maximusCount<n) && ( (maximusCount&1) == 0) ) {    cout<<"Conan\n";    }   
        else {  cout<<"Agasa\n";  }  
    }
    
    delete[] a;

    
    return 0;
}
