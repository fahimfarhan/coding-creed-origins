import java.io.IOException;

/**
 * Created by Fahim on 12/8/2016.
 */
public class Sudoku {

    public static int board[][];
    public static int globalSolution[][];

    static boolean backtrack(int u[][], int r, int c ){
        if(r==9) return true;

        c++;
        if(c==9){


            r++;
            c=0;
        }
        if(u[r][c]!=0) return backtrack(u,r,c);

        for(int i=1; i <=9; i++){
            int v[][] = new int[9][9];

            for(int p=0; p <9; p++){

                for(int q= 0; q <9; q++){
                    v[p][q]=u[p][q];
                }
            }

            printboard(v);
            /*try {
                System.in.read();
            } catch (IOException e) {
                e.printStackTrace();
            }*/
            v[r][c]= i;

            if(isvalid(v)) {
                if (backtrack(v, r, c)) {
                    globalSolution[r][c] = i;
                    return true;
                }
            }
        }
        return false;
    }

    static boolean isvalid(int b[][]){
        for(int r=0; r<9;r++){
            for(int i=0; i <9; i++){
                for(int j=0; j<9; j++){
                    if(i==j || b[r][i]==0 || b[r][j]==0) continue;
                    if(b[r][i]==b[r][j]) return false;
                }
            }
        }
        for(int c=0; c<9;c++){
            for(int i=0; i <9; i++){
                for(int j=0; j<9; j++){
                    if(i==j || b[i][c]==0 || b[j][c]==0) continue;
                    if(b[i][c]==b[j][c]) return false;
                }
            }
        }

        return true;
    }


    public static void printboard(int b[][]){
        for(int i=0; i <9; i++){
            for(int j=0; j <9; j++){
                System.out.print(b[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main (String args[]) throws ArrayIndexOutOfBoundsException{

        board = new int[9][9];
        globalSolution=new int[9][9];

        backtrack(board,0,-1);
        printboard(globalSolution);

    }
}
