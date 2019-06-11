#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define N 2750131

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int cnt[N+1];


class Seive{
public:
    int n, stop;
    bool *A;
    vector<int> v;
    int *biggestDivisor;
//public:
    Seive(){
        //cout<<"Enter n:\n";
        //cin>>n;
        n = N;
        stop = (int)sqrt(n)+1;

        A = new bool[n+1];
        biggestDivisor = new int[N+1];
        
        for(int i=0; i<=n; i++){
            A[i] = true;
            biggestDivisor[i] = 1;
        }
        A[0] = false;
        A[1] = false;

        //eliminate evens
        //v.push_back(2);
        
        for(int i=4; i<=n;i+=2){ A[i] = false; biggestDivisor[i] = max(biggestDivisor[i],2);  }
        // eliminate rest
        for(int i=3; i<=stop; i++){  // i=3,5,7,...,n
            //cout<<i<<" A[i]="<<A[i]<<endl;
            if(A[i]){
                //v.push_back(i);
                //cout<<"pushed back "<<i<<endl;
                for(int j=i; j<=n; j+=i){
                    A[j] = false;
                    if(i!=j){ biggestDivisor[j] = max(biggestDivisor[j],i); }
                }
            }
        }

        for(int i=0; i<=n; i++){
            if(A[i]) v.push_back(i);
        }

        /*
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<endl;*/
        
    }

    ~Seive(){
        if(!A)delete[] A;   
        if(!biggestDivisor)delete[] biggestDivisor;
    }
};



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

    int n,m;
    vector<int>a;

    cin>>n;
    n = n<<1;

    for(int i=0; i<=N; i++){    cnt[i] = 0;  }

    Seive s;
    
    int x,y;
    for(int i=0; i<n; i++){ cin>>x; cnt[x]++; }

    
    for(int i=N; i>=0; i--){
        if(cnt[i]>0){
            if(s.A[i]){
                // if i is prime 
                a.push_back(i);
                cnt[s.v[i]]--;
                cnt[i]--;
            }else{
                cnt[i]--;
                cnt[s.biggestDivisor[i]]--;
                a.push_back(s.biggestDivisor[i]);
            }
        }
    }

    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }cout<<"\n";
    

    return 0;
}
