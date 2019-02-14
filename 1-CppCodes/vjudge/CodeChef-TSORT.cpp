#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
//vector<int> *g;
//bool *isvisited;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    //vector<int> a;
    set<int> a;
    vector<int> s;
    //while( (cin>>n) && (n!=EOF) ){ 
    while(scanf("%d",&n)!=EOF){
        //a.push_back(n);
        a.insert(n);
    }
    

    //for(int i=0; i<a.size(); i++){  s.insert(a[i]); }

    set<int>::iterator it;
    for(it=a.begin(); it!=a.end(); it++){   s.push_back(*it); }
    sort(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){  cout<<s[i]<<"\n"; }
    //cout<<"\n";
  
  return 0;
}

