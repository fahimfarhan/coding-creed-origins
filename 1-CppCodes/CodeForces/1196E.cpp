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

    ll q, b,w, minimus, maximus;
    pair<ll,ll> start, start1, start2;
    cin>>q;
    while(q--){
        cin>>b>>w;
        minimus = min(b,w);
        maximus = max(b,w);

        if(maximus > (3*minimus+1) ){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            if(b == minimus){
                start = {3,2};
                start1 = {2,1};
                start2 = {4,1};
            }else{
                start = {2,2};
                start1 = {1,1};
                start2 = {3,1};
            }

            cout<<start.first<<" "<<(start.second-1)<<"\n";
            maximus--;
            int i=0;
            pair<ll,ll> curr = start;
            while(maximus>0){
                //curr.first = start.first; 
                curr.second += i;
                i+=2;
                cout<<curr.first<<" "<<curr.second<<"\n";
                minimus--;
                cout<<(curr.first-1)<<" "<<curr.second<<"\n";
                maximus--;
                if(maximus<=0){ break; }
                cout<<(curr.first+1)<<" "<<curr.second<<"\n";
                maximus--;
                if(maximus<=0){ break; }
                cout<<(curr.first)<<" "<<(curr.second+1)<<"\n";
                maximus--;
                if(maximus<=0){ break; }
                
            }

            i=0;
            while(minimus>0){
                cout<<(start1.first+i)<<" "<<start1.second<<"\n";
                i+=2;
                minimus--;
            }
        }

    }


    return 0;
}