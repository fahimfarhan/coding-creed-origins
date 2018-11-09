import static java.lang.Integer.max;

/**
 * Created by Tarik on 11/13/2016.
 */
public class LCS {

    public enum Dir {left, up, diag} ; //dir == direction
    public static Dir dir[][];
    static  int dp[][];
    static int parent[][];
    static String s1 = " abcab";
    static String s2 = " baed";

    public static int longest(String s1, String s2, int i, int j){
        if(i==0 || j==0) return dp[i][j]= 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s1.charAt(i)==s2.charAt(j)){
            parent[i][j]= 1;
            return dp[i][j]= longest(s1,s2,i-1,j-1)+1;
        }
        int l1 = longest(s1,s2,i-1,j);
        int l2 = longest(s1,s2,i,j-1);

        if(l1 < l2){
            parent[i][j]=2;
        }
        else {
            parent[i][j]=0;
        }
        return dp[i][j]= max(l1,l2);
    }


    public static void printlcs(int i, int j){

        System.out.println(i+" "+j+" "+dp[i][j]);
        if(i==0 || j==0) return;
        if(parent[i][j]==0){
            printlcs(i-1,j);
        }
        else if(parent[i][j]==2){
            printlcs(i,j-1);
        }
        else if(parent[i][j]==1){
            printlcs(i-1,j-1);
            System.out.print(s1.charAt(i));
        }
    }
    public static void main(String args[]){


        dp=new int[100][100];
        for(int i=0; i < 100; i++){
            for(int j=0; j < 100; j++){
                dp[i][j]=-1;
            }
        }

        parent =new int[100][100];
        System.out.println(""+longest(s1,s2,5,4));
        printlcs(5,4);
    }
}
