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

    int T, len;
    string s1, s2;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>s1;
        s2 = "";
        len = s1.size();
        for(int i=0; i<len; i++){
            if(s1[i]=='4'){
                s1[i] = '3';
                s2 = s2+'1';
            }else{
                s2 = s2 + '0';
            }
        }
        cout<<"Case #"<<t<<": "<<s1<<" "<<stoll(s2)<<"\n";

    }
    return 0;
}
