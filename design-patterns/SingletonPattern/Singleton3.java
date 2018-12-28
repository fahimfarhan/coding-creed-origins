/**
 * LAZY INITIALIZATION THREADSAFE
 */

import java.util.*;

public final class Singleton3{
    private static volatile Singleton3 Instance = null;
    private Singleton3(){}

    public static Singleton3 getInstance(){ 
        if(Instance == null){
            synchronized(Singleton3.class){
                if(Instance == null)
                    Instance = new Singleton3();
            }
            
        }    
        return Instance;
     }
}