/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
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

    int T, b,p,f,h,c, maximus;
    cin>>T;
    while(T--){

        cin>>b>>p>>f;
        cin>>h>>c;

        b = b>>1;
        maximus = 0;
        if(c>h){
            if(f>b){    maximus+=b*c; }
            else{
                maximus+=f*c;
                b-=f;
                if(p>b){    maximus+=b*h; }
                else{
                   maximus+=p*h; 
                }
            }
        }else{
            if(p>b){    maximus+=b*h; }
                else{
                   maximus+=p*h;
                   b-=p;
                   if(f>b){ maximus+=b*c;   }
                   else{
                       maximus+=f*c;
                   } 
                }
        }
        cout<<maximus<<"\n";
    }


    return 0;
}