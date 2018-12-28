import java.util.*;


public class Start{
    public static void main(String[] Args){
        Scanner sc = new Scanner(System.in);
        Factory factory = new Factory();
        while(sc.hasNextInt()){
            int n = sc.nextInt();
            Car car = factory.getCar(n);
            car.setFuel(n);
            System.out.println(car.model + " "+car.speed+" "+car.getFuel());
        }
    }
}