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

int n,m, *a;

bool recurse(int sum, int index){
    if(index == n){ // 0 based indexing
        if((sum%360)==0){   return true; }
        else return false;
    }
    bool ret = true;
    int s1 = sum+a[index], s2=sum-a[index];
    int i = index+1;
    ret = ( recurse(s1, i) | recurse(s2,i) );
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

    cin>>n;
    a = new int[n+1];
    for(int i=0; i<n; i++){    cin>>a[i];  }

    bool b = recurse(0,0);
    if(b) cout<<"YES\n";
    else cout<<"NO\n";
    
    if(!a)delete[] a;
    return 0;
}
