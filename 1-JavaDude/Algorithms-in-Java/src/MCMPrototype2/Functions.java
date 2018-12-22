package MCMPrototype2;

/**
 * Created by Fahim on 11/20/2016.
 */
public class Functions {
    int[][] M; /* M = dp[][] */
    int [] p;
    int l;
    final int INF = 999999;//Integer.MAX_VALUE;

    public int explored;
    Functions(int []p){
        explored = 0;
        this.p = p;
        l = p.length;
        M = new int[l][l];

        for(int i=0; i < l; i++){
            for(int j=0; j <l; j++){
                M[i][j]= -1;
            }
        }
    }

    int M1(int i, int j){
        explored++;
        if (i == j) return 0;   /* base case */
//        if(M[i][j]!=-1) return M[i][j];
        int min = INF;
        //the formula
        for(int k=i; k<j; k++){
            int temp = M1(i, k) + M1(k+1, j) + p[i-1]*p[k]*p[j];
            if(temp < min)  min = temp;
        }//end of loop, M[i][j] found and so return it

        return M[i][j]=min;
       // return 0;
    }

    /**
     * void PrintMCM(int i, int j){    //print(dp[][], i, j)
        if(i==j)
            System.out.print("A"+i);
        else{
            System.out.print("(");
            PrintMCM(i, s[i][j]);
            PrintMCM(s[i][j]+1,j);
            System.out.print(")");
        }

    }*/
    void Printer(){
        /*debug: print M*/
        for(int i=1; i<l; i++){
            for(int j=1; j<l; j++) {
                System.out.print(" "+ M[i][j]+"  ");
            }
            System.out.println("");
        }

        System.out.println(" Integer max value = "+ INF);
        System.out.println("Ans = " + M[1][l-1]);  // l = length of set p[]
    }


}
