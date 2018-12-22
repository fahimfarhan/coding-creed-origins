package LCSiterativePrototype1;

/**
 * Created by Fahim on 11/19/2016.
 *
 * FAILED :'( :'( :'(
 */
public class LCS1 {
    int Lcs[][];
    LCS1(){     Lcs = new int[50][50];  }
    int LCS_Func(String s1, String s2){

        int m = s1.length();
        int n = s2.length();

        for(int i=0; i<=m; i++) Lcs[i][n] = 0;
        for(int i=0; i<=m; i++) Lcs[m][i] = 0;

        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--){

                Lcs[i][j] = Lcs[i+1][j+1];
                if(s1.charAt(i) == s2.charAt(j))    Lcs[i][j]++;
                if(Lcs[i][j+1] >Lcs[i][j])  Lcs[i][j] = Lcs[i][j+1];
                if(Lcs[i+1][j] <Lcs[i][j])  Lcs[i][j] = Lcs[i+1][j];
            }
            return Lcs[0][0];
    }
}
