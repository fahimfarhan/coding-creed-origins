#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

bool comparator(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
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

    int n, a,b;
    pair<int,int> *p;

    cin>>n;
    p = new pair<int,int>[n+1];
    for(int i=0; i<n; i++){
        cin>>a>>b;
        p[i].first = a; p[i].second = b;
    }

    sort(p,p+n,comparator);

    bool b123 =  false;

    for(int i=1; i<n; i++){
        if(p[i-1].second>p[i].second){
            b123 = true; break;
        }
    }

    if(b123){
        cout<<"Happy Alex\n";
    }else{
        cout<<"Poor Alex\n";
    }

    delete[] p;
    return 0;
}
