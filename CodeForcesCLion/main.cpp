#include <bits/stdc++.h>
using namespace std;

class Pair{
public:
    int index, sum;
    Pair(){ index = 0; sum = 0;}
};

class C437
{
private:
    int m,n,x,y,ans;
    vector<int> *G;
    int *v;
    Pair *e;
public:
    C437();
    ~C437();
    void CalculateEnergy();
    void GraphPrinter();
    void myRemove(int pos);

};
void C437::CalculateEnergy(){
    for(int i=1; i<=n; i++){
        e[i].sum = 0;
        for(int j=0; j<G[i].size();j++){
            e[i].sum+=G[i][j];
        }
    }
}
void C437::GraphPrinter(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<G[i].size(); j++){
            cout<<G[i][j]<<" ";
        }cout<<endl;
    }
}

bool compare(const Pair&n, const Pair&m)
{
    return n.sum < m.sum;
}

C437::~C437(){
    if(!G)delete[] G;
    if(!v)delete[] v;
    if(!e)delete[] e;
}
C437::C437(){
    ans = 0;
    cin>>n>>m;
    v = new int[n+10];
    G = new vector<int>[n+10];
    e = new Pair[n+10];
    for(int i=1; i<=n; i++){
        e[i].index = i;
    }

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    for(int i=1; i<=m; i++){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        CalculateEnergy();
        sort(e,e+n+1,compare);
        int pos;
        for(int pos=1; pos<=n; pos++){
            if(e[pos].sum != 0){ break;}
        }

        ans+=e[pos].sum;
        myRemove(e[pos].index);

    }

    cout<<ans;

}

void C437::myRemove(int pos){
    int removeThisNum = v[pos];
    for(int i=1; i<=n; i++){
        for(int j=0; j<G[i].size(); j++){
            if(G[i][j] == removeThisNum){
                G[i].erase(G[i].begin()+j);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    C437 c437;
    return 0;
}