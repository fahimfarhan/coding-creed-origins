package LCSiterativePrototype1;

/**
 * Created by Fahim on 11/19/2016.
 */
public class MainLCS {
    public static void main(String []args){

        String s1 = "ATCGCCTA";
        String s2 = "ACGCTA";

        LCS2 lcs = new LCS2(s1, s2);

        lcs.F1();
        lcs.PrintLCS();

    }
}
