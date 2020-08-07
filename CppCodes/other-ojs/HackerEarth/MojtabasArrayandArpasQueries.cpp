#include <bits/stdc++.h>

using namespace std;

#define ll long long int

const int maxn = 5e5+17, lg = 19;

int n,k,q, fen[maxn], r[maxn], sp[lg][maxn], ans[maxn];

vector<int> vec[maxn];

void upd(int p, int x){
    p = p+1;
    while(p<maxn){
        fen[p] = min(x, fen[p]);
        p=p+(p&(-p));
    }
}

int get(int p){
    int ret = maxn;
    p=p+1;
    while(p){
        ret = min(ret, fen[p]);
        p = p^(p&(-p));
    }
    return ret;
}

int main(){

    memset(fen, 63, sizeof fen);
    cin>>n>>k>>q;

    for(int i=0; i<n; i++){
        cin>>sp[0][i];
        sp[0][i]%=k;
    }

    for(int l=1; l<lg; l++){
        for(int i=0; i+(1<<l) <= n; i++){
            sp[l][i] = (ll)sp[l-1][i]*sp[l-1][i+(1<<l-1)]%k;
        }
    }

    for(int i=0; i<q; i++){
        int l;
        cin>>l>>r[i];
        r[i]--;
        vec[l-1].push_back(i);
    }

  	for(int i = n - 1; i >= 0; i--){
		int j = i, curz = 1; // catche some bug!
		for(int lev = lg - 1; lev >= 0; lev--)
			if(j + (1 << lev) < n && (ll) curz * sp[lev][j] % k){
				curz = (ll) curz * sp[lev][j] % k;
				j += 1 << lev;
			}
		if((ll) curz * sp[0][j] % k == 0)
			upd(j, j - i + 1);
		for(auto qi : vec[i])
			ans[qi] = get(r[qi]);
	}
	for(int i = 0; i < q; i++)
		cout << (ans[i] >= maxn ? -1 : ans[i]) << ' ';
	cout << '\n';
    return 0;
}