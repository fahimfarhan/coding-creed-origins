#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int n, score, maximus, *num;
    string name, ans, *a;
    map<string, int> cf,f;
    maximus = INT_MIN;
    cin>>n;
    a = new string[n];
    num = new  int[n];
    for(int i=0; i<n; i++){
        cin>>name>>score;
        a[i] = name;
        num[i] = score;
        cf[name]+=score;
        // f[name] = score;

        // if(cf[name]>maximus){   maximus = cf[name]; }
    }

    for(int i=0; i<n; i++){
        maximus = max(maximus, cf[a[i]]);
    }
    int i=0;
    for(i=0; i<n; i++){
        f[a[i]] += num[i]; 
        if( (f[a[i]]>=maximus)  && (cf[a[i]]>=maximus) ){    break; } 
    }
    cout<<a[i]<<"\n";

delete[] a;
delete[] num;
	return 0;
}
