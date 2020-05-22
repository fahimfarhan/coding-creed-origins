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

bool checkAllConditions(int g, int s, int b){
    // 1
    if( (g>0) && (s>0) && (b>0)){}
    else{   return false;    }
    // 2
    if( (g<s) && (g<b) ){}
    else{   return false;   }
    // 3 4 5
    return true;
}

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

    ll T, n, a, prev, half;
    cin>>T;
    while(T--){
        int j=0, medals[3] = {0,0,0};
        cin>>n;
        half = n>>1;
        cin>>prev;
        medals[j]++;
        for(int i=1; i<n; i++){
            cin>>a;
            if(i<=half){
                if(a<prev){
                    j++;
                    prev = a;
                }
                if(j<3){  medals[j]++;  }  
            }
        }
        cout<<medals[0]<<" "<<medals[1]<<" "<<medals[2]<<"\n";
        // if(checkAllConditions(medals[0], medals[1], medals[2])){
        //     cout<<medals[0]<<" "<<medals[1]<<" "<<medals[2]<<"\n";
        // }else{  cout<<"0 0 0\n";    }
        
    }


    return 0;
}

