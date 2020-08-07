package N_QueenProblem;

/**
 * Created by Fahim on 12/8/2016.
 */
public class MainNQ {

    public static void main(String[] args){
        NQueen NQ ;
        for(int i=1; i<=20; i++){

            NQ = new NQueen(i);
            NQ.SolveNQ();
        }
    }
}
