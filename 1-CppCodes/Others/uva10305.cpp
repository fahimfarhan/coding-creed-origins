#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
#include <queue>
 
#define mx 111
 
using namespace std;
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
 
   
 
    int n, e;
 
    while(cin >> n >> e && n && e)
    {
        vector <int> G[mx];
        vector <int> indegree;
        queue <int> q, sorted;

        indegree.clear();
        indegree.assign(n+1, 0);
        int a, b, i, u;
 
        while(e--)
        {
            cin >> a >> b;
            G[a].push_back(b);
 
            indegree[b]++;
        }
 
        for(i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                //cout << i << " ";
            }
        }
 
        while(!q.empty())
        {
            int v;
 
            u = q.front();
            q.pop();
            sorted.push(u);
            //cout << u << " ";
 
            for(i = 0; i < G[u].size(); i++)
            {
                v = G[u][i];
                indegree[v]--;
 
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
 
        cout << sorted.front();
        sorted.pop();
        while(!sorted.empty())
        {
 
            cout <<  " " << sorted.front();
            sorted.pop();
        }
    }
    return 0;
}

