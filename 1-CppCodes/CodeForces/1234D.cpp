/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

vector<set<int> > charpos(26);
string s;
char c, ch;
int q, type, pos, l, r, mycount;
set<int>::iterator it;

void preprocess(){
    for(int i=0; i<s.size(); i++){
        ch = s[i];
        charpos[ch-'a'].insert(i);
    }
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

    cin>>s;
    preprocess();

    cin>>q;
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>pos>>c;
            // pos is in 1 based indexing. so pos--;
            pos--;

            ch = s[pos];
            s[pos] = c;

            charpos[ch-'a'].erase(pos);
            charpos[c-'a'].insert(pos);
        }else if(type == 2){
            cin>>l>>r;
            // l,r are given in 1 based indexing. so perform a decrement.
            l--; r--;
            mycount = 0;
            for(int i=0; i<26; i++){
                  it = charpos[i].lower_bound(l);
                if( (it!=charpos[i].end()) && ((*it)<=r) ){
                    mycount++;
                }
            }
            cout<<mycount<<"\n";

        }else{  }
    }    


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