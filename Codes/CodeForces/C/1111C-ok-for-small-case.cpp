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

int size1, sizex2, n,k;
ll A,B, *a;

ll divideAndConqure(int L, int R, int index){
    ll ret = 0;
    if(R<L){    return 0; }
    if(index >= sizex2 ){ return 0; }

    if(L==R){
        if(a[index]==0){  ret = A;  return ret; }
        else{   ret = B*a[index]*1; return ret; }
    }
    ll case1=0, case2=0;

    if(a[index]==0){    case1 = A; }
    else{   case1 = B*a[index]*(R-L+1); }

    int mid1 = (L+R); mid1 = mid1>>1;
    int mid2 = mid1+1;
    int left = index<<1; int right = left|1;

    case2 = divideAndConqure(L, mid1, left)+divideAndConqure(mid2, R, right);
    //ret = min(case1, case2);
    ret = case1; 
    if(case2<case1){    ret = case2; }
    return ret;
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

    cin>>n>>k>>A>>B;
     size1 = 1<<n;
     sizex2=size1<<1; // 2xsize , needed for segment tree
    a = new ll[sizex2+1];
    for(int i=0; i<=sizex2; i++){    a[i]=0;  }
    int pos=0;
    for(int i=0; i<k; i++){ cin>>pos; pos = pos + size1-1; a[pos]++; }

    int l, r;
    // build
    for(int i=size1-1; i>0; i--){
        l = i<<1; r = l|1;
        a[i] = a[l]+a[r];
    }

    int ans = divideAndConqure(1,size1, 1);
    cout<<ans<<"\n";
    if(!a)delete[] a;
    
    return 0;
}
