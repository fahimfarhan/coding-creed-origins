package FileIO;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by Fahim on 11/25/2016.
 */
public class BufferedReaderDemo {
    public static void main(String [] args) throws IOException{

        File f = new File("F:\\Codes\\Java_Codes\\Algorithms\\src\\FileIO\\test.txt");
        FileReader fr = new FileReader(f);
        BufferedReader br = new BufferedReader(fr);
        String s1="";
        while(true){

            String s = br.readLine();
            if(s == null) break;
            s1 = s1+s;
            System.out.println(s);
        }
        System.out.println(s1);
        br.close();
        fr.close();

    }
}
