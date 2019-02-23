import java.util.*;

public final class Singleton1{
    private static final Singleton1 Instance = new Singleton1();
    private Singleton1(){}

    public static Singleton1 getInstance(){ return Instance; }
}