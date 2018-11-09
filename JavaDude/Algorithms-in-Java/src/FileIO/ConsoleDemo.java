package FileIO;

import java.io.*;

/**
 * Created by Fahim on 11/25/2016.
 */
public class ConsoleDemo {
    public static void main(String [] srgs) throws Exception {

        String username, password;
        System.out.println("this is a test\n");
        Console con;
        con = System.console();
        System.out.println(con);
        if(con == null) return;

        username = con.readLine("Enter username: ");
        char []p = con.readPassword("Enter password: ");
        password = new String(p);
        con.printf("name = %s\n",username );
        con.printf("password = %s\n", password);
        //return;
    }
}
