#include <bits/stdc++.h> 
using namespace std;

class Seive{
public:
    bool *A;
    vector<int> v;
    Seive(int n){
        A = new bool[n+1];
        for(int i=0; i<=n; i++){ A[i] = true;}
        A[0] = false; A[1] = false;
        //v.push_back(2);
        int stop = (int)sqrt(n);
        //cout<<"Stop = "<<stop<<endl;
        //int curr;
        // eliminate even numbers except 2
        for(int i=4; i<=n; i+=2){ A[i] = false; }
        // eliminate remaining numbers    
        for(int i=3; i<=stop; i++){
            if(A[i]==true){
                //curr = i;
                //v.push_back(i);
        //        cout<<"pushed back = "<<i<<endl;
                //int temp = 2*curr;
                for(int j = 3*i; j<=n;j+=2*i){
                    A[j]=false;
        //            cout<<"j="<<j<<endl;
                }
            }
        }

        for(int i=0; i<=n; i++)
        { 
        //    cout<<i<<" "<<A[i]<<"\n";
            if(A[i]){v.push_back(i);}    
        }
        
        vector<int>::iterator it;
        //for(it = v.begin(); it!=v.end(); it++)
        
        //    cout<<*it<<" ";
        
        //cout<<endl;

        // t prime
        //cout<<"The t primes are:\n";
        //vector<int

    }
    ~Seive(){
        if(!A){
            delete[] A;
        }
    }
};

int main()
{
    int q;
    int64_t n;
    // cout<<"Enter n: ";
    Seive *s = new Seive(100);

    int64_t *a;
    int l = s->v.size();
    a = new int64_t[l];
    a[0] = s->v[0];
    for(int i=1; i<l; i++){
        a[i] = a[i-1]*(s->v[i]);
    }

    cin>>q;
    while(q--){
        cin>>n;
        int lb = lower_bound(a,a+l,n)-a;
		if(a[lb+1]==n){	lb++;}
        cout<<lb<<"\n";
    }
    if(!a)delete[] a;
    return 0;
}

