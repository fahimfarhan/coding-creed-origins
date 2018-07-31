#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n,m,l,r,t, *a;
    vector<int> divisors[300005];
public:
    void Divisors(){
        for(int i=1; i<=300005; i++){
            for(int j=i; j<=n; j=j+i){
                divisors[j].push_back(i);
            }
        }
    }

    void sum(){
        int Sum = 0;
        for(int i=l; i<=r; i++){
            Sum+=a[i];
        }
        cout<<Sum<<endl;
    }

    void replace(){
        for(int i=l; i<=r; i++){
            int temp = a[i];
            int temp2 = divisors[temp].size();
            a[i] = temp2;
        }
    }
    Soln(){

        Divisors();
        cin>>n>>m;
        a = new int[n+1];
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }

        for(int i=0; i<m; i++){
            cin>>t>>l>>r;
            if(t==1){ replace(); }
            else{ sum(); }
        }

    }
    ~Soln(){if(!a)delete[] a; }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}