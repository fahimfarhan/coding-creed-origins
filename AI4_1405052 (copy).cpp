#include<bits/stdc++.h>

using namespace std;

#define SIZE 3
#define POS_INF 1000
#define MIN_INF -1000

#define WIN 1
#define LOSE -1
#define DRAW 0
char player = 'X', computer = 'O';
class Game{
public:
    string s[SIZE];
    Game(){
        for(int i=0; i<SIZE; i++){
            s[i] = "";
        }

        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                s[i]=s[i]+"_";
            }
        }

        
    }

    void printer(){
        cout<<"\n------------\n";
        for(int i=0; i<SIZE; i++){
            cout<<s[i]<<"\n";
        }
        cout<<"\n------------\n";
    }

    bool movesAreLeft(){
            for(int i=0; i<SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    if(s[i][j]=='_'){
                        return true;
                    }
                }
            }
            return false;
        }

    ~Game(){}

    int gameOver(){
        bool same;
        // row check
        same = true;
        for(int i=0; i<SIZE; i++){
            for(int j=1; j<SIZE; j++){
                same = same & (s[i][j]==s[i][j-1]);
            }
            if(same){
                if(s[i][0]==computer){  return WIN; }
                else if(s[i][0]==player){ return LOSE;    }
            }
        }

        //col
        same = true;
        for(int i=0; i<SIZE; i++){
            for(int j=1; j<SIZE; j++){
                same = same & (s[j][j]==s[j-1][i]);
            }
            if(same){
                if(s[0][i]==computer){  return WIN; }
                else if(s[0][i]==player){ return LOSE;    }
            }
        }

        // Primary diagonal
        same = true;
        for(int i=1; i<SIZE; i++){
            same = same & (s[i][i] == s[i-1][i-1]);

        }

        if(same){
            if(s[0][0]==computer){  return WIN; }
            else if(s[0][0]==player){ return LOSE;    }
        }
        // auxiliary diagonal
        same = true;
        for(int i=1; i<SIZE; i++){
            same = same & (s[i][SIZE-i-1]==s[i-1][SIZE-i]);
        }

        if(same){
            if(s[0][SIZE-1]==computer){  return WIN; }
            else if(s[0][SIZE-1]==player){ return LOSE;    }
        }

        return DRAW;
    }
};



int minimax(Game g, int x, int y, int depth, int alpha, int beta, bool maximizingPlayer ){
    if(maximizingPlayer){   g.s[x][y] = computer;   }
    else{   g.s[x][y] = player;     }
    // BASE
    if(depth == 0){
        return DRAW;
    }
    int score = g.gameOver();
    if(score!=DRAW){  return score; }
    // recursion

    if(maximizingPlayer){
        int maxEval = MIN_INF;
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(g.s[i][j]=='_'){
                    int d = depth - 1;
                    int eval = minimax(g, i,j, d, alpha, beta, false);
                    maxEval = max(maxEval, eval);
                    alpha = max(alpha, eval);
                    if(beta <= alpha){
                        // break;
                        return maxEval;
                    }
                }
            }
        }
    }
    else{
        int minEval = POS_INF;
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(g.s[i][j]=='_'){
                    int d = depth - 1;
                    int eval = minimax(g, i,j, d, alpha, beta,true);
                    minEval = min(minEval, eval);
                    beta = min(beta, eval);
                    if(beta <= alpha){
                        // break
                        return minEval;
                    }
                }
            }
        }
    }


    return 0;
}

int main(int argc, char const *argv[])
{
    Game g;
    int depth = 16;
    g.printer();
    while(depth){
        
        cout<<"Computer's move!\n";
        int best_val = MIN_INF;
        int x,y;
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(g.s[i][j]=='_'){
                    int val = minimax(g,i,j,depth, MIN_INF, POS_INF, true);
                    if(val > best_val){
                        best_val = val;
                        x = i; y = j;
                    }
                }
                
            }
        }
        cout<<"x,y : "<<x<<" "<<y<<"\n";
        cout<<"depth : "<<depth<<"\n";
        g.s[x][y] = computer;
        g.printer();
        depth--;
        cout<<"Player's move! Plz enter:    ";
        int a,b;
        cin>>a>>b;
        g.s[a][b] = player;
        cout<<"depth : "<<depth<<"\n";
        g.printer();
        depth--;

        if(g.gameOver()!=0){    break;  }
        
    }
    cout<<"\n\n---------------------\n\n";
    int result = g.gameOver();
    if(result == WIN){
        cout<<"Computer Wins!\n";
        
    }else if(result == LOSE){
        cout<<"Player wins!\n";
        
    }else{
        cout<<"Draw!\n";
    }
    g.printer();
    return 0;
}