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


// int n,m;s
vector<pair<int,int> > v7094;
bool *isvisited;


int n,m;
int a[300001];

int partition(int lo,int hi){ 
    
    int pivot = a[hi];
    int i=lo;

    for(int j=lo; j<(hi-1); j++){
        if(a[j]<pivot){
            swap(a[j], a[i]);
            int x = i+1; int y=j+1;
            v7094.push_back({x,y});
            i=i+1;
        }
    }
    swap(a[i],a[hi]);
    int x = i+1; int y=hi+1;
    v7094.push_back({x,y});
    //i=i+1;
    
    return i; 
    
}

void quickSort(int lo, int hi){
    if(lo<hi){
        int pivot = partition(lo,hi);
        int x = pivot-1;
        int y = pivot+1;
        quickSort(lo,x );
        quickSort(y, hi);
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
    for(int i=0; i<n; i++){ cin>>a[i];  }

    quickSort(0,n-1);

    for(int i=0; i<n; i++){    cout<<a[i]<<" ";    }cout<<"\n";

    m = v7094.size();
    cout<<m<<"\n";
    for(int i=0; i<m; i++){
        cout<<v7094[i].first<<" "<<v7094[i].second<<"\n";
    }
    return 0;
}
