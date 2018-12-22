#include <bits/stdc++.h>

using namespace std;

int n, *p;
int **m;
int **s;

int MCM(int i,int j){
    if(i==j){   return 0;    }
    if(m[i][j]!=-1){    return m[i][j]; }
    m[i][j] = INT_MAX;
    //int q = INT_MAX;
    for(int k=i; k<j; k++){
        int q = MCM(i,k)+MCM(k+1,j)+p[i-1]*p[k]*p[j];
        if(q<m[i][j] ){ m[i][j] = q; s[i][j] = k;  }
    }
    return m[i][j];
}

void printOptimalParenthesis(int i, int j){
    if(i==j){   cout<<"A"<<i<<""; }
    else{   
        cout<<"(";
        printOptimalParenthesis(i,s[i][j]);
        printOptimalParenthesis(s[i][j]+1, j);
        cout<<")";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    m = new int*[n+1]; s = new int*[n+1];

    for(int i=0; i<=n; i++){ m[i] = new int[n+1]; s[i]  = new int[n+1];    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            m[i][j] = -1;
            s[i][j] = INT_MAX;
        }
    }
    for(int i=0; i<=n; i++){    m[i][i]=0;  }

    p = new int[n+1];
    for(int i=0; i<=n; i++){
        cin>>p[i];
    }

    cout<<MCM(1,n)<<"\n";
    printOptimalParenthesis(1,n);
    cout<<"\n";

    for(int i=0; i<=n; i++){ delete[] m[i]; delete[] s[i];    }
    delete[] m; delete[] s;
    if(!p)delete[] p;
    return 0;
}