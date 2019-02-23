#include <bits/stdc++.h>
using namespace std;

class A115{
private:
    int n; 
    vector<int> *G;
    list<int> q;
    bool *isVisited;
    int depth, max_depth;
public:
void DFS(){
    for(int i=1; i<=n;i++){
        if(!isVisited[i]){
            DFS_visit(i);
        }
    }
}
void DFS_visit(int i){
    isVisited[i]=true;
    depth++;
    if(depth>max_depth){    max_depth=depth;    }

    for(int u=0; u<G[i].size();u++){
        if(!isVisited[u]){
            DFS_visit(u);
        }
    }
    depth--;
}
    ~A115(){ if(!G)delete[] G; }
    A115(){
        depth=0;
        max_depth=0;
        scanf("%d",&n);
        G = new vector<int>[n+1];
        isVisited = new bool[n+1];
        for(int i=0; i<=n; i++){ isVisited[i]=false;}
        int temp;
        for(int i=1; i<=n; i++){
            scanf("%d",&temp);
            G[i].push_back(temp);
        }
        DFS();
        printf("%d\n",max_depth+1);
    }
    
};
int main()
{
    A115 a115;
    return 0;
}

/*void BFS(){
        while(!q.empty()){
            int u = q.front();
            q.pop_front();
            for(int i=0; i<G[u].size(); i++){
                int v = G[u][i];
                if(!isVisited[v]){
                    isVisited[v]=true;
                    q.push_back(v);
                }
            }
        }
    }*/
