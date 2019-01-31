#include <bits/stdc++.h>

using namespace std;

class B913{
private:
    vector<int> *G;
    bool *isLeaf;
    int n,x;
public:
    B913(){
        scanf("%d",&n);
        G = new vector<int>[n+1];
        isLeaf = new bool[n+1];
        for(int i=0; i<=n; i++){ isLeaf[i] = true; }
        for(int i=1; i<n; i++){
            scanf("%d",&x);
            G[x].push_back(i+1);
            isLeaf[x] = false;
        }
        bool b = true;
        for(int i=1; i<n; i++){
            int leafCount = 0;
            if(!isLeaf[i]){
                for (int j = 0; j < G[i].size(); j++)
                {
                    int u = G[i][j];
                    if (isLeaf[u])
                    {
                        leafCount++;
                    }
                }
                if(leafCount<3){b = false; break; }
            
            }
            

        }

        if(b){ printf("Yes\n"); }
        else{ printf("No\n"); }
        /*cout<<endl;
        for(int i=1; i<n; i++){
            cout<<i<<"->";
            for(int j=0; j<G[i].size();j++){
                cout<<G[i][j]<<" ";
            }cout<<endl;
        }*/
    }
    ~B913() {
        if(!G)delete[] G;
    }
};

int main()
{
    B913 b913;
    return 0;
}