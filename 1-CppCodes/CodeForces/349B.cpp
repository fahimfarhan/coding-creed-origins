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

int v,minimus,index, a[10];
    

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

    
    cin>>v;
    minimus = INT_MAX;

    for(int i=1; i<=9; i++){    cin>>a[i];  }

    index = 0;
    for(int i=1; i<=9; i++){    if(a[i]<=minimus){   minimus = a[i]; index=i; }  }

    if(v<minimus){  cout<<"-1\n";   }
    else{   
        v = v/minimus;
        for(int i=0; i<v; i++){ cout<<index; }
        cout<<"\n";
    }

    return 0;
}
