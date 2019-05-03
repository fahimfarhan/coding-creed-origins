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

    int n;
    string s;
    int key[26];
    for(int i=0; i<26; i++){    key[i]=0; }
    cin>>n;
    cin>>s;



    n = (n<<1)-2;

    int diff = 'A'-'a';

    int ans = 0;
    int ch;
    for(int i=1; i<n; i+=2){
        if(s[i]-s[i-1]==diff){  continue;  }
        else{
            ch = s[i]-diff-'a';
            if(key[ch]>0){
                key[ch]--;
                key[s[i-1]-'a']++;
            }else{
                // key[ch]++;
                key[s[i-1]-'a']++;
                ans++;
            }
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}
