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
    int **a, **b;
    cin>>n>>m;

    a = new int*[n+1]; b = new int*[n+1];
    for(int i=0; i<=n; i++){    a[i]=new int[m+1]; b[i]=new int[m+1];  }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ cin>>a[i][j];   }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ cin>>b[i][j];    }
    }

    //int temp=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(b[i][j]<a[i][j]){
                a[i][j] = a[i][j]^b[i][j]; 
                b[i][j]=a[i][j]^b[i][j];
                a[i][j]=a[i][j]^b[i][j];
            }
        }
    }

    bool result=true;
    
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            if(a[i][j]<=a[i][j-1]){    result=false;   }
            if(b[i][j]<=b[i][j-1]){    result=false;   }
        }
    }


    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]<=a[i-1][j]){    result=false;   }
            if(b[i][j]<=b[i-1][j]){    result=false;   }            
        }
    }



    if(result){ cout<<"Possible\n";   }
    else{     cout<<"Impossible\n";   }


    for(int i=0; i<=n; i++){    delete[] a[i]; delete[] b[i];   }
    delete[] a; delete[] b;
    return 0;
}
