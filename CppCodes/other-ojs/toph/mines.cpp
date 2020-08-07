/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

ll R, C;
int **m;

bool isSafe(int i, int j){
    if(0<=i && i<R && 0<=j && j<C){ return true;    }
    return false;
}

void f(int i, int j){
    if(isSafe( (i+1),j-1)){   m[i+1][j-1]++;    }
    if(isSafe((i+1),(j))){  m[i+1][j]++; }
    if(isSafe((i+1),(j+1))){  m[i+1][j+1]++; }

    if(isSafe( (i),j-1)){   m[i][j-1]++;    }
    if(isSafe((i),(j+1))){  m[i][j+1]++; }

    if(isSafe( (i-1),j-1)){   m[i-1][j-1]++;    }
    if(isSafe((i-1),(j))){  m[i-1][j]++; }
    if(isSafe((i-1),(j+1))){  m[i-1][j+1]++; }
}


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

    cin>>R>>C;

    string s[R+1];
    
    m = new int*[R+1];
    
    for(int i=0; i<=R; i++){    m[i] = new int[C+1];    }

    for(int i=0; i<R; i++){    cin>>s[i];  }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){ m[i][j] = 0;    }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){ 
            if(s[i][j] == '*'){
                f(i,j);
            }
        }
    }


    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(s[i][j] == '*'){ cout<<"*";  }
            else if(m[i][j]==0){    cout<<".";  }
            else{   cout<<m[i][j];  }
        }cout<<"\n";
    }


    for(int i=0; i<=R; i++){    delete[] m[i];  }
    delete[] m;

    return 0;
}