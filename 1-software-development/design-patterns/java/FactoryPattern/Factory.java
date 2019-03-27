import java.util.*;

public class Factory{
    private Car car;
    public Factory(){
        this.car = null;
    }

    public Car getCar(int choice){
        if(choice == 0){
            this.car = new Toyota();
        }else{
            this.car = new BMW();
        }
        return this.car;
    }
}