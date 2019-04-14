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

    int m,n,h;
    int *front, *left, **a;

    cin>>n>>m>>h;
    front = new int[m+10];
    left = new int[n+10];
    a = new int*[n+10];
    for(int i=0; i<=n; i++){    a[i] = new int[m+10];    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){ a[i][j]=0;   }
    }
    for(int i=0; i<m; i++){    cin>>front[i];   }
    for(int i=0; i<n; i++){     cin>>left[i];   }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ cin>>a[i][j];   }
    }

    int minimus=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==1){
                minimus = min(left[i], front[j]);
                a[i][j]=minimus;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ cout<<a[i][j]<<" ";   }cout<<"\n";
    }

    for(int i=0; i<=n; i++){
        delete[] a[i];
    }
    delete[] a;
    delete[] left;
    delete[] front;
    return 0;
}
