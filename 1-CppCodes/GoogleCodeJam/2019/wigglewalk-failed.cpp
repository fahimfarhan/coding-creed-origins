#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

bool isValidIndex(int x, int y);


// int n,m;
vector<int> *g;
bool isvisited[50005][50005];

int T, n, r,c,sr,sc;
string s;

bool isValidIndex(int x, int y){
    if( (x>=1) && (x<=r) && (y>=1) && (y<=c) ){   return true; }
    return false;
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

    cin>>T;
    for(int t=1; t<=T; t++){
        s = "";
        cin>>n>>r>>c>>sr>>sc;
        cin>>s;
        //isvisited = new bool*[r+1];
        //for(int i=0; i<=r; i++){    isvisited[i] = new bool[c+1];   }

        for(int i=0; i<=r; i++){    for(int j=0; j<=c; j++){    isvisited[i][j] = false;    }   }
        isvisited[sr][sc] = true;
        
        int dirsr=0, dirsc=0;

        for(int i=0; i<n; i++){
            if(s[i]=='N'){  dirsr=-1; dirsc = 0; }
            else if(s[i] == 'S'){   dirsr=1; dirsc = 0; }
            else if(s[i] == 'E'){   dirsc=1; dirsr = 0; }
            else if(s[i] == 'W'){   dirsc=-1; dirsr = 0; }

            while(true){
                sr+= dirsr;
                sc+= dirsc;
                if(!isvisited[sr][sc]){
                    isvisited[sr][sc] = true; break; 
                }
            }
        }

        cout<<"Case #"<<t<<": "<<sr<<" "<<sc<<"\n";
        
        //for(int i=0; i<=r; i++){    delete[] isvisited[i];   }
        //delete[] isvisited;
    }

    return 0;
}
