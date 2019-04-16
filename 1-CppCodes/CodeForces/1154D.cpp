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

    int X, n,a,b,amax, *s;

    cin>>n>>b>>a;
    amax = a;
    
    s = new int[n+1]; for(int i=0; i<=n; i++){ s[0]=0; }
    for(int i=01; i<=n; i++){ cin>>s[i];    }

    X = 0;
    int i=0;
    bool b1 = true;
    while(b1){

        if(X == n){ 
            //b1 = false;
         break; }
        if( (a == 0) && (b == 0) ){ //b1 = false; 
            break; }
        i = X+1;

        // cout<<a<<" "<<b<<" "<<i<<" "<<X<<"\n";
        
        if( (s[i] == 1) && (b>0) ){ 
            b--;
            X=X+1;
            a = a+1; //min(amax, a+1);
            a = min(a,amax);
        }else if( (s[i] == 1) && (b==0) && (a>0) ){
            a--;
            X=X+1;
        }else if( (s[i] == 1) && (b==0) && (a==0) ){
            //b1=false; 
            break; 
        }else if( (s[i]==0) && (b>=0) && (a>0) ){
            a--; X=X+1;
        }else if( (s[i]==0) && (b>0) && (a==0) ){
            b--; X=X+1;
        }else if( (s[i]==0) && (b==0) && (a==0) ){
            //b1 = false; 
            break;
        }
    }
    cout<<X<<"\n";
    if(!s)delete[] s;
    return 0;
}
