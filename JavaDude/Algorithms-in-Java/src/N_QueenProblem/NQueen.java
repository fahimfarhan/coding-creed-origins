package N_QueenProblem;

/**
 * Created by Fahim on 12/8/2016.
 */
public class NQueen {

    int N;
    int board[][];
    NQueen(int n){
        this.N = n;
        board = new int[N][N];
    }
    //void TakeInputs(){}
    void Printer(){

        System.out.println("N="+N+" :");
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                System.out.print(" "+board[i][j]);
            System.out.println();
        }
    }

    boolean IsSafe(int row, int col){
        /*check this row*/
        for(int i=0; i<col; i++){ if(board[row][i]==1)  return false; }

        /*check this col
        for(int i=0; i<row; i++){ if(board[i][col]==1)  return false; }
        */
        /*upper diagonal left side*/
        for(int i=row, j=col; i>=0 && j>=0; i--, j-- )
        {   if(board[i][j]==1) return false;   }

        /*upper diagonal right side
        for(int i=row, j=col; i>=0 && j<N; i--, j++ )
        {   if(board[i][j]==1) return false;   }

        //lower diagonal right side
        for(int i=row, j=col; i<N && j<N; i++, j++ )
        {   if(board[i][j]==1) return false;   }*/

        /*lower diagonal left side*/
        for(int i=row, j=col; i<N && j>=0; i++, j-- )
        {   if(board[i][j]==1) return false;   }

        return true;
    }

    boolean Solver(int col){

        //base case: if all queens are placed, return true
        if(col >= N) return true;
        for(int i=0; i<N; i++){

            if(IsSafe(i, col)==true){

                board[i][col] = 1;
                if(Solver(col+1) == true)
                    return true;
            }
            board[i][col] = 0;
        }
        return false;
    }

    void SolveNQ(){

        if(Solver(0) == true)
            Printer();
        else    System.out.println("N="+N+" :\n The Soln doesn't exist! :'(");
    }


}
