#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

vector<int> g[101];
map<int, string> mp;
void dfs(int u, string str=""){
    int l, r;
    string sl, sr;
    if(g[u].size() == 0){
        // therefor a leaf node!!!
        mp[u] = str;
        return;
    }else{
        l = g[u][0];
        r = g[u][1];

        sl = str+"0";
        sr = str+"1";
        dfs(l,sl);
        dfs(r,sr);
    }
}

int root;
int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
    root = 0;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int n=6;
    
    priority_queue<int, vector<int> > max_heap;
    priority_queue<int, vector<int> , greater<int> > min_heap;
    char ch[n] = {'a', 'b','c','d','e','f'};
    int f[n] = {5,9,12,13,16,45};

    map<char, int> h;
    for(int i=0; i<n; i++){
        h[ch[i]] = f[i];
    }

    for(int i=0; i<n; i++){ min_heap.push(f[i]); }
    while(min_heap.size()!=1){
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();

        int c = a+b;
        g[c].push_back(a); // the small one
        g[c].push_back(b); // the big one

        min_heap.push(c);
    }

    root = min_heap.top();
    for(int j=0; j<100; j++){
        if(g[j].size()>0){
            cout<<j<<"|-->";
            for(int i=0; i<g[j].size(); i++){
                cout<<g[j][i]<<"-->";
            }cout<<"|/|\n";
        }
    }

    dfs(root,"");
    for(int i=0; i<n; i++){
        int query = h[ch[i]];
        string s = mp[query];
        cout<<ch[i]<<"--->"<<s<<"\n";
    }
	return 0;
}
