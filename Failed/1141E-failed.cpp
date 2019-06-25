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
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll H,n, *d, sum=0;
    cin>>H>>n;
    d = new ll[n+1];
    for(int i=0; i<n; i++){
        cin>>d[i];
        sum+=d[i];
    }

    if(sum >=0 ){   cout<<"-1\n";   }
    else{
        ll a = abs(sum);
        ll D = H/a;
        D--;
        ll R = H - a*D;

        ll minute = D*n;
        while(R<=0){
            for(int i=0; i<n; i++){
                R=R+d[i];
                minute++;
                if(R<=0){ break; }
            }
        }
        
        cout<<minute<<"\n";


    }
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/