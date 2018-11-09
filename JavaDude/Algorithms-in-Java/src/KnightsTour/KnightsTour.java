package KnightsTour;

/**
 * Created by Fahim on 12/8/2016.
 */
public class KnightsTour {
    int N=8;
    int [][]sol;
    int []xmove;
    int []ymove;
    KnightsTour(){
        sol = new int[8][8];
        xmove = new int[]{2,1,-1,-2,-2,-1,1,2};
        ymove = new int[]{1,2,2,1,-1,-2,-2,-1}; /*anticlockwise rotation*/
        for(int i=0; i<N; i++)
            for(int j=0; j<8; j++)
                sol[i][j] = -1;
    }

    void Printer(){

        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++)
                System.out.print(" "+sol[i][j]);
            System.out.println("");
        }
    }

    boolean IsSafe(int x, int y){
        if(x>=0 && x<N && y>=0 && y<N && sol[x][y]== -1 )
            return true;
        return false;
    }

    boolean SolveKT(){

        if(!F(0,0,1)){
            System.out.println("The soln doesnot exist! :'(");
            return false;
        }
        Printer();
        return true;
    }

    boolean F(int x, int y, int movei){

        int  x1, y1;
        if(movei == N*N)
            return true;
        for(int k = 0; k<8; k++) {
            x1 = x + xmove[k];
            y1 = y + ymove[k];
            if(IsSafe(x1, y1)){
                sol[x1][y1] = movei;
                if(F(x1, y1, movei+1))
                    return true;
                else sol[x1][y1] = -1;
            }
        }
        return false;
    }
}
