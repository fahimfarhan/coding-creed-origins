#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int n; char c;
    Node(){ n=0; c='\0'; }
};

class Soln{
private:
    queue<int> qa,qb;
    queue<char> ca,cb;
    int n, m, ans;
    char prev;
    vector<Node> *G;
    bool *isVisited;
    int *Alevel, *Blevel;
    int al, bl;
public:
    void Init(){
        ans = 0; // if ans = 1 -> A, ans = 0 -> B
        prev = '\0';
        al=0; bl=0;
        for(int i=0; i<=n; i++){
            isVisited[i]=false;
            Alevel[i]=0;
            Blevel[i]=0;
        }
    }

    void InitA(){
        while(!qa.empty()){qa.pop();}
        while(!ca.empty()){ca.pop();}
        al=0; 
        for(int i=0; i<=n; i++){
            isVisited[i]=false;
            Alevel[i]=0;
            //Blevel[i]=0;
        }
    }
    void InitB(){
        while(!qb.empty()){qb.pop();}
        while(!cb.empty()){cb.pop();}
         bl=0;
        for(int i=0; i<=n; i++){
            isVisited[i]=false;
            
            Blevel[i]=0;
        }
    }
    /*void DFS_visit(int u){}
    void DFS(){
        for(int i=1; i<=n; i++){
            Init();
            DFS_visit(i);
            //if()
        }
    }*/

    Soln(){
        scanf("%d %d",&n,&m);
        G = new vector<Node>[n+1];
        isVisited = new bool[n+1];
        Alevel = new int[n+1];
        Blevel = new int[n+1];

        for(int i=0; i<m; i++){
            Node node;
            int x;
            scanf("%d %d %c",&x,&node.n,&node.c);
            G[x].push_back(node); 
        }
        
        BFS();

    }

    void BFS(){
        for(int i=1; i<=n; i++){
            InitA();
            BFS_A(i);
            for(int j=1; j<=n;j++){
                InitB();
                BFS_B(j);
                if(al>bl){
                    cout<<"A";
                }else{ cout<<"B";}
            }
            cout<<"\n";
        }
    }

    void BFS_A(int x){
        qa.push(x);
        ca.push('\0');
        while(!qa.empty()){
            int v = qa.front();
            char ch_prev = ca.front();
            al = Alevel[v];
            qa.pop();
            ca.pop();
            for(int i=0; i<G[v].size(); i++){
                int u=G[v][i].n;
                char ch_curr = G[v][i].c;
                if(ch_curr>ch_prev){
                    qa.push(u);
                    ca.push(ch_curr);
                    Alevel[u]=al+1;
                }
                
            }
        }
    }

    
    void BFS_B(int x){
        qb.push(x);
        cb.push('\0');
        while(!qb.empty()){
            int v = qb.front();
            char ch_prev = cb.front();
            bl = Blevel[v];
            qb.pop();
            cb.pop();
            for(int i=0; i<G[v].size(); i++){
                int u=G[v][i].n;
                char ch_curr = G[v][i].c;
                if(ch_curr>ch_prev){
                    qb.push(u);
                    cb.push(ch_curr);
                    Blevel[u]=bl+1;
                }
                
            }
        }
    }

    ~Soln(){ if(!G)delete[] G;
            if(!isVisited)delete[] isVisited;
            if(!Alevel)delete[] Alevel;
            if(!Blevel)delete[] Blevel;
     }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}
