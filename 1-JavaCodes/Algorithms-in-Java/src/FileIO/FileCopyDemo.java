package FileIO;

import java.io.*;

/**
 * Created by Fahim on 11/25/2016.
 */
public class FileCopyDemo {
    public static void main( String [] args) throws IOException{
        String source = "F:\\Codes\\Java_Codes\\Algorithms\\src\\FileIO\\test.txt";
        String dest = "F:\\Codes\\Java_Codes\\Algorithms\\src\\FileIO\\test1.txt";

        InputStream in = new FileInputStream(source);
        OutputStream out = new FileOutputStream(dest);

        while(true){

            int c = in.read();
            System.out.print((char)c);// tester
            if(c == -1) break;
            out.write(c);

        }
        out.close();
        in.close();
    }
}
