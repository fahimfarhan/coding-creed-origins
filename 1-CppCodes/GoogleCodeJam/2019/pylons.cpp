#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int T, R, C;


// int n,m;
bool **g;
vector< pair<int, int> > order;
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

    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>R>>C;
        g = new bool*[R+1];
        for(int i=0; i<=R; i++){    g[i] = new bool[C+1];   }

        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                
            }
        }
        
        for(int i=0; i<=C; i++){    delete[] g[i];  }
        if(!g)delete[] g;
    }

    return 0;
}
