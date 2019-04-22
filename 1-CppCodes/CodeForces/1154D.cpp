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

int n,a,b,amax;
bool *s;
void useBattery(const int &i){
    if(s[i]==1){    a=min(a+1, amax);   }
    b--;
}
void useAccumulator(){ a--; }
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

    cin>>n>>b>>a;
    amax = a;
    s = new bool[n+1];
    for(int i=0; i<n; i++){ cin>>s[i];  }

    int result = 0;
    for(int i=0; i<n; i++){
        if( (a==0) && (b==0) ){ break;    }
        else if(a==0){   useBattery(i);    }
        else if(b==0){  useAccumulator(); }
        else if((s[i]==1) && (a<amax)){ useBattery(i); }
        else{   useAccumulator(); }

        result++;
    }
    cout<<result<<"\n";
    
    delete[] s;
    return 0;
}
