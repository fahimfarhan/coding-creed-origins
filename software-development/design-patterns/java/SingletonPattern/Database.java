/**
 * LAZY INITIALIZATION THREADSAFE
 */

import java.util.*;

public final class Database{
    private static volatile Database Instance = null;
    private Database(){
        String url = "http:127.0.0.1:3306/username:password";
        // connect to mysql / sth
        boolean dbexists = true;
        if(!dbexists){
            // create db!
        }else{
            // establish connection!
        }
    }

    public static Database getInstance(){ 
        if(Instance == null){
            synchronized(Database.class){
                if(Instance == null){
                    System.out.println("Creating new db connection!");
                    Instance = new Database();
                    System.out.println("New db connection Created!");
                    return Instance;
                }
                    
            }
            
        }    
        System.out.println("old db connection!");
        return Instance;
     }
}