#include <bits/stdc++.h>

using namespace std;

#define EMPTY 0
#define UP 1
#define LEFT 2
#define DIAG 3
#define BOTH 4
#define BASE 5

string row, column;
int r,c;
int **dp, **num;

void LCS(int a, int b){
    if(dp[a][b]!=EMPTY){ return;  }
    if(row[a]==column[b]){  
        dp[a][b] = DIAG;    
        LCS( (a-1), (b-1) );
        num[a][b] = 1 + num[a-1][b-1];    
    }
    else{
        LCS(a,(b-1));
        LCS((a-1),b);
        if(num[a][b-1]>num[a-1][b]){
            dp[a][b] = LEFT;
            num[a][b] = num[a][b-1];
        }else if(num[a][b-1]<num[a-1][b]){
            dp[a][b] = UP;
            num[a][b] = num[a-1][b];
        }else{
            dp[a][b] = BOTH;
            num[a][b] = num[a-1][b];
        }
    }
}

string lcs(int i, int j){
    string ret = "";
    if(i==0 || j==0){   return ret; }
    if(dp[i][j]==DIAG){
        ret = lcs((i-1), (j-1))+row[i];
    }else if(dp[i][j]==UP){
        ret = lcs((i-1),j);
    }else{
        ret = lcs(i,(j-1));
    }
    return ret;
}

int main()
{

    row = "abcade";
    row = " "+row;
    column = "acbadf";
    column = " "+column;

    r = row.size();
    c = column.size();

    dp = new int*[r+1];
    num = new int*[r+1];
    for(int i=0; i<=r; i++){    dp[i] = new int[c+1]; num[i] = new int[c+1];   }

    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){

            num[i][j] = 0;
            if(i==0 || j==0){   dp[i][j] = BASE;   }
            else{   dp[i][j] = EMPTY;   }
        
        }
    }

    LCS((row.size()-1), (column.size()-1));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int temp = dp[i][j];
            char ch;
            switch (temp)
            {
            case UP:/* constant-expression */
                /* code */
                ch = 'u';
                break;
            case LEFT:
            ch = 'l';
            break;
            case DIAG:
            ch = 'd';
            break;
            case BOTH:
            ch = 'b';

            default:
                ch = '-';
                break;
            }
            cout<<ch<<" ";
        }cout<<"\n";
    }
    cout<<"\n------------------------\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<num[i][j]<<" ";
        }cout<<"\n";
    }

    string s = lcs((row.size()-1), (column.size()-1));
    cout<<"\n------------------------\n\n"<<s<<"\n";

    for(int i=0; i<=r; i++){    delete[] dp[i]; delete[] num[i];   }
    delete[] dp;
    delete[] num;

    return 0;
}