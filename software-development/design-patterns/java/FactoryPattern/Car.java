import java.util.*;

public class Car{
    public int speed;
    protected String model;
    private int fuel;

    Car(){
        fuel = 50;
    }

    public int getFuel(){  return this.fuel; }
    public void setFuel(int fuel){ this.fuel = fuel; }
}