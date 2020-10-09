#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
#include <queue>
 
#define mx 101
 
using namespace std;
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n, e;
 
    while(cin >> n >> e && n && e){
        vector <int> G[mx];
        int indegree[n+1] = {0};
        queue <int> q;
        vector<int> sorted;


        int a, b;
 
        while(e--)
        {
            cin >> a >> b;
            G[a].push_back(b);
 
            indegree[b]++;
        }
 
        for(int i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                //cout << i << " ";
            }
        }
 
        while(!q.empty())
        {
            int u, v;
 
            u = q.front();
            q.pop();
            sorted.push_back(u);
            //cout << u << " ";
 
            for(int i = 0; i < G[u].size(); i++)
            {
                v = G[u][i];
                indegree[v]--;
 
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
 
        for(int i=0; i<sorted.size(); i++){
            cout<<sorted[i]<<" ";
        }cout<<"\n";
    }
    return 0;
}