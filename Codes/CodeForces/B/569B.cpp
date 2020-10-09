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

    vector<int> v;
    int n,*a, *cnt;

    cin>>n;

    a = new int[n+1];
    cnt = new int[100001];
    for(int i=0; i<100001; i++){    cnt[i]=0;   }

    for(int i=1; i<=n; i++){    
        cin>>a[i];
        cnt[a[i]]++;
        if( (cnt[a[i]]>1) || (a[i]>n) ){
            v.push_back(i);
        }
    }

    int j=0;
    for(int i=1; i<=n; i++){
        if(!cnt[i]){
            j= v.back(); v.pop_back();
            a[j]=i;
        }
    }

    for(int i=1; i<=n; i++){    cout<<a[i]<<" ";    }cout<<"\n";   

    if(!a)delete[] a;
    if(!cnt)delete[] cnt;

    
    return 0;
}
