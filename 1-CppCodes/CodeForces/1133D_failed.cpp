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
    /* Soln soln */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, maximus = 0; ll *a, *b;
    int64_t c, s_a=0, s_b=0;
    double d, d_opt;
    map<double,int> mp;
    
    cin>>n;
    a = new ll[n+1];
    b = new ll[n+1];

    for(int i=0; i<n; i++){
        cin>>a[i];
        //s_a+=a[i];
    }
        for(int i=0; i<n; i++){
        cin>>b[i];
        //s_b+=b[i];
    }

    

    for(int i=0; i<n; i++){
        if(a[i]!=0){
            d = -1.0*(1.0*b[i]/a[i]);
            mp[d]++;
            if(mp[d]>maximus){  d_opt = d; maximus = mp[d]; } 
        }
        
    }

    //c = d_opt*s_a + s_b;
    //c = maximus;
    cout<<maximus<<"\n";



    delete[] a;
    delete[] b;
    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/