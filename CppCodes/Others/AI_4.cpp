#include <bits/stdc++.h>
using namespace std;
#define r 3
#define pii pair<int,int>
#define win_score 10
#define lose_score -10
char player = 'X', opponent = 'O';
struct Game{
    string board[r];
    Game(){
        for(int i = 0; i <r; i++){
            board[i] = "";
            for(int j = 0; j <r; j++) board[i] += '_';
        }
    }
    Game(string s1, string s2, string s3, string s4){
        board[0] = s1;
        board[1] = s2;
        board[2] = s3;
        board[3] = s4;
    }
    bool moves_left(){
        for(int i = 0; i <r; i++){
            for(int j = 0; j <r; j++){
                if(board[i][j] == '_') return true;
            }
        }
        return false;
    }
    void printBoard(){
        cout<<endl;
        for(int i = 0; i <r; i++) cout<<board[i]<<endl;
        cout<<endl;
    }
};

int calc(Game g, int depth){
    //row
    for(int i = 0; i <r; i++){
        bool same = true;
        for(int j = 1; j<r; j++){
            same = same & (g.board[i][j] == g.board[i][j-1]);
        }
        if(same){
            if(g.board[i][0] == player) return win_score;
            else if(g.board[i][0] == opponent) return lose_score;
        }
    }
    //column
    for(int i = 0; i <r; i++){
        bool same = true;
        for(int j = 1; j<r; j++){
            same &= (g.board[j][i]==g.board[j-1][i]);
        }
        if(same){
            if(g.board[0][i] == player) return win_score;
            else if(g.board[0][i] == opponent) return lose_score;
        }
    }
    //main_diagonal
    bool same = true;
    for(int i = 1; i <r; i++){
        same &= (g.board[i][i]==g.board[i-1][i-1]);
    }
    if(same){
        if(g.board[0][0] == player) return win_score;
        else if(g.board[0][0] == opponent) return lose_score;
    }
    //other diagonal
    same = true;
    for(int i = 1; i <r; i++){
        same &= (g.board[i][r-i-1]==g.board[i-1][r-i]);
    }
    if(same){
        if(g.board[0][r-1] == player) return win_score;
        else if(g.board[0][r-1] == opponent) return lose_score;
    }
    return 0;
}

bool isOver(Game g){
    //row
    for(int i = 0; i <r; i++){
        bool same = true;
        for(int j = 1; j<r; j++){
            same &= (g.board[i][j]==g.board[i][j-1]);
        }
        if(same){
            if(g.board[i][0] == player) return true;
            else if(g.board[i][0] == opponent) return true;
        }
    }
    //column
    for(int i = 0; i <r; i++){
        bool same = true;
        for(int j = 1; j<r; j++){
            same &= (g.board[j][i]==g.board[j-1][i]);
        }
        if(same){
            if(g.board[0][i] == player) return true;
            else if(g.board[0][i] == opponent) return true;
        }
    }
    //main_diagonal
    bool same = true;
    for(int i = 1; i <r; i++){
        same &= (g.board[i][i]==g.board[i-1][i-1]);
    }
    if(same){
        if(g.board[0][0] == player) return true;
        else if(g.board[0][0] == opponent) return true;
    }
    //other diagonal
    same = true;
    for(int i = 1; i <r; i++){
        same &= (g.board[i][r-i-1]==g.board[i-1][r-i]);
    }
    if(same){
        if(g.board[0][r-1] == player) return true;
        else if(g.board[0][r-1] == opponent) return true;
    }
    if(!g.moves_left()) return true;
    return false;
}

int adver_search(Game g, int depth, bool maximizer){
    //cout<<"sup";


    int val = calc(g, depth);
    if(val == 10|| val == -10) return val;
    if(!g.moves_left()) return 0;

    if(maximizer){
        int best_val = -1000;
        for(int i = 0; i <r; i++){
            for(int j = 0; j <r; j++){
                if(g.board[i][j] == '_'){
                    g.board[i][j] = player;
                    best_val = max(best_val, adver_search(g, depth+1, !maximizer));
                    g.board[i][j] = '_';
                }
            }
        }
        return best_val;
    }
    else{
        int best_val = 1000;
        for(int i = 0; i <r; i++){
            for(int j = 0; j <r; j++){
                if(g.board[i][j] == '_'){
                    g.board[i][j] = opponent;
                    best_val = min(best_val, adver_search(g, depth+1, !maximizer));
                    g.board[i][j] = '_';
                }
            }
        }
        return best_val;
    }
}
pii calcBestMove(Game g){
    pii mv = make_pair(-1, -1);
    int best_val = INT_MIN, cur;
    int scores[r][r];
    for(int i = 0; i <r; i++){
        for(int j = 0; j <r; j++){
            scores[i][j] = -1000;
        }
    }

    for(int i = 0; i <r;i++){
        for(int j = 0; j<r; j++){
            if(g.board[i][j] == '_'){
                cout<<"calculating "<<i<<", and "<<j<<endl;
                g.board[i][j] = player;
                cur = adver_search(g, 0, false);
                g.board[i][j] = '_';
                scores[i][j] = cur;
                if(cur>best_val){
                    best_val = cur;
                    mv.first = i;
                    mv.second = j;
                }
            }
        }
    }
    for(int i = 0; i <r; i++){
        for(int j = 0; j <r; j++){
            if(scores[i][j] != -1000) cout<<scores[i][j]<<" ";
            else cout<<" F ";
        }
        cout<<endl;
    }
    cout<<"\nbest move = "<<mv.first<<","<<mv.second<<endl;
    return mv;
}

int main(){
    /*
    Game g("XOOO", "X_OX", "X___", "____");
    calcBestMove(g);
    */
    Game g;
    int row, col;
    pii nxt;
    while(!isOver(g)){
        //cout<<"comes";
        nxt = calcBestMove(g);
        g.board[nxt.first][nxt.second] = player;
        g.printBoard();
        if(isOver(g)) break;
        cout<<"Your move??";
        cin>>row>>col;
        g.board[row][col] = opponent;
        g.printBoard();
        //if(isOver(g)) break;
    }
    return 0;
}
