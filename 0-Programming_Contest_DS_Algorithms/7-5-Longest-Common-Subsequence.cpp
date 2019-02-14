#include <bits/stdc++.h>

using namespace std;

string x,y;
char **b;
int  **c;
int m,n;

void LCS(){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = '\\';
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = '|';
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = '_';
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>x>>y;

    m = x.length(); n = y.length();
    x = " "+x; y = " "+y;
    b = new char*[m+1];
    c = new int*[m+1];
    for(int i=0; i<=m; i++){
        b[i] = new char[n+1];
        c[i] = new int[n+1];
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            b[i][j] = ' ';
            c[i][j] = -1;
        }
    }

    for(int i=0; i<m; i++){   c[i][0] = 0; }
    for(int i=0; i<n; i++){   c[0][i] = 0; }



    for(int i=0; i<=m; i++){
        delete[] b[i];// = new char[n+1];
        delete[] c[i];// = new int[n+1];
    }
    delete[] b;
    delete[] c;
    return 0;
}