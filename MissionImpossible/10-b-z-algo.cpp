#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;





int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    string s1, s2, s;
    s1 = "codeforcescode";
    s2 = "code";
    s = s2 + "$" + s1;
    int *z;
    int len = s.size();
    z = new int[len+1];
    z[0] = 0;

    for(int i=1; i<len; i++){
        int L,R, count;
        L = 0; R = i;
        
        while(s[L] == s[R]){
            L++;
            R++;
            if(R>s.size()){ break; }
        }
        z[i] = L;
    }

    for(int i=0; i<s.size(); i++){
        cout<<z[i] <<" ";
    }
    cout<<"\n"<<s2.size()<<"\n";

    int toSubstract = s2.size() + 1;
    len = s2.size();
    for(int i=0; i<s.size(); i++){
        if(z[i] == len){
            cout<<i - toSubstract<<"\n";
        }
    }
    delete[] z;
  return 0;
}
