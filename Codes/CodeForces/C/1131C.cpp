#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
ll *a;
vector<int> *g;
bool *isvisited;

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

    cin>>n;
    a = new ll[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    list<ll> mylist;
    bool toogle = true;
    for(int i=n-1; i>=0; i--){
        if(toogle){ mylist.push_front(a[i]);    }
        else{  mylist.push_back(a[i]);  }
        toogle = !toogle;
    }

    for (auto it = mylist.begin(); it != mylist.end(); ++it) 
     {cout << *it<<" ";}   
    cout<<"\n"; 
  return 0;
}


