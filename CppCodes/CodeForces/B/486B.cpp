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

    int n,m;
    bool **a, **b;

    cin>>n>>m;

    a = new bool*[n+1]; b = new bool*[n+1];
    for(int i=0; i<=n; i++){    a[i]=new bool[m+1]; b[i]=new bool[m+1]; }

    for(int i=1; i<=n; i++){    
        for(int j=1; j<=m; j++){    
            //cin>>b[i][j];
             a[i][j]=1;
        }
    }

    for(int i=1; i<=n; i++){    
        for(int j=1; j<=m; j++){    
            cin>>b[i][j];
            //a[i][j]=1;
            if(b[i][j]==0){
                for(int k=1; k<=n; k++){    a[k][j]=0; }
                for(int k=1; k<=m; k++){    a[i][k]=0; }
            }
        }
    }

    bool *row, *col;
    row = new bool[n+1]; col = new bool[m+1];
    for(int i=0; i<=n; i++){    row[i]=0; }
    for(int i=0; i<=m; i++){    col[i]=0; }

    for(int i=1; i<=n; i++){    
        for(int j=1; j<=m; j++){    
            //cin>>b[i][j];
             //a[i][j]=1;
             row[i]=(row[i]|a[i][j]);
             col[j]=(col[j]|a[i][j]);
        }
    }

    
    bool x=true,y=true,z=true;

    for(int i=1; i<=n; i++){    
        for(int j=1; j<=m; j++){    
            x = b[i][j]; y = (row[i]|col[j]);
            if(x!=y){   z = false; break; }
        }
        if(!z)break;
    }

    if(z){  
        cout<<"YES\n";  
        for(int i=1; i<=n; i++){    
            for(int j=1; j<=m; j++){    
            //cin>>b[i][j];
                cout<<a[i][j]<<" ";
            }cout<<"\n";
        }
    }else{  cout<<"NO\n";   }
    delete[] row; delete[] col;
    for(int i=0; i<=n; i++){    delete[] a[i]; delete[] b[i];   }
    delete[] a; delete[] b;
    
    return 0;
}
