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

ll T, N, G, M;
vector<pair<ll,ll> > *consulate; 

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

    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N>>G>>M;
        
        consulate = new vector<pair<ll,ll> >[N+10];
        ll guestStartingCons[G+10] = {0};
        char guestDirection[G+10]={0};
        for(int i=0; i<G; i++){
            cin>>guestStartingCons[i]>>guestDirection[i];
        }

        for(int i=0; i<G; i++){
            int curr = guestStartingCons[i];
            consulate[curr].push_back({i,0});
        }

        for(int i=0; i<G; i++){
            int dir=0;
            int currConsulate = guestStartingCons[i];
            int currGuest = i;

            if(guestDirection[i]=='C'){ dir = 1; }
            else{   dir = -1; }

            ll len=0;
            for(int j=1; j<=M; j++){
                currConsulate+=dir;
                if(currConsulate==(N+1) ){    currConsulate=1; }
                if(currConsulate==0){   currConsulate=N;    }

                len = consulate[currConsulate].size()-1;
                if(consulate[currConsulate][len].second < j ){
                    consulate[currConsulate].clear();
                    consulate[currConsulate].push_back({currGuest, j});
                }else if(consulate[currConsulate][len].second == j){
                    consulate[currConsulate].push_back({currGuest, j});
                }else{  }
            }
        }

        ll res[G+10] = {0};
        for(int i=1; i<=N; i++){
            for(int j=0; j<consulate[i].size(); j++){
                ll g = consulate[i][j].first;
                res[g]++;
            }
        }

        cout<<"Case #"<<t<<": ";
        for(int i=0; i<G; i++){ cout<<res[i]<<" ";  }
        cout<<"\n";

        delete[] consulate;
    }


    return 0;
}