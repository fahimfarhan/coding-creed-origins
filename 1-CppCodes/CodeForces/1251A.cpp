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



// int n,m;s
vector<int> *g;
bool *isvisited;

bool b[26];
string s;
int pos, Count;

void start(){
    for(int i=0; i<26; i++){    b[i] = 0;   }
    cin>>s;
    for(int i=0; i<s.size(); i++){
        Count = 0;
        int j=i;
        pos = s[i]-'a';
        while (j + 1 < s.size() && s[j + 1] == s[i])
		{j++;   }
        Count = j-i;
        if( (Count&1) == 0){
            b[pos] = 1;
        }
        i=j;
    }
    char ch;
    for(int i=0; i<26; i++){
        if(b[i]){  ch = 'a'+i; cout<<ch<<"";    }
    }cout<<"\n";

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

    int t;
    cin>>t;
    while(t--){
        start();
    }

    return 0;
}

