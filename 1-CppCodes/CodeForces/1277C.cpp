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

    ll T, kount;
    string s;
    cin>>T;
    while(T--){
        kount = 0;
        cin>>s;
        for(int i=2; i<s.size(); i++){
            if((s[i-2]=='o') && (s[i-1]=='n')){
                // case 1
                if(s[i]=='e'){
                    kount++;
                    //if(s[i+1]=='e'){
                        // remove n
                        s[i-1] = 'o';
                    //}else{ // on o, n, t, w

                    //}
                }
            }else if((s[i-2]=='t') && (s[i-1]=='w')){
                // case 2
                if(s[i] == 'o'){
                    kount++;
                    s[i-1] = 't';
                }
            }else{

            }
        }

        cout<<kount<<"\n";

    }


    return 0;
}

