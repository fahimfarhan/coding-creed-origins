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


int n, k, id, idToBeRemoved;
queue<int> q;
set<int> mp;

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

    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>id;
        if(!mp.count(id)){
            if(q.size() == k){
                idToBeRemoved = q.front();
                q.pop();
                mp.erase(idToBeRemoved);
            }
            q.push(id);
            mp.insert(id);
        }
    }


    int m = q.size();
    cout<<m<<"\n";

    stack<int> res;
    while(!q.empty()){
        id = q.front(); q.pop(); res.push(id);
    }

    while(!res.empty()){
        cout<<res.top()<<" "; 
        res.pop();
    }cout<<"\n";


    return 0;
}

/**
Dread it, run from it, destiny arrives all the same !
I find your lack of faith in the CodeForces disturbing! >_<
Love you 3000 !
Keep It Simple Stupid (KISS)!
Good Hunting 47!
*/
/**
AC I - Redemption AC II - Revenge AC: Brotherhood - Justice AC: Revelation - Answers 
AC III - Freedom AC IV - Glory AC Rogue - Betrayal AC Unity - Love AC Syndicate - Family 
AC Origins - Beginnings 
*/