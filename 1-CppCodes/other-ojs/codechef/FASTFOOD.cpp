#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll int64_t

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

    int T, N;
    int a[100005], b[100005];
    ll sum; int maximus;
    cin>>T;
    while(T--){
        cin>>N;
        
        //a = new int[N+1]; b = new int[N+1]; 

        for(int i=0; i<N; i++){    cin>>a[i];  }
        for(int i=0; i<N; i++){    cin>>b[i];  }
        
        sum=0; maximus=0;
        for(int i=0; i<N; i++){    
            if(a[i]>b[i]){  sum=sum+a[i]; }
            else{ sum=sum+b[i]; }
       }

        cout<<sum<<"\n";
        

        //delete[] a; delete[] b;
    }

    
    return 0;
}
