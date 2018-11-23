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

	int n;
    int *a;
    cin>>n;
    priority_queue<int> pq;
    a = new int[n];
    int prevCount = 0;
    int currCount = 0;
    int prevPos = 0;
    int currPos = 0;
    cin>>a[0];
    for(int i=01; i<n; i++){
        cin>>a[i];
        if(a[i] - a[i-1]==1){ currCount++; currPos = i;  }
        else{
            if(currCount>prevCount){    prevCount = currCount-1; prevPos = currPos; pq.push(-currCount);    }
        }
    }

    if(currCount>prevCount){    prevCount = currCount; prevPos = currPos;     }

    if(prevPos != n-1){ currCount--; }
    pq.push(-currCount);
    int ans = pq.top();
    ans  = -ans;
    cout<<ans<<"\n";


    if(!a)delete[] a;
	return 0;
}
