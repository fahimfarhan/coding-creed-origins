#include <bits/stdc++.h>
using namespace std;

class Soln{
private:
    int n,m,u,v, max;
    vector<int> *G;
    string s;//char *c;
    map<char, int> mp;
    bool *isVisited;//, dirf,dirb;
    vector<int> path;
public:
    Soln(){
        //cout<<"1\n";
        max = 0;
        scanf("%d %d",&n,&m);
        //cout<<"2\n";
        G = new vector<int>[n+1];
        isVisited = new bool[n+1];
        cin>>s;
        //cout<<"3\n";
        for(int i=1; i<=n; i++){
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            //cout<<i<<"\n";
        }
        //cout<<"5\n";
        DFS();
        printf("%d\n",max);


    }
    void mapInit(){
        for(int i=0; i<26; i++){
            mp['a'+i]=0;
        }
    }

    void algo(){
        /*for(int i=0; i<path.size(); i++){
            cout<<path[i]<<"->";
        }       
        cout<<endl;*/


        int temp = 0;
         mapInit();
        for(int i=0; i<path.size(); i++){
            int j=path[i];
            char c = s[j-1];
            mp[c]++;
            //cout<<"c="<<c<<" mp[c]="<<mp[c]<<endl;
        }
        for(int i=0; i<26; i++){
            if(mp['a'+i]>temp)temp=mp['a'+i];
            
        }

        if(temp>max)max=temp;

    }

    void DFS(){
        for(int i=1; i<=n; i++){
            if(!isVisited[i])
                DFS_visit(i);
        }
    }

    void DFS_visit(int u){
        isVisited[u]=true;
        path.push_back(u);
        int i=0;
        for(i=0; i<G[u].size(); i++){
            int v = G[u][i];
            if(!isVisited[v])
                DFS_visit(v);
        }
        if(i==0){ //this means node u is a leaf! therefore, we've reached end of a path!
            //so, check the path, find max and store it in a variable!
            algo();
        }
        path.pop_back();
    }

    ~Soln(){
        if(!G)delete[] G;
        //if(!c)delete[] c;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}