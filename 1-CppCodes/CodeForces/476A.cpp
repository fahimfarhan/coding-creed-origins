#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

//#define ll long long int

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

    int n,m;
    cin>>n>>m;
    if(m>n){    cout<<"-1\n"; exit(0);  }
    
    int ul,ll;
    ul = n; 
    ll = n>>1;
    if((n&1)==1){   ll++; }

    int temp = ll/m;
    if(ll%m!=0){    temp++; }
    temp=temp*m;
    if(temp<=ul){
        cout<<temp<<"\n";   
    }else{  
        cout<<"-1\n";
    }

    
    return 0;
}
