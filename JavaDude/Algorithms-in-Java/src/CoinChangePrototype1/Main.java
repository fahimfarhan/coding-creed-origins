package CoinChangePrototype1;

public class Main {

    public static void main(String[] args) {
	// write your code here

        CoinChange ob = new CoinChange(1000);
        int []c = new int[]{1,2,5,10};

        int value =  500;
        long n = ob.coinchange(0,value, c);
        System.out.println(""+n);
    }
}
