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

int n;
char **s;

void f(int i, int j){
    if(  (s[i][j]=='.') && (s[i+1][j]=='.') && (s[i-1][j]=='.')&& (s[i][j+1]=='.')&& (s[i][j-1]=='.') ){
        s[i][j]='x'; s[i+1][j]='x'; s[i-1][j]='x'; s[i][j+1]='x'; s[i][j-1]='x';
    }
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


    cin>>n;

    s = new char*[n+1];
    char ch;
    for(int i=0; i<=n; i++){    s[i] = new char[n+1];   }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>s[i][j];
            //s[i][j]=ch;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
     //       cin>>ch;
            cout<<s[i][j];
        }cout<<"\n";
    }
    cout<<"\n\n";

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
             if(  (s[i][j]=='.') && (s[i+1][j]=='.') && (s[i-1][j]=='.')&& (s[i][j+1]=='.')&& (s[i][j-1]=='.') ){
                s[i][j]='x'; s[i+1][j]='x'; s[i-1][j]='x'; s[i][j+1]='x'; s[i][j-1]='x';
            }
        }
    }

    bool b = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[i][j]=='.'){   b=false; cout<<"NO\n";  break; }
        }
        if(b==false){ break; }
    }

    if(b){ cout<<"YES\n";    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
     //       cin>>ch;
            cout<<s[i][j];
        }cout<<"\n";
    }
    cout<<"\n\n";

    for(int i=0; i<=n; i++){    if(!s[i])delete[] s[i]; }
    if(!s)delete[] s;

    return 0;
}
