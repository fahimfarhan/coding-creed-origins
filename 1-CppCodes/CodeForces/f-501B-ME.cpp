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
string *nodes;
vector< pair<string, string> > edges, output;
int n;
map<string, int> mp;

string dfs_visit(int u){
    string ret="";
    isvisited[u]=true;
    if(g[u].size() == 0){    return nodes[u];    }
    
    int v=0;
    
    for(int i=0; i<g[u].size(); i++){
        v = g[u][i];
        if(!isvisited[v]){    ret = dfs_visit(v);     }
    }
}

void dfs(){
    string s1,s2;
    for(int i=0; i<n; i++){
        if(!isvisited[i]){
            s1 = nodes[i];
            s2 = dfs_visit(i);
            output.push_back({s1,s2});
        }
    }
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

    cin>>n;
    string s1, s2;
    for(int i=0; i<n; i++){
        cin>>s1>>s2;
        edges.push_back({s1,s2});
    }

    {
        set<string> st;
        for(int i=0; i<n; i++){ st.insert(edges[i].first);st.insert(edges[i].second); }
        n = st.size();
        g = new vector<int>[n+1];
        nodes = new string[n+1];
        isvisited = new bool[n+1];
        set<string>::iterator it;
        int i1=0;
        for(it = st.begin(); it!=st.end(); it++)
        {   nodes[i1]=(*it); isvisited[i1]=false; i1++;     }
        
        for(int i=0; i<n; i++)
        {    mp[nodes[i]] = i;   }
        int u,v;
        for(int i=0; i<edges.size(); i++){
            u = mp[edges[i].first]; v = mp[edges[i].second];
            g[u].push_back(v);
        }
    }

    dfs();
    n = output.size();
    cout<<n<<"\n";

    for(int i=0; i<n; i++){
        cout<<output[i].first<<" "<<output.size()<<"\n";
    }

    delete[] isvisited;
    delete[] g;
    delete[] nodes;
    return 0;
}
