/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
#include <queue>
// #include <stack>
// #include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
int *indegree;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true){
        cin>>n>>m;
        if(n==0 && m==0){
            break;
        }
        g = new vector<int>[n+1];
        indegree = new int[n+1]; for(int i=0; i<=n; i++){   indegree[i] = 0; }
        int a, b;
        for(int i=0; i<m; i++){    
            cin>>a>>b;  
            g[a].push_back(b);
            indegree[b]++;    
        }

        queue<int> q;
        vector<int> output;

        for(int i=1; i<=n; i++){    if(indegree[i] == 0) q.push(i);     }

        while (!q.empty())
        {
            /* code */
            int u, v;
            u = q.front();
            q.pop();
            output.push_back(u);
            
            for(int i=0; i<g[u].size(); i++){
                v = g[u][i];
                if(indegree[v]>0){  
                    indegree[v]--;  
                    if(indegree[v] == 0){  q.push(v);  }    
                }            
            }
        }

        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<" ";
        }cout<<"\n";
        
        delete[] g;
        delete[] indegree;
    }


    return 0;
}

