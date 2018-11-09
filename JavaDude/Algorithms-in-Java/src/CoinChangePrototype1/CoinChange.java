package CoinChangePrototype1;

/**
 * Created by Fahim on 11/13/2016.
 */
public class CoinChange {


    long dp[][];

    public CoinChange(int n){
        dp = new long[n][50];
        for(int i= 0; i < n; i++){
            for(int j=0; j <50; j++)
                dp[i][j]=-1;
        }
    }


    public long coinchange(int index, int value, int c[]){
        int m = c.length;
        long way1 = 0;
        long way2 = 0;
        //double sum = 0;
        if(index >=  m) {
            return 0;
        }


        if(dp[value][index]!=-1) return dp[value][index];
        if(value == 0) {
            return 1;
        }
        if((value - c[index]) >=0){

            way1 = coinchange(index, (value - c[index]), c );
            System.out.println("way1 "+way1);
       // }else{

            way2 = coinchange(index+1, value, c );
            System.out.println("way2 "+way2);
        }

        System.out.println("way1 "+way1);
        System.out.println("way2 "+way1);


        return dp[value][index] = way1+way2;
    }
}
