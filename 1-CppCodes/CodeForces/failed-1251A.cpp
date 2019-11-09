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

    ll T;
    string s;
    char ch;
    cin>>T;

    while(T--){
        cin>>s;
        set<char> st;
        vector<char> v;
        if(s.size() == 1){  st.insert(s[0]);    }
        else if(s.size() == 2){
            if(s[0]!=s[1]){ st.insert(s[0]);    st.insert(s[1]);    }
        }else{
            if(s[0]!=s[1]){ st.insert(s[0]);    }
            for(int i=1; i<s.size()-1; i++){
                ch = s[i];
                if( (ch != s[i+1]) && (ch!=s[i-1])){
                    st.insert(ch);
                }
            }
            if(s[s.size()-1] != s[s.size()-2]){ st.insert(s[s.size()-1]);   }
        }
        for(auto x:st){ 
            //v.push_back(x);
            cout<<x<<"";    
        }
        //sort(v.begin(), v.end());
        cout<<"\n";

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
