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

    int n, x0,y0, x,y; double m;
    cin>>n>>x0>>y0;
    set<double> s;
    //map<double, int> mp;
    bool inditerminant=false;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        if( (x-x0) == 0){
            inditerminant=true;
        }else{
            m = 1.0*(y-y0)/(x-x0);
            s.insert(m); 
        }
    }
    int ans = s.size(); 
    if(inditerminant){  ans++; }
    cout<<ans<<"\n";
    return 0;
}
