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

    int c[5];
    for(int i=0; i<5; i++){ c[i]=0; }

    int n;
    cin>>n;

    int a;
    for(int i=0; i<n; i++){
        cin>>a; 
        c[a]++;
    }

    int ans=0;
    ans+=(c[4]+(c[2]>>1));
    if( (c[2]&1)==1){   c[2]=1; }else{ c[2] = 0; }
    if(c[1]<=c[3]){
        ans+=c[3]; 
        ans+=c[2];
    }else{
        ans+=c[3];
        c[1] = c[1]-c[3];
        if(c[2]==0){
            double temp = c[1];
            temp = ceil(temp/4);
            ans+=temp;
        }else{
            if(c[1]<=2){
                ans++;
            }else{
                ans++;
                c[1]-=2;
                double temp = c[1];
                temp = ceil(temp/4);
                ans+=temp;
            }
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}
