#include <bits/stdc++.h>

using namespace std;

class Seive{
private:
    int n, stop;
    bool *A;
    vector<int> v;

public:
    Seive(){
        cout<<"Enter n:\n";
        cin>>n;
        stop = (int)sqrt(n)+1;
        A = new bool[n+1];
        for(int i=0; i<=n; i++){
            A[i] = true;
        }
        A[0] = false;
        A[1] = false;

        //eliminate evens
        //v.push_back(2);
        for(int i=4; i<=n;i+=2){ A[i] = false; }
        // eliminate rest
        for(int i=3; i<=stop; i++){  // i=3,5,7,...,n
            //cout<<i<<" A[i]="<<A[i]<<endl;
            if(A[i]){
                //v.push_back(i);
                //cout<<"pushed back "<<i<<endl;
                for(int j=3*i; j<=n; j+=2*i){
                    A[j] = false;
                }
            }
        }

        for(int i=0; i<=n; i++){
            if(A[i]) v.push_back(i);
        }

        for(int i=0; i<v.size(); i++){
            int x = v[i]*v[i];
            if(x<=n)
            cout<<x<<" ";
            else break;
        }cout<<endl;
    }

    ~Seive(){
        if(!A)delete[] A;   
    }
};
int main()
{
    cout<<"T-PRIMES!!!\n";
    Seive seive;
    return 0;
}