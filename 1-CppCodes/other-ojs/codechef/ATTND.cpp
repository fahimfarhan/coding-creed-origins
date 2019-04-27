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

    int T, N, m;
    string *fn, *ln;
    
    cin>>T;
    while(T--){
        cin>>N;
        fn = new string[N+1]; ln = new string[N+1];

        map<string, int> mp;

        for(int i=0; i<N; i++){
            cin>>fn[i]>>ln[i];
            mp[fn[i]]++;
        }

        for(int i=0; i<N; i++){
            m = mp[fn[i]];
            if(m==1){   cout<<fn[i]<<"\n";  }
            else{   cout<<fn[i]<<" "<<ln[i]<<"\n";  }
        }

        delete[] fn; delete[] ln;
    }

    
    return 0;
}
