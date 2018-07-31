#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

class Soln{
private:
    int n, x,y, count, x0,y0;
    vector< pair<int,int> > v;
    bool **board;
    char **chess;
public:
    void init(){
        count = 0;

        board = new bool*[n+1];
        for(int i=0; i<=n; i++){
            board[i] = new bool[n+1];
        }

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                board[i][j]=false;
            }
        }

        chess = new char*[n+1];
        for(int i=0; i<n; i++){
            chess[i] = new char[n+1];
        }

        for(int i=01; i<=n; i++)
            for(int j=01; j<=n; j++)
                chess[i][j] = 'N';
    }

    void D(){ if(y>1) y--; }
    void R(){ if(x<n)x++; }
    void LU(){ if(x>1 && y<n) x--; y++; }

    void U(){ y++; } 
    void L(){ x--; }
    void RD(){ x++; y--; }

    void Prince(){
        //cout<<"ok1\n";
        if(v.size()==(n*n-1)){
            count++;
            chess[x0][y0] = 'Y';
            /*for(int i=0; i<v.size(); i++){
                cout<<"("<<v[i].first<<","<<v[i].second<<") --> ";
            }cout<<"\n";*/
            return;
        }
        //cout<<"ok2\n";
        int x1,y1;
        // check right
        x1 = x+1; y1 = y;
        if(x1<=n){
            if(!board[x1][y1]){
                board[x1][y1] = true;
                R();
                pair<int,int> p; p.first = x1; p.second = y1;
                v.push_back(p);

                Prince();
                v.pop_back();
                L();
                board[x1][y1] = false;
            }
        }
        
        // check down
        x1 = x; y1 = y-1;
        if(y1>0){
            if(!board[x1][y1]){
                board[x1][y1] = true;
                D();
                pair<int,int> p; p.first = x1; p.second = y1;
                v.push_back(p);

                Prince();
                v.pop_back();
                U();
                board[x1][y1] = false;
            }
        }
        
        // check diagonal
        x1 = x-1; y1 = y+1;
        if(x1>0 && y1<=n){
            if(!board[x1][y1]){
                board[x1][y1] = true;
                LU();
                pair<int,int> p; p.first = x1; p.second = y1;
                v.push_back(p);

                Prince();
                v.pop_back();
                RD();
                board[x1][y1] = false;
            }
        }
        
    }

    Soln(){
        
        /*printf("Enter board size: ");
        si(n);
        printf("Enter initial x,y(1 based indexing): ");
        si(x); si(y);
        */
        for(int k=2; k<=8; k++){
            n = k;
            init();
            board[x][y]=true;
                    
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    x=i; y=j;
                    x0 = i; y0 = j;
                    
                    Prince();
                    printf("Case# n=%d\n", count);
                    printer();
                    printf("\n----------\n");
                }
            }
            destroy();
            

        }
        

    }

    void printer(){
        for(int i=01; i<=n; i++)
        {
            for(int j=01; j<=n; j++){
                cout<<chess[i][j];
            }cout<<"\n";
        }
    }

    void destroy(){
        for(int i=0; i<=n; i++){
            if(!board[i])delete[] board[i];
        }
        if(!board)delete[] board;

        for(int i=0; i<n; i++){
            if(!chess[i])delete[] chess[i];
        }
        if(!chess)delete[] chess;
    }

    ~Soln(){
        //destroy();      
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}

/*                                           When Panda is Life !
 
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
  */
