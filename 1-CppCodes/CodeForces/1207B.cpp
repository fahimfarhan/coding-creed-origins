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

int **a, **b;
bool isOk( const int&  i,const int& j){
    if( (a[i][j] == a[i+1][j]) && (a[i][j] == a[i][j+1]) && (a[i+1][j+1] == a[i+1][j]) && (a[i][j]==1) ){
        return true;
    }return false;
}

void setB(const int&  i,const int& j){
    b[i][j] = 1;b[i+1][j] = 1;b[i][j+1] = 1;b[i+1][j+1] = 1;
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

    ll n,m, k;
    vector<pair<int,int> > v;
    k = 0;
    cin>>n>>m;
    a = new int*[n+1]; for(int i=0; i<=n; i++){  a[i]=new int[m+1];  }
    b = new int*[n+1]; for(int i=0; i<=n; i++){  b[i]=new int[m+1];  }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            b[i][j] = 0; a[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(isOk(i,j)){
                setB(i,j);
                
                v.push_back({i,j});
            }
        }
    }

    bool ok = true;
    int acount=0, bcount=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            acount+=a[i][j];
            bcount+=b[i][j];
        }
    }

    //cout<<acount<<"\n";
    //cout<<bcount<<"\n";

    if(acount!=bcount){ ok = false; }

    if(!ok){
        cout<<"-1\n";
    }else{
        cout<<v.size()<<"\n";
        for(int i=0; i<v.size(); i++){
            cout<<(v[i].first+1)<<" "<<(v[i].second+1)<<"\n";
        }
    }

    return 0;
}