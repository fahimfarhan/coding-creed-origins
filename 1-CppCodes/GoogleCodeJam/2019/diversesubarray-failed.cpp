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

    int T,N,S;
    int *a;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N>>S;
        //a = new int[N+1];
        int maximus = N;
        //for(int i=0; i<N; i++){ cin>>a[i];  }
        int A;
        map<int,int> mp;
        for(int i=0; i<N; i++){
            cin>>A; mp[A]++;
        }

        for(std::map<int,int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
        {
            int k =  iter->first;
            if(mp[k]>S){    maximus=maximus-mp[k]; mp[k] = 0;  }
            //ignore value
            //Value v = iter->second;
        }
        


        cout<<"Case #"<<t<<": "<<(maximus)<<"\n";
        if(!a)delete[] a;
    }
    
    return 0;
}
