package FileIO;

import java.io.*;

/**
 * Created by Fahim on 11/25/2016.
 */
public class BufferedWrierDemo {
    public static void main(String [] args) throws IOException {

        FileReader fr = new FileReader("F:\\Codes\\Java_Codes\\Algorithms\\src\\FileIO\\test.txt");
        BufferedReader br = new BufferedReader(fr);
        FileWriter fw = new FileWriter("F:\\Codes\\Java_Codes\\Algorithms\\src\\FileIO\\test1.txt");
        BufferedWriter bw = new BufferedWriter(fw);

        while(true){

            String s = br.readLine();
            if(s == null) break;
            s = s+"\n";
            bw.write(s);
        }
        /*close all 4 */
        bw.close();
        fw.close();
        br.close();
        fr.close();

    }
}
