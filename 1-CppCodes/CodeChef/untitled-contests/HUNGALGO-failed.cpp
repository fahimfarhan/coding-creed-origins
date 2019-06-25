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

int **a;
int T,N;
int r, c;
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
    while(T--){
        cin>>N;
        a = new int*[N+1]; for(int i=0; i<=N; i++){ a[i] = new int[N+1];    }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>a[i][j];
            }
        }

        for(int i=0; i<N; i++){
            r = INT_MAX;
            for(int j=0; j<N; j++){ r = min(r,a[i][j]); }
            for(int j=0; j<N; j++){ a[i][j]-=r; }
        }

       for(int i=0; i<N; i++){
            c = INT_MAX;
            for(int j=0; j<N; j++){ c = min(r,a[j][i]); }
            for(int j=0; j<N; j++){ a[j][i]-=c; }
        }

        for(int i=0; i<=N; i++){ delete[] a[i];    } delete[] a;
    }
    
    return 0;
}
