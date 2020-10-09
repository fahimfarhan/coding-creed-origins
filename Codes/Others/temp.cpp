    //#include <bits/stdc++.h>
    #include<iostream>
    #include <queue>
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstring>
    #include <map>
    #define pii pair<int,int>
     
    using namespace std;
     
    int x1,x2, y1,y2;
    int dx[] = {-1,-2,-2,-1,1,2,2,1};
    int dy[] = {-2,-1,1,2,2,1,-1,-2};
     
    int bfs()
    {
        bool vis[9][9];
        int level[9][9];
        memset(vis,1,sizeof(vis));
        memset(level,0,sizeof(level));
        queue< pii >Q;
        Q.push(make_pair(x1,y1));
        vis[x1][y1] = 0;
        level[x1][y1] = 0;
        while(!Q.empty())
        {
            pii u;
            u = Q.front();
            Q.pop();
            int tx,ty;
            for(int i=0; i<8; i++)
            {
                tx = u.first + dx[i];
                ty = u.second + dy[i];
                if(tx>0 && ty>0 && tx<=8 && ty<=8 && vis[tx][ty])
                {
                    level[tx][ty] = level[u.first][u.second] + 1;
                    vis[tx][ty] = 0;
                    Q.push(make_pair(tx,ty));
                }
                if(tx == x2 && ty==y2)
                    return level[tx][ty];
            }
        }
    }
     
    int main()
    {
        x1=0; x2=0; y1=0; y2=0;
        map<char,int>mp;
        int i=1;
        for(char ch='a'; ch<='h'; ch++) mp[ch] = i++;
        char c1,c2;
        while(scanf("%c%d %c%d",&c1,&x1,&c2,&x2)!=EOF)
        {
            y1 = mp[c1] ; y2 = mp[c2];
            printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,x1,c2,x2,bfs());
        }
        return 0;
    }
     
