import java.util.*;

public class B1146{
    public static void main(String[] Args){
        String t="",s="",s1="",temp="", temp2="";
        int acount=0;
        char ch;

        boolean b = false;
        Scanner sc = new Scanner(System.in);
        t = sc.nextLine();
        for(int i=0; i<t.length(); i++){
            if(t.charAt(i)=='a'){   acount++; }
            //else{   ch = (t.charAt(i)); temp = temp + ch;  }
        }
        int acount1 = acount;
        for(int i=0; i<t.length(); i++){
            if(t.charAt(i)=='a'){   acount1--; }
            else{ch = (t.charAt(i)); temp = temp + ch;}
               //acount1--;
               if(acount1 == 0){    break; }  
        }
        //System.out.println(t+" "+temp);
        
        if(acount == t.length() ){
            // case 1: aaaaaaa
            System.out.println(t);
            b = true;
        }else if(acount ==0){
            // case 2: teetrtyu
            System.out.println(t);
            b = true;
        }
        else {
                int index = t.indexOf(temp);
                int matchLength = temp.length();
                while (index >= 0) {  // indexOf returns -1 if no match found
                    // System.out.println(index);
                    s = t.substring(0, index);
                    s1 = t.substring(index);
                    //System.out.println(s+" "+s1);
                    temp2 = s+s1;
                    if(temp2.equals(t)){
                        System.out.println(s);
                        b = true;
                        break;
                    }
                index = t.indexOf(temp, index + matchLength);
            }
            
        }
        if(b == false){
            System.out.println(":(");
        }
        //int pos = 
        
        //System.out.print(s);
        sc.close();
    }
}