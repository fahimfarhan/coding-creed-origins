import java.util.*;

public class C158{
    public static void main(String[] Args){
        int T=0;
        ArrayList<String> path = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();

        String s;
        for(int t=0; t<=T; t++){ 
            s = sc.nextLine();
            if(s.equals("pwd")){
                if(path.size()==0){ System.out.println("/");   }
                else{
                    for(int i=01; i<path.size(); i++){
                        System.out.print("/"+path.get(i)+"");
                    }System.out.println("/");
                }
            }else{
                if(s.length()>3){
                    s = s.substring(3);
                    //System.out.println(s);

                    if(s.charAt(0)=='/'){
                        // clear path 
                        path.clear();
                    }
                    String[] temp = s.split("/");
                    for(int i=0; i<temp.length; i++){
                        if( (temp[i].equals("..")) && (path.size()>0)){
                            // remove last element
                            path.remove(path.size()-1);
                        }else{    path.add(temp[i]);  }
                    }
                }
            }
        }
        sc.close();
    }
}