/**
 * LAZY INITIALIZATION
 */

import java.util.*;

public final class Singleton2{
    private static volatile Singleton2 Instance = null;
    private Singleton2(){}

    public static Singleton2 getInstance(){ 
        if(Instance == null){
            Instance = new Singleton2();
        }    
        return Instance;
     }
}